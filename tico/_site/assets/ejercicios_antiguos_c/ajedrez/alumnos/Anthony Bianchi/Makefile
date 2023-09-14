ajedrez: tablero.o mov.o
	gcc -o ajedrez -lncurses tablero.o mov.o

tablero.o: tablero.c tablero.h
	gcc -g -c tablero.c

mov.o: mov.c mov.h
	gcc -g -c mov.c

