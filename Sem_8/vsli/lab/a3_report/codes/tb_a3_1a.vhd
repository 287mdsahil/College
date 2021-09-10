LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY tb_a3_1a IS
END tb_a3_1a;
 
ARCHITECTURE behavior OF tb_a3_1a IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a3_1a
    PORT(
         X : IN  std_logic;
         Y : OUT  std_logic_vector(1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic := '0';

 	--Outputs
   signal Y : std_logic_vector(1 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a3_1a PORT MAP (
          X => X,
          Y => Y
        );

   -- Stimulus process
   stim_proc: process
   begin		
		X <= '0';
		wait for 1 ps;
		X <= '1';
		wait for 1 ps;	
   end process;
	
END;
