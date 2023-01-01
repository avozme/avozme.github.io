---
layout: page
title: 9.6. Ejercicios propuestos
permalink: /ejercicios-propuestos-c/
nav_order: 6
has_children: true
parent: 9. El lenguaje C
grand_parent: Introd. a la prog. y al diseño 3D
---

## 9.6. Ejercicios propuestos
{: .no_toc }

- TOC
{:toc}


#### Ejercicio 1. Hola mundo

En este ejercicio, vamos a preparar nuestro entorno de trabajo.

1. Instala Visual Studio Code. Puedes descargarlo de [https://code.visualstudio.com/download](https://code.visualstudio.com/download) o bien instalarlo desde la tienda de aplicaciones de tu sistema operativo.

2. Abre Visual Studio Code y haz clic en el botón de extensiones (en el panel izquierdo). Busca una extensión llamada "C/C++ IntelliSense" e instálala.

3. Escribe un programa que salude con un "Hola, mundo". Encontrarás el código más abajo. Este programa es un clásico en el mundillo de la programación; siempre se usa para comprobar si un nuevo entorno de desarrollo está funcionando bien.

4. Ejecútalo y asegúrate de que el resultado es el esperado. Si algo falla, llama al profesor y no pases al siguiente ejercicio hasta dejar tu Visual Studio Code en perfecto estado de funcionamiento.

```c
#include <stdio.h>
int main()
{
   printf("Hola, mundo\n");
   return 0;
}
```

#### Ejercicio 2. Convertir de euros a dólares

Vamos a empezar por algo sencillito.

Escribe un programa en C capaz de leer un número real y un tipo de moneda, que puede ser "euro" o "dólar", y que convierta al tipo de moneda indicado, suponiendo que está expresada en la otra. 

Por ejemplo, si la cantidad es 15 y la moneda es "dólar", se supondrá que se trata de 15 € y que hay que convertirlos a dólares.

Utiliza el tipo de cambio que esté vigente el día en el que escribas el programa.</div>

#### Ejercicio 3. Tabla de multiplicar

Escribe un programa en C que pida un número y muestre la tabla de multiplicar de ese número.

Por ejemplo, si el usuario del programa escribe el número 3, la salida del programa debe ser:

```
3 x 1 = 3
3 x 2 = 6
3 x 3 = 9
3 x 4 = 12
3 x 5 = 15
3 x 6 = 18
3 x 7 = 21
3 x 8 = 24
3 x 9 = 27
3 x 10 = 30
```


#### Ejercicio 4. Juego del número secreto

Ahora algo solo un poquito más complicado: una versión en C del clásico juego del número secreto.

Se trata de un juego en el que el ordenador "piensa" un número al azar entre 1 y 100 y el jugador tiene que adivinarlo.

Cada vez que el jugador escribe un número, el programa le dice: "Mi número secreto es mayor" o "Mi número secreto es menor".

Cuando el jugador por fin acierta, el ordenador le dice: "Enhorabuena, has acertado", y añade el número de intentos que ha necesitado para acertar el número secreto.

#### Ejercicio 5. Juego de memoria

Ahora empieza la diversión.

Vamos a escribir en C un juego que podemos bautizar como "Juego de memoria". Será un juego en modo texto (bastante feo, por lo tanto), pero totalmente jugable y que nos servirá para afianzar todos los conocimientos adquiridos hasta ahora.

Reglas del juego:

* El juego comenzará preguntando el nivel de dificultad, que puede ser fácil, medio o difícil.
* El ordenador elegirá al azar una serie de números. La serie consistirá al principio en un solo número. Luego serán dos números, luego tres, luego cuatro... y así hasta diez. Los números de la serie solo pueden ser tres: 1, 2 y 3. 
* El ordenador mostrará su serie de números durante un tiempo en la pantalla. Ese tiempo será tanto menor cuanto más alto sea el nivel de dificultad.
* Después, la serie se borrará y el jugador debe demostrar su memoria y sus reflejos repitiéndola. 
* Si el jugador acierta en todos los números de la serie, el ordenador pasará a su siguiente serie (que tendrá un número más). Si el jugador falla, el juego termina.
* Si el jugador es capaz de repetir con éxito todas las series (desde la que solo tiene un número hasta la que tiene 10), el jugador gana.

#### Ejercicio 6. Pelota que rebota

Escribe un programa en C que muestre una pelota moviéndose por la pantalla y rebotando en sus bordes. La pelota se puede simular con el carácter “O”, escribiéndolo en diferentes celdas de la pantalla cada vez.

(Para este ejercicio necesitarás usar la librería *ncurses*)

Puedes realizar el programa en tres fases sucesivas. Para aprobar la actividad debes completar al menos la primera fase. Para sacar un 10 tienes que terminar la tercera fase.

* FASE 1: la “pelota” se mueve y rebota por la pantalla, pero va dejando un “rastro” de Oes.

```
O           O
 O         O O
  O       O   O
   O     O
    O   O
     O O
      O
```

* FASE 2: la “pelota” se mueve por la pantalla sin dejar rastro. Es decir, cada vez que se escribe la “O” en una nueva posición, se borra de la posición que ocupaba anteriormente. El resultado debe dar sensación de movimiento sin parpadeos.

```
           O


```

FASE 3: la “pelota” se mueve por la pantalla dejando una “estela” de cuatro o cinco “Oes” (u otros caracteres, como en la figura) a su paso.
    
```
      .
       .
        o
         o
          O


```

#### Ejercicio 7. Juego de automovilismo

Escribe un programa que simule un sencillo juego de automovilismo. La pantalla del juego debe tener un aspecto parecido a este:

```
                              |         |
                              |         |
                              |         |
                              |         |
                               |         |
                               |         |
                                |         |
                                 |         |
                                 |         |
                                 |         |
                                |         |
                                |    H    |
```

El jugador (cuyo vehículo representaremos con una H) puede mover su coche hacia la izquierda y hacia la derecha. Su objetivo es no salirse de la carretera, que tiene los límites marcados por un carácter "\|" a cada lado. Si se sale, pierde una vida. Si pierde tres vidas, la partida termina y el programa debe mostrar el tiempo que el conductor ha conseguido aguantar sin perder sus vidas.

La carretera se va desplazando de abajo a arriba, aprovechándose del scroll propio de la pantalla de texto. La carretera no debe ser recta, sino que tendrá irregularidades, como las mostradas en la figura, generadas al azar.

#### Proyecto.

XXX

* Hundir la flota
* Snake
* Buscaminas
* Pong
* Ahorcado
