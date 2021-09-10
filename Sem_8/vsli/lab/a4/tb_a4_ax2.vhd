--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   01:05:55 05/23/2021
-- Design Name:   
-- Module Name:   /home/sahil/College/Sem_8/vsli/lab/a4/tb_a4_ax2.vhd
-- Project Name:  a4
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: a4_ax2
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
use work.adder_package.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb_a4_ax2 IS
END tb_a4_ax2;
 
ARCHITECTURE behavior OF tb_a4_ax2 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a4_ax2
    PORT(
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
			C : IN std_logic;
         S : OUT  std_logic_vector(4 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(3 downto 0) := (others => '0');
	signal C : std_logic;
   signal B : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal S : std_logic_vector(4 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a4_ax2 PORT MAP (
          A => A,
          B => B,
			 C => C,
          S => S
        );


   -- Stimulus process
   stim_proc: process
	variable aa,bb: std_logic_vector(3 downto 0);
   begin		
		l1: for i in 0 to 15 loop
			l2: for j in 0 to 15 loop
				dec_to_bin_proc(i,4,aa);
				A <= aa;
				dec_to_bin_proc(j,4,bb);
				B <= bb;
				C<='0';
				wait for 1 ps;
				dec_to_bin_proc(i,4,aa);
				A <= aa;
				dec_to_bin_proc(j,4,bb);
				B <= bb;
				C<='1';
				wait for 1 ps;
			end loop;
		end loop;
   end process;
END;
