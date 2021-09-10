library IEEE;
use IEEE.STD_LOGIC_1164.all;

package adder_package is
	procedure half_adder ( A: in std_logic; B: in std_logic; S: out std_logic; C: out std_logic);
	procedure full_adder ( A: in std_logic; B: in std_logic; Cin: in std_logic; S: out std_logic; C: out std_logic);
	procedure ripple_carry_adder_4bit ( A: in std_logic_vector(3 downto 0); B: in std_logic_vector(3 downto 0); C: in std_logic; S: out std_logic_vector(4 downto 0));
	procedure adder_subtractor_4bit (A: in std_logic_vector(3 downto 0); B: in std_logic_vector(3 downto 0); C: in std_logic; S: out std_logic_vector(4 downto 0));
	procedure bcd_adder_4bit(A: in std_logic_vector(3 downto 0); B: in std_logic_vector(3 downto 0); s: out std_logic_vector(4 downto 0));
	procedure dec_to_bin_proc(decimal: in integer; num_of_bits: in integer; binary: out std_logic_vector);
end adder_package;

package body adder_package is

	procedure dec_to_bin_proc(decimal: in integer; num_of_bits: in integer; binary: out std_logic_vector) is
   variable dec, bit_pos: integer;
   begin
		dec := decimal;
		bit_pos := 0;
		while(bit_pos < num_of_bits) loop
			if (dec rem 2) = 0 then
				binary(bit_pos) := '0';
			else
				binary(bit_pos) := '1';
			end if;
			dec := dec/2;
			bit_pos := bit_pos + 1;
		end loop;
   end procedure;


	procedure half_adder (A: in std_logic;
								 B: in std_logic;
								 S: out std_logic; 
								 C: out std_logic)  is
	begin
		S := A xor B;
		C := A and B;
	end half_adder;
	
	procedure full_adder (A: in std_logic;
								 B: in std_logic;
								 Cin: in std_logic;
								 S: out std_logic; 
								 C: out std_logic)  is
		variable cc1, ss1, cc2, ss2 : std_logic;
	begin
		pc1: half_adder(A, B, ss1, cc1);
		pc2: half_adder(Cin, ss1, S, cc2);
		pc3: half_adder(cc1, cc2, C, ss2);
	end full_adder;
	
	
	procedure ripple_carry_adder_4bit (
		A: in std_logic_vector( 3 downto 0 );
		B: in std_logic_vector( 3 downto 0 );
		C: in std_logic;
		S: out std_logic_vector( 4 downto 0)
	)  is
		variable cc : std_logic_vector( 4 downto 0);
	begin
		cc(0):= C;
		for i in 0 to 3 loop
			pc1: full_adder(A(i), B(i), cc(i), S(i), cc(i+1));
		end loop;
		S(4) := cc(4);
	end ripple_carry_adder_4bit;

	
	procedure adder_subtractor_4bit(A: in std_logic_vector(3 downto 0); B: in std_logic_vector(3 downto 0); C: in std_logic; S: out std_logic_vector(4 downto 0)) is
		variable p: std_logic_vector(3 downto 0);
		variable s1: std_logic_vector(4 downto 0);
	begin
		p(3 downto 0) := B(3 downto 0) xor (C & C & C & C);
		pc1: ripple_carry_adder_4bit(A,P,'0',s1);
		if c='1' then
			s1(4) := not S1(4);
		end if;
		S := s1;
	end adder_subtractor_4bit;
	
	
	procedure bcd_adder_4bit(A: in std_logic_vector(3 downto 0); B: in std_logic_vector(3 downto 0); s: out std_logic_vector(4 downto 0)) is
		variable p: std_logic_vector(4 downto 0);
		variable z,c: std_logic;
		variable q: std_logic_vector(3 downto 0);
	begin
		c := '0';
		pc1: ripple_carry_adder_4bit(A,B,c,p);
		z:= p(4) or (p(3) and (p(2) or p(1)));
		q:= c & z & z & c;
		pc2: ripple_carry_adder_4bit(p(3 downto 0),q,c,s);
		s(4):=z;
	end bcd_adder_4bit;

end adder_package;
