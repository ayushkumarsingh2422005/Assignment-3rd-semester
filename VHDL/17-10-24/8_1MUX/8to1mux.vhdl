library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Mux_8bit is
    port (
        i0 : in std_logic;
        i1 : in std_logic;
        i2 : in std_logic;
        i3 : in std_logic;
        i4 : in std_logic;
        i5 : in std_logic;
        i6 : in std_logic;
        i7 : in std_logic;
        c0 : in std_logic;
        c1 : in std_logic;
        c2 : in std_logic;
        s : out std_logic
    );
end Mux_8bit;
architecture rlt of Mux_8bit is
    signal O0, O1 : std_logic;
    component Mux_4bit is
        port (
            I0 : in std_logic;
            I1 : in std_logic;
            I2 : in std_logic;
            I3 : in std_logic;
            C0 : in std_logic;
            C1 : in std_logic;
            S : out std_logic
        );
    end component;
begin
    nux_4bit1: Mux_4bit port map (i0, i1, i2, i3, c0, c1, O0);
    nux_4bit2: Mux_4bit port map (i4, i5, i6, i7, c0, c1, O1);
    s <= ((not c2) and O0) or (c2 and O1);
end rlt;