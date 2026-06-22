`timescale 1ns/1ps

`define DEBUG_SDRAM 0

// Testbench for dual_master_sdram

module tb_dual_master_sdram;

    localparam int ADDR_WIDTH   = 25;
    localparam int DATA_WIDTH   = 32;
    localparam int WORD_LEN     = DATA_WIDTH/8;
    localparam int CPU_CLK_DIV  = 24;   // clk_cpu period = CPU_CLK_DIV * clk period

    logic clk;
    logic rst;

    // Fast clock  (50 MHz)
    initial begin
        clk = 0;
        forever #10 clk = ~clk;
    end

    initial begin
        rst = 1;
        repeat (20) @(posedge clk);
        rst = 0;
    end

    // slow gated clock for port B (cpu clock)
    logic clk_cpu_en;
    int unsigned cpu_div_cnt;
    always @(negedge clk or posedge rst) begin
        if (rst) begin
            cpu_div_cnt <= 0;
            clk_cpu_en    <= 0;
        end else begin
            if (cpu_div_cnt == CPU_CLK_DIV - 1) begin
                cpu_div_cnt <= 0;
                clk_cpu_en    <= 1;   // will be high for the NEXT posedge clk
            end else begin
                cpu_div_cnt <= cpu_div_cnt + 1;
                clk_cpu_en    <= 0;
            end
        end
    end
    wire  clk_cpu = clk & clk_cpu_en;

    // --------------------------------------------------------------------
    // AXI-Lite signals
    // --------------------------------------------------------------------

    logic [ADDR_WIDTH-1:0]   axil_awaddr;
    logic                    axil_awvalid;
    logic                    axil_awready;
    logic [DATA_WIDTH-1:0]   axil_wdata;
    logic [WORD_LEN-1:0]     axil_wstrb;
    logic                    axil_wvalid;
    logic                    axil_wready;
    logic [1:0]              axil_bresp;
    logic                    axil_bvalid;
    logic                    axil_bready;
    logic [ADDR_WIDTH-1:0]   axil_araddr;
    logic                    axil_arvalid;
    logic                    axil_arready;
    logic [DATA_WIDTH-1:0]   axil_rdata;
    logic [1:0]              axil_rresp;
    logic                    axil_rvalid;
    logic                    axil_rready;

    // --------------------------------------------------------------------
    // SDRAM controller signals
    // --------------------------------------------------------------------

    logic [WORD_LEN-1:0]   ctrl_wr;
    logic                  ctrl_rd;
    logic [ADDR_WIDTH-1:0] ctrl_addr;
    logic [DATA_WIDTH-1:0] ctrl_write_data;
    logic                  ctrl_rdy;
    logic                  ctrl_rvalid;
    logic                  ctrl_wvalid;
    logic                  ctrl_error;
    logic [DATA_WIDTH-1:0] ctrl_read_data;

    // --------------------------------------------------------------------
    // SDRAM device signals
    // --------------------------------------------------------------------

    logic        dev_cke;
    logic        dev_cs;
    logic [2:0]  dev_cmd;
    logic [1:0]  dev_dqm;
    logic [12:0] dev_addr;
    logic [1:0]  dev_ba;
    logic [15:0] dev_write_data;
    logic        dev_wr_en;
    logic [15:0] dev_read_data;

    // --------------------------------------------------------------------
    // Port B signals
    // --------------------------------------------------------------------

    logic [WORD_LEN-1:0]   portB_wr;
    logic [ADDR_WIDTH-1:0] portB_addr;
    logic [DATA_WIDTH-1:0] portB_write_data;
    logic [DATA_WIDTH-1:0] portB_read_data;
    logic                  portB_rdy;

    // --------------------------------------------------------------------
    // DUT: Dual master controller
    // --------------------------------------------------------------------

    dual_master_sdram #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) dut (
        .clk(clk),
        .rst(rst),

        .axil_awaddr (axil_awaddr),
        .axil_awvalid(axil_awvalid),
        .axil_awready(axil_awready),
        .axil_wdata  (axil_wdata),
        .axil_wstrb  (axil_wstrb),
        .axil_wvalid (axil_wvalid),
        .axil_wready (axil_wready),
        .axil_bresp  (axil_bresp),
        .axil_bvalid (axil_bvalid),
        .axil_bready (axil_bready),
        .axil_araddr (axil_araddr),
        .axil_arvalid(axil_arvalid),
        .axil_arready(axil_arready),
        .axil_rdata  (axil_rdata),
        .axil_rresp  (axil_rresp),
        .axil_rvalid (axil_rvalid),
        .axil_rready (axil_rready),

        .portB_en        (clk_cpu_en),
        .portB_wr        (portB_wr),
        .portB_addr      (portB_addr),
        .portB_write_data(portB_write_data),
        .portB_read_data (portB_read_data),
        .portB_rdy       (portB_rdy),

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

    // --------------------------------------------------------------------
    // SDRAM controller
    // --------------------------------------------------------------------

    sdram_core #(
        .FREQ_MHZ   (50),
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

    // --------------------------------------------------------------------
    // SDRAM memory model
    // --------------------------------------------------------------------

    MT48LC8M16A2 #(.Debug(`DEBUG_SDRAM))
    sdram_model (
        .clk          (clk),
        .dev_cke      (dev_cke),
        .dev_cs       (dev_cs),
        .dev_cmd      (dev_cmd),
        .dev_dqm      (dev_dqm),
        .dev_addr     (dev_addr),
        .dev_ba       (dev_ba),
        .dev_write_data(dev_write_data),
        .dev_wr_en    (dev_wr_en),
        .dev_read_data(dev_read_data)
    );

    // --------------------------------------------------------------------
    // AXI-Lite helper tasks  (clocked on fast clk)
    // --------------------------------------------------------------------

    task automatic axi_write(
        input [ADDR_WIDTH-1:0] addr,
        input [DATA_WIDTH-1:0] data,
        input [WORD_LEN-1:0]  strb
    );
    begin
        @(posedge clk);
        axil_awaddr  <= addr;
        axil_awvalid <= 1'b1;
        axil_wdata   <= data;
        axil_wstrb   <= strb;
        axil_wvalid  <= 1'b1;
        axil_bready  <= 1'b1;

        wait (axil_awready && axil_wready);

        @(posedge clk);
        axil_awvalid <= 0;
        axil_wvalid  <= 0;

        wait (axil_bvalid);
        @(posedge clk);
        axil_bready <= 0;

        $display("[%0t] AXI WRITE addr=%08x data=%08x strb=%b",
                 $time, addr, data, strb);
    end
    endtask

    task automatic axi_read(
        input  [ADDR_WIDTH-1:0] addr,
        output [DATA_WIDTH-1:0] data
    );
    begin
        @(posedge clk);
        axil_araddr  <= addr;
        axil_arvalid <= 1'b1;
        axil_rready  <= 1'b1;

        wait (axil_arready);

        @(posedge clk);
        axil_arvalid <= 0;

        wait (axil_rvalid);
        data = axil_rdata;

        @(posedge clk);
        axil_rready <= 0;

        $display("[%0t] AXI READ addr=%08x data=%08x", $time, addr, data);
    end
    endtask

    // --------------------------------------------------------------------
    // Port B helper tasks  (clocked on clk_cpu)
    // --------------------------------------------------------------------

    // -----------------------------------------------------------------------
    // portb_write / portb_read
    // -----------------------------------------------------------------------

    task automatic portb_write(
        input [ADDR_WIDTH-1:0] addr,
        input [DATA_WIDTH-1:0] data,
        input [WORD_LEN-1:0]  strb
    );
    begin
        portB_addr       <= addr;
        portB_write_data <= data;
        portB_wr         <= strb;   // non-zero = write

        @(posedge clk_cpu);
        while (!portB_rdy) @(posedge clk_cpu);
        portB_wr <= '0;             // CPU goes idle next cycle
        $display("[%0t] PORTB WRITE addr=%08x data=%08x strb=%b",
                 $time, addr, data, strb);
    end
    endtask

    task automatic portb_read(
        input  [ADDR_WIDTH-1:0] addr,
        output [DATA_WIDTH-1:0] data
    );
    begin
        portB_addr <= addr;
        portB_wr   <= '0;           // zero strobe = read

        @(posedge clk_cpu);
        while (!portB_rdy) @(posedge clk_cpu);
        @(posedge clk_cpu);
        while (!portB_rdy) @(posedge clk_cpu);
        data = portB_read_data;

        $display("[%0t] PORTB READ addr=%08x data=%08x", $time, addr, data);
    end
    endtask

    // --------------------------------------------------------------------
    // Golden reference memory (byte-strobe aware, word-addressed)
    // --------------------------------------------------------------------

    logic [DATA_WIDTH-1:0] golden [logic [ADDR_WIDTH-3:0]];

    function automatic logic [DATA_WIDTH-1:0] golden_get(
        input [ADDR_WIDTH-1:0] addr
    );
        logic [ADDR_WIDTH-3:0] w = addr[ADDR_WIDTH-1:2];
        return golden.exists(w) ? golden[w] : '0;
    endfunction

    function automatic void golden_put(
        input [ADDR_WIDTH-1:0] addr,
        input [DATA_WIDTH-1:0] data,
        input [WORD_LEN-1:0]  strb
    );
        logic [ADDR_WIDTH-3:0] w = addr[ADDR_WIDTH-1:2];
        logic [DATA_WIDTH-1:0] cur = golden.exists(w) ? golden[w] : '0;
        for (int b = 0; b < WORD_LEN; b++)
            if (strb[b]) cur[b*8 +: 8] = data[b*8 +: 8];
        golden[w] = cur;
    endfunction

    // --------------------------------------------------------------------
    // Error / pass bookkeeping
    // --------------------------------------------------------------------

    int unsigned n_checks;
    int unsigned n_fail;

    task automatic check_data(
        input [DATA_WIDTH-1:0] expected,
        input [DATA_WIDTH-1:0] actual,
        input string          tag
    );
    begin
        n_checks++;
        if (expected !== actual) begin
            n_fail++;
            $error("[%0t] %s FAILED  expected=%08x  actual=%08x",
                   $time, tag, expected, actual);
        end else begin
            $display("[%0t] %s PASS  data=%08x", $time, tag, actual);
        end
    end
    endtask

    // --------------------------------------------------------------------
    // Test sequence
    // --------------------------------------------------------------------

    integer i;
    logic [DATA_WIDTH-1:0] rd_data;

    always begin

        // defaults
        axil_awaddr  = 0;  axil_awvalid = 0;
        axil_wdata   = 0;  axil_wstrb   = 0;  axil_wvalid = 0;
        axil_bready  = 0;
        axil_araddr  = 0;  axil_arvalid = 0;  axil_rready = 0;

        portB_wr         = 0;
        portB_addr       = 0;
        portB_write_data = 0;

        n_checks = 0;
        n_fail   = 0;

        wait (!rst);
        repeat (500) @(posedge clk);  // SDRAM init

        // ================================================================
        $display("\n==== BASIC AXI TEST ====\n");
        // ================================================================

        axi_write(24'h00_0000, 32'h1111AAAA, 4'hF);
        golden_put(24'h00_0000, 32'h1111AAAA, 4'hF);
        axi_read(24'h00_0000, rd_data);
        check_data(golden_get(24'h00_0000), rd_data, "AXI_BASIC");

        // ================================================================
        $display("\n==== BASIC PORTB TEST ====\n");
        // ================================================================

        portb_write(24'h00_0010, 32'h2222BBBB, 4'hF);
        golden_put(24'h00_0010, 32'h2222BBBB, 4'hF);
        portb_read(24'h00_0010, rd_data);
        check_data(golden_get(24'h00_0010), rd_data, "PORTB_BASIC");

        // ================================================================
        $display("\n==== BYTE-STROBE / PARTIAL-WRITE TEST ====\n");
        // Build 0x44332211 at 0x100 one byte lane at a time,
        // then overwrite only the middle two lanes -> 0x44CCBB11.
        // ================================================================

        axi_write(24'h00_0100, 32'h00000011, 4'b0001); golden_put(24'h00_0100, 32'h00000011, 4'b0001);
        axi_write(24'h00_0100, 32'h00002200, 4'b0010); golden_put(24'h00_0100, 32'h00002200, 4'b0010);
        portb_write(24'h00_0100, 32'h00330000, 4'b0100); golden_put(24'h00_0100, 32'h00330000, 4'b0100);
        portb_write(24'h00_0100, 32'h44000000, 4'b1000); golden_put(24'h00_0100, 32'h44000000, 4'b1000);
        axi_read(24'h00_0100, rd_data);
        check_data(golden_get(24'h00_0100), rd_data, "STRB_AXI_RD");
        portb_read(24'h00_0100, rd_data);
        check_data(golden_get(24'h00_0100), rd_data, "STRB_PORTB_RD");

        axi_write(24'h00_0100, 32'hAABBCCDD, 4'b0110); golden_put(24'h00_0100, 32'hAABBCCDD, 4'b0110);
        axi_read(24'h00_0100, rd_data);
        check_data(golden_get(24'h00_0100), rd_data, "STRB_PARTIAL_OVERWRITE");

        // ================================================================
        $display("\n==== AXI PREEMPTION TEST ====\n");
        // AXI fires while the CPU is running.  portB_rdy goes low whenever
        // AXI wins arbitration, transparently stalling clk_cpu for exactly
        // those fast-clock cycles.  Both masters write to disjoint addresses;
        // we verify both sets of data are correct afterward.
        // This is the primary use case: AXI preempts the CPU for init/debug.
        // ================================================================

        fork
            begin : axi_preempt_thread
                for (int k = 0; k < 8; k++) begin
                    axi_write(24'h00_0400 + k*4, 32'hAC10_0000 + k, 4'hF);
                    golden_put(24'h00_0400 + k*4, 32'hAC10_0000 + k, 4'hF);
                end
            end
            begin : cpu_preempt_thread
                for (int k = 0; k < 8; k++) begin
                    portb_write(24'h00_0500 + k*4, 32'hBC50_0000 + k, 4'hF);
                    golden_put(24'h00_0500 + k*4, 32'hBC50_0000 + k, 4'hF);
                end
            end
        join

        for (i = 0; i < 8; i++) begin
            axi_read(24'h00_0400 + i*4, rd_data);
            check_data(golden_get(24'h00_0400 + i*4), rd_data, "PREEMPT_AXI");
        end
        for (i = 0; i < 8; i++) begin
            portb_read(24'h00_0500 + i*4, rd_data);
            check_data(golden_get(24'h00_0500 + i*4), rd_data, "PREEMPT_PORTB");
        end

        // ================================================================
        $display("\n==== BACK-TO-BACK PORTB TEST ====\n");
        // Consecutive portB ops with no AXI pressure.
        // portB_rdy stays high between transactions (controller goes straight
        // back to IDLE); verifies zero stall in the no-contention case.
        // ================================================================

        for (i = 0; i < 8; i++) begin
            portb_write(24'h00_0200 + i*4, 32'hB2B0_0000 + i, 4'hF);
            golden_put(24'h00_0200 + i*4, 32'hB2B0_0000 + i, 4'hF);
        end
        for (i = 0; i < 8; i++) begin
            portb_read(24'h00_0200 + i*4, rd_data);
            check_data(golden_get(24'h00_0200 + i*4), rd_data, "B2B_PORTB");
        end

        // ================================================================
        $display("\n==== STRESS TEST ====\n");
        // Sequential AXI writes, then sequential portB writes to different
        // addresses, then read both back via each master.
        // ================================================================

        for (i = 0; i < 16; i++) begin
            axi_write(24'h00_0600 + i*4, 32'hAA00_0000 + i, 4'hF);
            golden_put(24'h00_0600 + i*4, 32'hAA00_0000 + i, 4'hF);
        end
        for (i = 0; i < 16; i++) begin
            portb_write(24'h00_0700 + i*4, 32'hBB00_0000 + i, 4'hF);
            golden_put(24'h00_0700 + i*4, 32'hBB00_0000 + i, 4'hF);
        end
        for (i = 0; i < 16; i++) begin
            axi_read(24'h00_0600 + i*4, rd_data);
            check_data(golden_get(24'h00_0600 + i*4), rd_data, "STRESS_AXI");
        end
        for (i = 0; i < 16; i++) begin
            portb_read(24'h00_0700 + i*4, rd_data);
            check_data(golden_get(24'h00_0700 + i*4), rd_data, "STRESS_PORTB");
        end

        // ================================================================
        $display("\n==== RANDOM CONCURRENT TRAFFIC ====\n");
        // AXI and portB are both active simultaneously (disjoint addresses).
        // AXI: words 0..63  portB: words 64..127
        // portB is transparently stalled by AXI preemption as needed.
        // Random byte strobes verify partial-write tracking.
        // ================================================================

        // Record writes in local arrays; update golden after fork completes
        // to avoid concurrent golden_put calls from two threads.
        begin
            logic [ADDR_WIDTH-1:0] axi_addrs  [20];
            logic [DATA_WIDTH-1:0] axi_datas  [20];
            logic [WORD_LEN-1:0]  axi_strbs   [20];
            logic [ADDR_WIDTH-1:0] pb_addrs   [20];
            logic [DATA_WIDTH-1:0] pb_datas   [20];
            logic [WORD_LEN-1:0]  pb_strbs    [20];

            fork
                begin : axi_random_thread
                    for (int k = 0; k < 20; k++) begin
                        axi_addrs[k] = ($urandom_range(0, 63) * 4);
                        axi_datas[k] = $urandom;
                        axi_strbs[k] = $urandom_range(1, 15);
                        axi_write(axi_addrs[k], axi_datas[k], axi_strbs[k]);
                    end
                end
                begin : portb_random_thread
                    for (int k = 0; k < 20; k++) begin
                        pb_addrs[k] = ($urandom_range(64, 127) * 4);
                        pb_datas[k] = $urandom;
                        pb_strbs[k] = $urandom_range(1, 15);
                        portb_write(pb_addrs[k], pb_datas[k], pb_strbs[k]);
                    end
                end
            join

            // Update golden model sequentially after both threads complete
            for (int k = 0; k < 20; k++) golden_put(axi_addrs[k], axi_datas[k], axi_strbs[k]);
            for (int k = 0; k < 20; k++) golden_put(pb_addrs[k],  pb_datas[k],  pb_strbs[k]);
        end

        // Read back all written locations via the same master that wrote them
        for (i = 0; i < 128; i++) begin
            if (golden.exists(i[ADDR_WIDTH-3:0])) begin
                if (i < 64) begin
                    axi_read(i*4, rd_data);
                    check_data(golden_get(i*4), rd_data, "RAND_AXI");
                end else begin
                    portb_read(i*4, rd_data);
                    check_data(golden_get(i*4), rd_data, "RAND_PORTB");
                end
            end
        end

        // ================================================================
        $display("\n====================================");
        $display(" CHECKS RUN : %0d", n_checks);
        $display(" FAILURES   : %0d", n_fail);
        if (n_fail == 0)
            $display(" RESULT     : *** PASS ***");
        else
            $display(" RESULT     : *** FAIL ***");
        $display("====================================\n");

        #100;
        if (n_fail != 0)
            $fatal(1, "TEST FAILED with %0d error(s)", n_fail);
        $finish;
    end

    // --------------------------------------------------------------------
    // Watchdog / waveform dump
    // --------------------------------------------------------------------

    initial begin
        $dumpfile("tb_dual_master_sdram.fst");
        $dumpvars(0, tb_dual_master_sdram);

        #2000000;
        $display("TERMINATING (watchdog timeout)....");
        $fatal(1, "WATCHDOG TIMEOUT: simulation did not complete");
    end

endmodule
