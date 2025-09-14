---
layout: page
title: 1.8 Ejercicios resueltos
permalink: /php/ejercicios-resueltos.html
nav_order: 8
has_children: false
parent: 1 Programación web con PHP
grand_parent: Desarrollo web full stack
---


## 1.8. Ejercicios resueltos
{: .no_toc }

- TOC
{:toc}

Ya hemos visto cómo es el lenguaje PHP y cómo se puede acceder desde él a una base de datos externa para almacenar o recuperar información de ella. También cómo se puede estructurar el código con la arquitectura MVC. Ahora nos queda poner eso en práctica antes de poder profundizar más en herramientas web más complejas.

**En esta sección vamos a mostrar algunos ejemplos de aplicaciones web programadas con PHP, sin nada más.**

Mira con detenimiento el código y asegúrate de comprenderlo. Para empezar a programar con PHP, no hay nada mejor que echar un vistazo a algunos programas fáciles que luego puedas utilizar como plantilla para los tuyos. 

Eso sí, es imprescindible que, después, dediques un tiempo a tratar de escribir tú mismo/a tus propios programas sencillos. Al final de esta sección te propondremos algunos, aunque tú puedes cambiarlos por otros que te apetezcan más. Lo importante es que recuerdes siempre algo que parece obvio pero que, a menudo, la gente olvida: *a programar solo puede aprenderse programando*.

### 1.8.1. Tabla de multiplicar

Vamos a escribir un programa en PHP que pida un número al usuario y muestre su tabla de multiplicar hasta el 25 en una tabla HTML de 5 por 5 casillas.

El usuario escribirá el número en un formulario HTML.

#### Solución 1: con dos archivos fuente

Esta primera solución la vamos a plantear con dos archivos:

* ***index.php***: contendrá el formulario en el que vamos a pedir al usuario que escriba un número. En el action del formulario, pondremos el nombre del segundo archivo para enviarle el número.
* ***tabla.php***: recibirá el número escrito en el formulario y calculará la tabla de multiplicar, escribiendo la salida en formato HTML.

**ARCHIVO *index.php***

```php
<!DOCTYPE html>
<html>
  <head>
    <title>Tabla de multiplicar - Versión 1</title>
  </head>
  <body>
    <form action='tabla.php' method='GET'>
	   Introduce un número:
	   <input type='text' name='numero'>
	   <br>
	   <input type='submit'>
    </form>
  </body>
</html>
```

**ARCHIVO *tabla.php***

```php
<!DOCTYPE html>
<html>
  <head>
    <title>Tabla de multiplicar - Versión 1</title>
  </head>
  <body>

	<?php
		// Recuperamos el número escrito en el formulario.
		$n = $_REQUEST["numero"];
		// Mostramos la tabla de multiplicar en una tabla HTML
		echo "<table border='1'>";
		echo "<tr><td colspan='5'>Tabla de multiplicar del número $n</td></tr>";
		echo "<tr>";
		for ($i = 1; $i <= 25; $i++) {
			if (($i-1) % 5 == 0) echo "</tr><tr>";
			echo "<td>$n x $i = " . $n * $i . "</td>";
		}
		echo "</tr>";
		echo "</table>";
	?>

  </body>
</html>
```

#### Solución 2: con un solo archivo

Vamos a mejorar la solución anterior **uniendo todo el código en un solo archivo**, que podemos llamar *index.php*.

Eso signfica que, ahora, en el *action* del formulario, escribiremos *index.php*, de modo que, al pulsar submit, el número se enviará al mismo programa. Es decir, *index.php* se ejecutará dos veces: una para mostrar el formulario y otra para calcular la tabla de multiplicar.

Observa como se usa la ***función isset()*** para averiguar en cuál de esas dos ejecuciones estamos. Esta función recibe como parámetro una variable y nos dice si esa variable existe o, por el contrario, si no ha sido declarada ni inicializada aún.

```php
<!DOCTYPE html>
<html>
  <head>
    <title>Tabla de multiplicar - Versión 2</title>
  </head>
  <body>

	<?php
	if (!isset($_REQUEST["numero"])) {
		// Si no tenemos un número pasado por GET, significa que estamos en la primera ejecución,
		// así que mostramos el formulario
		echo "<form action='index.php' method='GET'>
		Introduce un número:
		<input type='text' name='numero'>
		<br>
		<input type='submit'>
		</form>";
	}
	else {
		// Ya tenemos número pasado por GET. Vamos a calcular su tabla de multiplicar.
		$n = $_REQUEST["numero"];
		echo "<table border='1'>";
		echo "<tr><td colspan='5'>Tabla de multiplicar del número $n</td></tr>";
		echo "<tr>";
		for ($i = 1; $i <= 25; $i++) {
			if (($i-1) % 5 == 0) echo "</tr><tr>";
			echo "<td>$n x $i = " . $n * $i . "</td>";
		}
		echo "</tr>";
		echo "</table>";
	}
	?>

  </body>
</html>
```

### 1.8.2. Juego del número secreto

Vamos a escribir una aplicación web en PHP para jugar al *juego del número secreto*. 

Es un juego clásico que consiste en lo siguiente: el ordenador elegirá un número al azar entre 1 y 100 y el jugador tendrá que averiguarlo. Cada vez que el jugador haga un intento, la aplicación le indicará si el número secreto es mayor o menor que el número introducido. 

Cuando el jugador por fin acierte, la aplicación le dará la enhorabuena y le indicará cuántos intentos ha necesitado para averiguar el número secreto.

Vamos a ver dos soluciones para este programa. En la primera, utilizaremos las variables de la URL para mantener vivos los datos del programa. En la segunda, utilizaremos **variables de sesión** para lograr el mismo efecto de forma mucho más limpia.

#### Juego del número secreto: solución sin variables de sesión

Este juego necesita que algunas variables, como el número secreto (variable *$aleatorio*) o el número de intentos (variable *$intentos*) persistan entre una solicitud al servidor y la siguiente.

Para lograrlo, haremos que el script se envíe a sí mismo el valor de esas variables en la última línea. Supondremos que el archivo se llama *index.php*.

Esta es **una solución muy poco elegante**, un estilo de programación de aplicaciones web que se dejó de usar hace años, pero que ilustra perfectamente cuál es el primer problema al que nos enfrentamos al desarrollar aplicaciones web: *que se ejecutan en el servidor "a tirones", un trozo cada vez, y para el servidor cada uno de esos trozos es un programa independiente, aunque el usuario tenga la sensación de que forman una aplicación coherente*. 

```php
<!DOCTYPE html>
<html>
  <head>
    <title>Juego del número secreto</title>
  </head>
  <body>

	<?php
        // Primero, comprobamos su ya existe la variable "numero" en la URL.
        // Si no existe, significa que el usuario tiene que escribir un número: tenemos que mostrarle el formulario.
        // Si ya existe, significa que el usuario ha escrito algún número y tenemos que comprobar si coincide con el aleatorio.
        if (!isset($_REQUEST['numero'])) {
            // La variable "numero" NO existe. Vamos a pedirle que lo escriba en un formulario
            // ¿Y el número aleatorio? Si aún no existe, significa que es LA PRIMERA ejecución y aún tenemos que elegirlo.
            // En cambio, si ya existe, tendremos que recuperarlo para seguir usando el mismo aleatorio y no uno nuevo cada vez.
            if (!isset($_REQUEST['aleatorio'])) {
				$intentos = 0;
				$aleatorio = rand(1,100);
			} else {
				$aleatorio = $_REQUEST['aleatorio'];
				$intentos = $_REQUEST['intentos'];
			}
			echo "<form action='numsecreto.php' method='get'>
				Adivina mi número:
				<input type='text' name='numero'><br>
				<input type='hidden' name='aleatorio' value='$aleatorio'>
				<input type='hidden' name='intentos' value='$intentos'>
				<br>				
				<input type='submit'>
				</form>";
		} else {
            // La variable "numero" existe. Eso indica que el usuario escribió un número en el formulario.
            // Vamos a recuperar ese número y a compararlo con el aleatorio.
			$n = $_REQUEST['numero'];
			$aleatorio = $_REQUEST['aleatorio'];
			$intentos = $_REQUEST['intentos'];
			$intentos++;
			echo "Tu número es: $n<br>";
			if ($n > $aleatorio) {
				echo "Mi número es MENOR";
			}
			else if ($n < $aleatorio) {
				echo "Mi número es MAYOR";
			}
			else {
				echo "<p>ENHORABUENA, HAS ACERTADO</p>";
				echo "Has necesitado $intentos intentos";
			}
            // Volvemos a llamar a este mismo programa, pasándole como variables de URL el aleatorio
            // y el número de intentos, para seguir jugando con el mismo número secreto.
			echo "<br><a href='numsecreto.php?aleatorio=$aleatorio&intentos=$intentos'>Sigue jugando...</a>";
            
		}

	?>
```

#### Juego del número secreto: solución con variables de sesión

En esta solución, se ha sustituido la chapuza de las variables pasadas por URL por **variables de sesión**.

Aunque las veremos con más detalle en el siguiente tema, te puedo adelantar que las variables de sesión permiten almacenar datos persistentes entre sucesivas ejecuciones de scripts desde el mismo cliente.

Es decir, *el servidor **recuerda** el valor de determinadas variables* para que ese programa ejecutado a tirones se comporte como un todo unificado de cara al usuario.

Observa detenidamente cómo se usan las variables de sesión con PHP mediante el array global $_SESSION para obtener una solución más elegante que la anterior.

```php
<!DOCTYPE html>
<html>
  <head>
    <title>Juego del número secreto</title>
  </head>
  <body>

	<?php
		session_start();
        // Primero, comprobamos su ya existe la variable "numero" en la URL.
        // Si no existe, significa que el usuario tiene que escribir un número: tenemos que mostrarle el formulario.
        // Si ya existe, significa que el usuario ha escrito algún número y tenemos que comprobar si coincide con el aleatorio.
        if (!isset($_REQUEST['numero'])) {
            // La variable "numero" NO existe. Vamos a pedirle que lo escriba en un formulario
            // ¿Y el número aleatorio? Si aún no existe, significa que es LA PRIMERA ejecución y aún tenemos que elegirlo.
            // En cambio, si ya existe, tendremos que recuperarlo para seguir usando el mismo aleatorio y no uno nuevo cada vez.
            if (!isset($_SESSION['aleatorio'])) {
				$_SESSION["intentos"] = 0;
				$_SESSION["aleatorio"] = rand(1,100);
			}
			echo "<form action='numsecreto.php' method='get'>
				Adivina mi número:
				<input type='text' name='numero'><br>
				<br>				
				<input type='submit'>
				</form>";
		} else {
            // La variable "numero" existe. Eso indica que el usuario escribió un número en el formulario.
            // Vamos a recuperar ese número y a compararlo con el aleatorio.
			$n = $_REQUEST['numero'];
			$_SESSION["intentos"]++;
			echo "Tu número es: $n<br>";
			if ($n > $_SESSION["aleatorio"]) {
				echo "Mi número es MENOR";
			}
			else if ($n < $_SESSION["aleatorio"]) {
				echo "Mi número es MAYOR";
			}
			else {
				echo "<p>ENHORABUENA, HAS ACERTADO</p>";
				echo "Has necesitado ".$_SESSION["intentos"]." intentos";
			}
            // Volvemos a llamar a este mismo programa, pasándole como variables de URL el aleatorio
            // y el número de intentos, para seguir jugando con el mismo número secreto.
			echo "<br><a href='numsecreto.php'>Sigue jugando...</a>";
            
		}

	?>
```

### 1.8.3. Biblioteca

Este caso práctico es muy importante por dos razones:

1. Porque es nuestra primera aplicación web "de verdad", con una base de datos detrás.
2. Porque volveremos sobre ella varias veces a lo largo de las siguientes secciones para hacerle sucesivas mejoras, hasta dejarla presentable.

El código fuente lo hemos visto en los apuntes del tema. Es más largo, pero fácil de seguir. Está dividido en tres versiones de la misma aplicación, sucesivamente más completas.

No te desesperes ni intentes leerlo en dos minutos para marcharte a hacer otra cosa. Tómatelo con calma, como si leer el código fuente fuera como leer un manual de instrucciones de un electrodoméstico nuevo que aún no tienes ni idea de cómo se usa.

**Se trata de escribir una aplicación web en PHP que gestione, de forma muy simplificada, una biblioteca**.

La aplicación trabajará con una base de datos compuesta de solo dos tablas (ya te dije que estaría muy simplificada): *libros* y *autores*.

Esta aplicación nos permitirá, en principio, ver la lista de todos los libros disponibles, así como dar de alta libros nuevos y modificar o borrar los libros existentes. De momento no trabajaremos con los autores, pero sería fácil extenderla para que también nos dejase hacer altas, bajas y modificaciones de los autores.

Al leer el código, observa cómo utilizamos una variable muy especial llamada ***$action*** para saber qué tiene que hacer la aplicación en cada momento. Esa variable es el germen de la *arquitectura modelo-vista-controlador* con la que trabajaremos una y otra vez más adelante.

Haz clic en los siguientes enlaces para acceder al código fuente de la biblioteca: 

* [Versión 1](../php/mvc/#1751-biblioteca-v1): código MVC, pero sin capa de abstracción de datos ni seguridad
* [Versión 2](../php/mvc/#1752-biblioteca-v2): como el anterior, pero añadiendo una capa de abstracción de datos
* [Versión 3](../php/mvc/#1753-biblioteca-v3): como el anterior, pero con controladores múltiples y capa de seguridad

