--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   20:12:26 05/22/2021
-- Design Name:   
-- Module Name:   /home/sahil/College/Sem_8/vsli/lab/a5/tb_a4_4a.vhd
-- Project Name:  a5
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: a4_4a
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
use work.comparator_package.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb_a4_4a IS
END tb_a4_4a;
 
ARCHITECTURE behavior OF tb_a4_4a IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a4_4a
    PORT(
         A : IN  std_logic_vector(7 downto 0);
         B : IN  std_logic_vector(7 downto 0);
         C : OUT  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(7 downto 0) := (others => '0');
   signal B : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal C : std_logic_vector(2 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a4_4a PORT MAP (
          A => A,
          B => B,
          C => C
        );

 

   -- Stimulus process
   stim_proc: process
	variable aa,bb: std_logic_vector(7 downto 0);
   begin		
		l1: for i in 0 to 255 loop
			l2: for j in 0 to 255 loop
				dec_to_bin_proc(i,8,aa);
				A <= aa;
				dec_to_bin_proc(j,8,bb);
				B <= bb;
				wait for 1 ps;
			end loop;
		end loop;
   end process;

END;
