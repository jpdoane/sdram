# Clocks avaialble from PS (defined in zynq_ps.tcl)
# clk_fpga_0: 100MHz clock (u_zynq/processing_system7_0/inst/FCLK_CLK0)
# clk_fpga_1: 50MHz clock (u_zynq/processing_system7_0/inst/FCLK_CLK1)

# Gated CPU clock defined in u_clk_div
# 50 MHz / 24 = ~2.083 MHz
create_generated_clock -name clk_div \
    -source [get_pins u_zynq/CLK1] \
    -divide_by 24 \
    [get_pins u_clk_div/BUFGCE_div/O]

create_generated_clock -name clk_sdram -source [get_pins u_sdram_io/u_clock_oddr/C]  -multiply_by 1 -invert [get_ports clk_sdram]

# dont flag timing on master reset
set_false_path -through [get_pins u_zynq/ARST]