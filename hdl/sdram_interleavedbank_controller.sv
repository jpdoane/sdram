`timescale 1ns / 100ps

// control SDRAM on 8-cycle period, with two interleaved banks
// Bank is active when cycle[0] == BANK
// cycles 0-1:   Activate Row
// cycles 2-3:   Read/Write command wtih auto-precharge
// cycles 4-5:   Read data valid (CAS latecy 2)
// cycles 6-7:   NOP

// inputs are latched on cycle 7
// read data is updated on cycle 0

module sdram_interleavedbank_controller #(
    parameter BANK                  = 0,
    parameter ADDR_DEPTH            = 23,
    parameter COL_DEPTH             = 10
    )(
    // main clocks
    input logic clk, rst,
    input logic [2:0] cycle,    // operates on 8-cycle count
    input logic en,

    //controller interface
    input logic [7:0] data_in,
    input logic [ADDR_DEPTH-1:0] addr,
    input logic rd,
    input logic wr,
    output logic [7:0] data_out,

    // sdram interface
    input logic [15:0]  sdram_data_in,
    output logic [15:0]  sdram_data_out,
    output logic sdram_data_out_en,
    output logic [12:0] sdram_a,
    output logic [2:0]  sdram_cmd,
    output logic [1:0]  sdram_dqm
);

// sdram control words for sdram_cmd
localparam SDRAM_ACTIVATE           =   3'b011;
localparam SDRAM_WRITE              =   3'b100; //A10: auto precharge
localparam SDRAM_READ               =   3'b101; //A10: auto precharge
localparam SDRAM_NOP                =   3'b111;

// address decode
localparam ROW_DEPTH = ADDR_DEPTH-COL_DEPTH-1;
logic [ROW_DEPTH-1:0] row;
logic [COL_DEPTH-1:0] col;
logic en_r, rd_r, wr_r, ul_r;
logic [7:0] data_r;
logic sdram_rd, sdram_wr;

assign sdram_data_out_en = sdram_wr;
assign sdram_data_out = {{8{sdram_wr & ul_r}} & data_r, {8{sdram_wr & ~ul_r}} & data_r};

always_ff @(posedge clk)
begin
    if (rst) begin
        row <= 0;
        col <= 0;        
        ul_r <= 0;
        rd_r <= 0;
        wr_r <= 0;
        data_out <= 0;
        data_r <= 0;
        en_r <= 0;
    end else if(en) begin
        if(cycle==3'h7) begin
            {row, col} = addr[ADDR_DEPTH-1:1];
            ul_r = addr[0];
            rd_r <= rd;
            wr_r <= wr;
            data_out <= data_r;
            data_r <= data_in;
            en_r <= en;
        end else if(sdram_rd) begin
            data_r <= ul_r ? sdram_data_in[15:8] : sdram_data_in[7:0];
        end            
    end        
end


always @(*)
begin
    sdram_cmd = SDRAM_NOP;
    sdram_a = 0;
    sdram_wr = 0;
    sdram_rd = 0;
    sdram_dqm = 2'b11;
    if (cycle[0] == BANK && en_r) begin
        case(cycle[2:1])
            0:  begin   // activate row
                    // if(rd_r || wr_r) $display("activate %d:%d", BANK, row);
                    if(rd_r || wr_r) sdram_cmd = SDRAM_ACTIVATE;
                    sdram_a = row;
                end
            1:  begin   // read or write
                    // if(rd_r) $display("read %d:%d:%d", BANK, row, col);
                    // if(wr_r) $display("write %d:%d:%d", BANK, row, col);
                    sdram_cmd = rd_r ? SDRAM_READ : wr_r ? SDRAM_WRITE : SDRAM_NOP;
                    sdram_a = 13'(col);
                    sdram_a[10] = 1;                               // set precharge bit
                    sdram_dqm = (rd_r || wr_r) ? {~ul_r, ul_r} : 2'b11;    // mask data
                    sdram_wr = wr_r;
                end
            2:  begin   // read back
                    // if(rd_r) $display("read back %d:%d:%d", BANK, row, col);
                    sdram_rd = rd_r;
                end
            default: begin end
        endcase
    end
end

endmodule