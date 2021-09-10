----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:33:19 05/10/2021 
-- Design Name: 
-- Module Name:    a3_1bd - Behavioral 
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

entity a3_1bd is
    Port ( X : in  STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end a3_1bd;

architecture Behavioral of a3_1bd is

begin

	with X select Y <=
		"01" when '0',
		"10" when '1',
		"ZZ" when others;

end Behavioral;

