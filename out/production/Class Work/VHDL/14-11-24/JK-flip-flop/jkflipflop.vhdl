library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity JK_flip_flop is
    port(
        J   : in std_logic;
        K   : in std_logic;
        CLK : in std_logic;
        Q   : out std_logic;
        QN  : out std_logic  -- Complement of Q
    );
end JK_flip_flop;

architecture structural of JK_flip_flop is
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
    -- First cross-coupled NAND gate for JK flip-flop
    nand1: nand2_gate port map(A => J, B => nand2_out, Y => nand1_out);  -- Output for Q
    nand2: nand2_gate port map(A => K, B => nand1_out, Y => nand2_out);  -- Output for QN

    -- Second cross-coupled NAND gate for JK flip-flop
    nand3: nand3_gate port map(A => nand1_out, B => CLK, C => nand4_out, Y => nand3_out);  -- For Q
    nand4: nand3_gate port map(A => nand2_out, B => CLK, C => nand3_out, Y => nand4_out);  -- For QN

    -- Assign the final outputs
    Q <= nand3_out;
    QN <= nand4_out;

end structural;
