`timescale 1ns/1ps

module axil_sdram #(
    parameter int ADDR_WIDTH = 25,
    parameter int DATA_WIDTH = 32
)(
    input  logic clk,
    input  logic rst,

    // AXI-Lite subordinate port
    input  logic [ADDR_WIDTH-1:0]    axil_awaddr,
    input  logic                     axil_awvalid,
    output logic                     axil_awready,
    input  logic [DATA_WIDTH-1:0]    axil_wdata,
    input  logic [DATA_WIDTH/8-1:0]  axil_wstrb,
    input  logic                     axil_wvalid,
    output logic                     axil_wready,
    output logic [1:0]               axil_bresp,
    output logic                     axil_bvalid,
    input  logic                     axil_bready,
    input  logic [ADDR_WIDTH-1:0]    axil_araddr,
    input  logic                     axil_arvalid,
    output logic                     axil_arready,
    output logic [DATA_WIDTH-1:0]    axil_rdata,
    output logic [1:0]               axil_rresp,
    output logic                     axil_rvalid,
    input  logic                     axil_rready,

    // SDRAM controller port
    output logic [DATA_WIDTH/8-1:0]  ctrl_wr,
    output logic                     ctrl_rd,
    output logic [ADDR_WIDTH-1:0]    ctrl_addr,
    output logic [DATA_WIDTH-1:0]    ctrl_write_data,
    input  logic                     ctrl_rdy,
    input  logic                     ctrl_rvalid,
    input  logic                     ctrl_wvalid,
    input  logic                     ctrl_error,
    input  logic [DATA_WIDTH-1:0]    ctrl_read_data
);

wire rd_req = axil_arvalid;
wire wr_req = axil_awvalid & axil_wvalid;

wire rd_ack = rd_req & ctrl_rdy;
wire wr_ack = wr_req & ctrl_rdy;

logic bvalid, rvalid;
logic [DATA_WIDTH-1:0] rdata;

always_ff @(posedge clk) begin
    if (ctrl_rvalid) begin
        rdata  <= ctrl_read_data;
        rvalid <= 1'b1;
    end else if (axil_rready) begin
        rdata  <= '0;
        rvalid <= 1'b0;
    end

    if (ctrl_wvalid)     bvalid <= 1;
    else if (axil_bready) bvalid <= 0;

    if (rst) begin
        rdata  <= '0;
        rvalid <= 1'b0;
        bvalid <= 1'b0;
    end
end

assign axil_arready = rd_ack;
assign axil_awready = wr_ack;
assign axil_wready  = wr_ack;
assign axil_rdata   = rdata;
assign axil_rvalid  = rvalid;
assign axil_bvalid  = bvalid;
assign axil_bresp   = 2'b00;
assign axil_rresp   = 2'b00;

always_comb begin
    ctrl_wr         = '0;
    ctrl_rd         = 0;
    ctrl_addr       = '0;
    ctrl_write_data = '0;

    if (wr_ack) begin
        ctrl_wr         = axil_wstrb;
        ctrl_addr       = axil_awaddr;
        ctrl_write_data = axil_wdata;
    end
    if (rd_ack) begin
        ctrl_rd   = 1'b1;
        ctrl_addr = axil_araddr;
    end
end

endmodule
