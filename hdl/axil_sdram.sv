
module axil_sdram
(
    input  wire logic    clk,
    input  wire logic    rst,
    taxi_axil_if.wr_slv  s_axil_wr,
    taxi_axil_if.rd_slv  s_axil_rd,
    sdram_ctrl_if.man    sdram_ctrl
);

// // extract parameters
// localparam DATA_W = s_axil_wr.DATA_W;
// localparam STRB_W = s_axil_wr.STRB_W;

// localparam VALID_ADDR_W = ADDR_W - $clog2(STRB_W);
// localparam BYTE_LANES = STRB_W;
// localparam BYTE_W = DATA_W/BYTE_LANES;

// // check configuration
// if (BYTE_W * STRB_W != DATA_W)
//     $fatal(0, "Error: AXI data width not evenly divisible (instance %m)");

// if (2**$clog2(BYTE_LANES) != BYTE_LANES)
//     $fatal(0, "Error: AXI byte lane count must be even power of two (instance %m)");

// if (s_axil_wr.DATA_W != sdram_ctrl.DATA_WIDTH || s_axil_rd.DATA_W != sdram_ctrl.DATA_WIDTH )
//     $fatal(0, "Error: AXI interface configuration mismatch (instance %m)");

// if (s_axil_wr.ADDR_W != sdram_ctrl.ADDR_WIDTH || s_axil_rd.ADDR_W != sdram_ctrl.ADDR_WIDTH)
//     $fatal(0, "Error: AXI address width inconsistant (instance %m)");

wire rd_req, wr_req;
logic bvalid, rvalid;
logic [31:0] rdata;

assign rd_req = s_axil_rd.arvalid;
assign wr_req = s_axil_wr.awvalid & s_axil_wr.wvalid;

always_ff @(posedge clk) begin
    if(s_axil_rd.rready) begin
        rdata <= '0;
        rvalid <= 1'b0;
    end
    if(sdram_ctrl.rvalid) begin
        rdata <= sdram_ctrl.read_data;
        rvalid <= 1'b1;
    end

    if (s_axil_wr.bready) bvalid <= 0;
    if (sdram_ctrl.rdy & wr_req) bvalid <= 1;

    if (rst) begin
        rdata <=  '0;
        rvalid <= 1'b0;
        bvalid <= 1'b0;
    end
end

assign s_axil_rd.arready = rd_req & sdram_ctrl.rdy;
assign s_axil_wr.awready = wr_req & sdram_ctrl.rdy;
assign s_axil_wr.wready = wr_req & sdram_ctrl.rdy;
assign s_axil_rd.rdata = rdata;
assign s_axil_rd.rvalid = rvalid;
assign s_axil_wr.bvalid = bvalid;
assign s_axil_rd.rresp = 2'b00;
assign s_axil_wr.bresp = 2'b00;
assign s_axil_rd.ruser = '0;
assign s_axil_wr.buser = '0;

always_comb begin
    sdram_ctrl.wr = 0;
    sdram_ctrl.rd = 0;
    sdram_ctrl.addr = 0;
    sdram_ctrl.write_data = 0;
 
    if (wr_req) begin
        sdram_ctrl.wr = s_axil_wr.wstrb;
        sdram_ctrl.addr = s_axil_wr.awaddr;
        sdram_ctrl.write_data = s_axil_wr.wdata;
    end
    if (rd_req) begin
        sdram_ctrl.rd = 1'b1;
        sdram_ctrl.addr = s_axil_rd.araddr;
    end
end

endmodule
