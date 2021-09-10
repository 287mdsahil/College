library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a3_2_2bd is
    Port ( X : in  STD_LOGIC_VECTOR (2 downto 0);
           Y : out  STD_LOGIC_VECTOR (7 downto 0));
end a3_2_2bd;

architecture Behavioral of a3_2_2bd is

begin

	with X select Y <=
		"00000001" when "000",
		"00000010" when "001",
		"00000100" when "010",
		"00001000" when "011",
		"00010000" when "100",
		"00100000" when "101",
		"01000000" when "110",
		"10000000" when "111",
		"ZZZZZZZZ" when others;

end Behavioral;

