ghdl -a 4to1mux.vhdl
ghdl -a tb_4to1mux.vhdl
ghdl -e tb_4to1mux
ghdl -r tb_4to1mux --stop-time=70ns --vcd=output.vcd
gtkwave .\output.vcd