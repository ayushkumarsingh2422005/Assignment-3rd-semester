library ieee;
use ieee.std_logic_1164.all;

entity or3 is
port ( a: in std_logic;
b: in std_logic;
c: out std_logic);
end or3;

architecture or3_arch of or3 is
begin
c<=a or b;
end or3_arch;