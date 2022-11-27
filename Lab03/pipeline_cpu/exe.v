`timescale 1ns / 1ps
//*************************************************************************
//   > 文件名: exe.v
//   > 描述  :五级流水CPU的执行模块
//   > 作者  : LOONGSON
//   > 日期  : 2016-04-14
//*************************************************************************
module exe(                         // 执行级
    input              EXE_valid,   // 执行级有效信号
    input      [178:0] ID_EXE_bus_r,// ID->EXE总线
    output             EXE_over,    // EXE模块执行完成
    output     [153:0] EXE_MEM_bus, // EXE->MEM总线
    
     //5级流水新增
    input             clk,       // 时钟
    output     [  4:0] EXE_wdest,   // EXE级要写回寄存器堆的目标地址号
    input      [  4:0] MEM_wdest,   // MEM级要写回寄存器堆的目标地址号
    input      [  4:0] WB_wdest,    // WB级要写回寄存器堆的目标地址号
    input      [ 31:0] MEM_result,
    input      [ 31:0] WB_result, 
    output      [31:0] O1,
    output      [31:0] O2,
    output      [31:0] EXE_O,
    
    //展示PC
    output     [ 31:0] EXE_pc
);
//-----{ID->EXE总线}begin
    //EXE需要用到的信息
    wire multiply;            //乘法
    wire mthi;             //MTHI
    wire mtlo;             //MTLO
    wire [11:0] alu_control;
    wire [31:0] alu_operand1;
    wire [31:0] alu_operand2;

    //访存需要用到的load/store信息
    wire [3:0] mem_control;  //MEM需要使用的控制信号
    wire [31:0] store_data;  //store操作的存的数据
                          
    //写回需要用到的信息
    wire mfhi;
    wire mflo;
    wire mtc0;
    wire mfc0;
    wire [7 :0] cp0r_addr;
    wire       syscall;   //syscall和eret在写回级有特殊的操作 
    wire       eret;
    wire [4:0] rs;
    wire [4:0] rt;
    wire inst_no_rs;
    wire inst_no_rt;
    wire       rf_wen;    //写回的寄存器写使能
    wire [4:0] rf_wdest;  //写回的目的寄存器
    
    //pc
    wire [31:0] pc;
    assign {multiply,
            mthi,
            mtlo,
            alu_control,
            alu_operand1,
            alu_operand2,
            mem_control,
            store_data,
            mfhi,
            mflo,
            mtc0,
            mfc0,
            cp0r_addr,
            syscall,
            eret,
            rs,
            rt,
            inst_no_rs,
            inst_no_rt,
            rf_wen,
            rf_wdest,
            pc          } = ID_EXE_bus_r;
//-----{ID->EXE总线}end

    wire rs_wait_m;
    wire rt_wait_m;
    wire rs_wait_w;
    wire rt_wait_w;
    wire  [31:0] operand1;
    wire  [31:0] operand2;
    assign rs_wait_m = (rs!=5'd0) & (rs==MEM_wdest);
    assign rt_wait_m = (rt!=5'd0) & (rt==MEM_wdest);
    assign rs_wait_w = (rs!=5'd0) & (rs==WB_wdest);
    assign rt_wait_w = (rt!=5'd0) & (rt==WB_wdest);
    assign O1 = operand1;
    assign O2 = operand2;
    assign operand1 = inst_no_rs ? alu_operand1 : (rs_wait_m ? MEM_result : (rs_wait_w ? WB_result : alu_operand1));
    assign operand2 = inst_no_rt ? alu_operand2 : (rt_wait_m ? MEM_result : (rt_wait_w ? WB_result : alu_operand2));
//    always @(posedge clk)
//    begin
//        if(rs_wait==1'b1)
//        begin
//            operand1 <= MEM_result;
//        end
//        if(rt_wait==1'b1)
//        begin
//            operand2 <= MEM_result;
//        end
//    end

//-----{ALU}begin
    wire [31:0] alu_result;

    alu alu_module(
        .alu_control  (alu_control ),  // I, 12, ALU控制信号
//        .alu_src1     (alu_operand1),  // I, 32, ALU操作数1
        .alu_src1     (operand1),  // I, 32, ALU操作数1
//        .alu_src2     (alu_operand2),  // I, 32, ALU操作数2
        .alu_src2     (operand2),
        .alu_result   (alu_result  )   // O, 32, ALU结果
    );
//-----{ALU}end

//-----{乘法器}begin
    wire        mult_begin; 
    wire [63:0] product; 
    wire        mult_end;
    
    assign mult_begin = multiply & EXE_valid;
    multiply multiply_module (
        .clk       (clk       ),
        .mult_begin(mult_begin  ),
//        .mult_op1  (alu_operand1), 
        .mult_op1  (operand1), 
//        .mult_op2  (alu_operand2),
        .mult_op2  (operand2),
        .product   (product   ),
        .mult_end  (mult_end  )
    );
//-----{乘法器}end

//-----{EXE执行完成}begin
    //对于ALU操作，都是1拍可完成，
    //但对于乘法操作，需要多拍完成
    assign EXE_over = EXE_valid & (~multiply | mult_end) ;
//-----{EXE执行完成}end

//-----{EXE模块的dest值}begin
   //只有在EXE模块有效时，其写回目的寄存器号才有意义
    assign EXE_wdest = rf_wdest & {5{EXE_valid}};
//-----{EXE模块的dest值}end

//-----{EXE->MEM总线}begin
    wire [31:0] exe_result;   //在exe级能确定的最终写回结果
    assign EXE_O = exe_result;
    wire [31:0] lo_result;
    wire        hi_write;
    wire        lo_write;
    //要写入HI的值放在exe_result里，包括MULT和MTHI指令,
    //要写入LO的值放在lo_result里，包括MULT和MTLO指令,
    assign exe_result = mthi     ? alu_operand1 :
                        mtc0     ? alu_operand2 : 
                        multiply ? product[63:32] : alu_result;
    assign lo_result  = mtlo ? alu_operand1 : product[31:0];
    assign hi_write   = multiply | mthi;
    assign lo_write   = multiply | mtlo;
    
    assign EXE_MEM_bus = {mem_control,store_data,          //load/store信息和store数据
                          exe_result,                      //exe运算结果
                          lo_result,                       //乘法低32位结果，新增
                          hi_write,lo_write,               //HI/LO写使能，新增
                          mfhi,mflo,                       //WB需用的信号,新增
                          mtc0,mfc0,cp0r_addr,syscall,eret,//WB需用的信号,新增
                          rf_wen,rf_wdest,                 //WB需用的信号
                          pc};                             //PC
//-----{EXE->MEM总线}end

//-----{展示EXE模块的PC值}begin
    assign EXE_pc = pc;
//-----{展示EXE模块的PC值}end
endmodule
