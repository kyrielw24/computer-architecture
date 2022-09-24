# Verilated -*- CMake -*-
# DESCRIPTION: Verilator output: CMake include script with class lists
#
# This CMake script lists generated Verilated files, for including in higher level CMake scripts.
# This file is meant to be consumed by the verilate() function,
# which becomes available after executing `find_package(verilator).

### Constants...
set(PERL "perl" CACHE FILEPATH "Perl executable (from $PERL)")
set(VERILATOR_ROOT "/usr/share/verilator" CACHE PATH "Path to Verilator kit (from $VERILATOR_ROOT)")

### Compiler flags...
# User CFLAGS (from -CFLAGS on Verilator command line)
set(Vmd5_USER_CFLAGS )
# User LDLIBS (from -LDFLAGS on Verilator command line)
set(Vmd5_USER_LDLIBS )

### Switches...
# SystemC output mode?  0/1 (from --sc)
set(Vmd5_SC 0)
# Coverage output mode?  0/1 (from --coverage)
set(Vmd5_COVERAGE 0)
# Threaded output mode?  0/1/N threads (from --threads)
set(Vmd5_THREADS 0)
# VCD Tracing output mode?  0/1 (from --trace)
set(Vmd5_TRACE_VCD 0)
# FST Tracing output mode? 0/1 (from --fst-trace)
set(Vmd5_TRACE_FST 0)

### Sources...
# Global classes, need linked once per executable
set(Vmd5_GLOBAL "${VERILATOR_ROOT}/include/verilated.cpp")
# Generated module classes, non-fast-path, compile with low/medium optimization
set(Vmd5_CLASSES_SLOW )
# Generated module classes, fast-path, compile with highest optimization
set(Vmd5_CLASSES_FAST "/home/kyrie/computer-architecture/Lab01/verilog-design-for-student/verilog-design/build/CMakeFiles/TestBench.dir/Vmd5.dir/Vmd5.cpp" "/home/kyrie/computer-architecture/Lab01/verilog-design-for-student/verilog-design/build/CMakeFiles/TestBench.dir/Vmd5.dir/Vmd5___024unit.cpp")
# Generated support classes, non-fast-path, compile with low/medium optimization
set(Vmd5_SUPPORT_SLOW "/home/kyrie/computer-architecture/Lab01/verilog-design-for-student/verilog-design/build/CMakeFiles/TestBench.dir/Vmd5.dir/Vmd5__Syms.cpp")
# Generated support classes, fast-path, compile with highest optimization
set(Vmd5_SUPPORT_FAST )
# All dependencies
set(Vmd5_DEPS "/usr/bin/verilator_bin" "F.v" "G.v" "H.v" "I.v" "defs.v" "md5.v" "md5round.v")
# User .cpp files (from .cpp's on Verilator command line)
set(Vmd5_USER_CLASSES )
