\library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass2_1a is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
           Y : out  STD_LOGIC);
end ass2_1a;

architecture Behavioral of ass2_1a is
	p1 : process (X)
	begin
		if X(1) = '1' then
			Y <= '1';
		else
			Y <= '0';
		end if;
	end process p1;
begin

