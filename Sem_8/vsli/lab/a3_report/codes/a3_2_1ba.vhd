library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a3_2_1ba is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end a3_2_1ba;

architecture Behavioral of a3_2_1ba is

begin

	p1 : process(X)
	begin
		if X = "00" then Y <= "0001";
		elsif X = "01" then Y <= "0010";
		elsif X = "10" then Y <= "0100";
		elsif X = "11" then Y <= "1000";
		end if;
	end process;

end Behavioral;

