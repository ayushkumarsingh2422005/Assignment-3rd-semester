# Analyze each VHDL file
ghdl -a nand2.vhdl
ghdl -a nand3.vhdl
ghdl -a dflipflop.vhdl
ghdl -a tb_dflipflop.vhdl

# Elaborate the testbench
ghdl -e tb_dflipflop

# Run the simulation and generate the VCD waveform file
ghdl -r tb_dflipflop --stop-time=100ns --vcd=output.vcd

# View the waveform in GTKWave
gtkwave output.vcd
