`timescale 1ns/1ps

`define MAX(a,b) ((a) > (b) ? (a) : (b))
`define DELAY(cycles, bits) `MAX(bits'(cycles),bits'(0))

module sdram_core #(
    parameter SDRAM_MHZ     = 50,
    parameter CAS_LATENCY   = 2,
    parameter STARTUP_US    = 100.0,       // min time in us to hold in startup before initialization
    parameter tRC_NS        = 60.0,        // min time in ns between row activations (same bank)
    parameter tRAS_NS       = 42.0,        // min time in ns from row activation to precharge (same bank)
    parameter tRCD_NS       = 15.0,        // min time in ns from row activation to read/write
    parameter tRP_NS        = 15.0,        // min time in ns from precharge to refresh/activation (same bank)
    parameter tXSR_NS       = 72.0,        // min time in ns from self-refresh exit to activation
    parameter tREF_NS       = 64e6,        // max time in ns to perform all 8k refresh cycles
    parameter DELAY_WR      = 2,           // min clocks between row activations (different bank)
    parameter DELAY_RRD     = 2,           // min clocks between row activations (different bank)
    parameter DELAY_RSC     = 2
    )(
    // main clocks
    input logic clk, rst,
    sdram_core_if.sub core_if,
    sdram_part_if.man part_if
);

localparam int ADDR_WIDTH    = core_if.ADDR_WIDTH;
localparam int SDADDR_WIDTH  = part_if.ADDR_WIDTH;
localparam int COL_WIDTH     = part_if.COL_WIDTH;
localparam int ROW_WIDTH     = part_if.ROW_WIDTH;

localparam int CNT_W                = 4;
localparam int CNT2_W               = 16;
localparam real CLK_PERIOD_NS       = 1000.0 / SDRAM_MHZ;
localparam int DELAY_STARTUP        = int'($ceil(STARTUP_US * SDRAM_MHZ));
localparam int DELAY_REF_INTERVAL   = int'($ceil(tREF_NS/8192/CLK_PERIOD_NS));
localparam int DELAY_RC             = int'($ceil(tRC_NS / CLK_PERIOD_NS));
localparam int DELAY_RCD            = int'($ceil(tRCD_NS/CLK_PERIOD_NS));
localparam int DELAY_RP             = int'($ceil(tRP_NS/CLK_PERIOD_NS));
localparam int DELAY_DAL            = int'($ceil(DELAY_WR + DELAY_RP));

// sdram control words for sd_cmd
// applied to {ras_n, cas_n, we_n}
localparam SDRAM_ACTIVATE           = 3'b011;
localparam SDRAM_PRECHARGE          = 3'b010; //A10: all vs bank
localparam SDRAM_WRITE              = 3'b100; //A10: auto precharge
localparam SDRAM_READ               = 3'b101; //A10: auto precharge
localparam SDRAM_MODE_SET           = 3'b000;
localparam SDRAM_NOP                = 3'b111;
localparam SDRAM_BURST_STOP         = 3'b110;
localparam SDRAM_AUTO_REFRESH       = 3'b001; //cke H->H
localparam SDRAM_SELF_REFRESH_ENTRY = 3'b001; //cke H->L
localparam SDRAM_SELF_REFRESH_EXIT  = 3'b110; //cke L->H
localparam SDRAM_ACTIVE_POWER_DOWN  = 3'b110; //cke H->L
localparam SDRAM_POWER_DOWN_EXIT    = 3'b110; //cke L->H

// after initial DELAY_STARTUP, we go through sequence of:
// precharge, modeset, and 8x refreshes before memory is ready
localparam BOOT_DURATION            = DELAY_RP + DELAY_RSC + 8*(DELAY_RC+3);

localparam STATE_BOOT       = 4'h0;
localparam STATE_PRECHARGE  = 4'h1;
localparam STATE_MODESET    = 4'h2;
localparam STATE_REFRESH    = 4'h3;
localparam STATE_IDLE       = 4'h4;
localparam STATE_ACTIVATE   = 4'h5;
localparam STATE_READ_CMD   = 4'h6;
localparam STATE_READ       = 4'h7;
localparam STATE_WRITE      = 4'h8;

localparam SDMODE_BURST1 = 3'h0;
localparam SDMODE_BURST2 = 3'h1;
localparam SDMODE_BURST4 = 3'h2;
localparam SDMODE_BURST8 = 3'h3;
localparam SDMODE_BURSTPAGE = 3'h7;
localparam SDMODE_SEQUENTIAL = 1'b0;
localparam SDMODE_INTERLEAVE = 1'b1;
// localparam SDMODE_BURSTWRITE = 1'b0;
// localparam SDMODE_SINGLEWRITE = 1'b0;

if( !(core_if.DATA_WIDTH == 8 || core_if.DATA_WIDTH == 16 || core_if.DATA_WIDTH == 32))
    $error("unsupported data width: %d", core_if.DATA_WIDTH);

localparam int BURST_SIZE = (core_if.DATA_WIDTH == 32) ? 2 : 1;
localparam BURST_MODE = BURST_SIZE == 2 ? SDMODE_BURST2 : SDMODE_BURST1;

localparam sdmode = ROW_WIDTH'({3'b0, CAS_LATENCY[2:0], SDMODE_SEQUENTIAL, BURST_MODE});

// control signals
logic [3:0] state, state_next;
logic new_state;
logic [CNT_W-1:0] cnt, state_delay;
logic first_cycle, last_cycle;
logic [CNT2_W-1:0] cnt2;
logic trigger_refresh, refresh_ack;
logic boot_delay, booting;
logic rw;

// command port signals
logic rdy, valid, req, valid_req;
assign core_if.valid = valid;
assign core_if.error = 0;
assign core_if.rdy = rdy;
assign req = core_if.rd | (core_if.wr != 0);
assign valid_req = rdy & req;

// sdram port signals
logic [2:0] sd_cmd;
assign {part_if.ras, part_if.cas, part_if.we} = sd_cmd;
logic [1:0] bank;
logic [ROW_WIDTH-1:0] row;
logic [COL_WIDTH-1:0] col;
logic byte_misalign;
logic sd_wr, sd_rd, sd_rd_reg, sd_rd_cas;

assign part_if.wr_en = sd_wr;

assign last_cycle = (cnt==state_delay);
always_ff @(posedge clk)
begin
    if (rst) begin
        state <= STATE_BOOT;
        cnt <= 0;
        first_cycle <= 0;

        cnt2 <= `DELAY(DELAY_STARTUP, CNT2_W);
        booting <= 0;
        trigger_refresh <= 0;

        bank <= 0;
        row <= 0;
        col <= 0;
        byte_misalign <= 0;
        rw <= 0;
        sd_rd_reg <= 0;
        sd_rd_cas <= 0;
    end else begin

        sd_rd_reg <= sd_rd;
        sd_rd_cas <= (CAS_LATENCY == 2) ? sd_rd : sd_rd_reg;

        // count cycles within each state
        if(last_cycle) begin
            state <= state_next;
            cnt <= '0;
            first_cycle <= 1;
        end else begin
            cnt <= cnt+1;
            first_cycle <= 0;
        end

        // secondary counter for boot sequence and refresh
        if(cnt2==0) begin
            trigger_refresh <= 1;

            if(boot_delay) begin
                booting <= 1;
                cnt2 <= `DELAY(BOOT_DURATION, CNT2_W);
            end else begin
                booting <= 0;
                cnt2 <= `DELAY(DELAY_REF_INTERVAL, CNT2_W);
            end
        end else cnt2 <= cnt2-1;

        if(refresh_ack & !booting) trigger_refresh <= 0;
    
        if (valid_req) begin
            {bank, row, col, byte_misalign} <= core_if.addr[SDADDR_WIDTH-1:0];
            rw <= core_if.rd;
        end
   end
end

// state machine
always @(*)
begin
    part_if.cke = 1'b1;
    part_if.addr = 1 << 10; // auto precharge
    part_if.ba = 2'b0;
    part_if.cs = 1'b0;
    part_if.dqm = '0;
    part_if.write_data = '0;
    sd_cmd = SDRAM_NOP;
    sd_rd = 0;
    sd_wr = 0;

    rdy = 0;
    state_next = state;
    boot_delay = 0;
    state_delay = '0;
    refresh_ack = 0;
    valid = 0;

    case(state)
        STATE_BOOT: begin 
            // After power up, an initial pause of 200 μ S is required. To prevent data contention on the DQ bus 
            // during power up, it is required that the DQM and CKE pins be held high during the initial pause period.
            part_if.dqm = 2'b11;
            boot_delay = 1;
            if (booting) state_next = STATE_PRECHARGE;
        end
        STATE_PRECHARGE: begin 
            if(first_cycle) sd_cmd = SDRAM_PRECHARGE; // Precharge all banks            
            state_delay = `DELAY(DELAY_RP-1, CNT_W);
            state_next = booting ? STATE_MODESET : STATE_IDLE;
        end
        STATE_MODESET: begin
            if(first_cycle) sd_cmd = SDRAM_MODE_SET;
            part_if.addr = sdmode;
            part_if.ba = 2'b0;
            state_delay = `DELAY(DELAY_RSC-2, CNT_W);
            state_next = STATE_REFRESH;
        end
        STATE_REFRESH: begin
            if(first_cycle) sd_cmd = SDRAM_AUTO_REFRESH;
            refresh_ack = 1;
            state_delay = `DELAY(DELAY_RC-1, CNT_W);
            state_next = STATE_IDLE;
        end
        STATE_IDLE: begin  
            rdy = 1;
            if( trigger_refresh ) begin
                rdy = 0;
                state_next = STATE_REFRESH;
            end else if(req) begin
                state_next = STATE_ACTIVATE;                    
            end
        end
        STATE_ACTIVATE: begin
            if(first_cycle) sd_cmd = SDRAM_ACTIVATE;
            part_if.addr = row;
            part_if.ba = bank;
            state_next = rw ? STATE_READ : STATE_WRITE;
            state_delay = `DELAY(DELAY_RCD-1, CNT_W);
        end
        // STATE_READ_CMD: begin 
        //     if(first_cycle) sd_cmd = SDRAM_READ;
        //     part_if.ba = bank;
        //     part_if.addr[COL_WIDTH-1:0] = col;
        //     state_next = STATE_READ;
        //     state_delay = CAS_LATENCY-2;
        // end
        STATE_READ: begin 
            if(first_cycle) sd_cmd = SDRAM_READ;
            part_if.ba = bank;
            part_if.addr[COL_WIDTH-1:0] = col;
            sd_rd = 1;
            state_delay = `DELAY(CAS_LATENCY+BURST_SIZE-1, CNT_W);
            valid = last_cycle;
            state_next = STATE_IDLE;
        end
        STATE_WRITE: begin 
            if(first_cycle) sd_cmd = SDRAM_WRITE;
            part_if.ba = bank;
            part_if.addr[COL_WIDTH-1:0] = col;
            sd_wr = 1'b1;
            state_next = STATE_IDLE;
            state_delay = `DELAY(`MAX(BURST_SIZE-1, DELAY_DAL-1), CNT_W);
        end
        default: begin end
    endcase
end

// data register to support various data widths
localparam DATA_REG_W = core_if.DATA_WIDTH >= 16 ? core_if.DATA_WIDTH : 16;
localparam DATA_REG_BYTES = DATA_REG_W/8;
logic [DATA_REG_W-1:0] data_reg;
logic [DATA_REG_BYTES-1:0] dqm_reg;

generate
    if(core_if.DATA_WIDTH == 8) begin
        always_ff @(posedge clk) begin
            if (rst) begin
                data_reg <= '0;
                dqm_reg <= '0;
            end else begin
                if (valid_req) begin
                    if (core_if.addr[0]) begin
                        data_reg <= {core_if.write_data, 8'b0};
                        dqm_reg <= ~{core_if.wr, 1'b0};
                    end else begin
                        data_reg <= {8'b0, core_if.write_data};
                        dqm_reg <= ~{1'b0, core_if.wr};
                    end
                end
                if (sd_rd_cas) data_reg[7:0] <= byte_misalign ? part_if.read_data[15:8] : part_if.read_data[7:0];
            end
        end
    end else if(core_if.DATA_WIDTH == 16) begin
        always_ff @(posedge clk) begin
            if (rst) begin
                data_reg <= '0;
                dqm_reg <= '0;
            end else begin
                if (valid_req) begin
                    data_reg <= core_if.write_data;
                    dqm_reg <= ~core_if.wr;
                end
                if (sd_rd_cas) data_reg <= part_if.read_data;
            end
        end
    end else begin // core_if.DATA_WIDTH >= 32
        always_ff @(posedge clk) begin
            if (rst) begin
                data_reg <= '0;
                dqm_reg <= '0;
            end else begin
                if (valid_req) begin
                    data_reg <= core_if.write_data;
                    dqm_reg <= ~core_if.wr;
                end
                if (sd_wr | sd_rd_cas) begin
                    // each rd/wr cycle shift down active 16-bit
                    // active write data is shifted into low bits
                    // active read data is shifted into high bits
                    data_reg <= {part_if.read_data, data_reg[DATA_REG_W-1:16]};
                    dqm_reg <= {2'b11, dqm_reg[DATA_REG_BYTES-1:2]};
                end
            end
        end
    end
endgenerate

assign core_if.read_data = (valid & rw) ? data_reg[core_if.DATA_WIDTH-1:0] : '0;
assign part_if.write_data = data_reg[15:0];
assign part_if.dqm = rw ? '0 : dqm_reg[1:0];

endmodule