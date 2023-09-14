ajedrez: ajedrez.o movs.o io.o ini_fin.o menu.o lista.o fich.o ia.o
	gcc -g -I/usr/include/SDL -D_REENTRANT -o ajedrez ajedrez.o movs.o io.o ini_fin.o menu.o lista.o fich.o ia.o -lncurses -L/usr/lib -Wl,-rpath,/usr/lib -lSDL -lSDL_ttf -lpthread

ajedrez.o: ajedrez.c tipos.h
	gcc -g -c ajedrez.c

movs.o: movs.c tipos.h movs.h
	gcc -g -c movs.c

io.o: io.c tipos.h io.h bitmaps.h
	gcc -g -c io.c
	
ini_fin.o: ini_fin.c tipos.h ini_fin.h
	gcc -g -c ini_fin.c

menu.o: menu.c menu.h tipos.h
	gcc -g -c menu.c

lista.o: lista.c lista.h tipos.h
	gcc -g -c lista.c

fich.o: fich.c fich.h tipos.h
	gcc -g -c fich.c

ia.o: ia.c ia.h tipos.h
	gcc -g -c ia.c

clean:
	rm -f ajedrez *.o

