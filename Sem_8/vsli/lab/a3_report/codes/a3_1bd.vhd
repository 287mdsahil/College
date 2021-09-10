library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a3_1bd is
    Port ( X : in  STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end a3_1bd;

architecture Behavioral of a3_1bd is

begin

	with X select Y <=
		"01" when '0',
		"10" when '1',
		"ZZ" when others;

end Behavioral;

