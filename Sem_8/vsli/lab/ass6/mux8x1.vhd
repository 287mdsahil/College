
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity mux8x1 is
    Port ( X : in  STD_LOGIC_VECTOR (7 downto 0);
           s : in  STD_LOGIC_VECTOR (2 downto 0);
           Y : out  STD_LOGIC);
end mux8x1;

architecture Behavioral of mux8x1 is

COMPONENT mux4x1
    PORT(
         X : IN  std_logic_vector(3 downto 0);
         s : IN  std_logic_vector(1 downto 0);
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

c1: mux4x1 port map(X(7 downto 4), s(1 downto 0), t(0));
c2: mux4x1 port map(X(3 downto 0), s(1 downto 0), t(1));
c3: mux2x1 port map(t, s(2), Y);

end Behavioral;

