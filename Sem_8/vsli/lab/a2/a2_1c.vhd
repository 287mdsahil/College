library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a2_1c is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
           Y : out  STD_LOGIC);
end a2_1c;

architecture Behavioral of a2_1c is
begin
		Y <= '0' when X = "01" else
			  '1' when X = "10" else
			  'Z';
end Behavioral;

