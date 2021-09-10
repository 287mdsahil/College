
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE work.Multiplexer.ALL;
 
ENTITY mux4x1_test_bench IS
END mux4x1_test_bench;
 
ARCHITECTURE behavior OF mux4x1_test_bench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT mux4x1
    PORT(
         X : IN  std_logic_vector(3 downto 0);
         s : IN  std_logic_vector(1 downto 0);
			Y : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal X : std_logic_vector(3 downto 0) := (others => '0');
   signal s : std_logic_vector(1 downto 0) := (others => '0');

 	--Outputs
   signal Y : std_logic;

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: mux4x1 PORT MAP (
          X => X,
          s => s,
			 Y => Y
        );


   stim_proc: process
		variable s_bin: std_logic_vector(1 downto 0);
		variable binary: std_logic_vector(3 downto 0);
   begin
		for i in 0 to 3 loop
			proc_s: dec_to_bin_proc(i, 2, s_bin);
			s <= s_bin;
			for k in 0 to 15 loop
				proc: dec_to_bin_proc(k, 4, binary);
				X <= binary;
				wait for 1ps;
			end loop;
		end loop;
   end process;

END;
