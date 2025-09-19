`timescale 1ns/1ps


module sdram_axil_tb #(
    // Width of data bus in bits
    parameter DATA_W = 32,
    // Width of address bus in bits
    parameter ADDR_W = 32,
    // Width of wstrb (width of data bus in words)
    parameter STRB_W = (DATA_W/8),
    // Use awuser signal
    parameter logic AWUSER_EN = 1'b0,
    // Width of awuser signal
    parameter AWUSER_W = 1,
    // Use wuser signal
    parameter logic WUSER_EN = 1'b0,
    // Width of wuser signal
    parameter WUSER_W = 1,
    // Use buser signal
    parameter logic BUSER_EN = 1'b0,
    // Width of buser signal
    parameter BUSER_W = 1,
    // Use aruser signal
    parameter logic ARUSER_EN = 1'b0,
    // Width of aruser signal
    parameter ARUSER_W = 1,
    // Use ruser signal
    parameter logic RUSER_EN = 1'b0,
    // Width of ruser signal
    parameter RUSER_W = 1,

    parameter real FREQ_MHZ    = 50.0

)
(
    input  logic                 clk,
    input  logic                 rst,
    input  logic [ADDR_W-1:0]    awaddr,
    input  logic [2:0]           awprot,
    input  logic [AWUSER_W-1:0]  awuser,
    input  logic                 awvalid,
    output logic                 awready,
    //     W
    input  logic [DATA_W-1:0]    wdata,
    input  logic [STRB_W-1:0]    wstrb,
    input  logic [WUSER_W-1:0]   wuser,
    input  logic                 wvalid,
    output logic                 wready,
    //     B
    output logic [1:0]           bresp,
    output logic [BUSER_W-1:0]   buser,
    output logic                 bvalid,
    input  logic                 bready,
    //     AR
    input  logic [ADDR_W-1:0]    araddr,
    input  logic [2:0]           arprot,
    input  logic [ARUSER_W-1:0]  aruser,
    input  logic                 arvalid,
    output logic                 arready,
    //     R
    output logic [DATA_W-1:0]    rdata,
    output logic [1:0]           rresp,
    output logic [RUSER_W-1:0]   ruser,
    output logic                 rvalid,
    input  logic                 rready
    );

    // localparam DEBUG_SDRAM=0;
    // localparam real CLK_PERIOD=1000/FREQ_MHZ;
    // localparam real QTR_CLK_PERIOD=CLK_PERIOD/4;

    wire sdram_clk = ~clk; 

    sdram_ctrl_if sdram_ctrl_if();
    sdram_dev_if sdram_dev_if();
    taxi_axil_if axi_if();

    // inputs
    assign axi_if.awaddr = awaddr;
    assign axi_if.awprot = awprot;
    assign axi_if.awuser = awuser;
    assign axi_if.awvalid = awvalid;
    assign axi_if.wdata = wdata;
    assign axi_if.wstrb = wstrb;
    assign axi_if.wuser = wuser;
    assign axi_if.wvalid = wvalid;
    assign axi_if.bready = bready;
    assign axi_if.araddr = araddr;
    assign axi_if.arprot = arprot;
    assign axi_if.aruser = aruser;
    assign axi_if.arvalid = arvalid;
    assign axi_if.rready = rready;

    // outputs
    assign awready = axi_if.awready;
    assign wready = axi_if.wready;
    assign bresp = axi_if.bresp;
    assign buser = axi_if.buser;
    assign bvalid = axi_if.bvalid;
    assign arready = axi_if.arready;
    assign rdata = axi_if.rdata;
    assign rresp = axi_if.rresp;
    assign ruser = axi_if.ruser;
    assign rvalid = axi_if.rvalid;

    axil_sdram u_axil_sdram
    (
        .clk    (clk),
        .rst    (rst),
        .axi_if  (axi_if),
        .sdram_ctrl (sdram_ctrl_if)
    );

    sdram_core
    #(
        .FREQ_MHZ      (FREQ_MHZ),
        .STARTUP_US     (1)
    )
    u_sdram_controller(
        .clk      (clk      ),
        .rst      (rst      ),
        .ctrl_if  (sdram_ctrl_if),
        .dev_if   (sdram_dev_if)
    );
    
    MT48LC8M16A2 #(
    .Debug(`DEBUG_SDRAM)
    )
    u_sdram_model(sdram_clk, sdram_dev_if.man);

endmodule