library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tb_srflipflop is
end tb_srflipflop;

architecture behavior of tb_srflipflop is
    -- Testbench signals
    signal S   : std_logic := '0';
    signal R   : std_logic := '0';
    signal CLK : std_logic := '0';
    signal Q   : std_logic;
    signal QN  : std_logic;

    -- Component declaration for SR Flip-Flop
    component SR_flip_flop
        port(
            S   : in std_logic;
            R   : in std_logic;
            CLK : in std_logic;
            Q   : out std_logic;
            QN  : out std_logic
        );
    end component;

begin
    -- Instantiate the SR Flip-Flop under test
    uut: SR_flip_flop port map(S => S, R => R, CLK => CLK, Q => Q, QN => QN);

    -- Clock generation process
    clk_process : process
    begin
        CLK <= '0';
        wait for 10 ns;
        CLK <= '1';
        wait for 10 ns;
    end process clk_process;

    -- Stimulus generation process
    stim_proc: process
    begin
        -- Test case 1: Set=0, Reset=0 (No change state)
        S <= '0';
        R <= '0';
        wait for 20 ns;

        -- Test case 2: Set=1, Reset=0 (Set Q to 1)
        S <= '1';
        R <= '0';
        wait for 20 ns;

        -- Test case 3: Set=0, Reset=1 (Reset Q to 0)
        S <= '0';
        R <= '1';
        wait for 20 ns;

        -- Test case 4: Set=1, Reset=1 (Invalid state for SR flip-flop)
        S <= '1';
        R <= '1';
        wait for 20 ns;

        -- Test case 5: Return to no change state Set=0, Reset=0
        S <= '0';
        R <= '0';
        wait for 20 ns;

        -- Stop simulation
        wait;
    end process stim_proc;

end behavior;
