
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;


entity mux16x1 is
    Port ( X : in  STD_LOGIC_VECTOR (15 downto 0);
           s : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC);
end mux16x1;

architecture Behavioral of mux16x1 is
COMPONENT mux8x1
    PORT(
         X : IN  std_logic_vector(7 downto 0);
         s : IN  std_logic_vector(2 downto 0);
			Y : OUT  std_logic
        );
    END COMPONENT;
	 
COMPONENT mux2x1
    PORT(
         X : IN  std_logic_vector(1 downto 0);
         s : IN  std_logic;
			Y : OUT  std_logic
        );
    END COMPONENT;
	 
	signal t: std_logic_vector(1 downto 0);
begin

c1: mux8x1 port map(X(15 downto 8), s(2 downto 0), t(0));
c2: mux8x1 port map(X(7 downto 0), s(2 downto 0), t(1));
c3: mux2x1 port map(t, s(3), Y);

end Behavioral;

