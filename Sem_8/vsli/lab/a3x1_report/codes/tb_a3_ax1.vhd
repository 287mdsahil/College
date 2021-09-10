LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
 
ENTITY tb_a3_ax1 IS
END tb_a3_ax1;
 
ARCHITECTURE behavior OF tb_a3_ax1 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a3_ax1
    PORT(
         X : IN  std_logic_vector(3 downto 0);
         Y : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic_vector(15 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a3_ax1 PORT MAP (
          X => X,
          Y => Y
        );


   -- Stimulus process
   stim_proc: process
   begin		

				X <= "0000";
		wait for 1 ps;
		X <= "0001";
		wait for 1 ps;
		X <= "0010";
		wait for 1 ps;
		X <= "0011";
		wait for 1 ps;
		X <= "0100";
		wait for 1 ps;
		X <= "0101";
		wait for 1 ps;
		X <= "0110";
		wait for 1 ps;
		X <= "0111";
		wait for 1 ps;
		
		X <= "1000";
		wait for 1 ps;
		X <= "1001";
		wait for 1 ps;
		X <= "1010";
		wait for 1 ps;
		X <= "1011";
		wait for 1 ps;
		X <= "1100";
		wait for 1 ps;
		X <= "1101";
		wait for 1 ps;
		X <= "1110";
		wait for 1 ps;
		X <= "1111";
		wait for 1 ps;

   end process;

END;
