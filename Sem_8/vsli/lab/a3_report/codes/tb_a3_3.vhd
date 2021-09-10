LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY tb_a3_3 IS
END tb_a3_3;
 
ARCHITECTURE behavior OF tb_a3_3 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a3_3
    PORT(
         X : IN  std_logic_vector(2 downto 0);
         Y : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(2 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(7 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a3_3 PORT MAP (
          X => X,
          Y => Y
        );

 

   -- Stimulus process
   stim_proc: process
   begin		
		X <= "000";
		wait for 1 ps;
		X <= "001";
		wait for 1 ps;
		X <= "010";
		wait for 1 ps;
		X <= "011";
		wait for 1 ps;
		X <= "100";
		wait for 1 ps;
		X <= "101";
		wait for 1 ps;
		X <= "110";
		wait for 1 ps;
		X <= "111";
		wait for 1 ps;
   end process;

END;
