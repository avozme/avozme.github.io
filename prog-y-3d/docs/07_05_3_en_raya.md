---
layout: page
title: 9.5. Un ejemplo completo. Las tres en raya
permalink: /ejemplo-completo-3-en-raya/
nav_order: 5
has_children: true
parent: 9. El lenguaje C
grand_parent: Introd. a la prog. y al diseño 3D
---

## 9.5. Un ejemplo completo: las tres en raya
{: .no_toc }

- TOC
{:toc}

Llegó la hora de poner manos a la obra.

Si hay una sección de este capítulo que tienes que leer con atención, es esta. Así que es un mal momento para tener prisa.

Vamos a escribir un **programa completo en C**. Te puede servir de plantilla para desarrollar tus propios programas a partir de este código fuente.

El programa en cuestión será una versión del juego de **las tres en raya** que encontrarás resuelta en pseudocódigo el tema de introducción a la programación. No dudes en repasar aquel ejercicio resuelto para ver el pseudocódigo, puesto que nuestro programa será una traducción literal de ese pseudocódigo a C.

Aquí tienes el código fuente completo. Estúdialo con atención y asegúrate de entenderlo todo (o un gran porcentaje) antes de continuar. Ah, y no dejes de compararlo línea a línea con el mismo código en pseudocódigo.

### 9.6.1. El código fuente

```c
#include <stdio.h>

//-------------------------
//   ALGORITMO PRINCIPAL
//-------------------------
int main(void) {
   char tablero[10];
   int ganador = 0;        // 0 = ninguno, 1 = humano, 2 = ordenador
   int tablas;             // 0 = no hay tablas, 1 = sí hay tablas

   inicializar(tablero);   // Esto es un subalgoritmo. Está escrito más abajo
   do {
      mostrar(tablero);
      colocar_pieza_humano(tablero);
      ganador = comprobar_ganador(tablero);
      tablas = comprobar_tablas(tablero);
      if ((ganador == 0) && (tablas == 0)) {
         colocar_pieza_ordenador(tablero);
         ganador = comprobar_ganador(tablero);
         tablas = comprobar_tablas(tablero);
      }
   }
   while ((ganador == 0) && (tablas == 0));
	
   mostrar(tablero);
   if (ganador == 0) {
      printf("EL JUEGO HA TERMINADO EN TABLAS\n");
   }
   else if (ganador == 1) {
      printf("EL JUEGO HA TERMINADO Y HAS GANADO TÚ\n");
   }
   else {
      printf("EL JUEGO HA TERMINADO Y HE GANADO YO\n");
   }
}

// --------------------------------------------
// Inicializa el tablero con espacios en blanco
// --------------------------------------------
void inicializar(char tablero[10]) {
   int i;
   for (i = 1; i <= 9; i++) {
      // Como tablero es un array, se pasa por referencia y los cambios que
      // hagamos aquí se reflejarán en el algoritmo principal
      tablero[i] = ' ';
   }
}

// --------------------------------------------
// Muestra el estado actual del tablero
// --------------------------------------------
void mostrar(char tablero[10]) {
   printf("ESTADO ACTUAL DEL TABLERO\n");
   printf("+-+-+-+\n");
   printf("|%c|%c|%c|\n", tablero[1], tablero[2], tablero[3]);
   printf("+-+-+-+\n");
   printf("|%c|%c|%c|\n", tablero[4], tablero[5], tablero[6]);
   printf("+-+-+-+\n");
   printf("|%c|%c|%c|\n", tablero[7], tablero[8], tablero[9]);
   printf("+-+-+-+\n");
}

// ---------------------------------------------------
// Coloca una pieza del jugador humano en el tablero
// ---------------------------------------------------
void colocar_pieza_humano(char tablero[10]) {
   int casilla;
   int casilla_correcta = 0;
   do {
      printf("¿En qué casilla quieres poner una pieza? (1-9)");
      scanf("%d", &casilla);
      if (tablero[casilla] == ' ') {
         tablero[casilla] = 'X';
         casilla_correcta = 1;
      }
      else {
         printf("Error: Esa casilla ya está ocupada\n");
      }
   }
   while (casilla_correcta == 0);
}

// ---------------------------------------------------
// Coloca una pieza del ordenador en el tablero
// ---------------------------------------------------
void colocar_pieza_ordenador(char tablero[10]) {
   int casilla;
   int casilla_correcta = 0;
   srand(time(NULL));
   do {
      casilla = rand() % 10;
      printf("Voy a colocar mi pieza en la casilla ", casilla);
      if (tablero[casilla] == ' ') {
         tablero[casilla] = 'O';
         casilla_correcta = 1;
      }
      else {
         printf("¡Está ocupada! Voy a elegir otra");
      }
   }
   while (casilla_correcta == 0);
}

// ---------------------------------------------------
// Comprueba si hay un ganador según el estado del 
// tablero. Devuelve "Ninguno", "Humano" u "Ordenador"
// ---------------------------------------------------
int comprobar_ganador(char tablero[10]) {
   int ganador = 0;
   // Comprobamos primera fila
   if ((tablero[1] == tablero[2]) && (tablero[1] == tablero[3])) {
      if (tablero[1] == 'X') {
         ganador = 1;
      }
      if (tablero[1] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos segunda fila
   if ((tablero[4] == tablero[5]) && (tablero[4] == tablero[6])) {
      if (tablero[4] == 'X') {
         ganador = 1;
      }
      if (tablero[4] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos tercera fila
   if ((tablero[7] == tablero[8]) && (tablero[7] == tablero[9])) {
      if (tablero[7] == 'X') {
         ganador = 1;
      }
      if (tablero[7] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos primera columna
   if ((tablero[1] == tablero[4]) && (tablero[1] == tablero[7])) {
      if (tablero[1] == 'X') {
         ganador = 1;
      }
      if (tablero[1] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos segunda columna
   if ((tablero[2] == tablero[2]) && (tablero[2] == tablero[8])) {
      if (tablero[2] == 'X') {
         ganador = 1;
      }
      if (tablero[2] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos tercera columna
   if ((tablero[3] == tablero[6]) && (tablero[3] == tablero[9])) {
      if (tablero[3] == 'X') {
         ganador = 1;
      }
      if (tablero[3] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos una diagonal
   if ((tablero[1] == tablero[5]) && (tablero[1] == tablero[9])) {
      if (tablero[1] == 'X') {
         ganador = 1;
      }
      if (tablero[1] == 'O') {
         ganador = 2;
      }
   }
   // Comprobamos la otra diagonal
   if ((tablero[3] == tablero[5]) && (tablero[3] == tablero[7])) {
      if (tablero[3] == 'X') {
         ganador = 1;
      }
      if (tablero[3] == 'O') {
         ganador = 2;
      }
   }
   return ganador;
}

// -------------------------------------------
// Comprueba si hay una situación de tablas
// según el estado actual del tablero. Devuelve
// verdadero si hay tablas o falso en otro caso.
// -------------------------------------------
int comprobar_tablas(char tablero[10]) {
   int tablas = 0;
   int i, contador = 0;
   for (i = 1; i <= 9; i++) {
      if (tablero[i] !=  ' ') {
         contador++;
      }
   }
	
	// Si todas las casillas están ya ocupadas y no hay ganador,
	// entonces estamos en tablas.
   if (contador == 9) {
      tablas = 1;
   }
   else {
      tablas = 0;
   }
   return tablas;
}
```

### 9.6.2. ¿Cómo ejecutar y depurar este programa?

Guarda el programa anterior en un archivo de texto con extensión .c (por ejemplo, *3enraya.c*).

Si estás trabajando con Visual Studio Code con la extensión Code Runner, como hemos recomendado, puedes ejecutar tu programa directamente desde ahí. Basta con que pulses el botón "Play" de la esquina superior derecha. Se abrirá una consola en la parte de abajo donde tu programa se ejecutará.

#### ¡Socorro! El programa no funciona

¿El resultado no es el esperado? Es lo habitual. Habrá algún error en el código y te tocará depurarlo.

En la ventana inferior de Visual Studio Code verás varias pestañas. 

* En la pestaña **Terminal** verás el resultado de la ejecución de tu programa.
* En la pestaña **Problems** verás la lista de errores que el compilador ha encontrado en tu programa. En tal caso, en el *Terminal* solo verás un lenguaje de tipo "La compilación ha terminado con errores".

Los mensajes pueden estar en español o en inglés, dependiendo del compilador, pero ¿qué esperabas? Si quieres aprender a programar, tienes que acostumbrarte a manejar el inglés técnico.

El mensaje de error te dará información sobre lo que hay de malo en tu código y te dirá en qué línea, aproximadamente, está el error.

Cuando lo hayas localizado, **regresa a tu editor de texto, haz los cambios necesarios, guarda las modificaciones y vuelve a compilar y ejecutar el programa** (pulsando de nuevo el botón "Play").

Y así hasta que funcione.

¡Mucha paciencia y sangre fría! Recuerda siempre que la mayor parte del tiempo de programación se va en depurar programas, no en escribirlos.

