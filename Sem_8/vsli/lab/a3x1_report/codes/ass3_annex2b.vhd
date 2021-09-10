
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ass3_annex2b is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           Y : out  STD_LOGIC_VECTOR (15 downto 0));
end ass3_annex2b;

architecture Behavioral of ass3_annex2b is
	procedure demux2x4(x: in std_logic_vector; y: out std_logic_vector) is
	variable a: std_logic_vector(3 downto 0);
	begin
		if x = "00" then
			y := "0001";
		elsif x = "01" then
			y := "0010";
		elsif x = "10" then
			y := "0100";
		elsif x = "11" then
			y := "1000";
		else
			y := "ZZZZ";
		end if;
	end procedure;
begin
	p1: process(X)
	variable a: std_logic_vector(3 downto 0);
	variable b: std_logic_vector(3 downto 0);
	begin
		proc1: demux2x4(X(3 downto 2), a);
		proc2: demux2x4(X(1 downto 0), b);
		for k in 0 to 3 loop
			if a(k) = '1' then
				Y(4*k+3 downto 4*k) <= b;
			else
				Y(4*k+3 downto 4*k) <= "0000";
			end if;
		end loop;
	end process;

end Behavioral;

