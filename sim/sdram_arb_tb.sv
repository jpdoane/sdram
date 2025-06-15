`timescale 1ns / 100ps

module sdram_arb_tb;

    logic clk, rst;

    localparam int DATA_WIDTH    = 32;

    localparam real SDRAM_MHZ    = 50;
    localparam int ADDR_WIDTH    = 32;
    localparam int SDADDR_WIDTH  = 24;
    localparam int COL_WIDTH     = 9;
    localparam int CAS_LATENCY   = 2;

    parameter DEBUG_SDRAM         = 0;

    localparam real tRC_NS        = 60.0;   // min time in ns between row activations (same bank)
    localparam real tRAS_NS       = 42.0;   // min time in ns from row activation to precharge (same bank)
    localparam real tRCD_NS       = 15.0;   // min time in ns from row activation to read/write
    localparam real tRP_NS        = 15.0;   // min time in ns from precharge to refresh/activation (same bank)
    localparam real tXSR_NS       = 72.0;   // min time in ns from self-refresh exit to activation
    localparam real tREF_NS       = 64e6;   // max time in ns to perform all 8k refresh cycles
    localparam int DELAY_RRD     = 2;       // min clocks between row activations (different bank)
    localparam int DELAY_WR      = 2;       // min clocks write recovery time
    localparam int DELAY_RSC     = 2;       // min clocks for mode register reset

    localparam real CLK_PERIOD=1000/SDRAM_MHZ;
    localparam real HALF_CLK_PERIOD=CLK_PERIOD/2;
    localparam real QTR_CLK_PERIOD=CLK_PERIOD/4;
    
    initial
     begin
        $dumpfile("sdram.vcd");
        $dumpvars(0,sdram_core_tb);
        $dumpon;
        // #4500;
        // $finish;
     end
    
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
    // clock ram with 90deg lag
    wire #QTR_CLK_PERIOD sdram_clk = clk; 

    sdram_ctrl_if #(.ADDR_WIDTH(ADDR_WIDTH), .DATA_WIDTH(DATA_WIDTH)) portA_if();
    sdram_ctrl_if #(.ADDR_WIDTH(ADDR_WIDTH), .DATA_WIDTH(DATA_WIDTH)) portB_if();
    sdram_ctrl_if #(.ADDR_WIDTH(ADDR_WIDTH), .DATA_WIDTH(DATA_WIDTH)) ctrl_if();
    sdram_dev_if #(.ADDR_WIDTH(SDADDR_WIDTH), .COL_WIDTH(COL_WIDTH)) dev_if();
    
    // this breaks in Verilator due to 
    // https://github.com/verilator/verilator/issues/5116
    //
    // logic [ADDR_WIDTH-1:0] addrA;
    // logic [DATA_WIDTH-1:0] read_dataA, write_dataA;
    // always begin
    //     while(rst) @(posedge clk);
    
    //     repeat(10) begin
    //         addrA = $urandom();
    //         write_dataA = $urandom();
    //         write(portA_if, clk, addrA, write_dataA);
    //         $display("at time %t Wrote on PortA 0x%0x to 0x%0x", $time, write_dataA, addrA);
        
    //         read(portA_if, clk, addrA, read_dataA);
    //         if(read_dataA == write_dataA) $display("at time  %t: Read correct value on PortA 0x%0x from 0x%0x", $time, read_dataA, addrA);
    //         else $display("at time %t ERROR: Read incorrect value on PortA 0x%0x from 0x%0x, expected ", $time, read_dataA, addrA, write_dataA);
    //     end
    // end

    // logic [ADDR_WIDTH-1:0] addrB;
    // logic [DATA_WIDTH-1:0] read_dataB, write_dataB;
    // always begin
    //     while(rst) @(posedge clk);
    
    //     addrB = $urandom();
    //     write_dataB = $urandom();
    //     write(portB_if.sub, clk, addrB, write_dataB);
    //     $display("at time %t Wrote on PortB 0x%0x to 0x%0x", $time, write_dataB, addrB);
    
    //     read(portB_if.sub, clk, addrB, read_dataB);
    //     if(read_dataB == write_dataB) $display("at time  %t: Read correct value on PortB 0x%0x from 0x%0x", $time, read_dataB, addrB);
    //     else $display("at time %t ERROR: Read incorrect value on PortB 0x%0x from 0x%0x, expected ", $time, read_dataB, addrB, write_dataB);
    // end


    logic [ADDR_WIDTH-1:0] addrA;
    logic [DATA_WIDTH-1:0] read_dataA, write_dataA;
    always begin
        while(rst) @(posedge clk);
    
        repeat(10) begin
            addrA = $urandom();
            write_dataA = $urandom();
            portA_if.addr = addrA;
            portA_if.write_data = write_dataA;
            portA_if.wr = '1;
            while(~portA_if.rdy) @(posedge clk);
            @(posedge clk);
            portA_if.wr = '0;
            portA_if.write_data = 0;
            while(~portA_if.wvalid) @(posedge clk);
            $display("at time %t Wrote on PortA 0x%0x to 0x%0x", $time, write_dataA, addrA);
        
            repeat(20) @(posedge clk);

            portA_if.addr = addrA;
            portA_if.rd = 1;
            while(~portA_if.rdy) @(posedge clk);
            @(posedge clk);
            portA_if.rd = 0;
            while(~portA_if.rvalid) @(posedge clk);
            read_dataA = portA_if.read_data;
            if(read_dataA == write_dataA) $display("at time  %t: Read correct value on PortA 0x%0x from 0x%0x", $time, read_dataA, addrA);
            else $display("at time %t ERROR: Read incorrect value on PortA 0x%0x from 0x%0x, expected ", $time, read_dataA, addrA, write_dataA);

            repeat(20) @(posedge clk);
        end
        $finish;
    end

    logic [ADDR_WIDTH-1:0] addrB;
    logic [DATA_WIDTH-1:0] read_dataB, write_dataB;
    always begin
        while(rst) @(posedge clk);

        addrB = $urandom();
        write_dataB = $urandom();
        portB_if.addr = addrB;
        portB_if.write_data = write_dataB;
        portB_if.wr = '1;
        while(~portB_if.rdy) @(posedge clk);
        @(posedge clk);
        portB_if.wr = '0;
        portB_if.write_data = 0;
        while(~portB_if.wvalid) @(posedge clk);
        $display("\t\t\tat time %t Wrote on PortB 0x%0x to 0x%0x", $time, write_dataB, addrB);
    
        portB_if.addr = addrB;
        portB_if.rd = 1;
        while(~portB_if.rdy) @(posedge clk);
        @(posedge clk);
        portB_if.rd = 0;
        while(~portB_if.rvalid) @(posedge clk);
        read_dataB = portB_if.read_data;
        if(read_dataB == write_dataB) $display("\t\t\tat time  %t: Read correct value on PortB 0x%0x from 0x%0x", $time, read_dataB, addrB);
        else $display("\t\t\tat time %t ERROR: Read incorrect value on PortB 0x%0x from 0x%0x, expected ", $time, read_dataB, addrB, write_dataB);

    end


    sdram_arb
    u_sdram_arb
    (
        .clk(clk),
        .rst(rst),
        .ctrl_if(ctrl_if.man),
        .portA_if(portA_if.sub),
        .portB_if(portB_if.sub)
    );

    sdram_core
    #(
        .SDRAM_MHZ      (SDRAM_MHZ),
        .CAS_LATENCY    (CAS_LATENCY),
        .tRC_NS         (tRC_NS),
        .tRAS_NS        (tRAS_NS),
        .tRCD_NS        (tRCD_NS),
        .tRP_NS         (tRP_NS),
        .tXSR_NS        (tXSR_NS),
        .tREF_NS        (tREF_NS),
        .DELAY_WR       (DELAY_WR),
        .DELAY_RRD      (DELAY_RRD),
        .DELAY_RSC      (DELAY_RSC),        
        .STARTUP_US     (1)
    )
    u_sdram_controller(
        .clk      (clk      ),
        .rst      (rst      ),
        .ctrl_if  (ctrl_if.man),
        .dev_if  (dev_if.sub)
    );
    
    MT48LC8M16A2 #(
    .Debug(DEBUG_SDRAM),
    .tMRD   (DELAY_RSC*CLK_PERIOD),
    .tRAS   (tRAS_NS),
    .tRC    (tRC_NS),
    .tRCD   (tRCD_NS),
    .tRP    (tRP_NS),
    .tRRD   (DELAY_RRD*CLK_PERIOD)
    )
    u_sdram_model(sdram_clk, dev_if.man);

    // this breaks in Verilator due to 
    // https://github.com/verilator/verilator/issues/5116
    //
    // task write(
    //     virtual sdram_ctrl_if ctrl_if,
    //     ref logic  clk,
    //     input logic  [ ADDR_WIDTH-1:0]  a,
    //     input logic  [ DATA_WIDTH-1:0]  data
    //     );

    //     ctrl_if.addr = a;
    //     ctrl_if.write_data = data;
    //     ctrl_if.wr = '1;
    //     while(~ctrl_if.rdy) @(posedge clk);
    //     @(posedge clk);
    //     ctrl_if.wr = '0;
    //     ctrl_if.write_data = 0;
    //     while(~ctrl_if.wvalid) @(posedge clk);
    // endtask

    // task read(
    //     virtual sdram_ctrl_if ctrl_if,
    //     ref logic  clk,
    //     input logic  [ ADDR_WIDTH-1:0]  a,
    //     output logic  [ DATA_WIDTH-1:0]  data
    //     );

    //     ctrl_if.addr = a;
    //     ctrl_if.rd = 1;
    //     while(~ctrl_if.rdy) @(posedge clk);
    //     @(posedge clk);
    //     ctrl_if.rd = 0;
    //     while(~ctrl_if.rvalid) @(posedge clk);
    //     data = ctrl_if.read_data;
    // endtask

endmodule
