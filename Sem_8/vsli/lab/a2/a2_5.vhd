----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:24:10 05/09/2021 
-- Design Name: 
-- Module Name:    a2_5 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity a2_5 is
    Port ( X : in  STD_LOGIC_VECTOR (15 downto 0);
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end a2_5;

architecture Behavioral of a2_5 is

component a2_2a is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end component;

signal v1,v2,v3,v4,v5 : std_logic_vector(1 downto 0);
signal v6: std_logic_vector(3 downto 0);

begin
	
	c4:a2_2a port map(X(15 downto 12), v4);
	c3:a2_2a port map(X(11 downto 8), v3);
	c2:a2_2a port map(X(7 downto 4), v2);
	c1:a2_2a port map(X(3 downto 0), v1);
	c0:a2_2a port map(v6,v5);
	
	v6(0) <= X(0) or X(1) or X(2) or X(3);
	v6(1) <= X(4) or X(5) or X(6) or X(7);
	v6(2) <= X(8) or X(9) or X(10) or X(11);
	v6(3) <= X(12) or X(13) or X(14) or X(15);
	
	p1: process(X,v1,v2,v3,v4,v5)
	begin
		if X(11 downto 0) = "000000000000" then
			Y <= v5 & v4;
		elsif X(7 downto 0) = "00000000" and X(15 downto 12) = "0000" then
			Y <= v5 & v3;
		elsif X(3 downto 0) = "0000" and X(15 downto 8) = "00000000" then
			Y <= v5 & v2;
		elsif X(15 downto 4) = "000000000000" then
			Y <= v5 & v1;
		else
			Y <= "ZZZZ";
		end if;
	end process;

end Behavioral;

