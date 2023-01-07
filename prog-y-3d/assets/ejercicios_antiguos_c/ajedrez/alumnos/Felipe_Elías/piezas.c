#include "ajedrez.h"
#include "piezas.h"



int caballo(struct casilla tablero[8][8], struct posicion *posicion, int valido)
{
	if((posicion->fila_destino == posicion->fila_origen+1) && (posicion->columna_destino == posicion->columna_origen+2))
	{
		valido=1;
	}
	if((posicion->fila_destino == posicion->fila_origen+2) && (posicion->columna_destino == posicion->columna_origen+1))
	{
		valido=1;
	}
	if((posicion->fila_destino == posicion->fila_origen+1) && (posicion->columna_destino == posicion->columna_origen-2))
	{
		valido=1;
	}
	if((posicion->fila_destino == posicion->fila_origen+2) && (posicion->columna_destino == posicion->columna_origen-1))
	{
		valido=1;
	}
	if((posicion->fila_destino == posicion->fila_origen-1) && (posicion->columna_destino == posicion->columna_origen+2))
	{
		valido=1;
	}
	if((posicion->fila_destino == posicion->fila_origen-2) && (posicion->columna_destino == posicion->columna_origen+1))
	{
		valido=1;
	}
	if((posicion->fila_destino == posicion->fila_origen-1) && (posicion->columna_destino == posicion->columna_origen-2))
	{
		valido=1;
	}
	if((posicion->fila_destino == posicion->fila_origen-2) && (posicion->columna_destino == posicion->columna_origen-1))
	{
		valido=1;
	}

return valido;
}

int peon(struct casilla tablero[8][8], struct s_estado *estado, struct posicion *posicion, int valido)
{
	if(estado->turno == 0)
	{
		if((posicion->fila_destino == posicion->fila_origen-1) && (posicion->columna_destino == posicion->columna_origen) && (tablero[posicion->fila_destino][posicion->columna_destino].color_ficha == 2))
		{
			valido=1;
		}
		if((posicion->fila_destino == posicion->fila_origen-1) && (posicion->columna_destino == posicion->columna_origen+1) && (tablero[posicion->fila_destino][posicion->columna_destino].color_ficha == 1))
		{
			valido=1;
		}
		if((posicion->fila_destino == posicion->fila_origen-1) && (posicion->columna_destino == posicion->columna_origen-1) && (tablero[posicion->fila_destino][posicion->columna_destino].color_ficha == 1))
		{
			valido=1;
		}
		if((posicion->fila_destino == posicion->fila_origen-2) && (posicion->columna_destino == posicion->columna_origen) && (tablero[posicion->fila_destino][posicion->columna_destino].color_ficha == 2) && (tablero[posicion->fila_destino+1][posicion->columna_destino].color_ficha == 2))
		{
			valido=1;
		}
	}
	if(estado->turno == 1)
	{
		if((posicion->fila_destino == posicion->fila_origen+1) && (posicion->columna_destino == posicion->columna_origen) && (tablero[posicion->fila_destino][posicion->columna_destino].color_ficha == 2))
		{
			valido=1;
		}
		if((posicion->fila_destino == posicion->fila_origen+1) && (posicion->columna_destino == posicion->columna_origen+1) && (tablero[posicion->fila_destino][posicion->columna_destino].color_ficha == 0))
		{
			valido=1;
		}
		if((posicion->fila_destino == posicion->fila_origen+1) && (posicion->columna_destino == posicion->columna_origen-1) && (tablero[posicion->fila_destino][posicion->columna_destino].color_ficha == 0))
		{
			valido=1;
		}
		if((posicion->fila_destino == posicion->fila_origen+2) && (posicion->columna_destino == posicion->columna_origen) && (tablero[posicion->fila_destino][posicion->columna_destino].color_ficha == 2) && (tablero[posicion->fila_destino-1][posicion->columna_destino].color_ficha == 2))
		{
			valido=1;
		}
	}

return valido;
}

int torre(struct casilla tablero[8][8], struct posicion *posicion, int valido)
{
int i;
	if(posicion->fila_origen == posicion->fila_destino)
	{
		if(posicion->columna_destino > posicion->columna_origen)
		{
			for(i = posicion->columna_origen+1; i < posicion->columna_destino; i++)
			{
				if(tablero[posicion->fila_destino][i].color_ficha == 2)
				{
					valido=1;
				}
			}
		}
		if(posicion->columna_destino < posicion->columna_origen)
		{
			for(i = posicion->columna_origen-1; i > posicion->columna_destino; i--)
			{
				if(tablero[posicion->fila_destino][i].color_ficha == 2)
				{
					valido=1;
				}
			}
		}
	}
	if(posicion->columna_origen == posicion->columna_destino)
	{
		if(posicion->fila_destino > posicion->fila_origen)
		{
			for(i = posicion->fila_origen+1; i < posicion->fila_destino; i++)
			{
				if(tablero[i][posicion->columna_destino].color_ficha == 2)
				{
					valido=1;
				}
			}
		}
		if(posicion->fila_destino < posicion->fila_origen)
		{
			for(i = posicion->fila_origen-1; i > posicion->fila_destino; i--)
			{
				if(tablero[i][posicion->columna_destino].color_ficha == 2)
				{
					valido=1;
				}
			}
		}
	}

return valido;
}

int alfil(struct casilla tablero[8][8], struct posicion *posicion, int valido)
{

int i, columna, fila;

	// Movimiento hacia la derecha y hacia arriba
	if((posicion->columna_destino > posicion->columna_origen) && (posicion->fila_destino > posicion->fila_origen))
	{
		if(posicion->columna_destino - posicion->columna_origen == posicion->fila_destino - posicion-> fila_origen)
		{
			valido=1;
			columna=posicion->columna_origen;
			fila=posicion->fila_origen;
			do
			{
				columna++;
				fila++;
				if(tablero[fila][columna].color_ficha != 2)
				{
					valido=0;
				}
			}while((columna != posicion->columna_destino-1) && (fila != posicion->fila_destino-1));
		}
	}
	
	// Movimiento hacia la derecha y hacia abajo
	if((posicion->columna_destino > posicion->columna_origen) && (posicion->fila_destino < posicion->fila_origen))
	{
		if(posicion->columna_destino - posicion->columna_origen == posicion->fila_origen - posicion-> fila_destino)
		{
			valido=1;
			columna=posicion->columna_origen;
			fila=posicion->fila_origen;
			do
			{
				columna++;
				fila--;
				if(tablero[fila][columna].color_ficha != 2)
				{
					valido=0;
				}
			}while((columna != posicion->columna_destino-1) && (fila != posicion->fila_destino+1));
		}
	}
	if((posicion->columna_destino < posicion->columna_origen) && (posicion->fila_destino > posicion->fila_origen))
	{
		if(posicion->columna_origen - posicion->columna_destino == posicion->fila_destino - posicion-> fila_origen)
		{
			valido=1;
			columna=posicion->columna_origen;
			fila=posicion->fila_origen;
			do
			{
				columna--;
				fila++;
				if(tablero[fila][columna].color_ficha != 2)
				{
					valido=0;
				}
			}while((columna != posicion->columna_destino+1) && (fila != posicion->fila_destino-1));
		}
	}
	if((posicion->columna_destino < posicion->columna_origen) && (posicion->fila_destino < posicion->fila_origen))
	{
		if(posicion->columna_origen - posicion->columna_destino == posicion->fila_origen - posicion-> fila_destino)
		{
			valido=1;
			columna=posicion->columna_origen;
			fila=posicion->fila_origen;
			do
			{
				columna--;
				fila--;
				if(tablero[fila][columna].color_ficha != 2)
				{
					valido=0;
				}
			}while((columna != posicion->columna_destino+1) && (fila != posicion->fila_destino+1));
		}
	}
		
return valido;
}

int rey(struct casilla tablero[8][8], struct posicion *posicion, int valido){

	if(posicion->fila_destino == posicion->fila_origen)
	{
		if(posicion->columna_destino == posicion->columna_origen+1)
		{
			valido=1;
		}
		if(posicion->columna_destino == posicion->columna_origen-1)
		{
			valido=1;
		}
	}
	if(posicion->columna_destino == posicion->columna_origen)
	{
		if(posicion->fila_destino == posicion->fila_origen+1)
		{
			valido=1;
		}
		if(posicion->fila_destino == posicion->fila_origen-1)
		{
			valido=1;
		}
	}
	if((posicion->fila_destino == posicion->fila_origen+1) && (posicion->columna_destino == posicion->columna_origen+1))
	{
		valido=1;
	}
	if((posicion->fila_destino == posicion->fila_origen+1) && (posicion->columna_destino == posicion->columna_origen-1))
	{
		valido=1;
	}
	if((posicion->fila_destino == posicion->fila_origen-1) && (posicion->columna_destino == posicion->columna_origen+1))
	{
		valido=1;
	}
	if((posicion->fila_destino == posicion->fila_origen-1) && (posicion->columna_destino == posicion->columna_origen-1))
	{
		valido=1;
	}

return valido;
}
