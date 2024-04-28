`timescale 1ns / 100ps

// sdram controller with separate ports for two banks
// ram clocked 8x application clock
// every 8 ram cycles is read/write for each bank
// dual banks enabled
// cycle 0:   Activate Bank 0
// cycle 1:   Activate Bank 1
// cycle 2:   Write Bank 0
// cycle 3:   Write Bank 1
// cycle 4:   Read Bank 0 
// cycle 5:   Read Bank 1
// cycle 6:   Data valid Bank 0 
// cycle 7:   Data valid Bank 1 (sync & sample next cmd)

// one bank enabled
// cycle 0:   Activate Bank
// cycle 1:   NOP
// cycle 2:   Read or Write Bank
// cycle 3:   NOP
// cycle 4:   Data valid Bank  
// cycle 5:   Auto Refresh
// cycle 6:   NOP
// cycle 7:   NOP (sync & sample next cmd)

module sdram_controller_multibank #(
    parameter ADDR_DEPTH            = 23, // per bank
    parameter COL_DEPTH             = 10,
    parameter TICKS_REFRESH         = 36,
    parameter TICKS_STARTUP         = 1500
    )(
    // main clocks
    input logic clk, rst,
    output logic rdy,        // indicates controller is ready for rd/wr commands
    input logic enable_refresh,

    output logic sync,       // high on cycle that port command (rd/wr/addr) is sampled
                             // read data will be valid on (or before) following sync

    //bank 0 interface
    input logic [7:0] data_wr0,
    input logic [ADDR_DEPTH-1:0] addr0,
    input logic rw0,
    input logic en0,
    output logic [7:0] data_rd0,

    //bank 1 interface
    input logic [7:0] data_wr1,
    input logic [ADDR_DEPTH-1:0] addr1,
    input logic rw1,
    input logic en1,
    output logic [7:0] data_rd1,

    // sdram pins
    output logic [12:0] sdram_a,
    output logic [1:0] sdram_bs,
    output logic sdram_cs_n,
    output logic sdram_ras_n,
    output logic sdram_cas_n,
    output logic sdram_we_n,
    output logic [1:0] sdram_dqm,
    output logic sdram_cke,
    inout logic [15:0] sdram_dq
);

// sdram control words for sdram_cmd: {~ras, ~cas, ~we}
localparam SDRAM_ACTIVATE           =   3'b011;
localparam SDRAM_PRECHARGE          =   3'b010; //set A10 for all banks
localparam SDRAM_WRITE              =   3'b100; //set A10 for auto precharge
localparam SDRAM_READ               =   3'b101; //set A10 for auto precharge
localparam SDRAM_MODE_SET           =   3'b000;
localparam SDRAM_NOP                =   3'b111;
localparam SDRAM_AUTO_REFRESH       =   3'b001;
// unused cmds:
// localparam SDRAM_BURST_STOP         =   3'b110;
// localparam SDRAM_SELF_REFRESH_ENTRY =   3'b001; //cke H->L
// localparam SDRAM_SELF_REFRESH_EXIT  =   3'b110; //cke L->H
// localparam SDRAM_ACTIVE_POWER_DOWN  =   3'b110; //cke H->L
// localparam SDRAM_POWER_DOWN_EXIT    =   3'b110; //cke L->H

localparam STATE_BOOT       = 3'h0;
localparam STATE_PRECHARGE  = 3'h1;
localparam STATE_MODESET    = 3'h2;
localparam STATE_REFRESH    = 3'h3;
localparam STATE_MAIN       = 3'h4;
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
localparam SDMODE_BURSTWRITE = 1'b0;
localparam SDMODE_SINGLEWRITE = 1'b0;
localparam CAS_LATENCY           = 3'h2;
localparam sdmode = {5'b0, SDMODE_SINGLEWRITE, 2'b0, CAS_LATENCY, SDMODE_SEQUENTIAL, SDMODE_BURST1};


logic sdram_rd, sdram_wr, byte_ul;
logic [7:0] dwr;
logic [15:0] sdram_dq_buf;

always @(*)
begin
    sdram_dq_buf = 16'bz;
    if(sdram_wr) begin
        if (byte_ul) sdram_dq_buf[15:8] = dwr;
        else sdram_dq_buf[7:0] = dwr;
    end
end
assign sdram_dq = sdram_dq_buf;

logic [2:0] cycle; // 8 count cycles
assign sync = cycle==3'h7;
logic [11:0] ticks;
wire ticks_zero = ticks == 0;
logic reset_ticks;

logic [3:0] state, state_next;

logic [2:0] sdram_cmd;
assign {sdram_ras_n, sdram_cas_n, sdram_we_n} = sdram_cmd;

logic rw_b0, en_b0, rw_b1, en_b1;
logic [ADDR_DEPTH-1:0] addr_b0, addr_b1;
logic [7:0] dwr_b0, dwr_b1;

// register read commands per CAS latency
logic sdram_rd_r1; 
logic active_bank_r1;
logic byte_ul_r1;

always_ff @(posedge clk)
begin
    if (rst) begin
        state <= STATE_BOOT;
        ticks <= TICKS_STARTUP;
        cycle <= 0;
        sdram_rd_r1 <= 0;
        active_bank_r1 <= 0;
    end else begin
            
        cycle <= cycle + 1;

        if(sync) begin
            if (rdy) begin
                // register commands
                addr_b0 <= addr0;
                rw_b0 <= rw0;
                en_b0 <= en0;
                dwr_b0 <= data_wr0;
                addr_b1 <= addr1;
                rw_b1 <= rw1;
                en_b1 <= en1;
                dwr_b1 <= data_wr1;
            end else begin
                addr_b0 <= 0;
                rw_b0 <= 0;
                en_b0 <= 0;
                dwr_b0 <= 0;
                addr_b1 <= 0;
                rw_b1 <= 0;
                en_b1 <= 0;
                dwr_b1 <= 0;
            end                
            ticks <= ticks_zero ? 0 : ticks - 1;
        end

        sdram_rd_r1 <= sdram_rd;
        active_bank_r1 <= active_bank;
        byte_ul_r1 <= byte_ul;
        if(sdram_rd_r1) begin
            // register read data
            if (active_bank_r1) data_rd1 <= byte_ul_r1 ? sdram_dq[15:8] : sdram_dq[7:0];
            else data_rd0 <= byte_ul_r1 ? sdram_dq[15:8] : sdram_dq[7:0];
        end

        state <= state_next;
        if (reset_ticks) ticks <= 8;
    end
end

localparam ROW_DEPTH = ADDR_DEPTH-COL_DEPTH-1;
logic [ROW_DEPTH-1:0] row;
logic [COL_DEPTH-1:0] col;
logic active_bank, dual_bank, enable_cycle, rw;

always @(*)
begin
    sdram_a = 13'b0;
    sdram_bs = 2'b0;
    sdram_cs_n = 1'b0;
    sdram_dqm = 2'b11;
    sdram_cke = 1'b1;
    sdram_cmd = SDRAM_NOP;
    rdy = 0;
    reset_ticks = 0;
    state_next = state;

    sdram_wr = 0;
    sdram_rd = 0;

    enable_cycle = 0;
    dual_bank = 0;
    active_bank = 0;
    rw = 0;
    row = 0;
    col = 0;
    byte_ul = 0;

    case(state)
        // boot sequence is:
        //      >200us of NOP
        //      precharge all
        //      set mode reg
        //      refresh 8x
        //      main loop
        STATE_BOOT: begin 
            // After power up, an initial pause of 200 μ S is required. To prevent data contention on the DQ bus 
            // during power up, it is required that the DQM and CKE pins be held high during the initial pause period.
            if (ticks_zero) state_next = STATE_PRECHARGE;
        end
        STATE_PRECHARGE: begin 
            sdram_cmd = SDRAM_PRECHARGE;
            sdram_a[10] = 1;
            state_next = STATE_MODESET;
        end
        STATE_MODESET: begin
            sdram_cmd = SDRAM_MODE_SET;
            sdram_a = sdmode;
            sdram_bs = 2'b0;
            state_next = STATE_MAIN;
            reset_ticks = 1; // set delay to ensure 8 referesh cycles before ram is ready
        end
        STATE_MAIN: begin            
            rdy = ticks_zero; // ready for commands once tick count reaches 0

            if(en_b0 || en_b1) begin
                // which bank(s) are active?
                dual_bank = en_b0 && en_b1;
                if (dual_bank) begin
                    // both banks enabled
                    active_bank = cycle[0]; // bank0 gets even cycles, bank1 gets odd cycles
                    enable_cycle = 1;       // all cycles are active
                end else begin
                    // single enabled bank
                    active_bank = en_b1;    // which bank?
                    enable_cycle = !(cycle[2] || cycle[0]); // only active cycles are 0 & 2
                end

                // select data from active bank
                sdram_bs = {1'b0, active_bank};
                if (active_bank == 0) begin
                    {row, col, byte_ul} = addr_b0;
                    rw = rw_b0;
                    dwr = data_wr0;
                end else begin
                    {row, col, byte_ul} = addr_b1;
                    rw = rw_b1;
                    dwr = data_wr1;
                end
            end

            if(enable_cycle) begin

                // default to column address (during activate, override with row below )
                sdram_a = 13'(col);
                sdram_a[10] = 1;                    // set precharge bit
                sdram_dqm = {~byte_ul, byte_ul};    // mask data

                case(cycle[2:1])
                    0:  begin // activate bank(s)
                            sdram_cmd = SDRAM_ACTIVATE; 
                            sdram_a = row;
                        end
                    1:  begin // write cycles
                            if(!rw) begin
                                sdram_cmd = SDRAM_WRITE;
                                sdram_wr = 1;
                            end else if(!dual_bank) begin
                                // on single-bank access, also perform read on this cycle
                                sdram_cmd = SDRAM_READ;
                                sdram_rd = 1;
                            end
                        end
                    2:  begin   // read cycles (dual_bank access)
                            if(dual_bank && rw) begin
                                sdram_cmd = SDRAM_READ;
                                sdram_rd = 1;
                            end
                        end
                    default: begin end //NOP
                endcase
            end else if (cycle == 3'h5 && enable_refresh) begin
                sdram_cmd = SDRAM_AUTO_REFRESH;                
            end
            
        end
        default: begin end
    endcase
end




endmodule