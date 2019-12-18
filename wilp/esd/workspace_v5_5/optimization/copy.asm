
; dummy code to understand the instruction

		.def _asm_example

;a4 = &a, B4= &x, A6= 40 , b3 return address

_asm_example 	mv  A6, B0
		zero A2
loop 	ldh .d1 *a4++,a5
		nop 	4
		add .l2 a5,b5,b5
		sth .d2 b5,*b4
		nop
	[b0]sub  .l2 b0,1,b0
	[b0]b    .s1 loop
		nop   5
		b     .s2 b3
		nop   5


;------------------------------------------------------------------------------------------
;------------------------------------------------------------------------------------------

; first level optimized code for copy

;a4 = &a, B4= &x, A6= 40 , b3 return address
		.def _asm_copy_opt
_asm_copy_opt
		mv  A6, B0
		shr b0,3,b0
		add a4,8,b8
		add b4,8,a8
		sub b0,1,b0

loopp 	lddw .d1 *a4++[2],a11:a10
		lddw .d2 *b8++[2],b11:b10
		[b0] bdec   loopp,b0
		nop 	2
		stdw .d2 a11:a10,*b4++[2]
		stdw .d1 b11:b10,*a8++[2]
		nop
		b     .s2 b3
		nop   5

;------------------------------------------------------------------------------------------
;------------------------------------------------------------------------------------------
; final optimized code for copy developed by akash, santosh, corrected to work on the
; short value. the initial code assumed it to be char, but input array is short, therefore
; each element is made up of two bytes. Both the input and output array are type short, hence
; the type conversion from short to char is not required. The final output will also have
; every alternate memory location filled with zero

		.def _asm_copy_optimized

;a4 = &a, B4= &x, A6= 40 , b3 return address

_asm_copy_optimized
	 	mv  A6, B0

 		MV .S2X A4,B7 ;move the content of A4 to B7(make copy of src addr)
		|| MV .S1X B4,A7 ;move the content of B4 to A7(make copy of dst addr)
		LDDW .D1T2 *A4, B9:B8 ;load the value present at address A4/x to B reg pair
		|| LDDW .D2T1 *++B7[1],A9:A8 ;load value present at address B7 = x+8 to A reg pair
		LDDW .D1T2 *++A4[2], B11:B10 ;load the value present at addr A4 = x+16 to B reg pair
		|| LDDW .D2T1 *++B7[2],A11:A10 ;load value present at address B7 = 24 to A reg pair
		LDDW .D1T2 *++A4[2], B13:B12 ;load the value present at addr A4 = x+32 to B reg pair
		|| LDDW .D2T1 *++B7[2],A13:A12 ;load value present at address B7 = 40 to A reg pair
		LDDW .D1T2 *++A4[2], B15:B14 ;load the value present at addr A4 = x+48 to B reg pair
		|| LDDW .D2T1 *++B7[2],A15:A14 ;load value present at address B7 = 56 to A reg pair
		LDDW .D1T2 *++A4[2], B17:B16 ;load the value present at addr A4 = x+64 to B reg pair
		|| LDDW .D2T1 *++B7[2],A17:A16 ;load value present at address B7 = 72 to A reg pair

		STDW .D1T2 B9:B8, *A7 ;store content of reg pair B to addr stored at A7/y
		|| STDW .D2T1 A9:A8, *++B4[1] ;store content of reg pair A to addr stored at B4 = y+8
		STDW .D1T2 B11:B10, *++A7[2] ;store content of reg pair B to addr stored at A7 = y+16
		|| STDW .D2T1 A11:A10, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+24
		STDW .D1T2 B13:B12, *++A7[2] ;store content of reg pair B to addr stored at A7 = y+32
		|| STDW .D2T1 A13:A12, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+40
		STDW .D1T2 B15:B14, *++A7[2] ;store content of reg pair B to addr stored at A7 = y+48
		|| STDW .D2T1 A15:A14, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+56
		STDW .D1T2 B17:B16, *++A7[2] ;store content of reg pair B to addr stored at A7 = y+64
		|| STDW .D2T1 A17:A16, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+72

		LDDW .D1T2 *++A4[2], B9:B8 ;load the value present at address A4/x to y+80 reg pair
		|| LDDW .D2T1 *++B7[2],A9:A8 ;load value present at address B7 = x+88 to A reg pair
		LDDW .D1T2 *++A4[2], B11:B10 ;load the value present at addr A4 = x+96 to B reg pair
		|| LDDW .D2T1 *++B7[2],A11:A10 ;load value present at address B7 = x+102 to A reg pair
		LDDW .D1T2 *++A4[2], B13:B12 ;load the value present at addr A4 = x+112 to B reg pair
		|| LDDW .D2T1 *++B7[2],A13:A12 ;load value present at address B7 = x+128 to A reg pair
		b  .s2 B3
		nop

		STDW .D1T2 B9:B8, *++A7[2] ;store content of reg pair B to addr stored at A7 = y + 80 /y
		|| STDW .D2T1 A9:A8, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+88
		STDW .D1T2 B11:B10, *++A7[2] ;store content of reg pair B to addr stored at A7 = y+96
		|| STDW .D2T1 A11:A10, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+102
		STDW .D1T2 B13:B12, *++A7[2] ;store content of reg pair B to addr stored at A7 = y+112
		|| STDW .D2T1 A13:A12, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+118
		nop
		nop


;copy
;A4 = &x, B4 = &y, A6 = 64, B3 = return address
		.def _asm_copy_optimized_k

_asm_copy_optimized_k
						MV .S2X A4,B7 ;move the content of A4 to B7(make copy of src addr)
						|| MV .S1X B4,A7 ;move the content of B4 to A7(make copy of dst addr)
						LDDW .D1T2 *A4, B9:B8 ;load the value present at address A4/x to B reg pair
						|| LDDW .D2T1 *++B7[1],A9:A8 ;load value present at address B7 = x+8 to A reg pair
						LDDW .D1T2 *++A4[2], B11:B10 ;load the value present at addr A4 = x+16 to B reg pair
						|| LDDW .D2T1 *++B7[2],A11:A10 ;load value present at address B7 = 24 to A reg pair
						LDDW .D1T2 *++A4[2], B13:B12 ;load the value present at addr A4 = x+32 to B reg pair
						|| LDDW .D2T1 *++B7[2],A13:A12 ;load value present at address B7 = 40 to A reg pair
						LDDW .D1T2 *++A4[2], B15:B14 ;load the value present at addr A4 = x+48 to B reg pair
						|| LDDW .D2T1 *++B7[2],A15:A14 ;load value present at address B7 = 56 to A reg pair
						LDDW .D1T2 *++A4[2], B17:B16 ;load the value present at addr A4 = x+64 to B reg pair
						|| LDDW .D2T1 *++B7[2],A17:A16 ;load value present at address B7 = 72 to A reg pair
						LDDW .D1T2 *++A4[2], B19:B18 ;load the value present at address A4/x to y+80 reg pair
						|| LDDW .D2T1 *++B7[2],A19:A18 ;load value present at address B7 = x+88 to A reg pair
						LDDW .D1T2 *++A4[2], B21:B20 ;load the value present at addr A4 = x+96 to B reg pair
						|| LDDW .D2T1 *++B7[2],A21:A20 ;load value present at address B7 = x+102 to A reg pair
						LDDW .D1T2 *++A4[2], B23:B22 ;load the value present at addr A4 = x+112 to B reg pair
						|| LDDW .D2T1 *++B7[2],A23:A22 ;load value present at address B7 = x+118 to A reg pair
						STDW .D1T2 B9:B8, *A7 ;store content of reg pair B to addr stored at A7/y
						|| STDW .D2T1 A9:A8, *++B4[1] ;store content of reg pair A to addr stored at B4 = y+8
						STDW .D1T2 B11:B10, *++A7[2] ;store content of reg pair B to addr stored at A7 = y+16
						|| STDW .D2T1 A11:A10, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+24
						STDW .D1T2 B13:B12, *++A7[2] ;store content of reg pair B to addr stored at A7 = y+32
						|| STDW .D2T1 A13:A12, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+40
						|| B .S2 B3 ;branch back to calling address stored in B3
						STDW .D1T2 B15:B14, *++A7[2] ;store content of reg pair B to addr stored at A7 = y+48
						|| STDW .D2T1 A15:A14, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+56
						STDW .D1T2 B17:B16, *++A7[2] ;store content of reg pair B to addr stored at A7 = y+64
						|| STDW .D2T1 A17:A16, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+72
						STDW .D1T2 B19:B18, *++A7[2] ;store content of reg pair B to addr stored at A7= y+80
						|| STDW .D2T1 A19:A18, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+88
						STDW .D1T2 B21:B20, *++A7[2] ;store content of reg pair B to addr stored at A7 = y+96
						|| STDW .D2T1 A21:A20, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+102
						STDW .D1T2 B23:B22, *++A7[2] ;store content of reg pair B to addr stored at A7 = y+112
						|| STDW .D2T1 A23:A22, *++B4[2] ;store content of reg pair A to addr stored at B4 = y+118




