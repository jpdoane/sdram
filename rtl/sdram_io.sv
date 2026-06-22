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
    (* IOB = "TRUE" *) output          clk_sdram,
    (* IOB = "TRUE" *) output          sdram_cke,
    (* IOB = "TRUE" *) output          sdram_cs_n,
    (* IOB = "TRUE" *) output          sdram_ras_n,
    (* IOB = "TRUE" *) output          sdram_cas_n,
    (* IOB = "TRUE" *) output          sdram_we_n,
    (* IOB = "TRUE" *) output [1:0]    sdram_dqm,
    (* IOB = "TRUE" *) output [12:0]   sdram_a,
    (* IOB = "TRUE" *) output [1:0]    sdram_ba,
    (* IOB = "TRUE" *) inout  [15:0]   sdram_dq
);

  ODDR2 #(
      .DDR_ALIGNMENT("NONE"),
      .INIT(1'b0),
      .SRTYPE("SYNC")
  ) u_clock_delay (
      .Q  (clk_sdram),
      .C0 (clk),
      .C1 (~clk),
      .CE (1'b1),
      .R  (1'b0),
      .S  (1'b0),
      .D0 (1'b0),
      .D1 (1'b1)
  );

  assign sdram_cke   = dev_cke;
  assign sdram_cs_n  = dev_cs;
  assign sdram_ras_n = dev_cmd[2];
  assign sdram_cas_n = dev_cmd[1];
  assign sdram_we_n  = dev_cmd[0];
  assign sdram_dqm   = dev_dqm;
  assign sdram_ba    = dev_ba;
  assign sdram_a     = dev_addr;

  genvar i;
  for (i = 0; i < 16; i = i + 1) begin : gen_iobuf
    IOBUF #(
        .DRIVE(12),
        .IOSTANDARD("LVTTL"),
        .SLEW("FAST")
    ) u_data_buf (
        .O  (dev_read_data[i]),
        .IO (sdram_dq[i]),
        .I  (dev_write_data[i]),
        .T  (~dev_wr_en)
    );
  end

endmodule
