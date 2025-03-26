library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tb_Comparator_2bit is
end tb_Comparator_2bit;

architecture Behavioral of tb_Comparator_2bit is
    component Comparator_2bit
        Port (
            A : in STD_LOGIC_VECTOR(1 downto 0);
            B : in STD_LOGIC_VECTOR(1 downto 0);
            A_gt_B : out STD_LOGIC;
            A_lt_B : out STD_LOGIC;
            A_eq_B : out STD_LOGIC
        );
    end component;
    signal A : STD_LOGIC_VECTOR(1 downto 0) := "00";
    signal B : STD_LOGIC_VECTOR(1 downto 0) := "00";
    signal A_gt_B : STD_LOGIC;
    signal A_lt_B : STD_LOGIC;
    signal A_eq_B : STD_LOGIC;

begin
    UUT: Comparator_2bit
        Port map (
            A => A,
            B => B,
            A_gt_B => A_gt_B,
            A_lt_B => A_lt_B,
            A_eq_B => A_eq_B
        );
    process
    begin
        A <= "00";
        B <= "00";
        wait for 10 ns;
        assert (A_gt_B = '0' and A_lt_B = '0' and A_eq_B = '1') 
            report "Test Case 1 Failed" severity error;
        A <= "01";
        B <= "00";
        wait for 10 ns;
        assert (A_gt_B = '1' and A_lt_B = '0' and A_eq_B = '0') 
            report "Test Case 2 Failed" severity error;
        A <= "00";
        B <= "01";
        wait for 10 ns;
        assert (A_gt_B = '0' and A_lt_B = '1' and A_eq_B = '0') 
            report "Test Case 3 Failed" severity error;
        A <= "10";
        B <= "01";
        wait for 10 ns;
        assert (A_gt_B = '1' and A_lt_B = '0' and A_eq_B = '0') 
            report "Test Case 4 Failed" severity error;
        A <= "11";
        B <= "10";
        wait for 10 ns;
        assert (A_gt_B = '1' and A_lt_B = '0' and A_eq_B = '0') 
            report "Test Case 5 Failed" severity error;
        A <= "10";
        B <= "11";
        wait for 10 ns;
        assert (A_gt_B = '0' and A_lt_B = '1' and A_eq_B = '0') 
            report "Test Case 6 Failed" severity error;
        wait;
    end process;
end Behavioral;
