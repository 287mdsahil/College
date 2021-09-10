LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use work.comparator_package.ALL;
 
ENTITY tb_a5_3 IS
END tb_a5_3;
 
ARCHITECTURE behavior OF tb_a5_3 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a5_3
    PORT(
         A : IN  std_logic_vector(7 downto 0);
         B : IN  std_logic_vector(7 downto 0);
         C : OUT  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(7 downto 0) := (others => '0');
   signal B : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal C : std_logic_vector(2 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a5_3 PORT MAP (
          A => A,
          B => B,
          C => C
        );


   -- Stimulus process
   stim_proc: process
	variable aa,bb: std_logic_vector(7 downto 0);
   begin		
		l1: for i in 0 to 255 loop
			l2: for j in 0 to 255 loop
				dec_to_bin_proc(i,8,aa);
				A <= aa;
				dec_to_bin_proc(j,8,bb);
				B <= bb;
				wait for 1 ps;
			end loop;
		end loop;
   end process;

END;
