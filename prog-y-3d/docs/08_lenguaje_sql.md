---
layout: page
title: 8. El lenguaje SQL
permalink: /lenguaje-sql/
nav_order: 8
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 8. El lenguaje SQL
{: .no_toc }

- TOC
{:toc}

Ya sabemos cómo crear bases de datos para nuestros programas a partir del mundo real: diseñamos un diagrama entidad-relación, lo refinamos, lo pasamos a tablas relacionales y, por último, revisamos esas tablas hasta que queden normalizadas.

Sí, lo sé: es un proceso largo y aburrido, pero la base de datos es el cimiento de muchas aplicaciones. Por ejemplo, la inmensa mayoría de las aplicaciones web están basadas en una base de datos. Equivócate en el diseño de esa base de datos, y el resto de la aplicación jamás funcionará bien, por mucho empeño que pongas en el proceso de implementación.

Así que vale la pena dedicar un tiempo al diseño de la base de datos.

¿Y luego qué?

Bien, luego tienes que **acceder a esa base de datos para operar con ella**: insertar datos, modificarlos, borrarlos y, lo más habitual de todo, buscar información y recuperarla para que tu programa (aplicación web o lo que sea) la use.

Para hacer todo eso existe un lenguaje estandarizado que soportan la mayoría de las bases de datos relaciones. Puede que tu nombre te suene: se llama **SQL**, y vamos a dedicar todo este capítulo a aprenderlo

## 8.1. Introducción a SQL

### 8.1.1. Breve historia de SQL

**SQL (Structured Query Language)** es un lenguaje bastante antiguo en términos informáticos, porque su origen se remonta a 1970:

* 1970: Edgar Frank Codd propone el modelo relacional y un **lenguaje de acceso al mismo** basado en el **álgebra relacional**.
* 1977: IBM crea el lenguaje **SEQUEL**, basado en la teoría de Codd, para un SGBD experimental.
* 1979: Oracle utiliza un derivado de SEQUEL por primera vez en un producto comercial. Se cambió su nombre a SQL (Structured Query Language) porque SEQUEL ya estaba registrado como marca comercial.
* 1980: IBM lanza varios gestores de bases de datos, entre ellos el exitoso **DB2**, basados en SQL.
* Década de 1980: SQL tiene un éxito espectacular y cada fabricante de bases de datos utiliza su propio dialecto. Se hace patente la necesidad de una estandarización.
* 1986: Nace **SQL-86**, el primer estándar del lenguaje. Fue publicado por ANSI. ISO lo confirmó en 1987, por lo que a veces se denomina SQL-87.

A partir de entonces, SQL se ha convertido en el lenguaje universal para acceso a bases de datos relacionales y su estándar ha sido revisado continuamente, dando lugar a diferentes versiones: SQL-89, SQL-92, SQL-99, SQL-2003, etc. La revisión más reciente, en el momento de escribir estas líneas, es SQL-2016.

### 8.1.2. Dialectos de SQL

A pesar de que SQL se estandarizó hace mucho tiempo, los SGBD comerciales respetan solo aproximadamente ese estándar.

Es decir, todos incluyen mejoras y añadidos sobre SQL para tratar de superar a los competidores. Estos añadidos son incompatibles entre diferentes SGBD.

Por ese motivo, podemos hablar de ***dialectos* de SQL**.

Si queremos que nuestra base de datos sea portable, hay intentar respetar al máximo el estándar SQL.

### 8.1.3. SQL, un lenguaje para todo

Como vimos en el capítulo anterior, los SGBD relacionales tienen varios lenguajes incorporados:

* **Lenguaje de definición de datos (DDL)**: nos permite crear la representación lógica de los datos y sus relaciones. 
* **Lenguaje de control de datos (DCL)**: sirve para gestionar los permisos de acceso. 
* **Lenguaje de control de transacciones (TCL)**: se utiliza para asegurar la integridad de los datos. 
* **Lenguaje de manipulación de datos (DML)**: nos permite insertar datos, borrarlos, modificarlos, etc. 

Una de las grandes bazas de SQL es que él solito se las apaña para hacer todas estas cosas.

Otro aspecto increíble de SQL es que **no es un lenguaje imperativo**, es decir, no tienes que indicarle cómo hacer las cosas escribiendo algoritmos tradicionales. Más bien, a SQL le dices *el resultado que quieres obtener* y él se encarga de generar un algoritmo para obtenerlo de forma totalmente transparente.

## 8.2. Creando la estructura: lenguaje de definición de datos

El **DDL o lenguaje de definición de datos** es un lenguaje pensado para crar la estructura lógica de la base de datos.

Dicho en otras palabras, el DDL nos permite **crear las tablas, modificarlas y borrarlas**.

SQL, como hemos dicho, incluye instrucciones para implemental el DDL. En concreto, las instrucciones más importantes del DDL de SQL son estas tres:

* **CREATE TABLE**: para crear tablas.
* **ALTER TABLE**: para modificar una tabla existente.
* **DROP TABLE**: para eliminar tablas.

Escribiremos, a partir de ahora, las palabras reservadas de SQL en MAYÚSCULA por convenio y para distinguirlas del resto. Realmente, SQL no distingue mayúsculas de minúsculas, así que puedes escribirlas como prefieras.

### 8.2.1. Creación de tablas: CREATE TABLE

La instrucción **CREATE TABLE** sirve para **crear tablas** en la base de datos. Tiene muchísimas posibilidades. No es mi intención mostrártelas todas, porque para eso necesitarías un curso de SQL avanzado. Pero, a través de algunos ejemplos, aprenderás a usarla a un nivel básico enseguida.

La **sintaxis básica** (que admite montones de añadidos, pero que raramente usarás, al menos al principio) es esta:

```sql
CREATE TABLE nombre_de_tabla (
    columna1 tipo,
    columna2 tipo,
    columna3 tipo,
    etc.
);
```

Por ejemplo, así se **crea una tabla** de *clientes*:

```sql
CREATE TABLE clientes (
   id INTEGER,
   nombre VARCHAR(100),
   apellido1 VARCHAR(100),
   apellido2 VARCHAR(100),
   fecha_nacimiento DATE,
   estatura DECIMAL(1,2),
   email VARCHAR(200)
);
```

SQL maneja multitud de **tipos de datos**, pero por ahora basta con que conozcas estos:

* **INTEGER** = números enteros. Hay varios subtipos, como BIGINT (entero enorme), SMALLINT (entero pequeño), etc. Se diferencian entre sí por el número más grande que son capaces de almacenar. La mayoría de las veces, INTEGER es más que suficiente.
* **VARCHAR** = cadenas de caracteres (se indica la longitud máxima entre paréntesis).
* **CHAR** = cadenas de caracteres. Se diferencia de VARCHAR en que, si no se usan todos los caracteres, se rellenan con espacios. Con los VARCHAR no sucede eso: los caracteres que no se usan, simplemente, no existen. Ante la duda, usa siempre VARCHAR en lugar de CHAR.
* **DECIMAL** = números reales (se indica entre paréntesis la cantidad de cifras antes y después de la coma decimal)
* **DATE** = fechas.
* **TIME** = horas.
* **DATETIME** = fecha y hora.
* **BLOB** = información binaria así, en general. Los campos BLOB pueden usarse para guardar imágenes, archivos ejecutables, secuencias de vídeo o de audio...
* **TEXT** = información de texto de grandes dimensiones, que no nos quepa dentro de un VARCHAR o un CHAR.

Ahora vamos a utilizar **algunos modificadores** en la tabla *clientes*:

```sql
CREATE TABLE clientes (
   id INTEGER NOT NULL UNIQUE AUTO_INCREMENT,
   nombre VARCHAR(100) NOT NULL,
   apellido1 VARCHAR(100) NOT NULL,
   apellido2 VARCHAR(100) NOT NULL,
   fecha_nacimiento DATE,
   estatura DECIMAL(1,2),
   email VARCHAR(200),
   PRIMARY KEY (id)
) DEFAULT CHARACTER SET utf-8 COLLATE utf8-spanish-ci;
```

Fíjate en que hemos añadido algunas cosas a algunas columnas:

* **NOT NULL** significa que ese campo no puede quedarse en blanco, es decir, que todos los clientes deben tener obligatoriamente un valor asignado en ese campo.
* **UNIQUE** significa que el valor de ese campo no puede repetirse, esto es, que debe ser diferente en todos los clientes de la tabla.
* **AUTO_INCREMENT** hace que la base de datos, cada vez que se inserta un registro, asigne a este campo el número entero inmediatamente superior al que se asignó al último registro insertado. Solo funciona con campos de tipo INTEGER. Suele utilizarse en el campo ID de las tablas para no tener que ocuparnos de insertar nosotros un número manualmente.
* **PRIMARY KEY** especifica cual es la clave primaria de la tabla. Pueden ponerse varios campos, separados por comas. Lo lógico es que la clave sea NOT NULL y UNIQUE al mismo tiempo.

También hemos añadido algunos modificadores que afectan a toda la tabla, no solo a algunos campos:
* **CHARACTER SET** indica la condificación de caracteres que va a usarse en la tabla.
* **COLLATE** indica cómo van a ordenarse los caracteres en la tabla. Por ejemplo, usando utf8-spanish-ci nos aseguramos de que la Ñ va entre la N y la P. Si usásemos otras colaciones, la Ñ se ordenaría después de la Z.

Los modificadores que se pueden emplear con un CREATE TABLE son muy numerosos, pero la mayoría se usan con muy poca frecuencia. Los principales son los que hemos visto en este ejemplo.

Otro modificadorde uso frecuente es el que se emplea para la creación de **claves ajenas**. Obsérvalo en este otro ejemplo:

```sql
CREATE TABLE clientes (
   id INTEGER NOT NULL UNIQUE,
   nombre VARCHAR(100) NOT NULL,
   apellido1 VARCHAR(100) NOT NULL,
   apellido2 VARCHAR(100) NOT NULL,
   fecha_nacimiento DATE,
   estatura DECIMAL(1,2),
   email VARCHAR(200),
   id_ciudad INTEGER NOT NULL,
   PRIMARY KEY (id),
   FOREIGN KEY (id_ciudad) REFERENCES ciudades(id)
) DEFAULT CHARACTER SET utf-8 COLLATE utf8-spanish-ci;
```

Hemos añadido el campo *id_ciudad* que, obviamente, es una clave ajena que pertenece a la tabla *ciudades*. Pues bien, para informar a la base de datos que ese campo, en efecto, es una clave ajena, hay que usar FOREIGN KEY, indicándole la tabla (*ciudades*) y el campo (*id*) al que está enlazada nuestra clave ajena.

Por último, debes saber que tanto a restricción de clave primaria como a las restricciones de claves ajenas puede **asignárseles un nombre**. Esto es importante si luego queremos modificar esas claves sin necesidad de borrar toda la tabla (con la consiguiente pérdida de datos) para volver a crearla. Se hace así:

```sql
CREATE TABLE clientes (
   ...
   CONSTRAINT pk_clientes PRIMARY KEY (id),
   CONSTRAINT fk_clientes_ciudades FOREIGN KEY (id_ciudad) REFERENCES ciudades(id)
);
```

Como ves, basta con añadir **CONSTRAINT nombre** a la restricción de clave primaria o de clave ajena. Esto asigna un nombre a esa restricción para poder referirnos a él más adelante (ver ALTER TABLE).

El nombre para las restricciones de clave primaria suele empezar por las letras *pk_* (de "primary key") y el de las restricciones de clave ajena por *fk_* (de "foreign key"), pero esto solo es una convención que no tienes por qué respetar.

### 8.2.2. Modificación de tablas: ALTER TABLE

La **modificación de la estructura de una tabla** que ya existe se hace con la instrucción **ALTER TABLE**.

Vamos a ver cómo trabaja esta instrucción con unos ejemplos basado en la tabla *clientes* del apartado anterior. De nuevo, ALTER TABLE tiene muchísimas opciones, pero las que te voy a mostrar en estos ejemplos cubren el 99% de los usos habituales.

En primer lugar, si queremos **añadir un campo** (o varios) a una tabla ya existente, haremos esto:

```sql
ALTER TABLE clientes
    ADD telefono VARCHAR(15) NOT NULL;
```

También podemos **eliminar un campo** (o columna) existente (cuidado: todos los datos de ese campo se perderán):

```sql
ALTER TABLE clientes
    DROP COLUMN email;
```

Podemos, asimismo, **renombrar campos**:

```sql
ALTER TABLE clientes
    RENAME COLUMN email TO correo_electronico;
```

O podemos **modificar campos**, cambiando su tipo o sus restricciones (¡Ojo! Esto puede afectar a los datos que haya almacenados en ese campo, si la tabla ya tiene datos, puesto que el SGBD intentará convertirlos de un tipo de dato a otro. Si no lo consigue, la instrucción fallará):

```sql
ALTER TABLE
    MODIFY COLUMN telefono INTEGER;
```

Por último, con ALTER TABLE se pueden **crear o borrar las restricciones** de la tabla, tales como claves primarias o claves ajenas.

```sql
ALTER TABLE
    ADD CONSTRAINT pk_clientes PRIMARY KEY(id);
```

Para borrar una restricción, tendremos que haberles asignado un nombre al crear la tabla. Así:

```sql
ALTER TABLE
    DROP CONSTRAINT pk_clientes;
```

### 8.2.3. Borrado de tablas: DROP TABLE

El **borrado de tablas** se hace en sql con la instrucción **DROP TABLE**. Es muy fácil de usar, puesto que solo hay que indicar el nombre de la tabla que queremos borrar.

¡Mucho cuidado! Esta acción es destructiva y perderás todos los datos que hubiera almacenados en esa tabla.

Por ejemplo, para borrar la tabla *clientes* de los ejemplos anteriores, escribiríamos esto:

```sql
DROP TABLE clientes;
```

### 8.2.4. Algunas consideraciones sobre la integridad referencial

La **integridad referencial** es un mecanismo de seguridad de las bases de datos que asegura que la información entre las claves ajenas y las claves primarias a las que hacen referencia permanezca siempre bien sincronizada.

Enseguida pondremos un ejemplo en el que lo entenderás muy bien. Ahora lo importante es que quede claro esto: perder esa sincronización entre clave ajena y clave primaria (es decir, romper la integridad referencial) es equivalente a perder datos. Y, si una base de datos va por ahí perdiendo datos, ¿para qué narices sirve?

#### Entendiendo qué es la integridad referencial

En el siguiente ejemplo se ve muy bien en qué consiste la **pérdida de integridad referencial** y los problemas de pérdida de datos que causa.

Imaginemos dos tablas de una base de datos más grande (por ejemplo, de una biblioteca): la tabla ***libros*** contiene información sobre los libros (*cod_libro* y *título*, entre otros campos), mientras que la tabla ***autores*** contiene información sobre los autores de los libros (*cod_autor* y *nombre*, entre otros campos).

La tabla *libros* tiene una clave ajena, *cod_autor*, que es un campo que en realidad pertenece a la tabla *autores* pero que expandimos hasta *libros* para implementar la relación 1:N entre ambas entidades. ¡Repasa el capítulo anterior, sobre diseño de bases de datos, si no sabes de lo que estamos hablando!

(En realidad, la relación entre *libros* y *autores* es N:N, porque un libro puede ser escrito por muchos autores y cada autor puede escribir muchos libros, pero aquí la consideramos una 1:N para simplificar el ejemplo)

Este es el aspecto que podrían tener esas dos tablas o, al menos, un fragmento de ellas:

![Ejemplo de integridad referencial](/docs/prog-y-3d/_site/assets/images/08-01-integridad-referencial.png)

No hay que se un lince para darse cuenta de que todos los códigos de autor que aparecen en la tabla *libros* se corresponden con autores que **realmente existen** en la tabla *autores*.

¿Pero qué pasaría si, por cualquier razón, un código de autor inexistente acabase por error en la tabla de *libros*? Entonces tendríamos algo como esto:

![Ejemplo de integridad referencial rota](/docs/prog-y-3d/_site/assets/images/08-01-integridad-referencial-rota.png)

Ahí lo tenemos: el libro 484 ("Ana Karenina") está asociado al autor 32, que *no existe en la tabla de autores*. ¿El resultado? **Hemos perdido información**. Ya no hay manera de saber quién escribió ese libro. Es lo mismo que si hubiésemos borrado un registro, o parte de un registro, de una tabla, aunque en realidad nadie ha borrado nada.

Te puedes estar diciendo: "Sí, claro, ¿pero quién va a ser tan idiota de escribir un código que no existe en el campo *cod_autor*?"

Hay cientos de razones por las que el código equivocado puede acabar asignado a una clave ajena: puede tratarse de un error de programación en la aplicación cliente, puede haber un fallo de comunicaciones, puede ocurrir un problema de concurrencia, puede que alguien elimine, a propósito o sin querer, un autor que ya tenía libros asignados.

Y sí, también hay gente idiota en el mundo, esto es incuestionable. Y algunos podrían acabar usando nuestra base de datos.

Como el problema de la integridad referencial es tan frecuente y potencialmente devastador, **las bases de datos se autoprotegen e impiden que la integridad referencial pueda violarse**. 

El efecto colateral de esta obsesión por la protección de los datos es que *no podrás insertar los datos en cualquier orden*. En el ejemplo anterior, tendrás que insertar primero al autor del libro en la tabla *autores* y luego al libro en la tabla *libros*, y no al revés, porque en tal caso estarías violando la integridad referencial.

#### Borrado en cascada

El **borrado en cascada** es una de las formas que tiene la base de datos de proteger la integridad referencial.

Uno de los errores más frecuentes que provoca la violación de la integridad referencial es el borrado de un registro de una tabla que está referenciado en otra tabla como clave ajena.

Para entenderlo mejor, vamos a volver sobre nuestro ejemplo de la tabla ***libros*** y la tabla ***autores***. Supongamos que vamos a borrar un autor (el que tiene código 4):

![Ejemplo de integridad referencial - Borrado](/docs/prog-y-3d/_site/assets/images/08-01-integridad-referencial-borrado-1.png)

El resultado de borrar ese registro es que se rompe la integridad referencial, porque el libro 485 hará referencia a un autor que ya no existe:

![Ejemplo de integridad referencial - Borrado](/docs/prog-y-3d/_site/assets/images/08-01-integridad-referencial-borrado-2.png)

La base de datos impedirá este borrado para no violar la integridad referencial. Pero se puede hacer algo más: **activar el borrado en cascada**.

Cuando se activa el borrado en cascada para una clave ajena, la base de datos se encargará de eliminar los registros adecuados si se borra un registro de la tabla a la que hace referencia esa clave ajena. Así también se protege la integridad referencial.

En el ejemplo anterior, al borrar el autor 4, también se borrarán en cascada (¡y automáticamente!) *todos los libros escritos por ese autor*:

![Ejemplo de integridad referencial - Borrado](/docs/prog-y-3d/_site/assets/images/08-01-integridad-referencial-borrado-3.png)

El borrado en cascada se habilita durante la creación de la tabla con el modificador **ON DELETE CASCADE**. Por ejemplo, si queremos habilitarlo para la tabla *libros* anterior:

```sql
CREATE TABLE libros (
    cod_libro INTEGER NOT NULL UNIQUE,
    titulo VARCHAR(500),
    cod_autor INTEGER NOT NULL,
    FOREIGN KEY (cod_autor) REFERENCES autores(cod_autor) ON DELETE CASCADE
);
```


#### Modificación en cascada

La **modificación de registros** también puede provocar **fallos de integridad referencial**.

Por ejemplo: ¿qué ocurre si modificamos la clave de un registro de nuestra tabla de *autores*?

![Ejemplo de integridad referencial - Modificación](/docs/prog-y-3d/_site/assets/images/08-01-integridad-referencial-modificacion-1.png)

Aquí lo tenemos otra vez: al cambiar el código del autor "Benito Pérez Galdós" de 4 a 5, el libro 485 vuelve a quedarse sin autor. ¡Hemos perdido información de nuevo!

![Ejemplo de integridad referencial - Modificación](/docs/prog-y-3d/_site/assets/images/08-01-integridad-referencial-modificacion-2.png)

Como en el caso del borrado, la base de datos **nos prohibirá** hacer este tipo de cosas para **proteger la integridad referencial**.

Y, como en el caso del borrado, también existe la posibilidad de habilitar la **actualización o modificación en cascada**, de manera que, si cambia el valor de una clave primaria, pueda modificarse el valor de la clave ajena automáticamente:

![Ejemplo de integridad referencial - Modificación](/docs/prog-y-3d/_site/assets/images/08-01-integridad-referencial-modificacion-3.png)

Para habilitar la modificación en cascada, hay que especificarlo con **ON UPDATE CASCADE** durante la creación en la clave ajena:

```sql
CREATE TABLE libros (
    cod_libro INTEGER NOT NULL UNIQUE,
    titulo VARCHAR(500),
    cod_autor INTEGER NOT NULL,
    FOREIGN KEY (cod_autor) REFERENCES autores(cod_autor) ON DELETE CASCADE ON UPDATE CASCADE
);
```

Como ves en este código, la actualización y el borrado en cascada pueden usarse simultáneamente. También pueden habilitarse más tarde, cuando la tabla ya está en uso, mediante un **ALTER TABLE**.

## 8.3. Usando los datos: lenguaje de manipulación de datos

Hasta aquí hemos visto cómo SQL nos permite crear la estructura de la base de datos, es decir, las tablas con sus campos, tipos, restricciones, etc.

Pero aún no lo hemos usado para **almacenar y manipular datos**, que es el objetivo final de toda base de datos. De eso se encarga otra parte de SQL llamada **DML** (lenguaje de manipulación de datos).

En realidad, la creación de la estructura se hace solo una vez, cuando la base de datos se construye. Cuando la base de datos ya está en uso, raramente se altera la estructura, puesto que sería como modificar la estructura de una casa cuando ya está habitada: hay que meterse de albañiles y eso siempre es un engorro.

*Durante la inmensa mayoría del tiempo de explotación de una base de datos, el SQL que se utiliza es el que vamos a ver en esta sección.*

SQL tiene varias instrucciones para manipular datos, pero nos vamos a centrar en las cuatro más importantes:

* **INSERT**: sirve para insertar datos en una tabla.
* **UPDATE**: modifica datos ya existentes.
* **DELETE**: elimina datos de una tabla.
* **SELECT**: consulta datos de una o varias tablas.

Insisto en la idea: estas instrucciones actúan a nivel de datos, es decir, de *registros* o *filas* de las tablas. Insertan, modifican y borran registros. Para insertar, modificar y borrar *campos* está el lenguaje de definición de datos, es decir, CREATE TABLE, ALTER TABLE o DROP TABLE.

### 8.3.1. Inserción de datos: INSERT

La instrucción **INSERT** se utiliza para **insertar registros en una tabla**.

Como siempre, vamos a aprender a utilizarla mediante algunos ejemplos.

Supongamos que tenemos una tabla llamada *personas* con los siguientes campos:

```
PERSONAS(id, nombre, apellido1, apellido2, estatura, fecha_nacimiento, pais_nacimiento)
```

Esta tabla se habrá creado mediante esta instrucción:

```sql
CREATE TABLE personas (
   id INTEGER NOT NULL UNIQUE AUTO_INCREMENT,
   nombre VARCHAR(100) NOT NULL,
   apellido1 VARCHAR(100) NOT NULL,
   apellido2 VARCHAR(100) NOT NULL,
   estatura INTEGER,
   fecha_nacimiento DATE,
   pais_nacimiento VARCHAR(100),
   PRIMARY KEY (id)
);
```

Pues bien: para **insertar una fila** en esta tabla, basta con escribir esta instrucción **INSERT**:

```sql
INSERT INTO personas(nombre, apellido1, apellido2, estatura, fecha_nacimiento, pais_nacimiento)
       VALUES ('José', 'Pérez', 'Sánchez', '179', '13/12/1998', 'México');
```

En este código puedes observar varias cosas curiosas:

* No indicamos el valor del campo *id* porque lo hemos declarado como AUTO_INCREMENT y la base de datos se encargará de asignarle un valor automáticamente.
* Primero indicamos una lista de campos y luego una lista de valores. Los valores se asignarán a los campos en el mismo orden en el que están escritos.
* No hacemos distinción entre campos de texto, numéricos o fechas: todos los valores se escriben entre comillas. Da igual que sean comillas simples (') o dobles ("): SQL admite las dos. De hecho, los números pueden escribirse sin comillas, pero, para evitar errores, mi recomendación es que escribas todos los valores, siempre, entre comillas.

Es posible no asignar valores a todos los campos. Por ejemplo, *estatura*, *fecha_nacimiento* y *pais_nacimiento* no están declarados como NOT NULL, es decir, que se pueden dejar en blanco, así que este INSERT también funcionaría:

```sql
INSERT INTO personas(nombre, apellido1, apellido2)
       VALUES ('Susana', 'García', 'Moreno');
```

En cambio, si intentamos dejar en blanco el nombre o uno de los dos apellidos, el INSERT fallará.

### 8.3.2. Modificación de datos: UPDATE

La **modificación o actualización de registros** se hace mediante la instrucción **UPDATE**.

La podemos ver en acción en este ejemplo basado en la misma tabla *personas* del apartado anterior:

```sql
UPDATE personas
   SET nombre = 'Luis'
   WHERE id = 18;
```

Lo que hace UPDATE es localizar un registro que coincida con la condición expresada en la cláusula WHERE, el decir, localiza el registro cuyo id valga 18, y modifica el valor del campo *nombre* de ese registro, asignándole el valor "Luis".

Se pueden actualizar varios campos a la vez:

```sql
UPDATE personas
   SET nombre = 'Luis',
       estatura = '180'
   WHERE id = 25;
```

Y también se puede usar otra condición que no sea sobre el campo *id*. Por ejemplo, esta instrucción UPDATE actualizará todos los nombres almacenados como "Paco" y los cambiará por "Francisco".

```sql
UPDATE personas
   SET nombre = 'Francisco'
   WHERE nombre = 'Paco';
```

Por lo tanto, un UPDATE puede afectar 0, 1 o muchas filas de la tabla. ¡Mucho cuidado con ejecutar un UPDATE sin cláusula WHERE! Esa actualización afectará a **todos los registros** de la tabla:

```sql
UPDATE personas
   SET nombre = 'Francisco';
```

¡Acabamos de cambiar el nombre de todas las personas de nuestra base de datos!


### 8.3.3. Borrado de datos: DELETE

Para **eliminar registros** utilizamos la instrucción **DELETE**.

Aquí tienes un ejemplo sobre la tabla *personas*. Vamos a borrar la persona con id = 18:

```sql
DELETE FROM personas WHERE id = 18;
```

Al igual que UPDATE, DELETE localizará el registro (o registros) que coincida con la condición expresada en la cláusula WHERE. Y, una vez localizado, lo borrará.

Obviamente, DELETE es una **instrucción destructiva** y debe usarse con cautela.

Se pueden borrar varios registros a la vez. Por ejemplo, así borraremos a todas las personas cuyo primer apellido sea "Pérez":

```sql
DELETE FROM personas WHERE apellido1 = 'Pérez';
```

Y así borramos **todos los registros** de una tabla y la dejamos completamente vacía. ¡Utilízalo solo cuando estés muy seguro/a de lo que estás haciendo!

```sql
DELETE FROM personas;
```

## 8.4. Consultas. Las instrucción SELECT

Para **buscar datos** entre las tablas de una base de datos se usa la sentencia **SELECT**. Estas búsquedas suelen recibir el nombre de **consultas**.

El resultado de una búsqueda de datos tiene forma de tabla y está constituido por el conjunto de datos que cumplen unos **criterios de búsqueda**, porque, para buscar datos con SQL, no hace falta indicarle a la base de datos cómo hacer la búsqueda, sino *qué datos tiene que buscar*. Y ella se encarga de todo.

Sí, es increíble, pero funciona.

La sentencia SELECT es, probablemente, la más compleja del lenguaje SQL. Sin embargo, no necesitas conocerla en profundidad para sacarle partido. La mayor parte del tiempo, SELECT se usa en alguna de sus formas más simples. Si más adelante te vuelves un experto/a en bases de datos, ya aprenderás los usos más complejos.

Para comprender mejor los siguientes ejemplos, vamos a suponer que nuestra tabla *personas* contiene estos siete registros (que quede claro que, en un caso real, la tabla podría tener cientos o miles de registros):

id|nombre|apellido1|apellido2|estatura|fecha_nacimiento|pais_nacimiento
-|-|-|-|-|-|-
1|Antonia|López|Zapata|171|18/02/2002|España
2|Micaela|Cruz|Ortega|168|23/03/1993|México
3|Luis Fernando|Guzmán|Rojas|174|01/01/2001|Colombia
4|Juan|López|Gutiérrez|191|28/02/1997|Argentina
5|Esteban|López|López|166|07/09/2001|México
6|Ana Lucía|Smith|López|185|19/01/2000|Argentina
7|Fernando José|Delgado|Aguas|157|17/08/1969|México

### 8.4.1. Seleccionar columnas de una tabla

La sintaxis más básica concebible de una sentencia SELECT funcional es esta:

```sql
SELECT columna1, columna2, ..., columnaN
  FROM nombre_tabla;
```
Por ejemplo, esta instrucción nos devolverá todos los registros de la tabla *personas*, pero seleccionando solo las columnas *nombre*, *apellido1* y *apellido2* y desechando todas las demás:

```sql
SELECT nombre, apellido1, apellido2
  FROM personas;
```

El resultado de la consulta será:

```
Antonia López Zapata
Micaela Cruz Ortega
Luis Fernando Guzmán Rojas
Juan López Gutiérrez
Esteban López López
Ana Lucía Smith López
Fernando José Delgado Aguas
```

El símbolo * (asterisco) significa "todas las columnas". De modo que esto nos devolverá todo el contenido de la tabla *personas* sin excepción:

```sql
SELECT *
  FROM personas;
```

El resultado de esta consulta será:

```
1 Antonia López Zapata 171 18/02/2002 España
2 Micaela Cruz Ortega 168 23/03/1993 México
3 Luis Fernando Guzmán Rojas 174 01/01/2001 Colombia
4 Juan López Gutiérrez 191 28/02/1997 Argentina
5 Esteban López López 166 07/09/2001 México
6 Ana Lucía Smith López 185 19/01/2000 Argentina
7 Fernando José Delgado Aguas 157 17/08/1969 México
```

### 8.4.2. Filtrar resultados: la cláusula WHERE

Normalmente, no vamos a necesitar *todos* los registros de una tabla, sino que queremos localizar alguno o algunos en concreto. Para eso sirven las búsquedas, ¿no? Para encontrar unos pocos resultados entre un montón de datos.

Pues bien, para **filtrar esos resultados** se utiliza la **cláusula WHERE**.

Es sencilla de comprender. Simplemente, se indica una **condición** que afecte a alguno de los campos de la tabla, y la base de datos se encargará de encontrar para nosotros los registros que cumplan esa condición.

Por ejemplo, esta consulta nos devuelve los nombres y apellidos de todas las personas cuya estatura es igual a 168 cm (recuerda que *estatura* es un campo de nuestra tabla *personas*):

```sql
SELECT nombre, apellido1, apellido2
  FROM personas
  WHERE estatura = '168';
```

Como resultado, solo obtendremos un registro, porque solo una persona cumple esa condición:

```
Micaela Cruz Ortega
```

La condición puede utilizar los **operadores de comparación** habituales:

* **Igual que**: =
* **Mayor que**: >
* **Mayor o igual**: >=
* **Menor que**: <
* **Menor o igual**: <=
* **Distinto de**: !=

Además, también existen **operadores lógicos** que ya conoces de otros lenguajes de programación: **AND**, **OR** y **NOT**.

Con todo esto, se pueden hacer consultas bastante elaboradas con muy poco esfuerzo. Por ejemplo, vamos a pedirle a la base de datos que busque a todas las personas que miden más de 170 cm:

```sql
SELECT nombre, apellido1, apellido2
  FROM personas
  WHERE estatura > '170';
```

El resultado será:

```
Antonia López Zapata
Luis Fernando Guzmán Rojas
Juan López Gutiérrez
Ana Lucía Smith López
```

Esta otra consulta localiza a todas las personas cuyo primer apellido es "López" y que miden más de 170 cm:

```sql
SELECT nombre, apellido1, apellido2
  FROM personas
  WHERE apellido1 = 'López'
    AND estatura > '170';
```

Resultado:

```
Antonia López Zapata
Juan López Gutiérrez
```

Y esta otra busca a todas las personas que tienen "López" como primer o segundo apellido y que han nacido antes del año 2002. Observa cómo se pueden usar paréntesis para agrupar condiciones:

```sql
SELECT nombre, apellido1, apellido2
  FROM personas
  WHERE (apellido1 = 'López' OR apellido2 = 'López')
    AND fecha_nacimiento < '01/01/2002';
```

Resultado: 

```
Juan López Gutiérrez
Esteban López López
Ana Lucía Smith López
```

### 8.4.3. Búsquedas aproximadas con caracteres comodín

Las comparaciones en la cláusula WHERE permiten usar lo que se llaman **caracteres comodín**, que son básicamente dos: % (símbolo del tanto por ciento) y _ (símbolo del subrayado).

* **%** significa "cualquier conjunto de caracteres, incluyendo ningún carácter".
* **_** significa "un carácter cualquiera". En algunos gestores de bases de datos, este carácter es "?" (interrogación)

Las comparaciones que usan carácteres comodín deben escribirse con el operador de comparación **LIKE**, no con los operadores habituales.

Por ejemplo, esta consulta localiza personas cuyo nombre comienza por la letra A, sin importar cuántos caracteres contenga el nombre a continuación de esa A:

```sql
SELECT nombre, apellido1, apellido2
  FROM personas
  WHERE nombre LIKE 'A%';
```

Resultado:

```
Antonia López Zapata
Ana Lucía Smith López
```

Esta otra consulta busca a personas que hayan en el mes de enero de cualquier año:

```sql
SELECT nombre, apellido1, apellido2
  FROM personas
  WHERE fecha_nacimiento LIKE '__/01/____';
```

Resultado: 

```
Luis Fernando Guzmán Rojas
Ana Lucía Smith López
```

### 8.4.4. Ordenar resultados con ORDER BY

Los resultados obtenidos en una consulta pueden **ordenarse** por cualquier campo con la **cláusula ORDER BY**, independientemente de cuales sean las condiciones de búsqueda.

Por ejemplo, para obtener una lista de personas ordenadas por apellido:

```sql
SELECT nombre, apellido1, apellido2
  FROM personas
  ORDER BY apellido1;
```

Resultado:

```
Micaela Cruz Ortega
Fernando José Delgado Aguas
Luis Fernando Guzmán Rojas
Antonia López Zapata
Juan López Gutiérrez
Esteban López López
Ana Lucía Smith López
```

Fíjate que Antonia López, Juan López y Esteban López comparten el primer apellido y, por ese motivo, siguen apareciendo desordenados. O, mejor dicho, aparecen en el orden en el que están almacenados en la tabla, que no tiene por qué ser alfabético.

Se puede indicar un segundo criterio de ordenación (y un tercero, y un cuarto...). Nosotros vamos a usar como segundo criterio el segundo apellido, así:

```sql
SELECT nombre, apellido1, apellido2
  FROM personas
  ORDER BY apellido1, apellido2;
```

Resultado:

```
Micaela Cruz Ortega
Fernando José Delgado Aguas
Luis Fernando Guzmán Rojas
Esteban López López
Juan López Gutiérrez
Antonia López Zapata
Ana Lucía Smith López
```

El ordenamiento se hace, por defecto, de manera **ascendente** (numérica en caso de campos numéricos o alfabética en caso de campos de texto). Se puede forzar un ordenamiento **descendente** con el modificador **DESC**.

Por ejemplo, aquí obtenemos la lista de las personas apellidadas "López" ordenadas de la más alta a la más bajita:

```sql
SELECT nombre, apellido1, apellido2, estatura
  FROM personas
  WHERE apellido1 = "López"
  ORDER BY estatura DESC;
```

Resultado:

```
Juan López Gutiérrez 191
Antonia López Zapata 171
Esteban López López 166
```

### 8.4.5. Agrupar resultados con DISTINCT

Atención, pregunta. ¿Qué ocurrirá si ejecutamos esta consulta?

```sql
SELECT apellido1
  FROM personas
  ORDER BY apellido1;
```

Si has respondido que obtendremos todos los primeros apellidos de todas las personas de la tabla *personas*, ordenados alfabéticamente, has acertado.

*Pero hay varias personas que comparten el primer apellido.*

Por esa razón, ese apellido aparece ("López") repetido varias veces en el resultado:

```
Cruz
Delgado
Guzmán
López
López
López
Smith
```

Esta repetición de resultados puede ser algo buscado o un efecto secundario indeseable de la búsqueda. Para **evitar resultados repetidos** se usa **DISTINCT**. Por ejemplo, el siguiente SELECT nos mostrará todos los primeros apellidos de la tabla, pero sin repetir ninguno:

```sql
SELECT DISTINCT apellido1
  FROM personas
  ORDER BY apellido1;
```

```
Cruz
Delgado
Guzmán
López
Smith
```

### 8.4.6. Funciones de agregado y GROUP BY

En la lista de campos, se pueden utilizar las llamadas **funciones de agregado**. Se trata de funciones que realizan cálculos sobre los resultados de la consulta.

Por ejemplo, esta consulta (que no usa funciones de agregado) nos devuelve los IDs de las personas cuyo país de nacimiento es "México":

```sql
SELECT id
  FROM personas
  WHERE pais_nacimiento = "México";
```

Resultado:

```
Micaela Cruz Ortega
Esteban López López
Fernando José Delgado Aguas
```

En cambio, esta otra consulta (que usa la función de agregado COUNT()) nos devuelve *el número de personas* cuyo país de nacimiento es "México":

```sql
SELECT COUNT(id)
  FROM personas
  WHERE pais_nacimiento = "México";
```

Resultado:

```
3
```

Las **funciones de agregado más importantes** son las siguientes:

* **COUNT()**: cuenta el número de filas que cumplen los criterios de búsqueda de la consulta.
* **MIN()**: calcula el valor mínimo de un campo numérico.
* **MAX()**: calcula el valor máximo de un campo numérico.
* **AVG()**: calcula el valor promedio de un campo numérico.
* **SUM()**: calcula la suma de todos los valores de un campo numérico.

Con estas funciones, es muy fácil buscar, por ejemplo, la estatura máxima de todas las personas cuyo primer apellido es "López":

```sql
SELECT MAX(estatura)
  FROM personas
  WHERE apellido1 = "López";
```

Resultado:

```
191
```

Las funciones de agregado se usan a menudo con la **clásula GROUP BY**, que nos permite **agrupar los resultados por algún campo**. Observa cómo funciona en este ejemplo:

```sql
SELECT pais_nacimiento, COUNT(id)
  FROM personas;
  GROUP BY pais_nacimiento
  ORDER BY pais_nacimiento;
```

Esta consulta nos dirá cuántas personas han nacido en cada país, ofreciéndonos un resultado con un aspecto como este:

```
Argentina 2
Colombia 1
España 1
México 3
```

Lo que ha ocurrido aquí es que los resultados se han agrupado por paises (**GROUP BY pais_nacimiento**) y, para cada grupo, se ha hecho el cálculo de la función de agregado (**COUNT(id)**).

La cláusula GROUP BY aparece, a veces, acompañada de la **cláusula HAVING**, que es **como WHERE pero aplicable a funciones de agregado**.

Por ejemplo, esta consulta nos mostrará la cantidad de personas nacidas en cada país pero solo de aquellos países de los que se contabilicen al menos 3 personas en la tabla:

```sql
SELECT pais_nacimiento, COUNT(id)
  FROM personas;
  ORDER BY pais_nacimiento
  GROUP BY pais_nacimiento
    HAVING COUNT(id) >= 3 ;
```

Resultado:

```
México 3
```

### 8.4.7. Obtener resultados de varias tablas: JOIN

Hasta ahora, solo hemos visto ejemplos de consultas que obtienen datos de una sola tabla, pero es muy frecuente que queramos **extraer datos de varias tablas relacionadas entre sí**.

SQL permite hacer eso con la cláusula **JOIN**.

Para comprender cómo funciona JOIN, necesitamos añadir una o dos tablas a nuestra base de datos, así que los siguientes ejemplos se basarán en estas tres tablas:

```
PERSONAS(id, nombre, apellido1, apellido2, estatura, fecha_nacimiento, id_pais)
PAISES(id, nombre, id_continente)
CONTINENTES(id, nombre)
```

Como puedes imaginarte, el campo *id_pais* de la tabla *PERSONAS* es una clave ajena que está relacionada con el campo *id* de la tabla *PAISES*.

Del mismo modo, *id_continente* en la tabla *PAISES* es una clave ajena enlazada con *id* en la tabla CONTINENTES.

Para que quede más claro, te muestro un ejemplo de lo que podrían contener estas tablas:

**TABLA PERSONAS**

id|nombre|apellido1|apellido2|estatura|fecha_nacimiento|id_pais
-|-|-|-|-|-|-
1|Antonia|López|Zapata|171|18/02/2002|3
2|Micaela|Cruz|Ortega|168|23/03/1993|1
3|Luis Fernando|Guzmán|Rojas|174|01/01/2001|2
4|Juan|López|Gutiérrez|191|28/02/1997|7
5|Esteban|López|López|166|07/09/2001|1
6|Ana Lucía|Smith|López|185|19/01/2000|7
7|Fernando José|Delgado|Aguas|157|17/08/1969|1
etc|etc|etc|etc|etc|etc|etc

**TABLA PAISES**

id|nombre|id_continente
-|-|-
1|México|2
2|Colombia|2
3|España|4
4|Australia|5
5|China|3
6|Egipto|1
7|Argentina|2
etc|etc|etc

**TABLA CONTINENTES**

id|nombre
-|-
1|África
2|América
3|Asia
4|Europa
5|Oceanía

Ahora el nombre del país no está almacenado directamente en la tabla *personas*, sino en la tabla *paises*. Ambas tablas se relacionan gracias al campo *id_pais*. Lo mismo ocurre entre *paises* y *continentes*.

Por lo tanto, si necesitamos recuperar, por ejemplo, **los nombres y apellidos de todas las personas junto con su país de nacimiento**, será necesario mezclar los datos de las tablas *personas* y *paises*. Esto se hace así:

```sql
SELECT personas.nombre, apellido1, apellido2, paises.nombre
  FROM personas
  JOIN paises ON personas.id_pais = paises.id
```

El resultado será:

```
Antonia López Zapata España
Micaela Cruz Ortega México
Luis Fernando Guzmán Rojas Colombia
Juan López Gutiérrez Argentina
Esteban López López México
Ana Lucía Smith López Argentina
Fernando José Delgado Aguas México
```

Observa algunas cosas importantes en esta sentencia:

* En la **clásula FROM** indicamos la tabla principal de nuestra consulta (*personas*).
* En la **clásula JOIN** indicamos la segunda tabla de nuestra consulta (*paises*) y le indicamos a SQL cuál es el campo que relaciona *personas* con *paises* (```personas.id_pais = paises.id```).
* En la lista de campos, tenemos dos campos llamados *nombre*, uno perteneciente a la tabla *personas* (el nombre de la persona) y otro perteneciente a la tabla *paises* (el nombre del país). Por eso es necesario distinguirlos poniendo delante el identificador de la tabla (*personas.nombre* y *paises.nombre*). Con *apellido1* y *apellido2* no hace falta, puesto que esos campos solo existen en la tabla *personas*.

Y poco más hay que decir sobre los JOIN. Son así de sencillos. SQL se encargará de mostrar a cada persona con su país correspondiente, cruzando los datos de las dos tablas.

Se puede hacer **JOIN de más de dos tablas**. En esos casos, basta con cruzar las tablas por parejas. Por ejemplo, para mostrar la lista de personas junto con su país y su continente de nacimiento, primero cruzaremos *personas* con *paises* y después *paises* con *continentes*. No se puede cruzar directamente *personas* con *continentes* porque no tienen ningún campo en común, es decir, no están directamente relacionadas entre sí.

```sql
SELECT personas.nombre, apellido1, apellido2, paises.nombre, continentes.nombre
  FROM personas
  JOIN paises ON personas.id_pais = paises.id
  JOIN continentes ON paises.id_continente = continentes.id
```

El resultado de esta consulta será:

```
Antonia López Zapata España Europa
Micaela Cruz Ortega México América
Luis Fernando Guzmán Rojas Colombia América
Juan López Gutiérrez Argentina América
Esteban López López México América
Ana Lucía Smith López Argentina América
Fernando José Delgado Aguas México América
```

Por último, **las consultas con JOIN también pueden llevar cláusulas WHERE, ORDER BY, GROUP BY o HAVING**, como cualquier otra consulta. Por ejemplo, vamos a buscar los nombres, apellidos, país de nacimiento y continente de todas las personas nacidas a partir de 1 de enero del año 2000 y vamos a ordenar los resultados por apellidos:

```sql
SELECT personas.nombre, apellido1, apellido2, paises.nombre, continentes.nombre
  FROM personas
  JOIN paises ON personas.id_pais = paises.id
  JOIN continentes ON paises.id_continente = continentes.id
  WHERE fecha_nacimiento >= '01/01/2000'
  ORDER BY apellido1, apellido2;
```

El resultado será:

```
Luis Fernando Guzmán Rojas Colombia América
Esteban López López México América
Antonia López Zapata España Europa
Ana Lucía Smith López Argentina América
```

### 8.4.8. SQL avanzado: introducción a las subconsultas

Hay ciertas situaciones en las que nos encontramos con una consulta tan compleja que no se puede resolver con las herramientas que hemos visto hasta ahora.

En esos casos, **utilizar una subconsulta en una cláusula WHERE o HAVING** suele obrar milagros. Sin embargo, no conviene abusar de este recurso: las consultas con subconsultas siempre consumen más recursos y son más lentas de ejecutar que las consultas convencionales.

La subconsulta se inserta en cualquier cláusula WHERE o HAVING con alguno de estos operadores:

* **ANY**, **ALL** o **SOME**.
* **IN** o **NOT IN**.
* **EXISTS** o **NOT EXISTS**.
* **=, >, >=, <, <=**.

El significado de los operadores es bastante obvio. Como siempre, se comprende mejor con algunos ejemplos.

**Ejemplo 1: buscar a todas las personas que hayan nacido en algún país del continente americano:**

```sql
SELECT nombre, apellido1, apellido2
  FROM personas
  WHERE personas.id_pais IN (SELECT id_pais FROM paises
                              WHERE id_continente = 2);
```

Observa bien el código de esta consulta: le estamos pidiendo a la base de datos que, en primer lugar, ejecute la consulta que hay entre paréntesis (es decir, la *subconsulta*). Esta consulta nos devolverá una lista de IDs de paises del contienente americano. Y luego, gracias a la clásula WHERE de la consulta principal, seleccionaremos solo a las personas que hayan nacido en alguno de esos países.

(Esta consulta, por cierto, puede resolverse sin subconsultas de forma más eficiente. Puedes pensar en ello si lo deseas: es un interesante ejercicio).

**Ejemplo 2: buscar todos los países de los cuales hay al menos una persona en la base de datos:**

También puede hacerse sin subconsultas, pero la solución con subconsulta es así de simple:

```sql
SELECT nombre
  FROM paises
  WHERE id = ANY (SELECT id_pais FROM personas);
```

**Ejemplo 3: buscar a las personas más altas de la base de datos**:

Es decir, buscar a las personas que compartan el valor máximo de estatura, sea este el que sea. Este es un ejemplo de consulta que difícilmente podrías resolver sin subconsultas, pero que con subconsultas queda en algo tan simple como:

```sql
SELECT nombre, apellido1, apellido2
  FROM personas
  WHERE estatura = (SELECT MAX(estatura) FROM personas);
```

Las subconsultas se pueden considerar SQL avanzado, por lo que no es necesario que las domines en este momento, pero sí que conozcas su existencia por si más adelante en tu carrera como programador/a tienes que profundizar en ellas.

### 8.4.9. Otras cuestiones avanzadas: alias y combinaciones de consultas

Como dijimos al principio, SQL en general y la instrucción SELECT en particular son muy amplios y se pueden aplicar en muchísimos casos diferentes, desde consultas sencillísimas hasta casos complejos donde tu cerebro puede tener un amago de explosión mientras trata de buscar una solución.

Te menciono aquí **algunos aspectos avanzados de los SELECT** para que los conozcas, haciéndote saber que, si no aprendes a controlarlos ahora, no es ninguna tragedia: más adelante, si te especializas en esto, sin duda aprenderás a dominarlos.

Por ahora basta con que los conozcas y los comprendas. En algunos de los ejercicios del tema usaremos estos aspectos avanzados para buscar soluciones a supuestos prácticos particularmente enrevesados.

**ALIAS**

Los alias son **nombres alternativos que se asignan a las tablas o a las columnas** en una consulta.

El objetivo del alias puede ser doble:

* Usar un nombre más corto para facilitar la escritura de una expresión que, de otro modo, sería muy larga.
* Poder referirse a la misma tabla en dos conextos diferentes.

El primer uso es muy fácil de entender. El segundo, no tanto. De momento, vamos a ver el uso más fácil. No te preocupes demasiado por el otro: veremos algún ejemplo en los ejercicios de este capítulo.

El **alias se indica con la palabra AS**.

Por ejemplo, en la siguiente consulta, se usan alias para acortar los identificadores de los campos *persona.nombre*, *paises.nombre* y *continentes.nombre*, que pasan a ser *nom_pers*, *nom_pais* y *nom_cont*, respectivamente. Observa como podemos referirnos a cualquiera de esos campos por su nombre o su alias, como hacemos en la cláusula WHERE de este ejemplo.

```sql
SELECT personas.nombre AS nom_pers, apellido1, apellido2, paises.nombre AS nom_pais, continentes.nombre AS nom_cont
  FROM personas
  JOIN paises ON personas.id_pais = paises.id
  JOIN continentes ON paises.id_continente = continentes.id
  WHERE nom_pers LIKE 'A%'
  ORDER BY apellido1, apellido2;
```

**COMBINACIONES DE CONSULTAS**

Es posible **combinar los resultados de dos consultas** para obtener un resultado más amplio.

Si tenemos dos consultas, que llamaremos C1 y C2, sus resultados pueden combinarse de tres modos diferentes:

* Con **UNION**: los registros de C1 y de C2 se sumarán, es decir, el resultado de **C1 UNION C2** serán todas las filas que estén en C1 más las que estén en C2.
* Con **INSERSECT**: el resultado de **C1 INSERSECT C2** serán todas las filas que están a la vez en C1 y en C2, es decir, la insersección de los dos conjuntos de resultados.
* Con **EXCEPT**: el resultado de **C1 EXCEPT C2** serán todas las filas que estén en C1, quitando las que estén en C2.

Para poder hacer UNION, INSERSECT o EXCEPT de dos consultas, ambas tienen que haber producido exactamente el mismo conjunto de campos. Si no, estas operaciones no son posibles.

Por ejemplo, observa el siguiente código. Fíjate en que las dos consultas producen el mismo conjunto de campos (*nombre, apellido1, apellido2*). Si no, no sería posible combinarlas. Observa también el uso de los paréntesis:

```sql
(SELECT nombre, apellido1, apellido2
  FROM personas
  WHERE pais_nacimiento = '1')
UNION
(SELECT nombre, apellido1, apellido2
   FROM personas)
   WHERE estatura > '180');
```

(por supuesto, esto mismo puede resolverse sin usar UNION)

* La combinación de estas dos consultas con **UNION** nos devuelve la lista de personas que han nacido en Argentina **O** que miden más de 180 cm. Cualquier persona que cumpla una de las dos condiciones estará en el resultado final.

* Si combinásemos las mismas consultas con **INSERSECT** en lugar de con UNION, lo que obtendríamos sería la lista de personas que nacieron en Argentina **Y** que miden más de 180 cm. Es decir, las personas que formen parte de los dos resultados y, por lo tanto, cumplan *a la vez* las dos condiciones.

   Fíjate en que en el enunciado solo hemos cambiado una "O" por una "Y", pero es que esa es precisamente la diferencia entre UNION e INTERSECT.

* Por último, si combinamos las mismas consultas con **EXCEPT**, obtendremos la lista de personas que nacieron en Argentina, excepto las que miden más de 180 cm. Habremos eliminado del primer SELECT los resultados que estén en el segundo SELECT. Esto es, obtendremos la lista de personas nacidas en argentina que miden 180 cm o menos.

Es un lío desde el punto de vista lógico, ¿verdad? Y es que no se te habrán escapado las semejanzas de UNION, INTERSECT y EXCEPT con los operadores lógicos Y, O y NO. En efecto, UNION, INSERSECT y EXCEPT son los equivalentes a Y, O y NO a nivel de consultas completas.

Aplicaremos UNION, INSERSECT y EXCEPT a algunas de las consultas más complejas de nuestros ejercicios propuestos.

## 8.5. ¿Y cómo puedo probar todo esto?

Seguro que te has hecho esta pregunta mientras leías los ejemplos de este capítulo y tal vez incluso intentabas resolverlos por tu cuenta.

Es una excelente pregunta.

Para ejecutar SQL **necesitas un gestor de bases de datos relacionales**. Puede instalar un gestor de escritorio, para bases de datos domésticas, como *Microsoft Access* o *Libreoffice Base*, o puedes decantarte por un gestor profesional en red, como *MySQL, MariaDB, Oracle, SQLite* o *SQL Server*.

En realidad, da igual, porque el SQL es más o menos igual en todos.

(Digo "más o menos" porque cada base de datos hace su propia interpretación del estándar SQL y puede haber pequeñas diferencias entre uno y otro).

Si nunca has usado una base de datos profesional como MySQL, Oracle u SQL Server, probablemente **lo más sencillo es que empieces por Microsoft Access o Libreoffice Base**. Si, en cambio, ya conoces las bases de datos profesionales, no necesitas leer este apartado. Puedes pasar directamente a los ejercicios, aunque probablemente tampoco los necesites.

1. **Instala Microsoft Access (forma parte del paquete Microsoft Office) o Libreoffice Base (forma parte del paquete Libreoffice)** en tu ordenador. Microsoft ofrece una versión online de su Office. Recuerda que Microsoft Office es un paquete de software propietario y que copiar y usar programas de forma fraudulenta es un delito penal. Libreoffice, en cambio, es software libre y puedes usarlo y distribuirlo libremente. Eso sí: ¡Descárgalo solo de la web oficial, por favor! 

2. **Arranca el programa** (claro).

3. **En Microsoft Access**, crea una base de datos (o abre una existente). Ahora puedes ejecutar tus sentencias SQL pulsando el botón "Create" de la parte superior de la pantalla, y luego seleccionando "Query design" -> "Show table" -> "SQL view". Escribe tu sentencia SQL y pulsa "Run" para probarla.

4. **En Libreoffice Base**, crea una base de datos (o abre una existente). Selecciona "Tool - SQL" y luego "Create Query in SQL view". En la pantalla siguiente, haz clic en "View" -> "Switch Design View On/Off". Escribe tu sentencia SQL y pulsa "Run" para probarla.

En realidad, todo esto no tiene nada que ver con aprender SQL, sino con aprender a manejar un determinado programa. Elige el tuyo y bichea un poco hasta que averigües cómo se ejecuta el SQL. Se presupone de ti que eres un usuario/a de ordenadores de nivel medio-avanzado, y por eso quieres aprender a programar. No tiene mucho sentido explicar aquí cómo ejecutar SQL en cada gestor de bases de datos porque puede haber importantes diferencias entre un gestor de bases de datos y otro o, incluso, entre versiones del mismo programa. Y, en última instancia, es algo tan simple como trastear un rato con el programa.

## 8.6. Ejercicios propuestos

Como de costumbre, vamos a proponer una batería de ejercicios de SQL para que practiques todo lo que hemos visto a lo largo de este capítulo.

Muchos de ellos los encontrarás resueltos en la siguiente sección. Ya sabes lo que digo siempre: es una pésima idea mirar las soluciones antes de haber intentado resolverlos por tu cuenta.

#### Ejercicio 1: compañía de seguros

Una compañía de seguros dispone de una base de datos con las siguientes tablas:

* Personas (dni#, nombre, apellidos, dirección, ciudad, país)
* Coches (matrícula#, marca, modelo, potencia, conductor, seguro)
* Seguros (núm-póliza#, compañía, tipo, franquicia, dni-tomador, fecha)

Las claves ajenas son estas:

* Coches.conductor → Personas.dni (es decir, el campo *coches.conductor* es una clave ajena de *personas.dni*)
* Coches.seguro → Seguros.núm-póliza (el campo *coches.seguro* es una clave ajena de *seguros.num-numpoliza*)
* Seguros.dni-tomador → Personas.dni (el campo *seguros.dni-tomador* es una clave ajena de *personas.dni*)

Se pide escribir el código SQL necesario para:

**a) Crear las tablas** (CREATE TABLE), suponiendo las siguientes restricciones:

* Todas las claves primarias y ajenas son campos obligatorios (no pueden ser nulos). Además, las claves primarias no pueden tomar valores repetidos.
* *Personas.país* tendrá, por defecto, el valor "España". Personas.ciudad tendrá, por defecto, el valor "Almería".
* Hay que activar el borrado y actualización en cascada en todas las relaciones.
* Es conveniente definir todas las claves como restricciones (*constraints*), con el objeto de poder modificarlas más adelante.
* Todos los datos son cadenas de caracteres (la longitud puedes elegirla tú, siempre que sea razonable), excepto los siguientes:
   * *Coches.potencia* es un número real con tres cifras enteras y dos cifras decimales.
   * *Seguros.núm-póliza* es un número entero largo.
   * *Seguros.franquicia* es un número real con seis cifras enteras y dos decimales.
   * *Seguros.fecha* es de tipo fecha (claro)

**b) Realizar los siguientes cambios en las tablas** (ALTER TABLE, INSERT, UPDATE, DELETE):

1. Agregar a la tabla Personas el campo *sexo*, con un sólo carácter y obligatorio.
2. Desactivar el borrado en cascada (no la actualización) de la clave ajena en la tabla Seguros.
3. Insertar estos registros:
   * En *Personas*, DNI = 1111A, Juan Martín, C/ Barco, Roquetas de Mar, España
   * En *Seguros*, Nº Póliza = 1, Compañía = Mapfre, Franquicia = 299,95 €, Tomador = Juan Martín
4. Modificar todos los seguros de tipo "Todo riesgo" para que la franquicia sea de 120 €
5. Borrar todas las personas que no vivan ni en España ni en Portugal.

**c) Realizar las siguientes consultas** (SELECT):

1. Nombre y apellidos, ordenados alfabéticamente, de todas las personas que viven en ciudades que empiezan por "A".
2. Compañías de seguros que aseguran coches de la marca Seat y cuyas pólizas fueron contratadas después del año 2005.
3. Precio medio de las franquicias de los coches asegurados por la compañía Mapfre y cuya potencia es mayor de 100 caballos.
4. Nombre, apellidos, marca, modelo y compañía aseguradora de los vehículos cuyos dueños tienen varios coches y están asegurados en compañías diferentes.

#### Ejercicio 2: Biblioteca

Una base de datos de una biblioteca que lleva algún tiempo funcionando contiene, entre otras tablas, estas dos:

* Libros (cód-libro#, título, editorial, cód-autor)
* Autores (cód-autor#, nombre, apellidos, país, fecha-nacimiento)

Por un error de implementación, el campo *libros.cód-autor* no se hizo clave ajena durante la creación de la tabla. Ahora se ha intentado crear la clave ajena con un ALTER TABLE, pero la base de datos impide la ejecución de la instrucción, alegando que se produce una violación de la integridad referencial.

1. ¿A qué puede deberse que la base de datos esté dándonos ese error?
2. ¿Cómo puede solucionarse? Escribe el código SQL que estimes necesario para intentar arreglar el problema.

#### Ejercicio 3: academia de idiomas

La base de datos de una academia de idiomas está formada por las siguientes tablas:

* PROFESORES(#dni-prof, nombre, apellidos, idioma)
* ALUMNOS(#dni-alum, nombre, apellidos)
* GRUPOS(#cod-grupo, denominación)
* HORARIOS(#cod-grupo, #día-semana, #dni-prof, hora-inicio, hora-fin, aula)

Se pide escribir las sentencias SQL necesarias para:

1. Crear la tabla HORARIOS. Las claves y las horas son campos obligatorios. El aula es un número entero, y, aunque no es obligatorio, tomará por defecto el valor 1.
2. Modificar la tabla ALUMNOS para agregar el campo "cod-grupo", que es una clave ajena.
3. Insertar el registro ["12345678-Z", "Juan", "López López", "Italiano"] en la tabla PROFESORES.
4. Consultar los nombres y apellidos de los profesores que dan clase de francés de lunes a jueves a partir de las 16:00 horas, junto con la denominación de los grupos a los que dan clase y el horario de cada día.
5. Consultar los nombres y apellidos de los alumnos que reciben clases de al menos dos idiomas diferentes.
6. Consultar los nombres y apellidos de los alumnos que reciben clases de INGLÉS y de FRANCÉS.
7. Consultar los nombres y apellidos de los alumnos que reciben clases de INGLÉS o de FRANCÉS.
8. Consultar los nombres y apellidos de los alumnos que reciben clases de INGLÉS pero no reciben clases de ALEMÁN.

#### Ejercicio 4: concesionario de automóviles

Una empresa de venta de coches nuevos y usados tiene en su base de datos estas tablas:

* COCHES(cod_coche#, marca, modelo, color, precio, tipo) – tipo puede ser "nuevo", "km. 0" o "usado"
* COCHES_USADOS(cod_coche#, año, kilometraje, descuento, cod_desperfecto)
* DESPERFECTOS(cod_desperfecto#, descripción, observaciones)
* TIENDAS(cod_tienda#, ciudad, provincia, dirección, teléfono)
* COCHES-ESTÁN-EN-TIENDAS (cod_coche#, cod_tienda#, cantidad)
* CLIENTES (cod_cliente#, nombre, apellidos, domicilio, ciudad, provincia)
* VENTAS(cod_coche#, cod_tienda#, cod_cliente#, fecha)

A partir de esas tablas, se pide:

1. Crear la tabla COCHES, de forma coherente a cómo la hayas diseñado en el primer apartado. Utiliza tipos de datos SQL adecuados a la información que se guardará en cada campo. El campo cod_coche es obligatorio, y el campo precio tiene 10000,00 como valor por defecto.
2. Se ha detectado que algunos clientes tienen una "provincia" con valor nulo, pero, en cambio, sí que tienen un valor asignado al campo "ciudad". Escribe la(s) intrucción(es) SQL necesarias para arreglar este problema de la mejor manera que se te ocurra.
3. Obtener el NIF de los clientes y los códigos de tienda que no sean de la misma ciudad.
4. Obtener la matrícula, la marca y el modelo de los coches vendidos en tiendas de la provincia de Madrid que no hayan sido vendidos en ninguna otra provincia.
5. Obtener el código, ciudad y dirección de las tiendas que tengan entre 5 y 10 vehículos usados que sean de marca "Renault" y modelo "Megane".
6. Obtener el código, marca y modelo del coche, así como el nombre y apellidos del cliente, de todos los vehículos vendidos a un cliente de Almería por un concesionario de Almería.
7. Obtener el nombre y apellidos de clientes que hayan adquirido un coche en algún concesionario que posea actualmente en stock el vehículo marca "Seat", modelo "León".
8. Obtener los nombres y apellidos de clientes que no han comprado ningún coche de color rojo a ningún concesionario de Andalucía.

#### Ejercicio 5

Las siguientes tablas contienen información sobre la liga de fútbol (equipos, jugadores, árbitros y partidos):

* FUTBOLISTAS (cod-futbolista#, nombre, apellidos, fecha-nac, peso, estatura)
* PARTIDOS (cod-partido#, jornada, fecha, resultado)
* PARTICIPAN (cod-futbolista#, cod-partido#, minutos, goles, tarjetas) - Relación entre FUTBOLISTAS y PARTIDOS
* EQUIPOS (nombre-eq#, año_fundación, presidente, num_socios, estadio)
* JUEGAN (nombre-eq-casa#, nombre_eq_visitante#, cod_partido#) - Relación entre EQUIPOS y PARTIDOS
* CONTRATOS (num-contrato#, cod-futbolista, nombre-eq, fecha-contrato, duración, ficha, claúsulas)
* ÁRBITROS (num-colegiado#, colegio, nombre, apellidos, num-temporadas)
* ARBITRAN (cod-partido#, num-colegiado#, función) - Relación entre ÁRBITROS y PARTIDOS ("función" puede ser "principal", "juez de línea" o "cuarto")

Realiza estas consultas en lenguaje SQL:

1. El número de goles marcados por el jugador Pantuflo Zapatilla en los partidos del mes de febrero de 2007.
2. El nombre de los equipos contra los que ha jugado el Almería en partidos arbitrados por Esquinas Torres, así como el resultado y la jornada de esos partidos.
3. Todos los datos de la plantilla de futbolistas del Real Madrid.
4. Buscar el nombre y la estatura del futbolista más alto del FC Barcelona.

## 8.7. Ejercicios resueltos

Vamos a resolver los ejercicios propuestos en el apartado anterior. Recuerda que es importante que, antes de mirar las soluciones, trates de resolverlos por tu cuenta.

#### Ejercicio 1: compañía de seguros

**a) Crear las tablas con las restricciones detalladas en el enunciado del ejercicio:**

```sql
CREATE TABLE Personas (
	dni		VARCHAR(12)	UNIQUE NOT NULL,
	nombre	VARCHAR(50)	NOT NULL,
	apellidos	VARCHAR(50)	NOT NULL,
	ciudad	VARCHAR(50)	DEFAULT "Almería",
	país		VARCHAR(50)	DEFAULT "España",
	CONSTRAINT pk_personas
		PRIMARY KEY (dni)
);

CREATE TABLE Seguros (
	num_póliza	BIGINT	UNIQUE NOT NULL,
	compañía	VARCHAR(50)	NOT NULL,
	tipo		VARCHAR(20),
	franquicia	DECIMAL(8,2)	DEFAULT 0,
	dni_tomador	VARCHAR(12)	NOT NULL,
	fecha		DATE,
	CONSTRAINT pk_seguros
		PRIMARY KEY (num_póliza),
	CONSTRAINT fk_seguros_personas
		FOREIGN KEY (dni_tomador) REFERENCES Personas(dni)
		ON DELETE CASCADE
		ON UPDATE CASCADE
);

CREATE TABLE Coches (
	matrícula	VARCHAR(7)	UNIQUE NOT NULL,
	marca	VARCHAR(30)	NOT NULL,
	modelo	VARCHAR(30),
	potencia	DECIMAL(5,2),
	conductor	VARCHAR(12)	NOT NULL,
	seguro	BIGINT	NOT NULL,
	CONSTRAINT pk_coches
		PRIMARY KEY (matricula),
	CONSTRAINT fk_coches_personas
		FOREIGN KEY (conductor) REFERENCES Personas(dni)
		ON DELETE CASCADE
		ON UPDATE CASCADE,
	CONSTRAINT fk_coches_seguros
		FOREIGN KEY (seguro) REFERENCES Seguros(num_póliza)
		ON DELETE CASCADE
		ON UPDATE CASCADE
);
```

**b) Realizar los siguientes cambios en las tablas**

**Agregar a la tabla Personas el campo sexo, con un sólo carácter y obligatorio.**

```sql
ALTER TABLE Personas
	ADD Sexo VARCHAR(1) NOT NULL;
```

**Desactivar el borrado en cascada (no la actualización) de la clave ajena en la tabla Seguros.**

(No puede eliminarse solamente el borrado en cascada, así que hay que quitar por completo la restricción "fk_seguros_personas", y luego volver a crearla sin borrado en cascada. Observa que esto no afectará a los datos de la tabla.)

```sql
ALTER TABLE Seguros
	DROP CONSTRAINT fk_seguros_personas;

ALTER TABLE Seguros
	ADD CONSTRAINT fk_seguros_personas
		FOREIGN KEY (dni_tomador) REFERENCES Personas(dni)
		ON UPDATE CASCADE;
```

**Insertar estos registros:**
   * En Personas, DNI = 1111A, Juan Martín, C/ Barco, Roquetas de Mar, España
   * En Seguros, Nº Póliza = 1, Compañía = Mapfre, Franquicia = 299,95 €, Tomador = Juan Martín

```sql
INSERT INTO Personas VALUES ('1111A', 'Juan', 'Martín', 'C/ Barco', 'Roquetas de Mar', 'España');

INSERT INTO Seguros (num_póliza, compañía, franquicia, dni_tomador)
	VALUES (1, 'Mapfre', 299.95, '1111A');
```

**Modificar todos los seguros de tipo "Todo riesgo" para que la franquicia sea de 120 €**

```sql
UPDATE Pacientes
	SET pais = 'Desconocido'
	WHERE tipo = 'Todo riesgo';
```

**Borrar todas las personas que no vivan ni en España ni en Portugal.**

```sql
DELETE FROM Personas
	WHERE país <> 'España' AND país <> 'Portugal';
```

**c) Realizar las siguientes consultas** (SELECT):

**Nombre y apellidos, ordenados alfabéticamente, de todas las personas que viven en ciudades que empiezan por "A" (consideraremos también la "A" con tilde):**

```sql
SELECT nombre, apellidos
	FROM Personas
	WHERE ciudad LIKE 'A*'  OR  ciudad LIKE 'Á*'
	ORDER BY apellidos, nombre;
```

**Compañías de seguros que aseguran coches de la marca Seat y cuyas pólizas fueron contratadas después del año 2005.**

```sql
SELECT DISTINCT compañía
	FROM Seguros, Coches
	WHERE Seguros.num_póliza = Coches.seguro
	    AND marca = 'Seat'
	    AND fecha > '31/12/2005';
```

**Precio medio de las franquicias de los coches asegurados por la compañía Mapfre y cuya potencia es mayor de 100 caballos.**

```sql
SELECT AVG(franquicia)
	FROM Seguros, Coches
	WHERE Seguros.num_póliza = Coches.seguro
	    AND compañía = 'Mapfre'
	    AND potencia > 100;
```

**Nombre, apellidos, marca, modelo y compañía aseguradora de los vehículos cuyos dueños tienen varios coches y están asegurados en compañías diferentes.**

Esta consulta no puede resolverse tal y como está, porque no conocemos a los dueños de los vehículos. Esa información, simplemente, no está en la base de datos. Así que supondremos que los dueños y los conductores son los mismos, porque los conductores sí están en la base de datos.

```sql
SELECT nombre, apellidos, marca, modelo, compañía
	FROM Personas AS P1, Coches AS C1, Seguros
	WHERE P1.dni = Seguros.dni_tomador
	     AND Seguros.num_póliza = C1.seguro
	     AND compañía NOT IN (SELECT compañía 
 				FROM Personas AS P2, Coches AS C2, Seguros
				WHERE P2.dni = Seguros.dni_tomador
				     AND Seguros.num_póliza = C2.seguro
				     AND P2.dni = P1.dni
				     AND C2.matrícula <> C1.matrícula);
```

Otra solución posible pasa por conectar la consulta y la subconsulta a través del dni del conductor:

```sql
SELECT nombre, apellidos, marca, modelo, compañía
	FROM Personas AS P1, Coches, Seguros AS S1
	WHERE P1.dni = S1.dni_tomador
	     AND S1.num_póliza = Coches.seguro
	     AND dni IN (SELECT dni 
 			FROM Personas AS P2, Coches, Seguros AS S2
			WHERE P2.dni = S2.dni_tomador
			     AND S2.num_póliza = Coches.seguro
			     AND S1.compañía <> S2.compañía
			     AND P1.dni = P2.dni);
```

#### Ejercicio 2: Biblioteca

**¿A qué puede deberse que la base de datos esté dándonos ese error?**

En la tabla de Libros debe existir al menos un código de autor que no se corresponde con ningún autor de la tabla de Autores. Probablemente se deba a un error en la introducción de los datos. Al convertir a Libros.cód_autor en clave ajena que hace referencia a Autor.cód_autor, la integridad referencial quedaría rota, y por eso el gestor de base de datos nos impide crear esa clave ajena.

**¿Cómo puede solucionarse? Escribe el código SQL que estimes necesario para intentar arreglar el problema.**

Habría que localizar los registros de Libros que tienen asociados autores que no existen en la tabla de Autores. Una vez localizados, tenemos varias opciones: 
a) Borrarlos (una solución un poco bestia)
b) Moverlos a una nueva tabla temporal, para que el administrador de la base de datos haga lo que estime conveniente con esos registros (solución válida porque no destruye datos, pero muy trabajosa)
c) Asignarles un autor "ficticio". Por ejemplo, podemos crear un autor llamado "Desconocido" en la tabla de autores con un código especial (p.ej: el 0), y asignar esos libros al nuevo autor. Esta será la solución que adoptaremos.

```sql
INSERT INTO Autores (cód_autor, nombre) VALUES (0, 'Desconocido');

UPDATE Libros SET cód_autor = 0
	WHERE cód_autor NOT IN (SELECT cód_autor FROM Autores);
```

Ahora sí podemos crear la clave ajena de Autores sin provocar una violación de la integridad referencial. Además, deberíamos repasar los datos de la tabla de Autores para asignar autores válidos a los libros marcados con el código de autor 0 (esto hay que hacerlo manualmente: la base de datos no puede saber qué códigos son los correctos)

#### Ejercicio 3: academia de idiomas

**Crear la tabla HORARIOS. Las claves y las horas son campos obligatorios. El aula es un número entero, y, aunque no es obligatorio, tomará por defecto el valor 1.**

Como la clave primaria es triple (cod_grupo, dia_semana, dni_prof), no tiene sentido declarar esos atributos como UNIQUE de forma individual: lo que no puede repetirse es el conjunto de los tres, de modo que hay que crear una restricción de tabla que denominaremos pk_horarios_unique:

```sql
CREATE TABLE Horarios (
	cod_grupo	VARCHAR(5)	NOT NULL,
	dia_semana	CHAR(1)	NOT NULL,
	dni_prof	VARCHAR(12)	NOT NULL,
	hora_inicio	TIME	NOT NULL,
	hora_fin	TIME	NOT NULL,
	aula		SMALLINT	DEFAULT 1,
	CONSTRAINT pk_horarios
		PRIMARY KEY (cod_grupo, dia_semana, dni_prof),
	CONSTRAINT pk_horarios_unique
		UNIQUE (cod_grupo, dia_semana, dni_prof),
	CONSTRAINT fk_horarios_1
		FOREIGN KEY (cod_grupo) REFERENCES Grupos(cod_grupo),
	CONSTRAINT fk_horarios_2
		FOREIGN KEY (dni_prof) REFERENCES Profesores(dni_prof)
);
```

**Modificar la tabla ALUMNOS para agregar el campo "cod-grupo", que es una clave ajena.**

```sql
ALTER TABLE Alumnos
	ADD cod_grupo VARCHAR(5) NOT NULL;

ALTER TABLE Alumnos
	ADD CONSTRAINT fk_alumnos
		FOREIGN KEY (cod_grupo) REFERENCES Grupos(cod_grupo);
```

**Insertar el registro ["12345678-Z", "Juan", "López López", "Italiano"] en la tabla PROFESORES.**

```sql
INSERT INTO Profesores VALUES ('12345678-Z', 'Juan', 'López', 'Italiano');
```

**Consultar los nombres y apellidos de los profesores que dan clase de francés de lunes a jueves a partir de las 16:00 horas, junto con la denominación de los grupos a los que dan clase y el horario de cada día.**

```sql
SELECT nombre, apellidos, denominación, día_semana, hora_inicio, hora_fin 
	FROM Profesores, Horarios, Grupos
	WHERE Profesores.dni_prof = Horarios.dni_prof
	    AND Horarios.cod_grupo = Grupos.cod_grupo
	    AND (día_semana = 'L' OR día_semana = 'M' OR día_semana = 'X' OR día_semana = 'J')
	    AND hora_inicio >= '16:00'
	    AND idioma = 'Francés';
```

**Consultar los nombres y apellidos de los alumnos que reciben clases de al menos dos idiomas diferentes.**

```sql
SELECT DISTINCT Alumnos.nombre, Alumnos.apellidos
	FROM Alumnos, Horarios, Profesores AS Profes1
	WHERE Alumnos.cod_grupo = Horarios.cod_grupo
	    AND Horarios.dni_prof = Profes1.dni_prof
	    AND Alumnos.dni IN (SELECT Alumnos.dni 
				FROM Alumnos, Horarios, Profesores AS Profes2
				WHERE Alumnos.cod_grupo = Horarios.cod_grupo
			 	    AND Horarios.dni_prof = Profes2.dni_prof
				    AND Profes1.idioma <> Profes2.idioma);
```

**Consultar los nombres y apellidos de los alumnos que reciben clases de INGLÉS y de FRANCÉS.**

```sql
SELECT Alumnos.nombre, Alumnos.apellidos
	FROM Alumnos, Horarios, Profesores
	WHERE Alumnos.cod_grupo = Horarios.cod_grupo
	    AND Horarios.dni_prof = Profesores.dni_prof
	    AND Profesores.idioma = "Inglés"
INTERSECT
SELECT Alumnos.nombre, Alumnos.apellidos
	FROM Alumnos, Horarios, Profesores
	WHERE Alumnos.cod_grupo = Horarios.cod_grupo
	    AND Horarios.dni_prof = Profesores.dni_prof
	    AND Profesores.idioma = "Francés"
```

**Consultar los nombres y apellidos de los alumnos que reciben clases de INGLÉS o de FRANCÉS.**

```sql
SELECT Alumnos.nombre, Alumnos.apellidos
	FROM Alumnos, Horarios, Profesores
	WHERE Alumnos.cod_grupo = Horarios.cod_grupo
	    AND Horarios.dni_prof = Profesores.dni_prof
	    AND (Profesores.idioma = "Inglés" OR Profesores.idioma = "Francés");
```

**Consultar los nombres y apellidos de los alumnos que reciben clases de INGLÉS pero no reciben clases de ALEMÁN.**

```sql
SELECT Alumnos.nombre, Alumnos.apellidos
	FROM Alumnos, Horarios, Profesores
	WHERE Alumnos.cod_grupo = Horarios.cod_grupo
	    AND Horarios.dni_prof = Profesores.dni_prof
	    AND Profesores.idioma = "Inglés"
EXCEPT
SELECT Alumnos.nombre, Alumnos.apellidos
	FROM Alumnos, Horarios, Profesores
	WHERE Alumnos.cod_grupo = Horarios.cod_grupo
	    AND Horarios.dni_prof = Profesores.dni_prof
	    AND Profesores.idioma = "Alemán";
```

#### Ejercicio 4: concesionario de automóviles

**Crear la tabla COCHES, de forma coherente a cómo la hayas diseñado en el primer apartado. Utiliza tipos de datos SQL adecuados a la información que se guardará en cada campo. El campo cod_coche es obligatorio, y el campo precio tiene 10000,00 como valor por defecto.**

```sql
CREATE TABLE Coches (
	cod_coche 	INTEGER	NOT NULL UNIQUE,
	marca	VARCHAR(50)	NOT NULL,
	modelo	VARCHAR(50)	NOT NULL,
	color		VARCHAR(20),
	precio	DECIMAL(8,2)	DEFAULT 10000.00,
	tipo		VARCHAR(5),	
	CONSTRAINT pk_coches
		PRIMARY KEY (cod_coche),
	CONSTRAINT valores_tipo
		CHECK (tipo = "NUEVO" OR tipo = "KM.0" OR tipo = "USADO")
);
```

**Se ha detectado que algunos clientes tienen una "provincia" con valor nulo, pero, en cambio, sí que tienen un valor asignado al campo "ciudad". Escribe la(s) intrucción(es) SQL necesarias para arreglar este problema de la mejor manera que se te ocurra.**

Eso no habría ocurrido si la base de datos hubiera estado bien diseñada, con las provincias y las ciudades en sus respectivas tablas independientes de los Clientes.

Ahora habremos perdido datos irremediablemente. Lo único que podemos hacer es insertar una provincia genérica (por ejemplo, "Desconocida") en los registros que hayan perdido su provincia, para evitar tener valores nulos en la tabla de Clientes.

```sql
UPDATE Clientes
	SET Provincia = "Desconocida"
	WHERE Provincia IS NULL;
```

**Obtener el NIF de los clientes y los códigos de tienda que no sean de la misma ciudad.**

```sql
SELECT Clientes.cod_cliente, Tiendas.cod_tienda
	FROM Clientes, Ventas, Tiendas
	WHERE Clientes.cod_cliente = Ventas.cod_cliente
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Clientes.ciudad <> Tiendas.ciudad;
```

**Obtener la matrícula, la marca y el modelo de los coches vendidos en tiendas de la provincia de Madrid que no hayan sido vendidos en ninguna otra provincia.**

```sql
(SELECT Coches.cod_coche, marca, modelo
	FROM Coches, Ventas, Tiendas
	WHERE Coches.cod_coche = Ventas.cod_coche
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Tiendas.provincia = "Madrid")
EXCEPT
(SELECT Coches.cod_coche, marca, modelo
	FROM Coches, Ventas, Tiendas
	WHERE Coches.cod_coche = Ventas.cod_coche
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Tiendas.provincia <> "Madrid");
```

Existe una solución alternativa basada en subconsultas, pero el resultado debe ser el mismo:

```sql
SELECT Coches.cod_coche, marca, modelo
	FROM Coches, Ventas, Tiendas
	WHERE Coches.cod_coche = Ventas.cod_coche
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Tiendas.provincia = "Madrid"
	    AND Coches.cod_coche NOT IN (SELECT cod_coche
	FROM Coches, Ventas, Tiendas
	WHERE Coches.cod_coche = Ventas.cod_coche
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Tiendas.provicia <> "Madrid")
```

**Obtener el código, ciudad y dirección de las tiendas que tengan entre 5 y 10 vehículos usados que sean de marca "Renault" y modelo "Megane".**

```sql
SELECT Tiendas.cod_tienda, Tiendas.ciudad, Tiendas.dirección
	FROM Tiendas, Coches-están-en-tiendas, Coches
	WHERE Tiendas.cod_tienda = Coches-están-en-tiendas.cod_tienda
	    AND Coches-están-en-tiendas.cod_coche = Coches.cod_coche
	    AND Coches-están-en-tiendas.cantidad BETWEEN 5 AND 10
	    AND Coches.marca = "Renault" AND Coches.modelo = "Megane"
	    AND Coches.tipo = "U";
```

**Obtener el código, marca y modelo del coche, así como el nombre y apellidos del cliente, de todos los vehículos vendidos a un cliente de Almería por un concesionario de Almería.**

```sql
SELECT Coches.cod_coche, marca, modelo, nombre, apellidos
	FROM Coches, Ventas, Clientes, Tiendas
	WHERE Coches.cod_coche = Ventas.cod_coche
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Ventas.cod_cliente = Clientes.cod_cliente
	    AND Tiendas.ciudad = "Almería"
	    AND Clientes.ciudad = "Almería";
```

**Obtener el nombre y apellidos de clientes que hayan adquirido un coche en algún concesionario que posea actualmente en stock el vehículo marca "Seat", modelo "León".**

```sql
SELECT DISTINCT nombre, apellidos
	FROM Coches, Ventas, Clientes, Coches-están-en-tiendas
	WHERE Clientes.cod_cliente = Ventas.cod_cliente 
	    AND Ventas.cod_coches = Coches.cod_coche
	    AND Coches.cod_coches = Coches-están-en-venta.cod_coche
	    AND Coches.marca = "Seat" AND Coches.modelo = "León"
	    AND Coches-están-en-tienda.cantidad > 0;
```

**Obtener los nombres y apellidos de clientes que no han comprado ningún coche de color rojo a ningún concesionario de Andalucía.**

```sql
SELECT nombre, apellidos
	FROM Clientes, Ventas, Tiendas
	WHERE Clientes.cod_cliente = Ventas.cod_cliente
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Cliende.cod_cliente NOT IN (SELECT cod_cliente 
					FROM Clientes, Ventas, Tiendas
					WHERE Clientes.cod_cliente = Ventas.cod_cliente
					    AND Ventas.cod_tienda = Tiendas.cod_tienda
					    AND Coches.color = "Rojo"
					    AND Tiendas.provincia IN ("Almería", "Granada", "Jaén",
						"Málaga", "Córdoba", "Sevilla", "Cádiz", "Huelva") );
```

#### Ejercicio 5

**El número de goles marcados por el jugador Pantuflo Zapatilla en los partidos del mes de febrero de 2007.**

```sql
SELECT ADD(goles)
	FROM Futbolistas, Participan, Partidos
	WHERE Futbolistas.cod_futbolista = Participan.cod_futbolista
	    AND Participan.cod_partido = Partidos.cod_partido
	    AND nombre = "Pantuflo" AND apellidos = "Zapatilla"
	    AND fecha BETWEEN "1/2/07" AND "28/2/2007";
```

**El nombre de los equipos contra los que ha jugado el Almería en partidos arbitrados por Esquinas Torres, así como el resultado y la jornada de esos partidos.**

```sql
(SELECT nombre-eq-visitante, resultado, jornada
	FROM Juegan, Partidos, Arbitran, Arbitros
	WHERE Juegan.cod_partido = Partidos.cod_partido
	     AND Partidos.cod_partido = Arbitran.cod_partido
	     AND Arbitran.num_colegiado = Arbitros.num_colegiado
	     AND Arbitros.nombre = "Esquinas" AND Arbitros.apellidos = "Torres"
	     AND Juegan.nombre-eq-casa = "Almería")
UNION
(SELECT nombre-eq-casa, resultado, jornada
	FROM Juegan, Partidos, Arbitran, Arbitros
	WHERE Juegan.cod_partido = Partidos.cod_partido
	     AND Partidos.cod_partido = Arbitran.cod_partido
	     AND Arbitran.num_colegiado = Arbitros.num_colegiado
	     AND Arbitros.nombre = "Esquinas" AND Arbitros.apellidos = "Torres"
	     AND Juegan.nombre-eq-visitante = "Almería")
```

Una solución alternativa es la siguiente, que muestra en todos los registros el nombre de equipo "Almería" junto con su contrincante, ya sea local o visitante:

```sql
SELECT nombre-eq-casa, nombre-eq-visitante, resultado, jornada
	FROM Juegan, Partidos, Arbitran, Arbitros
	WHERE Juegan.cod_partido = Partidos.cod_partido
	     AND Partidos.cod_partido = Arbitran.cod_partido
	     AND Arbitran.num_colegiado = Arbitros.num_colegiado
	     AND Arbitros.nombre = "Esquinas" AND Arbitros.apellidos = "Torres"
	     AND (Juegan.nombre-eq-visitante = "Almería" OR Juegan.nombre-eq-casa = "Almeria")
```

**Todos los datos de la plantilla de futbolistas del Real Madrid.**

```sql
SELECT Futbolistas.*
	FROM Futbolistas, Contratos
	WHERE Futbolistas.cod-futbolista = Contratos.cod-futbolista
	    AND Contratos.nombre_eq = "Real Madrid";
```

**Buscar el nombre y la estatura del futbolista más alto del FC Barcelona.**

```sql
SELECT nombre, estatura
	FROM Futbolistas, Contratos
	WHERE Futbolistas.cod-futbolista = Contratos.cod-futbolista
	    AND Contratos.nombre_eq = "FC Barcelona"
	    AND estatura IN (SELECT MAX(estatura)
				FROM Futbolistas, Contratos
				WHERE Futbolistas.cod-futbolista = Contratos.cod-futbolista
				    AND Contratos.nombre_eq = "FC Barcelona");
```
