module I (
    input [31:0]x,
    input [31:0]y,
    input [31:0]z,
    output reg [31:0]r
);
always@(*) begin
    r = y ^ (x | (~z));
end
endmodule