-- tb_dflipflop.vhdl

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tb_dflipflop is
end tb_dflipflop;

architecture behavior of tb_dflipflop is
    -- Testbench signals
    signal D   : std_logic := '0';
    signal CLK : std_logic := '0';
    signal Q   : std_logic;
    signal QN  : std_logic;

    -- Component declaration for D Flip-Flop
    component D_flip_flop
        port(
            D   : in std_logic;
            CLK : in std_logic;
            Q   : out std_logic;
            QN  : out std_logic
        );
    end component;

begin
    uut: D_flip_flop port map(D => D, CLK => CLK, Q => Q, QN => QN);

    clk_process : process
    begin
        CLK <= '0';
        wait for 10 ns;
        CLK <= '1';
        wait for 10 ns;
    end process clk_process;

    stim_proc: process
    begin
        -- Test case 1: Set D to 0
        D <= '0';
        wait for 20 ns;

        -- Test case 2: Set D to 1
        D <= '1';
        wait for 20 ns;

        -- Test case 3: Set D to 0 again
        D <= '0';
        wait for 20 ns;

        -- Test case 4: Set D to 1 again
        D <= '1';
        wait for 20 ns;

        -- Stop simulation
        wait;
    end process stim_proc;

end behavior;
