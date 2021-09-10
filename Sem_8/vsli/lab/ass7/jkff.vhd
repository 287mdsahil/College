
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity jkff is
    Port ( j : in  STD_LOGIC;
           k : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           q : inout  STD_LOGIC;
           notq : inout  STD_LOGIC);
end jkff;

architecture Behavioral of jkff is
	shared variable q1, notq1: std_logic;
begin
	p1: process(clk, rst)
		variable temp: std_logic;
	begin
		if rst = '1' then
			q <= '0';
			notq <= '1';
			q1 := '0';
			notq1 := '1';
		elsif (clk'event and clk = '1') then
			if (j = '0' and k = '0') then
				q <= q1;
				notq <= notq1;
			elsif (j = '0' and k = '1') then
				q <= '0';
				notq <= '1';
				q1 := '0';
				notq1 := '1';
			elsif (j = '1' and k = '0') then
				q <= '1';
				notq <= '0';
				q1 := '1';
				notq1 := '0';
			else
				q  <= notq;
				notq <= q1;
				temp := q1;
				q1 := notq1;
				notq1 := temp;
			end if;
		end if;
	end process;

end Behavioral;

