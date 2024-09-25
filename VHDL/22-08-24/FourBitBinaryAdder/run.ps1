ghdl -a --work=work halfadder.vhdl
ghdl -a --work=work fulladder.vhdl
ghdl -a --work=work four_bit_adder.vhdl
ghdl -a --work=work tb_four_bit_adder.vhdl

# Elaborate the testbench
ghdl -e --work=work tb_four_bit_adder

# Run the simulation and generate a VCD file
ghdl -r tb_four_bit_adder --stop-time=100ns --vcd=output.vcd
