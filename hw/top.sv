`timescale 1ns/1ps

// zynq_sdram top-level
//
// Instantiates:
//   zynq_ps_axi      -- Zynq PS block design (provides 50 MHz ACLK, AXI master)
//   dual_master_sdram -- arbitrates AXI (PS) and portB (PL tester)
//   sdram_core       -- SDRAM timing controller
//   sdram_io         -- SDRAM physical I/O (IOB registers, ODDR clock)
//   portb_tester     -- PL-side CPU port exerciser on a decimated clock
//
// LED assignment:
//   LED[0]  portB test complete (stays lit after first pass or fail)
//   LED[1]  portB test PASS  (all readbacks matched)
//   LED[2]  portB test FAIL  (at least one mismatch)
//   LED[3]  heartbeat blink  (confirms PL is alive / clock running)
//
// SW[0]  restart the portB tester (rising edge triggers a new pass)
// SW[1]  unused

module zynq_sdram
(
    input  [1:0]  SW,
    input  [3:0]  BTN,
    output [3:0]  LED,

    // SDRAM pins
    inout  logic [15:0] sdram_dq,
    output logic [12:0] sdram_a,
    output logic [1:0]  sdram_ba,
    output logic        clk_sdram,
    output logic        sdram_cke,
    output logic        sdram_we_n,
    output logic        sdram_cas_n,
    output logic        sdram_ras_n,
    output logic        sdram_cs_n,
    output logic [1:0]  sdram_dqm,

    // Zynq DDR and fixed IO
    inout [14:0] DDR_addr,
    inout [2:0]  DDR_ba,
    inout        DDR_cas_n,
    inout        DDR_ck_n,
    inout        DDR_ck_p,
    inout        DDR_cke,
    inout        DDR_cs_n,
    inout [3:0]  DDR_dm,
    inout [31:0] DDR_dq,
    inout [3:0]  DDR_dqs_n,
    inout [3:0]  DDR_dqs_p,
    inout        DDR_odt,
    inout        DDR_ras_n,
    inout        DDR_reset_n,
    inout        DDR_we_n,
    inout        FIXED_IO_ddr_vrn,
    inout        FIXED_IO_ddr_vrp,
    inout [53:0] FIXED_IO_mio,
    inout        FIXED_IO_ps_clk,
    inout        FIXED_IO_ps_porb,
    inout        FIXED_IO_ps_srstb
);

    // -----------------------------------------------------------------------
    // Clocks / resets from Zynq PS block design
    // -----------------------------------------------------------------------

    wire ACLK;   // 50 MHz from FCLK_CLK1 (drives all PL logic)
    wire ARST;   // active-high synchronous reset

    // map btn[0] to reset module
    wire btn_rst = BTN[0];

    localparam real FREQ_MHZ   = 50.0;
    localparam int  ADDR_WIDTH = 25;
    localparam int  DATA_WIDTH = 32;
    localparam int  WORD_LEN   = DATA_WIDTH / 8;

    // -----------------------------------------------------------------------
    // AXI-Lite signals: Zynq PS M00_AXI_0 -> dual_master_sdram
    // -----------------------------------------------------------------------

    logic [31:0] axil_awaddr;
    logic        axil_awvalid;
    logic        axil_awready;
    logic [31:0] axil_wdata;
    logic [3:0]  axil_wstrb;
    logic        axil_wvalid;
    logic        axil_wready;
    logic [1:0]  axil_bresp;
    logic        axil_bvalid;
    logic        axil_bready;
    logic [31:0] axil_araddr;
    logic        axil_arvalid;
    logic        axil_arready;
    logic [31:0] axil_rdata;
    logic [1:0]  axil_rresp;
    logic        axil_rvalid;
    logic        axil_rready;

    // Unused M01_AXI_0 signals (second PS AXI master port, not connected)
    logic [31:0] m01_araddr, m01_awaddr, m01_wdata;
    logic        m01_arvalid, m01_awvalid, m01_wvalid, m01_bready, m01_rready;
    logic [3:0]  m01_wstrb;
    logic [2:0]  m01_arprot, m01_awprot;

    // -----------------------------------------------------------------------
    // SDRAM controller signals: dual_master_sdram -> sdram_core
    // -----------------------------------------------------------------------

    (* mark_debug = "true" *) logic [WORD_LEN-1:0]   ctrl_wr;
    (* mark_debug = "true" *) logic                  ctrl_rd;
    (* mark_debug = "true" *) logic [ADDR_WIDTH-1:0] ctrl_addr;
    (* mark_debug = "true" *) logic [DATA_WIDTH-1:0] ctrl_write_data;
    (* mark_debug = "true" *) logic                  ctrl_rdy;
    (* mark_debug = "true" *) logic                  ctrl_rvalid;
    (* mark_debug = "true" *) logic                  ctrl_wvalid;
    (* mark_debug = "true" *) logic                  ctrl_error;
    (* mark_debug = "true" *) logic [DATA_WIDTH-1:0] ctrl_read_data;

    // -----------------------------------------------------------------------
    // SDRAM device signals: sdram_core -> sdram_io
    // -----------------------------------------------------------------------

    (* IOB = "TRUE" *) logic        dev_cke;
    (* IOB = "TRUE" *) logic        dev_cs;
    (* IOB = "TRUE" *) logic [2:0]  dev_cmd;
    (* IOB = "TRUE" *) logic [1:0]  dev_dqm;
    (* IOB = "TRUE" *) logic [12:0] dev_addr;
    (* IOB = "TRUE" *) logic [1:0]  dev_ba;
    (* IOB = "TRUE" *) logic [15:0] dev_write_data;
    (* IOB = "TRUE" *) logic        dev_wr_en;
    (* IOB = "TRUE" *) logic [15:0] dev_read_data;

    // -----------------------------------------------------------------------
    // portB signals: portb_tester -> dual_master_sdram
    // -----------------------------------------------------------------------

    logic                  portB_en;
    logic [WORD_LEN-1:0]   portB_wr;
    logic [ADDR_WIDTH-1:0] portB_addr;
    logic [DATA_WIDTH-1:0] portB_write_data;
    logic [DATA_WIDTH-1:0] portB_read_data;
    logic                  portB_rdy;

    // portb_tester status
    logic        test_done;
    logic        test_pass;
    logic [15:0] error_count;

    // -----------------------------------------------------------------------
    // Heartbeat counter (bit [25] toggles at ~0.67 Hz at 50 MHz)
    // -----------------------------------------------------------------------

    logic [25:0] hb_cnt;
    always_ff @(posedge clk) hb_cnt <= hb_cnt + 1;

    // -----------------------------------------------------------------------
    // LEDs
    // -----------------------------------------------------------------------

    assign LED[0] = test_done;
    assign LED[1] = test_done &  test_pass;
    assign LED[2] = test_done & ~test_pass;
    assign LED[3] = hb_cnt[25];

    // clock divider
    wire clk, rst;
    wire clk_div, div_en;

    clk_div #(
        .DIV(24)
    ) u_clk_div (
        .clk_master (ACLK),
        .rst_master (ARST),
        .clk_buf    (clk),
        .rst_buf    (rst),
        .clk_div    (clk_div),
        .div_en     (div_en)
    );

    // -----------------------------------------------------------------------
    // Zynq PS block design
    // -----------------------------------------------------------------------

    zynq_ps_axi u_zynq
    (
        .ACLK_in          (clk),   
        .ARST             (ARST),
        .ARST_in          (btn_rst),
        .CLK0             (),           // 100 MHz -- unused
        .CLK1             (ACLK),       // 50 MHz  -- main PL clock
        .DDR_addr         (DDR_addr),
        .DDR_ba           (DDR_ba),
        .DDR_cas_n        (DDR_cas_n),
        .DDR_ck_n         (DDR_ck_n),
        .DDR_ck_p         (DDR_ck_p),
        .DDR_cke          (DDR_cke),
        .DDR_cs_n         (DDR_cs_n),
        .DDR_dm           (DDR_dm),
        .DDR_dq           (DDR_dq),
        .DDR_dqs_n        (DDR_dqs_n),
        .DDR_dqs_p        (DDR_dqs_p),
        .DDR_odt          (DDR_odt),
        .DDR_ras_n        (DDR_ras_n),
        .DDR_reset_n      (DDR_reset_n),
        .DDR_we_n         (DDR_we_n),
        .FIXED_IO_ddr_vrn (FIXED_IO_ddr_vrn),
        .FIXED_IO_ddr_vrp (FIXED_IO_ddr_vrp),
        .FIXED_IO_mio     (FIXED_IO_mio),
        .FIXED_IO_ps_clk  (FIXED_IO_ps_clk),
        .FIXED_IO_ps_porb (FIXED_IO_ps_porb),
        .FIXED_IO_ps_srstb(FIXED_IO_ps_srstb),

        // M00_AXI_0 -> dual_master_sdram AXI port (SDRAM at 0x4000_0000)
        .M00_AXI_0_araddr (axil_araddr),
        .M00_AXI_0_arprot (),
        .M00_AXI_0_arready(axil_arready),
        .M00_AXI_0_arvalid(axil_arvalid),
        .M00_AXI_0_awaddr (axil_awaddr),
        .M00_AXI_0_awprot (),
        .M00_AXI_0_awready(axil_awready),
        .M00_AXI_0_awvalid(axil_awvalid),
        .M00_AXI_0_bready (axil_bready),
        .M00_AXI_0_bresp  (axil_bresp),
        .M00_AXI_0_bvalid (axil_bvalid),
        .M00_AXI_0_rdata  (axil_rdata),
        .M00_AXI_0_rready (axil_rready),
        .M00_AXI_0_rresp  (axil_rresp),
        .M00_AXI_0_rvalid (axil_rvalid),
        .M00_AXI_0_wdata  (axil_wdata),
        .M00_AXI_0_wready (axil_wready),
        .M00_AXI_0_wstrb  (axil_wstrb),
        .M00_AXI_0_wvalid (axil_wvalid),

        // M01_AXI_0 -- unused; tie off outputs from PS side
        .M01_AXI_0_araddr (m01_araddr),
        .M01_AXI_0_arprot (m01_arprot),
        .M01_AXI_0_arready(1'b0),
        .M01_AXI_0_arvalid(m01_arvalid),
        .M01_AXI_0_awaddr (m01_awaddr),
        .M01_AXI_0_awprot (m01_awprot),
        .M01_AXI_0_awready(1'b0),
        .M01_AXI_0_awvalid(m01_awvalid),
        .M01_AXI_0_bready (m01_bready),
        .M01_AXI_0_bresp  (2'b00),
        .M01_AXI_0_bvalid (1'b0),
        .M01_AXI_0_rdata  (32'h0),
        .M01_AXI_0_rready (m01_rready),
        .M01_AXI_0_rresp  (2'b00),
        .M01_AXI_0_rvalid (1'b0),
        .M01_AXI_0_wdata  (m01_wdata),
        .M01_AXI_0_wready (1'b0),
        .M01_AXI_0_wstrb  (m01_wstrb),
        .M01_AXI_0_wvalid (m01_wvalid)
    );

    // -----------------------------------------------------------------------
    // Dual-master SDRAM arbiter
    // AXI port: Zynq PS (high priority)
    // portB port: PL portb_tester (decimated clock, lower priority)
    // -----------------------------------------------------------------------

    dual_master_sdram #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) u_dual_master (
        .clk(clk),
        .rst(rst),

        // AXI-Lite port (PS master)
        .axil_awaddr (axil_awaddr[ADDR_WIDTH-1:0]),
        .axil_awvalid(axil_awvalid),
        .axil_awready(axil_awready),
        .axil_wdata  (axil_wdata),
        .axil_wstrb  (axil_wstrb),
        .axil_wvalid (axil_wvalid),
        .axil_wready (axil_wready),
        .axil_bresp  (axil_bresp),
        .axil_bvalid (axil_bvalid),
        .axil_bready (axil_bready),
        .axil_araddr (axil_araddr[ADDR_WIDTH-1:0]),
        .axil_arvalid(axil_arvalid),
        .axil_arready(axil_arready),
        .axil_rdata  (axil_rdata),
        .axil_rresp  (axil_rresp),
        .axil_rvalid (axil_rvalid),
        .axil_rready (axil_rready),

        // portB port (PL tester)
        .portB_en        (portB_en),
        .portB_wr        (portB_wr),
        .portB_addr      (portB_addr),
        .portB_write_data(portB_write_data),
        .portB_read_data (portB_read_data),
        .portB_rdy       (portB_rdy),

        // SDRAM controller port
        .sdram_ctrl_wr        (ctrl_wr),
        .sdram_ctrl_rd        (ctrl_rd),
        .sdram_ctrl_addr      (ctrl_addr),
        .sdram_ctrl_write_data(ctrl_write_data),
        .sdram_ctrl_rdy       (ctrl_rdy),
        .sdram_ctrl_rvalid    (ctrl_rvalid),
        .sdram_ctrl_wvalid    (ctrl_wvalid),
        .sdram_ctrl_error     (ctrl_error),
        .sdram_ctrl_read_data (ctrl_read_data)
    );

    // -----------------------------------------------------------------------
    // SDRAM timing controller
    // -----------------------------------------------------------------------

    sdram_core #(
        .FREQ_MHZ   (FREQ_MHZ),
        .DATA_WIDTH (DATA_WIDTH),
        .ADDR_WIDTH (ADDR_WIDTH),
        .CAS_LATENCY(2)
    ) u_sdram_core (
        .clk            (clk),
        .rst            (rst),
        .ctrl_wr        (ctrl_wr),
        .ctrl_rd        (ctrl_rd),
        .ctrl_addr      (ctrl_addr),
        .ctrl_write_data(ctrl_write_data),
        .ctrl_rdy       (ctrl_rdy),
        .ctrl_rvalid    (ctrl_rvalid),
        .ctrl_wvalid    (ctrl_wvalid),
        .ctrl_error     (ctrl_error),
        .ctrl_read_data (ctrl_read_data),
        .dev_cke        (dev_cke),
        .dev_cs         (dev_cs),
        .dev_cmd        (dev_cmd),
        .dev_dqm        (dev_dqm),
        .dev_addr       (dev_addr),
        .dev_ba         (dev_ba),
        .dev_write_data (dev_write_data),
        .dev_wr_en      (dev_wr_en),
        .dev_read_data  (dev_read_data)
    );

    // -----------------------------------------------------------------------
    // SDRAM physical I/O (IOB registers + ODDR clock forwarding)
    // -----------------------------------------------------------------------

    sdram_io #(
        .CLK_MHZ(FREQ_MHZ)
    ) u_sdram_io (
        .clk           (clk),
        .rst           (rst),
        .dev_cke       (dev_cke),
        .dev_cs        (dev_cs),
        .dev_cmd       (dev_cmd),
        .dev_dqm       (dev_dqm),
        .dev_addr      (dev_addr),
        .dev_ba        (dev_ba),
        .dev_write_data(dev_write_data),
        .dev_wr_en     (dev_wr_en),
        .dev_read_data (dev_read_data),
        .clk_sdram     (clk_sdram),
        .sdram_cke     (sdram_cke),
        .sdram_cs_n    (sdram_cs_n),
        .sdram_ras_n   (sdram_ras_n),
        .sdram_cas_n   (sdram_cas_n),
        .sdram_we_n    (sdram_we_n),
        .sdram_dqm     (sdram_dqm),
        .sdram_a       (sdram_a),
        .sdram_ba      (sdram_ba),
        .sdram_dq      (sdram_dq)
    );

    // -----------------------------------------------------------------------
    // portB tester (PL-side CPU port exerciser)
    // Writes then reads 4096 words using a decimated 50/24 MHz CPU clock.
    // SW[0] rising edge restarts the test.
    // -----------------------------------------------------------------------

    portb_tester #(
        .ADDR_WIDTH  (ADDR_WIDTH),
        .DATA_WIDTH  (DATA_WIDTH),
        .N_TEST_WORDS(4096)
    ) u_portb_tester (
        .clk             (clk_div),
        .rst             (rst),
        .start           (SW[0]),

        .portB_wr        (portB_wr),
        .portB_addr      (portB_addr),
        .portB_write_data(portB_write_data),
        .portB_read_data (portB_read_data),
        .portB_rdy       (portB_rdy),

        .test_done       (test_done),
        .test_pass       (test_pass),
        .error_count     (error_count)
    );

endmodule
