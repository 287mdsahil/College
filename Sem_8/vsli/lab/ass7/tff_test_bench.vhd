
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY tff_test_bench IS
END tff_test_bench;
 
ARCHITECTURE behavior OF tff_test_bench IS 
 
    COMPONENT tff
    PORT(
         t : IN  std_logic;
         rst : IN  std_logic;
         clk : IN  std_logic;
         q : OUT  std_logic;
         notq : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal t : std_logic := '0';
   signal rst : std_logic := '0';
   signal clk : std_logic := '0';

 	--Outputs
   signal q : std_logic;
   signal notq : std_logic;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: tff PORT MAP (
          t => t,
          rst => rst,
          clk => clk,
          q => q,
          notq => notq
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
		clk <= '0';
		rst <= '0';
		wait for 1ps;
		
		rst <= '1';
		clk <= '1';
		wait for 1ps;
		
		rst <= '0';
		
		loop1: loop
			t <= '0';
			clk <= '0';
			wait for 1ps;
			clk <= '1';
			wait for 1ps;
			
			t <= '1';
			clk <= '0';
			wait for 1ps;
			clk <= '1';
			wait for 1ps;
		end loop;
	end process;

END;
