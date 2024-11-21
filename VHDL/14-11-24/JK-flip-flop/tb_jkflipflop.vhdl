library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tb_jkflipflop is
end tb_jkflipflop;

architecture behavior of tb_jkflipflop is
    -- Testbench signals
    signal J   : std_logic := '0';
    signal K   : std_logic := '0';
    signal CLK : std_logic := '0';
    signal Q   : std_logic;
    signal QN  : std_logic;

    -- Component declaration for JK Flip-Flop
    component JK_flip_flop
        port(
            J   : in std_logic;
            K   : in std_logic;
            CLK : in std_logic;
            Q   : out std_logic;
            QN  : out std_logic
        );
    end component;

begin
    -- Instantiate the JK Flip-Flop under test
    uut: JK_flip_flop port map(J => J, K => K, CLK => CLK, Q => Q, QN => QN);

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
        -- Test case 1: J=0, K=0 (No change state)
        J <= '0';
        K <= '0';
        wait for 20 ns;

        -- Test case 2: J=1, K=0 (Set Q to 1)
        J <= '1';
        K <= '0';
        wait for 20 ns;

        -- Test case 3: J=0, K=1 (Set Q to 0)
        J <= '0';
        K <= '1';
        wait for 20 ns;

        -- Test case 4: J=1, K=1 (Toggle state of Q)
        J <= '1';
        K <= '1';
        wait for 20 ns;

        -- Test case 5: Return to no change state J=0, K=0
        J <= '0';
        K <= '0';
        wait for 20 ns;

        -- Stop simulation
        wait;
    end process stim_proc;


end behavior;
