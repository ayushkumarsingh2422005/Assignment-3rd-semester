ghdl -a --work=work halfadder.vhdl

ghdl -a --work=work view.vhdl

ghdl -e --work=work view

ghdl -r view --stop-time=60ns --vcd=out4.vcd