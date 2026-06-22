`timescale 1ns/1ps

// clk_div.sv
//
// Generates a divided clock using a BUFGCE primitive.
// cpu_en is asserted for one clk_master cycle every DIV cycles,
// on the falling edge of clk_master so the BUFGCE gate decision
// is settled well before the subsequent rising edge.
// BUFGCE passes that rising edge through as a real clock (clk_cpu)
// that the tools can properly constrain and clock domain check.

module clk_div #(
    parameter int DIV = 24      // output period = DIV * clk_master period
)(
    input  logic clk_master,    // fast source clock
    input  logic rst,           // synchronous reset (holds clk_cpu gated)
    output logic clk_cpu,       // divided output clock (real BUFGCE clock)
    output logic cpu_en         // clock-enable pulse (one clk_master cycle)
);

    // -----------------------------------------------------------------------
    // Divide counter -- runs on falling edges so cpu_en is stable before
    // the next rising edge reaches the BUFGCE.
    // -----------------------------------------------------------------------

    localparam int CNT_W = $clog2(DIV);

    logic [CNT_W-1:0] cnt;

    always_ff @(negedge clk_master or posedge rst) begin
        if (rst) begin
            cnt    <= '0;
            cpu_en <= 1'b0;
        end else begin
            if (cnt == CNT_W'(DIV - 1)) begin
                cnt    <= '0;
                cpu_en <= 1'b1;
            end else begin
                cnt    <= cnt + 1'b1;
                cpu_en <= 1'b0;
            end
        end
    end

    // -----------------------------------------------------------------------
    // BUFGCE: only passes clock edges when CE is high.
    // Each asserted cpu_en lets exactly one rising edge of clk_master
    // propagate to clk_cpu, producing a clean divided clock on the
    // global clock network.
    // -----------------------------------------------------------------------

    BUFGCE BUFGCE_cpu (
        .O  (clk_cpu),
        .CE (cpu_en),
        .I  (clk_master)
    );

endmodule
