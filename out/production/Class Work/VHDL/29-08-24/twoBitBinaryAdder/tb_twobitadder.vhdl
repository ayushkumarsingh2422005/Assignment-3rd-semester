library ieee;
use ieee.std_logic_1164.all;

entity tb_twobitadder is
end entity tb_twobitadder;

architecture behavior of tb_twobitadder is
    component twobitadder
        port (
            A1   : in std_logic;
            A2   : in std_logic;
            B1   : in std_logic;
            B2   : in std_logic;
            Cin  : in std_logic;
            Cout : out std_logic;
            Sum1 : out std_logic;
            Sum2 : out std_logic
        );
    end component;
    signal A1   : std_logic := '0';
    signal A2   : std_logic := '0';
    signal B1   : std_logic := '0';
    signal B2   : std_logic := '0';
    signal Cin  : std_logic := '0';
    signal Cout : std_logic;
    signal Sum1 : std_logic;
    signal Sum2 : std_logic;

begin
    UUT: twobitadder
        port map (
            A1 => A1,
            A2 => A2,
            B1 => B1,
            B2 => B2,
            Cin => Cin,
            Cout => Cout,
            Sum1 => Sum1,
            Sum2 => Sum2
        );
    stim_proc: process
    begin        
        A1 <= '0'; A2 <= '0'; B1 <= '0'; B2 <= '0'; Cin <= '0';
        wait for 10 ns;
        A1 <= '1'; A2 <= '0'; B1 <= '1'; B2 <= '0'; Cin <= '0';
        wait for 10 ns;
        A1 <= '0'; A2 <= '1'; B1 <= '0'; B2 <= '1'; Cin <= '0';
        wait for 10 ns;
        A1 <= '1'; A2 <= '1'; B1 <= '1'; B2 <= '1'; Cin <= '1';
        wait for 10 ns;
        A1 <= '0'; A2 <= '1'; B1 <= '1'; B2 <= '0'; Cin <= '1';
        wait for 10 ns;
        A1 <= '1'; A2 <= '1'; B1 <= '0'; B2 <= '0'; Cin <= '1';
        wait for 10 ns;
        wait;
    end process;

end architecture behavior;
