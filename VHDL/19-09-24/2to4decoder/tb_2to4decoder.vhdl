library ieee;
use ieee.std_logic_1164.all;

entity tb_2to4decoder is
end entity tb_2to4decoder;

architecture behavior of tb_2to4decoder is
    signal A, B : std_logic;
    signal y : std_logic_vector(3 downto 0);

    component twoToFourDecoder is
        port(
            A : in std_logic;
            B : in std_logic;
            D0 : out std_logic;
            D1 : out std_logic;
            D2 : out std_logic;
            D3 : out std_logic
        );
    end component;
begin
    uut: twoToFourDecoder port map(
        A => A,
        B => B,
        D0 => y(0),
        D1 => y(1),
        D2 => y(2),
        D3 => y(3)
    );
    process
    begin
        A <= '0';
        B <= '0';
        wait for 10 ns;
        
        A <= '1';
        B <= '0';
        wait for 10 ns;
        
        A <= '0';
        B <= '1';
        wait for 10 ns;
        
        A <= '1';
        B <= '1';
        wait for 10 ns;
        wait;
    end process;
end architecture behavior;
