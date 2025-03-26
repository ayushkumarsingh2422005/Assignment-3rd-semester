ghdl -a 4to1mux.vhdl
ghdl -a 8to1mux.vhdl
ghdl -a tb_8to1mux.vhdl
ghdl -e tb_8to1mux
ghdl -r tb_8to1mux --stop-time=70ns --vcd=output.vcd
gtkwave .\output.vcd