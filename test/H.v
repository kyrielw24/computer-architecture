module H (
    input [31:0]x,
    input [31:0]y,
    input [31:0]z,
    output reg [31:0]r
);
always@(*) begin
    r = x ^ y ^ z;
end
endmodule