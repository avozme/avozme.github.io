ajedrez: ajedrez.o movimientos.o caguvi.o
	gcc -o ajedrez -lmenu ajedrez.o movimientos.o caguvi.o

ajedrez.o: ajedrez.c ajedrez.h
	gcc -c -lmenu ajedrez.c
movimientos.o: movimientos.c movimientos.h
	gcc -c -lmenu movimientos.c
opmen.o: opmen.c caguvi.h 
	gcc -c -lmenu caguvi.c
