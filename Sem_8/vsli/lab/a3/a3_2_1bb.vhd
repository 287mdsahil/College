----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:49:41 05/10/2021 
-- Design Name: 
-- Module Name:    a3_2_1bb - Behavioral 
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

entity a3_2_1bb is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end a3_2_1bb;

architecture Behavioral of a3_2_1bb is

begin
	p1: process(X)
	begin
	case X is
		when "00" => Y <= "0001";
		when "01" => Y <= "0010";
		when "10" => Y <= "0100";
		when "11" => Y <= "1000";
		when others => Y <= "ZZZZ";
	end case;
	end process;

end Behavioral;
