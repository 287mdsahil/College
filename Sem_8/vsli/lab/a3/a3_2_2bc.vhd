----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:09:05 05/10/2021 
-- Design Name: 
-- Module Name:    a3_2_2bc - Behavioral 
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

entity a3_2_2bc is
    Port ( X : in  STD_LOGIC_VECTOR (2 downto 0);
           Y : out  STD_LOGIC_VECTOR (7 downto 0));
end a3_2_2bc;

architecture Behavioral of a3_2_2bc is

begin

	Y <= 	"00000001" when X = "000" else
			"00000010" when x = "001" else
			"00000100" when X = "010" else
			"00001000" when X = "011" else
			"00010000" when X = "100" else
			"00100000" when X = "101" else
			"01000000" when X = "110" else
			"10000000" when X = "111" else
			"ZZZZZZZZ";
end Behavioral;

