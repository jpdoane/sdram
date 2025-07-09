`timescale 1ns/1ps

module sdram_io
#( parameter real CLK_MHZ = 50)
(
    // internal io w/ core
    input logic clk, rst,
    sdram_dev_if.sub dev_if,

    // external pin io
    (* IOB = "TRUE" *) output          clk_sdram,
    (* IOB = "TRUE" *) output          sdram_cke,
    (* IOB = "TRUE" *) output          sdram_cs_n,
    (* IOB = "TRUE" *) output          sdram_ras_n,
    (* IOB = "TRUE" *) output          sdram_cas_n,
    (* IOB = "TRUE" *) output          sdram_we_n,
    (* IOB = "TRUE" *) output [1:0]    sdram_dqm,
    (* IOB = "TRUE" *) output [12:0]   sdram_a,
    (* IOB = "TRUE" *) output [ 1:0]   sdram_ba,
    (* IOB = "TRUE" *) inout  [15:0]   sdram_dq
);

localparam real CLK_PERIOD_NS       = 1000.0 / CLK_MHZ;

logic clk_buf;
logic clkf_buf1, clkf_buf2;
logic clk_sdram_pll;
logic pll_lock;

PLLE2_BASE #(
   .BANDWIDTH("OPTIMIZED"),
   .CLKFBOUT_MULT(17),
   .CLKFBOUT_PHASE(0.0),
   .CLKIN1_PERIOD(CLK_PERIOD_NS),
   .CLKOUT0_DIVIDE(17),
   .CLKOUT0_DUTY_CYCLE(0.5),
   .CLKOUT0_PHASE(180.0),
   .DIVCLK_DIVIDE(1)
)
PLLE2_BASE_inst (
   .CLKOUT0(clk_sdram_pll),
   .CLKFBOUT(clkf_buf1), 
   .LOCKED(pll_lock),  
   .CLKIN1(clk_buf),
   .PWRDWN(1'b0),
   .RST(rst),          
   .CLKFBIN(clkf_buf2)
);


  BUFG clk_bufg
   (.O (clk_buf),
    .I (clk));


  BUFG clkf_bufg
   (.O (clkf_buf2),
    .I (clkf_buf1));

  BUFG clkout1_bufg
   (.O   (clk_sdram),
    .I   (clk_sdram_pll));


  // ODDR2 
  // #(
  //     .DDR_ALIGNMENT("NONE"),
  //     .INIT(1'b0),
  //     .SRTYPE("SYNC")
  // )
  // u_clock_delay
  // (
  //     .Q(clk_sdram),
  //     .C0(clk),
  //     .C1(~clk),
  //     .CE(1'b1),
  //     .R(1'b0),
  //     .S(1'b0),
  //     .D0(1'b0),
  //     .D1(1'b1)
  // );

  // ODDR
  // #(
  //     .DDR_CLK_EDGE("OPPOSITE_EDGE"),
  //     .INIT(1'b0),
  //     .SRTYPE("SYNC")
  // )
  // u_clock_delay
  // (
  //  .Q(clk_sdram), 
  //  .C(clk),       
  //  .CE(1'b1),     
  //  .D1(1'b1),     
  //  .D2(1'b0),     
  //  .R(1'b0),      
  //  .S(1'b1)       
  // );



  assign sdram_cke = dev_if.cke;
  assign sdram_cs_n = dev_if.cs;
  assign sdram_ras_n = dev_if.cmd[2];
  assign sdram_cas_n = dev_if.cmd[1];
  assign sdram_we_n = dev_if.cmd[0];
  assign sdram_dqm = dev_if.dqm;
  assign sdram_ba = dev_if.ba;
  assign sdram_a = dev_if.addr;


  genvar i;
  for (i=0; i < 16; i = i + 1) 
  begin
    IOBUF 
    #(
      .DRIVE(12),
      .IOSTANDARD("LVTTL"),
      .SLEW("FAST")
    )
    u_data_buf
    (
      .O(dev_if.read_data[i]),
      .IO(sdram_dq[i]),
      .I(dev_if.write_data[i]),
      .T(~dev_if.wr_en)
    );
  end

endmodule

