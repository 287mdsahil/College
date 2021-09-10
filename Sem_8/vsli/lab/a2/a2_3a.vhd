library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a2_3a is
    Port ( X : in  STD_LOGIC_VECTOR (7 downto 0);
           Y : out  STD_LOGIC_VECTOR (2 downto 0));
end a2_3a;

architecture Behavioral of a2_3a is
begin

	Y(2) <= X(4) or X(5) or X(6) or X(7);
	Y(1) <= X(2) or X(3) or X(6) or X(7);
	Y(0) <= X(1) or X(3) or X(5) or X(7);

end Behavioral;

