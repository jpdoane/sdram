`timescale 1ns/1ps
`define MAX(a,b) ((a > b) ? a : b)

module sdram_core_8bit #(
    parameter ADDR_DEPTH            = 25,
    parameter COL_DEPTH             = 10,
    parameter CAS_LATENCY           = 2,
    parameter DELAY_RC              = 3,     // cycles between row activations in same bank
    parameter DELAY_RCD             = 1,     // activation to read/write
    parameter DELAY_RP              = 1,     // precharge to actrivation or refresh 
    parameter DELAY_DAL             = 3,     // cycles after write
    parameter DELAY_REF_INTERVAL    = 340,   // autorefresh after this many cycles
    parameter DELAY_RSC             = 2,     // min clocks after mode register set        
    parameter DELAY_STARTUP         = 10000
    )(
    // main clocks
    input logic clk, rst,

    input logic [7:0] data_wr,
    input logic [ADDR_DEPTH-1:0] addr_in,
    input logic wr,
    input logic rd,
    output logic rdy,
    output logic val,
    output logic [7:0] data_rd,

    // sdram pins
    output logic [12:0] sd_a,
    output logic [1:0] sd_bs,
    output logic sd_cs_n,
    output logic sd_ras_n,
    output logic sd_cas_n,
    output logic sd_we_n,
    output logic sd_udqm, sd_ldqm,
    output logic sd_cke,

    // sdram datra iopins
    input logic [15:0] sd_din,
    output logic [15:0] sd_dout,
    output logic sd_dout_en
);

// `include "w9825g6kh-6.vh"

// sdram control words for sd_cmd
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
localparam STATE_IDLE       = 3'h4;
localparam STATE_ACTIVATE   = 3'h5;
localparam STATE_READ       = 3'h6;
localparam STATE_WRITE      = 3'h7;
logic [3:0] state;
logic [3:0] state_next;
logic new_state;
logic [3:0] phase;
wire phase_zero = phase == 0;
logic [15:0] count;
logic reset_count, hold_count;
logic booting, initialized;
logic rw;
logic sd_rd;

// address decode
localparam ROW_DEPTH = ADDR_DEPTH-COL_DEPTH-3;
logic [1:0] bank, bank_in;
logic [ROW_DEPTH-1:0] row, row_in;
logic [COL_DEPTH-1:0] col, col_in;
logic byte_ul, byte_in;
assign {bank_in, row_in, col_in, byte_in} = addr_in;

always_ff @(posedge clk)
begin
    if (rst) begin
        state <= STATE_BOOT;
        count <= 0;
        phase <= 0;
        booting <= 1;

        bank <= 0;
        row <= 0;
        col <= 0;
        byte_ul <= 0;
        rw <= 0;
        sd_dout <= 0;

        data_rd<=0;
        val<=0;

    end else begin
        if(initialized) booting <= 0;

        if(reset_count) count <= 0;
        else if(~hold_count) count <= count+1;

        if(new_state) begin
            state <= state_next;
            phase <= 0;
        end else begin
            phase <= phase+1;
        end

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
localparam sdmode = {5'b0, SDMODE_SINGLEWRITE, 2'b0, CAS_LATENCY[2:0], SDMODE_SEQUENTIAL, SDMODE_BURST1};

logic [2:0] sd_cmd;
assign {sd_ras_n, sd_cas_n, sd_we_n} = sd_cmd;


always @(*)
begin
    sd_a = 13'b0;
    sd_bs = 2'b0;
    sd_cs_n = 1'b0;
    sd_udqm = 1'b0;
    sd_ldqm = 1'b0;
    sd_dout_en = 1'b0;
    sd_cke = 1'b1;
    sd_cmd = SDRAM_NOP;
    sd_rd = 0;
    rdy = 0;
    state_next = state;
    reset_count = 0;
    hold_count = 0;
    new_state = 0;
    initialized = 0;

    case(state)
        // boot sequence is:
        //      200us of NOP
        //      precharge all
        //      set mode reg
        //      refresh 8x
        //      idle
    
        STATE_BOOT: begin 
            // After power up, an initial pause of 200 μ S is required. To prevent data contention on the DQ bus 
            // during power up, it is required that the DQM and CKE pins be held high during the initial pause period.
            sd_ldqm = 1;
            sd_udqm = 1;
            state_next = STATE_PRECHARGE;
            new_state = count==DELAY_STARTUP;
        end
        STATE_PRECHARGE: begin 
            if(phase_zero) sd_cmd = SDRAM_PRECHARGE; // Precharge all banks
            sd_a[10] = 1;
            state_next = booting ? STATE_MODESET : STATE_IDLE;
            new_state = phase == `MAX(DELAY_RP-1,0);
        end
        STATE_MODESET: begin
            if(phase_zero) sd_cmd = SDRAM_MODE_SET;
            sd_a = sdmode;
            sd_bs = 2'b0;
            state_next = STATE_REFRESH;
            new_state = phase == `MAX(DELAY_RSC-2,0);
            reset_count = 1;
        end
        STATE_REFRESH: begin
            if(phase_zero) sd_cmd = SDRAM_AUTO_REFRESH;
            new_state = phase == `MAX(DELAY_RC-1,0);
            if(booting) begin
                state_next = STATE_REFRESH;
                initialized = count==8*DELAY_RC; // done with boot sequence after 8 refreshes
            end else begin
                state_next = STATE_IDLE;
                reset_count = 1;
            end
        end
        STATE_IDLE: begin  
            rdy = 1;         // signal that we are ready to process cmd
            if( count == DELAY_REF_INTERVAL-1 ) begin
                // force refresh every DELAY_REF_INTERVAL cycles
                rdy = 0;
                state_next = STATE_REFRESH;                    
                new_state = 1;
            end else if (rd || wr) begin
                state_next = STATE_ACTIVATE;                    
                new_state = 1;
            end
        end
        STATE_ACTIVATE: begin
            if(phase_zero) sd_cmd = SDRAM_ACTIVATE;
            sd_a = row;
            sd_bs = bank;
            state_next = rw ? STATE_READ : STATE_WRITE;
            new_state = phase == `MAX(DELAY_RCD-1,0);
        end
        STATE_READ: begin 
            if(phase_zero) sd_cmd = SDRAM_READ;
            sd_bs = bank;
            sd_a[COL_DEPTH-1:0] = col;
            sd_a[10] = 1;
            // sd_udqm = ~byte_ul;
            // sd_ldqm = byte_ul;
            sd_udqm = 0;
            sd_ldqm = 0;
            sd_rd = phase == CAS_LATENCY-1;
            state_next = STATE_IDLE;
            //we can exit state one cycle early, since we are going to idle for at least one clock
            new_state = phase == CAS_LATENCY-1 +`MAX(DELAY_RP-1,0); 
        end
        STATE_WRITE: begin 
            if(phase_zero) sd_cmd = SDRAM_WRITE;
            sd_bs = bank;
            sd_a[COL_DEPTH-1:0] = col;
            sd_a[10] = 1;
            sd_udqm = ~byte_ul;
            sd_ldqm = byte_ul;
            sd_dout_en = 1'b1;
            state_next = STATE_IDLE;
            //we can exit state one cycle early, since we are going to idle for at least one clock
            new_state = phase == `MAX(DELAY_DAL-2, 0); 
        end
        default: begin end
    endcase
end

endmodule