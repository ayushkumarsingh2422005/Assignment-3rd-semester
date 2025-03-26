library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_four_bit_composite_adder is
    -- Testbench entity has no ports
end entity tb_four_bit_composite_adder;

architecture tb of tb_four_bit_composite_adder is

    -- Signal declarations for the adder inputs and outputs
    signal A    : std_logic_vector(3 downto 0);
    signal B    : std_logic_vector(3 downto 0);
    signal Cin  : std_logic;
    signal Sum  : std_logic_vector(3 downto 0);
    signal Cout : std_logic;

    -- Component declaration for the adder under test
    component four_bit_composite_adder is
        port (
            A    : in  std_logic_vector(3 downto 0);
            B    : in  std_logic_vector(3 downto 0);
            Cin  : in  std_logic;
            Sum  : out std_logic_vector(3 downto 0);
            Cout : out std_logic
        );
    end component;

begin

    -- Instantiate the Unit Under Test (UUT)
    uut: four_bit_composite_adder port map (
        A    => A,
        B    => B,
        Cin  => Cin,
        Sum  => Sum,
        Cout => Cout
    );

    -- Test process to apply test cases
    stimulus: process
    begin
        -- Test case 1: A = 0001, B = 0010, Cin = 0
        A   <= "0001";
        B   <= "0010";
        Cin <= '0';
        wait for 10 ns;
        assert (Sum = "0011" and Cout = '0')
            report "Test case 1 failed" severity error;

        -- Test case 2: A = 0101, B = 0101, Cin = 0
        A   <= "0101";
        B   <= "0101";
        Cin <= '0';
        wait for 10 ns;
        assert (Sum = "1010" and Cout = '0')
            report "Test case 2 failed" severity error;

        -- Test case 3: A = 1111, B = 0001, Cin = 0
        A   <= "1111";
        B   <= "0001";
        Cin <= '0';
        wait for 10 ns;
        assert (Sum = "0000" and Cout = '1')
            report "Test case 3 failed" severity error;

        -- Test case 4: A = 1111, B = 1111, Cin = 1
        A   <= "1111";
        B   <= "1111";
        Cin <= '1';
        wait for 10 ns;
        assert (Sum = "1111" and Cout = '1')
            report "Test case 4 failed" severity error;

        -- Test case 5: A = 0000, B = 0000, Cin = 1
        A   <= "0000";
        B   <= "0000";
        Cin <= '1';
        wait for 10 ns;
        assert (Sum = "0001" and Cout = '0')
            report "Test case 5 failed" severity error;

        -- All test cases have been applied; stop simulation
        wait;
    end process;

end architecture tb;
