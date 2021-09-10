----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:27:33 05/17/2021 
-- Design Name: 
-- Module Name:    a3_4 - Behavioral 
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

entity a3_4 is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (15 downto 0));
end a3_4;

architecture Behavioral of a3_4 is

component a3_2_1a is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
			  E : in STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end component;

signal e1,v0,v1,v2,v3: std_logic_vector(3 downto 0);

begin
		
		c0 : a3_2_1a port map(X(3 downto 2), '1', e1);
		c1 : a3_2_1a port map(X(1 downto 0), e1(3), v3);
		c2 : a3_2_1a port map(X(1 downto 0), e1(2), v2);
		c3 : a3_2_1a port map(X(1 downto 0), e1(1), v1);
		c4 : a3_2_1a port map(X(1 downto 0), e1(0), v0);
		
		Y <= v3 & v2 & v1 & v0;

end Behavioral;

