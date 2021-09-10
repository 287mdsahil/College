-- TestBench Template 

  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;
  USE ieee.numeric_std.ALL;

  ENTITY testbench IS
  END testbench;

  ARCHITECTURE behavior OF testbench IS 
  
          COMPONENT srff
				 Port ( s : in  STD_LOGIC;
						  r : in  STD_LOGIC;
						  clk : in  STD_LOGIC;
						  rst: in  STD_LOGIC;
						  q : out  STD_LOGIC;
						  notq : out  STD_LOGIC);
          END COMPONENT;

          SIGNAL rst : std_logic;
          SIGNAL s : std_logic;
			 SIGNAL r : std_logic;
			 SIGNAL clk : std_logic;
			 SIGNAL q : std_logic;
			 SIGNAL notq : std_logic;

  BEGIN

  -- Component Instantiation
          uut: srff PORT MAP(
                  s => s,
						r => r,
						clk => clk,
						rst => rst,
						q => q,
						notq => notq
          );


  --  Test Bench Statements
     tb : PROCESS
     BEGIN
			clk <= '0';
			rst <= '0';
			wait for 1ps;
			
			rst <= '1';
			clk <= '1';
			wait for 1ps;
			
			rst <= '0';
			
			loop1: loop
				s <= '0';
				r <= '0';
				clk <= '0';
				wait for 1ps;
				clk <= '1';
				wait for 1ps;
				
				s <= '0';
				r <= '1';
				clk <= '0';
				wait for 1ps;
				clk <= '1';
				wait for 1ps;
				
				s <= '1';
				r <= '0';
				clk <= '0';
				wait for 1ps;
				clk <= '1';
				wait for 1ps;
				
				s <= '1';
				r <= '1';
				clk <= '0';
				wait for 1ps;
				clk <= '1';
				wait for 1ps;
				
			end loop;
     END PROCESS tb;

  END;
