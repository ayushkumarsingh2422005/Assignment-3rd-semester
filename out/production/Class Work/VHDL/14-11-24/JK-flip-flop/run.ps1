# Analyze each VHDL file
ghdl -a nand2.vhdl
ghdl -a nand3.vhdl
# ghdl -a nand3.vhdl
ghdl -a jkflipflop.vhdl
ghdl -a tb_jkflipflop.vhdl

# Elaborate the testbench
ghdl -e tb_jkflipflop

# Run the simulation and generate the VCD waveform file
ghdl -r tb_jkflipflop --stop-time=100ns --vcd=output.vcd

# View the waveform in GTKWave
gtkwave output.vcd
