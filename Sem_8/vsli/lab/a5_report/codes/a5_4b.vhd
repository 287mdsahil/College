library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a5_4b is
    Port ( A : in  STD_LOGIC_VECTOR (7 downto 0);
           B : in  STD_LOGIC_VECTOR (7 downto 0);
           C : out  STD_LOGIC_VECTOR (2 downto 0));
end a5_4b;

architecture Behavioral of a5_4b is

component a5_1b is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           C : out  STD_LOGIC_VECTOR (2 downto 0));
end component;

signal c1,c2 : std_logic_vector(2 downto 0);

begin
	cp1: a5_1b port map(A(7 downto 4), B(7 downto 4), c2);
	cp2: a5_1b port map(A(3 downto 0), B(3 downto 0), c1);
	with c2 select C <= c1 when "010", c2 when others;

end Behavioral;
