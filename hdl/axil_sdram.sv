`timescale 1ns / 100ps

module axil_sdram
(
    input  wire logic    clk,
    input  wire logic    rst,
    taxi_axil_if.sub     axi_if,
    sdram_ctrl_if.man    sdram_ctrl
);

localparam int DATA_WIDTH    = sdram_ctrl.DATA_WIDTH;
localparam int ADDR_WIDTH    = sdram_ctrl.ADDR_WIDTH;

wire rd_req, wr_req, rd_ack, wr_ack;
logic bvalid, rvalid;
logic [31:0] rdata;

assign rd_req = axi_if.arvalid;
assign wr_req = axi_if.awvalid & axi_if.wvalid;

assign rd_ack = rd_req & sdram_ctrl.rdy;
assign wr_ack = wr_req & sdram_ctrl.rdy;

always_ff @(posedge clk) begin
    if(axi_if.rready) begin
        rdata <= '0;
        rvalid <= 1'b0;
    end
    if(sdram_ctrl.rvalid) begin
        rdata[DATA_WIDTH-1:0] <= sdram_ctrl.read_data;
        rvalid <= 1'b1;
    end

    if (axi_if.bready) bvalid <= 0;
    if (sdram_ctrl.wvalid) bvalid <= 1;

    if (rst) begin
        rdata <=  '0;
        rvalid <= 1'b0;
        bvalid <= 1'b0;
    end
end

assign axi_if.arready = rd_ack;
assign axi_if.awready = wr_ack;
assign axi_if.wready = wr_ack;
assign axi_if.rdata = rdata;
assign axi_if.rvalid = rvalid;
assign axi_if.bvalid = bvalid;
assign axi_if.rresp = 2'b00;
assign axi_if.bresp = 2'b00;
assign axi_if.ruser = '0;
assign axi_if.buser = '0;

always_comb begin
    sdram_ctrl.wr = '0;
    sdram_ctrl.rd = 0;
    sdram_ctrl.addr = '0;
    sdram_ctrl.write_data = '0;
 
    if (wr_req) begin
        sdram_ctrl.wr = axi_if.wstrb;
        sdram_ctrl.addr = axi_if.awaddr[ADDR_WIDTH-1:0];
        sdram_ctrl.write_data = axi_if.wdata[DATA_WIDTH-1:0];
    end
    if (rd_req) begin
        sdram_ctrl.rd = 1'b1;
        sdram_ctrl.addr = axi_if.araddr[ADDR_WIDTH-1:0];
    end
end

endmodule
