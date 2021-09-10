--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   01:27:46 05/22/2021
-- Design Name:   
-- Module Name:   /home/sahil/College/Sem_8/vsli/lab/a4/tb_a4_d.vhd
-- Project Name:  a4
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: a4_d
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
 
ENTITY tb_a4_d IS
END tb_a4_d;
 
ARCHITECTURE behavior OF tb_a4_d IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a4_d
    PORT(
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
         S : OUT  std_logic_vector(4 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(3 downto 0) := (others => '0');
   signal B : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal S : std_logic_vector(4 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a4_d PORT MAP (
          A => A,
          B => B,
          S => S
        );


   -- Stimulus process
   stim_proc: process
   begin		
	
		A <= "1110";
		B <= "0001";
		wait for 1 ps;
		
		A <= "1010";
		B <= "0001";
		wait for 1 ps;
		
   end process;

END;
