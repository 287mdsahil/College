--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   22:50:26 03/24/2021
-- Design Name:   
-- Module Name:   /home/sahil/College/Sem_8/vsli/lab/a1/a1_test_bench.vhd
-- Project Name:  a1
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: a1
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
 
ENTITY a1_test_bench IS
END a1_test_bench;
 
ARCHITECTURE behavior OF a1_test_bench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a1
    PORT(
         a : IN  std_logic;
         b : IN  std_logic;
         c : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal a : std_logic := '0';
   signal b : std_logic := '0';

 	--Outputs
   signal c : std_logic_vector(7 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   -- constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a1 PORT MAP (
          a => a,
          b => b,
          c => c
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
	   a<='0';
		b<='0';
		wait for 1 ps;
		a<='0';
		b<='1';
		wait for 1 ps;
		a<='1';
		b<='0';
		wait for 1 ps;
		a<='1';
		b<='1';
		wait for 1 ps;
   end process;

END;
