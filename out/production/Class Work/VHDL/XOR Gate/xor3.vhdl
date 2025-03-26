library ieee;
use ieee.std_logic_1164.all;

entity xor3 is
port ( a: in std_logic;
b: in std_logic;
c: out std_logic);
end xor3;

architecture xor3_arch of xor3 is
begin
c<= (a and (not b)) or (b and (not a));
end xor3_arch;