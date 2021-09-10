library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a3_1a is
    Port ( X : in  STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end a3_1a;

architecture Behavioral of a3_1a is

begin
	Y(1) <= X;
	Y(0) <= not X;
end Behavioral;

