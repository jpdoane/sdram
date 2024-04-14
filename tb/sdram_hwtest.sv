`timescale 1ns / 100ps

module sdram_hwtest
#(
    parameter CLK_PERIOD=23.288,
    parameter ADDR_DEPTH=25,
    parameter COL_DEPTH=10,
    parameter TEST_ADDR_BITS=ADDR_DEPTH
)
(
    // main clocks
input logic clk125MHz,

output logic [3:0] led,
input logic [3:0] sw,
input logic [3:0] btn,

// sdram pins
(* mark_debug = "true" *) inout logic [15:0] sdram_dq,
(* mark_debug = "true" *) output logic [12:0] sdram_a,
(* mark_debug = "true" *) output logic [1:0] sdram_bs,
                          output logic clk_sdram,
(* mark_debug = "true" *) output logic sdram_cke,
(* mark_debug = "true" *) output logic sdram_we_n,
(* mark_debug = "true" *) output logic sdram_cas_n,
(* mark_debug = "true" *) output logic sdram_ras_n,
(* mark_debug = "true" *) output logic sdram_cs_n,
(* mark_debug = "true" *) output logic sdram_ldqm,
(* mark_debug = "true" *) output logic sdram_udqm
);

// internal clock for sdram
logic clk, rst, rst_clocks, lock;
assign rst_clocks = btn[0];
assign rst = ~lock; 

(* mark_debug = "true" *) logic [ADDR_DEPTH-1:0] addr;
(* mark_debug = "true" *) logic [7:0] data_wr,data_rd, data_cmp;
assign data_wr = addr[7:0];

(* mark_debug = "true" *) logic done, error, rd_mode, wr_mode, boot_mode;

// wire next_addr = rd_mode ? val : rdy;
wire next_addr = rdy;
wire last_addr = &addr[TEST_ADDR_BITS-1:0]; 

(* mark_debug = "true" *) wire rd_error = rd_mode && val && (data_rd != data_cmp);

always_ff @(posedge clk)
begin
    if(rst) begin
        addr <= 0;
        error <= 0;
        done <= 0;
        rd_mode <= 0;
        wr_mode <= 0;
        boot_mode <= 1;
        data_cmp <= 0;
    end
    else begin
        if( next_addr ) begin
            if( last_addr) begin
                addr <= 0;
                rd_mode <= wr_mode;
                wr_mode <= rd_mode;
                if(rd_mode) done <= 1;
            end else begin
                addr <= addr+1;
            end
            data_cmp <= data_wr; // reads are pipelines, so register previous result to compare
        end
        if( rd_error ) error <= 1;
        if(boot_mode && rdy) begin
            boot_mode <= 0;
            wr_mode <= 1;
        end
    end    
end
assign led = {error, rd_mode, wr_mode, boot_mode};

clk_wiz_0 u_sdram_clk 
(
    .clk_sdram(clk),  // internal clock for sdram
    .clk_sdram90(clk_sdram), // external clock for sdram (90deg phase)
    .reset(rst_clocks),
    .locked(lock),
    .clk125MHz(clk125MHz)
);

// io buffer for tristate data pins
logic [15:0] sdram_din,sdram_dout;
logic sdram_dout_en;

sdram_controller_w9825g6kh
#(
    .SD_CLK_PERIOD_NS (23.288 ),
    .CAS_LATENCY      (2      ),
    .SIM_STARTUP      (0      )
)
u_sdram_controller(
    .clk      (clk      ),
    .rst      (rst      ),
    .data_wr  (data_wr  ),
    .addr_in  (addr  ),
    .wr       (~rd_mode       ),
    .rd       (rd_mode       ),
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

assign sdram_dq = sdram_dout_en ? sdram_dout : 16'bz;
assign sdram_din = sdram_dout_en ? 16'b0 : sdram_dq;

// generate
//     genvar i;
//     for (i = 0; i<16; i++) begin
//         IOBUF #(
//         .DRIVE(12), // Specify the output drive strength
//         .IBUF_LOW_PWR("TRUE"),  // Low Power - "TRUE", High Performance = "FALSE"
//         .IOSTANDARD("DEFAULT"), // Specify the I/O standard
//         .SLEW("FAST") // Specify the output slew rate
//         ) IOBUF_inst (
//         .O(sdram_dout[i]),    // Buffer output
//         .IO(sdram_dq[i]),      // Buffer inout port (connect directly to top-level port)
//         .I(sdram_din[i]),     // Buffer input
//         .T( ~sdram_dout_en )         // 3-state enable input, high=input, low=output
//         );
//     end    
// endgenerate

endmodule
