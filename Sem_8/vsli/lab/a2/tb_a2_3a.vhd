LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY tb_a2_3a IS
END tb_a2_3a;
 
ARCHITECTURE behavior OF tb_a2_3a IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a2_3a
    PORT(
         X : IN  std_logic_vector(7 downto 0);
         Y : OUT  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(2 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a2_3a PORT MAP (
          X => X,
          Y => Y
        );

   -- Stimulus process
   stim_proc: process
   begin		
		X <= "00000001";
		wait for 1 ps;
		X <= "00000010";
		wait for 1 ps;
		X <= "00000100";
		wait for 1 ps;
		X <= "00001000";
		wait for 1 ps;
		X <= "00010000";
		wait for 1 ps;
		X <= "00100000";
		wait for 1 ps;
		X <= "01000000";
		wait for 1 ps;
		X <= "10000000";
		wait for 1 ps;
   end process;

END;
