/*
PROGRAMA:  Ajedrez 1.0
ARCHIVO:   bitmaps.h
CONTENIDO: Definición de los bitmaps para el modo gráfico de Linux
           En este archivo se definen los bitmaps de:
	     - Las piezas
	     - Los caracteres
           Los bitmaps arrays de tipo char[10][10].
	   Una 'X' en la cadena indica que ese bit se debe imprimir.
	   Un espacio en la cadena indica que ese bit no se debe imprimir.
AUTOR:     Alfredo Moreno
*/

  char peon[10][10] = {"    XX    ",
                       "   XXXX   ",
		       "  XXXXXX  ",
		       "  XXXXXX  ",
		       "   XXXX   ",
		       "   XXXX   ",
		       "  XXXXXX  ",
		       " XXXXXXXX ",
		       " XXXXXXXX ",
		       "XXXXXXXXXX"};

  char torre[10][10] = {"XX  XX  XX",
                        "XX  XX  XX",
                        "XXXXXXXXXX",
			" XXXXXXXX ",
			" XXXXXXXX ",
			" XXXXXXXX ",
			" XXXXXXXX ",
			" XXXXXXXX ",
			"XXXXXXXXXX",
			"XXXXXXXXXX"};
			
  char alfil[10][10] = {"    XX    ",
			"   XXXX   ",
			"  XXXXXX  ",
			"  XXXXXX  ",
			"  XXXXXX  ",
			"   XXXX   ",
			"    XX    ",
			"    XX    ",
			" XXXXXXXX ",
			"XXXXXXXXXX"};

  char caballo[10][10] = {"   XX     ",
			  "  XXXX    ",
			  " XXXXXX   ",
			  "XXXXXXXX  ",
			  "XX  XXXXX ",
			  "    XXXXX ",
			  "   XXXXXXX",
			  "   XXXXXXX",
			  "  XXXXXXXX",
			  "XXXXXXXXXX"};
			  
  char rey[10][10] =   {"    XX    ",
			"  XXXXXX  ",
			"  XXXXXX  ",
			"    XX    ",
			" XX XX XX ",
			" XXXXXXXX ",
			"  XXXXXX  ",
			"  XXXXXX  ",
			"XXXXXXXXXX",
			"XXXXXXXXXX"};

  char dama[10][10] =  {"X   XX   X",
			"X   XX   X",
			"XX  XX  XX",
			"XX  XX  XX",
			" XX XX XX ",
			" XX XX XX ",
			"  XXXXXX  ",
			"  XXXXXX  ",
			"XXXXXXXXXX",
			"XXXXXXXXXX"};
			
