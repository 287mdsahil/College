LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY tb_a2_2a IS
END tb_a2_2a;
 
ARCHITECTURE behavior OF tb_a2_2a IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a2_2a
    PORT(
         X : IN  std_logic_vector(3 downto 0);
         Y : OUT  std_logic_vector(1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(1 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a2_2a PORT MAP (
          X => X,
          Y => Y
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
		X <= "0001";
		wait for 1 ps;
		X <= "0010";
		wait for 1 ps;
		X <= "0100";
		wait for 1 ps;
		X <= "1000";
		wait for 1 ps;
   end process;

END;
