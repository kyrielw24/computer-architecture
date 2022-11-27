-makelib ies/xil_defaultlib -sv \
  "D:/product_app/Xilinx/Vivado/2017.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
-endlib
-makelib ies/xpm \
  "D:/product_app/Xilinx/Vivado/2017.1/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib ies/blk_mem_gen_v8_3_6 \
  "../../../ipstatic/simulation/blk_mem_gen_v8_3.v" \
-endlib
-makelib ies/xil_defaultlib \
  "../../../../pipeline_cpu.srcs/sources_1/ip/inst_rom/sim/inst_rom.v" \
-endlib
-makelib ies/xil_defaultlib \
  glbl.v
-endlib

