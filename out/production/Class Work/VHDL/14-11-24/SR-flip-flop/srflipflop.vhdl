library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity SR_flip_flop is
    port(
        S   : in std_logic;
        R   : in std_logic;
        CLK : in std_logic;
        Q   : out std_logic;
        QN  : out std_logic  -- Complement of Q
    );
end SR_flip_flop;

architecture structural of SR_flip_flop is
    -- Signals for internal connections
    signal nand1_out, nand2_out, nand3_out, nand4_out : std_logic;

    -- Component declaration for 2-input NAND gate
    component nand2_gate
        port(
            A : in std_logic;
            B : in std_logic;
            Y : out std_logic
        );
    end component;

begin
    -- First cross-coupled NAND gate for SR flip-flop
    nand1: nand2_gate port map(A => S, B => nand2_out, Y => nand1_out);  -- Output for Q
    nand2: nand2_gate port map(A => R, B => nand1_out, Y => nand2_out);  -- Output for QN

    -- Second cross-coupled NAND gate for SR flip-flop
    nand3: nand2_gate port map(A => nand1_out, B => CLK, Y => nand3_out);  -- For Q
    nand4: nand2_gate port map(A => nand2_out, B => CLK, Y => nand4_out);  -- For QN

    -- Assign the final outputs
    Q <= nand3_out;
    QN <= nand4_out;

end structural;
