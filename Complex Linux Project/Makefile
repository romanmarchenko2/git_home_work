CC = gcc
CFLAGS = -Wall
AR = ar
ARFLAGS = rcs

PREFIX = /usr/local
LIBDIR = $(PREFIX)/lib
BINDIR = $(PREFIX)/bin

CALC_LIB = calculator/libcalc.a
TRANS_LIB = transformer/libtransform.dylib 

# Static lib
calc: calculator/calc
calculator/calc: calculator/main.o $(CALC_LIB)
	$(CC) $(CFLAGS) $^ -o $@

$(CALC_LIB): calculator/basic_ops.o calculator/advanced_ops.o calculator/fraction_ops.o
	$(AR) $(ARFLAGS) $@ $^

# Dynamic lib
transformer: transformer/upper transformer/lower

$(TRANS_LIB): transformer/transform_lib.o
	$(CC) -shared -fPIC $^ -o $@ -install_name $(LIBDIR)/libtransform.dylib

transformer/upper: transformer/upper.c $(TRANS_LIB)
	$(CC) $(CFLAGS) $< -L transformer -ltransform -o $@

transformer/lower: transformer/lower.c $(TRANS_LIB)
	$(CC) $(CFLAGS) $< -L transformer -ltransform -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

transformer/transform_lib.o: transformer/transform_lib.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

all: calc transformer

install: all
	install -d $(BINDIR) $(LIBDIR)
	install -m 755 calculator/calc $(BINDIR)
	install -m 755 transformer/upper transformer/lower $(BINDIR)
	install -m 644 $(TRANS_LIB) $(LIBDIR)/libtransform.dylib

clean:
	find calculator transformer -type f ! -name '*.c' ! -name '*.h' -delete
	find calculator transformer -type d -empty -delete

.PHONY: all clean install calc transformer