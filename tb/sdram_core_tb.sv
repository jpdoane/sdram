`timescale 1ns / 100ps

module sdram_core_tb;

parameter CLK_PERIOD=20.0;
parameter HALF_CLK_PERIOD=CLK_PERIOD/2;
parameter QTR_CLK_PERIOD=CLK_PERIOD/4;

parameter ADDR_DEPTH=32;
parameter DATA_DEPTH=32;

parameter DEBUG_SDRAM=0;

logic clk, rst;

logic  [  3:0]  portA_wr;
logic           portA_rd;
logic  [  7:0]  portA_len;
logic  [ 31:0]  portA_addr;
logic  [ 31:0]  portA_write_data;
logic          portA_accept;         // command accepted 
logic          portA_ack;            // command completed
logic          portA_error;
logic [ 31:0]  portA_read_data;



initial
 begin
    $dumpfile("sdram_wave.vcd");
    $dumpvars(0,sdram_core_tb);
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

logic [ 31:0]    dataA[0:5];
logic [ 31:0]    addrA[0:5];
always begin
    foreach(addrA[i]) begin
        addrA[i] = $urandom;
        dataA[i] = $urandom;

        portA_write_data <= 0;
        portA_addr <= 0;
        portA_wr <= 0;
        portA_rd <= 0;
        @(posedge clk);
    
        // write
        portA_addr <= addrA[i];
        portA_write_data <= dataA[i];
        portA_wr <= '1;
        @(posedge clk);
        while(~portA_accept) @(posedge clk); // delay if controller is not ready
        portA_wr <= 0;
        portA_write_data <= 0;
        $display("at time %t: Writing 0x%0x to 0x%0x on portA", $time, portA_write_data, portA_addr);
    end    

    foreach(addrA[i]) begin
        // read
        portA_addr <= addrA[i];
        portA_rd <= 1;
        @(posedge clk);
        while(~portA_accept) @(posedge clk); // delay if controller is not ready 
        portA_rd <= 0;
        while(~portA_ack) @(posedge clk); // delay until result is valid 

        if(portA_read_data == dataA[i]) $display("at time  %t: Read correct value 0x%0x from 0x%0x on portA", $time, portA_read_data, dataA[i]);
        else $display("at time %t: ERROR: Read incorrect value 0x%0x from 0x%0x on portA, expected 0x%0x", $time, portA_read_data, addrA[i], dataA[i]);
    end
    $finish;
end

logic [15:0] sdram_dq;
logic [15:0] sdram_din;
logic [15:0] sdram_dout;
logic sdram_dout_en;
logic [12:0] sdram_a;
logic [1:0] sdram_bs;
logic sdram_cs_n;
logic sdram_ras_n;
logic sdram_cas_n;
logic sdram_we_n;
logic sdram_udqm;
logic sdram_ldqm;
logic sdram_cke;
logic [1:0] sdram_dqm;
assign {sdram_udqm, sdram_ldqm} = sdram_dqm;

logic accept, ack, err;

sdram_core_32bit
#(.SDRAM_READ_LATENCY(2))
u_sdram_core(
.clk_i                  (clk),
.rst_i                  (rst),

.inport_wr_i(portA_wr),
.inport_rd_i(portA_rd),
.inport_len_i(portA_len),
.inport_addr_i(portA_addr),
.inport_write_data_i(portA_write_data),
.inport_accept_o(portA_accept),
.inport_ack_o(portA_ack),
.inport_error_o(portA_error),
.inport_read_data_o(portA_read_data),

.sdram_data_input_i     (sdram_din),
.sdram_clk_o            (),
.sdram_cke_o            (sdram_cke),
.sdram_cs_o             (sdram_cs_n),
.sdram_ras_o            (sdram_ras_n),
.sdram_cas_o            (sdram_cas_n),
.sdram_we_o             (sdram_we_n),
.sdram_dqm_o            (sdram_dqm),
.sdram_addr_o           (sdram_a),
.sdram_ba_o             (sdram_bs),
.sdram_data_output_o    (sdram_dout),
.sdram_data_out_en_o    (sdram_dout_en)
);

wire sdram_clk;
assign #QTR_CLK_PERIOD sdram_clk = clk; // clock ram with 90deg lag

MT48LC8M16A2_dualbus #(.Debug(DEBUG_SDRAM)) u_sdram_model(
    .data_rd    (sdram_din),
    .data_wr    (sdram_dout),
    .addr  (sdram_a),
    .ba    (sdram_bs),
    .clk   (sdram_clk),
    .cke   (sdram_cke),
    .csb   (sdram_cs_n),
    .rasb  (sdram_ras_n),
    .casb  (sdram_cas_n),
    .web   (sdram_we_n),
    .dqm   ({sdram_udqm, sdram_ldqm})
    );

// task write_word(input logic [ADDR_DEPTH-1:0] a, input logic [DATA_DEPTH-1:0] data);
//     rd <= 0;
//     wr <= '1;
//     addr <= a;    
//     data_wr <= data;
//     @(posedge clk);
//     while(~accept) @(posedge clk); // delay if controller is not ready
//     wr <= 0;
//     $display("at time %t: Writing 0x%0x to 0x%0x", $time, data, addr);
// endtask

// task read_word(input logic [ADDR_DEPTH-1:0] a);
//     rd <= 1;
//     wr <= 0;
//     addr <= a;
//     @(posedge clk);
//     while(~accept) @(posedge clk); // delay if controller is not ready 
//     rd <= 0;
//     while(~ack) @(posedge clk); // delay until result is valid 
//     // $display("at time %t: Read 0x%0x from 0x%0x", $time, data_rd, addr);
// endtask

// task validate_read(input logic [ADDR_DEPTH-1:0] addr, input logic [DATA_DEPTH-1:0] data_expected);
//     read_word(addr);
//     if(data_rd == data_expected) $display("at time  %t: Read correct value 0x%0x from 0x%0x", $time, data_rd, addr);
//     else $display("at time %t: ERROR: Read incorrect value 0x%0x from 0x%0x", $time, data_rd, addr);
// endtask

endmodule
