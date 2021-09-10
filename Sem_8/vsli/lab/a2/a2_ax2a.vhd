----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    21:59:42 05/19/2021 
-- Design Name: 
-- Module Name:    a2_ax2a - Behavioral 
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

entity a2_ax2a is
    Port ( X : in  STD_LOGIC_VECTOR (15 downto 0);
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end a2_ax2a;

architecture Behavioral of a2_ax2a is


function two_x_four_encoder(e: in std_logic; i:in std_logic_vector) return std_logic_vector is
variable a:std_logic_vector(1 downto 0);
begin
	if e = '0' then
		a := "00";
	elsif e = '1' then
			if i = "0001"
				then a := "00";
			elsif i = "0010"
				then a := "01";
			elsif i = "0100"
				then a := "10";
			elsif i = "1000"
				then a := "11";
			else
				a := "ZZ";
			end if;
	end if;
	return a;
end function;

begin	

	p1:process(X)
	variable e1:std_logic_vector(3 downto 0);
	variable v1:std_logic_vector(1 downto 0);
	begin
		e1(3) := X(15) or X(14) or X(13) or X(12);
		e1(2) := X(11) or X(10) or X(9) or X(8);
		e1(1) := X(7) or X(6) or X(5) or X(4);
		e1(0) := X(3) or X(2) or X(1) or X(0);
		
		Y(3 downto 2) <= two_x_four_encoder('1',e1);
		Y(1 downto 0) <= "ZZ";
		
		
		for i in 0 to 3 loop
			v1 := two_x_four_encoder(e1(i),X(4*i+3 downto 4*i));
			if e1(i) = '1' then
				Y(1 downto 0) <= v1;
			end if;
		end loop;
		
		
	end process;


end Behavioral;

