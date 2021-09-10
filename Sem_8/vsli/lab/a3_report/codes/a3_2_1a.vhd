library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a3_2_1a is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
			  E : in STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end a3_2_1a;

architecture Behavioral of a3_2_1a is

begin
	
	Y(3) <= E and (X(1) and X(0));
	Y(2) <= E and (X(1) and not X(0));
	Y(1) <= E and (not X(1) and X(0));
	Y(0) <= E and (not X(1) and not X(0));

end Behavioral;

