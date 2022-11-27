`timescale 1ns / 1ps
//*************************************************************************
//   > �ļ���: exe.v
//   > ����  :�弶��ˮCPU��ִ��ģ��
//   > ����  : LOONGSON
//   > ����  : 2016-04-14
//*************************************************************************
module exe(                         // ִ�м�
    input              EXE_valid,   // ִ�м���Ч�ź�
    input      [178:0] ID_EXE_bus_r,// ID->EXE����
    output             EXE_over,    // EXEģ��ִ�����
    output     [153:0] EXE_MEM_bus, // EXE->MEM����
    
     //5����ˮ����
    input             clk,       // ʱ��
    output     [  4:0] EXE_wdest,   // EXE��Ҫд�ؼĴ����ѵ�Ŀ���ַ��
    input      [  4:0] MEM_wdest,   // MEM��Ҫд�ؼĴ����ѵ�Ŀ���ַ��
    input      [  4:0] WB_wdest,    // WB��Ҫд�ؼĴ����ѵ�Ŀ���ַ��
    input      [ 31:0] MEM_result,
    input      [ 31:0] WB_result, 
    output      [31:0] O1,
    output      [31:0] O2,
    output      [31:0] EXE_O,
    
    //չʾPC
    output     [ 31:0] EXE_pc
);
//-----{ID->EXE����}begin
    //EXE��Ҫ�õ�����Ϣ
    wire multiply;            //�˷�
    wire mthi;             //MTHI
    wire mtlo;             //MTLO
    wire [11:0] alu_control;
    wire [31:0] alu_operand1;
    wire [31:0] alu_operand2;

    //�ô���Ҫ�õ���load/store��Ϣ
    wire [3:0] mem_control;  //MEM��Ҫʹ�õĿ����ź�
    wire [31:0] store_data;  //store�����Ĵ������
                          
    //д����Ҫ�õ�����Ϣ
    wire mfhi;
    wire mflo;
    wire mtc0;
    wire mfc0;
    wire [7 :0] cp0r_addr;
    wire       syscall;   //syscall��eret��д�ؼ�������Ĳ��� 
    wire       eret;
    wire [4:0] rs;
    wire [4:0] rt;
    wire inst_no_rs;
    wire inst_no_rt;
    wire       rf_wen;    //д�صļĴ���дʹ��
    wire [4:0] rf_wdest;  //д�ص�Ŀ�ļĴ���
    
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
//-----{ID->EXE����}end

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
        .alu_control  (alu_control ),  // I, 12, ALU�����ź�
//        .alu_src1     (alu_operand1),  // I, 32, ALU������1
        .alu_src1     (operand1),  // I, 32, ALU������1
//        .alu_src2     (alu_operand2),  // I, 32, ALU������2
        .alu_src2     (operand2),
        .alu_result   (alu_result  )   // O, 32, ALU���
    );
//-----{ALU}end

//-----{�˷���}begin
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
//-----{�˷���}end

//-----{EXEִ�����}begin
    //����ALU����������1�Ŀ���ɣ�
    //�����ڳ˷���������Ҫ�������
    assign EXE_over = EXE_valid & (~multiply | mult_end) ;
//-----{EXEִ�����}end

//-----{EXEģ���destֵ}begin
   //ֻ����EXEģ����Чʱ����д��Ŀ�ļĴ����Ų�������
    assign EXE_wdest = rf_wdest & {5{EXE_valid}};
//-----{EXEģ���destֵ}end

//-----{EXE->MEM����}begin
    wire [31:0] exe_result;   //��exe����ȷ��������д�ؽ��
    assign EXE_O = exe_result;
    wire [31:0] lo_result;
    wire        hi_write;
    wire        lo_write;
    //Ҫд��HI��ֵ����exe_result�����MULT��MTHIָ��,
    //Ҫд��LO��ֵ����lo_result�����MULT��MTLOָ��,
    assign exe_result = mthi     ? alu_operand1 :
                        mtc0     ? alu_operand2 : 
                        multiply ? product[63:32] : alu_result;
    assign lo_result  = mtlo ? alu_operand1 : product[31:0];
    assign hi_write   = multiply | mthi;
    assign lo_write   = multiply | mtlo;
    
    assign EXE_MEM_bus = {mem_control,store_data,          //load/store��Ϣ��store����
                          exe_result,                      //exe������
                          lo_result,                       //�˷���32λ���������
                          hi_write,lo_write,               //HI/LOдʹ�ܣ�����
                          mfhi,mflo,                       //WB���õ��ź�,����
                          mtc0,mfc0,cp0r_addr,syscall,eret,//WB���õ��ź�,����
                          rf_wen,rf_wdest,                 //WB���õ��ź�
                          pc};                             //PC
//-----{EXE->MEM����}end

//-----{չʾEXEģ���PCֵ}begin
    assign EXE_pc = pc;
//-----{չʾEXEģ���PCֵ}end
endmodule
