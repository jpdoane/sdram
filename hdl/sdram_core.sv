`timescale 1ns / 100ps

module sdram_core #(
    parameter real FREQ_MHZ     = 50,
    parameter int COL_WIDTH     = 9,
    parameter int ROW_WIDTH     = 13,
    parameter int BANK_WIDTH    = 2,

    parameter int CAS_LATENCY   = 2,
    parameter real STARTUP_US    = 100.0,       // min time in us to hold in startup before initialization
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
    input logic clk, rst,

    sdram_ctrl_if.sub ctrl_if,
    sdram_dev_if.man dev_if
);

localparam int DEV_ADDR_WIDTH  = COL_WIDTH + ROW_WIDTH + BANK_WIDTH;
localparam int N_BANKS  = 2 ** BANK_WIDTH;

localparam int DATA_WIDTH    = ctrl_if.DATA_WIDTH;
localparam int ADDR_WIDTH    = ctrl_if.ADDR_WIDTH;
localparam int WORD_LEN     = ctrl_if.WORD_LEN;

localparam int CNT_W                = 4;
localparam int CNTRST_W             = 16;
localparam real CLK_PERIOD_NS       = 1000.0 / FREQ_MHZ;
localparam int DELAY_STARTUP        = int'($ceil(STARTUP_US * FREQ_MHZ) + 100);
localparam int DELAY_REF_INTERVAL   = int'($ceil(tREF_NS/8192/CLK_PERIOD_NS));
localparam int DELAY_RC             = int'($ceil(tRC_NS / CLK_PERIOD_NS));
localparam int DELAY_RCD            = int'($ceil(tRCD_NS/CLK_PERIOD_NS));
localparam int DELAY_RP             = int'($ceil(tRP_NS/CLK_PERIOD_NS));

// sdram control words for sd_cmd
localparam CTRL_ACTIVATE           = 3'b011;
localparam CTRL_PRECHARGE          = 3'b010; //A10: all vs bank
localparam CTRL_WRITE              = 3'b100; //A10: auto precharge
localparam CTRL_READ               = 3'b101; //A10: auto precharge
localparam CTRL_MODE_SET           = 3'b000;
localparam CTRL_NOP                = 3'b111;
localparam CTRL_BURST_STOP         = 3'b110;
localparam CTRL_AUTO_REFRESH       = 3'b001;

localparam STATE_BOOT       = 4'h0;
localparam STATE_PRECHARGE  = 4'h1;
localparam STATE_MODESET    = 4'h2;
localparam STATE_REFRESH    = 4'h3;
localparam STATE_IDLE       = 4'h4;
localparam STATE_ACTIVATE   = 4'h5;
localparam STATE_READ       = 4'h6;
localparam STATE_WRITE      = 4'h7;
localparam STATE_READ2      = 4'h8;
localparam STATE_WRITE2     = 4'h9;

localparam SDMODE_BURST1 = 3'h0;
localparam SDMODE_BURST2 = 3'h1;
localparam SDMODE_BURST4 = 3'h2;
localparam SDMODE_BURST8 = 3'h3;
localparam SDMODE_BURSTPAGE = 3'h7;
localparam SDMODE_SEQUENTIAL = 1'b0;
localparam SDMODE_INTERLEAVE = 1'b1;

if( !(DATA_WIDTH == 8 || DATA_WIDTH == 16 || DATA_WIDTH == 32))
    $error("unsupported data width: %d", DATA_WIDTH);

localparam int BURST_SIZE = (DATA_WIDTH == 32) ? 2 : 1;
localparam BURST_MODE = BURST_SIZE == 2 ? SDMODE_BURST2 : SDMODE_BURST1;

localparam sdmode = ROW_WIDTH'({3'b0, CAS_LATENCY[2:0], SDMODE_SEQUENTIAL, BURST_MODE});

// control signals
logic [3:0] state;
logic [3:0] state_next, state_req;
logic new_state;
logic [CNT_W-1:0] cnt, state_delay;
logic first_cycle, last_cycle;
logic [CNTRST_W-1:0] cnt_reset;
logic trigger_refresh, refresh_ack, boot_complete;
logic open_row, close_row, close_all_rows;
logic active;
logic rd, wr;
logic [WORD_LEN-1:0] wr_strobe;

// command port signals
logic rdy, set_wvalid, set_rvalid, rvalid, wvalid, req, valid_req;
assign ctrl_if.rvalid = rvalid;
assign ctrl_if.wvalid = wvalid;
assign ctrl_if.error = 0;
assign ctrl_if.rdy = rdy;
assign req = ctrl_if.rd | (ctrl_if.wr != 0);
assign valid_req = rdy & req;
assign wr = |wr_strobe;
assign active = rd | wr | valid_req;

// sdram dev signals
logic [2:0] sd_cmd;
logic [BANK_WIDTH-1:0] bank, bank_req, sd_ba;
logic [ROW_WIDTH-1:0] row, row_req, sd_addr;
logic [COL_WIDTH-1:0] col, col_req;
logic byte_misalign, byte_req, row_hit;
logic [DATA_WIDTH-1:0] write_data;
logic [N_BANKS-1:0]  row_open;
logic [ROW_WIDTH-1:0]  active_row[N_BANKS-1:0];
logic sd_wr;

wire [DATA_WIDTH-1:0]   read_word;
logic [15:0]            read_data, read_data_r;
logic running;

// assign {bank_req, row_req, col_req, byte_req} = ctrl_if.addr[DEV_ADDR_WIDTH:0];
(* keep = "true" *) wire [DEV_ADDR_WIDTH:0] ctrl_addr = ctrl_if.addr[DEV_ADDR_WIDTH:0];
assign {row_req, bank_req, col_req, byte_req} = ctrl_addr;
assign row_hit = active_row[bank_req] == row_req;

assign last_cycle = cnt==state_delay;
assign read_data = dev_if.read_data;

always_ff @(posedge clk)
begin

    if(boot_complete) running <= 1;
    read_data_r <= read_data;

    // count cycles within each state (counts up)
    cnt <= cnt+1;
    first_cycle <= 0;

    if(last_cycle) begin
        state <= state_next;
        cnt <= '0;
        first_cycle <= 1;
    end

    // secondary counter for boot sequence and refresh (counts down)
    if(cnt_reset==0) begin
        trigger_refresh <= 1;
        cnt_reset <= CNTRST_W'(DELAY_REF_INTERVAL);
    end else cnt_reset <= cnt_reset-1;

    if(refresh_ack) trigger_refresh <= 0;

    if(rvalid) rd <= 0;
    if(wvalid) wr_strobe <= '0;

    rvalid <= set_rvalid;
    wvalid <= set_wvalid;
    
    if (valid_req) begin
        write_data <= ctrl_if.write_data;
        bank <= bank_req;
        row <= row_req;
        col <= col_req;
        byte_misalign <= byte_req;
        rd <= ctrl_if.rd;
        wr_strobe <= ctrl_if.wr;
    end

    if(open_row) begin
        row_open[bank] <= 1;
        active_row[bank] <= row;
    end
    if(close_row) row_open[bank] <= 0;
    if(close_all_rows) row_open <= '0;
    
    if (rst) begin
        state <= STATE_BOOT;
        cnt <= 0;
        first_cycle <= 0;
        cnt_reset <= CNTRST_W'(DELAY_STARTUP);
        trigger_refresh <= 0;
        bank <= 0;
        row <= 0;
        col <= 0;
        byte_misalign <= 0;
        rd <= 0;
        wr_strobe <= '0;
        row_open <= '0;
        read_data_r <= '0;
        running <= 0;
        rvalid <= 0;
        wvalid <= 0;
    end 
end

// state machine
always @(*)
begin
    boot_complete = 0;
    sd_addr = '0;
    sd_ba = 2'b0;
    sd_cmd = CTRL_NOP;
    sd_wr = 0;

    rdy = 0;
    state_next = state;
    state_delay = '0;
    refresh_ack = 0;
    set_rvalid = 0;
    set_wvalid = 0;

    close_row = 0;
    close_all_rows = 0;
    open_row = 0;

    case(state)
        STATE_BOOT: begin 
            case(cnt_reset)
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
            if(first_cycle) sd_cmd = CTRL_PRECHARGE;
            state_delay = CNT_W'(DELAY_RP); //1
            if(rd || (wr != 0)) begin
                sd_ba = bank;
                close_row = 1;  // precharge bank before activating next row
                state_next = STATE_ACTIVATE;
            end else begin
                // if(trigger_refresh) begin
                // must be a refresh
                sd_addr[10] = 1; // Precharge all banks on refresh
                close_all_rows = 1;    
                state_next = STATE_REFRESH;
            end
        end
        STATE_REFRESH: begin
            if(first_cycle) sd_cmd = CTRL_AUTO_REFRESH;
            refresh_ack = 1;
            state_delay = CNT_W'(DELAY_RC-1);
            // state_delay = CNT_W'(4);
            // rdy = last_cycle;
            state_next = active ? STATE_ACTIVATE : STATE_IDLE;
        end
        STATE_IDLE: begin  
            if( trigger_refresh ) begin
                state_next = |row_open ? STATE_PRECHARGE : STATE_REFRESH;
            end else begin
                rdy = 1;
                if(req) begin
                    if (row_open[bank_req]) begin
                        if (row_hit) state_next = ctrl_if.rd ? STATE_READ : STATE_WRITE;
                        else state_next = STATE_PRECHARGE;
                    end else begin
                        state_next = STATE_ACTIVATE;
                    end
                end
            end
        end
        STATE_ACTIVATE: begin
            if(first_cycle) sd_cmd = CTRL_ACTIVATE;
            sd_addr = row;
            sd_ba = bank;
            open_row = 1;
            state_next = rd ? STATE_READ : STATE_WRITE;
            state_delay = CNT_W'(1);
         end
        STATE_READ: begin 
            if(first_cycle) sd_cmd = CTRL_READ;
            sd_ba = bank;
            sd_addr[COL_WIDTH-1:0] = col;
            state_delay = CNT_W'(CAS_LATENCY+BURST_SIZE-2);
            set_rvalid = last_cycle;
            state_next = STATE_IDLE;
        end
        // STATE_READ2: begin 
        //     state_next = STATE_IDLE;
        //     // rdy = 1;
        //     // if(ctrl_if.rd) begin
        //     //     if (row_open[bank_req]) begin
        //     //         if (row_hit) state_req = STATE_READ;
        //     //         else state_req = STATE_PRECHARGE;
        //     //     end else begin
        //     //         state_req = STATE_ACTIVATE;
        //     //     end
        //     // end
        //     // else state_next = STATE_IDLE;
        // end
        STATE_WRITE: begin 
            if(first_cycle) begin
                sd_cmd = CTRL_WRITE;
                sd_wr = 1'b1;
            end
            sd_ba = bank;
            sd_addr[COL_WIDTH-1:0] = col;
            // sd_addr[10] = 1'b1; // auto precharge
            set_wvalid = last_cycle;
            state_next = STATE_IDLE;
        end
        // STATE_WRITE2: begin 
        //     set_wvalid = 1;
        //     state_next = STATE_IDLE;
        //     // rdy = 1;
        //     // if(!ctrl_if.wr) begin
        //     //     if (row_open[bank_req]) begin
        //     //         if (row_hit) state_next = STATE_WRITE;
        //     //         else state_next = STATE_PRECHARGE;
        //     //     end else begin
        //     //         state_next = STATE_ACTIVATE;
        //     //     end
        //     // end            
        //     // else state_next = STATE_IDLE;
        // end        
        default: begin end
    endcase
end

// write data and mask
logic [1:0] wr_mask;
logic [15:0] wr_data;
logic wr_en;
generate
    if(DATA_WIDTH == 8) begin
        assign wr_en = sd_wr;
        assign wr_mask = {~byte_misalign, byte_misalign};
        assign wr_data = {write_data, write_data};
        assign read_word = byte_misalign ? read_data[15:8] : read_data[7:0];
    end else if(DATA_WIDTH == 16) begin
        assign wr_mask = sd_wr ? ~wr_strobe : '0;
        assign wr_data = sd_wr ? write_data : '0;
        assign read_word = read_data;
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
        assign wr_mask = sd_wr2 ? ~wr_strobe[3:2]: ~wr_strobe[1:0];
        assign read_word = {read_data, read_data_r};
    end
endgenerate

assign ctrl_if.read_data = rvalid ? read_word : '0;

assign dev_if.cke = running;
assign dev_if.cs = '0;
assign dev_if.cmd = sd_cmd;
assign dev_if.dqm = wr_en ? wr_mask : '0;;
assign dev_if.addr = sd_addr;
assign dev_if.ba = sd_ba;
assign dev_if.write_data = wr_data;
assign dev_if.wr_en = wr_en;


endmodule