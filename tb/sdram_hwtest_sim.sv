`timescale 1ns / 100ps

module sdram_hwtest_sim;

logic [3:0] led, btn, sw;

// sdram pins
wire [15:0] sdram_dq;
wire [12:0] sdram_a;
wire [1:0] sdram_bs;
wire sdram_clk;
wire sdram_cke;
wire sdram_we_n;
wire sdram_cas_n;
wire sdram_ras_n;
wire sdram_cs_n;
wire sdram_ldqm;
wire sdram_udq;

// main clock
logic clk125MHz, rst;
always begin
    #4; // half periofd of 125MHz clk is 4ns
    clk125MHz = ~clk125MHz;
end
initial begin
    clk125MHz = 0;
    rst = 1;
    repeat(10) @(posedge clk125MHz);
    rst = 0;
end

assign btn = {3'b0,rst}; //rst
assign sw = 4'b0;

sdram_hwtest
#(
.CLK_PERIOD(23.288),
.ADDR_DEPTH(24),
.COL_DEPTH(9),
.TEST_ADDR_BITS(10)   
) u_sdram_hwtest (
.clk125MHz  (clk125MHz),
.led  (led),
.sw  (sw),
.btn  (btn),
.sdram_dq  (sdram_dq),
.sdram_a  (sdram_a),
.sdram_bs  (sdram_bs),
.sdram_clk  (sdram_clk),
.sdram_cke  (sdram_cke),
.sdram_we_n  (sdram_we_n),
.sdram_cas_n  (sdram_cas_n),
.sdram_ras_n  (sdram_ras_n),
.sdram_cs_n  (sdram_cs_n),
.sdram_ldqm  (sdram_ldqm),
.sdram_udqm  (sdram_udqm)
);


MT48LC8M16A2 #(.Debug(0)) u_sdram_model(
    .dq    (sdram_dq),
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
