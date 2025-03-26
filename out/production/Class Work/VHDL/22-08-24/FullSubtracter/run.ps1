# Compile the VHDL files
ghdl -a --work=work halfsubtractor.vhdl
ghdl -a --work=work fullsubtractor.vhdl
ghdl -a --work=work tb_fullsubtractor.vhdl

# Elaborate the testbench
ghdl -e --work=work tb_fullsubtractor

# Run the simulation and generate a VCD file
ghdl -r tb_fullsubtractor --stop-time=60ns --vcd=output.vcd
