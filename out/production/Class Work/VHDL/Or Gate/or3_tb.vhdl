library ieee;
use ieee.std_logic_1164.all;

entity or3_tb is
end or3_tb;

architecture or3_tb_arch of or3_tb is
component or3
port ( a: in std_logic;
b: in std_logic;
c: out std_logic);
end component;

signal a2: std_logic;
signal b2: std_logic;
signal c2: std_logic;

begin
or3_label: or3 port map(a=>a2,b=>b2,c=>c2);

tb_process: process
begin
wait for 10 ns;
a2<='0';
b2<='0';
wait for 10 ns;
a2<='0';
b2<='1';
wait for 10 ns;
a2<='1';
b2<='0';
wait for 10 ns;
a2<='1';
b2<='1';
wait for 10 ns;
end process;

end  or3_tb_arch; 

