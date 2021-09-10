library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a3_2_2ba is
    Port ( X : in  STD_LOGIC_VECTOR (2 downto 0);
           Y : out  STD_LOGIC_VECTOR (7 downto 0));
end a3_2_2ba;

architecture Behavioral of a3_2_2ba is

begin

	p1:process(X)
	begin
	if X = "000" then Y <= "00000001";
	elsif X = "001" then Y <= "00000010";
	elsif X = "010" then Y <= "00000100";
	elsif X = "011" then Y <= "00001000";
	elsif X = "100" then Y <= "00010000";
	elsif X = "101" then Y <= "00100000";
	elsif X = "110" then Y <= "01000000";
	elsif X = "111" then Y <= "10000000";
	else Y <= "ZZZZZZZZ";
	end if;
	end process;

end Behavioral;

