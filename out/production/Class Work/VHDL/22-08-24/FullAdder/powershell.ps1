ghdl -a --work=work halfadder.vhdl
ghdl -a --work=work fulladder.vhdl
ghdl -a --work=work fulladder_wb.vhdl
ghdl -e --work=work tb_fulladder
ghdl -r tb_fulladder --stop-time=60ns --vcd=output.vcd
