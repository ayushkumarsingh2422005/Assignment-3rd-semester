ghdl -a --work=work or3.vhdl

ghdl -a --work=work or3_tb.vhdl

ghdl -e --work=work or3_tb

ghdl -r or3_tb --stop-time=50ns --vcd=out4.vcd

# gtkwave out4.vcd