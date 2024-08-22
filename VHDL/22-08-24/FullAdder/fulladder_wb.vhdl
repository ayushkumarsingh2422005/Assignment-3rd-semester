library ieee;
use ieee.std_logic_1164.all;

entity tb_fulladder is
end entity tb_fulladder;

architecture behavior of tb_fulladder is

    signal A, B, Cin: std_logic;
    signal carry, sum: std_logic;

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

    uut: fulladder port map (
        A => A,
        B => B,
        Cin => Cin,
        carry => carry,
        sum => sum
    );
    process
    begin
        A <= '0';
        B <= '0';
        Cin <= '0';
        wait for 10 ns;
        
        A <= '0';
        B <= '0';
        Cin <= '1';
        wait for 10 ns;

        A <= '0';
        B <= '1';
        Cin <= '0';
        wait for 10 ns;

        A <= '0';
        B <= '1';
        Cin <= '1';
        wait for 10 ns;

        A <= '1';
        B <= '0';
        Cin <= '0';
        wait for 10 ns;

        A <= '1';
        B <= '0';
        Cin <= '1';
        wait for 10 ns;

        A <= '1';
        B <= '1';
        Cin <= '0';
        wait for 10 ns;

        A <= '1';
        B <= '1';
        Cin <= '1';
        wait for 10 ns;
        
        wait;
    end process;

end architecture behavior;
