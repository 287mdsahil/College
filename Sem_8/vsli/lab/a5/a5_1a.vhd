----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:24:37 05/22/2021 
-- Design Name: 
-- Module Name:    a5_1a - Behavioral 
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
use work.comparator_package.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity a5_1a is
    Port ( A : in  STD_LOGIC_VECTOR (1 downto 0);
           B : in  STD_LOGIC_VECTOR (1 downto 0);
           C : out  STD_LOGIC_VECTOR (2 downto 0));
end a5_1a;

architecture Behavioral of a5_1a is

begin
	p1: process(A,B) 
	variable cc : std_logic_vector(2 downto 0);
	begin
	comparator_2bit(A,B,cc);
	C <= cc;
	end process;

end Behavioral;

