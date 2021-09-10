`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:44:05 05/20/2021
// Design Name:   mux2x1
// Module Name:   /home/lp2917/14.7/ISE_DS/ass6/mux4x1.v
// Project Name:  ass6
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mux2x1
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module mux4x1;

	// Inputs
	reg [1:0] X;
	reg s;

	// Outputs
	wire Y;

	// Instantiate the Unit Under Test (UUT)
	mux2x1 uut (
		.X(X), 
		.s(s), 
		.Y(Y)
	);

	initial begin
		// Initialize Inputs
		X = 0;
		s = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

