library ieee;
use ieee.std_logic_1164.all;

entity tb_fullsubtractor is
end entity tb_fullsubtractor;

architecture behavior of tb_fullsubtractor is

    signal A, B, Bin: std_logic;
    signal Bout, Diff: std_logic;

    component fullsubtractor is
        port (
            A     : in std_logic;
            B     : in std_logic;
            Bin   : in std_logic;
            Bout  : out std_logic;
            Diff  : out std_logic
        );
    end component;

begin

    uut: fullsubtractor port map (
        A => A,
        B => B,
        Bin => Bin,
        Bout => Bout,
        Diff => Diff
    );

    process
    begin
        A <= '0';
        B <= '0';
        Bin <= '0';
        wait for 10 ns;
        
        A <= '0';
        B <= '0';
        Bin <= '1';
        wait for 10 ns;

        A <= '0';
        B <= '1';
        Bin <= '0';
        wait for 10 ns;

        A <= '0';
        B <= '1';
        Bin <= '1';
        wait for 10 ns;

        A <= '1';
        B <= '0';
        Bin <= '0';
        wait for 10 ns;

        A <= '1';
        B <= '0';
        Bin <= '1';
        wait for 10 ns;

        A <= '1';
        B <= '1';
        Bin <= '0';
        wait for 10 ns;

        A <= '1';
        B <= '1';
        Bin <= '1';
        wait for 10 ns;
        
        wait;
    end process;

end architecture behavior;
