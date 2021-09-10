
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity counter3bitdown_tff is
    Port ( rst : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           q : inout  STD_LOGIC_VECTOR (2 downto 0);
           notq : inout  STD_LOGIC_VECTOR (2 downto 0));
end counter3bitdown_tff;

architecture Behavioral of counter3bitdown_tff is
	signal t: std_logic_vector(2 downto 0);
	shared variable q1, notq1: std_logic_vector(2 downto 0);
begin
	t(0) <= '1';
	t(1) <= notq(0);
	t(2) <= notq(0) and notq(1);

	gen: for k in 0 to 2 generate
		p1: process(rst, clk)
		begin
			if rst = '1' then
				q(k) <= '1';
				notq(k) <= '0';
				q1(k) := '1';
				notq1(k) := '0';
			elsif (clk'event and clk = '1') then
				if t(k) = '0' then
					q(k) <= q1(k);
					notq(k) <= notq1(k);
				else
					q(k) <= notq1(k);
					notq(k) <= q1(k);
					q1(k) := notq1(k);
					notq1(k) := not q1(k);
				end if;
			end if;
		end process;
	end generate;

end Behavioral;

