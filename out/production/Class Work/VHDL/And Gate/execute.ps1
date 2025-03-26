ghdl -a --work=work and3.vhdl

ghdl -a --work=work and3_tb.vhdl

ghdl -e --work=work and3_tb

ghdl -r and3_tb --stop-time=50ns --vcd=out4.vcd

# gtkwave out4.vcd