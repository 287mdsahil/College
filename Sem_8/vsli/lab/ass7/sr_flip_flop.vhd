----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:31:59 05/20/2021 
-- Design Name: 
-- Module Name:    sr_flip_flop - Behavioral 
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

entity sr_flip_flop is
    Port ( s : in  STD_LOGIC;
           r : in  STD_LOGIC;
           clock : in  STD_LOGIC;
           q : out  STD_LOGIC;
           xq : out  STD_LOGIC);
end sr_flip_flop;

architecture Behavioral of sr_flip_flop is

begin


end Behavioral;

