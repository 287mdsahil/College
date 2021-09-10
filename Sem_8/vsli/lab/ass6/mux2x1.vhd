
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux2x1 is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
			  s : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end mux2x1;

architecture Behavioral of mux2x1 is
	signal a,b: std_logic;
begin
	a <= (X(0) nand s);
	b <= (X(1) nand (not s));

	Y <= a nand b;
end Behavioral;

