library ieee;
use ieee.std_logic_1164.all;

entity fourbitadder is
    port (
        A  : in std_logic_vector(3 downto 0);
        B  : in std_logic_vector(3 downto 0);
        Cin  : in std_logic;
        Cout : out std_logic;
        Sum  : out std_logic_vector(3 downto 0)
    );
end entity fourbitadder;

architecture rtl of fourbitadder is
    signal carry_temp1, carry_temp2, carry_temp3: std_logic;

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
        carry => carry_temp1,
        sum => Sum(0)
    );

    FA1: fulladder port map (
        A => A(1),
        B => B(1),
        Cin => carry_temp1,
        carry => carry_temp2,
        sum => Sum(1)
    );

    FA2: fulladder port map (
        A => A(2),
        B => B(2),
        Cin => carry_temp2,
        carry => carry_temp3,
        sum => Sum(2)
    );

    FA3: fulladder port map (
        A => A(3),
        B => B(3),
        Cin => carry_temp3,
        carry => Cout,
        sum => Sum(3)
    );

end architecture rtl;
