`timescale 1ns / 1ps

module sdram_axil_tb();
    
    initial
     begin
        $dumpfile("sdram.vcd");
        $dumpvars(0,sdram_axil_tb);
        $dumpon;
        // #2600;
        // $finish;
     end


    reg clk;
    reg rst;

    localparam DEBUG_SDRAM=0;

    localparam real SDRAM_MHZ=50;
    localparam real CLK_PERIOD=1000/SDRAM_MHZ;
    localparam real HALF_CLK_PERIOD=CLK_PERIOD/2;
    localparam real QTR_CLK_PERIOD=CLK_PERIOD/4;
    
    initial begin
        clk = 0;
        rst = 1;
        repeat(10) @(posedge clk);
        rst = 0;
    end
    always begin
        #HALF_CLK_PERIOD;
        clk = ~clk;
    end

    sdram_ctrl_if sdram_ctrl_if(clk);
    wire #QTR_CLK_PERIOD sdram_clk = clk; 
    sdram_dev_if sdram_dev_if(sdram_clk);
    taxi_axil_if axi_if();

    axil_sdram u_axil_sdram
    (
        .clk    (clk),
        .rst    (rst),
        .s_axil_wr  (axi_if.wr_mst),
        .s_axil_rd  (axi_if.rd_mst),
        .sdram_ctrl (sdram_ctrl_if.sub)
    );

    sdram_core
    #(
        .SDRAM_MHZ      (SDRAM_MHZ),
        .STARTUP_US     (1)
    )
    u_sdram_controller(
        .clk      (clk      ),
        .rst      (rst      ),
        .sdram_ctrl_if  (sdram_ctrl_if.man),
        .sdram_dev_if  (sdram_dev_if.sub)
    );
    
    MT48LC8M16A2 #(
    .Debug(DEBUG_SDRAM)
    )
    u_sdram_model(sdram_dev_if.man);

    int rnd;
    initial
    begin
        // *** Initial value ***
        axi_if.wr_mst.awaddr = 0;
        axi_if.wr_mst.awvalid = 0;
        axi_if.wr_mst.wstrb = 0;
        axi_if.wr_mst.wdata = 0;
        axi_if.wr_mst.wvalid = 0;
        axi_if.wr_mst.bready = 0;
        axi_if.rd_mst.araddr = 0;
        axi_if.rd_mst.arvalid = 0;
        axi_if.rd_mst.rready = 0;

        while(rst) @(posedge clk);
        
        repeat(20) begin
            rnd = $urandom();
            axi_write(rnd, rnd);
            axi_read(rnd);
            if(axi_if.rdata == rnd) $display("at time  %t: Read correct value 0x%0x from 0x%0x", $time, axi_if.rdata, rnd);
            else $error("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x", $time, axi_if.rdata, rnd);
        end
        $finish;
    end

    task axi_write;
        input [31:0] awaddr;
        input [31:0] wdata; 
        begin
            axi_if.wr_mst.awaddr = awaddr;
            axi_if.wr_mst.wdata = wdata;
            axi_if.wr_mst.wstrb = 4'hf;
            axi_if.wr_mst.awvalid = 1;
            axi_if.wr_mst.wvalid = 1;
            while(~axi_if.wr_mst.awready) @(posedge clk);
            @(posedge clk);
            axi_if.wr_mst.awvalid = 0;
            axi_if.wr_mst.wvalid = 0;
            axi_if.wr_mst.awaddr = 0;
            axi_if.wr_mst.wstrb = 0;
            axi_if.wr_mst.wdata = 0;
            axi_if.wr_mst.bready = 1;
            while(~axi_if.wr_mst.bvalid) @(posedge clk);
        end
    endtask
    
    task axi_read;
        input [31:0] araddr;
        // output [31:0] rdata; 
        begin
            axi_if.rd_mst.araddr = araddr;
            axi_if.rd_mst.arvalid = 1;
            while(~axi_if.rd_mst.arready) @(posedge clk);
            @(posedge clk);
            axi_if.rd_mst.arvalid = 0;
            axi_if.rd_mst.araddr = 0;
            axi_if.rd_mst.rready = 1;
            while(~axi_if.rd_mst.rvalid) @(posedge clk);
            // rdata = axi_if.rd_mst.rdata;
        end
    endtask
    
endmodule