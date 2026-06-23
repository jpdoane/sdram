#!/usr/bin/env python3
"""
Python wrapper for xsct (Xilinx Software Command-line Tool),
using xsct as a persistent subprocess controlled over stdin/stdout.
"""

import subprocess

XSCT_SENTINEL = '__XSCT_DONE__'

class Xsct:
    """
    Persistent xsct subprocess controlled over stdin/stdout.
    Commands are sent as Tcl; responses are read until the sentinel line.
    """

    def __init__(self,
                 ps_name = "APU*",
                 pl_name = "xc7z*",
                 mem_range_start = 0x40000000,
                 mem_range_stop = 0xbfffffff,
                 ):
        self.ps_name = ps_name
        self.pl_name = pl_name
        self.mem_range = [mem_range_start, mem_range_stop]

        self._proc = subprocess.Popen(
            ['xsct'],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.DEVNULL,   # suppress Xilinx banner noise
            text=True,
            bufsize=1,
        )
        # Flush the startup banner by sending a no-op and waiting for sentinel
        self._send_raw(f'puts {XSCT_SENTINEL}')
        self._collect()

    def __del__(self):
        self.close()

    def _send_raw(self, tcl: str):
        self._proc.stdin.write(tcl + '\n')
        self._proc.stdin.flush()

    def _collect(self) -> list[str]:
        """Read lines until sentinel; return lines before it."""
        lines = []
        while True:
            line = self._proc.stdout.readline()
            if not line:
                raise RuntimeError('xsct process died unexpectedly')
            line = line.rstrip('\n')
            if line == XSCT_SENTINEL:
                break
            lines.append(line)
        return lines

    def run(self, tcl: str) -> list[str]:
        """Execute a Tcl snippet; return output lines."""
        # Wrap in a catch so errors don't kill the session
        wrapped = (
            f'if {{[catch {{{tcl}}} _err]}} {{\n'
            f'    puts "XSCT_ERROR: $_err"\n'
            f'}}\n'
            f'puts {XSCT_SENTINEL}'
        )
        self._send_raw(wrapped)
        lines = self._collect()
        for line in lines:
            if line.startswith('XSCT_ERROR:'):
                raise RuntimeError(f'xsct: {line}')
        return lines

    def eval(self, tcl: str) -> str:
        """Execute Tcl and return the single-line result (stripped)."""
        lines = self.run(tcl)
        return lines[0].strip() if lines else ''

    def close(self):
        try:
            self._send_raw('exit')
        except Exception:
            pass
        self._proc.wait(timeout=5)

    # ---------------------------------------------------------------------------
    # Board setup
    # ---------------------------------------------------------------------------

    def connect(self):
        self.run('connect')
        self.set_target_ps()
        self.run('configparams force-mem-access 1')

    def set_target(self, name_glob: str):
        self.run(f'targets -set -nocase -filter {{name =~ "{name_glob}"}}')

    def set_target_ps(self):
        self.set_target(self.ps_name)

    def set_target_pl(self):
        self.set_target(self.pl_name)

    def wait_ms(self, delay_ms):
        self.run(f'after {delay_ms}')

    def reset(self):
        self.set_target_ps()
        self.run('rst -system')

    def init_ps(self, ps7_initfile: str):
        self.set_target_ps()
        self.run(f'source {{{ps7_initfile}}}')
        self.run('ps7_init')
        self.run('ps7_post_config')

    def program_board(self, bitfile: str, xsa: str, ps7_initfile: str):
        print('--- Connecting to hw_server ...')
        self.connect()

        print('--- Resetting system ...')
        self.reset()
        self.wait_ms(500)

        print('--- Programming FPGA ...')
        self.set_target_pl()
        self.run(f'fpga -file {{{bitfile}}}')

        print('--- Loading hardware platform ...')
        self.set_target_ps()
        self.run(f'loadhw -hw {{{xsa}}} -mem-ranges [list {{{self.mem_range[0]} {self.mem_range[-1]}}}] -regs')
        # self.run(f'loadhw -hw {{{xsa}}}')
        self.run('configparams force-mem-access 1')

        print('--- Initialising PS7 ...')
        self.init_ps(ps7_initfile)

    # ------------------------------------------------------------------
    # direct memory access functions
    # ------------------------------------------------------------------

    def write32(self, addr: int, value: int):
        self.run(f'mwr {addr:#010x} {value:#010x}')

    def read32(self, addr: int) -> int:
        raw = self.eval(f'puts [mrd -value {addr:#010x}]')
        return int(raw)

    def write_block(self, base: int, values: list[int]):
        """Write a list of 32-bit words starting at base.
        Batched into chunks to avoid huge Tcl scripts."""
        chunk = 128
        addr = base
        for i in range(0, len(values), chunk):
            lines = []
            for v in values[i:i + chunk]:
                lines.append(f'mwr {addr:#010x} {v:#010x}')
                addr += 4
            self.run('\n'.join(lines))

    def read_block(self, base: int, n: int) -> list[int]:
        """Read n 32-bit words starting at base, return as list of ints.
        Uses 'puts [mrd -value addr count]' which returns space-separated
        values on a single line; batched to avoid buffer overflows."""
        chunk = 256
        results = []
        addr = base
        remaining = n
        while remaining > 0:
            count = min(chunk, remaining)
            raw = self.eval(f'puts [mrd -value {addr:#010x} {count}]')
            for tok in raw.split():
                results.append(int(tok))
            addr += count * 4
            remaining -= count
        return results