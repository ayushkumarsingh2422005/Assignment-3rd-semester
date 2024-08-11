ghdl -a --work=work xor3.vhdl

ghdl -a --work=work xor3_tb.vhdl

ghdl -e --work=work xor3_tb

ghdl -r xor3_tb --stop-time=50ns --vcd=out4.vcd

# gtkwave out4.vcd