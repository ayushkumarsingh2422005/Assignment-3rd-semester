library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Mux_4bit is
    port (
        I0 : in std_logic;
        I1 : in std_logic;
        I2 : in std_logic;
        I3 : in std_logic;
        C0 : in std_logic;
        C1 : in std_logic;
        S : out std_logic
    );
end Mux_4bit;
architecture rlt of Mux_4bit is
    begin
        S <= ((I0 and ((not C0) and (not C1))) or (I1 and ((not C0) and (C1))) or (I2 and ((C0) and (not C1))) or (I3 and ((C0) and (C1))));
end rlt;