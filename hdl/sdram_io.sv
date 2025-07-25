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

  // ODDR u_clock_delay
  // (
  //  .Q(clk_sdram), 
  //  .C(clk),       
  //  .CE(1'b1),     
  //  .D1(1'b1),     
  //  .D2(1'b0),     
  //  .R(1'b0),      
  //  .S(1'b1)       
  // );

  ODDR2 
  #(
      .DDR_ALIGNMENT("NONE"),
      .INIT(1'b0),
      .SRTYPE("SYNC")
  )
  u_clock_delay
  (
      .Q(clk_sdram),
      .C0(clk),
      .C1(~clk),
      .CE(1'b1),
      .R(1'b0),
      .S(1'b0),
      .D0(1'b0),
      .D1(1'b1)
  );

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

