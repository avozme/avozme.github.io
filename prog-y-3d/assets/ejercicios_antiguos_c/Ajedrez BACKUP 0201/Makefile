ajedrez: ajedrez.o movs.o io.o ini_fin.o
	gcc -g -I/usr/include/SDL -D_REENTRANT -o ajedrez ajedrez.o movs.o io.o ini_fin.o -lncurses -L/usr/lib -Wl,-rpath,/usr/lib -lSDL -lpthread

ajedrez.o: ajedrez.c tipos.h
	gcc -g -c ajedrez.c

movs.o: movs.c tipos.h movs.h
	gcc -g -c movs.c

io.o: io.c tipos.h io.h bitmaps.h
	gcc -g -c io.c
	
ini_fin.o: ini_fin.c tipos.h ini_fin.h
	gcc -g -c ini_fin.c

clean:
	rm -f ajedrez *.o

