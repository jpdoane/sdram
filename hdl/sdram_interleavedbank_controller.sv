`timescale 1ns/1ps

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
    input logic [15:0]  sd_data_in,
    output logic [15:0]  sd_data_out,
    output logic sd_data_out_en,
    output logic [12:0] sd_a,
    output logic [2:0]  sd_cmd,
    output logic [1:0]  sd_dqm
);

// sdram control words for sd_cmd
localparam SDRAM_ACTIVATE           =   3'b011;
localparam SDRAM_WRITE              =   3'b100; //A10: auto precharge
localparam SDRAM_READ               =   3'b101; //A10: auto precharge
localparam SDRAM_NOP                =   3'b111;

// address decode
localparam ROW_DEPTH = ADDR_DEPTH-COL_DEPTH-1;
logic [ROW_DEPTH-1:0] row;
logic [COL_DEPTH-1:0] col;
logic rd_r, wr_r, ul;
logic [7:0] data_r;
logic sd_rd, sd_wr;

assign sd_data_out_en = sd_wr;
assign sd_data_out = {{8{sd_wr & ul}} & data_r, {8{sd_wr & ~ul}} & data_r};

always_ff @(posedge clk)
begin
    if (rst) begin
        row <= 0;
        col <= 0;        
        ul <= 0;
        rd_r <= 0;
        wr_r <= 0;
        data_out <= 0;
        data_r <= 0;
    end else if(en) begin
        if(cycle==3'h7) begin
            {row, col} = addr[ADDR_DEPTH-1:1];
            ul = addr[0];
            rd_r <= rd;
            wr_r <= wr;
            data_out <= data_r;
            data_r <= data_in;
        end else if(sd_rd) begin
            data_r <= ul ? sd_data_in[15:8] : sd_data_in[7:0];
        end            
    end        
end


always_comb
begin
    sd_cmd = SDRAM_NOP;
    sd_a = 0;
    sd_wr = 0;
    sd_rd = 0;
    sd_dqm = 2'b11;
    if (cycle[0] == BANK && en) begin
        case(cycle[2:1])
            0:  begin   // activate row
                    sd_cmd = SDRAM_ACTIVATE;
                    sd_a = row;
                end
            1:  begin   // read or write
                    sd_cmd = rd ? SDRAM_READ : wr ? SDRAM_WRITE : SDRAM_NOP;
                    sd_a = 13'(col);
                    sd_a[10] = 1;                               // set precharge bit
                    sd_dqm = (rd || wr) ? {~ul, ul} : 2'b11;    // mask data
                    sd_wr = wr;
                end
            2:  begin   // read back
                    sd_rd = rd;
                end
            default: begin end
        endcase
    end
end

endmodule