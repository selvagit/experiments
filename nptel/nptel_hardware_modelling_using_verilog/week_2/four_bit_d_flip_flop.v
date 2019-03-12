module d_flip_4bit (a1, a2, a3, a4, e , b1, b2, b3, b4); 
	input a1,a2,a3,a4,e; 

	output reg b1,b2,b3,b4;

	always @(posedge e) 
	begin 
		b1 = a1;	
		b2 = a2;	
		b3 = a3;	
		b4 = a4;	
	end

endmodule


module test_bench;

	input a1,a2,a3,a4,e;

	output b1,b2,b3,b4;
	
	d_flip_4bit dlip(a1,a2,a3,a4,e,b1,b2,b3,b4);

	initial 
		begin

		$dumpfile("d_flip_4bit.vcd");
		$dumpvars (0,test_bench);

		$monitor ($time, "b1=%b, b2=%b", b1,b2);
	
		a1=1; 
		//#5 assign a1=1'b0; a2=1'b0; a3=1'b0; a4=1'b0 ; e=1'b0;  
		//#10 a1=1'b0; a2=1'b0; a3=1'b0; a4=1'b1 ; e=1'b0; 
		//#15 a1=1'b0; a2=1'b0; a3=1'b0; a4=1'b1 ; e=1'b1; 
		//#20 a1=1'b1; a2=1'b1; a3=1'b1; a4=1'b0 ; e=1'b0; 
		//#20 a1=1'b1; a2=1'b1; a3=1'b1; a4=1'b0 ; e=1'b1; 
		end
endmodule
