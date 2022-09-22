`include "md5round.v"
`include "defs.v"

integer i;

module md5 (
    input clk,
    input rst,
    input [127:0]in,
    input in_valid,

    output reg [127:0]out,
    output reg out_valid,
    output reg ready
);
    reg [31:0] A;
    reg [31:0] B;
    reg [31:0] C;
    reg [31:0] D;
    reg [31:0] AA;
    reg [31:0] BB;
    reg [31:0] CC;
    reg [31:0] DD;
    reg [31:0] next_A;
    reg [31:0] next_B;
    reg [31:0] next_C;
    reg [31:0] next_D;

    reg [3:0] phase;
    reg [7:0] state;
    reg [7:0] next_state;

    reg [511:0] msg;
    reg out_r;
    reg [31:0]r_a;
    reg [31:0]r_b;
    reg [31:0]r_c;
    reg [31:0]r_d;
    reg [31:0]r_m;
    reg [4:0] r_s;
    reg [31:0]r_t;
    reg[1:0] r_r;
    reg [31:0] r_out;
    md5round round(.a(r_a), .b(r_b), .c(r_c), .d(r_d), .m(r_m), .s(r_s), .t(r_t), .r(r_r), .next_a(r_out));
    reg [31:0] cya;
    reg [31:0] cyb;
    reg [31:0] cyc;
    reg [31:0] cyd;
    always@(posedge clk) begin
        if(rst) begin
            A <= `A_INIT;
            B <= `B_INIT;
            C <= `C_INIT;
            D <= `D_INIT;
            state <= (1 << `idle);
            AA <= 0;
            BB <= 0;
            CC <= 0;
            DD <= 0;
            phase <= 0;
            msg <= 0;
            out_r <= 0;
        end else begin
            out_r <= state[`finished];
            state <= next_state;
            if (next_state[`idle]) begin
                AA <= 0;
                BB <= 0;
                CC <= 0;
                DD <= 0;
            end else if(next_state[`r0] && state[`idle]) begin
                AA <= A;
                BB <= B;
                CC <= C;
                DD <= D;
            end

            if (next_state[`idle]) begin
                A <= `A_INIT;
                B <= `B_INIT;
                C <= `C_INIT;
                D <= `D_INIT;
            end else begin
                A <= next_A;
                B <= next_B;
                C <= next_C;
                D <= next_D;
            end

            if (next_state[`r0] && state[`idle]) begin
                phase <= 0;
            end else begin
                phase <= phase + 1;
            end

            if (next_state[`idle]) begin
                msg <= 0;
            end else if (next_state[`r0] && state[`idle]) begin
                msg <= {in, in, in, in};
            end
        end
    end

    always@(*) begin
        next_A = A;
        next_B = B;
        next_C = C;
        next_D = D;
        next_state = state;
        r_a = 0;
        r_b = 0;
        r_c = 0;
        r_d = 0;
        r_m = 0;
        r_s = 0;
        r_t = 0;
        r_r = 0;
        cya = 0;
        cyb = 0;
        cyc = 0;
        cyd = 0;
        out_valid = out_r;
        ready = state[`idle];
        out = {A, B, C, D};
        case(phase[1:0])
            0: begin
                cya = A;
                cyb = B;
                cyc = C;
                cyd = D;
            end
            1: begin
                cya = D;
                cyb = A;
                cyc = B;
                cyd = C;
            end
            2: begin
                cya = C;
                cyb = D;
                cyc = A;
                cyd = B;
            end
            3: begin
                cya = B;
                cyb = C;
                cyc = D;
                cyd = A;
            end
        endcase
        if (state[`idle]) begin
            if (in_valid) begin
                next_state = (1 << `r0);
            end
        end

        if (state[`r0]) begin
            r_r = 0;
            case(phase[1:0])
                0: next_A = r_out;
                1: next_D = r_out;
                2: next_C = r_out;
                3: next_B = r_out;
            endcase
            r_a = cya;
            r_b = cyb;
            r_c = cyc;
            r_d = cyd;
            r_m = msg[(phase*32+31)-:32];
            r_s = S[{2'h0, phase}][4:0];
            r_t = K[{2'h0, phase}];
            if (phase == 4'b1111) next_state = (1 << `r1);
        end

        if (state[`r1]) begin
            r_r = 1;
            case(phase[1:0])
                0: next_A = r_out;
                1: next_D = r_out;
                2: next_C = r_out;
                3: next_B = r_out;
            endcase
            r_a = cya;
            r_b = cyb;
            r_c = cyc;
            r_d = cyd;
            r_m = msg[({phase[0], phase[3:1]}*32+31)-:32];
            r_s = S[{2'h1, phase}][4:0];
            r_t = K[{2'h1, phase}];
            if (phase == 4'b1111) next_state = (1 << `r2);
        end
        if (state[`r2]) begin
            r_r = 2;
            case(phase[1:0])
                0: next_A = r_out;
                1: next_D = r_out;
                2: next_C = r_out;
                3: next_B = r_out;
            endcase
            r_a = cya;
            r_b = cyb;
            r_c = cyc;
            r_d = cyd;
            r_m = msg[({phase[1:0], phase[3:2]}*32+31)-:32];
            r_s = S[{2'h2, phase}][4:0];
            r_t = K[{2'h2, phase}];
            if (phase == 4'b1111) next_state = (1 << `r3);
        end
        if (state[`r3]) begin
            r_r = 3;
            case(phase[1:0])
                0: next_A = r_out;
                1: next_D = r_out;
                2: next_C = r_out;
                3: next_B = r_out;
            endcase
            r_a = cya;
            r_b = cyb;
            r_c = cyc;
            r_d = cyd;
            r_m = msg[({phase[2:0], phase[3]}*32+31)-:32];
            r_s = S[{2'h3, phase}][4:0];
            r_t = K[{2'h3, phase}];
            if (phase == 4'b1111) next_state = (1 << `finished);
        end
        if (state[`finished]) begin
            next_A = AA + A;
            next_B = BB + B;
            next_C = CC + C;
            next_D = DD + D;
            next_state = (1 << `turn_arnd);
        end

        if(state[`turn_arnd]) begin
            next_state = (1 << `idle);
        end
    end
endmodule