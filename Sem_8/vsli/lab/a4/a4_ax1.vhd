----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:52:41 05/23/2021 
-- Design Name: 
-- Module Name:    a4_ax1 - Behavioral 
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

entity a4_ax1 is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           S : out  STD_LOGIC_VECTOR (4 downto 0));
end a4_ax1;

architecture Behavioral of a4_ax1 is

component a4_b is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Cin : in  STD_LOGIC;
           S : out  STD_LOGIC;
           C : out  STD_LOGIC);
end component;

signal cc : std_logic_vector( 4 downto 0);

begin

		cc(0)<= '0';
		f1: for i in 0 to 3 generate
			pc1: a4_b port map(A(i), B(i), cc(i), S(i), cc(i+1));
		end generate;
		S(4) <= cc(4);

end Behavioral;

