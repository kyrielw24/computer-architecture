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
    output wire [31:0]next_a
);
    reg [31:0]add_res;
    assign next_a = b + ((add_res << s) | (add_res >> (32 - s)));
    reg [31:0]fres;
    reg [31:0]gres;
    reg [31:0]hres;
    reg [31:0]ires;
    F f(.x(b), .y(c), .z(d), .r(fres));
    G g(.x(b), .y(c), .z(d), .r(gres));
    H h(.x(b), .y(c), .z(d), .r(hres));
    I i(.x(b), .y(c), .z(d), .r(ires));
    always@(*) begin
        case(r)
            0: add_res = a + fres + m + t;
            1: add_res = a + gres + m + t;
            2: add_res = a + hres + m + t;
            3: add_res = a + ires + m + t;
        endcase
    end
endmodule