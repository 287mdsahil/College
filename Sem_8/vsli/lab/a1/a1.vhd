----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    22:44:49 03/24/2021 
-- Design Name: 
-- Module Name:    a1 - Behavioral 
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

entity a1 is
    Port ( a : in  STD_LOGIC;
           b : in  STD_LOGIC;
           c : out  STD_LOGIC_VECTOR (7 downto 0));
end a1;

architecture Behavioral of a1 is

begin
	c(0) <= a xnor b;
	c(1) <= a xor b;
	c(2) <= a nor b;
	c(3) <= a nand b;
	c(4) <= not b;
	c(5) <= not a;
	c(6) <= a or b;
	c(7) <= a and b;
end Behavioral;

