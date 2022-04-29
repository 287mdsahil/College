----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:23:16 05/10/2021 
-- Design Name: 
-- Module Name:    a3_2_2a - Behavioral 
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

entity a3_2_2a is
    Port ( X : in  STD_LOGIC_VECTOR (2 downto 0);
           Y : out  STD_LOGIC_VECTOR (7 downto 0));
end a3_2_2a;

architecture Behavioral of a3_2_2a is

begin

	Y(7) <= X(2) and X(1) and X(0);
	Y(6) <= X(2) and X(1) and not X(0);
	Y(5) <= X(2) and not X(1) and X(0);
	Y(4) <= X(2) and not X(1) and not X(0);
	Y(3) <= not X(2) and X(1) and X(0);
	Y(2) <= not X(2) and X(1) and not X(0);
	Y(1) <= not X(2) and not X(1) and X(0);
	Y(0) <= not X(2) and not X(1) and not X(0);


end Behavioral;
