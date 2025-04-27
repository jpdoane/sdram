`timescale 1ns / 100ps

module sdram_core_tb;

parameter CLK_PERIOD=20.0;
parameter HALF_CLK_PERIOD=CLK_PERIOD/2;
parameter QTR_CLK_PERIOD=CLK_PERIOD/4;

parameter ADDR_DEPTH=32;
parameter DATA_DEPTH=32;

parameter DEBUG_SDRAM=1;

logic clk, rst;

sdram_part_if part_if(clk);
sdram_core_if core_if(clk);

// logic [DATA_DEPTH-1:0] data_rd;
// logic [DATA_DEPTH-1:0] data_wr;
// logic [ADDR_DEPTH-1:0] addr;
// logic rd;
// logic [3:0] wr;

initial
 begin
    $dumpfile("sdram_core_tb.vcd");
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

initial begin
    repeat(10) begin 
    core_if.write_data <= 0;
    core_if.addr <= 0;
    core_if.wr <= 0;
    core_if.rd <= 0;
    @(posedge clk);

    core_if.addr <= $urandom%((2**32)-1);
    @(posedge clk);

    // write
    core_if.write_data <= addr;
    core_if.wr <= '1;
    @(posedge clk);
    $display("at time %t: Writing 0x%0x to 0x%0x", $time, core_if.write_data, core_if.addr);
    while(~core_if.accept) @(posedge clk); // delay if controller is not ready
    core_if.wr <= 0;
    core_if.write_data <= 0;

    // read
    core_if.rd <= 1;
    @(posedge clk);
    while(~core_if.accept) @(posedge clk); // delay if controller is not ready 
    rd <= 0;
    while(~core_if.ack) @(posedge clk); // delay until result is valid 

    if(core_if.read_data == addr) $display("at time  %t: Read correct value 0x%0x from 0x%0x", $time, core_if.read_data, core_if.addr);
    else $display("at time %t: ERROR: Read incorrect value 0x%0x from 0x%0x", $time, core_if.read_data, core_if.addr);

    end
    $display("Sim finished at time %t", $time);
    $finish;
end

// logic [15:0] sdram_dq;
// logic [15:0] sdram_din;
// logic [15:0] sdram_dout;
// logic sdram_dout_en;
// logic [12:0] sdram_a;
// logic [1:0] sdram_bs;
// logic sdram_cs_n;
// logic sdram_ras_n;
// logic sdram_cas_n;
// logic sdram_we_n;
// logic sdram_udqm;
// logic sdram_ldqm;
// logic sdram_cke;
// logic [1:0] sdram_dqm;
// assign {sdram_udqm, sdram_ldqm} = sdram_dqm;

// logic accept, ack, err;


sdram_core_32bit
#(.SDRAM_READ_LATENCY(2))
u_sdram_core(
.clk_i                  (clk),
.rst_i                  (rst),
.core_if                (core_if.sub),
.part_if                (part_if.sub)
// .inport_len_i           (),
// .inport_addr_i          (addr),
// .inport_write_data_i    (data_wr),
// .inport_accept_o        (accept),
// .inport_ack_o           (ack),
// .inport_error_o         (err),
// .inport_read_data_o     (data_rd),

// .sdram_data_input_i     (sdram_din),
// .sdram_clk_o            (),
// .sdram_cke_o            (sdram_cke),
// .sdram_cs_o             (sdram_cs_n),
// .sdram_ras_o            (sdram_ras_n),
// .sdram_cas_o            (sdram_cas_n),
// .sdram_we_o             (sdram_we_n),
// .sdram_dqm_o            (sdram_dqm),
// .sdram_addr_o           (sdram_a),
// .sdram_ba_o             (sdram_bs),
// .sdram_data_output_o    (sdram_dout),
// .sdram_data_out_en_o    (sdram_dout_en)
);

wire sdram_clk;
assign #QTR_CLK_PERIOD sdram_clk = clk; // clock ram with 90deg lag

MT48LC8M16A2_dualbus #(.Debug(DEBUG_SDRAM)) u_sdram_model(
    .data_rd    (part_if.read_data),
    .data_wr    (part_if.write_data),
    .addr       (part_if.addr),
    .ba         (part_if.ba),
    .clk        (sdram_clk),
    .cke        (part_if.cke),
    .csb        (part_if.cs),
    .rasb       (part_if.ras),
    .casb       (part_if.cas),
    .web        (part_if.we),
    .dqm        (part_if.dqm)
    );

endmodule