library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity encoder2x1 is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
           Y : out  STD_LOGIC);
end encoder2x1;

architecture Behavioral of encoder2x1 is

begin
	p1 : process (X)
	begin
		if X(1) = '1' then
			Y <= '1';
		else
			Y <= '0';
		end if;
	end process p1;

end Behavioral;

