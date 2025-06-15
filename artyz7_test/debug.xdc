delete_debug_core [get_debug_cores {u_ila_0 }]
create_debug_core u_ila_0 ila
set_property C_DATA_DEPTH 1024 [get_debug_cores u_ila_0]
set_property C_TRIGIN_EN false [get_debug_cores u_ila_0]
set_property C_TRIGOUT_EN false [get_debug_cores u_ila_0]
set_property C_ADV_TRIGGER false [get_debug_cores u_ila_0]
set_property C_INPUT_PIPE_STAGES 0 [get_debug_cores u_ila_0]
set_property C_EN_STRG_QUAL false [get_debug_cores u_ila_0]
set_property ALL_PROBE_SAME_MU true [get_debug_cores u_ila_0]
set_property ALL_PROBE_SAME_MU_CNT 1 [get_debug_cores u_ila_0]
connect_debug_port u_ila_0/clk [get_nets [list u_zynq/processing_system7_0/inst/FCLK_CLK0 ]]
set_property port_width 32 [get_debug_ports u_ila_0/probe0]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe0]
connect_debug_port u_ila_0/probe0 [get_nets [list {u_sdram_axi/u_core/ram_read_data_w[0]} {u_sdram_axi/u_core/ram_read_data_w[1]} {u_sdram_axi/u_core/ram_read_data_w[2]} {u_sdram_axi/u_core/ram_read_data_w[3]} {u_sdram_axi/u_core/ram_read_data_w[4]} {u_sdram_axi/u_core/ram_read_data_w[5]} {u_sdram_axi/u_core/ram_read_data_w[6]} {u_sdram_axi/u_core/ram_read_data_w[7]} {u_sdram_axi/u_core/ram_read_data_w[8]} {u_sdram_axi/u_core/ram_read_data_w[9]} {u_sdram_axi/u_core/ram_read_data_w[10]} {u_sdram_axi/u_core/ram_read_data_w[11]} {u_sdram_axi/u_core/ram_read_data_w[12]} {u_sdram_axi/u_core/ram_read_data_w[13]} {u_sdram_axi/u_core/ram_read_data_w[14]} {u_sdram_axi/u_core/ram_read_data_w[15]} {u_sdram_axi/u_core/ram_read_data_w[16]} {u_sdram_axi/u_core/ram_read_data_w[17]} {u_sdram_axi/u_core/ram_read_data_w[18]} {u_sdram_axi/u_core/ram_read_data_w[19]} {u_sdram_axi/u_core/ram_read_data_w[20]} {u_sdram_axi/u_core/ram_read_data_w[21]} {u_sdram_axi/u_core/ram_read_data_w[22]} {u_sdram_axi/u_core/ram_read_data_w[23]} {u_sdram_axi/u_core/ram_read_data_w[24]} {u_sdram_axi/u_core/ram_read_data_w[25]} {u_sdram_axi/u_core/ram_read_data_w[26]} {u_sdram_axi/u_core/ram_read_data_w[27]} {u_sdram_axi/u_core/ram_read_data_w[28]} {u_sdram_axi/u_core/ram_read_data_w[29]} {u_sdram_axi/u_core/ram_read_data_w[30]} {u_sdram_axi/u_core/ram_read_data_w[31]} ]]
create_debug_port u_ila_0 probe
set_property port_width 16 [get_debug_ports u_ila_0/probe1]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe1]
connect_debug_port u_ila_0/probe1 [get_nets [list {u_sdram_axi/u_core/sample_data_q[0]} {u_sdram_axi/u_core/sample_data_q[1]} {u_sdram_axi/u_core/sample_data_q[2]} {u_sdram_axi/u_core/sample_data_q[3]} {u_sdram_axi/u_core/sample_data_q[4]} {u_sdram_axi/u_core/sample_data_q[5]} {u_sdram_axi/u_core/sample_data_q[6]} {u_sdram_axi/u_core/sample_data_q[7]} {u_sdram_axi/u_core/sample_data_q[8]} {u_sdram_axi/u_core/sample_data_q[9]} {u_sdram_axi/u_core/sample_data_q[10]} {u_sdram_axi/u_core/sample_data_q[11]} {u_sdram_axi/u_core/sample_data_q[12]} {u_sdram_axi/u_core/sample_data_q[13]} {u_sdram_axi/u_core/sample_data_q[14]} {u_sdram_axi/u_core/sample_data_q[15]} ]]
create_debug_port u_ila_0 probe
set_property port_width 5 [get_debug_ports u_ila_0/probe2]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe2]
connect_debug_port u_ila_0/probe2 [get_nets [list {u_sdram_axi/u_core/rd_q[0]} {u_sdram_axi/u_core/rd_q[1]} {u_sdram_axi/u_core/rd_q[2]} {u_sdram_axi/u_core/rd_q[3]} {u_sdram_axi/u_core/rd_q[4]} ]]
create_debug_port u_ila_0 probe
set_property port_width 16 [get_debug_ports u_ila_0/probe3]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe3]
connect_debug_port u_ila_0/probe3 [get_nets [list {u_sdram_axi/u_core/data_buffer_q[0]} {u_sdram_axi/u_core/data_buffer_q[1]} {u_sdram_axi/u_core/data_buffer_q[2]} {u_sdram_axi/u_core/data_buffer_q[3]} {u_sdram_axi/u_core/data_buffer_q[4]} {u_sdram_axi/u_core/data_buffer_q[5]} {u_sdram_axi/u_core/data_buffer_q[6]} {u_sdram_axi/u_core/data_buffer_q[7]} {u_sdram_axi/u_core/data_buffer_q[8]} {u_sdram_axi/u_core/data_buffer_q[9]} {u_sdram_axi/u_core/data_buffer_q[10]} {u_sdram_axi/u_core/data_buffer_q[11]} {u_sdram_axi/u_core/data_buffer_q[12]} {u_sdram_axi/u_core/data_buffer_q[13]} {u_sdram_axi/u_core/data_buffer_q[14]} {u_sdram_axi/u_core/data_buffer_q[15]} ]]
create_debug_port u_ila_0 probe
set_property port_width 16 [get_debug_ports u_ila_0/probe4]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe4]
connect_debug_port u_ila_0/probe4 [get_nets [list {u_sdram_axi/u_core/sample_data0_q[0]} {u_sdram_axi/u_core/sample_data0_q[1]} {u_sdram_axi/u_core/sample_data0_q[2]} {u_sdram_axi/u_core/sample_data0_q[3]} {u_sdram_axi/u_core/sample_data0_q[4]} {u_sdram_axi/u_core/sample_data0_q[5]} {u_sdram_axi/u_core/sample_data0_q[6]} {u_sdram_axi/u_core/sample_data0_q[7]} {u_sdram_axi/u_core/sample_data0_q[8]} {u_sdram_axi/u_core/sample_data0_q[9]} {u_sdram_axi/u_core/sample_data0_q[10]} {u_sdram_axi/u_core/sample_data0_q[11]} {u_sdram_axi/u_core/sample_data0_q[12]} {u_sdram_axi/u_core/sample_data0_q[13]} {u_sdram_axi/u_core/sample_data0_q[14]} {u_sdram_axi/u_core/sample_data0_q[15]} ]]
create_debug_port u_ila_0 probe
set_property port_width 32 [get_debug_ports u_ila_0/probe5]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe5]
connect_debug_port u_ila_0/probe5 [get_nets [list {u_sdram_axi/u_core/ram_write_data_w[0]} {u_sdram_axi/u_core/ram_write_data_w[1]} {u_sdram_axi/u_core/ram_write_data_w[2]} {u_sdram_axi/u_core/ram_write_data_w[3]} {u_sdram_axi/u_core/ram_write_data_w[4]} {u_sdram_axi/u_core/ram_write_data_w[5]} {u_sdram_axi/u_core/ram_write_data_w[6]} {u_sdram_axi/u_core/ram_write_data_w[7]} {u_sdram_axi/u_core/ram_write_data_w[8]} {u_sdram_axi/u_core/ram_write_data_w[9]} {u_sdram_axi/u_core/ram_write_data_w[10]} {u_sdram_axi/u_core/ram_write_data_w[11]} {u_sdram_axi/u_core/ram_write_data_w[12]} {u_sdram_axi/u_core/ram_write_data_w[13]} {u_sdram_axi/u_core/ram_write_data_w[14]} {u_sdram_axi/u_core/ram_write_data_w[15]} {u_sdram_axi/u_core/ram_write_data_w[16]} {u_sdram_axi/u_core/ram_write_data_w[17]} {u_sdram_axi/u_core/ram_write_data_w[18]} {u_sdram_axi/u_core/ram_write_data_w[19]} {u_sdram_axi/u_core/ram_write_data_w[20]} {u_sdram_axi/u_core/ram_write_data_w[21]} {u_sdram_axi/u_core/ram_write_data_w[22]} {u_sdram_axi/u_core/ram_write_data_w[23]} {u_sdram_axi/u_core/ram_write_data_w[24]} {u_sdram_axi/u_core/ram_write_data_w[25]} {u_sdram_axi/u_core/ram_write_data_w[26]} {u_sdram_axi/u_core/ram_write_data_w[27]} {u_sdram_axi/u_core/ram_write_data_w[28]} {u_sdram_axi/u_core/ram_write_data_w[29]} {u_sdram_axi/u_core/ram_write_data_w[30]} {u_sdram_axi/u_core/ram_write_data_w[31]} ]]
create_debug_port u_ila_0 probe
set_property port_width 4 [get_debug_ports u_ila_0/probe6]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe6]
connect_debug_port u_ila_0/probe6 [get_nets [list {u_sdram_axi/u_core/state_q[0]} {u_sdram_axi/u_core/state_q[1]} {u_sdram_axi/u_core/state_q[2]} {u_sdram_axi/u_core/state_q[3]} ]]
create_debug_port u_ila_0 probe
set_property port_width 32 [get_debug_ports u_ila_0/probe7]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe7]
connect_debug_port u_ila_0/probe7 [get_nets [list {u_sdram_axi/u_core/ram_addr_w[0]} {u_sdram_axi/u_core/ram_addr_w[1]} {u_sdram_axi/u_core/ram_addr_w[2]} {u_sdram_axi/u_core/ram_addr_w[3]} {u_sdram_axi/u_core/ram_addr_w[4]} {u_sdram_axi/u_core/ram_addr_w[5]} {u_sdram_axi/u_core/ram_addr_w[6]} {u_sdram_axi/u_core/ram_addr_w[7]} {u_sdram_axi/u_core/ram_addr_w[8]} {u_sdram_axi/u_core/ram_addr_w[9]} {u_sdram_axi/u_core/ram_addr_w[10]} {u_sdram_axi/u_core/ram_addr_w[11]} {u_sdram_axi/u_core/ram_addr_w[12]} {u_sdram_axi/u_core/ram_addr_w[13]} {u_sdram_axi/u_core/ram_addr_w[14]} {u_sdram_axi/u_core/ram_addr_w[15]} {u_sdram_axi/u_core/ram_addr_w[16]} {u_sdram_axi/u_core/ram_addr_w[17]} {u_sdram_axi/u_core/ram_addr_w[18]} {u_sdram_axi/u_core/ram_addr_w[19]} {u_sdram_axi/u_core/ram_addr_w[20]} {u_sdram_axi/u_core/ram_addr_w[21]} {u_sdram_axi/u_core/ram_addr_w[22]} {u_sdram_axi/u_core/ram_addr_w[23]} {u_sdram_axi/u_core/ram_addr_w[24]} {u_sdram_axi/u_core/ram_addr_w[25]} {u_sdram_axi/u_core/ram_addr_w[26]} {u_sdram_axi/u_core/ram_addr_w[27]} {u_sdram_axi/u_core/ram_addr_w[28]} {u_sdram_axi/u_core/ram_addr_w[29]} {u_sdram_axi/u_core/ram_addr_w[30]} {u_sdram_axi/u_core/ram_addr_w[31]} ]]
create_debug_port u_ila_0 probe
set_property port_width 4 [get_debug_ports u_ila_0/probe8]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe8]
connect_debug_port u_ila_0/probe8 [get_nets [list {u_sdram_axi/u_core/ram_wr_w[0]} {u_sdram_axi/u_core/ram_wr_w[1]} {u_sdram_axi/u_core/ram_wr_w[2]} {u_sdram_axi/u_core/ram_wr_w[3]} ]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe9]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe9]
connect_debug_port u_ila_0/probe9 [get_nets [list u_sdram_axi/u_core/ram_accept_w ]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe10]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe10]
connect_debug_port u_ila_0/probe10 [get_nets [list u_sdram_axi/u_core/ram_ack_w ]]
create_debug_port u_ila_0 probe
set_property port_width 1 [get_debug_ports u_ila_0/probe11]
set_property PROBE_TYPE DATA_AND_TRIGGER [get_debug_ports u_ila_0/probe11]
connect_debug_port u_ila_0/probe11 [get_nets [list u_sdram_axi/u_core/ram_rd_w ]]