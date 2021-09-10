----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:38:10 05/10/2021 
-- Design Name: 
-- Module Name:    a3_2_1a - Behavioral 
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

entity a3_2_1a is
    Port ( X : in  STD_LOGIC_VECTOR (1 downto 0);
			  E : in STD_LOGIC;
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end a3_2_1a;

architecture Behavioral of a3_2_1a is

begin
	
	Y(3) <= E and (X(1) and X(0));
	Y(2) <= E and (X(1) and not X(0));
	Y(1) <= E and (not X(1) and X(0));
	Y(0) <= E and (not X(1) and not X(0));

end Behavioral;

