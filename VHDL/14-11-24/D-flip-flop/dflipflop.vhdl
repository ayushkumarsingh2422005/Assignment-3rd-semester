library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity D_flip_flop is
    port(
        D   : in std_logic;
        CLK : in std_logic;
        Q   : out std_logic;
        QN  : out std_logic  -- Complement of Q
    );
end D_flip_flop;

architecture structural of D_flip_flop is
    -- Signals for internal connections
    signal nand1_out, nand2_out, nand3_out, nand4_out, nand5_out, nand6_out : std_logic;

    -- Component declaration for 2-input NAND gate
    component nand2_gate
        port(
            A : in std_logic;
            B : in std_logic;
            Y : out std_logic
        );
    end component;

    -- Component declaration for 3-input NAND gate
    component nand3_gate
        port(
            A : in std_logic;
            B : in std_logic;
            C : in std_logic;
            Y : out std_logic
        );
    end component;

begin
    -- 3-input NAND gates for the initial D and CLK inputs
    nand1: nand2_gate port map(A => nand4_out, B => nand2_out, Y => nand1_out);
    nand2: nand2_gate port map(A => nand1_out, B => CLK, Y => nand2_out);

    nand3: nand3_gate port map(A => nand2_out, B => CLK, C => nand4_out, Y => nand3_out);
    nand4: nand2_gate port map(A => nand3_out, B => D, Y => nand4_out);

    nand5: nand2_gate port map(A => nand2_out, B => nand6_out, Y => nand5_out);
    nand6: nand2_gate port map(A => nand3_out, B => nand5_out, Y => nand6_out);

    Q <= nand5_out;
    QN <= nand6_out;

end structural;
