ghdl -a --work=work halfadder.vhdl
ghdl -a --work=work fulladder.vhdl
ghdl -a --work=work four_bit_composit_adder.vhdl
ghdl -a --work=work tb_four_bit_composite_adder.vhdl

# Elaborate the testbench
ghdl -e --work=work tb_four_bit_composite_adder

# Run the simulation and generate a VCD file
ghdl -r tb_four_bit_composite_adder --stop-time=60ns --vcd=output.vcd

gtkwave output.vcd