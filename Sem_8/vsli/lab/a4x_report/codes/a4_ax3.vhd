
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a4_ax3 is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           S : out  STD_LOGIC_VECTOR (4 downto 0));
end a4_ax3;

architecture Behavioral of a4_ax3 is

component a4_d is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           S : out  STD_LOGIC_VECTOR (4 downto 0));
end component;

begin
	c1: a4_d port map(A,B,S);
end Behavioral;