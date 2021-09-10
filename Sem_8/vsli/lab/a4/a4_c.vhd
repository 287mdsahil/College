----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    00:59:37 05/22/2021 
-- Design Name: 
-- Module Name:    a4_c - Behavioral 
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
use work.adder_package.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity a4_c is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           C : in  STD_LOGIC;
           S : out  STD_LOGIC_VECTOR (4 downto 0));
end a4_c;

architecture Behavioral of a4_c is

begin
	p1: process(A,B,C)
	variable ss : std_logic_vector(4 downto 0);
	begin
		adder_subtractor_4bit(A,B,C,ss);
		S <= ss;
	end process;
end Behavioral;

