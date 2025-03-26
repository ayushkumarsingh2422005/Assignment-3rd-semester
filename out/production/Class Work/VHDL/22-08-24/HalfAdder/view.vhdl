library ieee;
use ieee.std_logic_1164.all;

entity view is
end view;

architecture view_arch of view is
component halfadder
    port (
        A, B : in std_logic;
        carry : out std_logic;
        sum : out std_logic
    );
end component;

signal A: std_logic;
signal B: std_logic;
signal carry: std_logic;
signal sum: std_logic;

begin
-- Correct component instantiation
halfadder_inst: halfadder port map(A => A, B => B, carry => carry, sum => sum);

tb_process: process
begin
    wait for 10 ns;
    A <= '0';
    B <= '1';
    wait for 10 ns;
    A <= '1';
    B <= '0';
    wait for 10 ns;
    A <= '1';
    B <= '1';
    wait for 10 ns;
    A <= '0';
    B <= '0';
    wait for 10 ns;
end process;

end view_arch;
