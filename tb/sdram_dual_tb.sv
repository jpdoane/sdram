`timescale 1ns / 100ps

module sdram_dual_tb;

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
    $dumpfile("sim/sdram_dual_tb.vcd");
    $dumpvars(0,sdram_dual_tb);
    $dumpoff;
    #118000; // startupo delay
    $dumpon;
    #10000; // startupo delay
    $display("Sim finished at time %t", $time);
    $finish;
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

logic  [  3:0]  portA_wr;
logic           portA_rd;
logic  [  7:0]  portA_len;
logic  [ 31:0]  portA_addr;
logic  [ 31:0]  portA_write_data;
logic          portA_accept;         // command accepted 
logic          portA_ack;            // command completed
logic          portA_error;
logic [ 31:0]  portA_read_data;

logic  [  3:0]  portB_wr;
logic           portB_rd;
logic  [  7:0]  portB_len;
logic  [ 31:0]  portB_addr;
logic  [ 31:0]  portB_write_data;
logic          portB_accept;
logic          portB_ack;
logic          portB_error;
logic [ 31:0]  portB_read_data;

logic  [  3:0]  core_wr;
logic           core_rd;
logic  [  7:0]  core_len;
logic  [ 31:0]  core_addr;
logic  [ 31:0]  core_write_data;
logic            core_accept;
logic            core_ack;
logic            core_err;
logic [ 31:0]    core_read_data;


logic [ 31:0]    dataA[0:5];
logic [ 31:0]    addrA[0:5];
initial begin
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

        #(CLK_PERIOD*20);
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

        #(CLK_PERIOD*20);
    end
    $finish;
end

logic [ 31:0]    dataB[0:2];
logic [ 31:0]    addrB[0:2];    
initial forever begin
    foreach(addrB[ii]) begin
        dataB[ii] = $urandom;
        addrB[ii] = $urandom;

        // write
        portB_addr <= addrB[ii];
        portB_write_data <= dataB[ii];
        portB_rd <= 0;
        portB_wr <= '1;
        @(posedge clk);
        $display("at time %t: Writing 0x%0x to 0x%0x on portB", $time, dataB[ii], addrB[ii]);
        while(~portB_accept) @(posedge clk); // delay if controller is not ready
        portB_wr <= 0;
        portB_write_data <= 0;
    end    
    foreach(addrB[ii]) begin
        // read
        portB_addr <= addrB[ii];
        portB_rd <= 1;
        @(posedge clk);
        while(~portB_accept) @(posedge clk); // delay if controller is not ready 
        portB_rd <= 0;
        while(~portB_ack) @(posedge clk); // delay until result is valid 

        if(portB_read_data == dataB[ii]) $display("at time  %t: Read correct value 0x%0x from 0x%0x on portB", $time, portB_read_data, addrB[ii]);
        else $display("at time %t: ERROR: Read incorrect value 0x%0x from 0x%0x on portB, expected 0x%0x", $time, portB_read_data, addrB[ii], dataB[ii]);
    end
end

sdram_arb
u_sdram_arb
(
    .clk_i(clk),
    .rst_i(rst),
    .portA_wr_i(portA_wr),
    .portA_rd_i(portA_rd),
    .portA_len_i(portA_len),
    .portA_addr_i(portA_addr),
    .portA_write_data_i(portA_write_data),
    .portA_accept_o(portA_accept),
    .portA_ack_o(portA_ack),
    .portA_error_o(portA_error),
    .portA_read_data_o(portA_read_data),
    .portB_wr_i(portB_wr),
    .portB_rd_i(portB_rd),
    .portB_len_i(portB_len),
    .portB_addr_i(portB_addr),
    .portB_write_data_i(portB_write_data),
    .portB_accept_o(portB_accept),
    .portB_ack_o(portB_ack),
    .portB_error_o(portB_error),
    .portB_read_data_o(portB_read_data),
    .core_wr_o( core_wr),
    .core_rd_o( core_rd),
    .core_len_o( core_len),
    .core_addr_o( core_addr),
    .core_write_data_o( core_write_data),
    .core_accept_i( core_accept),
    .core_ack_i( core_ack),
    .core_error_i( core_err),
    .core_read_data_i( core_read_data)
);
    

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

sdram_core_32bit
#(.SDRAM_READ_LATENCY(2))
u_sdram_core(
.clk_i                  (clk),
.rst_i                  (rst),
.inport_wr_i            (core_wr),
.inport_rd_i            (core_rd),
.inport_len_i           (core_len),
.inport_addr_i          (core_addr),
.inport_write_data_i    (core_write_data),
.inport_accept_o        (core_accept),
.inport_ack_o           (core_ack),
.inport_error_o         (core_err),
.inport_read_data_o     (core_read_data),

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

endmodule