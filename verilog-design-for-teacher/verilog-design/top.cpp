#include <bits/stdc++.h>
#include "verilated.h"
#include "Vmd5.h"
#include "verilated_types.h"
int main(int argc, char** argv, char** env) {
    std::unique_ptr<VerilatedContext> contextp {new VerilatedContext};
    contextp->commandArgs(argc, argv);
    std::unique_ptr<Vmd5> top {new Vmd5{contextp.get()}};
    
    // reset
    top->rst = 1;
    top->clk = 0;
    top->eval();
    top->clk = 1;
    top->eval();
    top->rst = 0;
    while (top->ready == 0) {
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();
    }

    top->in.at(0) = 0x3;
    top->in.at(1) = 0;
    top->in.at(2) = 0;
    top->in.at(3) = 0;
    top->in_valid = 1;

    while (top->out_valid == 0) {
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();
    }
    printf("0x%08x%08x%08x%08x\n", top->out.at(3), top->out.at(2),
           top->out.at(1), top->out.at(0));

    return 0;
}