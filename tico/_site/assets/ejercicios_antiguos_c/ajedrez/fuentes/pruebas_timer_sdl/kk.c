#include <stdio.h>
#include <SDL/SDL.h>


SDL_TimerID temporizador;	// Identificador del temporizador
SDL_Surface *pantalla;		

void iniciar_SDL(long *reloj);
void terminar_SDL();
Uint32 actualizar_reloj(Uint32 intervalo, long *reloj);




// Programilla de prueba. Inicia el sistema SDL y permanece sin hacer nada hasta que se pulsa la tecla ESCAPE.
// Lo único que ocurrirá es que, cada segundo, saltará la función actualizar_reloj() por efecto del temporizador.
int main(void)
{
	int terminar = 0;
	long reloj = time(NULL);	// Coge la hora actual
	SDL_Event evento;

	iniciar_SDL(&reloj);

	while (terminar == 0)		// Bucle de "juego"
	{
		SDL_WaitEvent(&evento);		// Espera a que ocurra algún evento

		switch (evento.type)
		{
			case SDL_KEYDOWN:		// El evento es que se ha pulsado una tecla
         			switch (evento.key.keysym.sym)			// Miramos qué tecla es
				{
			        	case SDLK_ESCAPE: terminar = 1;		// La tecla es ESCAPE
           		        	terminar = -1;				// Salir del programa
                         		break;
         			}
		}
	}

	terminar_SDL();
} 


// Inicialización del sistema SDL
void iniciar_SDL(long *reloj)
{
	// Inicia SDL (vídeo + timer)
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	// Inicia la pantalla gráfica
	pantalla = SDL_SetVideoMode(800, 600, 16, SDL_ANYFORMAT | SDL_DOUBLEBUF);
	// Establece el temporizador: cada 1000 milisegundos se llamará a la función actualizar_reloj()
	temporizador = SDL_AddTimer(1000, actualizar_reloj, reloj);
}



// Finalización del sistema SDL
void terminar_SDL()
{
	// Elimina temporizador
	SDL_RemoveTimer(temporizador);
	// Finaliza SDL
	SDL_Quit();
}


// Actualiza la variable reloj y la imprime en la consola en formato HH:MM:SS
Uint32 actualizar_reloj(Uint32 intervalo, long *reloj)
{
	(*reloj)++;
	printf("Valor actual del reloj: %02li:%02li:%02li\n", ((*reloj)/60/60)%24, ((*reloj)/60)%60, (*reloj)%60);
	return intervalo;
}
