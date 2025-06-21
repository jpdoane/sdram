`timescale 1ns / 100ps

module sdram_ref_tb;

    logic clk, rst;

    localparam int DATA_WIDTH    = 32;

    localparam real SDRAM_MHZ    = 50;
    localparam int ADDR_WIDTH    = 32;
    localparam int SDADDR_WIDTH  = 24;
    localparam int CAS_LATENCY   = 2;

    parameter DEBUG_SDRAM         = 1;

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
        // #110000;
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

    sdram_ctrl_if #(.ADDR_WIDTH(ADDR_WIDTH), .DATA_WIDTH(DATA_WIDTH)) ctrl_if();
    sdram_dev_if #(.ADDR_WIDTH(SDADDR_WIDTH)) dev_if();
    
    logic [ADDR_WIDTH-1:0] addr;
    logic [DATA_WIDTH-1:0] read_data, write_data;
    int n;
    always begin
        while(rst) @(posedge clk);
    
        repeat(10) begin
            for (int n = 0; n < 16; n++) begin
                addr = n << 2;
                write_data = 32'hab00cd00 + (n<<16) + n;

                // write(ctrl_if, clk, addr, write_data);
                ctrl_if.addr = addr;
                ctrl_if.write_data = write_data;
                ctrl_if.wr = '1;
                while(~ctrl_if.rdy) @(posedge clk);
                @(posedge clk);
                ctrl_if.wr = '0;
                ctrl_if.write_data = 0;
                while(~ctrl_if.wvalid) @(posedge clk);
                $display("at time %t Wrote 0x%0x to 0x%0x", $time, write_data, addr);
            end            
            for (int n = 0; n < 16; n++) begin
                addr = n << 2;
                write_data = 32'hab00cd00 + (n<<16) + n;

                ctrl_if.addr = addr;
                ctrl_if.rd = 1;
                while(~ctrl_if.rdy) @(posedge clk);
                @(posedge clk);
                ctrl_if.rd = 0;
                while(~ctrl_if.rvalid) @(posedge clk);
                read_data = ctrl_if.read_data;
                if(read_data == write_data) $display("at time  %t: Read correct value 0x%0x from 0x%0x", $time, read_data, addr);
                else $display("at time %t ERROR: Read incorrect value 0x%0x from 0x%0x, expected 0x%0x", $time, read_data, addr, write_data);
            end            

        end
        
        $finish;
    end

    sdram_ref
    #(
        // .SDRAM_MHZ      (SDRAM_MHZ),
        // .CAS_LATENCY    (CAS_LATENCY),
        // .tRC_NS         (tRC_NS),
        // .tRAS_NS        (tRAS_NS),
        // .tRCD_NS        (tRCD_NS),
        // .tRP_NS         (tRP_NS),
        // .tXSR_NS        (tXSR_NS),
        // .tREF_NS        (tREF_NS),
        // .DELAY_WR       (DELAY_WR),
        // .DELAY_RRD      (DELAY_RRD),
        // .DELAY_RSC      (DELAY_RSC),        
        // .STARTUP_US     (1)
    )
    u_sdram_controller(
        .clk      (clk      ),
        .rst      (rst      ),
        .ctrl_if  (ctrl_if.man),
        .dev_if   (dev_if.sub)
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
