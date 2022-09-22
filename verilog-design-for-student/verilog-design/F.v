module F (
    input [31:0]x,
    input [31:0]y,
    input [31:0]z,
    output reg [31:0]res
);
always@(*) 
    begin
        res = (x & y) | ((~x) & z);
    end
endmodule