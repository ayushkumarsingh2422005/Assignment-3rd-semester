library ieee;
use ieee.std_logic_1164.all;

entity four_bit_adder is
    port (
        A     : in std_logic_vector(3 downto 0);
        B     : in std_logic_vector(3 downto 0);
        Cin   : in std_logic;
        Sum   : out std_logic_vector(3 downto 0);
        Cout  : out std_logic
    );
end entity four_bit_adder;

architecture rtl of four_bit_adder is
    signal carry: std_logic_vector(3 downto 0);
    
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
    FA0: fulladder port map (
        A => A(0),
        B => B(0),
        Cin => Cin,
        carry => carry(0),
        sum => Sum(0)
    );

    FA1: fulladder port map (
        A => A(1),
        B => B(1),
        Cin => carry(0),
        carry => carry(1),
        sum => Sum(1)
    );

    FA2: fulladder port map (
        A => A(2),
        B => B(2),
        Cin => carry(1),
        carry => carry(2),
        sum => Sum(2)
    );

    FA3: fulladder port map (
        A => A(3),
        B => B(3),
        Cin => carry(2),
        carry => Cout,
        sum => Sum(3)
    );

end architecture rtl;
