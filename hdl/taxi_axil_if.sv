// SPDX-License-Identifier: MIT
/*

Copyright (c) 2025 FPGA Ninja, LLC

Authors:
- Alex Forencich

*/

interface taxi_axil_if #(
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
    parameter RUSER_W = 1
)
();
    // AW
    logic [ADDR_W-1:0]    awaddr;
    logic [2:0]           awprot;
    logic [AWUSER_W-1:0]  awuser;
    logic                 awvalid;
    logic                 awready;
    // W
    logic [DATA_W-1:0]    wdata;
    logic [STRB_W-1:0]    wstrb;
    logic [WUSER_W-1:0]   wuser;
    logic                 wvalid;
    logic                 wready;
    // B
    logic [1:0]           bresp;
    logic [BUSER_W-1:0]   buser;
    logic                 bvalid;
    logic                 bready;
    // AR
    logic [ADDR_W-1:0]    araddr;
    logic [2:0]           arprot;
    logic [ARUSER_W-1:0]  aruser;
    logic                 arvalid;
    logic                 arready;
    // R
    logic [DATA_W-1:0]    rdata;
    logic [1:0]           rresp;
    logic [RUSER_W-1:0]   ruser;
    logic                 rvalid;
    logic                 rready;

    modport man (
        // AW
        output awaddr,
        output awprot,
        output awuser,
        output awvalid,
        input  awready,
        // W
        output wdata,
        output wstrb,
        output wuser,
        output wvalid,
        input  wready,
        // B
        input  bresp,
        input  buser,
        input  bvalid,
        output bready,

        // AR
        output araddr,
        output arprot,
        output aruser,
        output arvalid,
        input  arready,
        // R
        input  rdata,
        input  rresp,
        input  ruser,
        input  rvalid,
        output rready
    );

    modport sub (
        // AW
        input  awaddr,
        input  awprot,
        input  awuser,
        input  awvalid,
        output awready,
        // W
        input  wdata,
        input  wstrb,
        input  wuser,
        input  wvalid,
        output wready,
        // B
        output bresp,
        output buser,
        output bvalid,
        input  bready,

        // AR
        input  araddr,
        input  arprot,
        input  aruser,
        input  arvalid,
        output arready,
        // R
        output rdata,
        output rresp,
        output ruser,
        output rvalid,
        input  rready
    );

    modport mon (
        // AW
        input  awaddr,
        input  awprot,
        input  awuser,
        input  awvalid,
        input  awready,
        // W
        input  wdata,
        input  wstrb,
        input  wuser,
        input  wvalid,
        input  wready,
        // B
        input  bresp,
        input  buser,
        input  bvalid,
        input  bready,

        // AR
        input  araddr,
        input  arprot,
        input  aruser,
        input  arvalid,
        input  arready,
        // R
        input  rdata,
        input  rresp,
        input  ruser,
        input  rvalid,
        input  rready
    );

endinterface


// module axi_probe (
//         input logic clk,
//         taxi_axil_if.mon axil_if );
 
//     (* keep="true",mark_debug="true" *)  wire [axil_if.ADDR_W-1:0]    awaddr = axil_if.awaddr;
//     (* keep="true",mark_debug="true" *)  wire                 awvalid = axil_if.awvalid;
//     (* keep="true",mark_debug="true" *)  wire                 awready = axil_if.awready;
//     (* keep="true",mark_debug="true" *)  wire [axil_if.DATA_W-1:0]    wdata = axil_if.wdata;
//     (* keep="true",mark_debug="true" *)  wire [axil_if.STRB_W-1:0]    wstrb = axil_if.wstrb;
//     (* keep="true",mark_debug="true" *)  wire                 wvalid = axil_if.wvalid;
//     (* keep="true",mark_debug="true" *)  wire                 wready = axil_if.wready;
//     (* keep="true",mark_debug="true" *)  wire [1:0]           bresp = axil_if.bresp;
//     (* keep="true",mark_debug="true" *)  wire [axil_if.BUSER_W-1:0]   buser = axil_if.buser;
//     (* keep="true",mark_debug="true" *)  wire                 bvalid = axil_if.bvalid;
//     (* keep="true",mark_debug="true" *)  wire                 bready = axil_if.bready;
//     (* keep="true",mark_debug="true" *)  wire [axil_if.ADDR_W-1:0]    araddr = axil_if.araddr;
//     (* keep="true",mark_debug="true" *)  wire                 arvalid = axil_if.arvalid;
//     (* keep="true",mark_debug="true" *)  wire                 arready = axil_if.arready;
//     (* keep="true",mark_debug="true" *)  wire [axil_if.DATA_W-1:0]    rdata = axil_if.rdata;
//     (* keep="true",mark_debug="true" *)  wire [1:0]           rresp = axil_if.rresp;
//     (* keep="true",mark_debug="true" *)  wire                 rvalid = axil_if.rvalid;
//     (* keep="true",mark_debug="true" *)  wire                 rready = axil_if.rready;

// endmodule