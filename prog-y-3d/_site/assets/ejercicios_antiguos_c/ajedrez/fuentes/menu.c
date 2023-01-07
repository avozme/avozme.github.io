/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   menu.c
CONTENIDO: Men�s de opciones
AUTOR:     Alfredo Moreno
*/

#include "menu.h"

// Muestra el men� inicial del juego y asigna los valores
// adecuados seg�n la selecci�n
int menu_inicial(Testado* estado)
{
   int opc;
   int tecla;
   
   borrar(0);
   escribir("Seleccione jugadores", 2, TXT_RESALTADO);
   escribir("BLANCAS:", 4, TXT_NORMAL);
   escribir("NEGRAS:", 7, TXT_NORMAL);
   escribir("Pulse Espacio para", 10, TXT_NORMAL);
   escribir("cambiar la selecci�n", 11, TXT_NORMAL);
   escribir("y Return para acabar", 12, TXT_NORMAL);

   opc = 1;
   do
   {
     if (opc == 1) 
     {
        if (estado->jug_blanco == HUMANO) 
            escribir("    Humano", 5, TXT_INVERSO);
        else
            escribir("    M�quina", 5, TXT_INVERSO);
     }
     else
     {
        if (estado->jug_blanco == HUMANO) 
            escribir("    Humano", 5, TXT_NORMAL);
        else
            escribir("    M�quina", 5, TXT_NORMAL);
     }
     
     if (opc == 2) 
     {
        if (estado->jug_negro == HUMANO) 
            escribir("    Humano", 8, TXT_INVERSO);
        else
            escribir("    M�quina", 8, TXT_INVERSO);
     }
     else
     {
        if (estado->jug_negro == HUMANO) 
            escribir("    Humano", 8, TXT_NORMAL);
        else
            escribir("    M�quina", 8, TXT_NORMAL);
     }
     
     tecla = leer_tecla();     // Lee la primera tecla que se pulse (io.c)
     
     switch(tecla)
     {
         case FLECHA_ARRIBA: opc--; if (opc<1) opc = 2; break;
         case FLECHA_ABAJO:  opc++; if (opc>2) opc = 1; break;
         case ' ': // Cambiar selecci�n
                   if (opc == 1) {         // Blancas
                      if (estado->jug_blanco == HUMANO) estado->jug_blanco = MAQUINA;
                      else estado->jug_blanco = HUMANO;
                   }
                   if (opc == 2) {         // Negras
                      if (estado->jug_negro == HUMANO) estado->jug_negro = MAQUINA;
                      else estado->jug_negro = HUMANO;
                   }
                   break;
     } // switch
   }
   while (tecla != RETURN);
}

// Muestra el men� principal del juego y llama a las funciones adecuadas
// seg�n la opci�n seleccionada. Devuelve el n� de la opci�n seleccionada.
int menu_juego(Tcasilla tablero[9][9], Testado* estado)
{
   int opc;
   int tecla;
   
   borrar(0);
   opc = 1;
   do
   {
     escribir("MEN� DE OPCIONES", 1, TXT_RESALTADO);
     if (opc == 1) escribir("Continuar partida", 3, TXT_INVERSO);
     else          escribir("Continuar partida", 3, TXT_NORMAL);
     if (opc == 2) escribir("Empezar otra partida", 4, TXT_INVERSO);
     else          escribir("Empezar otra partida", 4, TXT_NORMAL);
     if (opc == 3) escribir("Guardar partida", 5, TXT_INVERSO);
     else          escribir("Guardar partida", 5, TXT_NORMAL);
     if (opc == 4) escribir("Cargar partida", 6, TXT_INVERSO);
     else          escribir("Cargar partida", 6, TXT_NORMAL);
     if (opc == 5) escribir("Salir del programa", 7, TXT_INVERSO);
     else          escribir("Salir del programa", 7, TXT_NORMAL);
   
     tecla = leer_tecla();     // Lee la primera tecla que se pulse (io.c)
     
     switch(tecla)
     {
         case FLECHA_ARRIBA: opc--; if (opc<1) opc = 5; break;
         case FLECHA_ABAJO:  opc++; if (opc>5) opc = 1; break;
     }
   }
   while ((tecla != RETURN) && (tecla != ESCAPE));
  
   if (tecla == ESCAPE) opc = 1;   // Regresar al juego
    
   switch(opc)
   {
     case 1: // No hacer nada --> al terminar esta funci�n se regresar� al punto de partida
             break;
     case 2: terminar(estado);
             // Restaurar valores iniciales y volver al juego
             // XXX preguntar al usuario si est� seguro
             valores_iniciales(tablero, estado);
             elegir_jugadores(estado);
             refrescar_pantalla(tablero);
             break;
     case 3: // Guardar partida y regresar al juego
             grabar_partida();
             break;
     case 4: // Cargar partida y regresar al juego
             // XXX preguntar al usuario si est� seguro
             valores_iniciales(tablero, estado);
             cargar_partida();
	     reproducir_partida(tablero, estado, 0);
             break;
     case 5: // Finalizar
             estado->terminar = VERDADERO;
             break;
   }
   
   borrar(0);        // Borramos de nuevo todo el �rea de texto
   return opc;
}
