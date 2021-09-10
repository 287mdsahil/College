library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a2_2bb is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end a2_2bb;

architecture Behavioral of a2_2bb is

begin
	p1 : process(X)
	begin
		case X is
			when "0001" => Y <= "00";
			when "0010" => Y <= "01";
			when "0100" => Y <= "10";
			when "1000" => Y <= "11";
			when others => Y <= "ZZ";
		end case;
	end process p1;


end Behavioral;

