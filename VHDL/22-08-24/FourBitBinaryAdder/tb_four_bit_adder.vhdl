library ieee;
use ieee.std_logic_1164.all;

entity tb_four_bit_adder is
end entity tb_four_bit_adder;

architecture behavior of tb_four_bit_adder is

    signal A, B: std_logic_vector(3 downto 0);
    signal Cin: std_logic;
    signal Sum: std_logic_vector(3 downto 0);
    signal Cout: std_logic;

    component four_bit_adder is
        port (
            A     : in std_logic_vector(3 downto 0);
            B     : in std_logic_vector(3 downto 0);
            Cin   : in std_logic;
            Sum   : out std_logic_vector(3 downto 0);
            Cout  : out std_logic
        );
    end component;

begin

    uut: four_bit_adder port map (
        A => A,
        B => B,
        Cin => Cin,
        Sum => Sum,
        Cout => Cout
    );

    process
    begin
        A <= "0000"; -- 0
        B <= "0000"; -- 0
        Cin <= '0';
        wait for 10 ns;
        
        A <= "0001"; -- 1
        B <= "0011"; -- 3
        Cin <= '0';
        wait for 10 ns;

        A <= "0011"; -- 3
        B <= "0100"; -- 4
        Cin <= '0';
        wait for 10 ns;

        A <= "0010"; -- 2
        B <= "0101"; -- 5
        Cin <= '0';
        wait for 10 ns;

        A <= "0001"; -- 1
        B <= "0010"; -- 2
        Cin <= '0';
        wait for 10 ns;

        A <= "0100";
        B <= "0101";
        Cin <= '0';
        wait for 10 ns;

        A <= "0111";
        B <= "0011";
        Cin <= '1';
        wait for 10 ns;

        A <= "1111";
        B <= "1111";
        Cin <= '1';
        wait for 10 ns;

        wait;
    end process;

end architecture behavior;
