# Analyze each VHDL file
ghdl -a nand2.vhdl
# ghdl -a nand3.vhdl
ghdl -a srflipflop.vhdl
ghdl -a tb_srflipflop.vhdl

# Elaborate the testbench
ghdl -e tb_srflipflop

# Run the simulation and generate the VCD waveform file
ghdl -r tb_srflipflop --stop-time=100ns --vcd=output.vcd

# View the waveform in GTKWave
gtkwave output.vcd
