library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a2_1b is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
           Y : out  STD_LOGIC);
end a2_1b;

architecture Behavioral of a2_1b is
begin
	p1: process(X)
	begin
		case X is
			when "01" => Y <= '0';
			when "10" => Y <= '1';
			when others => Y <= 'Z';
		end case;
	end process p1;

end Behavioral;

