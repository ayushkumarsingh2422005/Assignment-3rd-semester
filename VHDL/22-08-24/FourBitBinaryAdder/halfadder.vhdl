library ieee;
use ieee.std_logic_1164.all;

entity halfadder is
    port (
        A     : in std_logic;
        B     : in std_logic;
        carry : out std_logic;
        sum   : out std_logic
    );
end entity halfadder;

architecture rtl of halfadder is
begin
    sum <= A xor B;
    carry <= A and B;
end architecture rtl;
