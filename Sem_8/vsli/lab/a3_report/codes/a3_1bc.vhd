library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a3_1bc is
    Port ( X : in  STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end a3_1bc;

architecture Behavioral of a3_1bc is

begin

	Y <= 	"01" when X = '0' else
			"10" when X = '1' else
			"ZZ";

end Behavioral;

