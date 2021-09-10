library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a3_2_2bc is
    Port ( X : in  STD_LOGIC_VECTOR (2 downto 0);
           Y : out  STD_LOGIC_VECTOR (7 downto 0));
end a3_2_2bc;

architecture Behavioral of a3_2_2bc is

begin

	Y <= 	"00000001" when X = "000" else
			"00000010" when x = "001" else
			"00000100" when X = "010" else
			"00001000" when X = "011" else
			"00010000" when X = "100" else
			"00100000" when X = "101" else
			"01000000" when X = "110" else
			"10000000" when X = "111" else
			"ZZZZZZZZ";
end Behavioral;

