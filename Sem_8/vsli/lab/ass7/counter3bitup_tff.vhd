
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity counter3bitup_tff is
    Port ( rst : in  STD_LOGIC;
           clk : in  STD_LOGIC;
           q : inout  STD_LOGIC_VECTOR(2 downto 0);
           notq : inout  STD_LOGIC_VECTOR(2 downto 0));
end counter3bitup_tff;

architecture Behavioral of counter3bitup_tff is
	COMPONENT tff
    PORT(
         t : IN  std_logic;
         rst : IN  std_logic;
         clk : IN  std_logic;
         q : OUT  std_logic;
         notq : OUT  std_logic
        );
    END COMPONENT;
	 
	 signal t: std_logic_vector(2 downto 0);
begin
	t(0) <= '1';
	t(1) <= q(0);
	t(2) <= q(0) and q(1);

	gen: for k in 0 to 2 generate
		proc: tff port map(t(k), rst, clk, q(k), notq(k));
	end generate;

end Behavioral;

