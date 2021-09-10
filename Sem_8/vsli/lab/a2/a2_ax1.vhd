----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:50:56 05/19/2021 
-- Design Name: 
-- Module Name:    a2_ax1 - Behavioral 
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

entity a2_ax1 is
    Port ( X : in  STD_LOGIC_VECTOR (15 downto 0);
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end a2_ax1;

architecture Behavioral of a2_ax1 is

component a2_2ba is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end component;

signal v1: std_logic_vector(7 downto 0);
signal v2: std_logic_vector(3 downto 0);
signal v3: std_logic_vector(1 downto 0);

begin

	v2(3) <= X(15) or X(14) or X(13) or X(12);
	v2(2) <= X(11) or X(10) or X(9) or X(8);
	v2(1) <= X(7) or X(6) or X(5) or X(4);
	v2(0) <= X(3) or X(2) or X(1) or X(0);
	
	c0: a2_2ba port map(v2,v3);

	g1: for k in 0 to 3 generate
		c1: a2_2ba port map(X(4*k+3 downto 4*k), v1(2*k+1 downto 2*k));
	end generate;
	
	p1:process(X,v1,v3)
	begin
		if v3 = "ZZ" then
			Y <= "ZZZZ";
		else
			for k in 0 to 3 loop
				if v1(2*k+1 downto 2*k) /= "ZZ" then
					Y <= v3 & v1(2*k+1 downto 2*k);
				end if;
			end loop;
		end if;
	end process;

end Behavioral;

