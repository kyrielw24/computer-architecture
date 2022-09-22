`include "F.v"
`include "G.v"
`include "H.v"
`include "I.v"

module md5round (
    input [31:0]a,
    input [31:0]b,
    input [31:0]c,
    input [31:0]d,
    input [31:0]m,
    input [4:0]s,
    input [31:0]t,
    input [1:0]r,
    //在此定义了模块的运行输出结果 next_a
    output wire [31:0]next_a
);
// TODO: add code for calculating single round

//定义 uint32_t res = 0
reg [31:0] add_res

//定义FGHI单独的运算结果
reg [3:0][31:0] FGHI;

//建立指向
F f(.x(b), .y(c), .z(d), .res(FGHI[0]));
G g(.x(b), .y(c), .z(d), .res(FGHI[1]));
H h(.x(b), .y(c), .z(d), .res(FGHI[2]));
I i(.x(b), .y(c), .z(d), .res(FGHI[3]));

// add_res 计算结果
always@(*) begin
    case(r)
        0: add_res = a + FGHI[0] + m + t;
        1: add_res = a + FGHI[1] + m + t;
        2: add_res = a + FGHI[2] + m + t;
        3: add_res = a + FGHI[3] + m + t;
    endcase
end

assign next_a = b + (add_res<<s)|(add_res>>(32-s));

endmodule