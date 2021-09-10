
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY mux2x1_test_bench IS
END mux2x1_test_bench;
 
ARCHITECTURE behavior OF mux2x1_test_bench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT mux2x1
    PORT(
         X : IN  std_logic_vector(1 downto 0);
         s : IN  std_logic;
         Y : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(1 downto 0);
   signal s : std_logic := '0';

 	--Outputs
   signal Y : std_logic;

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: mux2x1 PORT MAP (
          X => X,
          s => s,
          Y => Y
        );

   -- Stimulus process
   stim_proc: process
   begin		
      s <= '0';
		X <= "00";
		wait for 1ps;
		X <= "01";
		wait for 1ps;
		X <= "10";
		wait for 1ps;
		X <= "11";
		wait for 1ps;
		s <= '1';
		X <= "00";
		wait for 1ps;
		X <= "01";
		wait for 1ps;
		X <= "10";
		wait for 1ps;
		X <= "11";
		wait for 1ps;
   end process;

END;
