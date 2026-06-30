`timescale 1ns/1ps

// portb_tester.sv
//
// Self-contained PL-side portB test block for dual_master_sdram.
//
// portB protocol (matches dual_master_sdram):
//   portB_rdy -- normally 1; driven 0 by controller when busy (stalls CPU)
//   portB_wr  -- 0 = read, non-zero = write byte strobe
//   Read data is valid on the clk_cpu edge ONE cpu-cycle after read issued.
//
// When portB_rdy=0 the stall is
// modelled by holding the FSM outputs stable -- the controller ignores
// portB_en pulses that coincide with portB_rdy=0, so the FSM simply waits
// for the next clk edge where portB_rdy=1 before advancing.
//
// Status outputs:
//   test_done   asserts when the test has finished (pass or fail)
//   test_pass   asserts iff all readbacks matched the written pattern
//   error_count saturating 16-bit count of word mismatches

module portb_tester #(
    parameter int ADDR_WIDTH   = 25,
    parameter int DATA_WIDTH   = 32,
    parameter int N_TEST_WORDS = 4096   // words to write+read per pass
)(
    input  logic clk,           // div clock (clk_master/24)
    input  logic rst,           // active-high synchronous reset

    input  logic start,         // rising edge restarts the test

    // portB interface -> dual_master_sdram
    output logic [DATA_WIDTH/8-1:0] portB_wr,
    output logic [ADDR_WIDTH-1:0]   portB_addr,
    output logic [DATA_WIDTH-1:0]   portB_write_data,

    // portB interface <- dual_master_sdram
    input  logic [DATA_WIDTH-1:0]   portB_read_data,
    input  logic                    portB_rdy,

    // test status
    output logic                    test_done,
    output logic                    test_pass,
    output logic [15:0]             error_count
);

    localparam int WORD_LEN  = DATA_WIDTH / 8;
    localparam int ADDR_BITS = $clog2(N_TEST_WORDS);

    // -----------------------------------------------------------------------
    // Test pattern: address-indexed, non-trivial
    // -----------------------------------------------------------------------

    function automatic logic [DATA_WIDTH-1:0] pattern(
        input logic [ADDR_BITS-1:0] idx
    );
        return DATA_WIDTH'(idx) ^ 32'hA5A5_0000;
    endfunction

    logic start_s0, start_s1;
    logic start_pulse;

    always_ff @(posedge clk) begin
        if (rst) begin
            start_s0 <= 0;
            start_s1 <= 0;
        end else begin
            start_s0 <= start;
            start_s1 <= start_s0;
        end
    end
    assign start_pulse = start_s0 & ~start_s1;

    // -----------------------------------------------------------------------
    // Test FSM
    // -----------------------------------------------------------------------

    typedef enum logic [2:0] {
        ST_IDLE     = 3'd0,
        ST_WRITING  = 3'd1,
        ST_RD_ISSUE = 3'd2,
        ST_RD_WAIT  = 3'd3,
        ST_DONE     = 3'd4
    } state_t;

    state_t              state;
    logic [ADDR_BITS-1:0] word_cnt;
    logic [15:0]          err_cnt;

    always_ff @(posedge clk) begin
        if (rst) begin
            state            <= ST_IDLE;
            word_cnt         <= '0;
            err_cnt          <= '0;
            test_done        <= 0;
            test_pass        <= 0;
            portB_wr         <= '0;
            portB_addr       <= '0;
            portB_write_data <= '0;

        end else if (start_pulse) begin
            // Restart from any state
            state            <= ST_IDLE;
            word_cnt         <= '0;
            err_cnt          <= '0;
            test_done        <= 0;
            test_pass        <= 0;
            portB_wr         <= '0;

        end else if (!portB_rdy) begin
            // Stall: hold all outputs, do not advance
            ;

        end else begin
            case (state)

                // ------------------------------------------------------------
                ST_IDLE: begin
                    // Auto-launch on first clk_cpu tick after reset/start.
                    test_done        <= 0;
                    test_pass        <= 0;
                    word_cnt         <= '0;
                    err_cnt          <= '0;
                    portB_addr       <= '0;
                    portB_write_data <= pattern('0);
                    portB_wr         <= {WORD_LEN{1'b1}};
                    state            <= ST_WRITING;
                end

                // ------------------------------------------------------------
                ST_WRITING: begin
                    // Outputs already set for word_cnt; advance on this tick.
                    if (word_cnt == ADDR_BITS'(N_TEST_WORDS - 1)) begin
                        // All words written -- start read phase
                        word_cnt         <= '0;
                        portB_addr       <= '0;
                        portB_wr         <= '0;
                        portB_write_data <= '0;
                        state            <= ST_RD_ISSUE;
                    end else begin
                        word_cnt         <= word_cnt + 1'b1;
                        portB_addr       <= ADDR_WIDTH'((word_cnt + 1) * 4);
                        portB_write_data <= pattern(word_cnt + 1'b1);
                        // portB_wr stays all-ones
                    end
                end

                // ------------------------------------------------------------
                ST_RD_ISSUE: begin
                    // Drive read (portB_wr=0) for word_cnt.
                    // Accepted this tick; data arrives next tick (RD_WAIT).
                    portB_addr <= ADDR_WIDTH'(word_cnt * 4);
                    portB_wr   <= '0;
                    state      <= ST_RD_WAIT;
                end

                // ------------------------------------------------------------
                ST_RD_WAIT: begin
                    // One-cpu-cycle read latency: portB_read_data is valid
                    // on this tick (portB_rdy returned high after the read).
                    if (portB_read_data !== pattern(word_cnt)) begin
                        if (err_cnt != 16'hFFFF)
                            err_cnt <= err_cnt + 1'b1;
                    end

                    if (word_cnt == ADDR_BITS'(N_TEST_WORDS - 1)) begin
                        state <= ST_DONE;
                    end else begin
                        word_cnt   <= word_cnt + 1'b1;
                        portB_addr <= ADDR_WIDTH'((word_cnt + 1) * 4);
                        state      <= ST_RD_ISSUE;
                    end
                end

                // ------------------------------------------------------------
                ST_DONE: begin
                    test_done <= 1'b1;
                    test_pass <= (err_cnt == '0);
                    portB_wr  <= '0;
                    // Hold until restarted by start_pulse
                end

                default: state <= ST_IDLE;

            endcase
        end
    end

    assign error_count = err_cnt;

endmodule
