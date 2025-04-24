`timescale 1ns / 100ps

module sdram_burst_tb;

parameter CLK_PERIOD=23.288;
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
    $dumpfile("sdram_wave.vcd");
    $dumpvars(0,sdram_burst_tb);
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

logic [31:0] rand1,rand2,rand3;

initial begin
    data_wr = 0;
    addr = 0;
    wr = 0;
    rd = 0;

    rand1 = $urandom%((2**32)-1);
    rand2 = $urandom%((2**32)-1);
    rand3 = $urandom%((2**32)-1);
    write_word(rand1, rand1);
    write_word(rand2, rand2);
    write_word(rand3, rand3);
    validate_read(rand1, rand1);    
    validate_read(rand2, rand2);    
    validate_read(rand3, rand3);

    $display("Sim finished at time %t", $time);
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

sdram_burst
#(.SDRAM_READ_LATENCY(2))
u_sdram_burst(
.clk_i                  (clk),
.rst_i                  (rst),
.inport_wr_i            (wr),
.inport_rd_i            (rd),
.inport_len_i           (),
.inport_addr_i          (addr),
.inport_write_data_i    (data_wr),
.inport_accept_o        (accept),
.inport_ack_o           (ack),
.inport_error_o         (err),
.inport_read_data_o     (data_rd),

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

task write_word(input logic [ADDR_DEPTH-1:0] a, input logic [DATA_DEPTH-1:0] data);
    rd <= 0;
    wr <= '1;
    addr <= a;    
    data_wr <= data;
    @(posedge clk);
    while(~accept) @(posedge clk); // delay if controller is not ready
    wr <= 0;
    $display("at time %t: Writing 0x%0x to 0x%0x", $time, data, addr);
endtask

task read_word(input logic [ADDR_DEPTH-1:0] a);
    rd <= 1;
    wr <= 0;
    addr <= a;
    @(posedge clk);
    while(~accept) @(posedge clk); // delay if controller is not ready 
    rd <= 0;
    while(~ack) @(posedge clk); // delay until result is valid 
    // $display("at time %t: Read 0x%0x from 0x%0x", $time, data_rd, addr);
endtask

task validate_read(input logic [ADDR_DEPTH-1:0] addr, input logic [DATA_DEPTH-1:0] data_expected);
    read_word(addr);
    if(data_rd == data_expected) $display("at time  %t: Read correct value 0x%0x from 0x%0x", $time, data_rd, addr);
    else $display("at time %t: ERROR: Read incorrect value 0x%0x from 0x%0x", $time, data_rd, addr);
endtask

endmodule