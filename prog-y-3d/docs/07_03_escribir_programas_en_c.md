---
layout: page
title: 9.3. Escribiendo programas en C
permalink: /escribiendo-programas-en-c/
nav_order: 3
has_children: true
parent: 9. El lenguaje C
grand_parent: Introd. a la prog. y al diseño 3D
---

## 9.3. Escribiendo programas en C
{: .no_toc }

- TOC
{:toc}

Ya conocemos cómo se manejan los principales elementos de un programa con C: variables, instrucciones de control, asignaciones, funciones, etc.

Ahora nos queda saber cómo juntamos todo eso para escribir nuestros programas, ¿no te parece?

### 9.3.1. Estructura de un programa en C

Ya estamos en condiciones de echar un vistazo a cual será el aspecto de (casi) todos los programas que escribamos en C.

Los programas escritos en C suelen guardarse en dos tipos de archivo:

* **Archivos con extensión .c**. Estos archivos contienen el grueso del código fuente.

* **Archivos con extensión .h**. Estos archivos contienen los prototipos de funciones y otras definiciones necesarias para que el programa funcione bien. Al principio, no escribirás ningún archivo de este tipo, pero sí que tendrás que incluir (con *#include*) muchos de ellos.

Todo programa C, desde el más pequeño hasta el más complejo, tiene un **programa principal** ubicado en la función ***main()***, que debe ubicarse en un archivo con extensión .c. 

Además, por encima de *main()* deben aparecer los **prototipos de funciones** (y esto implica a los archivos de cabecera, si se utilizan funciones de librería) y las variables y constantes globales, si las hay. Por debajo de *main()* encontraremos el código de las funciones de usuario.

Por lo tanto, la **estructura habitual de nuestros programas en C** debería ser esta: 

```c
/* Comentario inicial: nombre del programa, del programador, fecha, etc */

/* Archivos de cabecera (prototipos de funciones de librería) */
#include <archivo_cabecera.h>
#include <archivo_cabecera.h>

/* Prototipos de funciones escritas por nosotros */
float función1 (argumentos);
float función2 (argumentos);

/* Variables globales */
int variable_global1;
char variable_global2;

/* Algoritmo principal */
int main(void)
{
   /* Variables locales del algoritmo principal */
   int a, b;
   float x, y;
   ...
   ...
   /* Instrucciones del algoritmo principal */
   ...
   función1(argumentos);
   ...
   función2(argumentos);
   ...
   return 0;
}

/* Código completo de las funciones escritas por nosotros */
float función1 (argumentos)
{
   /* Variables locales e instrucciones de este subalgoritmo */
}
float función2 (argumentos)
{
   /* Variables locales e instrucciones de este subalgoritmo */
}
```

### 9.3.2. Compilar y ejecutar un programa sencillo desde la consola: gcc/g++

Vamos a aprender a compilar con **gcc/g++**, un compilador rápido, muy flexible y riguroso con el estándar de C/C++.

En realidad, gcc compila C y g++ compila C++, pero por lo demás se usan de forma muy semejante.

Se consideran dos de los mejores compiladores del mundo. Ten en cuenta que son herramientas de consola, es decir, que se usan **escribiendo comandos**, lo cual demuestra que *un gran programa no tiene por qué ser un programa "bonito"*. ¡Todo depende de a qué tipo de usuario vaya dirigido!

En adelante, nos vamos a referir sobre todo a gcc, pero g++ es muy similar.

#### Compilación básica con gcc 

Casi siempre, gcc es invocado desde la herramienta *make*, cuyo funcionamiento se explica más adelante, pero antes debemos saber manejarlo mínimamente de forma manual.

Vamos a compilar nuestro primer programa con gcc, que, como no podía ser de otra manera, será "hola mundo". Supongamos que el código fuente de "hola mundo" se encuentra almacenado en el archivo *holamundo.c*. La compilación se realizaría con este comando:

```
$ gcc holamundo.c -o hola
```

Esto compilará el código fuente de *holamundo.c* y generará un programa ejecutable llamado *hola*, que puedes ejecutar escribiendo:

```
$ ./hola
```

#### Errores y warnings

Si el compilador detecta en el código fuente **errores** en tiempo de compilación, lo comunica al programador del siguiente modo: 

```
$ gcc holamundo.c
holamundo.c: In function 'main':
holamundo.c:7: 'a' undeclared (first use in this function)
holamundo.c:7: (Each undeclared identifier is reported only once
holamundo.c:7: for each function it appears in.)
holamundo.c:7: parse error before 'return'
```

Como ves, gcc te indica el fichero y la línea en la que ha detectado el error. Obviamente, cuando esto ocurre, no se crea archivo ejecutable como resultado. Debes corregir los errores e intentar la compilación de nuevo.

Las **advertencias** (***warnings***) del compilador, en cambio, se consideran errores no críticos, por lo que no impiden la compilación del código. 

Las advertencias se muestran de un modo similar a los errores, indicando el archivo, la línea y la causa de la advertencia. Aunque no sean críticas, es una buena idea que las revises y las corrijas en caso necesario.

#### Opciones comunes

A continuación mostramos algunas otras opciones habituales al usar gcc.

* **-help**: Indica a gcc que muestre su salida de ayuda (muy reducida). 
* **-o fichero**: Especifica el nombre del archivo ejecutable que se generará como resultado de la compilación. Si no se indica ninguno, gcc creará un archivo llamado *a.out*.
* **-O nivel**: Indica a gcc que utilice optimizaciones en el código. Los niveles posibles van desde 0 (no optimizar) hasta 3 (optimización máxima). Utilizar el optimizador aumenta el tiempo de compilación, pero suele generar ejecutables más rápidos. 
* **-I directorio**: Especifica un directorio adicional donde gcc debe buscar los archivos de cabecera indicados en el código fuente. 
* **-L directorio**: Especifica un directorio adicional donde gcc debe buscar las librerías necesarias en el proceso de enlazado. 
* **-lLibrería**: Especifica el nombre de una librería adicional que deberá ser utilizada en el proceso de enlazado. 

Por ejemplo, para compilar el programa *holamundo.c* con el nivel máximo de optimización y de manera que el ejecutable se llame "hola" y se enlace con la librería *ncurses*, el comando sería:

```
$ gcc -O3 -o hola -lncurses holamundo.c
```

### 9.3.3. Compilar y ejecutar un programa no tan sencillo desde la consola: make

Cualquier proyecto de programación complejo consta de varios archivos fuente, puede incluso que de centenares de ellos. 

En este tipo de proyectos, los archivos se van compilando conforme se van construyendo, creándose un archivo binario a partir de cada archivo fuente. El archivo ejecutable final no se puede crear hasta que no se tienen disponibles todos los archivos binarios compilados.

El proceso de composición de todos los archivos binarios en un archivo ejecutable final se denomina **enlace** o **linkado** (del inglés *link*).

Hacer la compilación y enlace de múltiples archivos a mano es muy tedioso. Además, en proyectos complejos suele ocurrir que, cuando modificamos el código fuente de un archivo, otros archivos que dependan del que acabamos de modificar y también deben ser recompilados. En consecuencia, llevar un control sobre qué debe compilarse y qué no resulta complicado, y la opción de recompilar el proyecto entero todo el rato no es viable porque puede consumir muchísimo tiempo. 

La **herramienta *make*** permite automatizar todo esto. Nos evita la tarea de comprobar las dependencias entre ficheros y se encarga de compilar solo lo que en cada momento debe ser compilado.

Para ello se sirve de un fichero (cuyo nombre suele ser *Makefile*, aunque puede cambiarse) en el el programador tiene que especificar las **dependencias** entre ficheros de código fuente, así como las órdenes necesarias para actualizar cada fichero.

Una vez escrito el fichero *Makefile*, cada vez que cambiemos algún fichero fuente, nos bastará invocar el comando *make* para que él solito revise todas las dependencias y recompile y enlace todos los archivos que sean necesarios.

#### El fichero *Makefile*

El fichero *Makefile* más simple está compuesto por *reglas* de este aspecto:

```
objetivo ... : prerrequisitos ...
               comando
               ...
               ...
```

* Un **objetivo** suele ser el nombre de un archivo generado por un programa; ejemplos de objetivos son los archivos de código objeto. Un objetivo puede ser también el nombre de una acción que debe llevarse a cabo, como *clean*, que veremos más adelante en un ejemplo. 

* Un **prerrequisito** es un archivo que se usa como entrada para crear un objetivo. Un objetivo con frecuencia depende de varios archivos, así que en esta sección puede aparecer una lista de archivos.

* Un **comando** es una acción que *make* ejecuta cuando detecta que alguno de los prerrequisitos ha sido modificado. Debe ser un comando válido para el sistema operativo. Una regla puede tener más de un comando, cada uno en su propia línea. *Atención: ¡hay que poner un tabulador al principio de cada línea de comando!*

¿Que no entiendes nada? ¡Normal! Lo verás mucho más claro con un ejemplo.

#### Un ejemplo práctico

Nuestro ejemplo es un *Makefile* que describe la manera en la que un fichero ejecutable llamado *trivia* depende de tres ficheros objeto (binarios) que a su vez dependen de tres ficheros de código fuente C (.c) y uno cabecera (.h). 

El fichero *Makefile* debe indicar qué hay que recompilar cada vez que se modifica un archivo cualquiera. Échale un vistazo y lo comentamos más abajo:

```
trivia: main.o display.o utils.o
       gcc -o trivia main.o display.o utils.o

main.o : main.c config.h
       gcc -c main.c

display.c : display.c config.h buffer.h
       gcc -c display.c

utils.o : utils.c config.h
       gcc -c utils.c

clean :
       rm -f trivia *.o
```

Observa la primera línea. Ahí hemos dicho que el programa ejecutable (*trivia*) depende de los tres ficheros objeto (*main.o, display.o* y *utils.o*). Es decir, que si cambia cualquiera de ellos, *make* lo detectará y ejecutará el comando que aparece en la segunda línea. Y ese comando se encarga precisamente de volver a enlazar todos los ficheros objeto para generar de nuevo el archivo ejecutable *trivia*.

La siguiente regla explica cómo se construye el archivo binario *main.o*: depende de *main.c* y de *config.h*, es decir, que se cambia cualquier cosa en alguno de esos dos archivos, *main.o* volverá a crearse con la línea que se indica justo debajo.

Y lo mismo ocurre en todas las líneas del *Makefile*. 

La última regla (*clean*) es una regla especial que explicaremos enseguida.

#### Cómo usar *make*

Cuando ya dispones de tu archivo *Makefile* como el anterior, usar la herramienta *make* para compilar es sencillísimo:

* Para crear el archivo ejecutable bastará con escribir en la línea de comandos:
  ```
  $ make
  ```

  Al ejecutar *make*, solo se compilarán los archivos necesarios en cada momento (según lo que esté descrito en el *Makefile*).

* Para borrar el archivo ejecutable y todos los ficheros objeto del directorio, escribiremos: 
  
  ```
  make clean
  ```

  Para que *make clean* funcione, debe existir una sección *clean* en el archivo *Makefile*. Observa de nuevo el ejemplo de *Makefile* anterior y encontrarás al final la sección *clean*, donde se indica el comando que debe ejecutarse para borrar todos los archivos compilados.

Esto es lo más esencial de la herramienta *make*, pero, por supuesto, tiene otras muchas funciones que puedes investigar por tu cuenta cuando te vayan haciendo falta.

### 9.3.4. Compilar y ejecutar un programa con un IDE: Visual Studio Code con Code Runner

Un **IDE** o Entorno Integrado de Desarrollo es un programa que contiene todo lo necesario para programar: un editor de texto, un compilador, un depurador, una consola de ejecución, una consola de errores y muchas otras cosas que no vamos a llegar a usar.

**[Visual Studio Code](https://code.visualstudio.com/)** es un IDE muy popular desde hace un par de años. Es rápido, ligero, muy configurable, multiplataforma (funciona en Windows, Linux y Mac) y sirve para cualquier lenguaje imaginable. Con la extensión **Code Runner**, es facilísimo compilar y ejectuar código C/C++ con Visual Studio Code.

Solo tienes que:

1. Instalar Visual Studio Code y, dentro de él, la extensión Code Runner.
2. Escribir tu programa en C.
3. Pulsar el botón "Play" que aparecerá en la esquina superior derecha.
4. Ver tu programa en funcionamiento en el terminal de la parte inferior.

Puedes ver a Visual Studio Code en funcionamiento en esta capura de pantalla. Arriba y a la derecha están los botones de "Play" y "Stop" para lanzar y detener el programa. En el panel superior, el código fuente. En el panel inferior, el programa en ejecución. Y, a la izquierda, el navegador de archivos.

![Ejecución del juego de las 3 en raya con Code Runner dentro de VS Code](/docs/prog-y-3d/_site/assets/images/05-3-en-raya.png)

### 9.3.5. Flujo de trabajo habitual

Cuando se trabaja con C, la implementación de un programa suele dividirse en varias subfases: edición, compilación, enlace y depuración. Te las describo brevemente:

1. **Edición del código fuente**. Editar consiste en escribir el código fuente del programa en el lenguaje seleccionado, en nuestro caso C. Usaremos para ello **Visual Studio Code** con la extensión **Code Runner**.

2. **Compilación**. Una vez escrito el programa, debe traducirse a binario en el proceso llamado *compilación*. Esto puede hacerse desde la línea de comandos, como ya hemos visto, o de forma gráfica desde nuestro IDE. Este es el botón "Compile & Run" de Code Runner, por ejemplo: ![Botón "play" de la extensión Code Runner](/docs/prog-y-3d/_site/assets/images/05-code-runner-play-button.png)

3. **Enlace**. Si tu programa es muy complejo, tu código fuente ocupará varios archivos. En tal caso, hay que compilarlos de uno en uno y después *enlazarlos* entre sí para generar un único programa ejecutable. Como vimos, esto puede hacerse con la herramienta *make* o, en caso de usar un IDE, dejar que sea él quien se encargue de hacer el enlace automáticamente.

4. **Depuración**. Ningún programa está bien escrito a la primera. Nunca. Lo normal es que el compilador te informe de que hay multitud de errores en tu código fuente. Tendrás que leer cuidadosamente los mensajes de error para corregirlos. Por fortuna, el compilador te informará de la línea exacta donde localizó el error, e incluso te dirá de qué tipo de error se trata.

   Una vez corregidos los errores de escritura, cuando el programa empiece a funcionar, es posible que no haga exactamente lo que tú pretendías que hiciera. También tendrás que corregir estos errores de ejecución.

   Por lo tanto, después de pasar por estos 4 pasos, tendrás que regresar de nuevo al paso 1 y volver a repetir el proceso hasta que tu programa funcione como es debido.
