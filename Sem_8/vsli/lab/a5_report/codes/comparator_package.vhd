library IEEE;
use IEEE.STD_LOGIC_1164.all;

package comparator_package is

	procedure comparator_2bit(
        A: in std_logic_vector(1 downto 0); 
        B: in std_logic_vector(1 downto 0);
        C: out std_logic_vector(2 downto 0));
	procedure comparator_4bit(
        A: in std_logic_vector(3 downto 0);
        B: in std_logic_vector(3 downto 0);
        C: out std_logic_vector(2 downto 0));
	procedure comparator_8bit(
        A: in std_logic_vector(7 downto 0);
        B: in std_logic_vector(7 downto 0);
        C: out std_logic_vector(2 downto 0));
	procedure comparator_8bit2(
        A: in std_logic_vector(7 downto 0);
        B: in std_logic_vector(7 downto 0); 
        C: out std_logic_vector(2 downto 0));
	procedure dec_to_bin_proc(
        decimal: in integer; 
        num_of_bits: in integer; binary: 
        out std_logic_vector);

end comparator_package;

package body comparator_package is

	procedure dec_to_bin_proc(
        decimal: in integer; 
        num_of_bits: in integer; 
        binary: out std_logic_vector) is
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

	procedure comparator_2bit(
        A: in std_logic_vector(1 downto 0);
        B: in std_logic_vector(1 downto 0);
        C: out std_logic_vector(2 downto 0)) is
	begin
		C(0) := (not A(1) and not A(0) and B(0)) 
                or (not A(1) and B(1))
                or (not A(0) and B(1) and B(0));
		C(1) := (A(1) xnor B(1)) and (A(0) xnor B(0));
		C(2) := (not B(1) and not B(0) and A(0))
                or (not B(1) and A(1))
                or (not B(0) and A(1) and A(0));
	end procedure;
	
	procedure comparator_4bit(
        A: in std_logic_vector(3 downto 0);
        B: in std_logic_vector(3 downto 0);
        C: out std_logic_vector(2 downto 0)) is
		variable cc2,cc1 : std_logic_vector(2 downto 0);
	begin
        comparator_2bit(A(3 downto 2),B(3 downto 2),cc2);
		comparator_2bit(cc2(2) & A(1),cc2(0) & B(1),cc1);
		comparator_2bit(cc1(2) & A(0), cc1(0) & B(0), C);
	end procedure;
	
	procedure comparator_8bit(
        A: in std_logic_vector(7 downto 0);
        B: in std_logic_vector(7 downto 0);
        C: out std_logic_vector(2 downto 0)) is
		variable cc2,cc1 : std_logic_vector(2 downto 0);
	begin
		comparator_4bit(A(7 downto 4),B(7 downto 4),cc2);
		comparator_4bit(A(3 downto 0),B(3 downto 0),cc1);
		
		if cc2 = "010" then
			C := cc1;
		else
			C := cc2;
		end if;
	end procedure;
	
	procedure comparator_8bit2(
        A: in std_logic_vector(7 downto 0);
        B: in std_logic_vector(7 downto 0);
        C: out std_logic_vector(2 downto 0)) is
		variable cc4,cc3,cc2,cc1 : std_logic_vector(2 downto 0);
	begin
		comparator_2bit(A(7 downto 6),B(7 downto 6),cc4);
		comparator_2bit(A(5 downto 4),B(5 downto 4),cc3);
		comparator_2bit(A(3 downto 2),B(3 downto 2),cc2);
		comparator_2bit(A(1 downto 0),B(1 downto 0),cc1);
		
		if cc4 /= "010" then
			C := cc4;
		elsif cc3 /= "010" then
			C := cc3;
		elsif cc2 /= "010" then
			C := cc2;
		elsif cc1 /= "010" then
			C := cc1;
		else
			C := "010";
		end if;

	end procedure;
 
end comparator_package;
