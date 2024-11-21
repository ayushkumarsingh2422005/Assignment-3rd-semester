-- nand2.vhdl

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity nand2_gate is
    port(
        A : in std_logic;
        B : in std_logic;
        Y : out std_logic
    );
end nand2_gate;

architecture behavior of nand2_gate is
begin
    Y <= not (A and B);
end behavior;
