include make1.mk
include make2.mk
include make3.mk

main.o: main.c
	gcc -c main.c -o main.o


main: main.o src1.o src2.o src3.o
	gcc main.o src1.o src2.o src3.o -o main

clean:
	rm -f *.o main

.PHONY: clean