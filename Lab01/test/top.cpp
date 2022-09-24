#include <bits/stdc++.h>
#include "verilated.h"
#include "Vmd5.h"
int main(int argc, char** argv, char** env) {

    std::unique_ptr<Vmd5> top {new Vmd5};
    
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

    top->in[0] = 0x3;
    top->in[1] = 0;
    top->in[2] = 0;
    top->in[3] = 0;
    top->in_valid = 1;

    while (top->out_valid == 0) {
        top->clk = 0;
        top->eval();
        top->clk = 1;
        top->eval();
    }
    printf("0x%08x%08x%08x%08x\n", top->out[3], top->out[2],
           top->out[1], top->out[0]);

    return 0;
}
