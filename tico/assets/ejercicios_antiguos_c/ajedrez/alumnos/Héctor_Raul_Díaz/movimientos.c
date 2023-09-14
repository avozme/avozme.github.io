#include <string.h>
#include <stdlib.h>
#include <menu.h>

#include "ajedrez.h"
#include "movimientos.h"
#include "caguvi.h"

int mover_pieza(int x, int y, int xd, int yd, struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov **moves)
{
	struct s_mov *nuevo;
	struct s_movs mueve;
	int jaquemate=0;
	escribir_mov(x, y, xd, yd, tablero, estado);
		
	attron(COLOR_PAIR(1));
	move(4,72);
	printw("                                     ");
	move(4,72);
	printw("Movimientos: %i.  ", estado.num_mov);
	
	if((tablero[yd][xd].pieza==REY)&&(estado.turno!=tablero[yd][xd].color))
		jaquemate=1;
		
	
	//Guardamos en esta estructura los datos del movimiento.
	mueve.mov_n=estado.num_mov;
	mueve.x=x;
	mueve.y=y;
	mueve.xd=xd;
	mueve.yd=yd;
	mueve.pieza=tablero[y][x].pieza;
	mueve.piezad=tablero[yd][xd].pieza;
	
	//Movemos la pieza.
	tablero[yd][xd].pieza=tablero[y][x].pieza;
	tablero[yd][xd].color=tablero[y][x].color;
	tablero[y][x].pieza=NADA;
	tablero[y][x].color=NADA;
	pintar_fichas(tablero);
	
	
	//Insertamos el movimiento en la lista.
	nuevo=(struct s_mov*)malloc(sizeof(struct s_mov));
	nuevo->movimiento=mueve;
	nuevo->siguiente=*moves;
	*moves=nuevo;
	
	if(jaquemate==1) //Si se produce el jaque mate terminamos el programa.
	{

		clear();
		move(15,50);
		attron(A_BOLD);
		attron(COLOR_PAIR(1));
		if(estado.turno==BLANCO)
			printw("JAQUE MATE el jugador BLANCO, gana.");
		else
			printw("JAQUE MATE el jugador NEGRO, gana.");	
		getch();
		endwin();
		exit(1);
	}
	
}

int mov_inc(struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
	move(20,72);
	printw("                              ");
	move(22,72);
	printw("MOVIMIENTO INCORRECTO!!!");
	move(23,72);
	printw("Pulsa un atecla para seguir.");
	getch();
	move(22,72);
	printw("                              ");
	move(23,72);
	printw("                              ");
}

int enroque(int x, int y, int xd, int yd, struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov **moves)
{
	
	struct s_mov *nuevo;
	struct s_movs mueve;
	escribir_mov(x, y, xd, yd, tablero, estado);
	estado.num_mov++;
				
	//Guardamos en esta estructura los datos del movimiento.
	mueve.mov_n=estado.num_mov;
	mueve.x=x;
	mueve.y=y;
	mueve.xd=xd;
	mueve.yd=yd;
	mueve.pieza=tablero[y][x].pieza;
	mueve.piezad=tablero[yd][xd].pieza;
	
	//Movemos la pieza.
	tablero[0][0].pieza=tablero[yd][xd].pieza;
	tablero[0][0].color=tablero[yd][xd].color;
	tablero[yd][xd].pieza=tablero[y][x].pieza;
	tablero[yd][xd].color=tablero[y][x].color;
	tablero[y][x].pieza=tablero[0][0].pieza;
	tablero[y][x].color=tablero[0][0].color;
	
	pintar_fichas(tablero);
	
	//Insertamos el movimiento en la lista.
	nuevo=(struct s_mov*)malloc(sizeof(struct s_mov));
	nuevo->movimiento=mueve;
	nuevo->siguiente=*moves;
	*moves=nuevo;
}



int comprobar_mov(int x, int y, int xd, int yd, struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
	int perm;
	switch(tablero[y][x].pieza)
	{
		case PEON: perm=comp_mov_p(x, y, xd, yd, tablero, estado, moves);break;
		case TORRE: perm=comp_mov_t(x, y, xd, yd, tablero, estado, moves);break;
		case CABALLO: perm=comp_mov_c(x, y, xd, yd, tablero, estado, moves);break;
		case ALFIL: perm=comp_mov_a(x, y, xd, yd, tablero, estado, moves);break;
		case REY: perm=comp_mov_r(x, y, xd, yd, tablero, estado, moves);break;
		case REINA: perm=comp_mov_d(x, y, xd, yd, tablero, estado, moves);break;
	}
	return perm;
}

int comp_mov_p(int columna, int fila, int columnd, int filad, struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
	int max, dif;
	int correcto=0;
	
	if((fila==7)||(fila==2))  //Si es el primer mov de peon  puede avanzar dos casillas, en los demas solo una.
		max=2;
	else
		max=1;
	
	dif=fila-filad;       //Si la distancia entre las casillas origen y destino es mayor de lo permitido.ERROR.
	if(abs(dif)>max)
		correcto=0;
	
	else
	{	
		if(tablero[filad][columnd].pieza==NADA)
		{
			if(columnd==columna)//Si la casilla destino esta vacia y en la misma columna.OK.
				correcto=1;
			else //Si la casilla destino esta vacia y en distinta columna.ERROR.
				correcto=0;
		}
		else
		{	//Si la casilla destino tiene una pieza del mismo jugador.ERROR
			if(tablero[filad][columnd].color==tablero[fila][columna].color)
				correcto=0;
			else  //Si la casilla destino tiene uan pieza del oponente.
			{
				if(columnd==columna) //Si esta en la misma columna que la de origen.ERROR.
					correcto=0;
				else  
				{
					if((columnd==columna-1)||(columnd==columna+1))//Si la columna es adyacente a la de origen.OK.
						correcto=1;
					else //Si la columna no es adyacete a la original.ERROR.
						correcto=0;
				}
			}
		}
	}
	return correcto;
}

int comp_mov_t(int columna, int fila, int columnd, int filad, struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
	int i, correcto=0, out=0;
	
	if((columnd==columna)||(filad==fila)) //Si la figura se mueve por la misma fila o columna;
	{
		if(columnd==columna) //Caso de que se mueva por la misma columna. 
		{
			//Miramos si en su camino se encuentra con algo.
			if(fila<filad)
			{
				for(i=fila+1; i<filad; i++)     //Si va de arriba abajo.
				{
					if(tablero[i][columna].pieza!=NADA)
						out=1;
				}
			}
			
			else
			{
				for(i=fila-1; i>filad; i--)  //Si va de abajo arriba.
				{
					if(tablero[i][columna].pieza!=NADA)
						out=1;
				}
			}
			
			if(out==0)
			{	
				if(tablero[filad][columnd].pieza==NADA) //Si la casilla destino esta vacia.OK.
					correcto=1;
				else //La casilla destino esta ocupada.
				{	//Si hay una pieza del oponente.OK.
					if(tablero[filad][columnd].color!=tablero[fila][columna].color)
						correcto=1;
					else  //Si la pieza es suya.ERROR.
						correcto=0;
				}
			}
			else
				correcto=0;
		}
	
		if(filad==fila) //Caso de que se mueva por la misma fila.
		{
			if(columna<columnd)
			{	
				for(i=columna+1; i<columnd; i++)   //for(i=columna-1; i>columnd; i--) de izq. a der.
				{	
					if(tablero[fila][i].pieza!=NADA)
						out=1;
				}
			}
			else
			{
				for(i=columna-1; i>columnd; i--)
				{
					if(tablero[fila][i].pieza!=NADA)
						out=1;
				}
			}
		
			if(out==0)
			{
				if(tablero[filad][columnd].pieza==NADA)
					correcto=1;
				else
				{
					if(tablero[filad][columnd].color!=tablero[fila][columna].color)
						correcto=1;
					else
						correcto=0;
				}
			}
			else
				correcto=0;
		}
	}
	else //Si se desplaza a cualquier casilla que no este en la misma fial o columna.ERROR.
		correcto=0;
		
	if(correcto==1) //Si la torre se mueve no se podra hacer el enroque. Solo se controla que la torre se encuentre en las columnas iniciales, ya que una vez se mueva esto no se volvera a poner a cero.
	{
		if(estado.turno=BLANCO)
		{
			if(columna==1)
				estado.torre_B1=1;
			if(columna==8)
				estado.torre_B2=1;
		}
		else
		{
			if(columna==1)
				estado.torre_B1=1;
			if(columna==8)
				estado.torre_B2=1;
		}
	}
	return correcto;
}

int comp_mov_c(int columna, int fila, int columnd, int filad, struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
	int correcto=0;
	//Si la casilla destino no esta vacia y la pieza es suya.ERROR.
	if((tablero[filad][columnd].pieza!=NADA)&&(tablero[filad][columnd].color==tablero[fila][columna].color))
	{
		correcto=0;
		//mov_inc(tablero, estado, moves);
	}
	else //Tanto si esta vacia como si es del oponente.OK.
	{
		if((columnd==columna+1)&&((filad==fila+2)||(filad==fila-2)))
			correcto=1;
		else if((columnd==columna-1)&&((filad==fila+2)||(filad==fila-2)))
			correcto=1;
		else if((columnd==columna+2)&&((filad==fila+1)||(filad==fila-1)))
			correcto=1;
		else if((columnd==columna-2)&&((filad==fila+1)||(filad==fila-1)))
			correcto=1;
		else
			correcto=0;
	}
	return correcto;
}

int comp_mov_a(int columna, int fila, int columnd, int filad, struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
	int correcto=0, aux1, aux2, obs=0;
	int i, j;
	
	aux1=(abs(fila-filad));
	aux2=(abs(columna-columnd));
	
	if(aux1==aux2)  //Si se mueve en la diagonal.
	{
		//Comprobamos que no hay obstaculos en el camino.
		if((fila<filad)&&(columna<columnd)) //De izq. a drch. bajando.
		{
			for(i=1; i<aux1; i++)
			{
				if(tablero[fila+i][columna+i].pieza!=NADA) //Si encuentra algo.ERROR.
					obs=1;
			}	
		}			
		
		if((fila<filad)&&(columna>columnd)) //De drch. a izq. subiendo.
		{	
			for(i=1; i<aux1; i++)
			{
				if(tablero[fila+i][columna-i].pieza!=NADA) //Si encuentra algo.ERROR.
					obs=1;
			}
		}
	
		if((fila>filad)&&(columna<columnd))	//De izq. a drch. subiendo.
		{
			for(i=1; i<aux1; i++)
			{
				if(tablero[fila-i][columna+i].pieza!=NADA)  //Si encuentra algo.ERROR.
					obs=1;
			}
		}
	
		if((fila>filad)&&(columna>columnd)) //De drch. a izq.  subiendo.
		{
			for(i=1; i<aux1; i++)
			{
				if(tablero[fila-i][columna-i].pieza!=NADA)	//Si encuentra algo.ERROR.
					obs=1;
			}
		}
	
		if(obs==0)//Si el camino no esta obstaculizado.
		{
			if(tablero[filad][columnd].pieza==NADA) //Si la casilla destino esta vacia.OK.
				correcto=1;
			else   
			{
				if(tablero[filad][columnd].color==tablero[fila][columna].color)//Si la pieza es suya.ERROR.
					correcto=0;
				else //Si la pieza no es suya.OK.
					correcto=1;
			}
		}
		else //Si el camino esta obstaculizado.
			correcto=0;
	}
	else //Si no se mueve en diagonal.
		correcto=0;
	
	return correcto;
}

int comp_mov_r(int columna, int fila, int columnd, int filad, struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
	int pos=0, obs=0;
	int correcto=0;
	int enjaque=0;
	int enro=0;
	int x, y, i, j;
	
	for(x=1; x<9; x++) //Comprobamos si la casilla destino es alcanzable por una pieza oponente.
	{
		for(y=1; y<9; y++)
		{
			if((tablero[y][x].pieza!=NADA)&&(tablero[y][x].color!=estado.turno))
				enjaque=comprobar_mov(x, y, columnd, filad, tablero, estado, moves);
				//enjaque toma valor 1 si la casilla destino es alcanzable.
		}
		
	}
	
	/*if(enjaque==0) 
	{*/
		//si se esta intentando hacer un enroque.
		if((tablero[filad][columnd].pieza==TORRE)&&(tablero[fila][columna].color==tablero[filad][columnd].color))
		{
			if(columnd>columna) //Si es el enroque corto.
			{
				for(i=6; i<8; i++)
				{
					if(tablero[fila][i].pieza!=NADA) //Si hay alguna pieza por el camino.
						obs=1;
				}
				if(obs==0)
				{	
					if(estado.turno==BLANCO)  //Si las piezas son blancas.
					{
						//Si la torre y el rey no se han movido, y si no se ha producido un eroque 	anterior.OK. 
						if((estado.torre_B2==0)&&(estado.reyB==0))
							enro=1;	//Se produce el enroque.
						else   //Si se ha movido cualquiera de las dos piezas.ERROR.
							correcto=0;	
					}
					else //Si es negra.
					{
						if((estado.torre_N2==0)&&(estado.reyN==0))
							enro=1;
						else
							correcto=0;
					}
				}
				else
					correcto=0;
			}
			else //Si es el enroque largo;
			{
				for(i=2; i<5; i++)
				{
					if(tablero[fila][i].pieza!=NADA) //Si hay alguna pieza por el camino.
						obs=1;
				}
				if(obs==0)
				{
					if(estado.turno==BLANCO)  //Si las piezas son blancas.
					{
						//Si la torre y el rey no se han movido, y si no se ha producido un eroque 	anterior.OK. 
						if((estado.torre_B1==0)&&(estado.reyB==0))
							enro=1;	//Se produce el enroque.
						else   //Si se ha movido cualquiera de las dos piezas.ERROR.
							correcto=0;	
					}
					else //Si es negra.
					{
						if((estado.torre_N1==0)&&(estado.reyN==0))
							enro=1;
						else
							correcto=0;
					}
				}
				else
					correcto=0;
			}
		}
		else //Si no intenta hacer el enroque.
		{
			if((filad==fila)||(filad==fila+1)||(filad==fila-1)) //Si se dirige a una casilla adyacente.OK.
			{	
				if((columnd==columna||columnd==columna+1)||(columnd==columna-1))
					pos=1;
				else
					pos=0;
			}
			else 
				pos=0;
		}
		
		if(pos==1)
		{		
			if(tablero[filad][columnd].pieza==NADA) //Si la casilla destino esta vacia.OK
				correcto=1;
			else //  //Si esta ocupada.
			{	
				if(tablero[fila][columna].color==tablero[filad][columnd].color)  //Si la pieza es suya.ERROR
					correcto=0;
				
				else   //Si la pieza no es suya.OK.
					correcto=1;
			}
		}
		else
			correcto=0;
	/*}
	else
		correcto=0;*/
	
	if(correcto==1) //Si el rey se mueve imposibilita hacer el enroque.
	{
		if(estado.turno==BLANCO)
			estado.reyB=1;
		else
			estado.reyN=1;
	}
	
	if(enro==1)
		enroque(columna, fila, columnd, filad, tablero, estado, &moves);
	
	return correcto;
}

int comp_mov_d(int columna, int fila, int columnd, int filad, struct s_casilla tablero[9][9], struct s_estado estado, struct s_mov *moves)
{
	int i, j, correcto=0, aux1, aux2, obs=0;;
	
	aux1=(abs(fila-filad));
	aux2=(abs(columna-columnd));
	
	if((fila==filad)||(columna==columnd)) //Si se mueve como la torre.
	{
		if(columnd==columna) //Caso de que se mueva por la misma columna. 
		{
			//Miramos si en su camino se encuentra con algo.
			if(fila<filad)
			{
				for(i=fila+1; i<filad; i++)     //Si va de arriba abajo.
				{
					if(tablero[i][columna].pieza!=NADA)
						obs=1;
				}
			}
			
			else
			{
				for(i=fila-1; i>filad; i--)  //Si va de abajo arriba.
				{
					if(tablero[i][columna].pieza!=NADA)
						obs=1;
				}
			}
			
			if(obs==0)
			{	
				if(tablero[filad][columnd].pieza==NADA) //Si la casilla destino esta vacia.OK.
					correcto=1;
				else //La casilla destino esta ocupada.
				{	//Si hay una pieza del oponente.OK.
					if(tablero[filad][columnd].color!=tablero[fila][columna].color)
						correcto=1;
					else  //Si la pieza es suya.ERROR.
						correcto=0;
				}
			}
			else
				correcto=0;
		}
	
		if(filad==fila) //Caso de que se mueva por la misma fila.
		{
			if(columna<columnd)
			{	
				for(i=columna+1; i<columnd; i++)   //for(i=columna-1; i>columnd; i--) de izq. a der.
				{	
					if(tablero[fila][i].pieza!=NADA)
						obs=1;
				}
			}
			else
			{
				for(i=columna-1; i>columnd; i--)
				{
					if(tablero[fila][i].pieza!=NADA)
						obs=1;
				}
			}
		
			if(obs==0)
			{
				if(tablero[filad][columnd].pieza==NADA)
					correcto=1;
				else
				{
					if(tablero[filad][columnd].color!=tablero[fila][columna].color)
						correcto=1;
					else
						correcto=0;
				}
			}
			else
				correcto=0;
		}
	}
	
	else if(aux1==aux2) //Si se mueve como el alfil.
	{
		//Comprobamos que no hay obstaculos en el camino.
		if((fila<filad)&&(columna<columnd)) //De izq. a drch. bajando.
		{
			for(i=1; i<aux1; i++)
			{
				if(tablero[fila+i][columna+i].pieza!=NADA) //Si encuentra algo.ERROR.
					obs=1;
			}	
		}			
		
		if((fila<filad)&&(columna>columnd)) //De drch. a izq. bajando.
		{	
			for(i=1; i<aux1; i++)
			{
				if(tablero[fila+i][columna-i].pieza!=NADA) //Si encuentra algo.ERROR.
					obs=1;
			}
		}
	
		if((fila>filad)&&(columna<columnd))	//De izq. a drch. subiendo.
		{
			for(i=1; i<aux1; i++)
			{
				if(tablero[fila-i][columna+i].pieza!=NADA)  //Si encuentra algo.ERROR.
					obs=1;
			}
		}
	
		if((fila>filad)&&(columna>columnd)) //De drch. a izq.  subiendo.
		{
			for(i=1; i<aux1; i++)
			{
				if(tablero[fila-i][columna-i].pieza!=NADA)	//Si encuentra algo.ERROR.
					obs=1;
			}
		}
	
		if(obs==0)//Si el camino no esta obstaculizado.
		{
			if(tablero[filad][columnd].pieza==NADA) //Si la casilla destino esta vacia.OK.
				correcto=1;
			else   
			{
				if(tablero[filad][columnd].color==tablero[fila][columna].color)//Si la pieza es suya.ERROR.
					correcto=0;
				else //Si la pieza no es suya.OK.
					correcto=1;
			}
		}
		else //Si el camino esta obstaculizado.
			correcto=0;
	}
	else //Si no se mueve en diagonal o en la misma fila o columna.
		correcto=0;
	
	return correcto;
}
