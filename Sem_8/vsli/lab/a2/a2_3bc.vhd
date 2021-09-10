----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:40:59 05/08/2021 
-- Design Name: 
-- Module Name:    a2_3bc - Behavioral 
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

entity a2_3bc is
    Port ( X : in  STD_LOGIC_VECTOR (7 downto 0);
           Y : out  STD_LOGIC_VECTOR (2 downto 0));
end a2_3bc;

architecture Behavioral of a2_3bc is

begin
		Y <= 	"000" when X = "00000001" else
				"001" when X = "00000010" else
				"010" when X = "00000100" else
				"011" when X = "00001000" else
				"100" when X = "00010000" else
				"101" when X = "00100000" else
				"110" when X = "01000000" else
				"111" when X = "10000000" else
				"ZZZ";

end Behavioral;

