`timescale 1ns/1ps

`define DEBUG (* keep="true",mark_debug="true",mark_debug_clock="u_zynq/processing_system7_0/inst/FCLK_CLK0" *)

module sdram_io
#( parameter real CLK_MHZ = 50)
(
    // internal io w/ core
    input logic clk, rst,
    input logic phase_adv,
    output logic phase_stable,
    sdram_dev_if.sub dev_if,

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
   .CLKOUT0_PHASE(-120.0),
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


// `DEBUG logic ps_en, ps_en_clk;
// debounce u_debounce(phase_adv,clk,ps_en, ps_en_clk);

// // MMCME2_ADV: Advanced Mixed Mode Clock Manager
// //             7 Series
// // Xilinx HDL Language Template, version 2025.1

// MMCME2_ADV #(
//    .BANDWIDTH("OPTIMIZED"),        // Jitter programming (OPTIMIZED, HIGH, LOW)
//    .CLKFBOUT_MULT_F(5.0),          // Multiply value for all CLKOUT (2.000-64.000).
//    .CLKFBOUT_PHASE(0.0),           // Phase offset in degrees of CLKFB (-360.000-360.000).
//    // CLKIN_PERIOD: Input clock period in ns to ps resolution (i.e. 33.333 is 30 MHz).
//    .CLKIN1_PERIOD(20.0),
//   //  .CLKIN2_PERIOD(0.0),
//    // CLKOUT0_DIVIDE - CLKOUT6_DIVIDE: Divide amount for CLKOUT (1-128)
//   //  .CLKOUT1_DIVIDE(1),
//   //  .CLKOUT2_DIVIDE(1),
//   //  .CLKOUT3_DIVIDE(1),
//   //  .CLKOUT4_DIVIDE(1),
//   //  .CLKOUT5_DIVIDE(1),
//   //  .CLKOUT6_DIVIDE(1),
//   //  .CLKOUT0_DIVIDE_F(1.0),         // Divide amount for CLKOUT0 (1.000-128.000).
//    // CLKOUT0_DUTY_CYCLE - CLKOUT6_DUTY_CYCLE: Duty cycle for CLKOUT outputs (0.01-0.99).
//    .CLKOUT0_DUTY_CYCLE(0.5),
//   //  .CLKOUT1_DUTY_CYCLE(0.5),
//   //  .CLKOUT2_DUTY_CYCLE(0.5),
//   //  .CLKOUT3_DUTY_CYCLE(0.5),
//   //  .CLKOUT4_DUTY_CYCLE(0.5),
//   //  .CLKOUT5_DUTY_CYCLE(0.5),
//   //  .CLKOUT6_DUTY_CYCLE(0.5),
//    // CLKOUT0_PHASE - CLKOUT6_PHASE: Phase offset for CLKOUT outputs (-360.000-360.000).
//    .CLKOUT0_PHASE(0.0),
//   //  .CLKOUT1_PHASE(0.0),
//   //  .CLKOUT2_PHASE(0.0),
//   //  .CLKOUT3_PHASE(0.0),
//   //  .CLKOUT4_PHASE(0.0),
//   //  .CLKOUT5_PHASE(0.0),
//   //  .CLKOUT6_PHASE(0.0),
//   //  .CLKOUT4_CASCADE("FALSE"),      // Cascade CLKOUT4 counter with CLKOUT6 (FALSE, TRUE)
//    .COMPENSATION("ZHOLD"),         // ZHOLD, BUF_IN, EXTERNAL, INTERNAL
//    .DIVCLK_DIVIDE(5),              // Master division value (1-106)
//    // REF_JITTER: Reference input jitter in UI (0.000-0.999).
//   //  .REF_JITTER1(0.0),
//   //  .REF_JITTER2(0.0),
//   //  .STARTUP_WAIT("FALSE"),         // Delays DONE until MMCM is locked (FALSE, TRUE)
//   //  // Spread Spectrum: Spread Spectrum Attributes
//   //  .SS_EN("FALSE"),                // Enables spread spectrum (FALSE, TRUE)
//   //  .SS_MODE("CENTER_HIGH"),        // CENTER_HIGH, CENTER_LOW, DOWN_HIGH, DOWN_LOW
//   //  .SS_MOD_PERIOD(10000),          // Spread spectrum modulation period (ns) (VALUES)
//   //  // USE_FINE_PS: Fine phase shift enable (TRUE/FALSE)
//   //  .CLKFBOUT_USE_FINE_PS("FALSE"),
//    .CLKOUT0_USE_FINE_PS("TRUE")
//   //  .CLKOUT1_USE_FINE_PS("FALSE"),
//   //  .CLKOUT2_USE_FINE_PS("FALSE"),
//   //  .CLKOUT3_USE_FINE_PS("FALSE"),
//   //  .CLKOUT4_USE_FINE_PS("FALSE"),
//   //  .CLKOUT5_USE_FINE_PS("FALSE"),
//   //  .CLKOUT6_USE_FINE_PS("FALSE")
// )
// MMCME2_ADV_inst (
//    // Clock Outputs: 1-bit (each) output: User configurable clock outputs
//    .CLKOUT0(clk_sdram_pll),           // 1-bit output: CLKOUT0
//   //  .CLKOUT0B(CLKOUT0B),         // 1-bit output: Inverted CLKOUT0
//   //  .CLKOUT1(CLKOUT1),           // 1-bit output: CLKOUT1
//   //  .CLKOUT1B(CLKOUT1B),         // 1-bit output: Inverted CLKOUT1
//   //  .CLKOUT2(CLKOUT2),           // 1-bit output: CLKOUT2
//   //  .CLKOUT2B(CLKOUT2B),         // 1-bit output: Inverted CLKOUT2
//   //  .CLKOUT3(CLKOUT3),           // 1-bit output: CLKOUT3
//   //  .CLKOUT3B(CLKOUT3B),         // 1-bit output: Inverted CLKOUT3
//   //  .CLKOUT4(CLKOUT4),           // 1-bit output: CLKOUT4
//   //  .CLKOUT5(CLKOUT5),           // 1-bit output: CLKOUT5
//   //  .CLKOUT6(CLKOUT6),           // 1-bit output: CLKOUT6
//    // DRP Ports: 16-bit (each) output: Dynamic reconfiguration ports
//   //  .DO(DO),                     // 16-bit output: DRP data
//   //  .DRDY(DRDY),                 // 1-bit output: DRP ready
//    // Dynamic Phase Shift Ports: 1-bit (each) output: Ports used for dynamic phase shifting of the outputs
//    .PSDONE(phase_stable),             // 1-bit output: Phase shift done
//    // Feedback Clocks: 1-bit (each) output: Clock feedback ports
//    .CLKFBOUT(clkf_buf1),         // 1-bit output: Feedback clock
//   //  .CLKFBOUTB(CLKFBOUTB),       // 1-bit output: Inverted CLKFBOUT
//   //  // Status Ports: 1-bit (each) output: MMCM status ports
//   //  .CLKFBSTOPPED(CLKFBSTOPPED), // 1-bit output: Feedback clock stopped
//   //  .CLKINSTOPPED(CLKINSTOPPED), // 1-bit output: Input clock stopped
//   //  .LOCKED(LOCKED),             // 1-bit output: LOCK
//   //  // Clock Inputs: 1-bit (each) input: Clock inputs
//    .CLKIN1(clk_buf),             // 1-bit input: Primary clock
//   //  .CLKIN2(CLKIN2),             // 1-bit input: Secondary clock
//    // Control Ports: 1-bit (each) input: MMCM control ports
//    .CLKINSEL(1'b1),         // 1-bit input: Clock select, High=CLKIN1 Low=CLKIN2
//   //  .PWRDWN(PWRDWN),             // 1-bit input: Power-down
//    .RST(rst),                   // 1-bit input: Reset
//    // DRP Ports: 7-bit (each) input: Dynamic reconfiguration ports
//   //  .DADDR(DADDR),               // 7-bit input: DRP address
//   //  .DCLK(DCLK),                 // 1-bit input: DRP clock
//   //  .DEN(DEN),                   // 1-bit input: DRP enable
//   //  .DI(DI),                     // 16-bit input: DRP data
//   //  .DWE(DWE),                   // 1-bit input: DRP write enable
//   //  // Dynamic Phase Shift Ports: 1-bit (each) input: Ports used for dynamic phase shifting of the outputs
//    .PSCLK(ps_en_clk),               // 1-bit input: Phase shift clock
//    .PSEN(ps_en),                 // 1-bit input: Phase shift enable
//    .PSINCDEC(1'b1),         // 1-bit input: Phase shift increment/decrement
//   //  // Feedback Clocks: 1-bit (each) input: Clock feedback ports
//    .CLKFBIN(clkf_buf2)            // 1-bit input: Feedback clock
// );

// // End of MMCME2_ADV_inst instantiation







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


module debounce(input pb_1,clk,output pb_out, output slow_clk);
wire Q1,Q2,Q2_bar,Q0;
clock_div u1(clk,slow_clk);
my_dff d0(slow_clk, pb_1,Q0 );

my_dff d1(slow_clk, Q0,Q1 );
my_dff d2(slow_clk, Q1,Q2 );
assign Q2_bar = ~Q2;
assign pb_out = Q1 & Q2_bar;
endmodule
// Slow clock for debouncing 
module clock_div(input Clk_100M, output reg slow_clk

    );
    reg [26:0]counter=0;
    always @(posedge Clk_100M)
    begin
        counter <= (counter>=249999)?0:counter+1;
        slow_clk <= (counter < 125000)?1'b0:1'b1;
    end
endmodule
// D-flip-flop for debouncing module 
module my_dff(input DFF_CLOCK, D, output reg Q);

    always @ (posedge DFF_CLOCK) begin
        Q <= D;
    end

endmodule