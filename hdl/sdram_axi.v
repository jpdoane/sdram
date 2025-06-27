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

module sdram_axi
#( 
    parameter S00_AXI_DATA_WIDTH = 32,
    parameter S00_AXI_ADDR_WIDTH = 32  
)
(
    // Inputs
     input           ACLK
    ,input           ARSTN
    ,input           S00_AXI_awvalid
    ,input  [ S00_AXI_ADDR_WIDTH-1:0]  S00_AXI_awaddr
    ,input  [  7:0]  S00_AXI_awlen
    ,input  [  1:0]  S00_AXI_awburst
    ,input           S00_AXI_wvalid
    ,input  [ S00_AXI_DATA_WIDTH-1:0]  S00_AXI_wdata
    ,input  [  3:0]  S00_AXI_wstrb
    ,input           S00_AXI_wlast
    ,input           S00_AXI_bready
    ,input           S00_AXI_arvalid
    ,input  [ S00_AXI_ADDR_WIDTH-1:0]  S00_AXI_araddr
    ,input  [  7:0]  S00_AXI_arlen
    ,input  [  1:0]  S00_AXI_arburst
    ,input           S00_AXI_rready
    ,input  [ 15:0]  sdram_data_input

    // Outputs
    ,output          S00_AXI_awready
    ,output          S00_AXI_wready
    ,output          S00_AXI_bvalid
    ,output [  1:0]  S00_AXI_bresp
    ,output          S00_AXI_arready
    ,output          S00_AXI_rvalid
    ,output [ S00_AXI_DATA_WIDTH-1:0]  S00_AXI_rdata
    ,output [  1:0]  S00_AXI_rresp
    ,output          S00_AXI_rlast
    ,output          sdram_cke
    ,output          sdram_cs
    ,output          sdram_ras
    ,output          sdram_cas
    ,output          sdram_we
    ,output [  1:0]  sdram_dqm
    ,output [ 12:0]  sdram_addr
    ,output [  1:0]  sdram_ba
    ,output [ 15:0]  sdram_data_output
    ,output          sdram_data_out_en
);


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
