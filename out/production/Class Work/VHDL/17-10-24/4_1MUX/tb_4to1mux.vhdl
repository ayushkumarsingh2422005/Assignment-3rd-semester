library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tb_4to1mux is
end tb_4to1mux;

architecture Behavioral of tb_4to1mux is
    component Mux_4bit
        port (
            I0 : in std_logic;
            I1 : in std_logic;
            I2 : in std_logic;
            I3 : in std_logic;
            C0 : in std_logic;
            C1 : in std_logic;
            S : out std_logic
        );
    end component;
    signal I0 : std_logic;
    signal I1 : std_logic;
    signal I2 : std_logic;
    signal I3 : std_logic;
    signal C0 : std_logic;
    signal C1 : std_logic;
    signal S :  std_logic;

begin
    UUT: Mux_4bit
        Port map (
            I0 => I0,
            I1 => I1,
            I2 => I2,
            I3 => I3,
            C0 => C0,
            C1 => C1,
            S  =>  S
        );
        process
        begin
            I0 <= '1';
            I1 <= '0';
            I2 <= '0';
            I3 <= '0';
            C0 <= '0';
            C1 <= '0';
            wait for 10 ns;
            I0 <= '0';
            I1 <= '0';
            I2 <= '0';
            I3 <= '0';
            C0 <= '1';
            C1 <= '0';
            wait for 10 ns;
            I0 <= '0';
            I1 <= '1';
            I2 <= '0';
            I3 <= '0';
            C0 <= '1';
            C1 <= '0';
            wait for 10 ns;
            I0 <= '0';
            I1 <= '1';
            I2 <= '1';
            I3 <= '0';
            C0 <= '0';
            C1 <= '1';
            wait for 10 ns;
            I0 <= '1';
            I1 <= '1';
            I2 <= '1';
            I3 <= '0';
            C0 <= '1';
            C1 <= '1';
            wait for 10 ns;
            I0 <= '1';
            I1 <= '0';
            I2 <= '0';
            I3 <= '1';
            C0 <= '1';
            C1 <= '1';
            wait for 10 ns;
            I0 <= '0';
            I1 <= '1';
            I2 <= '1';
            I3 <= '0';
            C0 <= '0';
            C1 <= '0';
            wait;
        end process;
end Behavioral;