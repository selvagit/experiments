module ripple_adder_4bit (A, B, Sum, Cin, Cout); 
	input [3:0] A,B; 
	output [3:0] Sum; 
	//reg [3:0] A,B; 
	//wire [3:0] Sum; 
	input Cin; 
	output Cout; 
	//reg Cin; 
	//reg Cout;

	wire [4:0] temp;

	assign temp = A + B + Cin;

	assign Cout = temp[4];

	assign Sum = temp[3:0];

endmodule


module test_bench;

	reg[3:0] A,B;
	//input [3:0] A,B;

	wire [3:0] Sum;
	//output [3:0] Sum;
	
	reg Cin; 
	wire Cout;

	//input Cin;
	//output Cout;
	
	ripple_adder_4bit adder(A,B,Sum,Cin,Cout);

	initial 
		begin
		$dumpfile("ripple_adder_4bit.vcd");
		$dumpvars (0,test_bench);
		$monitor ($time, "A=%h, B=%h, Cin=%b, Sum=%h, Cout =%b",
				A,B,Cin,Sum,Cout);
	
		#5 A=4'h0; B=4'h0; Cin=1'h0;
		#10 A=4'b0111; 
		#15 B=4'b1100; 
		#20 Cin=1'b1;
		end
endmodule
