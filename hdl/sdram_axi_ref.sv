//-----------------------------------------------------------------
//                    SDRAM Controller (AXI4)
//                           V1.0
//                     Ultra-Embedded.com
//                     Copyright 2015-2019
//
//                 Email: admin@ultra-embedded.com
//
//                         License: GPL
// If you would like a version with a more permissive license for
// use in closed source commercial applications please contact me
// for details.
//-----------------------------------------------------------------
//
// This file is open source HDL; you can redistribute it and/or 
// modify it under the terms of the GNU General Public License as 
// published by the Free Software Foundation; either version 2 of 
// the License, or (at your option) any later version.
//
// This file is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public 
// License along with this file; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA
//-----------------------------------------------------------------

//-----------------------------------------------------------------
//                          Generated File
//-----------------------------------------------------------------

module sdram_axi_ref
#( 
    parameter S00_AXI_DATA_WIDTH = 32,
    parameter S00_AXI_ADDR_WIDTH = 32  
)
(
    input logic clk, rst,
    taxi_axil_if.sub axi_if,
    sdram_dev_if.man dev_if
)

    // Inputs
    wire           ACLK;
    wire           ARSTN;
    wire           S00_AXI_awvalid;
    wire  [ S00_AXI_ADDR_WIDTH-1:0]  S00_AXI_awaddr;
    wire  [  7:0]  S00_AXI_awlen;
    wire  [  1:0]  S00_AXI_awburst;
    wire           S00_AXI_wvalid;
    wire  [ S00_AXI_DATA_WIDTH-1:0]  S00_AXI_wdata;
    wire  [  3:0]  S00_AXI_wstrb;
    wire           S00_AXI_wlast;
    wire           S00_AXI_bready;
    wire           S00_AXI_arvalid;
    wire  [ S00_AXI_ADDR_WIDTH-1:0]  S00_AXI_araddr;
    wire  [  7:0]  S00_AXI_arlen;
    wire  [  1:0]  S00_AXI_arburst;
    wire           S00_AXI_rready;
    wire  [ 15:0]  sdram_data_input;

    // Outputs
    wire          S00_AXI_awready;
    wire          S00_AXI_wready;
    wire          S00_AXI_bvalid;
    wire [  1:0]  S00_AXI_bresp;
    wire          S00_AXI_arready;
    wire          S00_AXI_rvalid;
    wire [ S00_AXI_DATA_WIDTH-1:0]  S00_AXI_rdata;
    wire [  1:0]  S00_AXI_rresp;
    wire          S00_AXI_rlast;
    wire          sdram_cke;
    wire          sdram_cs;
    wire          sdram_ras;
    wire          sdram_cas;
    wire          sdram_we;
    wire [  1:0]  sdram_dqm;
    wire [ 12:0]  sdram_addr;
    wire [  1:0]  sdram_ba;
    wire [ 15:0]  sdram_data_output;
    wire          sdram_data_out_en;

    assign ACLK = clk;
    assign ARSTN = ~rst;
    assign S00_AXI_awvalid = axi_if.awvalid;
    assign S00_AXI_awaddr = axi_if.awaddr;
    assign S00_AXI_wvalid = axi_if.wvalid;
    assign S00_AXI_wdata = axi_if.wdata;
    assign S00_AXI_wstrb = axi_if.wstrb;
    assign S00_AXI_bready = axi_if.bready;
    assign S00_AXI_arvalid = axi_if.arvalid;
    assign S00_AXI_araddr = axi_if.araddr;
    assign S00_AXI_rready = axi_if.rready;

    assign S00_AXI_awlen = 0;
    assign S00_AXI_awburst = 1;
    assign S00_AXI_wlast = 1;
    assign S00_AXI_arlen = 0;
    assign S00_AXI_arburst = 1;

    assign axi_if.awready = S00_AXI_awready;
    assign axi_if.wready = S00_AXI_wready;
    assign axi_if.bvalid = S00_AXI_bvalid;
    assign axi_if.bresp = S00_AXI_bresp;
    assign axi_if.arready = S00_AXI_arready;
    assign axi_if.rvalid = S00_AXI_rvalid;
    assign axi_if.rdata = S00_AXI_rdata;
    assign axi_if.rresp = S00_AXI_rresp;

    assign sdram_data_input = dev_if.read_data;

    assign def_if.cke = sdram_cke;
    assign def_if.cs = sdram_cs;
    assign def_if.ras = sdram_ras;
    assign def_if.cas = sdram_cas;
    assign def_if.we = sdram_we;
    assign def_if.dqm = sdram_dqm;
    assign def_if.addr = sdram_addr;
    assign def_if.ba = sdram_ba;
    assign def_if.data_output = sdram_data_output;
    assign def_if.data_out_en = sdram_data_out_en;
//-----------------------------------------------------------------
// Key Params
//-----------------------------------------------------------------
parameter SDRAM_MHZ             = 50;
parameter SDRAM_ADDR_W          = 24;
parameter SDRAM_COL_W           = 9;
parameter SDRAM_READ_LATENCY    = 3;

//-----------------------------------------------------------------
// AXI Interface
//-----------------------------------------------------------------
wire [ S00_AXI_ADDR_WIDTH-1:0]  ram_addr_w;
wire [  3:0]  ram_wr_w;
wire          ram_rd_w;
wire          ram_accept_w;
wire [ S00_AXI_DATA_WIDTH-1:0]  ram_write_data_w;
wire [ S00_AXI_DATA_WIDTH-1:0]  ram_read_data_w;
wire [  7:0]  ram_len_w;
wire          ram_ack_w;
wire          ram_error_w;

wire rst = ~ARSTN;
sdram_axi_pmem
#(
     .ID_WIDTH(0)
    ,.DATA_WIDTH(S00_AXI_DATA_WIDTH)
    ,.ADDR_WIDTH(S00_AXI_ADDR_WIDTH)
)
u_axi
(
    .clk_i(ACLK),
    .rst_i(rst),

    // AXI port
    .axi_awvalid_i(S00_AXI_awvalid),
    .axi_awaddr_i(S00_AXI_awaddr),
    // .axi_awid_i(S00_AXI_awid),
    .axi_awlen_i(S00_AXI_awlen),
    .axi_awburst_i(S00_AXI_awburst),
    .axi_wvalid_i(S00_AXI_wvalid),
    .axi_wdata_i(S00_AXI_wdata),
    .axi_wstrb_i(S00_AXI_wstrb),
    .axi_wlast_i(S00_AXI_wlast),
    .axi_bready_i(S00_AXI_bready),
    .axi_arvalid_i(S00_AXI_arvalid),
    .axi_araddr_i(S00_AXI_araddr),
    // .axi_arid_i(S00_AXI_arid),
    .axi_arlen_i(S00_AXI_arlen),
    .axi_arburst_i(S00_AXI_arburst),
    .axi_rready_i(S00_AXI_rready),
    .axi_awready_o(S00_AXI_awready),
    .axi_wready_o(S00_AXI_wready),
    .axi_bvalid_o(S00_AXI_bvalid),
    .axi_bresp_o(S00_AXI_bresp),
    // .axi_bid_o(S00_AXI_bid),
    .axi_arready_o(S00_AXI_arready),
    .axi_rvalid_o(S00_AXI_rvalid),
    .axi_rdata_o(S00_AXI_rdata),
    .axi_rresp_o(S00_AXI_rresp),
    // .axi_rid_o(S00_AXI_rid),
    .axi_rlast_o(S00_AXI_rlast),
    
    // RAM interface
    .ram_addr_o(ram_addr_w),
    .ram_accept_i(ram_accept_w),
    .ram_wr_o(ram_wr_w),
    .ram_rd_o(ram_rd_w),
    .ram_len_o(ram_len_w),
    .ram_write_data_o(ram_write_data_w),
    .ram_ack_i(ram_ack_w),
    .ram_error_i(ram_error_w),
    .ram_read_data_i(ram_read_data_w)
);

// assign S00_AXI_rdata = 32'hdeadbeef;
// assign ram_write_data_w = 32'h12345678;

//-----------------------------------------------------------------
// SDRAM Controller
//-----------------------------------------------------------------
sdram_axi_core
#(
     .SDRAM_MHZ(SDRAM_MHZ)
    ,.SDRAM_ADDR_W(SDRAM_ADDR_W)
    ,.SDRAM_COL_W(SDRAM_COL_W)
    ,.SDRAM_READ_LATENCY(SDRAM_READ_LATENCY)
)
u_core
(
     .clk_i(ACLK)
    ,.rst_i(rst)

    ,.inport_wr_i(ram_wr_w)
    ,.inport_rd_i(ram_rd_w)
    ,.inport_len_i(ram_len_w)
    ,.inport_addr_i(ram_addr_w)
    ,.inport_write_data_i(ram_write_data_w)
    ,.inport_accept_o(ram_accept_w)
    ,.inport_ack_o(ram_ack_w)
    ,.inport_error_o(ram_error_w)
    ,.inport_read_data_o(ram_read_data_w)

    ,.sdram_clk_o()
    ,.sdram_cke_o(sdram_cke)
    ,.sdram_cs_o(sdram_cs)
    ,.sdram_ras_o(sdram_ras)
    ,.sdram_cas_o(sdram_cas)
    ,.sdram_we_o(sdram_we)
    ,.sdram_dqm_o(sdram_dqm)
    ,.sdram_addr_o(sdram_addr)
    ,.sdram_ba_o(sdram_ba)
    ,.sdram_data_output_o(sdram_data_output)
    ,.sdram_data_out_en_o(sdram_data_out_en)
    ,.sdram_data_input_i(sdram_data_input)
);

endmodule
