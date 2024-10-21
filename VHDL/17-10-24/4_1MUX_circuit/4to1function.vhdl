library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity function_4_1 is
    port (
        i0 : in std_logic;
        i1 : in std_logic;
        i2 : in std_logic;
        o : out std_logic
    );
end function_4_1;
architecture rlt of function_4_1 is
    -- signal O0, O1 : std_logic;
    signal a, b : std_logic;
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
    a <= '0';
    b <= '1';
    mux_4bit1: Mux_4bit port map (i0, b, a, not i0, i1, i2, o);
end rlt;