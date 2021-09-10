library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a3_3 is
    Port ( X : in  STD_LOGIC_VECTOR (2 downto 0);
           Y : out  STD_LOGIC_VECTOR (7 downto 0));
end a3_3;

architecture Behavioral of a3_3 is


component a3_2_1a is
    PORT(
         X : IN  std_logic_vector(1 downto 0);
			E : in STD_LOGIC;
         Y : OUT  std_logic_vector(3 downto 0)
        );
end component;

component a3_1a is
    Port ( X : in  STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end component;

signal v1,v2 : std_logic_vector (3 downto 0);
signal e1    : std_logic_vector (1 downto 0);

begin
	
	c0 : a3_1a port map(X(2), e1);
	c1 : a3_2_1a port map(X(1 downto 0), e1(0), v1);
	c2 : a3_2_1a port map(X(1 downto 0), e1(1), v2);
	
	Y <= v2 & v1;

end Behavioral;

