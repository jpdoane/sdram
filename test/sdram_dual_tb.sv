`timescale 1ns / 100ps

// This is not working:
//    "Input combinational region did not converge."
// 
// class testor;

//     //virtual interface
//     virtual sdram_core_if vif;

//     //constructor
//     function new(virtual sdram_core_if vif);
//         //get the interface from test
//         this.vif = vif;
//     endfunction

//     task write_sdram(
//         input logic  [ 31:0]  addr,
//         input logic  [ 31:0]  data
//         );

//         vif.addr <= addr;
//         vif.write_data <= data;
//         vif.wr <= '1;
//         @(posedge vif.clk);
//         // hold inputs until accepted
//         while(~vif.accept) @(posedge vif.clk);
//         vif.wr <= 0;
//         vif.write_data <= 0;
//     endtask

//     task read_sdram(
//         input logic  [ 31:0]  addr
//         );

//         vif.addr <= addr;
//         vif.rd <= 1;
//         @(posedge vif.clk);
//         // hold inputs until accepted
//         while(~vif.accept) @(posedge vif.clk); 
//         vif.rd <= 0;
//         // hold until data is ready 
//         while(~vif.ack) @(posedge vif.clk); 
//     endtask

//     task rw_test();    
//         localparam num = 2;
//         logic [31:0] data[0:num-1];
//         logic [31:0] addr[0:num-1];
//         foreach(addr[i]) begin
//             addr[i] = $urandom;
//             data[i] = $urandom;
//             this.write_sdram(addr[i], data[i]);
//             $display("at time %t: Writing 0x%0x to 0x%0x", $time, vif.write_data, vif.addr);
//         end    
//         foreach(addr[i]) begin
//             this.read_sdram(addr[i]);
//             if(vif.read_data == data[i]) $display("at time  %t: Read correct value 0x%0x from 0x%0x on portB", $time, vif.read_data, addr[i]);
//             else $display("at time %t: ERROR: Read incorrect value 0x%0x from 0x%0x on portB, expected 0x%0x", $time, vif.read_data, addr[i], data[i]);
//         end
//     endtask
// endclass

module sdram_dual_tb2;

parameter CLK_PERIOD=20.0;
parameter HALF_CLK_PERIOD=CLK_PERIOD/2;
parameter QTR_CLK_PERIOD=CLK_PERIOD/4;

parameter ADDR_DEPTH=32;
parameter DATA_DEPTH=32;

parameter DEBUG_SDRAM=0;

logic clk, rst;
logic [DATA_DEPTH-1:0] data_rd;
logic [DATA_DEPTH-1:0] data_wr;
logic [ADDR_DEPTH-1:0] addr;
logic rd;
logic [3:0] wr;

initial
 begin
    $dumpfile("sdram_dual_tb2.vcd");
    $dumpvars(0,sdram_dual_tb2);
    $dumpoff;
    #118000; // startupo delay
    $dumpon;
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

sdram_core_if core_if();
sdram_core_if portA_if();
sdram_core_if portB_if();
sdram_part_if part_if();

sdram_arb
u_sdram_arb
(
    .clk(clk),
    .rst(rst),
    .core_if(core_if.man),
    .portA_if(portA_if.sub),
    .portB_if(portB_if.sub)
);

sdram_core_32bit
#(.SDRAM_READ_LATENCY(2))
u_sdram_core(
    .clk                    (clk),
    .rst                    (rst),
    .core_if                (core_if.man),
    .part_if                (part_if.sub)
);

MT48LC8M16A2 #(.Debug(DEBUG_SDRAM))
u_sdram_model(sdram_clk, part_if.man);

// testor testorA, testorB;
// initial begin
//     testorA = new(portA_if);
//     testorB = new(portB_if);
// end
// always begin
//     testorA.rw_test();
// end
// always begin
//     testorB.rw_test();
//     $finish;
// end

// r/w test for port A
// want to see port A get priority for intermittant access
logic [31:0] dataA[0:3];
logic [31:0] addrA[0:3];
localparam WAIT_CYCLES_A = 0;
int max_latency_a = 0;
int max_latency_b = 0;
int latency_a = 0;
int latency_b = 0;
int error_a = 0;
int error_b = 0;
always begin
    #110000 // startup delay
    while(rst) @(posedge clk);
    repeat(400) begin
        foreach(addrA[i]) begin
            addrA[i] = $urandom;
            dataA[i] = $urandom;
            latency_a <= 0;

            portA_if.addr <= addrA[i];
            portA_if.write_data <= dataA[i];
            portA_if.wr <= '1;
            @(posedge clk);
            // hold inputs until accepted
            while(~portA_if.accept) begin
                latency_a <= latency_a + 1;
                @(posedge clk);
            end
            if (latency_a > max_latency_a)
                max_latency_a <= latency_a;
            portA_if.wr <= 0;
            portA_if.write_data <= 0;
            $display("at time %t: Writing 0x%0x to 0x%0x on Port A", $time, portA_if.write_data, portA_if.addr);
            repeat(WAIT_CYCLES_A) @(posedge clk);
        end    
        foreach(addrA[i]) begin
            latency_a <= 0;

            portA_if.addr <= addrA[i];
            portA_if.rd <= 1;
            @(posedge clk);
            // hold inputs until accepted
            while(~portA_if.accept) begin
                latency_a <= latency_a + 1;
                @(posedge clk);
            end
            portA_if.rd <= 0;
            // hold until data is ready 
            while(~portA_if.ack) begin
                latency_a <= latency_a + 1;
                @(posedge clk);
            end
            if (latency_a > max_latency_a)
                max_latency_a <= latency_a;

            if(portA_if.read_data == dataA[i]) $display("at time  %t: Read correct value 0x%0x from 0x%0x on portA", $time, portA_if.read_data, addrA[i]);
            else begin
                $display("at time %t: ERROR: Read incorrect value 0x%0x from 0x%0x on portA, expected 0x%0x", $time, portA_if.read_data, addrA[i], dataA[i]);
                error_a <= error_a+1;
            end
            repeat(WAIT_CYCLES_A) @(posedge clk);
        end
    end

    $display("Sim finished at time %t", $time);
    $display("port A had %d errors with max latency of %d cycles", error_a, max_latency_a);
    $display("port B had %d errors with max latency of %d cycles", error_b, max_latency_b);
    $finish;
end

// r/w test for port B
// want to see port B make continous access, but preempted for port A
logic [31:0] dataB[0:3];
logic [31:0] addrB[0:3];
always begin
    #110000 // startup delay
    foreach(addrB[i]) begin
        addrB[i] = $urandom;
        dataB[i] = $urandom;
        latency_b <= 0;

        portB_if.addr <= addrB[i];
        portB_if.write_data <= dataB[i];
        portB_if.wr <= '1;
        @(posedge clk);
        // hold inputs until accepted
        while(~portB_if.accept) begin
            latency_b <= latency_b + 1;
            @(posedge clk);
        end
        if (latency_b > max_latency_b)
            max_latency_b <= latency_b;
        portB_if.wr <= 0;
        portB_if.write_data <= 0;
        $display("at time %t: Writing 0x%0x to 0x%0x on Port B", $time, portB_if.write_data, portB_if.addr);
    end    
    foreach(addrB[i]) begin
        latency_b <= 0;
        portB_if.addr <= addrB[i];
        portB_if.rd <= 1;
        @(posedge clk);
        // hold inputs until accepted
        while(~portB_if.accept) begin
            latency_b <= latency_b + 1;
            @(posedge clk);
        end
        portB_if.rd <= 0;
        // hold until data is ready 
        while(~portB_if.ack) begin
            latency_b <= latency_b + 1;
            @(posedge clk);
        end
        if (latency_b > max_latency_b)
            max_latency_b <= latency_b;

        if(portB_if.read_data == dataB[i]) $display("at time  %t: Read correct value 0x%0x from 0x%0x on portB", $time, portB_if.read_data, addrB[i]);
        else begin
            $display("at time %t: ERROR: Read incorrect value 0x%0x from 0x%0x on portB, expected 0x%0x", $time, portB_if.read_data, addrB[i], dataB[i]);
            error_b <= error_b+1;
        end
    end
end

endmodule


