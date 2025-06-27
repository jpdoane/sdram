`timescale 1ns / 100ps

module sdram_dual
(
// axi port
 input           ACLK
,input           ARSTN
,input           AXI_awvalid
,input  [ 31:0]  AXI_awaddr
,input  [  7:0]  AXI_awlen
,input  [  1:0]  AXI_awburst
,input           AXI_wvalid
,input  [ 31:0]  AXI_wdata
,input  [  3:0]  AXI_wstrb
,input           AXI_wlast
,input           AXI_bready
,input           AXI_arvalid
,input  [ 31:0]  AXI_araddr
,input  [  7:0]  AXI_arlen
,input  [  1:0]  AXI_arburst
,input           AXI_rready
,output          AXI_awready
,output          AXI_wready
,output          AXI_bvalid
,output [  1:0]  AXI_bresp
,output          AXI_arready
,output          AXI_rvalid
,output [ 31:0]  AXI_rdata
,output [  1:0]  AXI_rresp
,output          AXI_rlast


// direct port
// clk_direct should be slower gated clock derived from ACLK
,input           clk_direct 
,input           rst_direct
,input  [  3:0]  direct_wr_i
,input           direct_rd_i
,input  [ 31:0]  direct_addr_i
,input  [ 31:0]  direct_write_data_i
,output [ 31:0]  direct_read_data_o
,output          direct_wait_o
,output          direct_err_o

// sdram pins
,inout logic [15:0] sdram_dq
,output logic [12:0] sdram_a
,output logic [1:0] sdram_bs
,output logic clk_sdram
,output logic sdram_cke
,output logic sdram_we_n
,output logic sdram_cas_n
,output logic sdram_ras_n
,output logic sdram_cs_n
,output logic sdram_ldqm
,output logic sdram_udqm
);

parameter FREQ_MHZ             = 50;
parameter SDRAM_ADDR_W          = 24;
parameter SDRAM_COL_W           = 9;
parameter SDRAM_READ_LATENCY    = 3;

wire rst = ~ARSTN;

wire          sdram_core_cke;
wire          sdram_core_cs;
wire          sdram_core_ras;
wire          sdram_core_cas;
wire          sdram_core_we;
wire [  1:0]  sdram_core_dqm;
wire [ 12:0]  sdram_core_addr;
wire [  1:0]  sdram_core_ba;
wire [ 15:0]  sdram_core_data_output;
wire          sdram_core_data_out_en;
wire  [ 15:0] sdram_core_data_input;

wire [ 31:0]  axi_ram_addr;
wire          axi_ram_accept;
wire [  3:0]  axi_ram_wr;
wire          axi_ram_rd;
wire [  7:0]  axi_ram_len;
wire [ 31:0]  axi_ram_write_data;
wire          axi_ram_ack;
wire          axi_ram_error;
wire [ 31:0]  axi_ram_read_data;

logic  [  3:0] direct_fast_ram_wr;
logic          direct_fast_ram_rd;
logic  [ 31:0] direct_fast_ram_addr;
logic  [ 31:0] direct_fast_ram_write_data;
logic          direct_fast_ram_accept;
logic          direct_fast_ram_ack;
logic          direct_fast_ram_error;
logic [ 31:0]  direct_fast_ram_read_data;

wire [ 31:0]  core_addr;
wire          core_accept;
wire [  3:0]  core_wr;
wire          core_rd;
wire [ 31:0]  core_write_data;
wire          core_ack;
wire          core_error;
wire [ 31:0]  core_read_data;

sdram_gated
u_sdram_gated
(
  .clk_ram            (ACLK),
  .clk_gated          (clk_direct),
  .rst                (rst_direct),
  .ram_wr_o           (direct_fast_ram_wr),
  .ram_rd_o           (direct_fast_ram_rd),
  .ram_addr_o         (direct_fast_ram_addr),
  .ram_write_data_o   (direct_fast_ram_write_data),
  .ram_read_data_i    (direct_fast_ram_read_data),
  .ram_accept_i       (direct_fast_ram_accept),
  .ram_ack_i          (direct_fast_ram_ack),
  .ram_error_i        (direct_fast_ram_error),
  .gated_wr_i         (direct_ram_wr),
  .gated_rd_i         (direct_ram_rd),
  .gated_addr_i       (direct_ram_addr),
  .gated_write_data_i (direct_ram_write_data),
  .gated_read_data_o  (direct_ram_read_data),
  .gated_wait_o       (direct_ram_wait),
  .gated_err_o        (direct_ram_err)
);

sdram_arb
u_sdram_arb
(
  .clk_i              (ACLK),
  .rst_i              (ARST),
  .portA_wr_i         (direct_fast_ram_wr),
  .portA_rd_i         (direct_fast_ram_rd),
  .portA_addr_i       (direct_fast_ram_addr),
  .portA_write_data_i (direct_fast_ram_write_data),
  .portA_accept_o     (direct_fast_ram_accept),
  .portA_ack_o        (direct_fast_ram_ack),
  .portA_error_o      (direct_fast_ram_error),
  .portA_read_data_o  (direct_fast_ram_read_data),
  .portB_wr_i         (axi_ram_wr),
  .portB_rd_i         (axi_ram_rd),
  .portB_addr_i       (axi_ram_addr),
  .portB_write_data_i (axi_ram_write_data),
  .portB_accept_o     (axi_ram_accept),
  .portB_ack_o        (axi_ram_ack),
  .portB_error_o      (axi_ram_error),
  .portB_read_data_o  (axi_ram_read_data),
  .core_wr_o          (core_wr),
  .core_rd_o          (core_rd),
  .core_addr_o        (core_addr),
  .core_write_data_o  (core_write_data),
  .core_accept_i      (core_accept),
  .core_ack_i         (core_ack),
  .core_error_i       (core_error),
  .core_read_data_i   (core_read_data)
);
    

sdram_axi_pmem
#(
    .ID_WIDTH(0)
    ,.DATA_WIDTH(S00_AXI_DATA_WIDTH)
    ,.ADDR_WIDTH(S00_AXI_ADDR_WIDTH)
)
u_axi
(
    .clk_i(ACLK),
    .rst_i(ARST),

    // AXI port
    .axi_awvalid_i(AXI_awvalid),
    .axi_awaddr_i(AXI_awaddr),
    .axi_awlen_i(AXI_awlen),
    .axi_awburst_i(AXI_awburst),
    .axi_wvalid_i(AXI_wvalid),
    .axi_wdata_i(AXI_wdata),
    .axi_wstrb_i(AXI_wstrb),
    .axi_wlast_i(AXI_wlast),
    .axi_bready_i(AXI_bready),
    .axi_arvalid_i(AXI_arvalid),
    .axi_araddr_i(AXI_araddr),
    .axi_arlen_i(AXI_arlen),
    .axi_arburst_i(AXI_arburst),
    .axi_rready_i(AXI_rready),
    .axi_awready_o(AXI_awready),
    .axi_wready_o(AXI_wready),
    .axi_bvalid_o(AXI_bvalid),
    .axi_bresp_o(AXI_bresp),
    .axi_arready_o(AXI_arready),
    .axi_rvalid_o(AXI_rvalid),
    .axi_rdata_o(AXI_rdata),
    .axi_rresp_o(AXI_rresp),
    .axi_rlast_o(AXI_rlast),
    
    // RAM interface
    .ram_addr_o(axi_ram_addr),
    .ram_accept_i(axi_ram_accept),
    .ram_wr_o(axi_ram_wr),
    .ram_rd_o(axi_ram_rd),
    .ram_len_o(axi_ram_len),
    .ram_write_data_o(axi_ram_write_data),
    .ram_ack_i(axi_ram_ack),
    .ram_error_i(axi_ram_error),
    .ram_read_data_i(axi_ram_read_data)
);

sdram32
#(
     .FREQ_MHZ(FREQ_MHZ)
    ,.SDRAM_ADDR_W(SDRAM_ADDR_W)
    ,.SDRAM_COL_W(SDRAM_COL_W)
    ,.SDRAM_READ_LATENCY(SDRAM_READ_LATENCY)
)
u_core
(
     .clk_i(ACLK)
    ,.rst_i(rst)
    ,.inport_wr_i(core_wr)
    ,.inport_rd_i(core_rd)
    ,.inport_addr_i(core_addr)
    ,.inport_write_data_i(core_write_data)
    ,.inport_accept_o(core_accept)
    ,.inport_ack_o(core_ack)
    ,.inport_error_o(core_error)
    ,.inport_read_data_o(core_read_data)
    ,.sdram_clk_o()
    ,.sdram_cke_o(sdram_core_cke)
    ,.sdram_cs_o(sdram_core_cs)
    ,.sdram_ras_o(sdram_core_ras)
    ,.sdram_cas_o(sdram_core_cas)
    ,.sdram_we_o(sdram_core_we)
    ,.sdram_dqm_o(sdram_core_dqm)
    ,.sdram_addr_o(sdram_core_addr)
    ,.sdram_ba_o(sdram_core_ba)
    ,.sdram_data_output_o(sdram_core_data_output)
    ,.sdram_data_out_en_o(sdram_core_data_out_en)
    ,.sdram_data_input_i(sdram_core_data_input)
);

sdram_io
u_sdram_io
(
    .clk                     (ACLK),
    .sdram_core_cke          (sdram_core_cke),
    .sdram_core_cs           (sdram_core_cs),
    .sdram_core_ras          (sdram_core_ras),
    .sdram_core_cas          (sdram_core_cas),
    .sdram_core_we           (sdram_core_we),
    .sdram_core_dqm          (sdram_core_dqm),
    .sdram_core_addr         (sdram_core_addr),
    .sdram_core_ba           (sdram_core_ba),
    .sdram_core_data_output  (sdram_core_data_output),
    .sdram_core_data_out_en  (sdram_core_data_out_en),
    .sdram_core_data_input   (sdram_core_data_input),
    .clk_sdram               (clk_sdram),
    .sdram_cke               (sdram_cke),
    .sdram_cs_n              (sdram_cs_n),
    .sdram_ras_n             (sdram_ras_n),
    .sdram_cas_n             (sdram_cas_n),
    .sdram_we_n              (sdram_we_n),
    .sdram_ldqm              (sdram_ldqm),
    .sdram_udqm              (sdram_udqm),
    .sdram_a                 (sdram_a),
    .sdram_bs                (sdram_bs),
    .sdram_dq                (sdram_dq)
);

endmodule
