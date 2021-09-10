
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity counter3bit_a is
    Port ( rst : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           q : inout  STD_LOGIC_VECTOR (2 downto 0);
           notq : inout  STD_LOGIC_VECTOR (2 downto 0));
end counter3bit_a;

architecture Behavioral of counter3bit_a is
	COMPONENT srff
	Port ( s : in  STD_LOGIC;
		  r : in  STD_LOGIC;
		  clk : in  STD_LOGIC;
		  rst: in  STD_LOGIC;
		  q : out  STD_LOGIC;
		  notq : out  STD_LOGIC);
	END COMPONENT;
	
	signal s,r: std_logic_vector(2 downto 0);
begin
	s(2) <= notq(2) and q(1) and q(0);
	r(2) <= q(2) and q(1) and q(0);
	s(1) <= notq(1) and q(0);
	r(1) <= q(1) and q(0);
	s(0) <= notq(0);
	r(0) <= q(0);
	
	gen1: for k in 0 to 2 generate
		proc: srff port map(s(k), r(k), clk, rst, q(k), notq(k));
	end generate;
end Behavioral;

