--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:43:10 05/10/2021
-- Design Name:   
-- Module Name:   /home/sahil/College/Sem_8/vsli/lab/a3/tb_a3_2_1a.vhd
-- Project Name:  a3
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: a3_2_1a
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
 
ENTITY tb_a3_2_1a IS
END tb_a3_2_1a;
 
ARCHITECTURE behavior OF tb_a3_2_1a IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a3_2_1a
    PORT(
         X : IN  std_logic_vector(1 downto 0);
			E : in STD_LOGIC;
         Y : OUT  std_logic_vector(3 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(1 downto 0) := (others => '0');
	signal E : std_logic;

 	--Outputs
   signal Y : std_logic_vector(3 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a3_2_1a PORT MAP (
          X => X,
			 E => E,
          Y => Y
        );


   -- Stimulus process
   stim_proc: process
   begin
		E <= '1';
		
		X <= "00";
		wait for 1 ps;
		X <= "01";
		wait for 1 ps;
		X <= "10";
		wait for 1 ps;
		X <= "11";
		wait for 1 ps;
   end process;

END;
