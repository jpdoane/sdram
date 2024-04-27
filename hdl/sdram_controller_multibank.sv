`timescale 1ns / 100ps

// sdram controller with separate ports for two banks
// ram clocked 8x application clock
// every 8 ram cycles is read/write for each bank
// cycle 0:   Activate Bank 0
// cycle 1:   Activate Bank 1
// cycle 2:   Read/Write Bank 0
// cycle 3:   Read/Write Bank 1
// cycle 4:   Data valid Bank 0 
// cycle 5:   Data valid Bank 1 (& autorefresh as needed)
// cycle 6:   NOP
// cycle 7:   sync, sample port interface commands

// cycle 0:   Activate Bank 0
// cycle 1:   Activate Bank 1
// cycle 2:   Write Bank 0
// cycle 3:   Write Bank 1
// cycle 4:   Read Bank 0 
// cycle 5:   Read Bank 1
// cycle 6:   Data valid Bank 0 
// cycle 7:   Data valid Bank 1 (sync & sample next cmd)

module sdram_controller_multibank #(
    parameter ADDR_DEPTH            = 23, // per bank
    parameter COL_DEPTH             = 10,
    parameter TICKS_REFRESH         = 36,
    parameter TICKS_STARTUP         = 1500
    )(
    // main clocks
    input logic clk, rst,
    output logic rdy,        // indicates controller is ready for rd/wr commands

    output logic sync,       // high on cycle that port command (rd/wr/addr) is sampled
                             // read data will be valid on (or before) following sync

    //bank 0 interface
    input logic [7:0] data_wr0,
    input logic [ADDR_DEPTH-1:0] addr0,
    input logic rd0, wr0,
    output logic [7:0] data_rd0,

    //bank 1 interface
    input logic [7:0] data_wr1,
    input logic [ADDR_DEPTH-1:0] addr1,
    input logic rd1, wr1,
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

logic sdram_rd, sdram_wr, ul;
logic [7:0] dwr, drd;
logic [15:0] sdram_dq_buf;

always @(*)
begin
    drd = ul ? sdram_dq[15:8] : sdram_dq[7:0];

    sdram_dq_buf = 16'bz;
    if(sdram_wr) begin
        if (ul) sdram_dq_buf[15:8] = dwr;
        else sdram_dq_buf[7:0] = dwr;
    end
end
assign sdram_dq = sdram_dq_buf;

// sdram control words for sdram_cmd
localparam SDRAM_ACTIVATE           =   3'b011;
localparam SDRAM_PRECHARGE          =   3'b010; //A10: all vs bank
localparam SDRAM_WRITE              =   3'b100; //A10: auto precharge
localparam SDRAM_READ               =   3'b101; //A10: auto precharge
localparam SDRAM_MODE_SET           =   3'b000;
localparam SDRAM_NOP                =   3'b111;
localparam SDRAM_BURST_STOP         =   3'b110;
localparam SDRAM_AUTO_REFRESH       =   3'b001; //cke H->H
localparam SDRAM_SELF_REFRESH_ENTRY =   3'b001; //cke H->L
localparam SDRAM_SELF_REFRESH_EXIT  =   3'b110; //cke L->H
localparam SDRAM_ACTIVE_POWER_DOWN  =   3'b110; //cke H->L
localparam SDRAM_POWER_DOWN_EXIT    =   3'b110; //cke L->H

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

logic [2:0] cycle; // 8 count cycles
assign sync = cycle==3'h7;
logic [11:0] ticks;
logic reset_ticks;
logic [3:0] state, state_next;


logic [2:0] sdram_cmd;
assign {sdram_ras_n, sdram_cas_n, sdram_we_n} = sdram_cmd;

logic rd_b0, wr_b0, rd_b1, wr_b1;
logic [ADDR_DEPTH-1:0] addr_b0, addr_b1;
logic [7:0] dwr_b0, dwr_b1;

logic sdram_rd_r1, sdram_rd_r2; // delay reads by two cycles
always_ff @(posedge clk)
begin
    if (rst) begin
        state <= STATE_BOOT;
        ticks <= 0;
        cycle <= 0;
        sdram_rd_r1 <= 0;
        sdram_rd_r2 <= 0;
    end else begin
            
        cycle <= cycle + 1;

        if(sync) begin
            if (rdy) begin
                addr_b0 <= addr0;
                rd_b0 <= rd0;
                wr_b0 <= wr0;
                dwr_b0 <= data_wr0;

                addr_b1 <= addr1;
                rd_b1 <= rd1;
                wr_b1 <= wr1;
                dwr_b1 <= data_wr1;
            end
            ticks <= ticks+1;
        end

        sdram_rd_r1 <= sdram_rd;
        sdram_rd_r2 <= sdram_rd_r1;
        if(sdram_rd_r1) begin
            if (cycle[0]) data_rd0 <= drd;
            else data_rd1 <= drd;
        end

        state <= state_next;

        if(reset_ticks) begin
            ticks <= 0;
        end
    end
end



logic wr, rd;
localparam ROW_DEPTH = ADDR_DEPTH-COL_DEPTH-1;
logic [ROW_DEPTH-1:0] row;
logic [COL_DEPTH-1:0] col;
always @(*)
begin
    sdram_a = 13'b0;
    sdram_bs = 2'b0;
    sdram_cs_n = 1'b0;
    sdram_dqm = 2'b11;
    sdram_cke = 1'b1;
    sdram_cmd = SDRAM_NOP;
    rdy = 0;
    state_next = state;
    reset_ticks = 0;

    sdram_wr = 0;
    sdram_rd = 0;

    if(cycle[0]) begin
        // bank 1 cycle
        rd = rd_b1;
        wr = wr_b1;
        {row, col, ul} = addr_b1;
        dwr = dwr_b1;
    end else begin
        // bank 0 cycle
        rd = rd_b0;
        wr = wr_b0;
        {row, col, ul} = addr_b0;
        dwr = dwr_b0;
    end

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
            if (ticks == TICKS_STARTUP-1) begin
                reset_ticks = 1;
                state_next = STATE_PRECHARGE;
            end
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
            state_next = STATE_REFRESH;
            reset_ticks = 1;
        end
        STATE_REFRESH: begin
            if(sync) begin
                if (ticks == 8) begin
                    // proceed to main loop afer 8 refresh cycles
                    reset_ticks = 1;
                    state_next = STATE_MAIN;
                end else begin
                    sdram_cmd = SDRAM_AUTO_REFRESH;
                end
            end
        end
        STATE_MAIN: begin            
            rdy = 1;
            sdram_bs = {1'b0,cycle[0]};
            if(rd || wr) begin
                case(cycle[2:1])
                    0: begin   // activate bank
                            sdram_cmd = SDRAM_ACTIVATE;
                            sdram_a = row;
                        end
                    1:  begin   // read or write
                            sdram_a = 13'(col);
                            sdram_a[10] = 1;          // set precharge bit
                            sdram_dqm = {~ul, ul};    // mask data
                            if (wr) begin 
                                sdram_cmd = SDRAM_WRITE;
                                sdram_wr = 1;
                            end else begin
                                sdram_cmd = SDRAM_READ;
                                sdram_rd = 1;
                            end
                        end
                    // 2:  sdram_dqm = {~ul, ul};    // mask data for readback
                    default: begin end //NOP
                endcase
            end
            
            if (cycle == 3'h5 && ticks==TICKS_REFRESH-1) begin
                // refresh as needed (overlap with bank 1 readback)
                sdram_cmd = SDRAM_AUTO_REFRESH;                
                reset_ticks = 1;
            end
            
        end
        default: begin end
    endcase
end


endmodule