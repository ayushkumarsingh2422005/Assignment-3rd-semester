ghdl -a 4to1mux.vhdl
ghdl -a 4to1function.vhdl
ghdl -a tb_4to1function.vhdl
ghdl -e tb_4to1function
ghdl -r tb_4to1function --stop-time=70ns --vcd=output.vcd
gtkwave .\output.vcd