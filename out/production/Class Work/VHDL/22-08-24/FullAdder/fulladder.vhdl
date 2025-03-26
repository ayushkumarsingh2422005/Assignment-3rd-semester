library ieee;
use ieee.std_logic_1164.all;

entity fulladder is
    port (
        A     : in std_logic;
        B     : in std_logic;
        Cin   : in std_logic;
        carry : out std_logic;
        sum   : out std_logic
    );
end entity fulladder;

architecture rtl of fulladder is
    signal sum1, carry1, carry2: std_logic;
    component halfadder is
        port (
            A     : in std_logic;
            B     : in std_logic;
            carry : out std_logic;
            sum   : out std_logic
        );
    end component;

begin
    HA1: halfadder port map (
        A => A,
        B => B,
        carry => carry1,
        sum => sum1
    );
    HA2: halfadder port map (
        A => sum1,
        B => Cin,
        carry => carry2,
        sum => sum
    );
    carry <= carry1 or carry2;

end architecture rtl;
