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
    signal a, b : std_logic;
    signal i0_not : std_logic;  -- Signal to hold the result of `not i0`
    
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
    -- Assign fixed values to signals `a` and `b`
    a <= '0';
    b <= '1';
    i0_not <= not i0;  -- Compute `not i0` once and store it in `i0_not`
    
    -- Instantiate the Mux_4bit component
    mux_4bit1: Mux_4bit 
        port map (
            I0 => i0,         -- First input to Mux_4bit
            I1 => b,          -- Second input (fixed to '1')
            I2 => a,          -- Third input (fixed to '0')
            I3 => i0_not,     -- Fourth input, using `i0_not` instead of `not i0`
            C0 => i1,         -- Control line 0 (from `i1`)
            C1 => i2,         -- Control line 1 (from `i2`)
            S => o            -- Output of Mux_4bit connected to `o`
        );
end rlt;
