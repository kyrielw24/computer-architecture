`timescale 1ns / 1ps
//*************************************************************************
//   > �ļ���: fetch.v
//   > ����  :�弶��ˮCPU��ȡָģ��
//   > ����  : LOONGSON
//   > ����  : 2016-04-14
//*************************************************************************
`define STARTADDR 32'H00000034   // ������ʼ��ַΪ34H
module fetch(                    // ȡָ��
    input             clk,       // ʱ��
    input             resetn,    // ��λ�źţ��͵�ƽ��Ч
    input             IF_valid,  // ȡָ����Ч�ź�
    input             next_fetch,// ȡ��һ��ָ���������PCֵ
    input      [31:0] inst,      // inst_romȡ����ָ��
    input      [32:0] jbr_bus,   // ��ת����
    output     [31:0] inst_addr, // ����inst_rom��ȡָ��ַ
    output reg        IF_over,   // IFģ��ִ�����
    output     [63:0] IF_ID_bus, // IF->ID����
    
    //5����ˮ�����ӿ�
    input      [32:0] exc_bus,   // Exception pc����
        
    //չʾPC��ȡ����ָ��
    output     [31:0] IF_pc,
    output     [31:0] IF_inst
    
//    output   D,
//    output   D1  
);

//-----{���������PC}begin
    wire [31:0] next_pc;
    wire [31:0] seq_pc;
    reg  [31:0] pc;
    
    // �ӳ�һ��cycle����
    reg  Delay = 1'b0;
    reg  Delay1 = 1'b0;
    
    //��תpc
    wire        jbr_taken;
    wire [31:0] jbr_target;
    assign {jbr_taken, jbr_target} = jbr_bus;  // ��ת���ߴ��Ƿ���ת��Ŀ���ַ
    
    //Exception PC
    wire        exc_valid;
    wire [31:0] exc_pc;
    assign {exc_valid,exc_pc} = exc_bus;
    
    //pc+4
    assign seq_pc[31:2]    = pc[31:2] + 1'b1;  // ��һָ���ַ��PC=PC+4
    assign seq_pc[1:0]     = pc[1:0];

    // ��ָ�����Exception,��PCΪExceptio��ڵ�ַ
    //         ��ָ����ת����PCΪ��ת��ַ������Ϊpc+4
    assign next_pc = exc_valid ? exc_pc : 
                     jbr_taken ? jbr_target : seq_pc;
    always @(posedge clk)    // PC���������
    begin
        if (!resetn)
        begin
            pc <= `STARTADDR; // ��λ��ȡ������ʼ��ַ
        end
        else if (next_fetch)
        begin
            pc <= next_pc;    // ����λ��ȡ��ָ��
        end
    end
    
    
//-----{���������PC}end

//-----{����inst_rom��ȡָ��ַ}begin
    assign inst_addr = pc;
//-----{����inst_rom��ȡָ��ַ}end

//-----{IFִ�����}begin
    //����ָ��romΪͬ����д��,
    //ȡ����ʱ����һ����ʱ
    //������ַ����һ��ʱ�Ӳ��ܵõ���Ӧ��ָ��
    //��ȡָģ����Ҫ����ʱ��
    //��ÿ��PCˢ�£�IF_over��Ҫ��0
    //Ȼ��IF_valid����һ�ļ���IF_over�ź�
//    always @(posedge clk)
//    begin
//        if (!resetn || next_fetch)
//        begin
//            IF_over <= 1'b0;
//        end
//        else
//        begin
//            IF_over <= IF_valid;
//        end
//    end
    
    always @(posedge clk)
    begin
        if (!resetn || next_fetch)
        begin
            IF_over <= 1'b0;
            Delay <= 1'b0;
        end
        else
        begin
            if(Delay == 1'b0)
                Delay = 1'b1;
            else
            begin
                IF_over <= IF_valid;
                Delay <= 1'b0;
            end
        end
    end

    always @(posedge clk)
    begin
        if (!resetn || next_fetch)
        begin
        end
        else
        begin
            if(Delay1 == 1'b0)
                Delay1 = 1'b1;
            else
            begin
                 Delay1 <= 1'b0;
            end
        end
    end


//    assign D = Delay;
//    assign D1 = Delay1;
    
    
    //���ָ��romΪ�첽���ģ���IF_valid����IF_over�źţ�
    //��ȡָһ�����
//-----{IFִ�����}end

//-----{IF->ID����}begin
    assign IF_ID_bus = {pc, inst};  // ȡָ����Чʱ������PC��ָ��
//-----{IF->ID����}end

//-----{չʾIFģ���PCֵ��ָ��}begin
    assign IF_pc   = pc;
    assign IF_inst = inst;
//-----{չʾIFģ���PCֵ��ָ��}end
endmodule