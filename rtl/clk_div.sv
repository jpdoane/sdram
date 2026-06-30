`timescale 1ns/1ps

// clk_div.sv
//
// Generates a divided clock that ticks every DIV cycles of clk_master
module clk_div #(
    parameter int DIV = 24      // output period = DIV * clk_master period
)(
    input  logic clk_master,    // fast source clock
    input  logic rst_master,    // synchronous reset
    output logic clk_buf,       // buffered copy of clk_master, phase-matched to clk_div
    output logic rst_buf,       // buffered copy of rst_master
    output logic clk_div,       // divided clock, ticks every DIV cycles of clk_master
    output logic div_en         // goes high for each tick of clk_div (supports divided operations in logic clocked by clk_fast)
);

    localparam int CNT_W = $clog2(DIV);

    logic [CNT_W-1:0] cnt;

    always_ff @(negedge clk_master) begin
        if (rst_master) begin
            cnt    <= '0;
            div_en <= 1'b0;
        end else begin
            if (cnt == CNT_W'(DIV - 1)) begin
                cnt    <= '0;
                div_en <= 1'b1;
            end else begin
                cnt    <= cnt + 1'b1;
                div_en <= 1'b0;
            end
        end
    end

    BUFGCE BUFGCE_div (
        .O  (clk_div),
        .CE (div_en),
        .I  (clk_master)
    );

    BUFG BUFG_buf (
        .O  (clk_buf),
        .I  (clk_master)
    );

    assign rst_buf = rst_master;

    // buffer the reset deassertion
    // logic rst_r1, rst_r2;
    // always @(posedge clk_buf or posedge rst_master) begin
    //     if(rst_master) begin
    //         rst_buf <= 1'b1;
    //         rst_r1 <= 1'b1;
    //         rst_r2 <= 1'b1;
    //     end else begin
    //         rst_r1 <= 1'b0;
    //         rst_r2 <= rst_r1;
    //         rst_buf <= rst_r2;
    //     end
    // end
endmodule
