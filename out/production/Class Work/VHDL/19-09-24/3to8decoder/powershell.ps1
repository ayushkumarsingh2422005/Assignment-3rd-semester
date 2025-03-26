ghdl -a --work=work 2to4decoder.vhdl
ghdl -a --work=work 3to8decoder.vhdl
ghdl -a --work=work tb_3to8decoder.vhdl
ghdl -e --work=work tb_3to8decoder
ghdl -r tb_3to8decoder --stop-time=60ns --vcd=output_3to8.vcd
gtkwave .\output_3to8.vcd
