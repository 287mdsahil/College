----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:03:50 05/08/2021 
-- Design Name: 
-- Module Name:    a2_3bb - Behavioral 
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

entity a2_3bb is
    Port ( X : in  STD_LOGIC_VECTOR (7 downto 0);
           Y : out  STD_LOGIC_VECTOR (2 downto 0));
end a2_3bb;

architecture Behavioral of a2_3bb is

begin
	p1 : process(X)
	begin
		case X is
			when "00000001" => Y <= "000";
			when "00000010" => Y <= "001";
			when "00000100" => Y <= "010";
			when "00001000" => Y <= "011";
			when "00010000" => Y <= "100";
			when "00100000" => Y <= "101";
			when "01000000" => Y <= "110";
			when "10000000" => Y <= "111";
			when others => Y <="ZZZ";
		end case;
	end process p1;

end Behavioral;

