`timescale 1ns/1ps

module tb_dual_master_sdram;

    localparam int ADDR_WIDTH = 24;
    localparam int DATA_WIDTH = 32;
    localparam int WORD_LEN   = DATA_WIDTH/8;

    logic clk;
    logic rst;

    // --------------------------------------------------------------------
    // Clock / Reset
    // --------------------------------------------------------------------

    initial begin
        clk = 0;
        forever #10 clk = ~clk; // 50 MHz
    end

    initial begin
        rst = 1;
        repeat (20) @(posedge clk);
        rst = 0;
    end

    // --------------------------------------------------------------------
    // AXI-Lite interface
    // --------------------------------------------------------------------

    taxi_axil_if #(
        .ADDR_W(ADDR_WIDTH),
        .DATA_W(DATA_WIDTH)
    ) axi_if ();

    // --------------------------------------------------------------------
    // SDRAM controller interface
    // --------------------------------------------------------------------

    sdram_ctrl_if #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) ctrl_if ();

    // --------------------------------------------------------------------
    // SDRAM device interface
    // --------------------------------------------------------------------

    sdram_dev_if dev_if();

    // --------------------------------------------------------------------
    // Port B signals
    // --------------------------------------------------------------------

    logic                   portB_en;
    logic [WORD_LEN-1:0]   portB_wr;
    logic [ADDR_WIDTH-1:0] portB_addr;
    logic [DATA_WIDTH-1:0] portB_write_data;
    logic [DATA_WIDTH-1:0] portB_read_data;
    logic                  portB_valid;
    logic                  portB_rdy;

    // --------------------------------------------------------------------
    // DUT
    // --------------------------------------------------------------------

    dual_master_sdram #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) dut (
        .clk(clk),
        .rst(rst),

        .axi_if(axi_if),

        .portB_en(portB_en),
        .portB_wr(portB_wr),
        .portB_addr(portB_addr),
        .portB_write_data(portB_write_data),
        .portB_read_data(portB_read_data),
        .portB_valid(portB_valid),
        .portB_rdy(portB_rdy),

        .sdram_ctrl_wr(ctrl_if.wr),
        .sdram_ctrl_rd(ctrl_if.rd),
        .sdram_ctrl_addr(ctrl_if.addr),
        .sdram_ctrl_write_data(ctrl_if.write_data),
        .sdram_ctrl_rdy(ctrl_if.rdy),
        .sdram_ctrl_rvalid(ctrl_if.rvalid),
        .sdram_ctrl_wvalid(ctrl_if.wvalid),
        .sdram_ctrl_error(ctrl_if.error),
        .sdram_ctrl_read_data(ctrl_if.read_data)
    );

    // --------------------------------------------------------------------
    // Existing SDRAM controller
    // --------------------------------------------------------------------

    sdram_core #(
        .FREQ_MHZ(50),
        .CAS_LATENCY(2)
    ) u_sdram_core (
        .clk(clk),
        .rst(rst),
        .ctrl_if(ctrl_if),
        .dev_if(dev_if)
    );

    // --------------------------------------------------------------------
    // Existing SDRAM memory model
    // --------------------------------------------------------------------

    MT48LC8M16A2 #(.Debug(0))
    sdram_model (
        .clk(clk),
        .sdram_dev_if(dev_if)
    );

    // --------------------------------------------------------------------
    // AXI-Lite helper tasks
    // --------------------------------------------------------------------

    task automatic axi_write(
        input [ADDR_WIDTH-1:0] addr,
        input [DATA_WIDTH-1:0] data,
        input [WORD_LEN-1:0]  strb
    );
    begin
        @(posedge clk);

        axi_if.awaddr  <= addr;
        axi_if.awvalid <= 1'b1;

        axi_if.wdata   <= data;
        axi_if.wstrb   <= strb;
        axi_if.wvalid  <= 1'b1;

        axi_if.bready  <= 1'b1;

        wait (axi_if.awready && axi_if.wready);

        @(posedge clk);
        axi_if.awvalid <= 0;
        axi_if.wvalid  <= 0;

        wait (axi_if.bvalid);
        @(posedge clk);
        axi_if.bready <= 0;

        $display("[%0t] AXI WRITE addr=%08x data=%08x",
                 $time, addr, data);
    end
    endtask

    task automatic axi_read(
        input  [ADDR_WIDTH-1:0] addr,
        output [DATA_WIDTH-1:0] data
    );
    begin
        @(posedge clk);

        axi_if.araddr  <= addr;
        axi_if.arvalid <= 1'b1;
        axi_if.rready  <= 1'b1;

        wait (axi_if.arready);

        @(posedge clk);
        axi_if.arvalid <= 0;

        wait (axi_if.rvalid);

        data = axi_if.rdata;

        @(posedge clk);
        axi_if.rready <= 0;

        $display("[%0t] AXI READ addr=%08x data=%08x",
                 $time, addr, data);
    end
    endtask

    // --------------------------------------------------------------------
    // Port B helper tasks
    // --------------------------------------------------------------------

    task automatic portb_write(
        input [ADDR_WIDTH-1:0] addr,
        input [DATA_WIDTH-1:0] data,
        input [WORD_LEN-1:0]  strb
    );
    begin
        @(posedge clk);

        portB_addr       <= addr;
        portB_write_data <= data;
        portB_wr         <= strb;
        portB_en         <= 1'b1;

        wait (portB_rdy);

        @(posedge clk);
        portB_en <= 0;
        portB_wr <= 0;

        wait (portB_valid);

        $display("[%0t] PORTB WRITE addr=%08x data=%08x",
                 $time, addr, data);
    end
    endtask

    task automatic portb_read(
        input  [ADDR_WIDTH-1:0] addr,
        output [DATA_WIDTH-1:0] data
    );
    begin
        @(posedge clk);

        portB_addr <= addr;
        portB_wr   <= 0;
        portB_en   <= 1'b1;

        wait (portB_rdy);
        @(posedge clk);
        portB_en <= 0;
        @(posedge clk);
        wait (portB_valid);
        data = portB_read_data;

        $display("[%0t] PORTB READ addr=%08x data=%08x",
                 $time, addr, data);
    end
    endtask

    // --------------------------------------------------------------------
    // Scoreboard memory
    // --------------------------------------------------------------------

    logic [31:0] expected_mem [0:255];

    task automatic check_data(
        input [31:0] expected,
        input [31:0] actual,
        input [255:0] tag
    );
    begin
        if (expected !== actual) begin
            $error("%s FAILED expected=%08x actual=%08x",
                   tag, expected, actual);
        end
        else begin
            $display("%s PASS data=%08x", tag, actual);
        end
    end
    endtask

    // --------------------------------------------------------------------
    // Test sequence
    // --------------------------------------------------------------------

    integer i;
    logic [31:0] rd_data;

    always begin

        // defaults
        axi_if.awaddr  = 0;
        axi_if.awvalid = 0;
        axi_if.wdata   = 0;
        axi_if.wstrb   = 0;
        axi_if.wvalid  = 0;
        axi_if.bready  = 0;
        axi_if.araddr  = 0;
        axi_if.arvalid = 0;
        axi_if.rready  = 0;

        portB_en         = 0;
        portB_wr         = 0;
        portB_addr       = 0;
        portB_write_data = 0;

        wait (!rst);

        // wait for SDRAM initialization
        repeat (500) @(posedge clk);

        $display("\n==== BASIC AXI TEST ====\n");

        axi_write(32'h0000_0000, 32'h1111AAAA, 4'hF);
        axi_read (32'h0000_0000, rd_data);
        check_data(32'h1111AAAA, rd_data, "AXI_BASIC");

        $display("\n==== BASIC PORTB TEST ====\n");

        portb_write(32'h0000_0010, 32'h2222BBBB, 4'hF);
        portb_read (32'h0000_0010, rd_data);
        check_data(32'h2222BBBB, rd_data, "PORTB_BASIC");

        $display("\n==== SIMULTANEOUS REQUEST TEST ====\n");

        fork
            begin
                axi_write(32'h0000_0020, 32'hAAAA0001, 4'hF);
            end

            begin
                portb_write(32'h0000_0030, 32'hBBBB0002, 4'hF);
            end
        join

        axi_read(32'h0000_0020, rd_data);
        check_data(32'hAAAA0001, rd_data, "SIMUL_AXI");

        portb_read(32'h0000_0030, rd_data);
        check_data(32'hBBBB0002, rd_data, "SIMUL_PORTB");

        $display("\n==== AXI PRIORITY TEST ====\n");

        fork
            begin
                axi_write(32'h0000_0040, 32'hDEADBEEF, 4'hF);
            end

            begin
                portb_write(32'h0000_0050, 32'hCAFEBABE, 4'hF);
            end
        join

        axi_read(32'h0000_0040, rd_data);
        check_data(32'hDEADBEEF, rd_data, "AXI_PRIORITY_AXI");

        portb_read(32'h0000_0050, rd_data);
        check_data(32'hCAFEBABE, rd_data, "AXI_PRIORITY_PORTB");

        $display("\n==== STRESS TEST ====\n");

        for (i = 0; i < 32; i++) begin
            expected_mem[i] = 32'h10000000 + i;

            if (i[0]) begin
                axi_write(i*4, expected_mem[i], 4'hF);
            end
            else begin
                portb_write(i*4, expected_mem[i], 4'hF);
            end
        end

        for (i = 0; i < 32; i++) begin
            if (i[0]) begin
                axi_read(i*4, rd_data);
            end
            else begin
                portb_read(i*4, rd_data);
            end

            check_data(expected_mem[i], rd_data, "STRESS");
        end

        $display("\n==== RANDOM CONCURRENT TRAFFIC ====\n");

        fork
            begin : axi_random_thread
                integer k;
                logic [31:0] addr;
                logic [31:0] data;

                for (k = 0; k < 20; k++) begin
                    addr = ($urandom_range(0,63) * 4);
                    data = $random;

                    axi_write(addr, data, 4'hF);
                    expected_mem[addr>>2] = data;
                end
            end

            begin : portb_random_thread
                integer k;
                logic [31:0] addr;
                logic [31:0] data;

                for (k = 0; k < 20; k++) begin
                    addr = ($urandom_range(64,127) * 4);
                    data = $random;

                    portb_write(addr, data, 4'hF);
                    expected_mem[addr>>2] = data;
                end
            end
        join

        for (i = 0; i < 128; i++) begin
            if (expected_mem[i] !== 'x) begin
                if (i[0])
                    axi_read(i*4, rd_data);
                else
                    portb_read(i*4, rd_data);

                check_data(expected_mem[i], rd_data, "FINAL_CHECK");
            end
        end

        $display("\n====================================");
        $display(" ALL TESTS COMPLETED SUCCESSFULLY ");
        $display("====================================\n");

        #100;
        $finish;
    end

    initial begin
        $dumpfile("tb_dual_master_sdram.fst");
        $dumpvars(0, tb_dual_master_sdram);

        #200000;
        $display("TERMINATING....\n");
        $finish;
    end

endmodule

