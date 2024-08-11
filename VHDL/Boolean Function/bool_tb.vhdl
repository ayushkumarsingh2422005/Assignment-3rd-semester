library ieee;
use ieee.std_logic_1164.all;

entity bool_tb is
end bool_tb;

architecture bool_tb_arch of bool_tb is
component bool
port ( a: in std_logic;
b: in std_logic;
c: in std_logic;
d: out std_logic);
end component;

signal a2: std_logic;
signal b2: std_logic;
signal c2: std_logic;
signal d2: std_logic;

begin
bool_label: bool port map(a=>a2,b=>b2,c=>c2,d=>d2);

tb_process: process
begin
wait for 10 ns;
a2<='0';
b2<='0';
c2<='0';
wait for 10 ns;
a2<='0';
b2<='1';
c2<='0';
wait for 10 ns;
a2<='0';
b2<='0';
c2<='1';
wait for 10 ns;
a2<='0';
b2<='1';
c2<='1';
wait for 10 ns;
a2<='1';
b2<='0';
c2<='0';
wait for 10 ns;
a2<='1';
b2<='1';
c2<='0';
wait for 10 ns;
a2<='1';
b2<='0';
c2<='1';
wait for 10 ns;
a2<='1';
b2<='1';
c2<='1';
wait for 10 ns;
end process;

end  bool_tb_arch;