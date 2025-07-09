`timescale 1ns/1ps

module sdram_io
#( parameter real CLK_MHZ = 50)
(
    // internal io w/ core
    input         clk, rst,
    input          sdram_core_cke,
    input          sdram_core_cs,
    input [2:0]    sdram_core_cmd,
    input [  1:0]  sdram_core_dqm,
    input [ 12:0]  sdram_core_addr,
    input [  1:0]  sdram_core_ba,
    input [ 15:0]  sdram_core_data_output,
    input          sdram_core_data_out_en,
    output  [ 15:0] sdram_core_data_input,


    // external pin io
    output          clk_sdram,
    output          sdram_cke,
    output          sdram_cs_n,
    output          sdram_ras_n,
    output          sdram_cas_n,
    output          sdram_we_n,
    output [1:0]    sdram_dqm,
    output [12:0]   sdram_a,
    output [ 1:0]   sdram_ba,
    inout  [15:0]   sdram_dq
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
   .CLKOUT0_PHASE(-90.0),
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

    
  assign sdram_cke = sdram_core_cke;
  assign sdram_cs_n = sdram_core_cs;
  assign sdram_ras_n = sdram_core_cmd[2];
  assign sdram_cas_n = sdram_core_cmd[1];
  assign sdram_we_n = sdram_core_cmd[0];
  assign sdram_dqm = sdram_core_dqm;
  assign sdram_a = sdram_core_addr;
  assign sdram_ba = sdram_core_ba;


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
      .O(sdram_core_data_input[i]),
      .IO(sdram_dq[i]),
      .I(sdram_core_data_output[i]),
      .T(~sdram_core_data_out_en)
    );
  end


endmodule
