---
layout: page
title: 2.6 Ejercicios propuestos
permalink: /php/ejercicios-propuestos
nav_order: 6
has_children: false
parent: 2 Introducción a PHP
grand_parent: Desarrollo Web en Entorno Servidor
---


## 2.6. Ejercicios propuestos
{: .no_toc }

- TOC
{:toc}

Los siguientes son una colección de ejercicios de programación que funcionan exactamente igual que los ejercicios en el gimnasio: para fortalecer tu musculatura como programador o programadora.

Está ordenados por orden creciente de complejidad, y no es necesario que los hagas todos. Por ejemplo, si los primeros te resultan demasiado fáciles, salta hasta alguno que suponga algún reto para ti.

Por el contrario, si hasta los primeros te cuestan trabajo, deberías ir intentándolos todos o casi todos en orden.

También puedes escribir tus propios programas si los que aparecen aquí no te interesan demasiado: siempre es bueno que el programa que estás desarrollando, aunque sea sencillo, te resulte motivador. No te asustes si el programa que intentas escribir parece muy complejo, no llegas a terminarlo o incluso no te funciona en absoluto: todo el tiempo dedicado a programar es tiempo bien aprovechado para un aprendiz de programación.

Estos ejercicios requerirán de ti dedicación, esfuerzo y constancia. Como ir al gimnasio, vamos. Pero por eso estás aquí, ¿no es cierto? Y recuerda lo que ya hemos dicho varias veces antes: ***a programar solo se aprende programando***.

### 2.6.1. Ejercicios sin acceso a bases de datos

#### Ejercicio 1: positivo, negativo

Diseña un formulario con un campo de texto en el que puedas escribir números. Al pulsar el botón de enviar, debe llamar a un script escrito en PHP que debe decirnos si el número enviado fue positivo, cero o negativo.

#### Ejercicio 2: anagramas

Una palabra es un anagrama de otra si contiene las mismas letras colocadas en orden diferente. Por ejemplo, "CAVA" es un anagrama de "VACA", y viceversa.

El ejercicio consiste en escribir un programa en PHP que pida dos palabras y compruebe si la primera es un anagrama de la segunda.

#### Ejercicio 3: función potencia

Escribe una función PHP que reciba dos parámetros (A y B) y devuelva el valor de la potencia de A elevado a B (AB). 

Escribe también un programa PHP que haga uso de esa función para calcular potencias.

#### Ejercicio 4: devolución de arrays

Escribe un programa PHP que pida cinco números al usuario y los guarde en un array. 

Luego debe llamar a una función pasándole el array como parámetro, y la función calculará cuál de los cinco números es el mayor, cuál el menor y cuánto vale la media, devolviendo esos tres valores en otro array. 

Por último, se mostrarán en la pantalla el mayor, el menor y la media.

#### Ejercicio 5: Simon dice

"Simon dice" es un clásico juego de memoria que consiste en componer secuencias de cuatro colores cada vez más largas, y el jugador tiene que recordarlas y reproducirlas. Puedes encontrar muchas versiones de Simon en internet.

Nosotros vamos a construir una versión simplificada que muestre secuencias de números (aunque podríamos hacerlo con colores sólo complicándolo un poco).

El programa mostrará un número entre 1 y 4 durante un instante, y luego borrará la pantalla y pedirá al usuario que lo repita. Después mostrará dos números aleatorios entre 1 y 4 (por ejemplo, 3 – 1), y luego el usuario los tendrá que repetir, y así hasta que el usuario falle al introducir los números.

### 2.6.2. Ejercicios con acceso a bases de datos

En esta sección, en lugar de ejercicios independientes, vamos a plantear una aplicación más larga que iremos montando paso a paso. Al final, tendrás una aplicación web simple pero plenamente funcional: *tu primera aplicación web*.

**Importante**: puedes (y te aconsejo que así lo hagas) utilizar como base para esta aplicación la Biblioteca que pusimos como ejemplo en la sección anterior.

#### Ejercicio 6: creación de tablas

Crea una base de datos nueva llamada *Videoclub* en MySQL. Puedes utilizar PHPMyAdmin para ello, aunque también podríamos hacerlo desde un programa PHP.

Luego, escribe un programa PHP llamado ejercicio09.php que sirva para crear las siguientes tablas del Videoclub (sólo usaremos tres por ahora). El programa debe informar de si las tablas se crearon correctamente o si ocurrió algún error al crearlas.

* Películas (cod_película#, título, género, país, año, distribuidora)
* Personas (cod_persona#, nombre, apellidos)
* Actúan (cod_película#, cod_persona#)

#### Ejercicio 7: mantenimiento de tablas maestras

Crea un programa PHP para mantener la tabla Películas. El programa debe permitir:

* Añadir nuevos registros, introduciendo todos los campos de la tabla.
* Eliminar registros existentes, introduciendo el código de la película.

#### Ejercicio 8: consultas simples

Escribe un programa en PHP que permita buscar a una película cualquiera introduciendo su código. Debe mostrar todos los datos disponibles en la tabla Películas.

#### Ejercicio 9: consultas y actualizaciones

Combina los ejercicios anteriores para que el mantenimiento de tablas también incluya la posibilidad de modificar registros existentes.

Primero, el usuario podrá buscar una película introduciendo su código, y el programa mostrará los datos correspondientes a ese registro (o un error si no existe). Luego, podrá modificarse cualquier campo del mismo.

#### Ejercicio 10: consultas complejas

Escribe un último programa PHP que permita consultar una película por código, por título o por género (en los dos últimos casos, la búsqueda puede producir varios resultados, de los que el usuario debe poder seleccionar el que desee). En la pantalla deben aparecer todos los datos de la película, incluyendo su reparto.

#### Ejercicio 11: ampliación indefinida del videoclub

Puedes ir ampliando esta aplicación indefinidamente en varias direcciones:

* Añadir el mantenimiento de la tabla de Personas: búsquedas, inserciones, modificaciones y borrados.
* Asignar el reparto a cada película, es decir, hacer inserciones y borrados en la tabla Actúan.
* Crear nuevas tablas para relacionar Personas y Películas, de manera que la base de datos pueda contener también las personas que dirigen, escriben o producen las películas, y añadir todo esto a la aplicación.
* Incluir enlaces a trailers de cada película en Youtube.
* ¡Y todo lo que se te ocurra!