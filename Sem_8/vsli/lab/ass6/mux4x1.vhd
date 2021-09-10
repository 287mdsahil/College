
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity mux4x1 is
    Port ( X : in  STD_LOGIC_VECTOR (3 downto 0);
           s : in  STD_LOGIC_VECTOR (1 downto 0);
			  Y : out STD_LOGIC);
end mux4x1;

architecture Behavioral of mux4x1 is
	signal t1, t2, t3, t4: std_logic;
begin
	t1 <= (X(0) and (not s(0)) and (not s(1)));
	t2 <= (X(1) and s(0) and (not s(1)));
	t3 <= (X(2) and (not s(0)) and s(1));
	t4 <= (X(3) and s(0) and s(1));

	y <= (t1 or t2 or t3 or t4);
end Behavioral;

