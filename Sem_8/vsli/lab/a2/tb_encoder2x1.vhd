LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

 
ENTITY tb_encoder2x1 IS
END tb_encoder2x1;
 
ARCHITECTURE behavior OF tb_encoder2x1 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT encoder2x1
    PORT(
         X : IN  std_logic_vector(1 downto 0);
         Y : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(1 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: encoder2x1 PORT MAP (
          X => X,
          Y => Y
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
		X <= "01";
		wait for 1 ps;
		X <= "10";
		wait for 1 ps;
   end process;

END;
