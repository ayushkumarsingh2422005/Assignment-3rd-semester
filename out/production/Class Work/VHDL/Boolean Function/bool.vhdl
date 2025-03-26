library ieee;
use ieee.std_logic_1164.all;

entity bool is
port ( a: in std_logic;
b: in std_logic;
c: in std_logic;
d: out std_logic);
end bool;

architecture bool_arch of bool is
begin
d<= a or (b and c);
end bool_arch;