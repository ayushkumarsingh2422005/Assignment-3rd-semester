-- nand3.vhdl

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity nand3_gate is
    port(
        A : in std_logic;
        B : in std_logic;
        C : in std_logic;
        Y : out std_logic
    );
end nand3_gate;

architecture behavior of nand3_gate is
begin
    Y <= not (A and B and C);
end behavior;
