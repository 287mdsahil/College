----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:22:03 05/10/2021 
-- Design Name: 
-- Module Name:    a3_1ba - Behavioral 
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

entity a3_1ba is
    Port ( X : in  STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (1 downto 0));
end a3_1ba;

architecture Behavioral of a3_1ba is

begin
	p1 : process(X)
	begin
		if X = '0' then
			Y <= "01";
		elsif X = '1' then
			Y <= "10";
		end if;
	end process;

end Behavioral;

