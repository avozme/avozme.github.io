ajedrez: ajedrez.o piezas.o 
	gcc -g -o ajedrez -lncurses ajedrez.o piezas.o 

ajedrez.o: ajedrez.c ajedrez.h
	gcc -g -c ajedrez.c

piezas.o: piezas.c piezas.h
	gcc -g -c piezas.c

