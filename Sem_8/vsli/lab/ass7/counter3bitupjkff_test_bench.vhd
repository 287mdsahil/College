
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY counter3bitupjkff_test_bench IS
END counter3bitupjkff_test_bench;
 
ARCHITECTURE behavior OF counter3bitupjkff_test_bench IS 

 
    COMPONENT counter3bitupjkff
    PORT(
         rst : IN  std_logic;
         clk : IN  std_logic;
         q : INOUT  std_logic_vector(2 downto 0);
         notq : INOUT  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal rst : std_logic := '0';
   signal clk : std_logic := '0';

	--BiDirs
   signal q : std_logic_vector(2 downto 0);
   signal notq : std_logic_vector(2 downto 0);
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: counter3bitupjkff PORT MAP (
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
			clk <= '0';
			wait for 1ps;
			clk <= '1';
			wait for 1ps;
		end loop;
   end process;

END;
