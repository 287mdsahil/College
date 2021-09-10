--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   21:42:25 05/19/2021
-- Design Name:   
-- Module Name:   /home/sahil/College/Sem_8/vsli/lab/a3/tb_a3_ax1.vhd
-- Project Name:  a3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: a3_ax1
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
 
ENTITY tb_a3_ax1 IS
END tb_a3_ax1;
 
ARCHITECTURE behavior OF tb_a3_ax1 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a3_ax1
    PORT(
         X : IN  std_logic_vector(3 downto 0);
         Y : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(15 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a3_ax1 PORT MAP (
          X => X,
          Y => Y
        );


   -- Stimulus process
   stim_proc: process
   begin		

				X <= "0000";
		wait for 1 ps;
		X <= "0001";
		wait for 1 ps;
		X <= "0010";
		wait for 1 ps;
		X <= "0011";
		wait for 1 ps;
		X <= "0100";
		wait for 1 ps;
		X <= "0101";
		wait for 1 ps;
		X <= "0110";
		wait for 1 ps;
		X <= "0111";
		wait for 1 ps;
		
		X <= "1000";
		wait for 1 ps;
		X <= "1001";
		wait for 1 ps;
		X <= "1010";
		wait for 1 ps;
		X <= "1011";
		wait for 1 ps;
		X <= "1100";
		wait for 1 ps;
		X <= "1101";
		wait for 1 ps;
		X <= "1110";
		wait for 1 ps;
		X <= "1111";
		wait for 1 ps;

   end process;

END;
