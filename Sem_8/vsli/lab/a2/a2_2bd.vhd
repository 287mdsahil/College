library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a2_2bd is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end a2_2bd;

architecture Behavioral of a2_2bd is

begin
	with X select Y <= 
		"00" when "0001",
		"01" when "0010",
		"10" when "0100",
		"11" when "1000",
		"ZZ" when others;
end Behavioral;

