ajedrez: tablero_en_curso2.o tirada.o tirada_humano.o movimientos.o
	gcc -g -o ajedrez -lncurses tablero_en_curso2.o tirada.o tirada_humano.o movimientos.o

tablero_en_curso2.o: tablero_en_curso2.c tablero_en_curso2.h
	gcc -g -c tablero_en_curso2.c 

tirada.o: tirada.c tirada.h
	gcc -g -c tirada.c

tirada_humano.o: tirada_humano.c tirada_humano.h
	gcc -g -c tirada_humano.c
	
movimientos.o: movimientos.c movimientos.h
	gcc -g -c movimientos.c
