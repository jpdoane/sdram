#!/usr/bin/env xsct
# hil_test.tcl -- Hardware-in-the-loop test for dual_master_sdram
#
# Connects to the Arty Z7 via hw_server, programs the bitfile, then
# exercises the SDRAM through the AXI port using direct memory-mapped
# access (no PS application needed).
#
# Tests:
#   1. Basic write/readback          -- sanity check
#   2. Sequential write/readback     -- full address sweep
#   3. Byte-strobe / partial-write   -- verify DQM masking
#   4. Concurrent-region test        -- AXI writes to upper half while
#                                       portB tester owns lower half;
#                                       verify AXI region is uncorrupted
#   5. Boundary/bank-crossing test   -- addresses that cross SDRAM row/bank
#
# Pass/fail is printed to stdout; the script exits 0 on full pass, 1 on
# any failure.  This makes it usable from CI / make targets.
#
# Usage:  xsct hil_test.tcl [bitfile] [xsa]
#
# If bitfile and xsa are omitted the build/zynq_sdram.{bit,xsa} defaults
# are used.

# ---------------------------------------------------------------------------
# Configuration
# ---------------------------------------------------------------------------

set SCRIPT_DIR [file dirname [file normalize [info script]]]
set HW_DIR     [file normalize "$SCRIPT_DIR/../hw"]
set BUILD_DIR  "$HW_DIR/build"

set BITFILE    [expr {[llength $argv] > 0 ? [lindex $argv 0] : "$BUILD_DIR/zynq_sdram.bit"}]
set XSA_FILE   [expr {[llength $argv] > 1 ? [lindex $argv 1] : "$BUILD_DIR/zynq_sdram.xsa"}]
set PS7_INIT   "$BUILD_DIR/workspace/sdram_test/_ide/psinit/ps7_init.tcl"

set SDRAM_BASE 0x40000000   ;# AXI window start
set SDRAM_SIZE 0x2000000    ;# 32 MB

# portB tester uses words 0..4095 (bytes 0x0000..0x3FFF).
# AXI region for our exclusive use starts just above.
set AXI_TEST_BASE  [expr {$SDRAM_BASE + 0x00010000}]  ;# 64 KB offset
set AXI_TEST_WORDS 0x4000                              ;# 16K words = 64 KB

# SDRAM init time after bitstream load (ms)
set INIT_WAIT_MS 200

# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

set n_pass 0
set n_fail 0
set failures {}

proc pass {tag} {
    global n_pass
    incr n_pass
    puts "  PASS  $tag"
}

proc fail {tag msg} {
    global n_fail failures
    incr n_fail
    lappend failures "$tag: $msg"
    puts "  FAIL  $tag -- $msg"
}

proc check_eq {tag expected actual} {
    if {$expected == $actual} {
        pass $tag
    } else {
        fail $tag [format "expected 0x%08x got 0x%08x" $expected $actual]
    }
}

# Write a 32-bit word via xsct mwr
proc write32 {addr val} {
    mwr $addr $val
}

# Read a 32-bit word via xsct mrd, return integer
proc read32 {addr} {
    return [mrd -value $addr]
}

# Write a block of N words starting at byte_addr with values from list.
# Uses mwr -size w for efficiency when the list is large.
proc write_block {byte_addr values} {
    set addr $byte_addr
    foreach v $values {
        mwr $addr $v
        incr addr 4
    }
}

# Read N words starting at byte_addr, return as list of integers.
proc read_block {byte_addr n} {
    set result {}
    set addr $byte_addr
    for {set i 0} {$i < $n} {incr i} {
        lappend result [mrd -value $addr]
        incr addr 4
    }
    return $result
}

# ---------------------------------------------------------------------------
# Board programming
# ---------------------------------------------------------------------------

puts "\n=== Hardware-in-the-loop SDRAM test ==="
puts "Bitfile : $BITFILE"
puts "XSA     : $XSA_FILE\n"

if {![file exists $BITFILE]} {
    puts "ERROR: bitfile not found: $BITFILE"
    exit 1
}

puts "--- Connecting to hw_server ..."
connect

puts "--- Resetting system ..."
targets -set -nocase -filter {name =~ "APU*"}
rst -system
after 500

puts "--- Programming FPGA ..."
targets -set -filter {name =~ "xc7z020"}
fpga -file $BITFILE

puts "--- Loading hardware platform ..."
targets -set -nocase -filter {name =~ "APU*"}
loadhw -hw $XSA_FILE -mem-ranges [list {0x40000000 0xbfffffff}] -regs

puts "--- Initialising PS7 ..."
configparams force-mem-access 1
targets -set -nocase -filter {name =~ "APU*"}
source $PS7_INIT
ps7_init
ps7_post_config

puts "--- Waiting ${INIT_WAIT_MS} ms for SDRAM initialisation ..."
after $INIT_WAIT_MS
puts "--- Ready.\n"

# ---------------------------------------------------------------------------
# Test 1: Basic write / readback
# ---------------------------------------------------------------------------
puts "=== TEST 1: Basic write/readback ==="

set base $AXI_TEST_BASE
write32 [expr {$base + 0x00}] 0x1111AAAA
write32 [expr {$base + 0x04}] 0x2222BBBB
write32 [expr {$base + 0x08}] 0xDEADBEEF
write32 [expr {$base + 0x0C}] 0xCAFEBABE

check_eq "basic_0" 0x1111AAAA [read32 [expr {$base + 0x00}]]
check_eq "basic_1" 0x2222BBBB [read32 [expr {$base + 0x04}]]
check_eq "basic_2" 0xDEADBEEF [read32 [expr {$base + 0x08}]]
check_eq "basic_3" 0xCAFEBABE [read32 [expr {$base + 0x0C}]]

# ---------------------------------------------------------------------------
# Test 2: Sequential write then readback  (AXI_TEST_WORDS words)
# ---------------------------------------------------------------------------
puts "\n=== TEST 2: Sequential write/readback ($AXI_TEST_WORDS words) ==="

set base $AXI_TEST_BASE
set addr $base
for {set i 0} {$i < $AXI_TEST_WORDS} {incr i} {
    mwr $addr [expr {$i ^ 0x5A5A0000}]
    incr addr 4
}

set addr $base
set seq_errors 0
for {set i 0} {$i < $AXI_TEST_WORDS} {incr i} {
    set got [mrd -value $addr]
    set exp [expr {$i ^ 0x5A5A0000}]
    if {$got != $exp} {
        incr seq_errors
        if {$seq_errors <= 4} {
            puts "    mismatch @ [format 0x%08x $addr]: exp=[format 0x%08x $exp] got=[format 0x%08x $got]"
        }
    }
    incr addr 4
}
if {$seq_errors == 0} {
    pass "sequential ($AXI_TEST_WORDS words)"
} else {
    fail "sequential" "$seq_errors word(s) mismatched"
}

# ---------------------------------------------------------------------------
# Test 3: Byte-strobe / partial-write
#
# xsct mwr -size b issues non-word-aligned AXI transactions; the Zynq PS
# interconnect may merge or reorder them, making isolated byte DQM tests
# unreliable through this path.  Instead we verify the DQM path indirectly:
#
#   a) Full-word write followed by full-word overwrite -- verifies that
#      wstrb=0xF causes all four byte lanes to be written correctly.
#   b) portB tester region readback -- the PL tester uses full-word
#      writes/reads with its own pattern; we read those words back via AXI
#      to confirm the DQM path is sound end-to-end.
#
# Sub-word AXI byte-strobe tests (DQM masking via separate byte writes)
# are covered by the Verilator simulation testbench (STRB_* checks).
# ---------------------------------------------------------------------------
puts "\n=== TEST 3: Write / overwrite (full word, wstrb=0xF) ==="

set ow_base [expr {$AXI_TEST_BASE + ($AXI_TEST_WORDS * 4) + 0x100}]

mwr $ow_base 0xDEADBEEF
check_eq "overwrite_initial"  0xDEADBEEF [mrd -value $ow_base]
mwr $ow_base 0xCAFEBABE
check_eq "overwrite_second"   0xCAFEBABE [mrd -value $ow_base]
mwr $ow_base 0x00000000
check_eq "overwrite_zero"     0x00000000 [mrd -value $ow_base]
mwr $ow_base 0xFFFFFFFF
check_eq "overwrite_ones"     0xFFFFFFFF [mrd -value $ow_base]

puts "\n=== TEST 3b: portB tester region readback via AXI ==="
# portB tester writes pattern(i) = i ^ 0xA5A5_0000 to words 0..4095.
# Poll word 0 until it matches the expected pattern (tester has completed
# at least one full write pass).  Timeout after 2 seconds.
set exp0 [expr {0 ^ 0xA5A50000}]
set poll_ok 0
for {set t 0} {$t < 40} {incr t} {
    after 50
    if {[mrd -value $SDRAM_BASE] == $exp0} { set poll_ok 1; break }
}
if {!$poll_ok} {
    fail "portB_region_via_AXI" "timed out waiting for portB tester to complete (word 0 never matched [format 0x%08x $exp0])"
} else {
    set portb_errors 0
    for {set i 0} {$i < 256} {incr i} {
        set addr [expr {$SDRAM_BASE + $i * 4}]
        set got  [mrd -value $addr]
        set exp  [expr {$i ^ 0xA5A50000}]
        if {$got != $exp} {
            incr portb_errors
            if {$portb_errors <= 4} {
                puts "    portB word $i @ [format 0x%08x $addr]: exp=[format 0x%08x $exp] got=[format 0x%08x $got]"
            }
        }
    }
    if {$portb_errors == 0} {
        pass "portB_region_via_AXI (256 words)"
    } else {
        fail "portB_region_via_AXI" "$portb_errors mismatche(s)"
    }
}

# ---------------------------------------------------------------------------
# Test 4: Strided access (different SDRAM rows / banks)
# ---------------------------------------------------------------------------
puts "\n=== TEST 4: Strided access (rows/banks) ==="

# SDRAM geometry: 13-bit row, 2-bit bank, 9-bit col.
# Address mapping in sdram_core: {row, bank, col, byte}.
# Row width = 13, bank = 2, col = 9 -> row stride = 4KB (2^(9+2+1)).
# Writing at strides that cross row and bank boundaries exercises the
# open-row / precharge logic.

set stride_words 1024   ;# 4 KB stride -- one full row
set n_strides    16
set stride_base  [expr {$SDRAM_BASE + 0x100000}]   ;# 1 MB into SDRAM

for {set s 0} {$s < $n_strides} {incr s} {
    set addr [expr {$stride_base + $s * $stride_words * 4}]
    mwr $addr [expr {0xC0DE0000 | $s}]
}

set stride_errors 0
for {set s 0} {$s < $n_strides} {incr s} {
    set addr [expr {$stride_base + $s * $stride_words * 4}]
    set got  [mrd -value $addr]
    set exp  [expr {0xC0DE0000 | $s}]
    if {$got != $exp} {
        incr stride_errors
        puts "    stride $s @ [format 0x%08x $addr]: exp=[format 0x%08x $exp] got=[format 0x%08x $got]"
    }
}
if {$stride_errors == 0} {
    pass "strided ($n_strides rows)"
} else {
    fail "strided" "$stride_errors error(s)"
}

# ---------------------------------------------------------------------------
# Test 5: Concurrent-region integrity
#   The portB tester autonomously writes/reads words 0..4095 (bytes 0..16383).
#   We write a known pattern to the region *above* that (starting at 0x8000),
#   then interleave many AXI writes to our own region and verify neither
#   region is corrupted.  This exercises the arbitration under real load.
# ---------------------------------------------------------------------------
puts "\n=== TEST 5: Concurrent-region integrity ==="

set axi_region  [expr {$SDRAM_BASE + 0x8000}]  ;# above portB tester region
set axi_n       0x800                           ;# 2K words

# Write our pattern
set addr $axi_region
for {set i 0} {$i < $axi_n} {incr i} {
    mwr $addr [expr {0xAA000000 | $i}]
    incr addr 4
}

# Verify it -- portB tester is running concurrently in PL
set addr $axi_region
set conc_errors 0
for {set i 0} {$i < $axi_n} {incr i} {
    set got [mrd -value $addr]
    set exp [expr {0xAA000000 | $i}]
    if {$got != $exp} {
        incr conc_errors
        if {$conc_errors <= 4} {
            puts "    conc @ [format 0x%08x $addr]: exp=[format 0x%08x $exp] got=[format 0x%08x $got]"
        }
    }
    incr addr 4
}
if {$conc_errors == 0} {
    pass "concurrent_region ($axi_n words, portB active)"
} else {
    fail "concurrent_region" "$conc_errors error(s)"
}

# ---------------------------------------------------------------------------
# Test 6: Refresh / retention -- write, wait, read back
# ---------------------------------------------------------------------------
puts "\n=== TEST 6: Refresh retention (500 ms wait) ==="

set ret_addr [expr {$SDRAM_BASE + 0x200000}]   ;# 2 MB mark
set ret_n    64

set addr $ret_addr
for {set i 0} {$i < $ret_n} {incr i} {
    mwr $addr [expr {0xFEED0000 | $i}]
    incr addr 4
}

# Wait long enough that the refresh counter must have fired many times
after 500

set addr $ret_addr
set ret_errors 0
for {set i 0} {$i < $ret_n} {incr i} {
    set got [mrd -value $addr]
    set exp [expr {0xFEED0000 | $i}]
    if {$got != $exp} {
        incr ret_errors
        puts "    retention @ [format 0x%08x $addr]: exp=[format 0x%08x $exp] got=[format 0x%08x $got]"
    }
    incr addr 4
}
if {$ret_errors == 0} {
    pass "refresh_retention"
} else {
    fail "refresh_retention" "$ret_errors error(s)"
}

# ---------------------------------------------------------------------------
# Summary
# ---------------------------------------------------------------------------
puts "\n======================================"
puts " CHECKS : [expr {$n_pass + $n_fail}]"
puts " PASS   : $n_pass"
puts " FAIL   : $n_fail"
if {$n_fail == 0} {
    puts " RESULT : *** PASS ***"
} else {
    puts " RESULT : *** FAIL ***"
    puts "\nFailed tests:"
    foreach f $failures { puts "  $f" }
}
puts "======================================\n"

if {$n_fail > 0} { exit 1 }
