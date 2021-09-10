library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity a2_2bc is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end a2_2bc;

architecture Behavioral of a2_2bc is

begin
		Y <=	"00" when X = "0001" else
				"01" when X = "0010" else
				"10" when X = "0100" else
				"11" when X = "1000" else
				"ZZ";
end Behavioral;

