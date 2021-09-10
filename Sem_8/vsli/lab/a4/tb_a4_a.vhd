-- TestBench Template 

  LIBRARY ieee;
  USE ieee.std_logic_1164.ALL;
  USE ieee.numeric_std.ALL;

  ENTITY testbench IS
  END testbench;

  ARCHITECTURE behavior OF testbench IS 

  -- Component Declaration

			component a4_a is
				Port ( A : in  STD_LOGIC;
					B : in  STD_LOGIC;
					S : out  STD_LOGIC;
					C : out  STD_LOGIC);
			end component;

          SIGNAL A,B : std_logic;
          SIGNAL S,C : std_logic;
          

  BEGIN

  -- Component Instantiation
          uut: a4_a PORT MAP(
                  A => A,
                  B => B,
						S => S,
						C => C
          );


  --  Test Bench Statements
     tb : PROCESS
     BEGIN
			A <= '0';
			B <= '0';
			wait for 1 ps;
			
			A <= '0';
			B <= '1';
			wait for 1 ps;
			
			A <= '1';
			B <= '0';
			wait for 1 ps;
			
			A <= '1';
			B <= '1';
			wait for 1 ps;
     END PROCESS tb;
  --  End Test Bench 

  END;
