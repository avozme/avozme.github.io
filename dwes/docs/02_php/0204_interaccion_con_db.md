---
layout: page
title: 2.4 Interacción con la base de datos
permalink: /php/interaccion-con-php
nav_order: 4
has_children: false
parent: 2 Introducción a PHP
grand_parent: Desarrollo Web en Entorno Servidor
---

## 2.4. Interacción entre MariaDB y PHP
{: .no_toc }

- TOC
{:toc}

A partir de ahora, vamos a referirnos a MySQL/MariaDB indistintamente. Este será el gestor de bases de datos relacionales que vamos a usar a lo largo del curso. La adaptación a otros gestores, en cualquier caso, es muy simple.

MySQL/MariaDB, como ya hemos visto, es un SGBD relacional de probada eficacia. La interacción con él resulta eficiente y segura para casi cualquier aplicación web que podamos concebir.

Hay básicamente tres métodos de utilizar MySQL/MariaDB:

* **A través de la línea de comandos:**

   Iniciamos una sesión en MySQL con:
   
   ```
   $ mysql -h servidor -u nombre_usuario -p
   ```

   Y luego tenemos a nuestra disposición montones de comandos para hacer cosas con la base de datos, incluyendo ejecutar cualquier instrucción válida en SQL.

* **A través de una aplicación con interfaz gráfico**, como PHPMyAdmin, una aplicación web escrita en PHP que proporciona un interfaz muy cómodo para trabajar con MySQL o MariaDB. Si no la conoces, te recomiendo que la uses a partir de ahora porque te la vas a encontrar en casi todos los servidores web.

* **A través de un programa escrito en PHP** o algún otro lenguaje con posibilidad de acceso a MySQL. Este método de acceso será el que nosotros usaremos en nuestros programas para convertirlos en auténticas aplicaciones web.

En esta sección, vamos a ver lo fundamental para usar MySQL desde un programa en PHP. Iremos perfeccionando nuestras habilidades al respecto a lo largo del resto del curso.

### 2.4.1. MySQL/MariaDB con PHP4

Si PHP4 está obsoleto, ¿por qué hay un apartado dedicado al acceso a MySQL desde PHP4?

Buena pregunta. La respuesta es simple: <span style='color: red'>*para que sepas lo que **NO** tienes que hacer*</span>.

El hecho es que encontrarás aún mucho código PHP4 pululando por internet. Los sitios donde haya código de ese estilo deben ser evitados. Suele tratarse de blogs antiguos, tutoriales obsoletos o, simplemente, gente ignorante con ganas de ayudar pero que anda bastante perdida.

#### Acceso a MySQL con PHP4 (¡OBSOLETO!)

El modo en que se accedía a bases de datos en PHP4 era mediante **bibliotecas de funciones diferentes para cada SGBD**.

Lo digo otra vez: *esta forma de programar está obsoleta y se desaconseja su uso*. No tiene soporte oficial. Si aparecen problemas de seguridad o estabilidad, nadie los va a resolver. Si encuentras código de este estilo en internet, lárgate de ese sitio, porque no vas a aprender nada útil.

PHP4 utilizaba una biblioteca de funciones PHP cuyo nombre empiezaba por las letras *mysql_*.

Por ejemplo, para insertar un registro en una BD MySQL, se hacía así:

```php
<?php
// Conectamos con MySQL
mysql_connect("URL","nombre_usuario","contraseña");

// Seleccionamos la base de datos con la que vamos a trabajar
mysql_select_db("nombre_base_de_datos");

// Ejecutamos una sentencia SQL
mysql_query("INSERT INTO clientes (nombre,telefono) VALUES ('$nombre','$telefono')");
?>
```

Y para ejecutar consultas (SELECT), se hacía más o menos como en este ejemplo. No es necesario que lo entiendas todo. Basta con que te hagas una idea de la manera en la que trabajaba PHP4 para que sepas identificarlo si te lo encuentras por ahí:

```php
<?php
//Nos conectamos con MySQL
mysql_connect("URL","user","password");

//Seleccionamos la base de datos con la que vamos a trabajar
mysql_select_db("nombre_base_datos");

//Ejecutamos la consulta SQL para obtener toda la tabla de Clientes
$result=mysql_query("SELECT * FROM Clientes");
?>

<table align="center"><tr>
<th>Nombre</th>
<th>Teléfono</th></tr>

<?
//Mostramos los nombres y teléfonos de los clientes
while ($registro=mysql_fetch_array($result)) {
echo '<tr><td>'.$registro["nombre"].'</td>';
echo '<td>'.$registro["telefono"].'</td></tr>';
}
mysql_free_result($result)
?>

</table>
</body>
```

### 2.4.2. MySQL/MariaDB con PHP5+

Desde PHP5, se utiliza **una biblioteca de clases para acceder a los diferentes SGBDs**.

Todos los nuevos desarrollos deberían usar las bibliotecas de clases y prescindir de las viejas librerías de funciones.

<span style='color: red'>*Vuelvo a repetirlo: mucho código de ejemplo de PHP que circula por la red es PHP4 y DEBE SER EVITADO.*</span>

#### Formas de acceder a bases de datos en PHP

PHP proporciona varios mecanismos para acceder a bases de datos (ya te lo dije antes: en PHP, casi todo se puede hacer de varias maneras distintas):

* **Forma 1: Usar la extensión mysqli en su forma procedimental.**

   Esta forma recuerda mucho a PHP4, pero cambiando la palabra “mysql” por “mysqli”. 

   Por ejemplo, la función *mysql_connect()* ahora se llama *mysqli_connect()* (la "i" significa "improved", es decir, "mejorado").

   Esta forma es apta para programadores/as perezosos y anticuados, que no quieren pasarse a la programación orientada a objetos y se sienten cómodos con la forma de codificación tradicional. Pero ese no es tu caso, ¿verdad? Así que nunca utilizaremos la forma procedimental.

* **Forma 2: Usar la extensión mysqli en su forma orientada a objetos.**

   Se accede a la base de datos a través de un objeto de la clase *mysqli*. Es decir, se crea una instancia (con ```new mysqli()```) y, a través de ella, se tiene acceso a todos los métodos para interactuar con la base de datos.

   Si en lugar de una base de datos MySQL, trabajamos con otro gestor de base de datos, hay que crear un objeto de otro tipo. Por ejemplo, la clase *SQLite3* sirve para conectar con bases de datos SQLite. Hay otros gestores que solo ofrecen la forma procedimental.
   
   Nosotros, como somos muy modernos, usaremos esta forma de conectar a MySQL durante el resto de este texto.
   
* **Forma 3: Usar la extensión PDO.**

   A partir de PHP 5.1, existe una clase genérica, llamada *PDO*, que permite acceder a cualquier gestor de bases de datos mediante el mismo conjunto de métodos. Es lo que se llama una *capa de abstracción de acceso a datos*
   
   Esto significa que, independientemente de la base de datos que se esté utilizando, PDO permite utilizar los mismos métodos para realizar consultas y obtener datos, por lo que es una forma de trabajo perfectamente válida y que podríamos haber usado en lugar de la extensión mysqli.

#### Inserción, modificación y borrado de datos con PHP5+

Vamos a ver cómo funciona la clase *mysqli* mediante unos cuantos ejemplos. En primer lugar, lanzaremos una inserción de datos.

Imagina que tenemos una base de datos MySQL o MariaDB llamada *mi-base-de-datos* que contiene una tabla de clientes donde guardamos, entre otras cosas, los nombres y los teléfonos de los clientes.

Insertar un registro en esa tabla desde PHP se logra en solo dos pasos:

```php
<?php
// Conectamos con el servidor y abrimos la BD
$conexdb = new mysqli('servidor','nombre-de-usuario','password','mi-base-de-datos');

// Insertamos un registro en una tabla (aquí se podría escribir cualquier sentencia SQL válida)
$conexdb->query("INSERT INTO clientes (nombre,telefono) VALUES ('$nombre','$telefono')");
?>
```

Si sustituyes la sentencia INSERT por cualquier otra instrucción SQL válida, también funcionará. Con una excepción: SELECT se ejecuta de otra manera que enseguida veremos.

Por lo tanto, el código anterior te puede servir de base para ejecutar cualquier INSERT, UPDATE o DELETE sobre tu base de datos. O incluso sentencias de definición de la base de datos, como CREATE TABLE o ALTER TABLE (siempre que el usuario con el que te estés conectando tenga permisos para ejecutarlas, claro)

#### Consultas con PHP5+

Hemos dicho que las sentencias SELECT se lanzan desde PHP de un modo diferente al resto. ¿Por qué será?

La respuesta es sencilla de entender: la ejecución de consultas (SELECT) produce la devolución de un conjunto de registros, mientras que cualquier otra instucción (INSERT, UPDATE, DELETE o lo que sea) no devuelve ningún registro. 

Los registros obtenidos como resultado de un SELECT se manejan en PHP con un objeto denominado **cursor**. Un cursor no es más que un puntero al conjunto de resultados que señala al registro que se va a procesar a continuación.

Es decir: se parece al cursor de tu procesador de textos, que te indica el lugar en el que vas a insertar o borrar caracteres. 

En el caso de los cursores MySQL, no te permiten borrar nada. El cursor solo señala un registro concreto dentro de los resultados del SELECT.

Observa cómo se hace un SELECT en este ejemplo:

```php
<body>
<?php
//Nos conectamos con MySQL
$db = new mysqli("servidor","user","password", "database");

// Comprobamos que la conexión se ha realizado
if($db->connect_error){
    die("Error en la conexion : ".$db->connect_error);
}

//Ejecutamos la consulta SQL
$result=$db->query("SELECT * FROM Clientes");
?>

<table align="center"><tr>
   <th>Nombre</th>
   <th>Teléfono</th></tr>
<?
//Mostramos los registros de SELECT
while ($registro=$result->fetch_array()) {
   echo '<tr><td>'.$registro["nombre"].'</td>';
   echo '<td>'.$registro["telefono"].'</td></tr>';
}
$db->free($result);  // Libera memoria usada por cursor
$db->close();   // Cierra la conexión con el servidor
?>
</table>
</body>
```

Probablemente ya lo hayas captado sin necesidad de explicaciones adicionales, pero, por si acaso no es así, ahí va una explicación adicional gratuita.

Cuando se lanza una consulta contra una base de datos desde PHP, la base de datos nos devuelve el resultado en un *cursor*, como hemos dicho. Ese objeto de tipo cursor lo almacenamos en una variable que, en este ejemplo, hemos llamado *$result*.

Recuerda que un cursor es un apuntador a un conjunto de resultados. Cuando un cursor está recién abierto, *siempre apunta al primer registro de ese conjunto de resultados*.

Nuestra variable *result* es un objeto (su clase se llama *mysqli_result*, por cierto). Y, como cualquier objeto, contiene una serie de métodos. Entre esos métodos, cualquier cursor siempre nos ofrecerá un método importantísimo llamado ***fetch()*** o algo semejante.

El método *fetch()* hace lo siguiente: nos devuelve el siguiente dato almacenado en el cursor (en nuestro caso, un registro completo) y hace avanzar al cursor para que apunte al siguiente dato (en nuestro caso, el siguiente registro). Así, lo deja preparado para recuperar otro registro en la siguiente iteración.

Por eso hemos colocado la instrucción *fetch()* en un bucle. Ahora todo empieza a encajar, ¿verdad? 

Cuando el cursor está recién abierto, el primer *fetch()* nos devuelve el primer registro del resultado. Es decir, el primer cliente. Podemos acceder a los campos de ese registro (como "nombre" o "teléfono") accediendo al registro como si fuera un array ($registro["nomnre"], $registro["telefono"], etc). Por eso el método no se llama solo *fetch()*, sino *fetch_array()*.

Pero *fetch()* no solo recupera el primer registro, sino que hace avanzar el cursor para que se quede apuntando al segundo. De este modo, en la siguiente iteración del bucle, *fetch_array()* nos recupera *el segundo* registro (el segundo cliente), y el cursor queda apuntando al tercero, listo para la siguiente iteración.

Cuando no quedan más registros que procesar, *fetch()* devuelve *false* y el bucle termina. De ese modo, habremos procesado fácilmente todo el conjunto de resultados devueltos por la consulta.

El método *fetch()* tiene varias formas. Nosotros usaremos sobre todo estas dos:
* ***fetch_array()***, como en el ejemplo anterior. Cada registro del resultado tiene forma de array. Para acceder, por ejemplo, al nombre de un cliente, escribimos algo como ```$registro["nombre"]```.
* ***fetch_object()***, que funciona igual, pero cada registro del resultado tiene forma de objeto. Para acceder, por ejemplo, al nombre de un cliente, escribimos algo como ```$registro->nombre```.

