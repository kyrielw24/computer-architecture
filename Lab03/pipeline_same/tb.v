`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:57:16 04/23/2016
// Design Name:   pipeline_cpu
// Module Name:   F:/new_lab/8_pipeline_cpu/tb.v
// Project Name:  pipeline_cpu
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: pipeline_cpu
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module tb;

    // Inputs
    reg clk;
    reg resetn;
    reg [4:0] rf_addr;
    reg [31:0] mem_addr;

    // Outputs
    wire [31:0] rf_data;
    wire [31:0] mem_data;
    wire [31:0] IF_pc;
    wire [31:0] IF_inst;
    wire [31:0] ID_pc;
    wire [31:0] EXE_pc;
    wire [31:0] MEM_pc;
    wire [31:0] WB_pc;
    wire [31:0] cpu_5_valid;
    
    wire F_Over;
    wire F_Valid;
//    wire D;
//    wire D1;
    wire D_Over;
    wire D_Valid;
    wire E_Over;
    wire E_Valid;
    wire M_Over;
    wire M_Valid;
    wire W_Over;
    wire W_Valid;
    wire w_delay;
    wire [31:0] O1;
    wire [31:0] O2;
    wire [31:0] EXE_O;
    wire [31:0] M_S;
    wire [31:0] W_S;
    wire [ 4:0] E_d;
    wire [ 4:0] M_d;
    wire [ 4:0] W_d;
    wire [ 4:0] rs;
    wire [ 4:0] rt;   
    wire [31:0] rs_value;
    wire [31:0] rt_value;

    // Instantiate the Unit Under Test (UUT)
    pipeline_cpu uut (
        .clk(clk), 
        .resetn(resetn), 
        .rf_addr(rf_addr), 
        .mem_addr(mem_addr), 
        .rf_data(rf_data), 
        .mem_data(mem_data), 
        .IF_pc(IF_pc), 
        .IF_inst(IF_inst), 
        .ID_pc(ID_pc), 
        .EXE_pc(EXE_pc), 
        .MEM_pc(MEM_pc), 
        .WB_pc(WB_pc), 
        .cpu_5_valid(cpu_5_valid),
        
        .F_Over(F_Over),
        .F_Valid(F_Valid),
//        .D(D),
//        .D1(D1),
        .D_Over(D_Over),
        .D_Valid(D_Valid),
        .E_Over(E_Over),
        .E_Valid(E_Valid),
        .M_Over(M_Over),
        .M_Valid(M_Valid),
        .W_Over(W_Over),
        .W_Valid(W_Valid),
        .w_delay(w_delay),
        .O1(O1),
        .O2(O2),
        .EXE_O(EXE_O),
        .M_S(M_S),
        .W_S(W_S),
        .E_d(E_d),
        .M_d(M_d),
        .W_d(W_d),
        .rs(rs),
        .rt(rt),
        .rs_value(rs_value),
        .rt_value(rt_value)
        
    );

    initial begin
        // Initialize Inputs
        clk = 0;
        resetn = 0;
        rf_addr = 0;
        mem_addr = 0;

        // Wait 100 ns for global reset to finish
        #100;
      resetn = 1;
        // Add stimulus here
    end
   always #5 clk=~clk;
endmodule

