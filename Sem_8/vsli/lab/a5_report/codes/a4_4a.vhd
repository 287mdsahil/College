library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.comparator_package.ALL;

entity a4_4a is
    Port ( A : in  STD_LOGIC_VECTOR (7 downto 0);
           B : in  STD_LOGIC_VECTOR (7 downto 0);
           C : out  STD_LOGIC_VECTOR (2 downto 0));
end a4_4a;

architecture Behavioral of a4_4a is

begin

	p1: process(A,B) 
	variable cc : std_logic_vector(2 downto 0);
	begin
	comparator_8bit2(A,B,cc);
	C <= cc;
	end process;


end Behavioral;

