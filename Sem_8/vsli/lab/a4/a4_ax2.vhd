----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:02:25 05/23/2021 
-- Design Name: 
-- Module Name:    a4_ax2 - Behavioral 
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

entity a4_ax2 is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
			  C : in STD_LOGIC;
           S : out  STD_LOGIC_VECTOR (4 downto 0));
end a4_ax2;

architecture Behavioral of a4_ax2 is

    COMPONENT a4_ax1
    PORT(
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
         S : OUT  std_logic_vector(4 downto 0)
        );
    END COMPONENT;

	signal p: std_logic_vector(3 downto 0);
	signal s1: std_logic_vector(4 downto 0);
	
	begin
		p(3 downto 0) <= B(3 downto 0) xor (C & C & C & C);
		pc1: a4_ax1 port map(A,p,s1);
		with C select S(4) <= not s1(4) when '1', s1(4) when others;
		S(3 downto 0) <= s1(3 downto 0);



end Behavioral;

