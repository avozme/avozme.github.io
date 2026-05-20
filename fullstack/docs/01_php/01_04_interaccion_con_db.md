---
layout: page
title: 1.4 Interacción con la base de datos
permalink: /php/interaccion-con-mysql.html
nav_order: 4
has_children: false
parent: 1 Programación web con PHP
grand_parent: Desarrollo web full stack
---

## 1.4. Interacción entre MariaDB y PHP
{: .no_toc }

- TOC
{:toc}

A partir de ahora, vamos a referirnos a MySQL/MariaDB indistintamente. Este será el gestor de bases de datos relacionales que vamos a usar a lo largo del curso. La adaptación a otros gestores, en cualquier caso, es muy simple.

MySQL/MariaDB, como ya hemos visto, es un SGBD relacional de probada eficacia. La interacción con él resulta eficiente y segura para casi cualquier aplicación web que podamos concebir.


### 1.4.1. MySQL/MariaDB con PHP4 (¡Ojo! ¡Obsoleto!)

En la red hay mucho código PHP obsoleto que ***NO debes utilizar bajo ningún concepto*** porque es muy inseguro.

Si encuentras código que se parece al siguiente, huye de esa página porque no te va a ayudar:

```php
<?php
// *** CÓDIGO OBSOLETO -- ¡¡¡NO USAR!!!***

// Conectamos con MySQL
mysql_connect("URL","nombre_usuario","contraseña");

// Seleccionamos la base de datos con la que vamos a trabajar
mysql_select_db("nombre_base_de_datos");

// Ejecutamos una sentencia SQL
mysql_query("INSERT INTO clientes (nombre,telefono) VALUES ('$nombre','$telefono')");
```

### 1.4.2. MySQL/MariaDB a partir de PHP5

Desde PHP5, se utiliza **una biblioteca de clases para acceder a los diferentes SGBDs**.

Todos los nuevos desarrollos deberían usar las bibliotecas de clases y prescindir de las viejas librerías de funciones.

#### La forma profesional de acceder a bases de datos en PHP

Aunque PHP ofrece varios mecanismos, el estándar profesional es uno:

* **La extensión PDO (PHP Data Objects)**
      

   A partir de PHP 5.1, existe una clase genérica, llamada *PDO*, que permite acceder a cualquier gestor de bases de datos mediante el mismo conjunto de métodos. Es lo que se llama una *capa de abstracción de acceso a datos*
   
   Esto significa que, independientemente de la base de datos que se esté utilizando, PDO permite utilizar los mismos métodos para realizar consultas y obtener datos, por lo que es la forma de trabajo más flexible y la que vamos a utilizar en este curso.

### 1.4.3. Inserción, modificación y borrado de datos con PDO

Vamos a ver cómo funciona la clase *PDO* mediante unos cuantos ejemplos. En primer lugar, lanzaremos una inserción de datos.

Insertar un registro en una tabla desde PHP requiere configurar la conexión y usar **sentencias preparadas** para evitar ataques de inyección SQL.

```php
declare(strict_types=1);

// Configuración (esto suele ir en un archivo de configuración separado)
$dsn = "mysql:host=servidor;dbname=mi-base-de-datos;charset=utf8mb4";
$usuario = "usuario_db";
$clave = "password_seguro";

try {
    // 1. Conexión segura
    $pdo = new PDO($dsn, $usuario, $clave, [
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
        PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
    ]);

    // 2. Sentencia preparada con parámetros nombrados
    $sql = "INSERT INTO clientes (nombre, telefono) VALUES (:nombre, :telefono)";
    $stmt = $pdo->prepare($sql);

    // 3. Ejecución segura
    $stmt->execute([
        "nombre" => $nombre,
        "telefono" => $telefono
    ]);

    echo "Registro insertado correctamente";

} catch (PDOException $e) {
    // En producción, nunca mostrar el mensaje exacto al usuario
    error_log($e->getMessage());
    echo "Hubo un error al procesar la solicitud.";
}
```

Si sustituyes la sentencia INSERT por cualquier otra instrucción SQL válida, también funcionará, con la excepción de SELECT, que se maneja de otra manera que enseguida veremos.

Por lo tanto, el código anterior te puede servir de base para ejecutar cualquier INSERT, UPDATE o DELETE sobre tu base de datos. O incluso sentencias de definición de la base de datos, como CREATE TABLE o ALTER TABLE (siempre que el usuario con el que te estés conectando tenga permisos para ejecutarlas, claro)

### 1.4.4. Consultas con PDO

Hemos dicho que las sentencias SELECT se lanzan desde PHP de un modo diferente al resto. ¿Por qué será?

La respuesta es sencilla de entender: la ejecución de consultas (SELECT) produce la devolución de un conjunto de registros, mientras que cualquier otra instucción (INSERT, UPDATE, DELETE o lo que sea) no devuelve ningún registro. 

Los registros obtenidos como resultado de un SELECT se manejan en PHP con un objeto denominado **cursor**. Un cursor no es más que un puntero al conjunto de resultados que señala al registro que se va a procesar a continuación.

Es decir: se parece al cursor de tu procesador de textos, que te indica el lugar en el que vas a insertar o borrar caracteres. 

En el caso de los cursores MySQL, no te permiten borrar nada. El cursor solo señala un registro concreto dentro de los resultados del SELECT.

Observa cómo se hace un SELECT en este ejemplo:

```php
declare(strict_types=1);

// Datos de conexión
$dsn = "mysql:host=servidor;dbname=database;charset=utf8mb4";
$usuario = "user";
$clave   = "password";

try {
    // Conexión segura con PDO
    $pdo = new PDO($dsn, $usuario, $clave, [
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION
    ]);

    // Ejecutamos la consulta
    $sql = "SELECT nombre, telefono FROM Clientes";
    $stmt = $pdo->query($sql);
} catch (PDOException $e) {
    die("Error en la conexión o en la consulta: " . $e->getMessage());
}
?>
<table border="1" align="center">
    <thead>
        <tr>
            <th>Nombre</th>
            <th>Teléfono</th>
        </tr>
    </thead>
    <tbody>
        <?php while ($cliente = $stmt->fetch(PDO::FETCH_ASSOC)): ?>
            <tr>
                <td><?= htmlspecialchars($cliente["nombre"]) ?></td>
                <td><?= htmlspecialchars($cliente["telefono"]) ?></td>
            </tr>
        <?php endwhile; ?>
    </tbody>
</table>
```

Probablemente ya lo hayas captado sin necesidad de explicaciones adicionales, pero, por si acaso no es así, ahí va una explicación adicional gratuita.

Cuando se lanza una consulta contra una base de datos desde PHP, la base de datos nos devuelve el resultado en un *cursor*, como hemos dicho. Ese objeto de tipo cursor lo almacenamos en una variable que, en este ejemplo, hemos llamado *$stmt* (abreviatura de "Statement").

Recuerda que un cursor es un apuntador a un conjunto de resultados. Cuando un cursor está recién abierto, *siempre apunta al primer registro de ese conjunto de resultados*.

Nuestra variable *$stmt* es un objeto y, como cualquier objeto, contiene una serie de métodos. Entre esos métodos, cualquier cursor siempre nos ofrecerá un método importantísimo llamado ***fetch()***.

El método *fetch()* nos devuelve el siguiente dato almacenado en el cursor (en nuestro caso, un registro completo) y hace avanzar al cursor para que apunte al siguiente dato (en nuestro caso, el siguiente registro). Así, lo deja preparado para recuperar otro registro en la siguiente iteración.

Por eso hemos colocado la instrucción *fetch()* en un bucle.

Cuando el cursor está recién abierto, el primer *fetch()* nos devuelve el primer registro del resultado. Es decir, el primer cliente. Podemos acceder a los campos de ese registro (como "nombre" o "teléfono") accediendo al registro como si fuera un array ($registro["nombre"], $registro["telefono"], etc).

Pero *fetch()* no solo recupera el primer registro, sino que hace avanzar el cursor para que se quede apuntando al segundo. De este modo, en la siguiente iteración del bucle, *fetch()* nos recupera *el segundo* registro (el segundo cliente), y el cursor queda apuntando al tercero, listo para la siguiente iteración.

Cuando no quedan más registros que procesar, *fetch()* devuelve *false* y el bucle termina. De ese modo, habremos procesado fácilmente todo el conjunto de resultados devueltos por la consulta.

### 1.4.5. Mejorando la implementación de consultas

Podríamos hacer muchas consideraciones adicionales sobre PHP, pero esto solo es una introducción al lenguaje, así que no profundizaremos mucho.

Sin embargo, me gustaría que vieras una implementación alternativa del código anterior (PHP es muy flexible y admite muchas maneras de hacer lo mismo), porque ilustra algunas características de PHP que me parece que debes conocer:

```php
declare(strict_types=1);

// 1. Lógica: Obtención de datos
try {
    $pdo = new PDO($dsn, $usuario, $clave, [
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
        PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC
    ]);

    $stmt = $pdo->prepare("SELECT nombre, telefono FROM Clientes WHERE id = :id");
    $stmt->execute(['id' => $id]);
    $clientes = $stmt->fetchAll();

} catch (PDOException $e) {
    error_log($e->getMessage());
    die("Error interno del servidor");
}
?>

<!-- 2. Presentación: Renderizado HTML -->
<table>
    <thead>
        <tr>
            <th>Nombre</th>
            <th>Teléfono</th>
        </tr>
    </thead>
    <tbody>
        <?php foreach ($clientes as $cliente): ?>
            <tr>
                <td><?= htmlspecialchars($cliente["nombre"]) ?></td>
                <td><?= htmlspecialchars($cliente["telefono"]) ?></td>
            </tr>
        <?php endforeach; ?>
    </tbody>
</table>
```

Este código es funcionalmente idéntico que el que veíamos antes, pero tiene algunas mejoras interesantes en las que quiero que te fijes:

1. **Separa completamente la lógica del problema (la extracción de datos de la BD) de su presentación**. Cuanto menos se mezcle el código PHP con el código HTML, menos confuso será el resultado. Por eso, en esta solución usamos ***fetchAll()*** en lugar de *fetch()*: para mover todo el resultado a un array asociativo (PDO::FETCH_ASSOC), que es un array PHP normal que podemos procesar más adelante, cuando vayamos a mostrarlo.
2. **Utiliza *<?= ... ?>***. Esto es una abreviatura muy habitual de *<?php echo("...") ?>*.
3. **Utiliza *$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION)***, que fuerza a que PDO lance una excepción si ocurre un error en la consulta. De otro modo, PDO no lanza excepciones, solo devuelve *false* si la consulta falla. El manejador de excepciones es más seguro y puede tener en cuenta más situaciones de error que la simple comprobación de ese *false*.
4. **Utiliza *htmlspecialchars()***. Esto filtra cualquier contenido sospechoso que un atacante malicioso pudiera haber inyectado en tu base de datos, por lo que se considera más seguro que usar solo *echo()* en aplicaciones web. Imagínate que en la BD alguien hubiera logrado inyectar el código *\<script\>location.href='miServidor.com'\</script\>* en el campo *teléfono* de un usuario. ¿Qué pasaría al tratar de mostrar la lista de usuarios? *htmlspecialchars()* impedirá la ejecución de ese código malicioso y de cualquier otra cosa sospechosa o mal formada.

### 1.4.6. Formas de hacer fetch

Como has visto en los ejemplos, al hacer *fetch()* del resultado de una consulta recuperas los datos del siguiente registro, pero esto se puede lograr de varias maneras.

En primer lugar, tenemos dos métodos para hacer *fetch*:
* ***fetch()*** recupera el siguiente registro de la consulta.
* ***fetchAll()*** recupera todos los registros de la consulta.

Además, tanto a *fetch()* como a *fetchAll()* podemos indicarle la forma en la que queremos que se almacenen los datos recuperados en variables PHP. Por ejemplo:

```php
declare(strict_types=1);

$stmt = $pdo->query("SELECT id, nombre FROM usuarios");
while ($fila = $stmt->fetch(PDO::FETCH_ASSOC)) {
    echo $fila['nombre'];
}
```

Aquí se ha usado *fetch(PDO::FETCH_ASSOC)*, que devuelve los datos de la consulta en un array asociativo con esta forma:

```
$fila['id'] = Aquí-va-el-ID;
$fila['nombre'] = "Aquí va el nombre";
```

En cambio, podríamos haber recuperado los datos así:

```php
declare(strict_types=1);

$stmt = $pdo->query("SELECT id, nombre FROM usuarios");
while ($fila = $stmt->fetch(PDO::FETCH_NUM)) {
    echo $fila[1]; // El nombre está en la segunda columna
}
```

En este caso, *fetch(PDO::FETCH_NUM)* nos colocará los datos en un array indexado por números, donde la posición 0 es la primera columna, la posición 1 la segunda, etc:

```
$fila[0] = Aquí-va-el-ID;
$fila[1] = "Aquí va el nombre";
```

Tanto *fetch()* como *fetchAll()* admiten, por tanto, varias posibilidades. Estas son las más interesantes, aunque hay más:

* ***fetch(PDO::FETCH_ASSOC)***: Devuelve los datos en un array asociativo.
* ***fetch(PDO::FETCH_NUM)***: Devuelve los datos en un array indexado por números enteros.
* ***fetch(PDO::FETCH_BOTH)*** (por defecto): Devuelve los datos en un array asociativo y en un array indexado por números enteros, las dos cosas a la vez.
* ***fetch(PDO::FETCH_OBJ)***: Devuelve los datos en un objeto creado para la ocasión (Los datos serían accesibles como *$fila->nombre, $fila->id*, etc).
* ***fetch(PDO::FETCH_CLASS, NombreClase)***: Devuelve los datos como instancias de la clase especificada.
