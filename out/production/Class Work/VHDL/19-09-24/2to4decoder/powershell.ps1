ghdl -a --work=work 2to4decoder.vhdl
ghdl -a --work=work tb_2to4decoder.vhdl
ghdl -e --work=work tb_2to4decoder
ghdl -r tb_2to4decoder --stop-time=60ns --vcd=output.vcd
gtkwave .\output.vcd
