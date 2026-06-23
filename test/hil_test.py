#!/usr/bin/env python3
"""
hil_test.py -- Hardware-in-the-loop test for dual_master_sdram on Arty Z7.

Drives the Arty Z7 SDRAM via xsct (Xilinx Software Command-line Tool),
using xsct as a persistent subprocess controlled over stdin/stdout.
No PS application is required; all access is via AXI memory-mapped reads
and writes through the debug port with force-mem-access enabled.

Tests
-----
1. Basic write / readback
2. Sequential write / readback  (16 K words)
3. Full-word overwrite           (same address, multiple patterns)
4. portB tester region readback  (AXI reads of PL-written words)
5. Strided access                (crosses SDRAM rows and banks)
6. Concurrent-region integrity   (AXI + portB active simultaneously)
7. Refresh retention             (500 ms wait between write and read)

Usage
-----
    python3 hil_test.py [--bitfile PATH] [--xsa PATH] [--no-program]

Exit code 0 = all tests passed, 1 = one or more failures.
"""

import argparse
import os
import time
import sys
from pathlib import Path

# ---------------------------------------------------------------------------
# Paths
# ---------------------------------------------------------------------------

SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
INC_DIR  = os.path.normpath(os.path.join(SCRIPT_DIR, '..', 'inc'))
HW_DIR     = os.path.normpath(os.path.join(SCRIPT_DIR, '..', 'hw'))
BUILD_DIR  = os.path.join(HW_DIR, 'build')

DEFAULT_BITFILE = os.path.join(BUILD_DIR, 'zynq_sdram.bit')
DEFAULT_XSA     = os.path.join(BUILD_DIR, 'zynq_sdram.xsa')
DEFAULT_PS7        = os.path.join(BUILD_DIR, 'workspace', 'sdram_test',
                               '_ide', 'psinit', 'ps7_init.tcl')

sys.path.append(str(INC_DIR))
from xsct_utils import Xsct

# ---------------------------------------------------------------------------
# Memory map
# ---------------------------------------------------------------------------

SDRAM_BASE      = 0x40000000   # AXI window start
SDRAM_SIZE      = 0x02000000   # 32 MB

# portB tester uses words 0..N_TEST_WORDS-1 starting at SDRAM_BASE.
# N_TEST_WORDS=4096 -> bytes 0x0000..0x3FFF
PORTB_BASE      = SDRAM_BASE
PORTB_WORDS     = 4096

# AXI-exclusive test region starts above the portB zone.
AXI_TEST_BASE   = SDRAM_BASE + 0x0001_0000   # 64 KB offset
AXI_TEST_WORDS  = 0x4000                     # 16 K words = 64 KB

# portB pattern: word_index ^ 0xA5A5_0000  (matches portb_tester.sv)
def portb_pattern(i: int) -> int:
    return (i ^ 0xA5A5_0000) & 0xFFFF_FFFF

# AXI sequential pattern
def seq_pattern(i: int) -> int:
    return (i ^ 0x5A5A_0000) & 0xFFFF_FFFF

# SDRAM init + portB tester first-pass time at 50 MHz / DIV=24:
#   SDRAM startup: 100 µs
#   portB writes:  4096 words × 24 cycles × 20 ns = ~2 ms
#   portB reads:   ~2 ms
#   Total:         ~105 ms  -- use 300 ms to be safe
INIT_WAIT_S     = 0.30

# Timeout waiting for portB tester to complete one pass
PORTB_POLL_S    = 3.0

# ---------------------------------------------------------------------------
# Test runner
# ---------------------------------------------------------------------------

class TestRunner:
    def __init__(self):
        self.n_pass = 0
        self.n_fail = 0
        self.failures: list[str] = []

    def passed(self, tag: str, detail: str = ''):
        self.n_pass += 1
        suffix = f'  ({detail})' if detail else ''
        print(f'  PASS  {tag}{suffix}')

    def failed(self, tag: str, msg: str):
        self.n_fail += 1
        self.failures.append(f'{tag}: {msg}')
        print(f'  FAIL  {tag} -- {msg}')

    def check_eq(self, tag: str, expected: int, actual: int):
        if expected == actual:
            self.passed(tag)
        else:
            self.failed(tag, f'expected {expected:#010x}  got {actual:#010x}')

    def check_block(self, tag: str, base: int,
                    expected: list[int], actual: list[int],
                    max_report: int = 4) -> int:
        """Compare two word lists; return number of mismatches."""
        errors = 0
        for i, (exp, got) in enumerate(zip(expected, actual)):
            if exp != got:
                errors += 1
                if errors <= max_report:
                    addr = base + i * 4
                    print(f'    [{i}] {addr:#010x}  exp={exp:#010x}  got={got:#010x}')
        if errors == 0:
            self.passed(tag, f'{len(expected)} words')
        else:
            self.failed(tag, f'{errors} word(s) mismatched out of {len(expected)}')
        return errors

    def summary(self):
        total = self.n_pass + self.n_fail
        print()
        print('=' * 42)
        print(f' CHECKS : {total}')
        print(f' PASS   : {self.n_pass}')
        print(f' FAIL   : {self.n_fail}')
        if self.n_fail == 0:
            print(' RESULT : *** PASS ***')
        else:
            print(' RESULT : *** FAIL ***')
            print('\nFailed tests:')
            for f in self.failures:
                print(f'  {f}')
        print('=' * 42)
        return self.n_fail == 0

# ---------------------------------------------------------------------------
# Individual tests
# ---------------------------------------------------------------------------

def test_basic(xsct: Xsct, tr: TestRunner):
    print('\n=== TEST 1: Basic write / readback ===')
    cases = [
        (AXI_TEST_BASE + 0x00, 0x1111_AAAA),
        (AXI_TEST_BASE + 0x04, 0x2222_BBBB),
        (AXI_TEST_BASE + 0x08, 0xDEAD_BEEF),
        (AXI_TEST_BASE + 0x0C, 0xCAFE_BABE),
    ]
    for addr, val in cases:
        xsct.write32(addr, val)
    for i, (addr, val) in enumerate(cases):
        tr.check_eq(f'basic_{i}', val, xsct.read32(addr))


def test_sequential(xsct: Xsct, tr: TestRunner, n: int = AXI_TEST_WORDS):
    print(f'\n=== TEST 2: Sequential write / readback ({n:#x} words) ===')
    expected = [seq_pattern(i) for i in range(n)]
    xsct.write_block(AXI_TEST_BASE, expected)
    actual = xsct.read_block(AXI_TEST_BASE, n)
    tr.check_block('sequential', AXI_TEST_BASE, expected, actual)


def test_overwrite(xsct: Xsct, tr: TestRunner):
    print('\n=== TEST 3: Full-word overwrite ===')
    addr = AXI_TEST_BASE + AXI_TEST_WORDS * 4 + 0x100
    for tag, val in [
        ('overwrite_deadbeef', 0xDEAD_BEEF),
        ('overwrite_cafebabe', 0xCAFE_BABE),
        ('overwrite_zero',     0x0000_0000),
        ('overwrite_ones',     0xFFFF_FFFF),
    ]:
        xsct.write32(addr, val)
        tr.check_eq(tag, val, xsct.read32(addr))


def test_portb_region(xsct: Xsct, tr: TestRunner):
    """
    Poll the portB tester region until word 0 matches the expected pattern,
    then read back 256 words and verify them via AXI.

    The portB tester (running in PL on a ~2 MHz decimated clock) auto-starts
    after reset and writes pattern(i) = i ^ 0xA5A5_0000 to words 0..4095.
    """
    print('\n=== TEST 4: portB tester region readback via AXI ===')
    exp0 = portb_pattern(0)
    deadline = time.monotonic() + PORTB_POLL_S
    found = False
    polls = 0
    while time.monotonic() < deadline:
        if xsct.read32(PORTB_BASE) == exp0:
            found = True
            break
        time.sleep(0.05)
        polls += 1

    if not found:
        tr.failed('portB_region_via_AXI',
                  f'timed out ({PORTB_POLL_S:.0f}s) waiting for portB '
                  f'tester: word[0] never matched {exp0:#010x}  '
                  f'(bitfile may pre-date portb_tester RTL)')
        return

    n = 256
    expected = [portb_pattern(i) for i in range(n)]
    actual   = xsct.read_block(PORTB_BASE, n)
    tr.check_block('portB_region_via_AXI', PORTB_BASE, expected, actual)


def test_strided(xsct: Xsct, tr: TestRunner):
    """
    Write / read at 4 KB strides to exercise SDRAM row/bank switching
    (open-row cache misses, precharge, re-activate).
    """
    print('\n=== TEST 5: Strided access (rows / banks) ===')
    stride_words = 1024   # 4 KB per stride = one SDRAM row
    n_strides    = 16
    base         = SDRAM_BASE + 0x0010_0000   # 1 MB into SDRAM

    addrs    = [base + s * stride_words * 4 for s in range(n_strides)]
    expected = [0xC0DE_0000 | s            for s in range(n_strides)]

    for addr, val in zip(addrs, expected):
        xsct.write32(addr, val)
    errors = 0
    for i, (addr, exp) in enumerate(zip(addrs, expected)):
        got = xsct.read32(addr)
        if got != exp:
            errors += 1
            print(f'    stride {i} @ {addr:#010x}: exp={exp:#010x} got={got:#010x}')
    if errors == 0:
        tr.passed('strided', f'{n_strides} rows')
    else:
        tr.failed('strided', f'{errors} error(s)')


def test_concurrent(xsct: Xsct, tr: TestRunner):
    """
    Write AXI pattern to a region above the portB zone while portB is
    running, then verify the AXI region is uncorrupted.
    """
    print('\n=== TEST 6: Concurrent-region integrity ===')
    base = SDRAM_BASE + 0x0000_8000   # above portB zone (0..0x3FFF)
    n    = 0x800                       # 2 K words

    expected = [(0xAA00_0000 | i) & 0xFFFF_FFFF for i in range(n)]
    xsct.write_block(base, expected)
    actual = xsct.read_block(base, n)
    tr.check_block('concurrent_region', base, expected, actual)


def test_retention(xsct: Xsct, tr: TestRunner, wait_s: float = 0.5):
    """
    Write data, wait long enough for many SDRAM refresh cycles, read back.
    Verifies the refresh logic keeps data alive without corruption.
    """
    print(f'\n=== TEST 7: Refresh retention ({wait_s*1000:.0f} ms wait) ===')
    base = SDRAM_BASE + 0x0020_0000   # 2 MB mark
    n    = 64
    expected = [(0xFEED_0000 | i) & 0xFFFF_FFFF for i in range(n)]
    xsct.write_block(base, expected)
    time.sleep(wait_s)
    actual = xsct.read_block(base, n)
    tr.check_block('refresh_retention', base, expected, actual)


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(
        description='Hardware-in-the-loop SDRAM test for Arty Z7')
    parser.add_argument('--bitfile', default=DEFAULT_BITFILE,
                        help=f'Path to .bit file (default: {DEFAULT_BITFILE})')
    parser.add_argument('--xsa', default=DEFAULT_XSA,
                        help=f'Path to .xsa file (default: {DEFAULT_XSA})')
    parser.add_argument('--ps7', default=DEFAULT_PS7,
                        help=f'Path to ps7_init.tcl file (default: {DEFAULT_PS7})')
    parser.add_argument('--no-program', action='store_true',
                        help='Skip FPGA programming (board already configured)')
    parser.add_argument('--test', metavar='N', type=int, action='append',
                        help='Run only test N (1-7); may be repeated')
    args = parser.parse_args()

    print('\n=== Hardware-in-the-loop SDRAM test ===')
    print(f'Bitfile : {args.bitfile}')
    print(f'XSA     : {args.xsa}')
    print(f'PS7     : {args.ps7}')
    if args.no_program:
        print('Mode    : connect only (--no-program)')
    print()

    if not args.no_program:
        for path, name in [(args.bitfile, 'bitfile'), (args.xsa, 'xsa'),
                           (args.ps7, 'ps7_init')]:
            if not os.path.exists(path):
                print(f'ERROR: {name} not found: {path}')
                sys.exit(1)

    xsct = Xsct()
    tr   = TestRunner()

    try:
        if args.no_program:
            xsct.connect()
        else:
            xsct.program_board(args.bitfile, args.xsa, args.ps7)
            print(f'--- Waiting {INIT_WAIT_S*1000:.0f} ms for SDRAM init ...')
            time.sleep(INIT_WAIT_S)
            print('--- Ready.\n')

        run = args.test or list(range(1, 8))

        if 1 in run: test_basic(xsct, tr)
        if 2 in run: test_sequential(xsct, tr)
        if 3 in run: test_overwrite(xsct, tr)
        if 4 in run: test_portb_region(xsct, tr)
        if 5 in run: test_strided(xsct, tr)
        if 6 in run: test_concurrent(xsct, tr)
        if 7 in run: test_retention(xsct, tr)

    finally:
        xsct.close()

    ok = tr.summary()
    sys.exit(0 if ok else 1)


if __name__ == '__main__':
    main()
