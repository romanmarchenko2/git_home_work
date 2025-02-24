bin_PROGRAMS = calculator
calculator_SOURCES = main.c add.c multiply.c calculator.h

clean-local:
	rm -rf *.o *.lo *.la *.a *.so *.obj .libs \
	aclocal.m4 autom4te.cache config.log config.status \
	depcomp install-sh missing Makefile.in \
	configure Makefile configure~ compile .deps/

clean-all:
	$(MAKE) clean
	sudo rm -f /usr/local/bin/my_calculator
	sudo rm -f /usr/local/include/my_calc.h