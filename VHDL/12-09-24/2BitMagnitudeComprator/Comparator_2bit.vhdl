library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity Comparator_2bit is
    Port (
        A : in STD_LOGIC_VECTOR(1 downto 0);
        B : in STD_LOGIC_VECTOR(1 downto 0);
        A_gt_B : out STD_LOGIC;
        A_lt_B : out STD_LOGIC;
        A_eq_B : out STD_LOGIC
    );
end Comparator_2bit;
architecture Gate_Level of Comparator_2bit is
begin
    A_eq_B <= (not (A(1) xor B(1))) and (not (A(0) xor B(0)));
    A_gt_B <= (A(1) and not B(1)) or (A(0) and not B(0) and (not (A(1) xor B(1))));
    A_lt_B <= (not A(1) and B(1)) or (not A(0) and B(0) and (not (A(1) xor B(1))));
end Gate_Level;
