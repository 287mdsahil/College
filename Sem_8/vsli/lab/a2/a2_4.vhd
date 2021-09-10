----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:00:24 05/09/2021 
-- Design Name: 
-- Module Name:    a2_4 - Behavioral 
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

entity a2_4 is
    Port ( X : in  STD_LOGIC_VECTOR (7 downto 0);
           Y : out  STD_LOGIC_VECTOR (2 downto 0));
end a2_4;

architecture Behavioral of a2_4 is

component a2_1a is 
	Port( X : in  STD_LOGIC_VECTOR (1 downto 0);
         Y : out  STD_LOGIC);
end component;

component a2_2a is 
	Port( X : in  STD_LOGIC_VECTOR (3 downto 0);
         Y : out  STD_LOGIC_VECTOR (1 downto 0));
end component;

signal s1,s2,s3:std_logic_vector(1 downto 0);
signal s4:std_logic;

begin

	c1:a2_2a port map (X(3 downto 0), s1);
	c2:a2_2a port map (X(7 downto 4), s2);
	c3:a2_1a port map (s3,s4);
	
	s3(0) <= X(0) or X(1) or X(2) or X(3);
	s3(1) <= X(4) or X(5) or X(6) or X(7);
	
	p1:process(X,s1,s2,s3,s4)
	begin
		if X(7 downto 4) = "0000" then
			Y <= s4 & s1;
		elsif X(3 downto 0) = "0000" then
			Y <= s4 & s2;
		else 
			Y <= "ZZZ";
		end if;
	end process;

end Behavioral;

