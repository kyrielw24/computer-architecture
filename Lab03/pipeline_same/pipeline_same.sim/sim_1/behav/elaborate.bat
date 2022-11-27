@echo off
set xv_path=D:\\product_app\\Xilinx\\Vivado\\2017.1\\bin
call %xv_path%/xelab  -wto 33e25e35deed468c96c0904c5355f1ce -m64 --debug typical --relax --mt 2 -L blk_mem_gen_v8_3_6 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip -L xpm --snapshot tb_behav xil_defaultlib.tb xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
