LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use work.comparator_package.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb_a5_1b IS
END tb_a5_1b;
 
ARCHITECTURE behavior OF tb_a5_1b IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a5_1b
    PORT(
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
         C : OUT  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(3 downto 0) := (others => '0');
   signal B : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal C : std_logic_vector(2 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a5_1b PORT MAP (
          A => A,
          B => B,
          C => C
        );

   -- Stimulus process
   stim_proc: process
	variable aa,bb : std_Logic_vector(3 downto 0);
   begin		
		l1: for i in 0 to 15 loop
			l2: for j in 0 to 15 loop
				dec_to_bin_proc(i,4,aa);
				A <= aa;
				dec_to_bin_proc(j,4,bb);
				B <= bb;
				wait for 1 ps;
			end loop;
		end loop;
   end process;

END;
