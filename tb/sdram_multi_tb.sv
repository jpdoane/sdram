`timescale 1ns/100ps

module sdram_multi_tb;

parameter CLK_PERIOD=23.288;
parameter HALF_CLK_PERIOD=CLK_PERIOD/2;
parameter QTR_CLK_PERIOD=CLK_PERIOD/4;
parameter ADDR_DEPTH=23;
parameter COL_DEPTH=9;

parameter DEBUG_SDRAM=1;

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
    $dumpfile("sdram_multi_tb.vcd");
    $dumpvars(0,sdram_multi_tb);
 end

logic [4:0] tb_cycle;
initial begin
    clk = 0;
    // ppu_clk = 0;
    // cpu_clk = 0;
    rst = 1;
    tb_cycle = 0;
    repeat(10) @(posedge clk);
    rst = 0;
    repeat(200) @(posedge clk);
    $display("Sim finished at time %t", $time);
    $finish;
end

always begin
    #HALF_CLK_PERIOD;
    clk = ~clk;
end


always @(posedge clk) begin
    if(rst) begin
        tb_cycle <= 0;
    end else begin
        // $display("tb_cycle %d", tb_cycle);
        tb_cycle <= tb_cycle == 5'd23 ? 0 : tb_cycle + 1;
        if(sync) tb_cycle[2:0] <= 3'h1;
    end
end 

logic cpu_clk_gate, ppu_clk_gate;
logic ppu_clk,cpu_clk;
always @(*) begin
    // latch gates on ~clk of final cycle
    // (avoid glitching)
  if(~clk) begin
    ppu_clk_gate = tb_cycle[2:0] == 3'h7;
    cpu_clk_gate = tb_cycle == 5'd23;
  end
  ppu_clk = clk & ppu_clk_gate;
  cpu_clk = clk & cpu_clk_gate;
end





int cpu_cnt;
always  @(posedge cpu_clk)
    if(rst || ~rdy) begin
        cpu_data_wr <= 0;
        cpu_addr <= 0;
        cpu_wr <= 0;
        cpu_rd <= 1;
        cpu_cnt <= 0;
    end else begin
        cpu_rd <= cpu_wr;
        cpu_wr <= cpu_rd;
        if( cpu_wr ) begin
            // $display("at time  %t: (CPU cnt %d) Writing value 0x%0x at 0x%0x", $time, cpu_cnt, cpu_data_wr, cpu_addr);

            // read back data
            cpu_rd <= 1;    
            cpu_wr <= 0;
        end else begin
            // validate read from last tb_cycle
            if (cpu_cnt>0) begin
                if(cpu_data_rd == cpu_data_wr)
                    $display("SUCCESS: (CPU cnt %d) Read correct value 0x%0x from 0x%0x", cpu_cnt, cpu_data_rd, cpu_addr);
                else begin
                    $display("ERROR: (CPU cnt %d) Read incorrect value 0x%0x from 0x%0x (expected 0x%0x)", cpu_cnt, cpu_data_rd, cpu_addr, cpu_data_wr);
                    $finish;
                end
            end
            
            // write new data
            cpu_wr <= 1;    
            cpu_rd <= 0;    
            cpu_data_wr <= $urandom%256;
            cpu_addr <= $urandom%((2**ADDR_DEPTH)-1);
            cpu_cnt <= cpu_cnt+1;
        end
end

int ppu_cnt;
always  @(posedge ppu_clk)
    if(rst || ~rdy) begin
        ppu_data_wr <= 0;
        ppu_addr <= 0;
        ppu_wr <= 0;
        ppu_rd <= 1;
        ppu_cnt <= 0;
    end else begin
        ppu_rd <= ppu_wr;
        ppu_wr <= ppu_rd;
        if( ppu_wr ) begin
            // $display("at time  %t: (PPU cnt %d) Writing value 0x%0x at 0x%0x", $time, ppu_cnt, ppu_data_wr, ppu_addr);

            // read back data
            ppu_rd <= 1;    
            ppu_wr <= 0;
        end else begin
            // validate read from last tb_cycle
            if (ppu_cnt>0) begin
                if(ppu_data_rd == ppu_data_wr)
                    $display("SUCCESS: (PPU cnt %d) Read correct value 0x%0x from 0x%0x", ppu_cnt, ppu_data_rd, ppu_addr);
                else begin
                    $display("ERROR: (PPU cnt %d) Read incorrect value 0x%0x from 0x%0x (expected 0x%0x)", ppu_cnt, ppu_data_rd, ppu_addr, ppu_data_wr);
                    $finish;
                end
            end

            // write new data
            ppu_wr <= 1;    
            ppu_rd <= 0;    
            ppu_data_wr <= $urandom%256;
            ppu_addr <= $urandom%((2**ADDR_DEPTH)-1);
            ppu_cnt <= ppu_cnt+1;
        end
end

wire [15:0] sdram_dq;
logic [12:0] sdram_a;
logic [1:0] sdram_bs;
logic sdram_cs_n;
logic sdram_ras_n;
logic sdram_cas_n;
logic sdram_we_n;
logic [1:0] sdram_dqm;
logic sdram_cke;


logic [7:0] ppu_data_wr, cpu_data_wr;
logic [ADDR_DEPTH-1:0] ppu_addr, cpu_addr;
logic ppu_rd, ppu_wr;
logic cpu_rd, cpu_wr;
logic [7:0] ppu_data_rd, cpu_data_rd;

sdram_controller_multibank #(
    .TICKS_STARTUP    (1)
) u_sdram_controller_multibank (
    // main clocks
    .clk              (clk),
    .rst              (rst),
    .rdy              (rdy),
    .sync             (sync),
    //bank 0 interface
    .data_wr0         (ppu_data_wr),
    .addr0            (ppu_addr),
    .rd0              (ppu_rd),
    .wr0              (ppu_wr),
    .data_rd0         (ppu_data_rd),
    //bank 1 interface
    .data_wr1         (cpu_data_wr),
    .addr1            (cpu_addr),
    .rd1              (cpu_rd),
    .wr1              (cpu_wr),
    .data_rd1         (cpu_data_rd),
    // sdram pins
    .sdram_a          (sdram_a),
    .sdram_bs         (sdram_bs),
    .sdram_cs_n       (sdram_cs_n),
    .sdram_ras_n      (sdram_ras_n),
    .sdram_cas_n      (sdram_cas_n),
    .sdram_we_n       (sdram_we_n),
    .sdram_dqm        (sdram_dqm),
    .sdram_cke        (sdram_cke),
    .sdram_dq         (sdram_dq)
);


wire sdram_clk;
assign #QTR_CLK_PERIOD sdram_clk = clk; // clock ram with 90deg lag

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
    .dqm   (sdram_dqm)
    );

endmodule