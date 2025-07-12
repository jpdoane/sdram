`timescale 1ns / 100ps

interface sdram_ctrl_if
#(
    parameter int ADDR_WIDTH=32,
    parameter int DATA_WIDTH=32,
    parameter int WORD_LEN=DATA_WIDTH/8
)
();
    logic  [ WORD_LEN-1:0]      wr;
    logic                       rd;
    logic  [ ADDR_WIDTH-1:0]    addr;
    logic  [ DATA_WIDTH-1:0]    write_data;
    logic                       rdy;
    logic                       rvalid;
    logic                       wvalid;
    logic                       error;
    logic [ DATA_WIDTH-1:0]     read_data;


    modport man (input  rdy, rvalid, wvalid, error, read_data,
                 output wr, rd, addr, write_data);

    modport sub (input wr, rd, addr, write_data,
                 output rdy, rvalid, wvalid, error, read_data);

    modport mon (input wr, rd, addr, write_data, rdy, rvalid, wvalid, error, read_data);

endinterface

interface sdram_dev_if
#(
    parameter ADDR_WIDTH=24,
    parameter ROW_WIDTH=13,
    parameter BANK_WIDTH=2,
    parameter COL_WIDTH=ADDR_WIDTH-ROW_WIDTH-BANK_WIDTH
)
();

    logic                   cke;
    logic                   cs;
    logic [ 2:0]            cmd;
    logic [ 1:0]            dqm;
    logic [ROW_WIDTH-1:0]   addr;
    logic [BANK_WIDTH-1:0]  ba;
    logic [15:0]            read_data;
    logic [15:0]            write_data;
    logic                   wr_en;

    modport man (input read_data,
                 output cke, cs, cmd, dqm, addr, ba, write_data, wr_en);
  
    modport sub (input cke, cs, cmd, dqm, addr, ba, write_data, wr_en, 
                 output read_data);

    modport mon (input cke, cs, cmd, dqm, addr, ba, write_data, wr_en,  read_data);
endinterface


// module sdram_ctrl_probe (
//         input logic clk,
//         sdram_ctrl_if.mon ctrl_if );

//     (* keep="true",mark_debug="true" *) wire  [ ctrl_if.WORD_LEN-1:0]      wr = ctrl_if.wr;
//     (* keep="true",mark_debug="true" *) wire                       rd = ctrl_if.rd;
//     (* keep="true",mark_debug="true" *) wire  [ ctrl_if.ADDR_WIDTH-1:0]    addr = ctrl_if.addr;
//     (* keep="true",mark_debug="true" *) wire  [ ctrl_if.DATA_WIDTH-1:0]    write_data = ctrl_if.write_data;
//     (* keep="true",mark_debug="true" *) wire                       rdy = ctrl_if.rdy;
//     (* keep="true",mark_debug="true" *) wire                       rvalid = ctrl_if.rvalid;
//     (* keep="true",mark_debug="true" *) wire                       wvalid = ctrl_if.wvalid;
//     // (* keep="true",mark_debug="true" *) wire                       error = ctrl_if.error;
//     (* keep="true",mark_debug="true" *) wire [ ctrl_if.DATA_WIDTH-1:0]     read_data = ctrl_if.read_data;

// endmodule

// module sdram_dev_probe (
//         input logic clk,
//         sdram_dev_if.mon dev_if );

//     (* keep="true",mark_debug="true" *)  wire                   cke = dev_if.cke;
//     (* keep="true",mark_debug="true" *)  wire                   cs = dev_if.cs;
//     (* keep="true",mark_debug="true" *)  wire                   ras = dev_if.ras;
//     (* keep="true",mark_debug="true" *)  wire                   cas = dev_if.cas;
//     (* keep="true",mark_debug="true" *)  wire                   we = dev_if.we;
//     (* keep="true",mark_debug="true" *)  wire [ 1:0]            dqm = dev_if.dqm;
//     (* keep="true",mark_debug="true" *)  wire [dev_if.ROW_WIDTH-1:0]   addr = dev_if.addr;
//     (* keep="true",mark_debug="true" *)  wire [ 1:0]            ba = dev_if.ba;
//     (* keep="true",mark_debug="true" *)  wire [15:0]            read_data = dev_if.read_data;
//     (* keep="true",mark_debug="true" *)  wire [15:0]            write_data = dev_if.write_data;
//     (* keep="true",mark_debug="true" *)  wire                   wr_en = dev_if.wr_en;

// endmodule