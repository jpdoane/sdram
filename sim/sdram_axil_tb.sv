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

    localparam real FREQ_MHZ=50;
    localparam real CLK_PERIOD=1000/FREQ_MHZ;
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
    wire #QTR_CLK_PERIOD sdram_clk = clk; 

    sdram_ctrl_if sdram_ctrl_if();
    sdram_dev_if sdram_dev_if();
    taxi_axil_if axi_if();

    axil_sdram u_axil_sdram
    (
        .clk    (clk),
        .rst    (rst),
        .axi_if  (axi_if),
        .sdram_ctrl (sdram_ctrl_if)
    );

    sdram_core
    #(
        .FREQ_MHZ      (FREQ_MHZ),
        .STARTUP_US     (1)
    )
    u_sdram_controller(
        .clk      (clk      ),
        .rst      (rst      ),
        .ctrl_if  (sdram_ctrl_if),
        .dev_if   (sdram_dev_if)
    );
    
    MT48LC8M16A2 #(
    .Debug(DEBUG_SDRAM)
    )
    u_sdram_model(sdram_clk, sdram_dev_if.man);

    int rnd;
    initial
    begin
        // *** Initial value ***
        axi_if.man.awaddr = 0;
        axi_if.man.awvalid = 0;
        axi_if.man.wstrb = 0;
        axi_if.man.wdata = 0;
        axi_if.man.wvalid = 0;
        axi_if.man.bready = 0;
        axi_if.man.araddr = 0;
        axi_if.man.arvalid = 0;
        axi_if.man.rready = 0;

        while(rst) @(posedge clk);
        
        repeat(20) begin
            rnd = $urandom();


            // axi_write(rnd, rnd);
            axi_if.man.awaddr = rnd;
            axi_if.man.wdata = rnd;
            axi_if.man.wstrb = 4'hf;
            axi_if.man.awvalid = 1;
            axi_if.man.wvalid = 1;
            while(~axi_if.man.awready) @(posedge clk);
            @(posedge clk);
            axi_if.man.awvalid = 0;
            axi_if.man.wvalid = 0;
            axi_if.man.awaddr = 0;
            axi_if.man.wstrb = 0;
            axi_if.man.wdata = 0;
            axi_if.man.bready = 1;
            while(~axi_if.man.bvalid) @(posedge clk);

            // axi_read(rnd);
            axi_if.man.araddr = rnd;
            axi_if.man.arvalid = 1;
            while(~axi_if.man.arready) @(posedge clk);
            @(posedge clk);
            axi_if.man.arvalid = 0;
            axi_if.man.araddr = 0;
            axi_if.man.rready = 1;
            while(~axi_if.man.rvalid) @(posedge clk);

            if(axi_if.rdata == rnd) $display("at time  %t: Read correct value 0x%0x from 0x%0x", $time, axi_if.rdata, rnd);
            else $error("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x", $time, axi_if.rdata, rnd);
        end
        $finish;
    end


endmodule