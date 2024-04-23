`timescale 1ns / 100ps

module sdram_tb;

parameter CLK_PERIOD=23.288;
parameter HALF_CLK_PERIOD=CLK_PERIOD/2;
parameter QTR_CLK_PERIOD=CLK_PERIOD/4;
parameter ADDR_DEPTH=24;
parameter COL_DEPTH=9;

parameter DEBUG_SDRAM=0;

logic clk, rst;
logic [7:0] data_wr;
logic [ADDR_DEPTH-1:0] sdram_addr;
logic wr;
logic rd;
logic rdy;
logic val;
logic [7:0] data_rd;

initial
 begin
    $dumpfile("sdram_wave.vcd");
    $dumpvars(0,sdram_tb);
 end

initial begin
    clk = 0;
    rst = 1;
    repeat(10) @(posedge clk);
    rst = 0;
    repeat(400) @(posedge clk);
    $display("Sim finished at time %t", $time);
    $finish;
end

always begin
    #HALF_CLK_PERIOD;
    clk = ~clk;
end

logic [ADDR_DEPTH-1:0] test_addr1,test_addr2,test_addr3,test_addr4;
logic [7:0] test_data1,test_data2,test_data3,test_data4;

always @(posedge clk) begin
    if(rst) begin
        data_wr <= 0;
        sdram_addr <= 0;
        wr <= 0;
        rd <= 0;
    end else begin

        test_addr1 = $urandom%((2**ADDR_DEPTH)-1);
        test_data1 = $urandom%256;
        test_addr2 = $urandom%((2**ADDR_DEPTH)-1);
        test_data2 = $urandom%256;
        test_addr3 = $urandom%((2**ADDR_DEPTH)-1);
        test_data3 = $urandom%256;
        test_addr4 = $urandom%((2**ADDR_DEPTH)-1);
        test_data4 = $urandom%256;
        write_byte(test_addr1, test_data1);
        write_byte(test_addr2, test_data2);
        write_byte(test_addr3, test_data3);
        validate_read(test_addr1, test_data1);    
        validate_read(test_addr2, test_data2);    
        validate_read(test_addr3, test_data3);    
        //test independent read/write of each byte in the same word
        write_byte({test_addr4[ADDR_DEPTH-1:1],1'b0}, test_data4);
        write_byte({test_addr4[ADDR_DEPTH-1:1],1'b1}, ~test_data4); 
        validate_read({test_addr4[ADDR_DEPTH-1:1],1'b0}, test_data4);    
        validate_read({test_addr4[ADDR_DEPTH-1:1],1'b1}, ~test_data4);
    end
end


wire [15:0] sdram_dq;
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
    .sdram_a     (sdram_a     ),
    .sdram_bs    (sdram_bs    ),
    .sdram_cs_n  (sdram_cs_n  ),
    .sdram_ras_n (sdram_ras_n ),
    .sdram_cas_n (sdram_cas_n ),
    .sdram_we_n  (sdram_we_n  ),
    .sdram_udqm  (sdram_udqm  ),
    .sdram_ldqm  (sdram_ldqm  ),
    .sdram_cke   (sdram_cke   ),
    .sdram_din    (sdram_din    ),
    .sdram_dout    (sdram_dout    ),
    .sdram_dout_en    (sdram_dout_en    )
);



wire sdram_clk;
assign #QTR_CLK_PERIOD sdram_clk = clk; // clock ram with 90deg lag

// tristate io buffer
assign sdram_dq = sdram_dout_en ? sdram_dout : 16'bz;
assign sdram_din = sdram_dout_en ? 16'b0 : sdram_dq;

MT48LC8M16A2 #(.Debug(DEBUG_SDRAM)) u_sdram_model(
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

task write_byte(input logic [ADDR_DEPTH-1:0] addr, input logic [7:0] data);
    rd <= 0;
    wr <= 1;
    sdram_addr <= addr;    
    data_wr <= data;
    @(posedge clk);
    while(~rdy) @(posedge clk); // delay if controller is not ready
    wr <= 0;
    $display("at time %t: Writing 0x%0x to 0x%0x", $time, data, addr);
endtask

task read_byte(input logic [ADDR_DEPTH-1:0] addr);
    rd <= 1;
    wr <= 0;
    sdram_addr <= addr;
    @(posedge clk);
    while(~rdy) @(posedge clk); // delay if controller is not ready 
    rd <= 0;
    while(~val) @(posedge clk); // delay until result is valid 
    // $display("at time %t: Read 0x%0x from 0x%0x", $time, data_rd, addr);
endtask

task validate_read(input logic [ADDR_DEPTH-1:0] addr, input logic [7:0] data_expected);
    read_byte(addr);
    if(data_rd == data_expected) $display("at time  %t: Read correct value 0x%0x from 0x%0x", $time, data_rd, addr);
    else $display("at time %t: ERROR: Read incorrect value 0x%0x from 0x%0x", $time, data_rd, addr);
endtask

endmodule