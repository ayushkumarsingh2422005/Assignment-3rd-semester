library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity four_bit_composite_adder is
    port (
        A    : in  std_logic_vector(3 downto 0);
        B    : in  std_logic_vector(3 downto 0);
        Cin  : in  std_logic;
        Sum  : out std_logic_vector(3 downto 0);
        Cout : out std_logic
    );
end entity four_bit_composite_adder;

architecture behavioral of four_bit_composite_adder is
    signal A_unsigned, B_unsigned : unsigned(3 downto 0);
    signal result                 : unsigned(4 downto 0);  -- Increased width to 5 bits
begin
    A_unsigned <= unsigned(A);
    B_unsigned <= unsigned(B);
    result <= ("0" & A_unsigned) + ("0" & B_unsigned) + ("0000" & Cin);  -- Extend to 5 bits for addition
    Sum  <= std_logic_vector(result(3 downto 0));
    Cout <= result(4);  -- Correctly accessing the 5th bit
end architecture behavioral;
