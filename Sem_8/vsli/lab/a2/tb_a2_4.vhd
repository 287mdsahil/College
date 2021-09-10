--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   16:21:04 05/09/2021
-- Design Name:   
-- Module Name:   /home/sahil/College/Sem_8/vsli/lab/a2/tb_a2_4.vhd
-- Project Name:  a2
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: a2_4
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
 
ENTITY tb_a2_4 IS
END tb_a2_4;
 
ARCHITECTURE behavior OF tb_a2_4 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a2_4
    PORT(
         X : IN  std_logic_vector(7 downto 0);
         Y : OUT  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(2 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a2_4 PORT MAP (
          X => X,
          Y => Y
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
		X <= "00000001";
		wait for 1 ps;
		X <= "00000010";
		wait for 1 ps;
		X <= "00000100";
		wait for 1 ps;
		X <= "00001000";
		wait for 1 ps;
		X <= "00010000";
		wait for 1 ps;
		X <= "00100000";
		wait for 1 ps;
		X <= "01000000";
		wait for 1 ps;
		X <= "10000000";
		wait for 1 ps;
		X <= "01000001";
		wait for 1 ps;
		X <= "10000100";
		wait for 1 ps;
   end process;

END;
