
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux16x1b is
    Port ( X : in  STD_LOGIC_VECTOR (15 downto 0);
           s : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC);
end mux16x1b;

architecture Behavioral of mux16x1b is
COMPONENT mux4x1
    PORT(
         X : IN  std_logic_vector(3 downto 0);
         s : IN  std_logic_vector(1 downto 0);
			Y : OUT  std_logic
        );
    END COMPONENT;

	signal t: std_logic_vector(3 downto 0);
begin
	c1: mux4x1 port map(X(15 downto 12), s(1 downto 0), t(3));
	c2: mux4x1 port map(X(11 downto 8), s(1 downto 0), t(2));
	c3: mux4x1 port map(X(7 downto 4), s(1 downto 0), t(1));
	c4: mux4x1 port map(X(3 downto 0), s(1 downto 0), t(0));
	c5: mux4x1 port map(t, s(3 downto 2), Y);
end Behavioral;

