library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity a3_ax1 is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (15 downto 0));
end a3_ax1;

architecture Behavioral of a3_ax1 is

component a3_2_1a is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
			  E : in STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end component;

signal e1: std_logic_vector(3 downto 0);

begin

		c0 : a3_2_1a port map(X(3 downto 2), '1', e1);
		l1: for i in 0 to 3 generate
			c1 : a3_2_1a port map(X(1 downto 0), e1(i), Y(4*i+3 downto 4*i));
		end generate;

end Behavioral;

