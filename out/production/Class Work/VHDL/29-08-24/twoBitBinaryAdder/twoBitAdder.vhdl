library ieee;
use ieee.std_logic_1164.all;

entity twobitadder is
    port (
        A1   : in std_logic;
        A2   : in std_logic;
        B1   : in std_logic;
        B2   : in std_logic;
        Cin  : in std_logic;
        Cout : out std_logic;
        Sum1 : out std_logic;
        Sum2 : out std_logic
    );
end entity twobitadder;

architecture rtl of twobitadder is
    signal carry_temp: std_logic;
    
    component fulladder is
        port (
            A     : in std_logic;
            B     : in std_logic;
            Cin   : in std_logic;
            carry : out std_logic;
            sum   : out std_logic
        );
    end component;

begin
    FA1: fulladder port map (
        A => A1,
        B => B1,
        Cin => Cin,
        carry => carry_temp,
        sum => Sum1
    );
    
    FA2: fulladder port map (
        A => A2,
        B => B2,
        Cin => carry_temp,
        carry => Cout,
        sum => Sum2
    );

end architecture rtl;
