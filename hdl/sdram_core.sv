`timescale 1ns / 100ps

`define MAX(a,b) ((a) > (b) ? (a) : (b))
`define DELAY(cycles, bits) `MAX(bits'(cycles),bits'(0))

module sdram_core #(
    parameter real FREQ_MHZ     = 50,
    parameter int CAS_LATENCY   = 2,
    parameter real STARTUP_US    = 250.0,       // min time in us to hold in startup before initialization
    parameter real tRC_NS        = 60.0,        // min time in ns between row activations (same bank)
    parameter real tRAS_NS       = 42.0,        // min time in ns from row activation to precharge (same bank)
    parameter real tRCD_NS       = 15.0,        // min time in ns from row activation to read/write
    parameter real tRP_NS        = 15.0,        // min time in ns from precharge to refresh/activation (same bank)
    parameter real tXSR_NS       = 72.0,        // min time in ns from self-refresh exit to activation
    parameter real tREF_NS       = 64e6,        // max time in ns to perform all 8k refresh cycles
    parameter int DELAY_WR      = 2,           // min clocks between row activations (different bank)
    parameter int DELAY_RRD     = 2,           // min clocks between row activations (different bank)
    parameter int DELAY_RSC     = 2
    )(
    // main clocks
    input logic clk, rst,
    sdram_ctrl_if.sub ctrl_if,
    sdram_dev_if.man dev_if
);

localparam int DATA_WIDTH    = ctrl_if.DATA_WIDTH;
localparam int ADDR_WIDTH    = ctrl_if.ADDR_WIDTH;
localparam int WORD_LEN     = ctrl_if.WORD_LEN;

localparam int DEV_ADDR_WIDTH  = dev_if.ADDR_WIDTH;
localparam int COL_WIDTH     = dev_if.COL_WIDTH;
localparam int ROW_WIDTH     = dev_if.ROW_WIDTH;

localparam int CNT_W                = 4;
localparam int CNT2_W               = 16;
localparam real CLK_PERIOD_NS       = 1000.0 / FREQ_MHZ;
localparam int DELAY_STARTUP        = int'($ceil(STARTUP_US * FREQ_MHZ));
localparam int DELAY_REF_INTERVAL   = 350; //int'($ceil(tREF_NS/8192/CLK_PERIOD_NS));
localparam int DELAY_RC             = int'($ceil(tRC_NS / CLK_PERIOD_NS));
localparam int DELAY_RCD            = int'($ceil(tRCD_NS/CLK_PERIOD_NS));
localparam int DELAY_RP             = int'($ceil(tRP_NS/CLK_PERIOD_NS));
localparam int DELAY_DAL            = DELAY_WR + DELAY_RP;

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

localparam STATE_BOOT       = 3'h0;
localparam STATE_PRECHARGE  = 3'h1;
localparam STATE_MODESET    = 3'h2;
localparam STATE_REFRESH    = 3'h3;
localparam STATE_IDLE       = 3'h4;
localparam STATE_ACTIVATE   = 3'h5;
localparam STATE_READ       = 3'h6;
localparam STATE_WRITE      = 3'h7;

localparam SDMODE_BURST1 = 3'h0;
localparam SDMODE_BURST2 = 3'h1;
localparam SDMODE_BURST4 = 3'h2;
localparam SDMODE_BURST8 = 3'h3;
localparam SDMODE_BURSTPAGE = 3'h7;
localparam SDMODE_SEQUENTIAL = 1'b0;
localparam SDMODE_INTERLEAVE = 1'b1;
// localparam SDMODE_BURSTWRITE = 1'b0;
// localparam SDMODE_SINGLEWRITE = 1'b0;

if( !(DATA_WIDTH == 8 || DATA_WIDTH == 16 || DATA_WIDTH == 32))
    $error("unsupported data width: %d", DATA_WIDTH);

localparam int BURST_SIZE = (DATA_WIDTH == 32) ? 2 : 1;
localparam BURST_MODE = BURST_SIZE == 2 ? SDMODE_BURST2 : SDMODE_BURST1;

localparam sdmode = ROW_WIDTH'({3'b0, CAS_LATENCY[2:0], SDMODE_SEQUENTIAL, BURST_MODE});

// control signals
(* keep="true",mark_debug="true" *) logic [2:0] state;
logic [2:0] state_next;
logic new_state;
logic [CNT_W-1:0] cnt, state_delay;
logic first_cycle, last_cycle;
logic [CNT2_W-1:0] cnt2;
logic trigger_refresh, refresh_ack;
logic boot_delay, booting;
logic rd;
logic [WORD_LEN-1:0] wr;

// command port signals
logic rdy, rvalid, wvalid, req, valid_req;
assign ctrl_if.rvalid = rvalid;
assign ctrl_if.wvalid = wvalid;
assign ctrl_if.error = 0;
assign ctrl_if.rdy = rdy;
assign req = ctrl_if.rd | (ctrl_if.wr != 0);
assign valid_req = rdy & req;

// sdram port signals
(* keep="true",mark_debug="true" *) logic [2:0] sd_cmd;
assign dev_if.cmd = sd_cmd;
logic [1:0] bank;
logic [ROW_WIDTH-1:0] row;
logic [COL_WIDTH-1:0] col;
logic byte_misalign;
logic [DATA_WIDTH-1:0] write_data;
(* keep="true",mark_debug="true" *) logic sd_wr, sd_rd, sd_rd2;

assign last_cycle = (cnt==state_delay);

always_ff @(posedge clk)
begin
    if(DATA_WIDTH == 32) sd_rd2 <= sd_rd;

    // count cycles within each state
    cnt <= cnt+1;
    first_cycle <= 0;

    if(last_cycle) begin
        state <= state_next;
        cnt <= '0;
        first_cycle <= 1;
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
        // valid ctrl_if address range is DEV_ADDR_WIDTH+1 bits
        // LSB indicates whether address is aligned to 16bit word
        {bank, row, col, byte_misalign} <= ctrl_if.addr[DEV_ADDR_WIDTH:0];
        rd <= ctrl_if.rd;
        wr <= ctrl_if.wr;
        write_data <= ctrl_if.write_data;
    end

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
        rd <= 0;
        wr <= '0;
        write_data <= '0;
        sd_rd2 <= 0;
    end 
end

// state machine
always @(*)
begin
    dev_if.cke = 1'b1;
    dev_if.addr = '0;
    dev_if.ba = 2'b0;
    dev_if.cs = 1'b0;
    sd_cmd = SDRAM_NOP;
    sd_rd = 0;
    sd_wr = 0;

    rdy = 0;
    state_next = state;
    boot_delay = 0;
    state_delay = '0;
    refresh_ack = 0;
    rvalid = 0;
    wvalid = 0;

    case(state)
        STATE_BOOT: begin 
            boot_delay = 1;
            if (booting) state_next = STATE_PRECHARGE;
        end
        STATE_PRECHARGE: begin 
            if(first_cycle) sd_cmd = SDRAM_PRECHARGE; // Precharge all banks            
            dev_if.addr[10] = 1'b1;
            state_delay = 10; //`DELAY(DELAY_RP-1, CNT_W);
            state_next = booting ? STATE_MODESET : STATE_IDLE;
        end
        STATE_MODESET: begin
            if(first_cycle) sd_cmd = SDRAM_MODE_SET;
            dev_if.addr = sdmode;
            dev_if.ba = 2'b0;
            state_delay = 10; //`DELAY(DELAY_RSC-2, CNT_W);
            state_next = STATE_REFRESH;
        end
        STATE_REFRESH: begin
            if(first_cycle) sd_cmd = SDRAM_AUTO_REFRESH;
            refresh_ack = 1;
            state_delay = `DELAY(DELAY_RC-1, CNT_W);
            state_next = STATE_IDLE;
        end
        STATE_IDLE: begin  
            if( trigger_refresh ) begin
                rdy = 0;
                state_next = STATE_REFRESH;
            end else begin
                rdy = 1;
                if(req) state_next = STATE_ACTIVATE;
            end
        end
        STATE_ACTIVATE: begin
            if(first_cycle) sd_cmd = SDRAM_ACTIVATE;
            dev_if.addr = row;
            dev_if.ba = bank;
            // we only activate during either a read or write request
            state_next = rd ? STATE_READ : STATE_WRITE; 
            state_delay = 1; //`DELAY(DELAY_RCD-1, CNT_W);
        end
        STATE_READ: begin 
            if(first_cycle) sd_cmd = SDRAM_READ;
            dev_if.ba = bank;
            dev_if.addr[COL_WIDTH-1:0] = col;
            dev_if.addr[10] = 1'b1; // auto precharge
            /* verilator lint_off WIDTHEXPAND */
            sd_rd = (cnt == (CAS_LATENCY-1));
            /* verilator lint_on WIDTHEXPAND */
            state_delay = `DELAY(CAS_LATENCY+BURST_SIZE-1, CNT_W);
            state_next = STATE_IDLE;
            rvalid = last_cycle;
        end
        STATE_WRITE: begin 
            if(first_cycle) begin
                sd_cmd = SDRAM_WRITE;
                sd_wr = 1'b1;
            end
            dev_if.ba = bank;
            dev_if.addr[COL_WIDTH-1:0] = col;
            dev_if.addr[10] = 1'b1; // auto precharge
            state_next = STATE_IDLE;
            state_delay = `DELAY(`MAX(BURST_SIZE-1, DELAY_DAL-1), CNT_W);
            wvalid = last_cycle;
        end
        default: begin end
    endcase
end

// register read data
(* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *)  logic [15:0] data_rd_reg0, data_rd_reg1;
always_ff @(posedge clk) begin
    data_rd_reg0 <= dev_if.read_data;
    data_rd_reg1 <= data_rd_reg0;
    if (rst) begin
        data_rd_reg0 <= '0;
        data_rd_reg1 <= '0;
    end
end
wire [DATA_WIDTH-1:0] data_read;
generate
    if(DATA_WIDTH == 8) begin
        assign data_read = byte_misalign ? data_rd_reg0[15:8] : data_rd_reg0[7:0];
    end else if(DATA_WIDTH == 16) begin
        assign data_read = data_rd_reg0;
    end else begin //DATA_WIDTH == 32
        assign data_read = {data_rd_reg0, data_rd_reg1};
    end
endgenerate
assign ctrl_if.read_data = rvalid ? data_read : '0;

// write data and mask
logic [1:0] wr_mask;
logic [15:0] wr_data;
logic wr_en;
generate
    if(DATA_WIDTH == 8) begin
        assign wr_en = sd_wr;
        assign wr_mask = {~byte_misalign, byte_misalign};
        assign wr_data = {write_data, write_data};
    end else if(DATA_WIDTH == 16) begin
        assign wr_mask = sd_wr ? ~wr : '0;
        assign wr_data = sd_wr ? write_data : '0;
    end else begin //DATA_WIDTH == 32
        logic sd_wr2;
        always_ff @(posedge clk) begin
            sd_wr2 <= sd_wr;
            if (rst) begin
                sd_wr2 <= '0;
            end
        end
        assign wr_en = sd_wr | sd_wr2;
        assign wr_data = sd_wr2 ? write_data[31:16] : write_data[15:0];
        assign wr_mask = sd_wr2 ? ~wr[3:2]: ~wr[1:0];
    end
endgenerate
assign dev_if.write_data = wr_en ? wr_data : '0;;
assign dev_if.wr_en = wr_en;
assign dev_if.dqm = boot_delay ? 2'b11 :
                    wr_en ? wr_mask :
                    '0;

endmodule