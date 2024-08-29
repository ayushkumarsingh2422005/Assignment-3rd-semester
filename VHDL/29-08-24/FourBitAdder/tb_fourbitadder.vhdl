library ieee;
use ieee.std_logic_1164.all;

entity tb_fourbitadder is
end entity tb_fourbitadder;

architecture behavior of tb_fourbitadder is

    -- Component declaration of the Unit Under Test (UUT)
    component fourbitadder
        port (
            A  : in std_logic_vector(3 downto 0);
            B  : in std_logic_vector(3 downto 0);
            Cin  : in std_logic;
            Cout : out std_logic;
            Sum  : out std_logic_vector(3 downto 0)
        );
    end component;

    -- Signals to connect to UUT
    signal A   : std_logic_vector(3 downto 0) := "0000";
    signal B   : std_logic_vector(3 downto 0) := "0000";
    signal Cin : std_logic := '0';
    signal Cout : std_logic;
    signal Sum  : std_logic_vector(3 downto 0);

begin

    -- Instantiate the Unit Under Test (UUT)
    UUT: fourbitadder
        port map (
            A => A,
            B => B,
            Cin => Cin,
            Cout => Cout,
            Sum => Sum
        );

    -- Stimulus process
    stim_proc: process
    begin        
        -- Test Case 1: A = 0000, B = 0000, Cin = 0
        A <= "0000"; B <= "0000"; Cin <= '0';
        wait for 10 ns;
        
        -- Test Case 2: A = 0001, B = 0001, Cin = 0
        A <= "0001"; B <= "0001"; Cin <= '0';
        wait for 10 ns;

        -- Test Case 3: A = 0101, B = 0011, Cin = 0
        A <= "0101"; B <= "0011"; Cin <= '0';
        wait for 10 ns;

        -- Test Case 4: A = 1010, B = 0101, Cin = 1
        A <= "1010"; B <= "0101"; Cin <= '1';
        wait for 10 ns;

        -- Test Case 5: A = 1111, B = 1111, Cin = 1
        A <= "1111"; B <= "1111"; Cin <= '1';
        wait for 10 ns;

        -- End simulation
        wait;
    end process;

end architecture behavior;
