
`timescale 1ns / 100ps

module sdram_gated
(
     input  logic          clk_ram
    ,input  logic          clk_gated
    ,input  logic          rst
    ,output logic  [  3:0] ram_wr_o
    ,output logic          ram_rd_o
    ,output logic  [ 31:0] ram_addr_o
    ,output logic  [ 31:0] ram_write_data_o
    ,input  logic  [ 31:0] ram_read_data_i
    ,input  logic          ram_accept_i
    ,input  logic          ram_ack_i
    ,input  logic          ram_error_i
    ,input  logic [  3:0]  gated_wr_i
    ,input  logic          gated_rd_i
    ,input  logic [ 31:0]  gated_addr_i
    ,input  logic [ 31:0]  gated_write_data_i
    ,output logic [ 31:0]  gated_read_data_o
    ,output logic          gated_wait_o
    ,output logic          gated_err_o
);

logic busy;
logic [31:0] read_data;
logic ram_err;
logic gated_r1;
wire next_clk = gated_r1 != gated_r;
wire req = gated_rd_i | (gated_wr_i != 0);

always_ff @ (posedge clk_ram) begin
    if (rst_ram)
        gated_r1 <= 0;
        busy <= 0;
        read_data <= 0;
        ram_err <= 0;
    else begin
        gated_r1 <= gated_r;
        if (ram_ack_i) begin
            busy <= 0;
            read_data <= ram_read_data_i;
            ram_err <= ram_error_i;
        end else if (next_clk) begin
            busy <= req;
            read_data <= 0;
            ram_err <= ram_error_i;
        end
    end
end


always_ff @ (posedge clk_ram) begin
    if (rst_ram)
        ram_wr_o <= 0;
        ram_rd_o <= 0;
        ram_addr_o <= 0;
        ram_write_data_o <= 0;
    else begin
        if(next_clk & !busy) begin
            ram_wr_o <= gated_wr_i;
            ram_rd_o <= gated_rd_i;
            ram_addr_o <= gated_addr_i;
            ram_write_data_o <= gated_write_data_i;
        end else if (ram_ack_i) begin
            ram_wr_o <= 0;
            ram_rd_o <= 0;
            ram_addr_o <= 0;
            ram_write_data_o <= 0;
        end
    end
end

logic gated_r;
always_ff @ (posedge clk_gated) begin
    if (rst_gated)
        gated_r <= 0;
        gated_read_data_o <= 0;
        gated_wait_o <= 0;
        gated_err_o <= 0;
    else begin
        gated_r <= ~gated_r;
        gated_read_data_o <= read_data;
        gated_err_o <= ram_err;
        gated_wait_o <= req & busy;
    end
end

endmodule
