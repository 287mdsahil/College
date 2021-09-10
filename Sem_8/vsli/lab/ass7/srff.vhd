
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity srff is
    Port ( s : in  STD_LOGIC;
           r : in  STD_LOGIC;
           clk : in  STD_LOGIC;
			  rst: in  STD_LOGIC;
           q : out  STD_LOGIC;
           notq : out  STD_LOGIC);
end srff;

architecture Behavioral of srff is
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
			if (s = '0' and r = '0') then
				q <= q1;
				notq <= notq1;
			elsif (s = '0' and r = '1') then
				q <= '0';
				notq <= '1';
				q1 := '0';
				notq1 := '1';
			elsif (s = '1' and r = '0') then
				q <= '1';
				notq <= '0';
				q1 := '1';
				notq1 := '0';
			else
				q  <= 'Z';
				notq <= 'Z';
				q1 := 'Z';
				notq1 := 'Z';
			end if;
		end if;
	end process;

end Behavioral;

