ajedrez: ajedrez.o e_s.o movimiento.o
	gcc -g -o ajedrez -lncurses ajedrez.o e_s.o movimiento.o

ajedrez.o: ajedrez.c ajedrez.h
	gcc -g -c ajedrez.c

e_s.o: e_s.c ajedrez.h
	gcc -g -c e_s.c

movimiento.o: movimiento.c ajedrez.h
	gcc -g -c movimiento.c