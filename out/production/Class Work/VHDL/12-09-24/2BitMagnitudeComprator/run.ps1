ghdl -a Comparator_2bit.vhdl
ghdl -a tb_Comparator_2bit.vhdl
ghdl -e tb_Comparator_2bit
ghdl -r tb_Comparator_2bit --stop-time=70ns --vcd=output.vcd
gtkwave .\output.vcd