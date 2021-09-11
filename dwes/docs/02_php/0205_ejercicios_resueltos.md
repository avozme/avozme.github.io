---
layout: page
title: 2.5 Ejercicios resueltos
permalink: /php/ejercicios-resueltos
nav_order: 5
has_children: false
parent: 2 Introducción a PHP
grand_parent: Desarrollo Web en Entorno Servidor
---


## 2.5. Ejercicios resueltos
{: .no_toc }

- TOC
{:toc}

Ya hemos visto muy superficialmente cómo es el lenguaje PHP y cómo se puede acceder desde él a una base de datos externa para almacenar o recuperar información de ella. Ahora nos queda poner eso en práctica antes de poder profundizar más en el desarrollo de aplicaciones web complejas.

En esta sección vamos a mostrar algunos ejemplos sencillos de aplicaciones web muy, muy básicas programadas con PHP. La última de ellas incluye un acceso a una base de datos.

Mira con detenimiento el código y asegúrate de comprenderlo. Para empezar a programar con PHP, no hay nada mejor que echar un vistazo a algunos programas fáciles que luego puedas utilizar como plantilla para los tuyos. 

Eso sí, es imprescindible que, después, dediques un tiempo a tratar de escribir tú mismo/a tus propios programas sencillos. Al final de esta sección te propondremos algunos, aunque tú puedes cambiarlos por otros que te apetezcan más. Lo importante es que recuerdes siempre algo que parece obvio pero que, a menudo, la gente olvida: *a programar solo puede aprenderse programando*.

### 2.5.1. Tabla de multiplicar

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

### 2.5.2. Juego del número secreto

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
        if (!isset($_REQUEST['numero']])) {
            // La variable "numero" NO existe. Vamos a pedirle que lo escriba en un formulario
			echo "<form action='05-numero-secreto.php' method='get'>
				Adivina mi número:
				<input type='text' name='numero'><br>
				<input type='hidden' name='aleatorio' value='$aleatorio'>
				<input type='hidden' name='intentos' value='$intentos'>
				<br>				
				<input type='submit'>
				</form>";
            // ¿Y el número aleatorio? Si aún no existe, significa que es LA PRIMERA ejecución y aún tenemos que elegirlo.
            // En cambio, si ya existe, tendremos que recuperarlo para seguir usando el mismo aleatorio y no uno nuevo cada vez.
            if (!isset($_REQUEST['aleatorio'])) {
				$intentos = 0;
				$aleatorio = rand(1,100);
			} else {
				$aleatorio = $_REQUEST['aleatorio'];
				$intentos = $_REQUEST['intentos'];
			}
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
			echo "<br><a href='index.php?aleatorio=$aleatorio&intentos=$intentos'>Sigue jugando...</a>";
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
		session_start();  // Para poder usar variables de sesión

		if (!isset($_REQUEST['numero'])) {
			// NO existe la variable número: vamos a mostrar el formulario
			echo "<form action='05-numero-secreto-v2.php' method='get'>
				Adivina mi número:
				<input type='text' name='numero'><br>
				<br>				
				<input type='submit'>
				</form>";
			// ¿Será la primera ejecución? Vamos a ver si ya existe la variable "aleatorio".
			// Si no existe, la creamos, pero esta vez como variable de sesión, no de URL.
			// Esa variable quedará almacenada en el servidor y seguirá existiendo hasta que
			// cerremos la sesión.
			if (!isset($_SESSION['aleatorio'])) {
				$_SESSION['aleatorio'] = rand(1,100);
				$_SESSION['intentos'] = 0;
			}
		} else {
			// Existe la variable "numero": significa que el usuario rellenó el formulario y pulsó "submit".
			// Vamos a compararla con el aleatorio.
			// Guardaremos "numero" y "aleatorio" en variable locales
			// para manejarlas con más comodidad, pero no es imprescindible hacerlo.
			$n = $_REQUEST['numero'];
			$aleatorio = $_SESSION['aleatorio'];
			$_SESSION['intentos']++;

            echo "Tu número es: $n<br>";
			if ($n > $aleatorio) {
				echo "Mi número es MENOR";
				echo "<br><a href='index.php'>Sigue jugando...</a>";
			}
			else if ($n < $aleatorio) {
				echo "Mi número es MAYOR";
				echo "<br><a href='index.php'>Sigue jugando...</a>";
			}
			else {
				echo "<p>ENHORABUENA, HAS ACERTADO</p>";
				echo "Has necesitado ".$_SESSION['intentos']." intentos";
				unset($_SESSION['aleatorio']);  // Esto destruye la variable de sesión
				echo "<br><a href='index.php'>Jugar de nuevo</a>";
			}
		}

	?>
</body>
</html>
```

### 2.5.3. Biblioteca

Este es un ejemplo muy importante por dos razones:

1. Porque es nuestra primera aplicación web "de verdad", con una base de datos detrás.
2. Porque volveremos sobre ella varias veces a lo largo de las siguientes secciones para hacerle sucesivas mejoras, hasta dejarla presentable.

El código fuente es más largo, pero fácil de seguir. No te desesperes ni intentes leerlo en dos minutos para marcharte a hacer otra cosa. Tómatelo con calma, como si leer el código fuente fuera como leer un manual de instrucciones de un electrodoméstico nuevo que aún no tienes ni idea de cómo se usa.

**Se trata de escribir una aplicación web en PHP que gestione, de forma muy simplificada, una biblioteca**.

La aplicación trabajará con una base de datos compuesta de solo dos tablas (ya te dije que estaría muy simplificada): *libros* y *autores*.

Esta aplicación nos permitirá, en principio, ver la lista de todos los libros disponibles, así como dar de alta libros nuevos y modificar o borrar los libros existentes. De momento no trabajaremos con los autores, pero sería fácil extenderla para que también nos dejase hacer altas, bajas y modificaciones de los autores.

Al leer el código, observa cómo utilizamos una variable muy especial llamada ***$action*** para saber qué tiene que hacer la aplicación en cada momento. Esa variable es el germen de la *arquitectura modelo-vista-controlador* con la que trabajaremos una y otra vez más adelante.

XXX

```php
<!-- BIBLIOTECA VERSIÓN 1
     Características de esta versión:
       - Código monolítico (sin arquitectura MVC)
       - Sin seguridad
       - Sin sesiones ni control de acceso
       - Sin reutilización de código
-->

<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
</head>

<body>
    <?php

    $db = new mysqli("servidor-de-base-de-datos", "usuario", "password", "nombre-base-de-datos");

    // Miramos el valor de la variable "action", si existe. Si no, le asignamos una acción por defecto
    if (isset($_REQUEST["action"])) {
        $action = $_REQUEST["action"];
    } else {
        $action = "mostrarListaLibros";  // Acción por defecto
    }

    // CONTROL DE FLUJO PRINCIPAL
    // El programa saltará a la sección del switch indicada por la variable "action"
    switch ($action) {

        // --------------------------------- MOSTRAR LISTA DE LIBROS ----------------------------------------

        case "mostrarListaLibros":
            echo "<h1>Biblioteca</h1>";

            // Buscamos todos los libros de la biblioteca
            if ($result = $db->query("SELECT * FROM libros
                                        INNER JOIN escriben ON libros.idLibro = escriben.idLibro
                                        INNER JOIN personas ON escriben.idPersona = personas.idPersona
                                        ORDER BY libros.titulo")) {

                // La consulta se ha ejecutado con éxito. Vamos a ver si contiene registros
                if ($result->num_rows != 0) {
                    // La consulta ha devuelto registros: vamos a mostrarlos

                    // Primero, el formulario de búsqueda
                    echo "<form action='index.php'>
                                <input type='hidden' name='action' value='buscarLibros'>
                                <input type='text' name='textoBusqueda'>
                                <input type='submit' value='Buscar'>
                                </form><br>";

                    // Ahora, la tabla con los datos de los libros
                    echo "<table border ='1'>";
                    while ($fila = $result->fetch_object()) {
                        echo "<tr>";
                        echo "<td>" . $fila->titulo . "</td>";
                        echo "<td>" . $fila->genero . "</td>";
                        echo "<td>" . $fila->numPaginas . "</td>";
                        echo "<td>" . $fila->nombre . "</td>";
                        echo "<td>" . $fila->apellido . "</td>";
                        echo "<td><a href='index.php?action=formularioModificarLibro&idLibro=" . $fila->idLibro . "'>Modificar</a></td>";
                        echo "<td><a href='index.php?action=borrarLibro&idLibro=" . $fila->idLibro . "'>Borrar</a></td>";
                        echo "</tr>";
                    }
                    echo "</table>";
                } else {
                    // La consulta no contiene registros
                    echo "No se encontraron datos";
                }
            } else {
                // La consulta ha fallado
                echo "Error al tratar de recuperar los datos de la base de datos. Por favor, inténtelo más tarde";
            }
            echo "<p><a href='index.php?action=formularioInsertarLibros'>Nuevo</a></p>";
            break;

            // --------------------------------- FORMULARIO ALTA DE LIBROS ----------------------------------------

        case "formularioInsertarLibros":
            echo "<h1>Modificación de libros</h1>";

            // Creamos el formulario con los campos del libro
            echo "<form action = 'index.php' method = 'get'>
                    Título:<input type='text' name='titulo'><br>
                    Género:<input type='text' name='genero'><br>
                    País:<input type='text' name='pais'><br>
                    Año:<input type='text' name='ano'><br>
                    Número de páginas:<input type='text' name='numPaginas'><br>";

            // Añadimos un selector para el id del autor o autores
            $result = $db->query("SELECT * FROM personas");
            echo "Autores: <select name='autor[]' multiple='true'>";
            while ($fila = $result->fetch_object()) {
                echo "<option value='" . $fila->idPersona . "'>" . $fila->nombre . " " . $fila->apellido . "</option>";
            }
            echo "</select>";
            echo "<a href='index.php?action=formularioInsertarAutores'>Añadir nuevo</a><br>";

            // Finalizamos el formulario
            echo "  <input type='hidden' name='action' value='insertarLibro'>
					<input type='submit'>
				</form>";
            echo "<p><a href='index.php'>Volver</a></p>";

            break;

            // --------------------------------- INSERTAR LIBROS ----------------------------------------

        case "insertarLibro":
            echo "<h1>Alta de libros</h1>";

            // Vamos a procesar el formulario de alta de libros
            // Primero, recuperamos todos los datos del formulario
            $titulo = $_REQUEST["titulo"];
            $genero = $_REQUEST["genero"];
            $pais = $_REQUEST["pais"];
            $ano = $_REQUEST["ano"];
            $numPaginas = $_REQUEST["numPaginas"];
            $autores = $_REQUEST["autor"];

            // Lanzamos el INSERT contra la BD.
            echo "INSERT INTO libros (titulo,genero,pais,ano,numPaginas) VALUES ('$titulo','$genero', '$pais', '$ano', '$numPaginas')";
            $db->query("INSERT INTO libros (titulo,genero,pais,ano,numPaginas) VALUES ('$titulo','$genero', '$pais', '$ano', '$numPaginas')");
            if ($db->affected_rows == 1) {
                // Si la inserción del libro ha funcionado, continuamos insertando en la tabla "escriben"
                // Tenemos que averiguar qué idLibro se ha asignado al libro que acabamos de insertar
                $result = $db->query("SELECT MAX(idLibro) AS ultimoIdLibro FROM libros");
                $idLibro = $result->fetch_object()->ultimoIdLibro;
                // Ya podemos insertar todos los autores junto con el libro en "escriben"
                foreach ($autores as $idAutor) {
                    $db->query("INSERT INTO escriben(idLibro, idPersona) VALUES('$idLibro', '$idAutor')");
                }
                echo "Libro insertado con éxito";
            } else {
                // Si la inserción del libro ha fallado, mostramos mensaje de error
                echo "Ha ocurrido un error al insertar el libro. Por favor, inténtelo más tarde.";
            }
            echo "<p><a href='index.php'>Volver</a></p>";

            break;

            // --------------------------------- BORRAR LIBROS ----------------------------------------

        case "borrarLibro":
            echo "<h1>Borrar libros</h1>";

            // Recuperamos el id del libro y lanzamos el DELETE contra la BD
            $idLibro = $_REQUEST["idLibro"];
            $db->query("DELETE FROM libros WHERE idLibro = '$idLibro'");

            // Mostramos mensaje con el resultado de la operación
            if ($db->affected_rows == 0) {
                echo "Ha ocurrido un error al borrar el libro. Por favor, inténtelo de nuevo";
            } else {
                echo "Libro borrado con éxito";
            }
            echo "<p><a href='index.php'>Volver</a></p>";

            break;

            // --------------------------------- FORMULARIO MODIFICAR LIBROS ----------------------------------------

        case "formularioModificarLibro":
            echo "<h1>Modificación de libros</h1>";

            // Recuperamos el id del libro que vamos a modificar y sacamos el resto de sus datos de la BD
            $idLibro = $_REQUEST["idLibro"];
            $result = $db->query("SELECT * FROM libros WHERE libros.idLibro = '$idLibro'");
            $libro = $result->fetch_object();

            // Creamos el formulario con los campos del libro
            // y lo rellenamos con los datos que hemos recuperado de la BD
            echo "<form action = 'index.php' method = 'get'>
				    <input type='hidden' name='idLibro' value='$idLibro'>
                    Título:<input type='text' name='titulo' value='$libro->titulo'><br>
                    Género:<input type='text' name='genero' value='$libro->genero'><br>
                    País:<input type='text' name='pais' value='$libro->pais'><br>
                    Año:<input type='text' name='ano' value='$libro->ano'><br>
                    Número de páginas:<input type='text' name='numPaginas' value='$libro->numPaginas'><br>";

            // Vamos a añadir un selector para el id del autor o autores.
            // Para que salgan preseleccionados los autores del libro que estamos modificando, vamos a buscar
            // también a esos autores.
            $todosLosAutores = $db->query("SELECT * FROM personas");  // Obtener todos los autores
            $autoresLibro = $db->query("SELECT idPersona FROM escriben WHERE idLibro = '$idLibro'");             // Obtener solo los autores del libro que estamos buscando
            // Vamos a convertir esa lista de autores del libro en un array de ids de personas
            $listaAutoresLibro = array();
            while ($autor = $autoresLibro->fetch_object()) {
                $listaAutoresLibro[] = $autor->idPersona;
            }

            // Ya tenemos todos los datos para añadir el selector de autores al formulario
            echo "Autores: <select name='autor[]' multiple size='3'>";
            while ($fila = $todosLosAutores->fetch_object()) {
                if (in_array($fila->idPersona, $listaAutoresLibro))
                    echo "<option value='$fila->idPersona' selected>$fila->nombre $fila->apellido</option>";
                else
                    echo "<option value='$fila->idPersona'>$fila->nombre $fila->apellido</option>";
            }
            echo "</select>";

            // Por último, un enlace para crear un nuevo autor
            echo "<a href='index.php?action=formularioInsertarAutores'>Añadir nuevo</a><br>";

            // Finalizamos el formulario
            echo "  <input type='hidden' name='action' value='modificarLibro'>
                    <input type='submit'>
                  </form>";
            echo "<p><a href='index.php'>Volver</a></p>";

            break;

            // --------------------------------- MODIFICAR LIBROS ----------------------------------------

        case "modificarLibro":
            echo "<h1>Modificación de libros</h1>";

            // Vamos a procesar el formulario de modificación de libros
            // Primero, recuperamos todos los datos del formulario
            $idLibro = $_REQUEST["idLibro"];
            $titulo = $_REQUEST["titulo"];
            $genero = $_REQUEST["genero"];
            $pais = $_REQUEST["pais"];
            $ano = $_REQUEST["ano"];
            $numPaginas = $_REQUEST["numPaginas"];
            $autores = $_REQUEST["autor"];

            // Lanzamos el UPDATE contra la base de datos.
            $db->query("UPDATE libros SET
							titulo = '$titulo',
							genero = '$genero',
							pais = '$pais',
							ano = '$ano',
							numPaginas = '$numPaginas'
							WHERE idLibro = '$idLibro'");

            if ($db->affected_rows == 1) {
                // Si la modificación del libro ha funcionado, continuamos actualizando la tabla "escriben".
                // Primero borraremos todos los registros del libro actual y luego los insertaremos de nuevo
                $db->query("DELETE FROM escriben WHERE idLibro = '$idLibro'");
                // Ya podemos insertar todos los autores junto con el libro en "escriben"
                foreach ($autores as $idAutor) {
                    $db->query("INSERT INTO escriben(idLibro, idPersona) VALUES('$idLibro', '$idAutor')");
                }
                echo "Libro actualizado con éxito";
            } else {
                // Si la modificación del libro ha fallado, mostramos mensaje de error
                echo "Ha ocurrido un error al modificar el libro. Por favor, inténtelo más tarde.";
            }
            echo "<p><a href='index.php'>Volver</a></p>";
            break;

            // --------------------------------- BUSCAR LIBROS ----------------------------------------

        case "buscarLibros":
            // Recuperamos el texto de búsqueda de la variable de formulario
            $textoBusqueda = $_REQUEST["textoBusqueda"];
            echo "<h1>Resultados de la búsqueda: \"$textoBusqueda\"</h1>";

            // Buscamos los libros de la biblioteca que coincidan con el texto de búsqueda
            if ($result = $db->query("SELECT * FROM libros
					INNER JOIN escriben ON libros.idLibro = escriben.idLibro
					INNER JOIN personas ON escriben.idPersona = personas.idPersona
					WHERE libros.titulo LIKE '%$textoBusqueda%'
					OR libros.genero LIKE '%$textoBusqueda%'
					OR personas.nombre LIKE '%$textoBusqueda%'
					OR personas.apellido LIKE '%$textoBusqueda%'
					ORDER BY libros.titulo")) {

                // La consulta se ha ejecutado con éxito. Vamos a ver si contiene registros
                if ($result->num_rows != 0) {
                    // La consulta ha devuelto registros: vamos a mostrarlos
                    // Primero, el formulario de búsqueda
                    echo "<form action='index.php'>
								<input type='hidden' name='action' value='buscarLibros'>
                            	<input type='text' name='textoBusqueda'>
								<input type='submit' value='Buscar'>
                          </form><br>";
                    // Después, la tabla con los datos
                    echo "<table border ='1'>";
                    while ($fila = $result->fetch_object()) {
                        echo "<tr>";
                        echo "<td>" . $fila->titulo . "</td>";
                        echo "<td>" . $fila->genero . "</td>";
                        echo "<td>" . $fila->numPaginas . "</td>";
                        echo "<td>" . $fila->nombre . "</td>";
                        echo "<td>" . $fila->apellido . "</td>";
                        echo "<td><a href='index.php?action=formularioModificarLibro&idLibro=" . $fila->idLibro . "'>Modificar</a></td>";
                        echo "<td><a href='index.php?action=borrarLibro&idLibro=" . $fila->idLibro . "'>Borrar</a></td>";
                        echo "</tr>";
                    }
                    echo "</table>";
                } else {
                    // La consulta no contiene registros
                    echo "No se encontraron datos";
                }
            } else {
                // La consulta ha fallado
                echo "Error al tratar de recuperar los datos de la base de datos. Por favor, inténtelo más tarde";
            }
            echo "<p><a href='index.php?action=formularioInsertarLibros'>Nuevo</a></p>";
            echo "<p><a href='index.php'>Volver</a></p>";
            break;

            // --------------------------------- ACTION NO ENCONTRADA ----------------------------------------

        default:
            echo "<h1>Error 404: página no encontrada</h1>";
            echo "<a href='index.php'>Volver</a>";
            break;
    } // switch

    ?>

</body>

</html>
```
```
