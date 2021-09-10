library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.comparator_package.ALL;

entity a5_1a is
    Port ( A : in  STD_LOGIC_VECTOR (1 downto 0);
           B : in  STD_LOGIC_VECTOR (1 downto 0);
           C : out  STD_LOGIC_VECTOR (2 downto 0));
end a5_1a;

architecture Behavioral of a5_1a is

begin
	p1: process(A,B) 
	variable cc : std_logic_vector(2 downto 0);
	begin
	comparator_2bit(A,B,cc);
	C <= cc;
	end process;

end Behavioral;

