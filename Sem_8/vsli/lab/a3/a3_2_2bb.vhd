----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:57:36 05/10/2021 
-- Design Name: 
-- Module Name:    a3_2_2bb - Behavioral 
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

entity a3_2_2bb is
    Port ( X : in  STD_LOGIC_VECTOR (2 downto 0);
           Y : out  STD_LOGIC_VECTOR (7 downto 0));
end a3_2_2bb;

architecture Behavioral of a3_2_2bb is

begin
	p1 : process(X)
	begin
		case X is
			when "000" => Y <= "00000001";
			when "001" => Y <= "00000010";
			when "010" => Y <= "00000100";
			when "011" => Y <= "00001000";
			when "100" => Y <= "00010000";
			when "101" => Y <= "00100000";
			when "110" => Y <= "01000000";
			when "111" => Y <= "10000000";
			when others => Y <= "ZZZZZZZZ";
		end case;
	end process;


end Behavioral;

