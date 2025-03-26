ghdl -a --work=work bool.vhdl

ghdl -a --work=work bool_tb.vhdl

ghdl -e --work=work bool_tb

ghdl -r bool_tb --stop-time=90ns --vcd=out4.vcd

# gtkwave out4.vcd