`timescale 1ns/100ps

module sdram_nes_tb;

parameter CLK_PERIOD=23.288;
parameter HALF_CLK_PERIOD=CLK_PERIOD/2;
parameter QTR_CLK_PERIOD=CLK_PERIOD/4;
parameter ADDR_DEPTH=23;
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
    $dumpfile("sdram_nes_tb.vcd");
    $dumpvars(0,sdram_nes_tb);
 end

logic [4:0] cycle;
initial begin
    clk = 0;
    // ppu_clk = 0;
    // cpu_clk = 0;
    rst = 1;
    cycle = 0;
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


always @(posedge clk) begin
    if(rst) begin
        cycle <= 0;
    end else begin
        // $display("cycle %d", cycle);
        cycle <= cycle == 5'd23 ? 0 : cycle + 1;
    end
end 

logic cpu_clk_gate, ppu_clk_gate;
always_ff @(negedge clk) begin
  ppu_clk_gate <= cycle[2:0] == 0;
  cpu_clk_gate <= cycle == 0;
end
wire sync = cpu_clk_gate;

wire ppu_clk = clk & ppu_clk_gate;
wire cpu_clk = clk & cpu_clk_gate;




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
            $display("at time  %t: (CPU) Writing value 0x%0x at 0x%0x", $time, cpu_data_wr, cpu_addr);

            // read back data
            cpu_rd <= 1;    
            cpu_wr <= 0;
        end else begin
            // validate read from last cycle
            if (cpu_cnt>0) begin
                if(cpu_data_rd == cpu_data_wr)
                    $display("at time  %t: (PPU) Read correct value 0x%0x from 0x%0x", $time, cpu_data_rd, cpu_addr);
                else
                    $display("at time  %t: (PPU) ERROR: Read incorrect value 0x%0x from 0x%0x", $time, cpu_data_rd, cpu_addr);
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
            $display("at time  %t: (PPU) Writing value 0x%0x at 0x%0x", $time, ppu_data_wr, ppu_addr);

            // read back data
            ppu_rd <= 1;    
            ppu_wr <= 0;
        end else begin
            // validate read from last cycle
            if (ppu_cnt>0) begin
                if(ppu_data_rd == ppu_data_wr)
                    $display("at time  %t: (PPU) Read correct value 0x%0x from 0x%0x", $time, ppu_data_rd, ppu_addr);
                else
                    $display("at time  %t: (PPU) ERROR: Read incorrect value 0x%0x from 0x%0x", $time, ppu_data_rd, ppu_addr);
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
logic [15:0] sdram_din;
logic [15:0] sdram_dout;
logic sdram_dout_en;

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

sdram_nes_controller #(
    .TICKS_STARTUP    (1)
) u_sdram_nes_controller (
    // main clocks
    .clk              (clk),
    .rst              (rst),
    .sync             (sync),
    .rdy              (rdy),
    .ppu_data_wr      (ppu_data_wr),
    .ppu_addr         (ppu_addr),
    .ppu_rd           (ppu_rd),
    .ppu_wr           (ppu_wr),
    .ppu_data_rd      (ppu_data_rd),
    .cpu_data_wr      (cpu_data_wr),
    .cpu_addr         (cpu_addr),
    .cpu_rd           (cpu_rd),
    .cpu_wr           (cpu_wr),
    .cpu_data_rd      (cpu_data_rd),
    .sdram_a             (sdram_a),
    .sdram_bs            (sdram_bs),
    .sdram_cs_n          (sdram_cs_n),
    .sdram_ras_n         (sdram_ras_n),
    .sdram_cas_n         (sdram_cas_n),
    .sdram_we_n          (sdram_we_n),
    .sdram_dqm           (sdram_dqm),
    .sdram_cke           (sdram_cke),
    .sdram_din           (sdram_din),
    .sdram_dout          (sdram_dout),
    .sdram_dout_en       (sdram_dout_en)
);


wire sdram_clk;
assign #QTR_CLK_PERIOD sdram_clk = clk; // clock ram with 90deg lag

// tristate io buffer
assign sdram_dq = sdram_dout_en ? sdram_dout : 16'bz;
assign sdram_din = sdram_dout_en ? 16'b0 : sdram_dq;
// assign sdram_dq = 16'bz;
// assign sdram_din = 16'b0;

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