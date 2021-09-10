LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
use work.adder_package.ALL;
 
ENTITY tb_a4_ax2 IS
END tb_a4_ax2;
 
ARCHITECTURE behavior OF tb_a4_ax2 IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT a4_ax2
    PORT(
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
			C : IN std_logic;
         S : OUT  std_logic_vector(4 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(3 downto 0) := (others => '0');
	signal C : std_logic;
   signal B : std_logic_vector(3 downto 0) := (others => '0');

 	--Outputs
   signal S : std_logic_vector(4 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: a4_ax2 PORT MAP (
          A => A,
          B => B,
			 C => C,
          S => S
        );


   -- Stimulus process
   stim_proc: process
	variable aa,bb: std_logic_vector(3 downto 0);
   begin		
		l1: for i in 0 to 15 loop
			l2: for j in 0 to 15 loop
				dec_to_bin_proc(i,4,aa);
				A <= aa;
				dec_to_bin_proc(j,4,bb);
				B <= bb;
				C<='0';
				wait for 1 ps;
				dec_to_bin_proc(i,4,aa);
				A <= aa;
				dec_to_bin_proc(j,4,bb);
				B <= bb;
				C<='1';
				wait for 1 ps;
			end loop;
		end loop;
   end process;
END;
