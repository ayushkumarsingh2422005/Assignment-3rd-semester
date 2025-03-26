library ieee;
use ieee.std_logic_1164.all;

entity halfsubtractor is
    port (
        A     : in std_logic;
        B     : in std_logic;
        Bout  : out std_logic;
        Diff  : out std_logic
    );
end entity halfsubtractor;

architecture rtl of halfsubtractor is
begin
    Diff <= A xnor B;
    Bout <= not A and B;
end architecture rtl;
