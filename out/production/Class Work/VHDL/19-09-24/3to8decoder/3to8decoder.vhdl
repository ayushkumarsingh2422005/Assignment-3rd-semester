library ieee;
use ieee.std_logic_1164.all;

entity threeToEightDecoder is
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
end entity threeToEightDecoder;

architecture structural of threeToEightDecoder is

    signal lower_select : std_logic_vector(3 downto 0);
    signal upper_select : std_logic_vector(3 downto 0);

    component twoToFourDecoder
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
    lower: twoToFourDecoder
        port map(
            A => B,
            B => C,
            D0 => lower_select(0),
            D1 => lower_select(1),
            D2 => lower_select(2),
            D3 => lower_select(3)
        );
    upper: twoToFourDecoder
        port map(
            A => B,
            B => C,
            D0 => upper_select(0),
            D1 => upper_select(1),
            D2 => upper_select(2),
            D3 => upper_select(3)
        );
    D0 <= lower_select(0) when A = '0' else '0';
    D1 <= lower_select(1) when A = '0' else '0';
    D2 <= lower_select(2) when A = '0' else '0';
    D3 <= lower_select(3) when A = '0' else '0';

    D4 <= upper_select(0) when A = '1' else '0';
    D5 <= upper_select(1) when A = '1' else '0';
    D6 <= upper_select(2) when A = '1' else '0';
    D7 <= upper_select(3) when A = '1' else '0';

end architecture structural;
