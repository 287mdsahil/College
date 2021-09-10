
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass3_annex2a is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (15 downto 0));
end ass3_annex2a;

architecture Behavioral of ass3_annex2a is
	function demux2x4(x: in std_logic_vector) return std_logic_vector is
	variable a: std_logic_vector(3 downto 0);
	begin
		if x = "00" then
			a := "0001";
		elsif x = "01" then
			a := "0010";
		elsif x = "10" then
			a := "0100";
		elsif x = "11" then
			a := "1000";
		else
			a := "ZZZZ";
		end if;
	return a;
	end function;

begin
	p1: process(X)
	variable a: std_logic_vector(3 downto 0);
	variable b: std_logic_vector(3 downto 0);
	begin
		a := demux2x4(X(3 downto 2));
		b := demux2x4(X(1 downto 0));
		for k in 0 to 3 loop
			if a(k) = '1' then
				Y(4*k+3 downto 4*k) <= b;
			else
				Y(4*k+3 downto 4*k) <= "0000";
			end if;
		end loop;
	end process;
end Behavioral;

