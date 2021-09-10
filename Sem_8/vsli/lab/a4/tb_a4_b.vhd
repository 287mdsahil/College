--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   23:53:55 05/21/2021
-- Design Name:   
-- Module Name:   /home/sahil/College/Sem_8/vsli/lab/a4/tb_a4_b.vhd
-- Project Name:  a4
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: a4_b
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb_a4_b IS
END tb_a4_b;
 
ARCHITECTURE behavior OF tb_a4_b IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a4_b
    PORT(
         A : IN  std_logic;
         B : IN  std_logic;
         Cin : IN  std_logic;
         S : OUT  std_logic;
         C : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic := '0';
   signal B : std_logic := '0';
   signal Cin : std_logic := '0';

 	--Outputs
   signal S : std_logic;
   signal C : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a4_b PORT MAP (
          A => A,
          B => B,
          Cin => Cin,
          S => S,
          C => C
        );


   -- Stimulus process
   stim_proc: process
   begin		
			A <= '0';
			B <= '0';
			Cin <= '0';
			wait for 1 ps;
			
			A <= '0';
			B <= '1';
			Cin <= '0';
			wait for 1 ps;
			
			A <= '1';
			B <= '0';
			Cin <= '0';
			wait for 1 ps;
			
			A <= '1';
			B <= '1';
			Cin <= '0';
			wait for 1 ps;

			A <= '0';
			B <= '0';
			Cin <= '1';
			wait for 1 ps;
			
			A <= '0';
			B <= '1';
			Cin <= '1';
			wait for 1 ps;
			
			A <= '1';
			B <= '0';
			Cin <= '1';
			wait for 1 ps;
			
			A <= '1';
			B <= '1';
			Cin <= '1';
			wait for 1 ps;
   end process;

END;
