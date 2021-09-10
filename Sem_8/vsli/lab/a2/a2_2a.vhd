library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a2_2a is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end a2_2a;

architecture Behavioral of a2_2a is
begin
	Y(0) <= X(1) or X(3);
	Y(1) <= X(2) or X(3);
end Behavioral;

