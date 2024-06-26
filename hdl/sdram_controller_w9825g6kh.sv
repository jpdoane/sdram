`timescale 1ns/1ps

module sdram_controller_w9825g6kh #(
    parameter SD_CLK_PERIOD_NS=23.288,
    parameter CAS_LATENCY = 2,
    parameter SIM_STARTUP = 1
    )(
    input logic clk, rst,
    input logic [7:0] data_wr,
    input logic [24:0] addr_in,
    input logic wr,
    input logic rd,
    output logic rdy,
    output logic val,
    output logic [7:0] data_rd,

    // sdram pins
    output logic [12:0] sdram_a,
    output logic [1:0] sdram_bs,
    output logic sdram_cs_n,
    output logic sdram_ras_n,
    output logic sdram_cas_n,
    output logic sdram_we_n,
    output logic sdram_udqm, sdram_ldqm,
    output logic sdram_cke,

    // sdram datra iopins
    input logic [15:0] sdram_din,
    output logic [15:0] sdram_dout,
    output logic sdram_dout_en
);

localparam ADDR_DEPTH = 25;
localparam COL_DEPTH  = 10;
localparam tRC_NS =    60.0;        // min time in ns between row activations (same bank)
localparam tRAS_NS =   42.0;        // min time in ns from row activation to precharge (same bank)
localparam tRCD_NS =   15.0;        // min time in ns from row activation to read/write
localparam tRP_NS =    15.0;        // min time in ns from precharge to refresh/activation (same bank)
localparam tXSR_NS =   72.0;        // min time in ns from self-refresh exit to activation
localparam tREF_NS =   64000000.0;  // `MAX time in ns to perform all 8k refresh cycles
localparam DELAY_WR =    2;    // min clocks between row activations (different bank)
localparam DELAY_RRD =   2;    // min clocks between row activations (different bank)
// localparam integer DELAY_RAS  =  $ceil(tRAS_NS/SD_CLK_PERIOD_NS);       // NES: 2
// localparam integer DELAY_XSR  =  $ceil(tXSR_NS/SD_CLK_PERIOD_NS);       // NES: 4
// localparam integer DELAY_REF  =  $ceil(tREF_NS/SD_CLK_PERIOD_NS);       // NES: 2748197

localparam DELAY_RC   =  $ceil(tRC_NS / SD_CLK_PERIOD_NS);
localparam DELAY_RCD  =  $ceil(tRCD_NS/SD_CLK_PERIOD_NS);
localparam DELAY_RP   =  $ceil(tRP_NS/SD_CLK_PERIOD_NS);
localparam DELAY_DAL  =  DELAY_WR + DELAY_RP;
localparam DELAY_REF_INTERVAL  = $floor(tREF_NS/8192/SD_CLK_PERIOD_NS);
localparam DELAY_RSC =   2;        
localparam DELAY_STARTUP  = SIM_STARTUP ? 20 : $ceil(210000 / SD_CLK_PERIOD_NS);                                                                        // for NES, SD_CLK_PERIOD_NS = 23.3ns (clock @ PPU*8 = 42.9MHz)

sdram_controller #(
    .ADDR_DEPTH           (ADDR_DEPTH),
    .COL_DEPTH            (COL_DEPTH),
    .CAS_LATENCY          (CAS_LATENCY),
    .DELAY_RC             (DELAY_RC),
    .DELAY_RCD            (DELAY_RCD),
    .DELAY_RP             (DELAY_RP),
    .DELAY_DAL            (DELAY_DAL),
    .DELAY_REF_INTERVAL   (DELAY_REF_INTERVAL),
    .DELAY_RSC            (DELAY_RSC),
    .DELAY_STARTUP        (DELAY_STARTUP))
u_sdram_controller (
    .clk                  (clk),
    .rst                  (rst),
    .data_wr              (data_wr),
    .addr_in              (addr_in),
    .wr                   (wr),
    .rd                   (rd),
    .rdy                  (rdy),
    .val                  (val),
    .data_rd              (data_rd),
    .sdram_a                 (sdram_a),
    .sdram_bs                (sdram_bs),
    .sdram_cs_n              (sdram_cs_n),
    .sdram_ras_n             (sdram_ras_n),
    .sdram_cas_n             (sdram_cas_n),
    .sdram_we_n              (sdram_we_n),
    .sdram_udqm              (sdram_udqm),
    .sdram_ldqm              (sdram_ldqm),
    .sdram_cke               (sdram_cke),
    .sdram_din               (sdram_din),
    .sdram_dout              (sdram_dout),
    .sdram_dout_en           (sdram_dout_en)
);

endmodule