library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity a2_1a is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
           Y : out  STD_LOGIC);
end a2_1a;

architecture Behavioral of a2_1a is

begin
	p1 : process (X)
	begin
		if X = "01" then
			Y <= '0';
		elsif X = "10" then
			Y <= '1';
		else 
			Y <= 'Z';
		end if;
	end process p1;
end Behavioral;



