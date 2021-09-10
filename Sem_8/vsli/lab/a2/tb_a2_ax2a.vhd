--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   12:30:05 05/20/2021
-- Design Name:   
-- Module Name:   /home/sahil/College/Sem_8/vsli/lab/a2/tb_a2_ax2a.vhd
-- Project Name:  a2
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: a2_ax2a
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
 
ENTITY tb_a2_ax2a IS
END tb_a2_ax2a;
 
ARCHITECTURE behavior OF tb_a2_ax2a IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a2_ax2a
    PORT(
         X : IN  std_logic_vector(15 downto 0);
         Y : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(15 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(3 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a2_ax2a PORT MAP (
          X => X,
          Y => Y
        );


   -- Stimulus process
   stim_proc: process
   begin		
		X <= "0000000000000000";	
		l1: for i in 0 to 15 loop
			X(i) <= '1';
			wait for 1 ps;
			X(i) <= '0';
		end loop;
		
		X <= "0000000000000000";
		wait for 1 ps;
		X <= "0000011110000000";
		wait for 1 ps;
   end process;

END;
