`timescale 1ns/1ps

module zynq_sdram
(
    //GPIO
    input [1:0] SW,
    input [3:0] btn,
    output [3:0] LED,

    // sdram pins
    inout logic [15:0] sdram_dq,
    output logic [12:0] sdram_a,
    output logic [1:0] sdram_bs,
    output logic clk_sdram,
    output logic sdram_cke,
    output logic sdram_we_n,
    output logic sdram_cas_n,
    output logic sdram_ras_n,
    output logic sdram_cs_n,
    output logic sdram_ldqm,
    output logic sdram_udqm,

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

    assign LED[0] = SW[0];
    assign LED[1] = 1;

    wire ACLK;
    wire ARST;
    wire ARSTN;

    localparam real SDRAM_MHZ    = 50;
    localparam int ADDR_WIDTH    = 32;
    localparam int DATA_WIDTH    = 32;
    localparam int SDADDR_WIDTH  = 24;
    localparam int COL_WIDTH     = 9;

    sdram_ctrl_if #(.ADDR_WIDTH(ADDR_WIDTH), .DATA_WIDTH(DATA_WIDTH)) ctrl_if();
    sdram_dev_if #(.ADDR_WIDTH(SDADDR_WIDTH), .COL_WIDTH(COL_WIDTH)) dev_if();
    taxi_axil_if axil_if();

    zynq_ps_axi
    u_zynq
    (
    .ACLK_in              (ACLK),
    .ARST                 (ARST),
    .ARSTN                (ARSTN),
    .CLK1                 (ACLK),
    // .CLK2              (CLK2),
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
    .M00_AXI_0_araddr     (axil_if.araddr),
    .M00_AXI_0_arprot     (axil_if.arprot),
    .M00_AXI_0_arready    (axil_if.arready),
    .M00_AXI_0_arvalid    (axil_if.arvalid),
    .M00_AXI_0_awaddr     (axil_if.awaddr),
    .M00_AXI_0_awprot     (axil_if.awprot),
    .M00_AXI_0_awready    (axil_if.awready),
    .M00_AXI_0_awvalid    (axil_if.awvalid),
    .M00_AXI_0_bready     (axil_if.bready),
    .M00_AXI_0_bresp      (axil_if.bresp),
    .M00_AXI_0_bvalid     (axil_if.bvalid),
    .M00_AXI_0_rdata      (axil_if.rdata),
    .M00_AXI_0_rready     (axil_if.rready),
    .M00_AXI_0_rresp      (axil_if.rresp),
    .M00_AXI_0_rvalid     (axil_if.rvalid),
    .M00_AXI_0_wdata      (axil_if.wdata),
    .M00_AXI_0_wready     (axil_if.wready),
    .M00_AXI_0_wstrb      (axil_if.wstrb),
    .M00_AXI_0_wvalid     (axil_if.wvalid)
    );

    axil_sdram u_axil_sdram
    (
        .clk    (ACLK),
        .rst    (ARST),
        .s_axil_wr  (axil_if),
        .s_axil_rd  (axil_if),
        .sdram_ctrl (ctrl_if)
    );

    sdram_core
    #(
        .SDRAM_MHZ      (SDRAM_MHZ)
    )
    u_sdram_controller(
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
        .sdram_ldqm              (sdram_ldqm),
        .sdram_udqm              (sdram_udqm),
        .sdram_a                 (sdram_a),
        .sdram_bs                (sdram_bs),
        .sdram_dq                (sdram_dq)
    );

endmodule
