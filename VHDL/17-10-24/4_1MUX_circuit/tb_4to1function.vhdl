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
    signal i0 : std_logic;
    signal i1 : std_logic;
    signal i2 : std_logic;
    signal o :  std_logic;

begin
    UUT: tb_4to1function
        Port map (i0, i1, i2, o);
        process
        begin
            i0 <= '1';
            i1 <= '0';
            i2 <= '0';
            wait for 10 ns;
            i0 <= '1';
            i1 <= '0';
            i2 <= '1';
            wait for 10 ns;
            i0 <= '1';
            i1 <= '1';
            i2 <= '0';
            wait for 10 ns;
            i0 <= '1';
            i1 <= '1';
            i2 <= '1';
            wait for 10 ns;
            i0 <= '0';
            i1 <= '0';
            i2 <= '0';
            wait for 10 ns;
            i0 <= '0';
            i1 <= '0';
            i2 <= '1';
            wait for 10 ns;
            i0 <= '0';
            i1 <= '1';
            i2 <= '0';
            wait for 10 ns;
            i0 <= '0';
            i1 <= '1';
            i2 <= '1';
            wait;
        end process;
end Behavioral;