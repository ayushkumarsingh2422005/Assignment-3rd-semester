library ieee;
use ieee.std_logic_1164.all;

entity and3 is
port ( a: in std_logic;
b: in std_logic;
c: out std_logic);
end and3;

architecture and3_arch of and3 is
begin
c<=a and b;
end and3_arch;