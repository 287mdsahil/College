library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a2_3ba is
    Port ( X : in  STD_LOGIC_VECTOR (7 downto 0);
           Y : out  STD_LOGIC_VECTOR (2 downto 0));
end a2_3ba;

architecture Behavioral of a2_3ba is

begin

	p1: process(X)
	begin
		if X = "00000001" then Y <= "000";
		elsif X = "00000010" then Y <= "001";
		elsif X = "00000100" then Y <= "010";
		elsif X = "00001000" then Y <= "011";
		elsif X = "00010000" then Y <= "100";
		elsif X = "00100000" then Y <= "101";
		elsif X = "01000000" then Y <= "110";
		elsif X = "10000000" then Y <= "111";
		else Y <= "ZZZ";
		end if;
	end process p1;


end Behavioral;

