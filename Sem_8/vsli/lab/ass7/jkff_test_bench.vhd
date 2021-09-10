
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

 
ENTITY jkff_test_bench IS
END jkff_test_bench;
 
ARCHITECTURE behavior OF jkff_test_bench IS 

 
    COMPONENT jkff
    PORT(
         j : IN  std_logic;
         k : IN  std_logic;
         rst : IN  std_logic;
         clk : IN  std_logic;
         q : INOUT  std_logic;
         notq : INOUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal j : std_logic := '0';
   signal k : std_logic := '0';
   signal rst : std_logic := '0';
   signal clk : std_logic := '0';

	--BiDirs
   signal q : std_logic;
   signal notq : std_logic;

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: jkff PORT MAP (
          j => j,
          k => k,
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
				j <= '0';
				k <= '0';
				clk <= '0';
				wait for 1ps;
				clk <= '1';
				wait for 1ps;
				
				j <= '0';
				k <= '1';
				clk <= '0';
				wait for 1ps;
				clk <= '1';
				wait for 1ps;
				
				j <= '1';
				k <= '0';
				clk <= '0';
				wait for 1ps;
				clk <= '1';
				wait for 1ps;
				
				j <= '1';
				k <= '1';
				clk <= '0';
				wait for 1ps;
				clk <= '1';
				wait for 1ps;
				
			end loop;
   end process;

END;
