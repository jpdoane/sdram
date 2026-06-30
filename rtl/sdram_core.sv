`timescale 1ns/1ps

module sdram_core #(
    parameter real FREQ_MHZ     = 50,
    parameter int COL_WIDTH     = 9,
    parameter int ROW_WIDTH     = 13,
    parameter int BANK_WIDTH    = 2,
    parameter int DATA_WIDTH    = 32,
    parameter int ADDR_WIDTH    = 25,       // *Byte address* width == BANK_WIDTH + COL_WIDTH + ROW_WIDTH + 1

    parameter int CAS_LATENCY   = 2,
    parameter real STARTUP_US   = 100.0,    // min time in us before initialization
    parameter real tRC_NS       = 60.0,     // min time between row activations (same bank)
    parameter real tRAS_NS      = 42.0,     // min time from row activation to precharge
    parameter real tRCD_NS      = 15.0,     // min time from row activation to read/write
    parameter real tRP_NS       = 15.0,     // min time from precharge to refresh/activation
    parameter real tXSR_NS      = 72.0,     // min time from self-refresh exit to activation
    parameter real tREF_NS      = 64e6,     // max time to perform all 8k refresh cycles
    parameter int DELAY_WR      = 2,
    parameter int DELAY_RRD     = 2,
    parameter int DELAY_RSC     = 2
)(
    input  logic clk,
    input  logic rst,

    // SDRAM controller interface (from arbiter / AXI bridge)
    input  logic [DATA_WIDTH/8-1:0]  ctrl_wr,         // byte write strobe (0 = read)
    input  logic                     ctrl_rd,          // read request
    input  logic [ADDR_WIDTH-1:0]    ctrl_addr,
    input  logic [DATA_WIDTH-1:0]    ctrl_write_data,
    output logic                     ctrl_rdy,
    output logic                     ctrl_rvalid,
    output logic                     ctrl_wvalid,
    output logic                     ctrl_error,
    output logic [DATA_WIDTH-1:0]    ctrl_read_data,

    // SDRAM device interface (to sdram_io / model)
    output logic                     dev_cke,
    output logic                     dev_cs,
    output logic [2:0]               dev_cmd,
    output logic [1:0]               dev_dqm,
    output logic [ROW_WIDTH-1:0]     dev_addr,
    output logic [BANK_WIDTH-1:0]    dev_ba,
    output logic [15:0]              dev_write_data,
    output logic                     dev_wr_en,
    input  logic [15:0]              dev_read_data
);

localparam int WORD_LEN        = DATA_WIDTH / 8;
localparam int DEV_ADDR_WIDTH  = COL_WIDTH + ROW_WIDTH + BANK_WIDTH;
localparam int N_BANKS         = 2 ** BANK_WIDTH;

localparam int CNT_W           = 4;
localparam int CNTRST_W        = 16;
localparam real CLK_PERIOD_NS  = 1000.0 / FREQ_MHZ;
localparam int DELAY_STARTUP   = int'($ceil(STARTUP_US * FREQ_MHZ) + 100);
localparam int DELAY_REF_INTERVAL = int'($ceil(tREF_NS/8192/CLK_PERIOD_NS));
localparam int DELAY_RC        = int'($ceil(tRC_NS / CLK_PERIOD_NS));
localparam int DELAY_RCD       = int'($ceil(tRCD_NS/CLK_PERIOD_NS));
localparam int DELAY_RP        = int'($ceil(tRP_NS/CLK_PERIOD_NS));

// SDRAM command encoding
localparam CTRL_ACTIVATE     = 3'b011;
localparam CTRL_PRECHARGE    = 3'b010;
localparam CTRL_WRITE        = 3'b100;
localparam CTRL_READ         = 3'b101;
localparam CTRL_MODE_SET     = 3'b000;
localparam CTRL_NOP          = 3'b111;
localparam CTRL_BURST_STOP   = 3'b110;
localparam CTRL_AUTO_REFRESH = 3'b001;

localparam STATE_BOOT      = 4'h0;
localparam STATE_PRECHARGE = 4'h1;
localparam STATE_MODESET   = 4'h2;
localparam STATE_REFRESH   = 4'h3;
localparam STATE_IDLE      = 4'h4;
localparam STATE_ACTIVATE  = 4'h5;
localparam STATE_READ      = 4'h6;
localparam STATE_WRITE     = 4'h7;
localparam STATE_READ2     = 4'h8;
localparam STATE_WRITE2    = 4'h9;

localparam SDMODE_BURST1     = 3'h0;
localparam SDMODE_BURST2     = 3'h1;
localparam SDMODE_BURST4     = 3'h2;
localparam SDMODE_BURST8     = 3'h3;
localparam SDMODE_BURSTPAGE  = 3'h7;
localparam SDMODE_SEQUENTIAL = 1'b0;
localparam SDMODE_INTERLEAVE = 1'b1;

if (!(DATA_WIDTH == 8 || DATA_WIDTH == 16 || DATA_WIDTH == 32))
    $error("unsupported data width: %d", DATA_WIDTH);

localparam int BURST_SIZE = (DATA_WIDTH == 32) ? 2 : 1;
localparam BURST_MODE = BURST_SIZE == 2 ? SDMODE_BURST2 : SDMODE_BURST1;
localparam sdmode = ROW_WIDTH'({3'b0, CAS_LATENCY[2:0], SDMODE_SEQUENTIAL, BURST_MODE});

// State machine
logic [3:0] state, state_next;
logic [CNT_W-1:0] cnt, state_delay;
logic first_cycle, last_cycle;
logic [CNTRST_W-1:0] cnt_reset;
logic trigger_refresh, refresh_ack, boot_complete;
logic open_row, close_row, close_all_rows;
logic active;
logic rd, wr;
logic [WORD_LEN-1:0] wr_strobe;

// Controller port signals
logic rdy, set_wvalid, set_rvalid, rvalid, wvalid, req, valid_req;
assign ctrl_rvalid    = rvalid;
assign ctrl_wvalid    = wvalid;
assign ctrl_error     = 0;
assign ctrl_rdy       = rdy;
assign req            = ctrl_rd | (ctrl_wr != 0);
assign valid_req      = rdy & req;
assign wr             = |wr_strobe;
assign active         = rd | wr | valid_req;

// SDRAM device signals
logic [2:0] sd_cmd;
logic [BANK_WIDTH-1:0] bank, bank_req, sd_ba;
logic [ROW_WIDTH-1:0]  row, row_req, sd_addr;
logic [COL_WIDTH-1:0]  col, col_req;
logic byte_misalign, byte_req, row_hit;
logic [DATA_WIDTH-1:0] write_data;
logic [N_BANKS-1:0]    row_open;
logic [ROW_WIDTH-1:0]  active_row [N_BANKS-1:0];
logic sd_wr;

wire  [DATA_WIDTH-1:0] read_word;
logic [15:0]           read_data_in, read_data_r;
logic running;

(* keep = "true" *) wire [DEV_ADDR_WIDTH:0] c_addr = unsigned'(ctrl_addr);

assign {row_req, bank_req, col_req, byte_req} = c_addr;
assign row_hit    = active_row[bank_req] == row_req;
assign last_cycle = cnt == state_delay;
assign read_data_in = dev_read_data;

always_ff @(posedge clk) begin
    if (boot_complete) running <= 1;
    read_data_r <= read_data_in;

    cnt        <= cnt + 1;
    first_cycle <= 0;

    if (last_cycle) begin
        state       <= state_next;
        cnt         <= '0;
        first_cycle <= 1;
    end

    if (cnt_reset == 0) begin
        trigger_refresh <= 1;
        cnt_reset       <= CNTRST_W'(DELAY_REF_INTERVAL);
    end else cnt_reset <= cnt_reset - 1;

    if (refresh_ack)  trigger_refresh <= 0;
    if (rvalid)       rd              <= 0;
    if (wvalid)       wr_strobe       <= '0;

    rvalid <= set_rvalid;
    wvalid <= set_wvalid;

    if (valid_req) begin
        write_data    <= ctrl_write_data;
        bank          <= bank_req;
        row           <= row_req;
        col           <= col_req;
        byte_misalign <= byte_req;
        rd            <= ctrl_rd;
        wr_strobe     <= ctrl_wr;
    end

    if (open_row)       begin row_open[bank]  <= 1; active_row[bank] <= row; end
    if (close_row)      row_open[bank]  <= 0;
    if (close_all_rows) row_open        <= '0;

    if (rst) begin
        state           <= STATE_BOOT;
        cnt             <= 0;
        first_cycle     <= 0;
        cnt_reset       <= CNTRST_W'(DELAY_STARTUP);
        trigger_refresh <= 0;
        bank            <= 0;
        row             <= 0;
        col             <= 0;
        byte_misalign   <= 0;
        rd              <= 0;
        wr_strobe       <= '0;
        row_open        <= '0;
        read_data_r     <= '0;
        running         <= 0;
        rvalid          <= 0;
        wvalid          <= 0;
    end
end

// State machine (combinatorial)
always_comb begin
    boot_complete = 0;
    sd_addr       = '0;
    sd_ba         = '0;
    sd_cmd        = CTRL_NOP;
    sd_wr         = 0;

    rdy        = 0;
    state_next = state;
    state_delay = '0;
    refresh_ack  = 0;
    set_rvalid   = 0;
    set_wvalid   = 0;

    close_row      = 0;
    close_all_rows = 0;
    open_row       = 0;

    case (state)
        STATE_BOOT: begin
            case (cnt_reset)
                50: boot_complete = 1;
                40: begin sd_cmd = CTRL_PRECHARGE; sd_addr[10] = 1'b1; end
                30: sd_cmd = CTRL_AUTO_REFRESH;
                20: sd_cmd = CTRL_AUTO_REFRESH;
                10: begin sd_cmd = CTRL_MODE_SET; sd_addr = sdmode; end
                default: sd_cmd = CTRL_NOP;
            endcase
            state_next = trigger_refresh ? STATE_IDLE : STATE_BOOT;
        end
        STATE_PRECHARGE: begin
            if (first_cycle) sd_cmd = CTRL_PRECHARGE;
            state_delay = CNT_W'(DELAY_RP);
            if (rd || (wr != 0)) begin
                sd_ba     = bank;
                close_row = 1;
                state_next = STATE_ACTIVATE;
            end else begin
                sd_addr[10]    = 1;
                close_all_rows = 1;
                state_next     = STATE_REFRESH;
            end
        end
        STATE_REFRESH: begin
            if (first_cycle) sd_cmd = CTRL_AUTO_REFRESH;
            refresh_ack = 1;
            state_delay = CNT_W'(DELAY_RC-1);
            state_next  = active ? STATE_ACTIVATE : STATE_IDLE;
        end
        STATE_IDLE: begin
            if (trigger_refresh) begin
                state_next = |row_open ? STATE_PRECHARGE : STATE_REFRESH;
            end else begin
                rdy = 1;
                if (req) begin
                    if (row_open[bank_req]) begin
                        if (row_hit) state_next = ctrl_rd ? STATE_READ : STATE_WRITE;
                        else         state_next = STATE_PRECHARGE;
                    end else begin
                        state_next = STATE_ACTIVATE;
                    end
                end
            end
        end
        STATE_ACTIVATE: begin
            if (first_cycle) sd_cmd = CTRL_ACTIVATE;
            sd_addr    = row;
            sd_ba      = bank;
            open_row   = 1;
            state_next = rd ? STATE_READ : STATE_WRITE;
            state_delay = CNT_W'(1);
        end
        STATE_READ: begin
            if (first_cycle) sd_cmd = CTRL_READ;
            sd_ba      = bank;
            sd_addr[COL_WIDTH-1:0] = col;
            state_delay = CNT_W'(CAS_LATENCY + BURST_SIZE - 1);
            set_rvalid = last_cycle;
            state_next = STATE_IDLE;
        end
        STATE_WRITE: begin
            if (first_cycle) begin
                sd_cmd = CTRL_WRITE;
                sd_wr  = 1'b1;
            end
            sd_ba      = bank;
            sd_addr[COL_WIDTH-1:0] = col;
            set_wvalid = last_cycle;
            state_next = STATE_IDLE;
        end
        default: begin end
    endcase
end

// Write data / mask generation
logic [1:0]  wr_mask;
logic [15:0] wr_data;
logic        wr_en;

generate
    if (DATA_WIDTH == 8) begin
        assign wr_en   = sd_wr;
        assign wr_mask = {~byte_misalign, byte_misalign};
        assign wr_data = {write_data, write_data};
        assign read_word = byte_misalign ? read_data_in[15:8] : read_data_in[7:0];
    end else if (DATA_WIDTH == 16) begin
        assign wr_mask   = sd_wr ? ~wr_strobe : '0;
        assign wr_data   = sd_wr ? write_data : '0;
        assign read_word = read_data_in;
    end else begin // DATA_WIDTH == 32
        logic sd_wr2;
        always_ff @(posedge clk) begin
            sd_wr2 <= sd_wr;
            if (rst) sd_wr2 <= '0;
        end
        assign wr_en   = sd_wr | sd_wr2;
        assign wr_data = sd_wr2 ? write_data[31:16] : write_data[15:0];
        assign wr_mask = sd_wr2 ? ~wr_strobe[3:2]   : ~wr_strobe[1:0];
        assign read_word = {read_data_in, read_data_r};
    end
endgenerate

assign ctrl_read_data = rvalid ? read_word : '0;

assign dev_cke        = running;
assign dev_cs         = '0;
assign dev_cmd        = sd_cmd;
assign dev_dqm        = wr_en ? wr_mask : '0;
assign dev_addr       = sd_addr;
assign dev_ba         = sd_ba;
assign dev_write_data = wr_data;
assign dev_wr_en      = wr_en;

endmodule
