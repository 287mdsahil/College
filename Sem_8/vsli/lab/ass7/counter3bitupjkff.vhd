
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity counter3bitupjkff is
    Port ( rst : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           q : inout  STD_LOGIC_VECTOR(2 downto 0);
           notq : inout  STD_LOGIC_VECTOR(2 downto 0));
end counter3bitupjkff;

architecture Behavioral of counter3bitupjkff is
	COMPONENT jkff
    PORT(
         j : IN  std_logic;
         k : IN  std_logic;
         rst : IN  std_logic;
         clk : IN  std_logic;
         q : INOUT  std_logic;
         notq : INOUT  std_logic
        );
    END COMPONENT;
	 signal j, k: std_logic_vector(2 downto 0);
begin

	j(2) <= q(1) and q(0);
	k(2) <= q(1) and q(0);
	j(1) <= q(0);
	k(1) <= q(0);
	j(0) <= '1';
	k(0) <= '1';
			
	gen: for i in 0 to 2 generate
		proc: jkff port map(j(i), k(i), rst, clk, q(i), notq(i));
	end generate;

end Behavioral;

