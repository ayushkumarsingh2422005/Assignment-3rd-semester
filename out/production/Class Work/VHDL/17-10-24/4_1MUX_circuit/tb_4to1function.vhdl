library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tb_4to1function is
end tb_4to1function;

architecture Behavioral of tb_4to1function is
    component function_4_1
        port (
            i0 : in std_logic;
            i1 : in std_logic;
            i2 : in std_logic;
            o : out std_logic
        );
    end component;
    
    -- Signals to connect to the inputs and output of function_4_1
    signal i0 : std_logic := '0';
    signal i1 : std_logic := '0';
    signal i2 : std_logic := '0';
    signal o : std_logic;

begin
    -- Instantiate the function_4_1 module (Unit Under Test)
    UUT: function_4_1
        port map (
            i0 => i0,
            i1 => i1,
            i2 => i2,
            o => o
        );

    -- Test process to apply input stimulus
    process
    begin
        -- Test case 1
        i0 <= '1';
        i1 <= '0';
        i2 <= '0';
        wait for 10 ns;

        -- Test case 2
        i0 <= '1';
        i1 <= '0';
        i2 <= '1';
        wait for 10 ns;

        -- Test case 3
        i0 <= '1';
        i1 <= '1';
        i2 <= '0';
        wait for 10 ns;

        -- Test case 4
        i0 <= '1';
        i1 <= '1';
        i2 <= '1';
        wait for 10 ns;

        -- Test case 5
        i0 <= '0';
        i1 <= '0';
        i2 <= '0';
        wait for 10 ns;

        -- Test case 6
        i0 <= '0';
        i1 <= '0';
        i2 <= '1';
        wait for 10 ns;

        -- Test case 7
        i0 <= '0';
        i1 <= '1';
        i2 <= '0';
        wait for 10 ns;

        -- Test case 8
        i0 <= '0';
        i1 <= '1';
        i2 <= '1';
        wait;

    end process;
end Behavioral;
