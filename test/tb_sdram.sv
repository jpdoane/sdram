`timescale 1ns/1ps

module tb_sdram;

    localparam CLK_PERIOD = 20ns;

    logic clk;
    logic rst;

    sdram_ctrl_if #(
        .DATA_WIDTH(32),
        .ADDR_WIDTH(24)
    ) ctrl_if();

    sdram_dev_if dev_if();

    sdram_core #(
        .FREQ_MHZ(50),
        .COL_WIDTH(9),
        .ROW_WIDTH(13),
        .BANK_WIDTH(2),
        .CAS_LATENCY(2)
    ) dut (
        .clk(clk),
        .rst(rst),
        .ctrl_if(ctrl_if),
        .dev_if(dev_if)
    );

    MT48LC8M16A2 mem (
        .clk(clk),
        .sdram_dev_if(dev_if)
    );


    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end


    task automatic wait_ready();
        begin
            while (!ctrl_if.rdy)
                @(posedge clk);
        end
    endtask


    task automatic write32(
        input logic [23:0] addr,
        input logic [31:0] data
    );
        begin
            wait_ready();

            @(posedge clk);
            ctrl_if.addr       <= addr;
            ctrl_if.write_data <= data;
            ctrl_if.wr         <= 4'b1111;
            ctrl_if.rd         <= 1'b0;

            @(posedge clk);
            ctrl_if.wr <= 0;

            wait(ctrl_if.wvalid);

            $display("[%0t] WRITE32 COMPLETE addr=%h data=%h",
                $time,
                addr,
                data);
        end
    endtask


    task automatic read32(
        input  logic [23:0] addr,
        output logic [31:0] data
    );
        begin
            wait_ready();

            @(posedge clk);
            ctrl_if.addr <= addr;
            ctrl_if.rd   <= 1'b1;
            ctrl_if.wr   <= 0;

            @(posedge clk);
            ctrl_if.rd <= 0;

            wait(ctrl_if.rvalid);
            data = ctrl_if.read_data;

            $display("[%0t] READ32 COMPLETE addr=%h data=%h",
                $time,
                addr,
                data);
        end
    endtask


    logic [31:0] rd_data;

    initial begin

        ctrl_if.rd         = 0;
        ctrl_if.wr         = 0;
        ctrl_if.addr       = 0;
        ctrl_if.write_data = 0;

        rst = 1;

        repeat (20)
            @(posedge clk);

        rst = 0;

        $display("[%0t] Waiting for SDRAM initialization", $time);

        repeat (6000)
            @(posedge clk);

        $display("[%0t] Starting transactions", $time);


        write32(24'h000100, 32'hDEADBEEF);
        read32 (24'h000100, rd_data);

        assert(rd_data == 32'hDEADBEEF)
        else begin
            $error("READBACK MISMATCH exp=DEADBEEF got=%h", rd_data);
            $fatal;
        end


        write32(24'h000104, 32'h12345678);
        read32 (24'h000104, rd_data);

        assert(rd_data == 32'h12345678)
        else begin
            $error("READBACK MISMATCH exp=12345678 got=%h", rd_data);
            $fatal;
        end


        write32(24'h010000, 32'hCAFEBABE);
        read32 (24'h010000, rd_data);

        assert(rd_data == 32'hCAFEBABE)
        else begin
            $error("READBACK MISMATCH exp=CAFEBABE got=%h", rd_data);
            $fatal;
        end


        $display("========================================");
        $display(" SDRAM TEST PASSED");
        $display("========================================");

        repeat (20)
            @(posedge clk);

        $finish;
    end

endmodule

