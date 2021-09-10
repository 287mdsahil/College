library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a2_2aa is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end a2_2aa;

architecture Behavioral of a2_2aa is
begin
	p1 : process
	begin
		if X = "0001" then
			Y <= "00";
		elsif X = "0010" then
			Y <= "01";
		elsif X = "0100" then
			Y <= "10";
		elsif X = "1000" then
			Y <= "11";
		else 
			Y <= "ZZ";
		end if;
	end process p1;

end Behavioral;

