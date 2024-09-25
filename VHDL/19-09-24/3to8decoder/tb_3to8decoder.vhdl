library ieee;
use ieee.std_logic_1164.all;

entity tb_3to8decoder is
end entity tb_3to8decoder;

architecture behavior of tb_3to8decoder is
    signal A, B, C : std_logic;
    signal y : std_logic_vector(7 downto 0);

    component threeToEightDecoder is
        port(
            A : in std_logic;
            B : in std_logic;
            C : in std_logic;
            D0 : out std_logic;
            D1 : out std_logic;
            D2 : out std_logic;
            D3 : out std_logic;
            D4 : out std_logic;
            D5 : out std_logic;
            D6 : out std_logic;
            D7 : out std_logic
        );
    end component;

begin
    uut: threeToEightDecoder port map(
        A => A,
        B => B,
        C => C,
        D0 => y(0),
        D1 => y(1),
        D2 => y(2),
        D3 => y(3),
        D4 => y(4),
        D5 => y(5),
        D6 => y(6),
        D7 => y(7)
    );
    process
    begin
        A <= '0'; B <= '0'; C <= '0';
        wait for 10 ns;
        
        A <= '0'; B <= '0'; C <= '1';
        wait for 10 ns;
        
        A <= '0'; B <= '1'; C <= '0';
        wait for 10 ns;
        
        A <= '0'; B <= '1'; C <= '1';
        wait for 10 ns;
        
        A <= '1'; B <= '0'; C <= '0';
        wait for 10 ns;
        
        A <= '1'; B <= '0'; C <= '1';
        wait for 10 ns;
        
        A <= '1'; B <= '1'; C <= '0';
        wait for 10 ns;
        
        A <= '1'; B <= '1'; C <= '1';
        wait for 10 ns;
        wait;
    end process;

end architecture behavior;
