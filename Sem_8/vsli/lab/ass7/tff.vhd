
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tff is
    Port ( t : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           q : out  STD_LOGIC;
           notq : out  STD_LOGIC);
end tff;

architecture Behavioral of tff is
	shared variable q1, notq1: std_logic;
begin
	p1: process(clk, rst)
	begin
		if rst = '1' then
			q <= '0';
			notq <= '1';
			q1 := '0';
			notq1 := '1';
		elsif (clk'event and clk = '1') then
			if t = '0' then
				q <= q1;
				notq <= notq1;
			else
				q <= notq1;
				notq <= q1;
				q1 := notq1;
				notq1 := not q1;
			end if;
		end if;
	end process;
end Behavioral;

