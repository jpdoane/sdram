## This file is a general .xdc for the ARTY Z7-10 Rev.B
## To use it in a project:
## - uncomment the lines corresponding to used pins
## - rename the used ports (in each line, after get_ports) according to the top level signal names in the project

## Master 125MHz clock
# set_property -dict {PACKAGE_PIN H16 IOSTANDARD LVCMOS33} [get_ports CLK_125MHZ]
# create_clock -period 8.000 -name sys_clk -waveform {0.000 4.000} [get_ports CLK_125MHZ]

create_generated_clock -name clk50MHz [get_pins u_zynq/processing_system7_0/inst/FCLK_CLK0]


## Switches
# set_property -dict {PACKAGE_PIN M20 IOSTANDARD LVCMOS33} [get_ports {SW[0]}]
# set_property -dict {PACKAGE_PIN M19 IOSTANDARD LVCMOS33} [get_ports {SW[1]}]

## RGB LEDs
#set_property -dict { PACKAGE_PIN L15    IOSTANDARD LVCMOS33 } [get_ports { led4_b }]; #IO_L22N_T3_AD7P_35 Sch=LED4_B
#set_property -dict { PACKAGE_PIN G17    IOSTANDARD LVCMOS33 } [get_ports { led4_g }]; #IO_L16P_T2_35 Sch=LED4_G
#set_property -dict { PACKAGE_PIN N15    IOSTANDARD LVCMOS33 } [get_ports { led4_r }]; #IO_L21P_T3_DQS_AD14P_35 Sch=LED4_R
#set_property -dict { PACKAGE_PIN G14    IOSTANDARD LVCMOS33 } [get_ports { led5_b }]; #IO_0_35 Sch=LED5_B
#set_property -dict { PACKAGE_PIN L14    IOSTANDARD LVCMOS33 } [get_ports { led5_g }]; #IO_L22P_T3_AD7P_35 Sch=LED5_G
#set_property -dict { PACKAGE_PIN M15    IOSTANDARD LVCMOS33 } [get_ports { led5_r }]; #IO_L23N_T3_35 Sch=LED5_R

## LEDs
set_property -dict {PACKAGE_PIN R14 IOSTANDARD LVCMOS33} [get_ports {LED[0]}]
set_property -dict {PACKAGE_PIN P14 IOSTANDARD LVCMOS33} [get_ports {LED[1]}]
set_property -dict {PACKAGE_PIN N16 IOSTANDARD LVCMOS33} [get_ports {LED[2]}]
set_property -dict {PACKAGE_PIN M14 IOSTANDARD LVCMOS33} [get_ports {LED[3]}]

## Buttons
set_property -dict {PACKAGE_PIN D19 IOSTANDARD LVCMOS33} [get_ports {btn[0]}]
set_property -dict {PACKAGE_PIN D20 IOSTANDARD LVCMOS33} [get_ports {btn[1]}]
set_property -dict {PACKAGE_PIN L20 IOSTANDARD LVCMOS33} [get_ports {btn[2]}]
set_property -dict {PACKAGE_PIN L19 IOSTANDARD LVCMOS33} [get_ports {btn[3]}]

## Pmod Header JA
# set_property -dict { PACKAGE_PIN Y18   IOSTANDARD LVCMOS33 } [get_ports { ja_p[1] }]; #IO_L17P_T2_34 Sch=JA1_P (Pin 1)
# set_property -dict {PACKAGE_PIN Y19 IOSTANDARD LVCMOS33} [get_ports {ctrl_data[0]}]
# set_property -dict {PACKAGE_PIN Y16 IOSTANDARD LVCMOS33} [get_ports {ctrl_strobe[0]}]
# set_property -dict {PACKAGE_PIN Y17 IOSTANDARD LVCMOS33} [get_ports {ctrl_out[0]}]
# set_property -dict { PACKAGE_PIN U18   IOSTANDARD LVCMOS33 } [get_ports { ja_p[3] }]; #IO_L12P_T1_MRCC_34 Sch=JA3_P (Pin 7)
# set_property -dict { PACKAGE_PIN U19   IOSTANDARD LVCMOS33 } [get_ports { ja_n[3] }]; #IO_L12N_T1_MRCC_34 Sch=JA3_N (Pin 8)
# set_property -dict { PACKAGE_PIN W18   IOSTANDARD LVCMOS33 } [get_ports { ja_p[4] }]; #IO_L22P_T3_34 Sch=JA4_P (Pin 9)
# set_property -dict { PACKAGE_PIN W19   IOSTANDARD LVCMOS33 } [get_ports { ja_n[4] }]; #IO_L22N_T3_34 Sch=JA4_N (Pin 10)

# set_property PULLDOWN true [get_ports {ctrl_strobe[1]}]
# set_property PULLDOWN true [get_ports {ctrl_strobe[0]}]
# set_property PULLDOWN true [get_ports {ctrl_out[1]}]
# set_property PULLDOWN true [get_ports {ctrl_out[0]}]

## Pmod Header JB
# set_property -dict { PACKAGE_PIN W14   IOSTANDARD LVCMOS33 } [get_ports { jb_p[1] }]; #IO_L8P_T1_34 Sch=JB1_P (Pin 1)
# set_property -dict {PACKAGE_PIN Y14 IOSTANDARD LVCMOS33} [get_ports {ctrl_data[1]}]
# set_property -dict {PACKAGE_PIN T11 IOSTANDARD LVCMOS33} [get_ports {ctrl_strobe[1]}]
# set_property -dict {PACKAGE_PIN T10 IOSTANDARD LVCMOS33} [get_ports {ctrl_out[1]}]
# set_property -dict { PACKAGE_PIN V16   IOSTANDARD LVCMOS33 } [get_ports { jb_p[3] }]; #IO_L18P_T2_34 Sch=JB3_P (Pin 7)
# set_property -dict { PACKAGE_PIN W16   IOSTANDARD LVCMOS33 } [get_ports { jb_n[3] }]; #IO_L18N_T2_34 Sch=JB3_N (Pin 8)
# set_property -dict { PACKAGE_PIN V12   IOSTANDARD LVCMOS33 } [get_ports { jb_p[4] }]; #IO_L4P_T0_34 Sch=JB4_P (Pin 9)
# set_property -dict { PACKAGE_PIN W13   IOSTANDARD LVCMOS33 } [get_ports { jb_n[4] }]; #IO_L4N_T0_34 Sch=JB4_N (Pin 10)

## Audio Out
# set_property -dict {PACKAGE_PIN R18 IOSTANDARD LVCMOS33} [get_ports aud_pwm]
# set_property -dict {PACKAGE_PIN T17 IOSTANDARD LVCMOS33} [get_ports aud_sd]

## Crypto SDA
#set_property -dict { PACKAGE_PIN J15   IOSTANDARD LVCMOS33 } [get_ports { crypto_sda }]; #IO_25_35 Sch=CRYPTO_SDA

## HDMI RX Signals
#set_property -dict { PACKAGE_PIN H17   IOSTANDARD LVCMOS33 } [get_ports { hdmi_rx_cec }]; #IO_L13N_T2_MRCC_35 Sch=HDMI_RX_CEC
#set_property -dict { PACKAGE_PIN P19   IOSTANDARD TMDS_33  } [get_ports { hdmi_rx_clk_n }]; #IO_L13N_T2_MRCC_34 Sch=HDMI_RX_CLK_N
#set_property -dict { PACKAGE_PIN N18   IOSTANDARD TMDS_33  } [get_ports { hdmi_rx_clk_p }]; #IO_L13P_T2_MRCC_34 Sch=HDMI_RX_CLK_P
#set_property -dict { PACKAGE_PIN W20   IOSTANDARD TMDS_33  } [get_ports { hdmi_rx_d_n[0] }]; #IO_L16N_T2_34 Sch=HDMI_RX_D0_N
#set_property -dict { PACKAGE_PIN V20   IOSTANDARD TMDS_33  } [get_ports { hdmi_rx_d_p[0] }]; #IO_L16P_T2_34 Sch=HDMI_RX_D0_P
#set_property -dict { PACKAGE_PIN U20   IOSTANDARD TMDS_33  } [get_ports { hdmi_rx_d_n[1] }]; #IO_L15N_T2_DQS_34 Sch=HDMI_RX_D1_N
#set_property -dict { PACKAGE_PIN T20   IOSTANDARD TMDS_33  } [get_ports { hdmi_rx_d_p[1] }]; #IO_L15P_T2_DQS_34 Sch=HDMI_RX_D1_P
#set_property -dict { PACKAGE_PIN P20   IOSTANDARD TMDS_33  } [get_ports { hdmi_rx_d_n[2] }]; #IO_L14N_T2_SRCC_34 Sch=HDMI_RX_D2_N
#set_property -dict { PACKAGE_PIN N20   IOSTANDARD TMDS_33  } [get_ports { hdmi_rx_d_p[2] }]; #IO_L14P_T2_SRCC_34 Sch=HDMI_RX_D2_P
#set_property -dict { PACKAGE_PIN T19   IOSTANDARD LVCMOS33 } [get_ports { hdmi_rx_hpd }]; #IO_25_34 Sch=HDMI_RX_HPD
#set_property -dict { PACKAGE_PIN U14   IOSTANDARD LVCMOS33 } [get_ports { hdmi_rx_scl }]; #IO_L11P_T1_SRCC_34 Sch=HDMI_RX_SCL
#set_property -dict { PACKAGE_PIN U15   IOSTANDARD LVCMOS33 } [get_ports { hdmi_rx_sda }]; #IO_L11N_T1_SRCC_34 Sch=HDMI_RX_SDA

## HDMI TX Signals
# set_property -dict { PACKAGE_PIN G15   IOSTANDARD LVCMOS33 } [get_ports { HDMI_CEC }]; #IO_L19N_T3_VREF_35 Sch=HDMI_TX_CEC
# set_property -dict {PACKAGE_PIN L17 IOSTANDARD TMDS_33} [get_ports HDMI_CLK_N]
# set_property -dict {PACKAGE_PIN L16 IOSTANDARD TMDS_33} [get_ports HDMI_CLK]
# set_property -dict {PACKAGE_PIN K18 IOSTANDARD TMDS_33} [get_ports {HDMI_TX_N[0]}]
# set_property -dict {PACKAGE_PIN K17 IOSTANDARD TMDS_33} [get_ports {HDMI_TX[0]}]
# set_property -dict {PACKAGE_PIN J19 IOSTANDARD TMDS_33} [get_ports {HDMI_TX_N[1]}]
# set_property -dict {PACKAGE_PIN K19 IOSTANDARD TMDS_33} [get_ports {HDMI_TX[1]}]
# set_property -dict {PACKAGE_PIN H18 IOSTANDARD TMDS_33} [get_ports {HDMI_TX_N[2]}]
# set_property -dict {PACKAGE_PIN J18 IOSTANDARD TMDS_33} [get_ports {HDMI_TX[2]}]
# set_property -dict { PACKAGE_PIN R19   IOSTANDARD LVCMOS33 } [get_ports { HDMI_HPD }]; #IO_0_34 Sch=HDMI_TX_HDPN
# set_property -dict { PACKAGE_PIN M17   IOSTANDARD LVCMOS33 } [get_ports { HDMI_SCL }]; #IO_L8P_T1_AD10P_35 Sch=HDMI_TX_SCL
# set_property -dict { PACKAGE_PIN M18   IOSTANDARD LVCMOS33 } [get_ports { HDMI_SDA }]; #IO_L8N_T1_AD10N_35 Sch=HDMI_TX_SDA

###########
# SDRAM
# Outer ChipKit digital header: Address bus, clock, clock enable
set_property -dict {PACKAGE_PIN T14 IOSTANDARD LVCMOS33} [get_ports {sdram_a[0]}]
set_property -dict {PACKAGE_PIN U12 IOSTANDARD LVCMOS33} [get_ports {sdram_a[1]}]
set_property -dict {PACKAGE_PIN U13 IOSTANDARD LVCMOS33} [get_ports {sdram_a[2]}]
set_property -dict {PACKAGE_PIN V13 IOSTANDARD LVCMOS33} [get_ports {sdram_a[3]}]
set_property -dict {PACKAGE_PIN V15 IOSTANDARD LVCMOS33} [get_ports {sdram_a[4]}]
set_property -dict {PACKAGE_PIN T15 IOSTANDARD LVCMOS33} [get_ports {sdram_a[5]}]
set_property -dict {PACKAGE_PIN R16 IOSTANDARD LVCMOS33} [get_ports {sdram_a[6]}]
set_property -dict {PACKAGE_PIN U17 IOSTANDARD LVCMOS33} [get_ports {sdram_a[7]}]
set_property -dict {PACKAGE_PIN V17 IOSTANDARD LVCMOS33} [get_ports {sdram_a[8]}]
set_property -dict {PACKAGE_PIN V18 IOSTANDARD LVCMOS33} [get_ports {sdram_a[9]}]
set_property -dict {PACKAGE_PIN T16 IOSTANDARD LVCMOS33} [get_ports {sdram_a[10]}]
set_property -dict {PACKAGE_PIN R17 IOSTANDARD LVCMOS33} [get_ports {sdram_a[11]}]
set_property -dict {PACKAGE_PIN P18 IOSTANDARD LVCMOS33} [get_ports {sdram_a[12]}]
set_property -dict {PACKAGE_PIN N17 IOSTANDARD LVCMOS33} [get_ports sdram_cke]
set_property -dict {PACKAGE_PIN Y13 IOSTANDARD LVCMOS33} [get_ports clk_sdram]

# ChipKit Inner Digital Header: Data Bus
set_property -dict {PACKAGE_PIN U5 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[0]}]
set_property -dict {PACKAGE_PIN V5 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[1]}]
set_property -dict {PACKAGE_PIN V6 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[2]}]
set_property -dict {PACKAGE_PIN U7 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[3]}]
set_property -dict {PACKAGE_PIN V7 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[4]}]
set_property -dict {PACKAGE_PIN U8 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[5]}]
set_property -dict {PACKAGE_PIN V8 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[6]}]
set_property -dict {PACKAGE_PIN V10 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[7]}]
set_property -dict {PACKAGE_PIN W10 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[8]}]
set_property -dict {PACKAGE_PIN W6 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[9]}]
set_property -dict {PACKAGE_PIN Y6 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[10]}]
set_property -dict {PACKAGE_PIN Y7 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[11]}]
set_property -dict {PACKAGE_PIN W8 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[12]}]
set_property -dict {PACKAGE_PIN Y8 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[13]}]
set_property -dict {PACKAGE_PIN W9 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[14]}]
set_property -dict {PACKAGE_PIN Y9 IOSTANDARD LVCMOS33} [get_ports {sdram_dq[15]}]

# ChipKit Analog Header (as Digital I/O): SDRAM Control
set_property -dict {PACKAGE_PIN Y11 IOSTANDARD LVCMOS33} [get_ports sdram_we_n]
set_property -dict {PACKAGE_PIN Y12 IOSTANDARD LVCMOS33} [get_ports sdram_cas_n]
set_property -dict {PACKAGE_PIN W11 IOSTANDARD LVCMOS33} [get_ports sdram_ras_n]
set_property -dict {PACKAGE_PIN V11 IOSTANDARD LVCMOS33} [get_ports sdram_cs_n]
set_property -dict {PACKAGE_PIN T5 IOSTANDARD LVCMOS33} [get_ports {sdram_ba[0]}]
set_property -dict {PACKAGE_PIN U10 IOSTANDARD LVCMOS33} [get_ports {sdram_ba[1]}]
set_property -dict {PACKAGE_PIN F19 IOSTANDARD LVCMOS33} [get_ports {sdram_dqm[0]}]
set_property -dict {PACKAGE_PIN F20 IOSTANDARD LVCMOS33} [get_ports {sdram_dqm[1]}]

set_max_delay -datapath_only -from [all_registers] -to [get_ports clk_sdram] 4
set_max_delay -datapath_only -from [all_registers] -to [get_ports sdram_cke] 4
set_max_delay -datapath_only -from [all_registers] -to [get_ports sdram_cs_n] 4
set_max_delay -datapath_only -from [all_registers] -to [get_ports sdram_ras_n] 4
set_max_delay -datapath_only -from [all_registers] -to [get_ports sdram_cas_n] 4
set_max_delay -datapath_only -from [all_registers] -to [get_ports sdram_we_n] 4
set_max_delay -datapath_only -from [all_registers] -to [get_ports sdram_dqm] 4
set_max_delay -datapath_only -from [all_registers] -to [get_ports sdram_a] 4
set_max_delay -datapath_only -from [all_registers] -to [get_ports sdram_ba] 4
set_max_delay -datapath_only -from [all_registers] -to [get_ports sdram_dq] 4
set_max_delay -datapath_only -from [get_ports sdram_dq] 4

# set_property -dict { PACKAGE_PIN C20   IOSTANDARD LVCMOS33 } [get_ports { ck_a[8]  }]; #IO_L1P_T0_AD0P_35       Sch=AD0_P
# set_property -dict { PACKAGE_PIN B20   IOSTANDARD LVCMOS33 } [get_ports { ck_a[9]  }]; #IO_L1N_T0_AD0N_35       Sch=AD0_N
# set_property -dict { PACKAGE_PIN B19   IOSTANDARD LVCMOS33 } [get_ports { ck_a[10] }]; #IO_L2P_T0_AD8P_35       Sch=AD8_P
# set_property -dict { PACKAGE_PIN A20   IOSTANDARD LVCMOS33 } [get_ports { ck_a[11] }]; #IO_L2N_T0_AD8N_35       Sch=AD8_N

## ChipKit SPI
#set_property -dict { PACKAGE_PIN W15   IOSTANDARD LVCMOS33 } [get_ports { ck_miso }]; #IO_L10N_T1_34 Sch=CK_MISO
#set_property -dict { PACKAGE_PIN T12   IOSTANDARD LVCMOS33 } [get_ports { ck_mosi }]; #IO_L2P_T0_34  Sch=CK_MISO
#set_property -dict { PACKAGE_PIN H15   IOSTANDARD LVCMOS33 } [get_ports { ck_sck  }]; #IO_L19P_T3_35 Sch=CK_SCK
#set_property -dict { PACKAGE_PIN F16   IOSTANDARD LVCMOS33 } [get_ports { ck_ss   }]; #IO_L6P_T0_35  Sch=CK_SS

## ChipKit I2C
#set_property -dict { PACKAGE_PIN P16   IOSTANDARD LVCMOS33 } [get_ports { ck_scl }]; #IO_L24N_T3_34 Sch=CK_SCL
#set_property -dict { PACKAGE_PIN P15   IOSTANDARD LVCMOS33 } [get_ports { ck_sda }]; #IO_L24P_T3_34 Sch=CK_SDA

## Not Connected Pins
#set_property PACKAGE_PIN F17 [get_ports {netic20_f17}]; #IO_L6N_T0_VREF_35
#set_property PACKAGE_PIN G18 [get_ports {netic20_g18}]; #IO_L16N_T2_35



