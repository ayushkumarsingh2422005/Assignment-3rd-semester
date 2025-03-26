library ieee;
use ieee.std_logic_1164.all;

entity twoToFourDecoder is
    port(
        A  : in  std_logic;
        B  : in  std_logic;
        D0 : out std_logic;
        D1 : out std_logic;
        D2 : out std_logic;
        D3 : out std_logic
    );
end entity twoToFourDecoder;

architecture rtl of twoToFourDecoder is
begin
    D0 <= (not A) and (not B);
    D1 <= (not A) and B;
    D2 <= A and (not B);
    D3 <= A and B;
end architecture rtl;
