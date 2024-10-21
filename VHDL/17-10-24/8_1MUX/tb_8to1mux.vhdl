library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity tb_8to1mux is
end tb_8to1mux;

architecture Behavioral of tb_8to1mux is
    component Mux_8bit
        port (
            i0 : in std_logic;
            i1 : in std_logic;
            i2 : in std_logic;
            i3 : in std_logic;
            i4 : in std_logic;
            i5 : in std_logic;
            i6 : in std_logic;
            i7 : in std_logic;
            c0 : in std_logic;
            c1 : in std_logic;
            c2 : in std_logic;
            s : out std_logic
        );
    end component;
    signal i0 : std_logic;
    signal i1 : std_logic;
    signal i2 : std_logic;
    signal i3 : std_logic;
    signal i4 : std_logic;
    signal i5 : std_logic;
    signal i6 : std_logic;
    signal i7 : std_logic;
    signal c0 : std_logic;
    signal c1 : std_logic;
    signal c2 : std_logic;
    signal s :  std_logic;

begin
    UUT: Mux_8bit
        Port map (i0, i1, i2, i3, i4, i5, i6, i7, c0, c1, c2, s);
        process
        begin
            i0 <= '1';
            i1 <= '0';
            i2 <= '0';
            i3 <= '0';
            i4 <= '0';
            i5 <= '0';
            i6 <= '0';
            i7 <= '0';
            c0 <= '0';
            c1 <= '0';
            c2 <= '0';
            wait for 10 ns;
            i0 <= '1';
            i1 <= '0';
            i2 <= '0';
            i3 <= '1';
            i4 <= '0';
            i5 <= '0';
            i6 <= '0';
            i7 <= '0';
            c0 <= '0';
            c1 <= '1';
            c2 <= '0';
            wait for 10 ns;
            i0 <= '1';
            i1 <= '0';
            i2 <= '0';
            i3 <= '0';
            i4 <= '0';
            i5 <= '1';
            i6 <= '0';
            i7 <= '0';
            c0 <= '0';
            c1 <= '1';
            c2 <= '1';
            wait for 10 ns;
            i0 <= '1';
            i1 <= '0';
            i2 <= '0';
            i3 <= '0';
            i4 <= '0';
            i5 <= '0';
            i6 <= '0';
            i7 <= '1';
            c0 <= '1';
            c1 <= '1';
            c2 <= '0';
            wait for 10 ns;
            i0 <= '1';
            i1 <= '0';
            i2 <= '0';
            i3 <= '0';
            i4 <= '0';
            i5 <= '0';
            i6 <= '0';
            i7 <= '1';
            c0 <= '1';
            c1 <= '0';
            c2 <= '1';
            wait for 10 ns;
            
            wait;
        end process;
end Behavioral;