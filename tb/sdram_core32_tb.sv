`timescale 1ns / 100ps

module sdram_core_tb;

parameter DEBUG_SDRAM=0;

parameter CLK_PERIOD=20.0;
parameter HALF_CLK_PERIOD=CLK_PERIOD/2;
parameter QTR_CLK_PERIOD=CLK_PERIOD/4;
parameter ADDR_DEPTH=32;
parameter DATA_DEPTH=32;

logic clk, rst;

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

// clock ram with 90deg lag
wire #QTR_CLK_PERIOD sdram_clk = clk; 

always begin
    repeat(10) begin 
    core_if.write_data <= 0;
    core_if.addr <= 0;
    core_if.wr <= 0;
    core_if.rd <= 0;
    @(posedge clk);

    core_if.addr <= $urandom;
    @(posedge clk);

    // write
    core_if.write_data <= core_if.addr;
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
    core_if.rd <= 0;
    while(~core_if.ack) @(posedge clk); // delay until result is valid 

    if(core_if.read_data == core_if.addr) $display("at time  %t: Read correct value 0x%0x from 0x%0x", $time, core_if.read_data, core_if.addr);
    else $display("at time %t: ERROR: Read incorrect value 0x%0x from 0x%0x", $time, core_if.read_data, core_if.addr);

    end
    $finish;
end

sdram_part_if part_if(sdram_clk);

sdram_controller_w9825g6kh
#(
    .SD_CLK_PERIOD_NS (23.288 ),
    .CAS_LATENCY      (2      ),
    .SIM_STARTUP      (1      )
)
u_sdram_controller(
    .clk      (clk      ),
    .rst      (rst      ),
    .data_wr  (data_wr  ),
    .addr_in  (sdram_addr  ),
    .wr       (wr       ),
    .rd       (rd       ),
    .rdy      (rdy      ),
    .val      (val      ),
    .data_rd (data_rd ),
    .sd_a     (sdram_a     ),
    .sd_bs    (sdram_bs    ),
    .sd_cs_n  (sdram_cs_n  ),
    .sd_ras_n (sdram_ras_n ),
    .sd_cas_n (sdram_cas_n ),
    .sd_we_n  (sdram_we_n  ),
    .sd_udqm  (sdram_udqm  ),
    .sd_ldqm  (sdram_ldqm  ),
    .sd_cke   (sdram_cke   ),
    .sd_din    (sdram_din    ),
    .sd_dout    (sdram_dout    ),
    .sd_dout_en    (sdram_dout_en    )
);

sdram_core_32bit
#(.SDRAM_READ_LATENCY(2))
u_sdram_core(
    .clk                    (clk),
    .rst                    (rst),
    .core_if                (core_if.sub),
    .part_if                (part_if.sub)
);

MT48LC8M16A2 #(.Debug(DEBUG_SDRAM))
u_sdram_model(part_if.man);

endmodule
