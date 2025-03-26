ghdl -a --work=work halfadder.vhdl
ghdl -a --work=work fulladder.vhdl
ghdl -a --work=work fourbitadder.vhdl
ghdl -a --work=work tb_fourbitadder.vhdl
ghdl -e --work=work tb_fourbitadder
ghdl -r tb_fourbitadder --stop-time=60ns --vcd=output.vcd
