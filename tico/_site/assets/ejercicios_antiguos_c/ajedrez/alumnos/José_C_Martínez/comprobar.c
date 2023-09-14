#include "ajedrez.h"
#include "interfaz.h"
#include "comprobar.h"

int comprobar(struct s_casillas tablero[9][9], struct s_estado* estado, int io, int jo, int id, int jd){
int correcto=0;
int i, j;

//escribir_estado(estado);

	switch(tablero[jo][io].pieza){
		case PEON:					//////////////////// PEON /////////////////
			if(tablero[jo][io].color_pieza==BLANCA){
				if(jd==jo-1){							correcto=1;	}
				if((jd==jo-2)&&(jo==7)&&(tablero[jo-1][io].pieza==NADA)){	correcto=1;	}
			}
			if(tablero[jo][io].color_pieza==NEGRA){
				if(jd==jo+1){							correcto=1;	}
				if((jd==jo+2)&&(jo==2)&&(tablero[jo+1][io].pieza==NADA)){	correcto=1;	}
			}
			if(tablero[jd][id].pieza!=NADA){					correcto=0;	}
			if(id!=io){								correcto=0;	}
			
			if((jd==jo-1)&&(id==io-1)&&(tablero[jd][id].pieza!=NADA)){		correcto=1;	}
			if((jd==jo-1)&&(id==io+1)&&(tablero[jd][id].pieza!=NADA)){		correcto=1;	}
			if((jd==jo+1)&&(id==io-1)&&(tablero[jd][id].pieza!=NADA)){		correcto=1;	}
			if((jd==jo+1)&&(id==io+1)&&(tablero[jd][id].pieza!=NADA)){		correcto=1;	}
			if((tablero[jo][io].color_pieza==BLANCA)&&(jd==jo+1)){			correcto=0;	}
			if((tablero[jo][io].color_pieza==NEGRA)&&(jd==jo-1)){			correcto=0;	}
			break;
			
		case REY:					/////////////////// REY ///////////////////
			if((jd==jo-1)&&(id==io)){						correcto=1;	}
			if((jd==jo-1)&&(id==io+1)){						correcto=1;	}
			if((jd==jo)&&(id==io+1)){						correcto=1;	}
			if((jd==jo+1)&&(id==io+1)){						correcto=1;	}
			if((jd==jo+1)&&(id==io)){						correcto=1;	}
			if((jd==jo+1)&&(id==io-1)){						correcto=1;	}
			if((jd==jo)&&(id==io-1)){						correcto=1;	}
			if((jd==jo-1)&&(id==io-1)){						correcto=1;	}
			

			//////////////// ENROQUE /////////////////
			if(tablero[jo][io].color_pieza==BLANCA){
				if((estado->rey_blanco_movido=='N')&&(estado->torre_d_blanca_movida=='N')&&(tablero[8][6].pieza==NADA)&&(tablero[8][7].pieza==NADA)&&(tablero[8][8].color_pieza==BLANCA)&&(id==io+2)){
					tablero[8][6].pieza=TORRE;
					tablero[8][6].color_pieza=BLANCA;
					tablero[8][8].pieza=NADA;
					estado->torre_d_blanca_movida='S';
					estado->rey_blanco_movido='S';
												correcto=1;
				}
				if((estado->rey_blanco_movido=='N')&&(estado->torre_i_blanca_movida=='N')&&(tablero[8][2].pieza==NADA)&&(tablero[8][2].pieza==NADA)&&(tablero[8][4].pieza==NADA)&&(tablero[8][1].color_pieza==BLANCA)&&(id==io-2)){
					tablero[8][4].pieza=TORRE;
					tablero[8][4].color_pieza=BLANCA;
					tablero[8][1].pieza=NADA;
					estado->torre_i_blanca_movida='S';
					estado->rey_blanco_movido='S';
												correcto=1;
				}
			}
			if(tablero[jo][io].color_pieza==NEGRA){
				if((estado->rey_negro_movido=='N')&&(estado->torre_d_negra_movida=='N')&&(tablero[1][6].pieza==NADA)&&(tablero[1][7].pieza==NADA)&&(tablero[1][8].color_pieza==NEGRA)&&(id==io+2)){
					tablero[1][6].pieza=TORRE;
					tablero[1][8].pieza=NADA;
					tablero[1][6].color_pieza=NEGRA;
					estado->torre_d_negra_movida='S';
					estado->rey_negro_movido='S';
												correcto=1;
				}
				if((estado->rey_negro_movido=='N')&&(estado->torre_i_negra_movida=='N')&&(tablero[1][2].pieza==NADA)&&(tablero[1][3].pieza==NADA)&&(tablero[1][4].pieza==NADA)&&(tablero[1][1].color_pieza==NEGRA)&&(id==io-2)){
					tablero[1][4].pieza=TORRE;
					tablero[1][1].pieza=NADA;
					tablero[1][4].color_pieza=NEGRA;
					estado->torre_i_negra_movida='S';
					estado->rey_negro_movido='S';
												correcto=1;
				}
				if(correcto==1){
					if(tablero[jo][io].color_pieza==BLANCA){
						estado->rey_blanco_movido='S';
					}
					if(tablero[jo][io].color_pieza==NEGRA){
						estado->rey_negro_movido='S';
					}
				}
			}
				
			break;
			
			
		case CABALLO:					//////////////// CABALLO /////////////////
			if((jd==jo-2)&&(id==io-1)){						correcto=1;	}
			if((jd==jo-2)&&(id==io+1)){						correcto=1;	}
			if((jd==jo+2)&&(id==io-1)){						correcto=1;	}
			if((jd==jo+2)&&(id==io+1)){						correcto=1;	}
			if((jd==jo-1)&&(id==io-2)){						correcto=1;	}
			if((jd==jo-1)&&(id==io+2)){						correcto=1;	}
			if((jd==jo+1)&&(id==io-2)){						correcto=1;	}
			if((jd==jo+1)&&(id==io+2)){						correcto=1;	}
			break;
			
		
		case DAMA: ;					///////////////// DAMA ///////////////////
		case TORRE:					///////////////// TORRE //////////////////
			if(jd==jo){
				j=jo;
				if(id>io){
					for(i=io+1; i<=id-1; i++){
						if(tablero[j][i].pieza!=NADA){
												correcto=0;
							break;
						}
						else{
												correcto=1;
						}
					}
				}
				if(id==io+1){							correcto=1;	}
				if(io>id){
					for(i=io-1; i>=id+1; i--){
						if(tablero[j][i].pieza!=NADA){
												correcto=0;
							break;
						}
						else{
												correcto=1;
						}
					}
				}
				if(id==io-1){							correcto=1;	}
			}
			if(id==io){
				i=io;
				if(jd>jo){
					for(j=jo+1; j<=jd-1; j++){
						if(tablero[j][i].pieza!=NADA){
												correcto=0;
							break;
						}
						else{
												correcto=1;
						}
					}
				}
				if(jd==jo+1){							correcto=1;	}
				if(jo>jd){
					for(j=jo-1; j>=jd+1; j--){
						if(tablero[j][i].pieza!=NADA){
												correcto=0;
							break;
						}
						else{
												correcto=1;
						}
					}
				}
				if(jd==jo-1){							correcto=1;	}
			}
			if((jo==1)&&(io==1)&&(correcto==1)){	estado->torre_i_negra_movida='S';	}
			if((jo==1)&&(io==8)&&(correcto==1)){	estado->torre_d_negra_movida='S';	}
			if((jo==8)&&(io==1)&&(correcto==1)){	estado->torre_i_blanca_movida='S';	}
			if((jo==8)&&(io==8)&&(correcto==1)){	estado->torre_d_blanca_movida='S';	}
			
			
			if(tablero[jo][io].pieza==TORRE) break;
			
		case ALFIL:					//////////////// ALFIL ///////////////////
			if((jd>jo)&&(id>io)){
				if(jd-jo==id-io){						correcto=1;	}
			}
			if((jd>jo)&&(id<io)){
				if(jd-jo==io-id){						correcto=1;	}
			}
			if((jd<jo)&&(id<io)){
				if(jo-jd==io-id){						correcto=1;	}
			}
			if((jd<jo)&&(id>io)){
				if(jo-jd==id-io){						correcto=1;	}
			}
			
			j=jo; i=io;
			if((jd>jo)&&(id>io)){
				do{
					j=j+1;
					i=i+1;
					if(tablero[j][i].pieza!=NADA){
												correcto=0;
						break;
					}
				} while((j!=jd-1)&&(i!=id-1));
			}
			if((jd==jo+1)&&(id==io+1)){						correcto=1;	}
			if((jd>jo)&&(id<io)){
				do{
					j=j+1;
					i=i-1;
					if(tablero[j][i].pieza!=NADA){
												correcto=0;
						break;
					}
				} while((j!=jd-1)&&(i!=id+1));
			}
			if((jd==jo+1)&&(id==io-1)){						correcto=1;	}
			if((jd<jo)&&(id<io)){
				do{
					j=j-1;
					i=i-1;
					if(tablero[j][i].pieza!=NADA){
												correcto=0;
						break;
					}
				} while((j!=jd+1)&&(i!=id+1));
			}
			if((jd==jo-1)&&(id==io-1)){						correcto=1;	}
			if((jd<jo)&&(id>io)){
				do{
					j=j-1;
					i=i+1;
					if(tablero[j][i].pieza!=NADA){
												correcto=0;
						break;
					}
				} while((j!=jd+1)&&(i!=id-1));
			}
			if((jd==jo-1)&&(id==io+1)){						correcto=1;	}
			break;
		
	}
	return correcto;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////


int comprobar_jaque(struct s_casillas tablero[9][9], struct s_estado estado){
int i, j;
int jb, jn, ib, in;
int jaque=0, jaqueb=0, jaquen=0, posible=0;
int reyb=0, reyn=0;

	for(i=1; i<=8; i++){
		for(j=1; j<=8; j++){
			if(tablero[j][i].pieza==REY){
				if(tablero[j][i].color_pieza==BLANCA){
					jb=j; ib=i;
					reyb=1;
				}
				if(tablero[j][i].color_pieza==NEGRA){
					jn=j; in=i;
					reyn=1;
				}
			}
		}
	}
	if(reyb==0){	return 5;	}
	if(reyn==0){	return 4;	}	

	/// Ya tenemos las coordenadas de los dos reyes ///
	
	//////// JAQUE AL REY BLANCO ///////
		
	for(i=1; i<=8; i++){
		for(j=1; j<=8; j++){
			if((tablero[j][i].pieza!=NADA)&&(tablero[j][i].color_pieza==NEGRA)){
				posible=comprobar(tablero, &estado, i, j, ib, jb);
				if(posible==1) {
					jaqueb=1;
				}
			}
		}
	}
	
	//////// JAQUE AL REY NEGRO /////////
	
	for(i=1; i<=8; i++){
		for(j=1; j<=8; j++){
			if((tablero[j][i].pieza!=NADA)&&(tablero[j][i].color_pieza==BLANCA)){
				posible=comprobar(tablero, &estado, i, j, in, jn);
				if(posible==1) {
					jaquen=1;
				}
			}
		}
	}
	
	if(jaqueb==1){				jaque=1;	}
	if(jaquen==1){				jaque=2;	}
	if((jaqueb==0)&&(jaquen==0)){		jaque=0;	}
	
	return jaque;
}