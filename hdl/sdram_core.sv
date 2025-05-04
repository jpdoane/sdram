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

localparam STATE_BOOT       = 3'h0;
localparam STATE_PRECHARGE  = 3'h1;
localparam STATE_MODESET    = 3'h2;
localparam STATE_REFRESH    = 3'h3;
localparam STATE_IDLE       = 3'h4;
localparam STATE_ACTIVATE   = 3'h5;
localparam STATE_READ       = 3'h6;
localparam STATE_WRITE      = 3'h7;


// control port
logic [core_if.DATA_WIDTH-1:0] data_wr;
logic [core_if.ADDR_WIDTH-1:0] addr_in;
logic wr;
logic rd;
logic rdy;
logic val;
logic [core_if.DATA_WIDTH-1:0] data_rd;

assign wr = core_if.wr;
assign rd = core_if.rd;
assign addr_in = core_if.addr;
assign data_wr = core_if.write_data;
assign core_if.accept = rdy & (wr | rd);
assign core_if.ack = val;
assign core_if.error = 0;
assign core_if.read_data = data_rd;

// sdram port
logic [ROW_WIDTH-1:0] sd_a;
logic [1:0] sd_bs;
logic sd_cs_n;
logic sd_ras_n;
logic sd_cas_n;
logic sd_we_n;
logic [1:0] sd_dqm;
logic sd_cke;
logic [15:0] sd_din;
logic [15:0] sd_dout;
logic sd_dout_en;

assign part_if.cke          = sd_cke;
assign part_if.cs           = sd_cs_n;
assign part_if.ras          = sd_ras_n;
assign part_if.cas          = sd_cas_n;
assign part_if.we           = sd_we_n;
assign part_if.dqm          = sd_dqm;
assign part_if.addr         = sd_a;
assign part_if.ba           = sd_bs;
assign part_if.write_data   = sd_dout;
assign part_if.wr_en        = sd_dout_en;
assign sd_din               = part_if.read_data;


logic [2:0] state, state_next;
logic new_state;
logic [CNT_W-1:0] cnt, state_delay;
logic first_cycle;
logic [CNT2_W-1:0] cnt2;
logic trigger_refresh, refresh_ack;
logic boot_delay, booting;
logic rw;
logic sd_rd;

// address decode
logic [1:0] bank, bank_in;
logic [ROW_WIDTH-1:0] row, row_in;
logic [COL_WIDTH-1:0] col, col_in;
logic byte_ul, byte_in;
assign {bank_in, row_in, col_in, byte_in} = SDADDR_WIDTH'(addr_in);

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
        byte_ul <= 0;
        rw <= 0;
        sd_dout <= 0;

        data_rd<=0;
        val<=0;

    end else begin

        // count cycles within each state
        if(cnt==state_delay) begin
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
    
        if (rdy) begin
            if (rd || wr) begin
                bank <= bank_in;
                row <= row_in;
                col <= col_in;
                byte_ul <= byte_in;
                rw <= rd;
                sd_dout <= {data_wr,data_wr};
            end
            // if(wr) sd_dout <= byte_in ? {data_wr,8'h0} : {8'h0, data_wr};
        end

        if( sd_rd ) begin
            data_rd <= byte_ul ? sd_din[15:8] : sd_din[7:0]; 
            val <= 1;
        end else begin
            val <= 0;
            data_rd <= 0;
        end
    end
end

localparam SDMODE_BURST1 = 3'h0;
localparam SDMODE_BURST2 = 3'h1;
localparam SDMODE_BURST4 = 3'h2;
localparam SDMODE_BURST8 = 3'h3;
localparam SDMODE_BURSTPAGE = 3'h7;
localparam SDMODE_SEQUENTIAL = 1'b0;
localparam SDMODE_INTERLEAVE = 1'b1;
localparam SDMODE_BURSTWRITE = 1'b0;
localparam SDMODE_SINGLEWRITE = 1'b0;
localparam sdmode = ROW_WIDTH'({SDMODE_SINGLEWRITE, 2'b0, CAS_LATENCY[2:0], SDMODE_SEQUENTIAL, SDMODE_BURST1});

logic [2:0] sd_cmd;
assign {sd_ras_n, sd_cas_n, sd_we_n} = sd_cmd;


always @(*)
begin
    sd_a = 1 << 10; // auto precharge
    sd_bs = 2'b0;
    sd_cs_n = 1'b0;
    sd_dqm = '0;
    sd_dout_en = 1'b0;
    sd_cke = 1'b1;
    sd_cmd = SDRAM_NOP;
    sd_rd = 0;

    rdy = 0;
    state_next = state;
    boot_delay = 0;
    state_delay = '0;
    refresh_ack = 0;

    case(state)
        STATE_BOOT: begin 
            // After power up, an initial pause of 200 μ S is required. To prevent data contention on the DQ bus 
            // during power up, it is required that the DQM and CKE pins be held high during the initial pause period.
            sd_dqm = 2'b11;
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
            sd_a = sdmode;
            sd_bs = 2'b0;
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
            end else if (rd || wr) begin
                state_next = STATE_ACTIVATE;                    
            end
        end
        STATE_ACTIVATE: begin
            if(first_cycle) sd_cmd = SDRAM_ACTIVATE;
            sd_a = row;
            sd_bs = bank;
            state_next = rw ? STATE_READ : STATE_WRITE;
            state_delay = `DELAY(DELAY_RCD-1, CNT_W);
        end
        STATE_READ: begin 
            if(first_cycle) sd_cmd = SDRAM_READ;
            sd_bs = bank;
            sd_a[COL_WIDTH-1:0] = col;
            state_next = STATE_IDLE;
            sd_rd = cnt == CAS_LATENCY-1;
            state_delay = CAS_LATENCY-1 +`DELAY(DELAY_RP-1, CNT_W);
        end
        STATE_WRITE: begin 
            if(first_cycle) sd_cmd = SDRAM_WRITE;
            sd_bs = bank;
            sd_a[COL_WIDTH-1:0] = col;
            sd_dqm = {~byte_ul, byte_ul};
            sd_dout_en = 1'b1;
            state_next = STATE_IDLE;
            state_delay = `DELAY(DELAY_DAL-1, CNT_W);
        end
        default: begin end
    endcase
end

endmodule