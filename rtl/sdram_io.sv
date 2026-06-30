`timescale 1ns/1ps

module sdram_io #(
    parameter real    CLK_MHZ    = 50,
    parameter int     ROW_WIDTH  = 13,
    parameter int     BANK_WIDTH = 2
)(
    input  logic                  clk,
    input  logic                  rst,

    // Internal interface (from sdram_core)
    input  logic                  dev_cke,
    input  logic                  dev_cs,
    input  logic [2:0]            dev_cmd,
    input  logic [1:0]            dev_dqm,
    input  logic [ROW_WIDTH-1:0]  dev_addr,
    input  logic [BANK_WIDTH-1:0] dev_ba,
    input  logic [15:0]           dev_write_data,
    input  logic                  dev_wr_en,
    output logic [15:0]           dev_read_data,

    // External SDRAM pins
    output          clk_sdram,
    output          sdram_cke,
    output          sdram_cs_n,
    output          sdram_ras_n,
    output          sdram_cas_n,
    output          sdram_we_n,
    output [1:0]    sdram_dqm,
    output [12:0]   sdram_a,
    output [1:0]    sdram_ba,
    inout  [15:0]   sdram_dq          // set IOB constriant on dev_read_data rather than sdram_dq per: https://adaptivesupport.amd.com/s/article/66668?language=en_US
);

//   ODDR2 #(
//       .DDR_ALIGNMENT("NONE"),
//       .INIT(1'b0),
//       .SRTYPE("SYNC")
//   ) u_clock_delay (
//       .Q  (clk_sdram),
//       .C0 (clk),
//       .C1 (~clk),
//       .CE (1'b1),
//       .R  (1'b0),
//       .S  (1'b0),
//       .D0 (1'b0),
//       .D1 (1'b1)
//   );

  wire clk_sdram_ODDR;
  ODDR #(
      .DDR_CLK_EDGE("SAME_EDGE"),
    //   .DDR_CLK_EDGE("OPPOSITE_EDGE"),
      .INIT(1'b0),
      .SRTYPE("SYNC")
  ) u_clock_oddr (
      .Q  (clk_sdram_ODDR),
      .C  (clk),
      .CE (1'b1),
      .R  (1'b0),
      .S  (1'b0),
      .D1 (1'b1),
      .D2 (1'b0)
  );

  OBUF u_clk_obuf (
      .I(clk_sdram_ODDR),
      .O(clk_sdram)
  );

  assign sdram_cke   = dev_cke;
  assign sdram_cs_n  = dev_cs;
  assign sdram_ras_n = dev_cmd[2];
  assign sdram_cas_n = dev_cmd[1];
  assign sdram_we_n  = dev_cmd[0];
  assign sdram_dqm   = dev_dqm;
  assign sdram_ba    = dev_ba;
  assign sdram_a     = dev_addr;

  logic [15:0]                  dev_read_data_raw;

  genvar i;
  for (i = 0; i < 16; i = i + 1) begin : gen_iobuf
    IOBUF #(
        .DRIVE(12),
        .IOSTANDARD("LVTTL"),
        .SLEW("FAST")
    ) u_data_buf (
        .O  (dev_read_data_raw[i]),
        .IO (sdram_dq[i]),
        .I  (dev_write_data[i]),
        .T  (~dev_wr_en)
    );
  end

  always_ff @(posedge clk) begin
      if (rst) begin
        dev_read_data <= '0;
      end else begin
        dev_read_data <= dev_read_data_raw;
      end
  end


endmodule
