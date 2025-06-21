`timescale 1ns/1ps

module zynq_sdram
(
    //GPIO
    // input [1:0] SW,
    // input [3:0] btn,
    output [3:0] LED,

    // sdram pins
    inout logic [15:0] sdram_dq,
    output logic [12:0] sdram_a,
    output logic [1:0] sdram_ba,
    output logic clk_sdram,
    output logic sdram_cke,
    output logic sdram_we_n,
    output logic sdram_cas_n,
    output logic sdram_ras_n,
    output logic sdram_cs_n,
    output logic [1:0] sdram_dqm,

    // DDR and other IO
    inout [14:0]DDR_addr,
    inout [2:0]DDR_ba,
    inout DDR_cas_n,
    inout DDR_ck_n,
    inout DDR_ck_p,
    inout DDR_cke,
    inout DDR_cs_n,
    inout [3:0]DDR_dm,
    inout [31:0]DDR_dq,
    inout [3:0]DDR_dqs_n,
    inout [3:0]DDR_dqs_p,
    inout DDR_odt,
    inout DDR_ras_n,
    inout DDR_reset_n,
    inout DDR_we_n,
    inout FIXED_IO_ddr_vrn,
    inout FIXED_IO_ddr_vrp,
    inout [53:0]FIXED_IO_mio,
    inout FIXED_IO_ps_clk,
    inout FIXED_IO_ps_porb,
    inout FIXED_IO_ps_srstb
);

    // assign LED[0] = SW[0];
    // assign LED[1] = SW[1];

    wire ACLK;
    wire ARST;
    wire ARSTN;

    localparam real SDRAM_MHZ    = 50;
    localparam int ADDR_WIDTH    = 32;
    localparam int DATA_WIDTH    = 32;
    localparam int SDADDR_WIDTH  = 24;

    sdram_ctrl_if #(.ADDR_WIDTH(ADDR_WIDTH), .DATA_WIDTH(DATA_WIDTH)) ctrl_if();
    sdram_dev_if #(.ADDR_WIDTH(SDADDR_WIDTH)) dev_if();
    taxi_axil_if axi_if();

    assign LED[0] = 1'b1;
    assign LED[1] = ctrl_if.rvalid;
    assign LED[2] = ctrl_if.wvalid;
    assign LED[3] = ctrl_if.error;
    
    zynq_ps_axi
    u_zynq
    (
    .ACLK_in              (ACLK),
    .ARST                 (ARST),
    .ARSTN                (ARSTN),
    .CLK1                 (),           // 100 MHz
    .CLK2                 (ACLK),       // 50 MHz
    .DDR_addr             (DDR_addr),
    .DDR_ba               (DDR_ba),
    .DDR_cas_n            (DDR_cas_n),
    .DDR_ck_n             (DDR_ck_n),
    .DDR_ck_p             (DDR_ck_p),
    .DDR_cke              (DDR_cke),
    .DDR_cs_n             (DDR_cs_n),
    .DDR_dm               (DDR_dm),
    .DDR_dq               (DDR_dq),
    .DDR_dqs_n            (DDR_dqs_n),
    .DDR_dqs_p            (DDR_dqs_p),
    .DDR_odt              (DDR_odt),
    .DDR_ras_n            (DDR_ras_n),
    .DDR_reset_n          (DDR_reset_n),
    .DDR_we_n             (DDR_we_n),
    .FIXED_IO_ddr_vrn     (FIXED_IO_ddr_vrn),
    .FIXED_IO_ddr_vrp     (FIXED_IO_ddr_vrp),
    .FIXED_IO_mio         (FIXED_IO_mio),
    .FIXED_IO_ps_clk      (FIXED_IO_ps_clk),
    .FIXED_IO_ps_porb     (FIXED_IO_ps_porb),
    .FIXED_IO_ps_srstb    (FIXED_IO_ps_srstb),
    .M00_AXI_0_araddr     (axi_if.araddr),
    .M00_AXI_0_arprot     (axi_if.arprot),
    .M00_AXI_0_arready    (axi_if.arready),
    .M00_AXI_0_arvalid    (axi_if.arvalid),
    .M00_AXI_0_awaddr     (axi_if.awaddr),
    .M00_AXI_0_awprot     (axi_if.awprot),
    .M00_AXI_0_awready    (axi_if.awready),
    .M00_AXI_0_awvalid    (axi_if.awvalid),
    .M00_AXI_0_bready     (axi_if.bready),
    .M00_AXI_0_bresp      (axi_if.bresp),
    .M00_AXI_0_bvalid     (axi_if.bvalid),
    .M00_AXI_0_rdata      (axi_if.rdata),
    .M00_AXI_0_rready     (axi_if.rready),
    .M00_AXI_0_rresp      (axi_if.rresp),
    .M00_AXI_0_rvalid     (axi_if.rvalid),
    .M00_AXI_0_wdata      (axi_if.wdata),
    .M00_AXI_0_wready     (axi_if.wready),
    .M00_AXI_0_wstrb      (axi_if.wstrb),
    .M00_AXI_0_wvalid     (axi_if.wvalid)
    );

    axil_sdram u_axil_sdram
    (
        .clk    (ACLK),
        .rst    (ARST),
        .axi_if  (axi_if),
        .sdram_ctrl (ctrl_if)
    );

    sdram_ref u_sdram_controller(
    // sdram_core u_sdram_controller(
        .clk      (ACLK      ),
        .rst      (ARST      ),
        .ctrl_if  (ctrl_if),
        .dev_if   (dev_if)
    );

    sdram_io
    u_sdram_io
    (
        .clk                     (ACLK),
        .rst                     (ARST),
        .dev_if                  (dev_if),
        .clk_sdram               (clk_sdram),
        .sdram_cke               (sdram_cke),
        .sdram_cs_n              (sdram_cs_n),
        .sdram_ras_n             (sdram_ras_n),
        .sdram_cas_n             (sdram_cas_n),
        .sdram_we_n              (sdram_we_n),
        .sdram_dqm              (sdram_dqm),
        .sdram_a                 (sdram_a),
        .sdram_ba                (sdram_bs),
        .sdram_dq                (sdram_dq)
    );


//     // (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *)  wire                   cke = dev_if.cke;
//     // (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *)  wire                   cs = dev_if.cs;
//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *)  wire [2:0]                  dev_cmd = dev_if.cmd;
//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *)  wire [ 1:0]            dev_dqm = dev_if.dqm;
//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *)  wire [dev_if.ROW_WIDTH-1:0]   dev_addr = dev_if.addr;
//     // (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *)  wire [ 1:0]            dev_ba = dev_if.ba;
//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0"*)  wire [15:0]            dev_write_data = dev_if.write_data;
//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *)  wire                   dev_wr_en = dev_if.wr_en;

//     (* keep="true",mark_debug="true",mark_debug_clock="u_sdram_io/clk_sdram" *)  wire [15:0]            dev_read_data = dev_if.read_data;
//    (* keep="true",mark_debug="true",mark_debug_clock="u_sdram_io/clk_sdram" *)  wire [2:0]              dev2_cmd = dev_if.cmd;

//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *) wire  [ ctrl_if.WORD_LEN-1:0]      ctrl_wr = ctrl_if.wr;
//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *) wire                       ctrl_rd = ctrl_if.rd;
//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *) wire  [ ctrl_if.ADDR_WIDTH-1:0]    ctrl_addr = ctrl_if.addr;
//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *) wire  [ ctrl_if.DATA_WIDTH-1:0]    ctrl_write_data = ctrl_if.write_data;
//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *) wire                       ctrl_rdy = ctrl_if.rdy;
//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *) wire                       ctrl_rvalid = ctrl_if.rvalid;
//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *) wire                       ctrl_wvalid = ctrl_if.wvalid;
//     (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *) wire [ ctrl_if.DATA_WIDTH-1:0]     ctrl_read_data = ctrl_if.read_data;



endmodule
