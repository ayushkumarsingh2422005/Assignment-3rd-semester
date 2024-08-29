library ieee;
use ieee.std_logic_1164.all;

entity fullsubtractor is
    port (
        A     : in std_logic;
        B     : in std_logic;
        Bin   : in std_logic;
        Bout  : out std_logic;
        Diff  : out std_logic
    );
end entity fullsubtractor;

architecture rtl of fullsubtractor is
    signal Diff1, Bout1, Bout2: std_logic;
    
    component halfsubtractor is
        port (
            A     : in std_logic;
            B     : in std_logic;
            Bout  : out std_logic;
            Diff  : out std_logic
        );
    end component;

begin
    HS1: halfsubtractor port map (
        A => A,
        B => B,
        Bout => Bout1,
        Diff => Diff1
    );
    
    HS2: halfsubtractor port map (
        A => Diff1,
        B => Bin,
        Bout => Bout2,
        Diff => Diff
    );
    
    Bout <= Bout1 or Bout2;

end architecture rtl;
