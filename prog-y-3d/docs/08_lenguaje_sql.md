---
layout: page
title: 9. El lenguaje SQL
permalink: /lenguaje-sql/
nav_order: 9
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 9. El lenguaje SQL
{: .no_toc }

- TOC
{:toc}


Comandos básicos de SQL: DDL, DML y DCL.

## 7.4. El diseño físico

Unidad 3 Creación de bases de datos relacionales: el diseño físico

I.E.S. Celia Viñas (Almería)

C.F.G.S. Desarrollo de Aplicaciones Web

Módulo de Bases de datos
3. Creación de bases de datos relacionales: el diseño físico Índice del tema
Unidad 3. Creación de bases de datos relacionales: el diseño físico
Contenido:

    3.1 Notación
    3.2 Interfaces gráficos para el SGDB
    3.3 Intérpretes de comandos para el SGBD
    3.4 El lenguaje de definición de datos
    3.5 Definición de la base de datos con SQL
    3.6 Definición de la estructura de la base de datos con SQL

3. Creación de bases de datos relacionales: el diseño físico 3.1 Notación
3.1 Notación

    MAYÚSCULAS: palabra reservada.
    minúsculas cursiva: definido en otra parte.
    [corchetes] : opcionalidad.
    { llaves | llaves | … }: optatividad (se debe elegir una opción)
    Puntos suspensivos (...): repetición del último elemento

p. 92
3. Creación de bases de datos relacionales: el diseño físico 3.1 Notación
Ejemplo: sintaxis de la instrucción DROP TABLE
DROP [TEMPORARY] TABLE [IF EXISTS]
tbl_name [, tbl_name] ...
[RESTRICT | CASCADE]
3. Creación de bases de datos relacionales: el diseño físico 3.2 Interfaces gráficos para el SGBD
3.2 Interfaces gráficos para el SGBD

    A lo largo del curso trabajaremos principalmente con dos SGBD relacionales:
        Microsoft Access
        MySQL
    Antes de continuar, vamos a hablar brevemente de ellos.

p. 93
3. Creación de bases de datos relacionales: el diseño físico 3.2 Interfaces gráficos para el SGBD

    ¿Qué es Microsoft Access?
        MS Access es un gestor de bases de datos relacionales ofimáticas, destinado a ser fácil de usar y altamente productivo.
        No está diseñado para un alto rendimiento ni para soportar múltiples conexiones simultáneas.
        Es propiedad de Microsoft y se incluye en el paquete Microsoft Office, aunque puede obtenerse e instalarse por separado.
        Puede conectarse a múltiples lenguajes de programación (C/C++, PHP, Java...), aunque para su operación en red requiere un servidor web de Microsoft (IIS)
        Pueden programarse módulos adicionales con VBA (Visual Basic for Applications)
        Está muy extendido en el ámbito de las bases de datos ofimáticas por su relativa facilidad de uso.

new!
3. Creación de bases de datos relacionales: el diseño físico 3.2 Interfaces gráficos para el SGBD
Breve historia de MS Access

    Access 1.0 apareció en 1992, después de varios intentos fallidos de Microsoft de desarrollar un SGBD sencillo para usuarios sin gran experiencia.
    A partir de 1995 empieza a formar parte de la suite Microsoft Office y se populariza.
    Access es el programa que más cambios ha sufrido en las sucesivas versiones de Office, siendo a menudo los formatos de base de datos incompatibles entre versiones.
    La versión actual es Access 2010.

new!
3. Creación de bases de datos relacionales: el diseño físico 3.2 Interfaces gráficos para el SGBD

    ¿Qué es MySQL?
        MySQL es un gestor de bases de datos relacional multiusuario y multiplataforma de altas prestaciones.
        Permite mútiples conexiones remotas.
        El software libre, aunque el código es propiedad de la empresa AB MySQL (adquirida por SUN en 2008 y por Oracle en 2010)
        Existen librerías para acceder a MySQL desde los lenguajes de programación más extendidos: C/C++, Java, PHP, Perl, Pascal...
        Está muy extendida en aplicaciones web, generalmente en combinación con PHP.
        Cuenta un un interfaz gráfico programado en PHP, llamado PHPMyAdmin, que se ejecuta en el navegador web y permite administrar remotamente las bases de datos.

new!
3. Creación de bases de datos relacionales: el diseño físico 3.2 Interfaces gráficos para el SGBD
Breve historia de MySQL

    MySQL surgió como un proyecto OpenSource en Suecia en 1995.
    El objetivo era lograr un SGBD rápido y fiable que cumpliera con el estándar SQL.
    Las primeras versiones (que se denominaron mSQL) eran muy ineficientes.
    La popularización de PHP y su ganancia en eficiencia a partir de la versión 3 la han hecho muy popular en la actualidad.
    Versión más reciente: 5.5.17 (octubre de 2011)

new!
3. Creación de bases de datos relacionales: el diseño físico 3.2 Interfaces gráficos para el SGBD
Interfaz gráfico para MS Access

    El interfaz está integrado en el propio SGBD y son inseparables.

new!
3. Creación de bases de datos relacionales: el diseño físico 3.2 Interfaces gráficos para el SGBD
Interfaces gráficos para MySQL

    Hay varios, y el más usado es PHPMyAdmin. Debe instalarse por separado y es un interfaz web.

p. 93
3. Creación de bases de datos relacionales: el diseño físico 3.2 Interfaces gráficos para el SGBD
Interfaz gráfico para Oracle

    Oracle incorpora el Enterprise Manager, incluido en el propio paquete de Oracle.
    Interfaz gráfico para DB2 de IBM
    Para este SGBD existe el DB2 Data Studio (antes llamado Control Center). DB2 tiene una versión gratuita reducida (DB2 Express)

p. 94

p. 96
3. Creación de bases de datos relacionales: el diseño físico 3.3. Intérpretes de comandos para SGBD
3.3 Intérpretes de comandos para SGBD

    Microsoft Access: carece de intérprete de comandos. Sólo puede usarse a través de su interfaz gráfico.
    MySQL: el intérprete de comandos se llama mysql.
    Oracle: su intérprete es SQL*Plus.

p. 97
3. Creación de bases de datos relacionales: el diseño físico 3.3. Intérpretes de comandos para SGBD
El intérprete de comandos de MySQL

    Sintaxis general:
    mysql [options] [database]
    Se obtiene la lista completa de opciones con mysql --help
    Conexión con el servidor:
    mysql -u usuario [-p password] [-h servidor] [-P puerto]
    Una vez conectados al servidor, obtendremos el prompt del intérprete de comandos:
    mysql>

p. 98
3. Creación de bases de datos relacionales: el diseño físico 3.3. Intérpretes de comandos para SGBD
Algunos comandos sencillos para MySQL

    mysql> SELECT VERSION();
    mysql> SELECT CURRENT_DATE();
    mysql> SELECT NOW();
    mysql> SELECT USER();
    mysql> SOURCE nombre_archivo.sql;
    mysql> SHOW DATABASES;
    mysql> USE nombre_db;
    mysql> SHOW TABLES;
    mysql> DESCRIBE [esquema.]nombre_tabla;

p. 100

Act. 3.1 (p. 94) + Act. 3.4 (p. 102)
3. Creación de bases de datos relacionales: el diseño físico 3.4. El lenguaje de definición de datos
3.4 El lenguaje de definición de datos: SQL

    Breve historia de SQL
        Origen de SQL
            Codd (1970) propone el modelo relacional y un lenguaje de acceso al mismo basado en álgebra relacional.
        Evolución de SQL
            IBM (1977) crea el lenguaje SEQUEL basado en la teoría de Codd para un SGBD experimental.
            Oracle (1979) lo utiliza por primera vez en un producto comercial.
            SQL evoluciona a partir de SEQUEL.
            Tiene mucho éxito, pero cada compañía fabrica su “dialecto” de SQL: se hace necesaria una estandarización.

new!
3. Creación de bases de datos relacionales: el diseño físico 3.4. El lenguaje de definición de datos
Versiones de SQL

    SQL-86
        Es el primer estándar. Fue publicado por ANSI. ISO lo confirmó en 1987, por lo que a veces se denomina SQL-87.
    SQL-89 y SQL-92
        Fueron diferentes revisiones del lenguaje para agregarles características que ya estaban es uso en diferentes SGBD.
    SQL-99 (o SQL3)
        Incluye tiggers, recursión y orientación a objetos.
    SQL-2003
        Introduce XML y otras estandarizaciones.

new!
3. Creación de bases de datos relacionales: el diseño físico 3.4. El lenguaje de definición de datos

    Dialectos de SQL
        Los SGBD comerciales se ajustan sólo aproximadamente al estándar.
        Además, todos incluyen mejoras y añadidos sobre SQL para superar a los competidores.
        Esos añadidos no son compatibles entre diferentes SGBD:
            Podemos hablar de “dialectos” de SQL
            Si queremos que nuestra base de datos sea portable, hay que evitar usar los añadidos y respetar al máximo el estándar.
            Con el tiempo, los añadidos de mayor éxito pueden acabar incorporados al estándar.
            En cualquier caso, lo habitual es tener que hacer pequeños ajustes al código SQL para hacerlo funcionar con varios SGBD.

new!
3. Creación de bases de datos relacionales: el diseño físico 3.4. El lenguaje de definición de datos
El DDL de SQL

    El DDL (lenguaje de definición de datos) sólo es un subconjunto de SQL formado por tres instrucciones:
        CREATE
        DROP
        ALTER

p. 104
3. Creación de bases de datos relacionales: el diseño físico 3.5. Definición de la base de datos
3.5 Definición de la base de datos: CREACIÓN

    Sintaxis:
    CREATE { DATABASE | SCHEMA } [IF NOT EXISTS] nombre_db
    [especificación_create [,espec_create] … ]
    especificación_create:
    [DEFAULT] CHARACTER SET juego_caracteres |
    [DEFAULT] COLLATE nombre_colación
    Ejemplo:
    CREATE DATABASE videoclub CHARACTER SET utf8
    COLLATE utf8_spanish_ci;

p. 105
3. Creación de bases de datos relacionales: el diseño físico 3.5. Definición de la base de datos

    Después de crear la base de datos, con el intérprete de MySQL se puede comprobar que se ha creado correctamente:
    mysql> SHOW DATABASES;
    Para utilizar la base de datos hay que teclear:
    mysql> USE nombre_bd;

Act. 3.6 (p. 106)
3. Creación de bases de datos relacionales: el diseño físico 3.5. Definición de la base de datos
Definición de la base de datos: MODIFICACIÓN

    Sintaxis:
    ALTER DATABASE nombre_db
    {COLLATE nueva_colación | CHARACTER SET nuevo_cs }
    Una limitación de MySQL es que no permite modificar casi nada de la base de datos una vez creada. En esto, otros SGBD como Oracle son más flexibles.

p. 110
3. Creación de bases de datos relacionales: el diseño físico 3.5. Definición de la base de datos
Definición de la base de datos: BORRADO

    Sintaxis:
    DROP DATABASE nombre_db
    También se pueden borrar todos los ficheros de la DB manualmente, pero esto puede confundir al SGBD.
    Una vez eliminada la base de datos, es irrecuperable a menos que tengamos una copia de seguridad.

p. 111
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos
3.6 Definición de la estructura de la base de datos
3.6.a) Creación de tablas
CREATE [TEMPORARY] TABLE [esquema.]nombre_tabla
[(definición_create,...)]
[opciones_tabla]

    definición_create:
    definición_columna |
    [CONSTRAINT [símbolo]] PRIMARY KEY (nombre_columna,...)
    | [CONSTRAINT [símbolo]] FOREIGN KEY (i,...)
    [definición_referencia]

p. 111
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos

    definición_columna:
    nombre_columna tipo_datos [NOT NULL|NULL] [DEFAULT valor]
    [UNIQUE [KEY] | [PRIMARY] KEY]
    [definición_referencia]
    definición_referencia:
    REFERENCES nombre_tabla [(nombre_columna,...)]
    [ON DELETE {CASCADE | SET NULL | NO ACTION} ]
    [ON UPDATE {CASCADE | SET NULL | NO ACTION} ]

3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos

    opciones_tabla (para MySQL):
    ENGINE = nombre_motor
    | AUTO_INCREMENT = valor
    | [DEFAULT] CHARACTER SET juego_caracteres [COLLATE col]
    | CHECKSUM = {0 | 1}
    | COMMENT = 'string'
    | MAX_ROWS = valor
    | MIN_ROWS = valor

Act. 3.8 (p. 115) (sólo mysql)
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos
Restricciones de integridad al crear tablas
Las restricciones de integridad del modelo relacional pueden ayudan a evitar inconsistencias en los datos.

    Hay básicamente tres tipos de restricciones:
        Integridad referencial
        Eliminación en cascada
        Actualización en cascada
    Podemos elegir usarlas o no:
        Si no se usan, nos arriesgamos a tener inconsistencias: la base de datos dejaría de ser útil.
        Si se usan, la base de datos nos impedirá hacer ciertas cosas, lo que puede restar flexibilidad.

p. 113
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos

    Integridad referencial
        Nos asegura que los registros de tablas relacionadas son coherentes

cod_autor

nombre

1

2

Joseph Conrad

Isaac Asimov

Tabla

Libros

Tabla

Autores

cod_libro

título

482

Lord Jim

cod_autor

1

2

3

4

484

Ana Karenina

485

Misericordia

483

Fundación

Lev Tolstói

3

B. Pérez Galdós

4

cod_autor

nombre

1

2

Joseph Conrad

Isaac Asimov

Tabla

Libros

Tabla

Autores

cod_libro

título

482

Lord Jim

cod_autor

1

2

32

4

484

Ana Karenina

485

Misericordia

483

Fundación

Lev Tolstói

3

B. Pérez Galdós

4

Sin integridad referencial puede ocurrir esto:

¡No está relacionado con ningún registro!

new!
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos

    Es muy grave que ocurra una inconsistencia como la de la figura anterior:
        No hay modo de saber quién es el autor del libro.
        ¡El dato se ha perdido irremediablemente!
        La base de datos pierde su razón de ser si deja de contener datos válidos.
    La integridad referencial impide que se dé esa circunstancia:
        El propio SGBD prohibirá insertar en la tabla de Libros un código de autor que no exista en la tabla de Autores.
        Problema: debemos dar de alta a todos los autores antes de dar de alta a los libros.

3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos
Borrado en cascada

    ¿Qué ocurre si borramos un registro de la tabla de Autores?

cod_autor

nombre

1

2

Joseph Conrad

Isaac Asimov

Tabla

Libros

Tabla

Autores

cod_libro

título

482

Lord Jim

cod_autor

1

2

3

4

484

Ana Karenina

485

Misericordia

483

Fundación

Lev Tolstói

3

B. Pérez Galdós

4

cod_autor

nombre

1

2

Joseph Conrad

Isaac Asimov

Tabla

Libros

Tabla

Autores

cod_libro

título

482

Lord Jim

cod_autor

1

2

3

4

484

Ana Karenina

485

Misericordia

483

Fundación

Lev Tolstói

3

¡El libro 485 ha perdido su referencia!

Vamos a borrar este registro

new!
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos

    Si tenemos activada la integridad referencial, el SGBD nos prohibirá hacer ese borrado.
    Pero si, además, tenemos activada la eliminación en cascada, el SGBD sí que nos dejará borrar el registro.
        Se borrará el registro 4 en la tabla de Autores.
        Y también se borrarán todos los registros de la tabla de Libros que estén relacionados con ese autor.
        Así se mantiene la coherencia, pero, ¡cuidado!: podemos perder datos que no queríamos borrar.

3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos

    Al borrar un autor con eliminación en cascada...

cod_autor

nombre

1

2

Joseph Conrad

Isaac Asimov

Tabla

Libros

Tabla

Autores

cod_libro

título

482

Lord Jim

cod_autor

1

2

3

4

484

Ana Karenina

485

Misericordia

483

Fundación

Lev Tolstói

3

B. Pérez Galdós

4

cod_autor

nombre

1

2

Joseph Conrad

Isaac Asimov

Tabla

Libros

Tabla

Autores

cod_libro

título

482

Lord Jim

cod_autor

1

2

3

484

Ana Karenina

483

Fundación

Lev Tolstói

3

...también se borran TODOS sus libros:

Vamos a borrar este registro
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos
Modificación en cascada:

        ¿Qué ocurre si modificamos la clave de un registro de la tabla de Autores?

cod_autor

nombre

1

2

Joseph Conrad

Isaac Asimov

Tabla

Libros

Tabla

Autores

cod_libro

título

482

Lord Jim

cod_autor

1

2

3

4

484

Ana Karenina

485

Misericordia

483

Fundación

Lev Tolstói

3

B. Pérez Galdós

4

cod_autor

nombre

1

2

Joseph Conrad

Isaac Asimov

Tabla

Libros

Tabla

Autores

cod_libro

título

482

Lord Jim

cod_autor

1

2

3

4

484

Ana Karenina

485

Misericordia

483

Fundación

Lev Tolstói

3

¡El libro 485 ha perdido su referencia!

Vamos a cambiar la clave de este registro

B. Pérez Galdós

5

Son distintos

new!
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos

    Si tenemos activada la integridad referencial, el SGBD nos prohibirá hacer esa modificación.
    Pero si, además, tenemos activada la modificación en cascada, el SGBD sí que nos dejará cambiar el registro.
        Se modificará la clave del registro 4 en la tabla de Autores.
        Y también se modificarán todas las claves ajenas de la tabla de Libros que estén relacionadas con ese autor.
        Por tanto, es un caso muy parecido al de eliminación en cascada, aunque menos destructivo.

3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos

    Si tenemos activada la modificación en cascada...

cod_autor

nombre

1

2

Joseph Conrad

Isaac Asimov

Tabla

Libros

Tabla

Autores

cod_libro

título

482

Lord Jim

cod_autor

1

2

3

4

484

Ana Karenina

485

Misericordia

483

Fundación

Lev Tolstói

3

B. Pérez Galdós

4

cod_autor

nombre

1

2

Joseph Conrad

Isaac Asimov

Tabla

Libros

Tabla

Autores

cod_libro

título

482

Lord Jim

cod_autor

1

2

3

5

484

Ana Karenina

485

Misericordia

483

Fundación

Lev Tolstói

3

...el SGBD modificará las claves ajenas en Libros:

Vamos a cambiar la clave de este registro

B. Pérez Galdós

5

Siguen relacionados
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos
Tipos de datos en MySQL

    TINYINT, SMALLINT, MEDIUMINT, INT, BIGINT: números enteros de 8, 16, 24, 32 y 64 bits.
    FLOAT, DOUBLE: números reales de precisión simple (E±38) y doble (E±308).
    DECIMAL(num-dígitos, num-decimales): números reales. “num-dígitos” es el número total de dígitos.
    DATE: Fecha. El formato suele ser 'aaaa-mm-dd'
    TIME: Hora. El formato suele ser 'hh:mm:ss'
    DATETIME: fecha y hora. El formato generalmente es 'aaaa-mm-dd hh:mm:ss'
    CHAR (num-caracteres): cadena de caracteres. La longitud puede ir de 1 a 255. Los caracteres no utilizados se rellenan con espacios.
    VARCHAR(num-cars), VARCHAR2(num-cars): cadena de caracteres de longitud máxima 2000 o 4000. Sólo se almacenan los caracteres realmente utilizados.
    BLOB, TEXT: cadenas de hasta 216 bytes. El primero almacena en formato binario y el segundo en formato carácter.
    TINYTEXT, LONGTEXT: cadenas de hasta 28 y 232 caracteres. También existen los correspondientes TINYBLOB y BIGBLOB.
    BINARY(num-bytes): números binarios de hasta 255 bytes.

p. 116
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos
3.6.b) Modificación de tablas
ALTER TABLE nombre_tabla
especificación_alter [,especificación_alter] ...

    especificación_alter:
    ADD definición_columna [FIRST | AFTER columna]
    | ADD (definición_columna, ...)
    | ADD [CONSTRAINT símbolo]] PRIMARY KEY (columna,...)
    | ADD [CONSTRAINT símbolo]] UNIQUE (columna,...)
    | ADD [CONSTRAINT símbolo]] FOREIGN KEY (columna,...)
    [definición_referencia]
    (continúa en pág. siguiente)

p. 120
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos
(viene de pág. anterior)
| CHANGE [COLUMN] nombre_anterior definición_columna
[FIRST|AFTER nombre_columna]
| RENAME COLUMN nombre_anterior TO nombre_nuevo
| MODIFY definición_columna [FIRST | AFTER columna]
| DROP COLUMN columna
| DROP PRIMARY KEY
| DROP FOREIGN KEY símbolo
| opciones_tabla
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos
3.6.c) Borrado de tablas
DROP [TEMPORARY] TABLE nombre_tabla [,nombre_tabla] ...
3.6.d) Renombrado de tablas
RENAME TABLE nombre_tabla TO nuevo_nombre
[, nombre_tabla TO nuevo_nombre] ...

p. 122

p. 122
3. Creación de bases de datos relacionales: el diseño físico 3.6. Definición de la estructura de la base de datos
Prácticas

Práctica 3.5 (p. 128)

Práctica 3.7 (p. 129)

Práctica 3.8 (p. 129)

Prácticas adicionales (aula virtual)





4.

REALIZACIÓN DE CONSULTAS EN MYSQL

4.0.

CONTENIDOS



Sentencia SELECT



Consultas básicas, filtros y ordenación



Consultas resumen



Subconsultas



Consultas multitabla. Componentes internas y externas



Consultas reflexivas



Consultas con tablas derivadas

4.1.

LENGUAJE DML

Las sentencias DML de SQL son:



SELECT: extrae información de una o varias tablas



INSERT: inserta registros en tabla



DELETE: borra registros en tabla



UPDATE: modifica registros en tabla

4.2.

SENTENCIA SELECT

EJEMPLOS:

1.

Consulta básica:

Ejemplo: muestra todos los registros de la tabla empleados

SELECT * FROM empleados;

2.

Consulta que obtiene información filtrada de múltiples tablas , usando

relaciones entre tablas, incluso varias tablas virtuales creadas a partir de

una consulta

Ejemplo: obtener el total de los pedidos d los clientes de una tienda

SELECT NombreCliente, Tot.Cantidad

FROM Clientes, Pedidos,

(SELECT SUM(Cantidad*PrecioUnidad) AS Cantidad, NumeroPedido

FROM DetallePedidos GROUP BY NumeroPedido) Tot

WHERE Clientes.NumeroCliente=Pedidos.NumeroCliente

AND Pedidos.NumeroPedido=Tot.NumeroPedido

ORDER BY Cantidad;

4.3.

CONSULTAS BÁSICAS

SELECT *DISTINCT+ campo1, campo2,… *expresión+

FROM tabla



DISTINCT es opcional, suprime los resultados repetidos



campo1, campo2,… son los campos o columnas de la tabla que usaremos para

extraer

información.

Si

deseamos

todos

los

campos

debemos

indicarlo

mediante el carácter comodín *.



Expresión

es

una

fórmula

compuesta

por

operadores(

+,-,*,/)

o

funciones(SUM, AVG, MAX, MIN, COUNT) calculados sobre los campos de la

tabla



Ejemplos pág. 136 del libro escanear

o

Destacar la expresión 1+5,

o

Destacar función CONCAT (marca, modelo) AS coche FROM vehiculos

Comentario [a1]:

Tabla virtual

Comentario [a2]:

Las tablas de

pedidos y clientes están relacionadas

por el campo NumeroCliente



Concatena los campos marca y modelo y los reúne en una

columna que llama coche.



CONCAT En Oracle sólo admite 2 parámetros pero en MySQL

se puede concatenar múltiples parámetros



Para

concatenar

varios

parámetros

en

Oracle

usamos

el

operador relacional OR ||

ACTIVIDAD 4.1: Pag 137

1.

Crear

tabla

de

Mascotas

(Codigo,

Nombre,

Especie,

Raza,

Edad,

Sexo)

mediante

la

declaración:

CREATE TABLE Mascotas(

Codigo integer PRIMARY KEY,

Nombre varchar (20) NOT NULL,

Especie varchar (20) NOT NULL,

Raza varchar (20) NOT NULL,

Edad integer NOT NULL,

Sexo varchar (2) NOT NULL);

2.

Introduce 6 registros(inventados) mediante la sentencia

INSERT INTO Mascotas VALUES

(‘kira’, “perro”, "doberman", 3, “F”), (otro registro),(otro registro);

3.

Realiza las consultas

3.1.

Muestra el nombre y la especie de todas las mascotas

3.2.

Muestra el nombre y el sexo de las mascotas poniendo un alias a los campos (por

ejemplo la letra inicial)

3.3.

Muestra el nombre y la fecha de nacimiento aproximada de las mascotas. Usa la

función date_sub y now. Buscar en el manual de MySQL la sintaxis de estas funciones.

4.4.

FILTROS



Son las condiciones que deben cumplir los registros de las tablas



Se utiliza la cláusula WHERE



Ejemplo: WHERE marca=’seat’

4.4.1.

Expresiones en filtros



WHERE expresión



Expresión puede contener



Operandos: pueden ser valores constantes que ya aparecen en la tabla o

valores calculados mediante operadores



Operadores

1.

Aritméticos:+,-,*,/,%(calcula el resto de la división)

2.

Relacionales:>,<,>=,<=,<>,=

3.

Lógicos: AND, OR, NOT

4.

Funciones: SUM, MAX, MIN, AVG, COUNT, CONCAT, DATE_ADD, LEFT,

RIGHT



Ejemplos de la BD de la NBA pag 141

1.

Selecciona los nombres de los jugadores de los Lakers

SELECT Nombre FROM jugadores

WHERE Nombre_equipo=’Lakers’;

2.

Selecciona los jugadores españoles de los Lakers

SELECT codigo, Nombre, Altura

Comentario [a3]:

expresión

FROM jugadores WHERE Nombre_equipo=’Lakers’

AND Procedencia=’Spain’;

3.

Selecciona los jugadores españoles y eslavos de los Lakers

SELECT codigo, Nombre, Altura

FROM jugadores WHERE Nombre_equipo=’Lakers’

AND (Procedencia=’Spain’ OR Procedencia = ‘Slovenia’);

4.4.2.

Filtros con operador de pertenencia a conjuntos IN



Permite comprobar si un campo tiene algún valor contenido en una lista

de valores



Campo IN ( Valor1, Valor2, …, ValorN)



Ejemplo: seleccionar los jugadores españoles, eslovenos o serbios de los

Lakers

SELECT codigo, Nombre, Altura

FROM jugadores WHERE Nombre_equipo=’Lakers’

AND Procedencia IN (‘Spain’, ‘Slovenia’, ‘Serbia & Montenegro’);

4.4.3.

Filtros con operador de rango BETWEEN

Permite seleccionar los registros que están incluidos entre un rango de 2 valores



Campo BETWEEN Valor1 AND Valor2



Ejemplo:

Seleccionar

los

jugadores

de

la

NBA

cuyo

peso

esté

comprendido entre 270 y 300 libras

SELECT Nombre, Nombre_equipo

FROM jugadores

WHERE Peso BETWEEN 270 AND 300;

4.4.4.

Filtros con test IS, LIKE



de valor nulo: operador IS null , IS NOT null: Permite comprobar si un campo

es o no nulo



ejemplo1: comprobar los jugadores cuya procedencia es desconocida (null)

SELECT Nombre, Nombre_equipo

FROM jugadores

WHERE Procedencia IS null;



ejemplo2: comprobar los jugadores cuya procedencia es conocida (not null)

SELECT Nombre, Nombre_equipo

FROM jugadores

WHERE Procedencia IS NOT null;



de

patrón:

operador

LIKE

:

Selecciona

los

registros

si

cumplen

las

características

indicadas

en

el

patrón.

En

el

patrón

se

pueden

usar

los

caracteres comodín % (un carácter) _(grupo de caracteres)

ejemplo3:

Seleccionar

de

la

tabla

de

vehículos

aquellos

vehículos

cuyo

modelo sea ‘tdi’

SELECT * FROM vehiculos

WHERE modelo LIKE ‘%tdi%’;

4.4.5.

Filtros para limitar el número de registros LIMIT



No es un filtro estándar, pues varía de unos SGBD a otros



En MySQL

LIMIT [desplazamiento,] nfilas

Ejemplo1: devuelve las 4 primeras filas

SELECT nombre, Nombre_equipo FROM jugadores LIMIT 4;

Ejemplo2: devuelve las 3 primeras filas a partir de la sexta

SELECT nombre, Nombre_equipo FROM jugadores LIMIT 5,3 ;

4.4.6.

Filtros para ordenación ORDER BY



Ordena

los

resultados

por

campo,

expresión

o

posición

ascendente

o

descendentemente



ORDER BY campo(s) o expression o posición [ASC | DESC]

Ejemplo1: pag146: Obtener los equipos de la conferencia oeste de la NBA por

división

SELECT Nombre, Division

FROM equipos WHERE Conferencia=’West’

ORDER BY Division ASC;

Ejemplo2: pag147: Obtener los equipos de la conferencia oeste de la NBA por

división ascendentemente y por nombre descendentemente

SELECT Nombre, Division

FROM equipos WHERE Conferencia=’West’

ORDER BY Division ASC, Nombre ASC;

4.5.

CONSULTAS RESUMEN



Generan consultas complejas que resumen la información



Realizan cálculos sobre los datos mediante funciones de columna



Las funciones más utilizadas son:

o

SUM(expresión) p

o

AVG(expresión)

o

MAX(expresión)

o

MIN(expresión)

o

COUNT (expresión)

Donde expresión puede ser: el nombre de un campo, *, expresión con operadores

Comentario [a4]:

a partir de qué fila

Comentario [a5]:

número de filas a

devolver

Comentario [a6]:

la primera fila

ocupa la posición 0

Ejemplo1: selecciona el jugador más pesado de la NBA

SELECT MAX(peso) FROM jugadores;

Ejemplo2: selecciona el jugador más bajito de la NBA

SELECT MIN(altura) FROM jugadores;

Ejemplo3:

selecciona

el

número

de

jugadores

de

los

Lakers=

¿Cuántos

jugadores tiene el equipo de los Lakers?

SELECT COUNT(*)

FROM jugadores

WHERE Nombre_equipo=’Lakers’;



GROUP BY: Permite agrupar registros que tienen una o varias columnas con el

mismo valor. Se coloca antes de ORDER BY. En el enunciado de la consulta

suele decir cada.

Ejemplo1: ¿Cuánto pesa el jugador más pesado de cada equipo?

SELECT Nombre_equipo, MAX(peso)

FROM jugadores

GROUP BY Nombre_equipo;

Ejemplo2: ¿Cuántos equipos tiene cada conferencia en la NBA?

SELECT COUNT(*), conferencia

FROM equipos

GROUP BY conferencia;

Ejemplo3: ¿Cuánto pesan de media los jugadores en España, Francia e Italia?

SELECT AVG(peso), procedencia

FROM jugadores

WHERE procedencia IN (‘Spain’,’Italy’,’France’)

GROUP BY procedencia;

4.6.

FILTROS DE GRUPOS :HAVING



Restringe los grupos a la condición especificada mediante un filtro



Se coloca después de GROUP BY



Su sintaxis es: HAVING filtro de grupos

Ejemplo1: Seleccionar los equipos de la NBA cuyos jugadores pesen de media

más de 228 libras

SELECT Nombre_equipo

FROM jugadores

GROUP BY Nombre_equipo

HAVING AVG(peso)>228

ORDER BY AVG(peso);

Ejemplo2: Seleccionar qué equipos de la NBA tienen más de 1 jugador

español

SELECT Nombre_equipo, COUNT(*)

FROM jugadores

WHERE procedencia=’Spain’

GROUP BY Nombre_equipo

HAVING COUNT(*)>1;

4.7.

SUBCONSULTAS



Se utilizan para realizar filtrados con los datos de otra consulta



Los filtros se pueden utilizar tanto en la cláusula WHERE como en la cláusula

HAVING



Ejemplo: seleccionar los nombres de los jugadores de la división ‘SouthEast’

SELECT nombre FROM jugadores

WHERE Nombre_equipo IN

(SELECT nombre FROM equipos WHERE division=‘SouthEast’);

TEST DE COMPARACIÓN =, <>, >=,<=, <,>



La subconsulta debe estar al lado derecho del operador de comparación

Campo < subconsulta y subconsulta > campo



Ejemplo: Consultar el nombre del jugador de mayor altura de la NBA

SELECT nombre FROM jugadores

WHERE altura=

(SELECT MAX(altura) FROM jugadores);

TEST DE PERTENENCIA A UN CONJUNTO: IN



Filtra los registros cuya expresión coincida con algún valor producido por la

subconsulta



Ejemplo:

extraer

las

divisiones

de

la

NBA

donde

juegan

los

jugadores

españoles

SELECT división FROM equipos

WHERE nombre IN

(SELECT Nombre_equipo FROM jugadores

WHERE procedencia=’Spain’);

TEST DE EXISTENCIA: EXISTS y NOT EXISTS



Filtra los registros de la consulta si existen filas en la subconsulta asociada



Ejemplo: Seleccionar los equipos que no tengan jugadores españoles

SELECT nombre FROM equipos

WHERE NOT EXISTS

(SELECT Nombre FROM jugadores

WHERE equipos.nombre=jugadores. Nombre_equipo

AND procedencia=’Spain’);

TEST CUANTIFICADOS: ALL y ANY



Sirven para calcular la relación entre una expresión y todos (ALL), o algunos

(ANY) de los registros de una subconsulta



Ejemplo1: ¿Qué jugadores de la NBA pesan más que todos los jugadores

españoles?

SELECT nombre, peso FROM jugadores

WHERE peso> ALL

(SELECT peso FROM jugadores

WHERE procedencia=’Spain’);



Ejemplo2: Consultar las bases (posición=’G’) que pesan más que cualquier

pivot (posición=’C’) de la NBA

SELECT nombre, peso FROM jugadores

WHERE posición=’G’ AND

peso > ANY

(SELECT peso FROM jugadores

WHERE posición=’C’);

SUBCONSULTAS ANIDADAS



Permite explorar la información de forma estructurada



Utilizan subconsultas para filtrar los resultados de otra(s) subconsultas



Ejemplo: obtener el nombre de la ciudad donde juega el jugador más alto de

la NBA.

SELECT ciudad FROM equipos WHERE nombre=

(SELECT Nombre_equipo FROM jugadores WHERE altura=

(SELECT MAX(altura) FROM jugadores));

4.8.

CONSULTAS MULTITABLA



Utilizan información de más de una tabla



Las tablas deben estar relacionadas por algún campo común



Aprovechan los campos relacionados de ambas tablas para unirlas (JOIN)

mediante un producto cartesiano



Para especificar los campos de cada tabla: nombre_tabla.nombre_campo



La referencia a cada tabla se realiza de varias maneras dependiendo del

SGBD:

o

tabla1,tabla2,tabla3, …

o

tabla1 [INNER | CROSS] JOIN tabla2 [ON condición]

o

tabla1 LEFT [OUTER] JOIN tabla2 ON condición

o

tabla1 RIGHT [OUTER] JOIN tabla2 ON condición

o

tabla1: nombre_tabla[ [AS] alias]



La unión de las tablas relacionadas se realiza mediante el producto cartesiano

que genera como resultado todas las combinaciones posibles entre las filas y

columnas de todas las tablas que intervienen



Pag 159 y 160: al unir las tablas se producen repeticiones, que aprovechamos

para filtrar por coincidencias



Por tanto el producto cartesiano necesita un filtro



JOIN= PRODUCTO CARTESIANO + FILTRO



Ejemplo1: BD de MASCOTAS con tablas de propietarios y animales:

o

Seleccionar todas las filas en las que el dni del propietario coincida

con el propietario de la mascota

SELECT * FROM animales, propietarios

WHERE propietarios.dni=animales.propietario



Ejemplo2: BD de Jardinería. Abrir para ver relaciones o Pág 161

Obtener el listado de pedidos gestionados por cada empleado

SELECT Empleados.Nombre, Clientes.NombreCliente, Pedidos.CodigoPedido

FROM Clientes, Pedidos, Empleados

WHERE Clientes.CodigoCliente=Pedidos.CodigoCliente

AND Empleados.CodigoEmpleado=Clientes.CodigoEmpleadoRespVentas

ORDER BY Empleados.Nombre;



Ejemplo3: obtener cuántos pedidos ha gestionado cada empleado (idem al

ejemplo 2 pero agrupando por Nombre de empleados y ordenando por

NumeroDe Pedidos

SELECT Empleados.Nombre, Clientes.NombreCliente, Pedidos.CodigoPedido

FROM Clientes, Pedidos, Empleados

WHERE Clientes.CodigoCliente=Pedidos.CodigoCliente

AND Empleados.CodigoEmpleado=Clientes.CodigoEmpleadoRespVenta

GROUP BY Empleados.Nombre

ORDER BY NumeroDe Pedidos;

4.9.

COMPOSICIONES CON JOIN



Pueden ser: internas, externas y productos cartesianos

1.

Interna



De equivalencia: INNER JOIN



Natural: NATURAL JOIN

2.

Externa



De tabla derecha (RIGHT OUTER JOIN)



De tabla izquierda (LEFT OUTER JOIN)



Completa (FULL OUTER JOIN)

3.

Producto Cartesiano: CROSS JOIN

INNER JOIN



Es igual al separador de tablas ‘,’



Calcula

el

producto

cartesiano

de

todos

los

registros

de

las

tablas

que

combina, de manera que solo selecciona los que satisfacen las condiciones

establecidas



Hay que tener en cuenta que los valores nulos no se combinan



Las condiciones se establecen con ON Condición



Ejemplo1:

seleccionar

los

registros

de

la

tabla

animales

que

tengan

combinaciones ( coincidencias ) en la tabla propietarios.

SELECT * FROM animales INNER JOIN propietarios

ON animals.propietario= propietarios.dni;

Otra respuesta es:

SELECT * FROM animales, propietarios

WHERE animales.propietario=propietarios.dni;

NATURAL JOIN



Es una especialización de INNER JOIN



Compara todas las columnas que tengan el mismo nombre en ambas tablas

(todas las tablas especificadas)

Ejemplo: pag 165

SELECT CodigoEmpleado, Empleados.Nombre, Oficinas.Codigooficina, Oficinas.Ciudad

FROM Empleados NATURAL JOIN Oficinas;

CROSS JOIN



Devuelve el producto cartesiano de las tablas (todas las filas y todas las

columnas con valores repetidos

Ejemplo: pag 166

SELECT * FROM animales CROSS JOIN propietarios;

Otra respuesta: SELECT * FROM animales, propietarios;

OUTER JOIN



Las composiciones externas no requieren que haya una equivalencia entre las

tablas relacionadas



El registro es seleccionado para ser mostrado aunque no haya otro registro

que le corresponda



Dependiendo

de

donde

se

administren

los

registros

que

no

tienen

correspondencia se subdivide en

o

LEFT OUTER JOIN: los registros que no tienen correspondencia son los

que aparecen a la izquierda

Ejemplo pag 167:

SELECT * FROM animales LEFT OUTER JOIN propietarios

ON animales.propietario= propietarios.dni;

o

RIGHT OUTER JOIN: los registros que no tienen correspondencia son

los que aparecen a la derecha

Ejemplo pag 167

SELECT * FROM animales RIGHT OUTER JOIN propietarios

ON animales.propietario= propietarios.dni;

o

FULL OUTER JOIN: los registros que no tienen correspondencia son los

que aparecen tanto a la izquierda como a la derecha

SELECT * FROM animales FULL OUTER JOIN propietarios

ON animales.propietario= propietarios.dni;

MySQL no implementa FULL OUTER JOIN. Para ello realiza la UNION DE LEFT OUTER JOIN

Con RIGHT OUTER JOIN.

Ejemplo: pag 169

SELECT * FROM animales LEFT OUTER JOIN propietarios

ON animales.propietario=propietarios.dni

UNION

SELECT * FROM animales RIGHT OUTER JOIN propietarios

ON animales.propietario=propietarios.dni

4.10.

CONSULTAS REFLEXIVAS



Son consultas donde se hace una JOIN entre los registros de la misma tabla



Ejemplo pag 169: obtener el nombre y apellidos de los empleados, junto con

el nombre y apellidos de su jefe

SELECT CONCAT (emp.Nombre, ‘ ‘ , emp.Apellido1) AS Empleado,

CONCAT (jefe.Nombre, ‘ ‘ , jefe.Apellido1) AS jefe

FROM Empleados emp INNER JOIN Empleados jefe

ON emp.codigoEmpleado=jefe.CodigoJefe;

4.11.

CONSULTAS CON TABLAS DERIVADAS (INLINE VIEWS)



Obtiene información relacionada de forma más avanzada



Utilizan sentencias SELECT en la cláusula FROM en lugar de nombres de tablas



Hay que distinguir entre la tabla derivada( tabla temporal) que tiene un alias

para distinguirla de la tabla principal



Ejemplo: BD de jardinería. Obtener el importe del pedido de menor coste de

todos los pedidos.

o

Se debe obtener el total de todos los pedidos y después sobre los

resultados se obtendrá el valor menor

SELECT MIN(total) FROM

(SELECT SUM(Cantidad*PrecioUnidad) AS total, CodigoPedido

FROM DetallePedidos

GROUP BY CodigoPedido)

AS TotalPedidos;

PRÁCTICAS DEL LIBRO PAG 176

PRÁCTICAS RESUELTAS

PRÁCTICAS PROPUESTAS

Comentario [a7]:

alias de

Empleado, es como una tabla virtual

Comentario [a8]:

alias de jefe, tabla

virtual para la consulta reflexiva

Comentario [a9]:

es la tabla

derivada formada por el resultado de la

consulta entre paréntesis







TEMA 5: TRATAMIENTO DE LOS DATOS

CONTENIDOS:



Herramientas gráficas



Sentencias para insertar, modificar y borrar registros

o

INSERT

o

UPDATE

o

DELETE



Transacciones



Acceso concurrente a los datos



Vistas



Usuarios



Privilegios

1.

HERRAMIENTAS GRÁFICAS PARA LA EDICIÓN DE DATOS

Se genera el código SQL automáticamente

ACCESS



Creación de formularios

o

Usando asistentes

o

En vista diseño



PRÁCTICA: En Cursaccess01:

1.

elaborar formularios usando asistente:

o

crear, formulario, asistente para formulario

o

seguir pasos

2.

añadir datos en el formulario

Phpmyadmin



Pestaña insertar



Seleccionar tabla



Rellenar valores



Continuar



Pestaña examinar para eliminar o modificar registros



PRÁCTICA: descargar y realizar formularios

2.

ACCESS COMO ENTORNO GRÁFICO PARA OTROS GESTORES



Se

hace

a

través

de

conectores

ODBC

(Open

DataBase

Connectivity)



ODBC

o

Herramienta

que

de

forma

estándar

permite

conectar

aplicaciones a cualquier SGBD

o

Instalar el driver ODBC para ese SGBD

o

Se crea una DNS(Data Source Name) (referencia a cierta

base de datos)



Windows:

panel

de

control,

herramientas

administrativas,

opción orígenes de datos ODBC, creación de origen de datos

ODBC en mysql , rellenar campos, data source name

ACTIVIDAD 5.1: Descargar desde mysql.org el apartado Download

Connectors, el conector ODBC e instalarlo en el ordenador.

Conectar la BD DE la jardinería dese la máquina virtual disponible en la

página web www.garceta.es

3.

SENTENCIA INSERT



Añadir registros a una tabla



Sintaxis

INSERT [INTO] nombre_tabla

*(nombre_campo1, nombre_campo2, …)+

VALUES

(valor_campo1 | default, valor_campo2 | default, …);



Los nombres de campos son opcionales.



Si no se especifican los nombres de campos, la lista de valores se

escribirá conforme al orden especificado en la definición de la

tabla



Se pueden especificar columnas concretas

o

Ejemplo: insertar en la tabla de mascotas el registro

(1,’Pequitas’, ‘Gato Común europeo’)

INSERT INTO mascotas (código, nombre, raza)

VALUES

(1,’Pequitas’, ‘Gato Común europeo’);



Las columnas no especificadas contendrá valor NULL.



Default:

si

queremos

utilizar

el

valor

por

defecto

que

se

especificó cuando se creó la tabla



Especificar varios registros a la vez, separados por coma

INSERT [INTO] nombre_tabla

*(nombre_campo1, nombre_campo2, …)+

VALUES

(valor_campo1 | default, valor_campo2 | default, …),

(valor_campo1 | default, valor_campo2 | default, …),

(valor_campo1 | default, valor_campo2 | default, …),

….

(valor_campo1 | default, valor_campo2 | default, …);



INSERT Y SELECT: en lugar de especificar valores, se extraen de

una consulta

INSERT [INTO] nombre_tabla

Consulta con los registros necesarios.

EJEMPLO: crear en zoológico la tabla copia y llenarla con los registros

de las mascotas.

CREATE TABLE copia ( nombre varchar(20), propietario varchar(20),

especie

varchar(20),

sexo

varchar(1),

nacimiento

date,

fallecimiento date);

INSERT INTO copia select * from mascotas;

4.

SENTENCIA UPDATE



Modifica el contenido de la tabla



Sintaxis

UPDATE nombre_tabla

SET campo1=expresión [, campo2=expresión]

[WHERE filtro]



Si se omite el filtro se aplica a todos los registros

EJEMPLOS:

1.

Cambiar el peso de libras a kilos de todos los jugadores

UPDATE jugadores SET peso=peso*0.4535;

UPDATE jugadores SET peso=peso/0.4535;

2.

Modificar la procedencia del jugador ‘Pau Gasol’

UPDATE jugadores SET procedencia = 'Italia'

WHERE nombre='Pau Gasol';

UPDATE jugadores SET procedencia = 'Spain'

WHERE nombre='Pau Gasol';

3.

Modificar el peso y la procedencia del jugador ‘Pau Gasol’

UPDATE jugadores SET procedencia = 'Italia', Peso=100

WHERE nombre='Pau Gasol';

UPDATE jugadores SET procedencia = 'Spain', Peso=249

WHERE nombre='Pau Gasol';

5.

SENTENCIA DELETE



Borra registros de una tabla



Sintaxis:

DELETE FROM nombre_tabla

[WHERE filtro]

Ejemplo:

insertar

en

zoológico

una

mascota

y

borrarla

posteriormente

INSERT INTO mascotas (nombre) VALUES ('kira');

DELETE FROM mascotas WHERE nombre='kira';

6.

ACTUALIZAR Y BORRAR UTILIZANDO CONSULTAS

EJEMPLO1: En la BD de la jardinería eliminar los empleados que no

tengan clientes. ( creamos una base de datos para las eliminaciones

y modificaciones)

create database anajardineria1;

use anajardineria1

source ruta_archivo

COMPROBAMOS LOS DATOS

TODOS LOS EMPLEADOS

select * from empleados;

EMPLEADOS QUE TIENEN CLIENTES

Select codigoempleado from Empleados where codigoempleado in

(select

codigoempleadorepventas

from

Clientes)

and

puesto

like

'Representante Ventas';

EMPLEADOS QUE NO TIENEN CLIENTES

Select codigoempleado from Empleados where codigoempleado not in

(select

codigoempleadorepventas

from

Clientes)

and

puesto

like

'Representante Ventas';

BORRAMOS LOS REGISTROS

delete

from

Empleados

where

codigoempleado

not

in

(select

codigoempleadorepventas

from

Clientes)

and

puesto

like

'Representante Ventas';

7.

SENTENCIAS UPDATE Y DELETE CON SUBCONSULTAS



Limitación: no se permite realizar cambios en la tabla que se lee

en la subconsulta



Ejemplo de borrado posible: el caso anterior



Ejemplo

de

borrado

imposible:

borrar

los

clientes

con

limitecredito=0

DELETE FROM Clientes WHERE Codigocliente IN

(SELECT Codigocliente FROM Clientes WHERE limitecredito=);

8.

BORADO Y MODIFICACIÓN DE REGISTROS CON RELACIONES



No es posible modificar o borrar directamente registros que

participen en relaciones



El SGBD nos informará de ello



Ejemplo:

borrar

nombre

de

cliente

que

tiene

pagos

pendientes



Surgen

problemas

al

intentar

borrar

o

modificar

la

clave

primaria o clave foránea.



LA

CREACIÓN

DE

TABLAS,

CON

CLAVES

PRIMARIAS

Y

FORÁNEAS es necesario utilizar la cláusula REFERENCES

SINTAXIS

REFERENCES nombre_tabla *(nombre_campo, ….)+

[ON DELETE opción_referencia]

[ON UPDATE opción_referencia ]

Opción_referencia

CASCADE|SET NULL| NO ACTION

ON DELETE, ON UPDATE : personalizan el comportamiento para el

borrado y actualización respectivamente.

CASCADE: permite modificar y borrar las claves primarias y foráneas,

de

manera

que

se

realizan

cambios

en

todas

las

tablas

que

aparecen.

SET NULL: permite modificar y borrar pero el registro permanece con

valores nulos o vacíos.

NO ACTION: no permite ni borrado ni modificaciones. Es aconsejable

para las claves primarias.

PRÁCTICA:



Realizar ejercicio propuesto de Pag 195 libro.



Las tablas deben ser innodb para soportar FOREING KEY



Crear bd comercial.

#crar la base de datos

Create database comercial;

Use comercial

1.

Creamos las tablas

create

table

clientes

(

dni

varchar(15)

PRIMARY

KEY,

nombre

varchar(50), direccion varchar(50)) engine = innodb;

create

table

pagos_pendientes(

dni

varchar(15),

importe

double,

FOREING

KEY

(dni)

REFERENCES

clientes(dni)

ON

DELETE

NO

ACTION ON UPDATE NO ACTION) engine=innodb;

2.

Insertamos valores

insert

into

clientes

values

('5555672L','PEPE

CIFUENTES','C/

LOS

ALMENDROS 23');

insert into pagos_pendientes values ("5555672L", 500);

insert into pagos_pendientes values ( "5555672", 234.5);

ERROR 1452 (23000): Cannot add or update a child row: a foreign key

constraint

fails

(`comercial`.`pagos_pendientes`,

CONSTRAINT

`pagos_pendientes_ibfk_1`

FOREIGN

KEY

(`dni`)

REFERENCES

`clientes` (`dni`) ON DELETE NO ACTION ON UPDATE NO ACTION)

3.

Borramos cliente: no es possible

delete from clientes where dni= "5555672L";

ERROR 1451 (23000)

4.

Modificar dni del cliente: no es posible

update clientes set dni="55555555L" where dni="5555672L";

ERROR 1451

5.

Borrar tabla clientes: no es posible

drop table clientes;

ERROR 1217 (23000): Cannot delete or update a parent row: a foreign

key constraint fails

6.

Realizar los ejercicios anteriores creando las tablas para cambiar las

restricciones a:

on delete cascade on update cascade

PRÁCTICAS RESUELTAS

5.1 Inserciones, Actualizaciones y Borrados

5.2 Actualizaciones y borrados con subconsultas

PRÁCTICAS PROPUESTAS

5.3 Vincular tablas a través de Access /ODBC

5.4 Actualizaciones y borrados variados

9.

TRANSACCIONES



Son conjuntos de sentencias SQL que se tratan como una sola

instrucción



Son esenciales para mantener la integridad de los datos



Garantiza la atomicidad de la operación: o se hacen todas las

operaciones o no se hace ninguna



Pueden ser:

o

Confirmadas: commit

o

Abortadas: rollback



Por

defecto

el

SGBD

tiene

activado

el

modo

AUTOCOMMIT=ON

(cada

comando

SQL

se

considera

una

transacción independiente)



AUTOCOMMIT=OFF :

o

activa las transacciones de múltiples sentencias

o

todos los comandos SQL tendrán que terminarse con la

orden COMMIT o ROLLBACK

o

algunos

SGBD

requieren

de

las

órdenes

START

TRANSACTION

o

START

WORK

para

indicar

que

comience o termine una transacción



EN mysql: 3 formas de comenzar una transacción

o

SET AUTOCOMMIT=0

o

START TRANSACTION

o

BEGIN WORK



Aceptar cambios: COMMIT WORK;



Cancelar cambios: ROLLBACK WORK;



Ejemplo:

Realizar

la

siguiente

transacción

en

la

BD

de la

jardinería:

Actualizar el stock para disminuirlo en 2 unidades, insertar un

pedido, insertar el detalle del pedido.

#COMENZAR TRANSACCIÓN

SET AUTOCOMMIT=0;

#DISMINUIR EN 2 LA CANTIDADENSTOCK

update Productos set Cantidadenstock=Cantidadenstock-2

where cantidadenstock between 150 and 200;

#INSERTAR EL PEDIDO

insert into Pedidos values (425,now(),now(),now(), "pendiente "," ", 1);

#INSERTAR

DETALLE

DEL

PEDIDOSinsert

into

DetallePedidos

values

(425,"FR-67",20,100,1);

#ACEPTAR CAMBIOS;

COMMIT WORK;

10.

ACCESO CONCURRENTE A LOS DATOS

Alumnos:

Realizar documento o presentación con los problemas de acceso

concurrente con ejemplos



Ocurren

cuando

se

accede

al

mismo

dato

en

2

o

más

transacciones distintas.

Los problemas del acceso concurrente son:

1.

Dirty Read(Lectura sucia): una transacción lee datos escritos por

una transacción que no ha hecho COMMIT.

2.

Nonrepeatable

Read(Lectura

no

repetible):

una

transacción

vuelve a leer datos que leyó previamente y encuentra que han

sido modificados por otra transacción.

3.

Phantom Read (Lectura fantasma). Una transacción lee unos

datos que no existían cuando se inició la transacción.



Cuando se trabaja con transacciones, se pueden bloquear

conjuntos

de

datos

para

evitar

o

permitir

los

problemas

anteriores.



Según el nivel de concurrencia, se puede solicitar 4 niveles de

aislamiento



Nivel de aislamiento define cómo los cambios hechos por una

transacción son visibles a otras transacciones

1.

Read Uncommited(Lectura no acometida).



Permite que sucedan los tres problemas anteriores.



Las sentencias SELECT son efectuadas sin realizar bloqueos



Todos los cambios hechos por una transacción pueden verlos

las otras transacciones

2.

Read Commited(Lectura acometida).



Los datos leídos por una transacción pueden ser modificados

por otras transacciones



Se pueden dar los problemas 2 y 3

3.

Repeatable Read (Lectura Repetible)



Ningún registro leído con un SELECT se puede cambiar en otra

transacción.



Se permite el problema 3

NIVEL DE AISLAMIENTO EN MYSQL



Las tablas innodb por defecto tienen nivel REPEATABLE READ



Para variar el nivel de aislamiento:

o

Cambiando el fichero de configuración my.cnf

o

Ejecutando

SET TRANSACTION ISOLATION

LEVEL

{

READ

UNCOMMITTED

|

READ

COMMITTED

|

REPEATABLE READ | SERIALIZABLE}

EJEMPLOS PAGINA 200 del libro.

11.

ACCESO A LA INFORMACIÓN



Es

necesario

administrar

la

seguridad

en

el

acceso

a

la

información



Existen 2 tipos de seguridad:

o

Integrada por el sistema operativo

o

Proporcionada por el SGBD o seguridad nativa

12.

LAS VISTAS

DEFINICIONES



Es una tabla virtual, sin contenido



Devuelve el resultado de ejecutar una consulta SQL



Es una consulta cuya definición ha sido almacenada y compilada

previamente, por tanto su tiempo de ejecución es menor



Permite restringir el acceso a los usuarios a determinadas tablas

CREACIÓN DE VISTAS

SINTAXIS

CREATE

[OR

REPLACE]

VIEW

[esquema.]

nombre_vista

[(lista_columnas)] AS sentencia_select

OR REPLACE: cuando la vista ya existe y queremos reemplazarla

Lista_columnas: cada columna tendrá el alias que se indique. Si no se

especifica,

el

nombre

de

las

columnas

será

el resultado

de

la

consulta

Ejemplo:

create view jugadoresmi as select nombre, posicion, nombre_equipo

from jugadores where nombre_equipo='Heat';

select * from jugadoresmi;

BORRADO DE VISTAS

DROP VIEW nombre_vista;

MODIFICAR VISTAS

ALTER VIEW nombre_vista ….

13.

USUARIOS

Acceden a los objetos de la BD con cierto nivel de privilegios

CREAR

CREATE USER nombre_usuario IDENTIFIED BY ‘password’ *opciones+;

Ejemplo:

CREATE USER paco IDENTIFIED BY ‘123456’;

ACTIVIDAD

5.3.

CREAR

USUARIO

Pedro

y

Javier

con

password

apropiados.

BORRAR

DROP USER nombre_usuario [CASCADE];

CASCADE: para indicar que junto con el usuario se borren los objetos

de su esquema.

Se pueden borrar varios usuarios separados por comas.

MODIFICAR

Es necesario actualizar sus datos en la tabla mysql.user del sistema

UPDATE mysql.user

SET cambios;

FLUSH PRIVILEGES;

FLUSH PRIVILEGES: fuerza al gestor:



a leer las tablas de permisos



los cambios en los permisos sean efectivos desde ese momento

Ejemplo: cambiar el host desde el que el usuario Javier se puede

conectar.

UPDATE mysql.user

SET host=’192.168.3.1’ WHERE USER=’Javier’;

FLUSH PRIVILEGES;

RENOMBRAR

Renombrar usuario

RENAME USER nombre_usuario1 TO nombre_usuario2;

Renombrar password

SET PASSWORD FOR password1=PASSWORD(‘password2’);

Actividad 5.4: modificar usuario

UPDATE mysql.user

SET PASSWORD=PASSWORD(“Nuevo”)

WHERE USER=’Paco’ AND host=’localhost’;

Actividades consolidación:

1.

Crear usuario con vuestro nombre y password el mismo nombre

create user ana identified by 'ana';

2.

salir de mysql y volver a entrar como el usuario creado

14.

PRIVILEGIOS

Permiten manipular los objetos de la base de datos.

GRANT

Quitar privilegios

REVOKE

14.1.

SISTEMA DE PRIVILEGIOS EN MYSQL

GRANT tipo_privilegio *(columnas)+ *, tipo_privilegio*(columnas)++ …

ON

{nombre_tabla |*|*.*|base_datos.* |base_datos.nombre_tabla}

TO nombre_usuario [IDENTIFIED BY [PASSWORD]’password’]

[, nombre_usuario1 *IDENTIFIED BY *PASSWORD+’password’+ +…

[WITH opcion *,opcion++…

Tipo_privilegio: clase de permiso que se puede otorgar:

Select |insert | update | otros

Otros: página 210 libro.

Los tipos de privilegios se pueden aplicar a los siguientes objetos:



nombre_tabla: una tabla concreta



*: todas las tablas de la BD



*.*: todas las tablas de todas las BBDD



base_datos.* : todas las tablas de la BD especificada



base_datos.nombre_tabla:

la

tabla

especificada

de

la

BD

especificada

Opcion=

GRANT OPCION

|MAX_QUERIES_PER_HOUR count

|MAX_UPDATES_PER_HOUR count

|MAX_CONNECTIONS_PER_HOUR count

|MAX_USER_CONNECTIONS count

GRANT OPCION: concede a otros usuarios los permisos que tiene el

usuario. Si el root concede GRANT OPCION a los usuarios que cree

le otorga los mismos permisos que él

MAX_QUERIES_PER_HOUR count: restringe el número de consultas

por hora que realiza el usuario

|MAX_UPDATES_PER_HOUR

count:

restringe

el

número

de

modificaciones por hora que realiza el usuario

|MAX_CONNECTIONS_PER_HOUR count: restringe el número de

conexiones login por hora que realiza el usuario

|MAX_USER_CONNECTIONS count: limita el número de conexiones

simultáneas que puede realizar el usuario.

Ejemplos:

1.

Otorgar

permisos

al

usuario

Paco

para

que

sólo

pueda

seleccionar las columnas NombreCliente, Telefono, Ciudad de

la tabla Clientes

GRANT SELECT (NombreCliente, Telefono, Ciudad)

ON Clientes TO Paco;

2.

Otorgar permisos de select e insert a todas las tablas de la BD

de la NBA al usuario Paco.

GRANT SELECT, INSERT ON nba.* TO Paco;

3.

Otorgar

todos

los

privilegios

a

la

tabla

Clientes

de

la

BD

JARDINERIA

GRANT ALL PRIVILEGES ON jardinería.Clientes TO Paco;

4.

Otorgar permisos de select a todas las tablas de todas las bases de

datos, permitiendo al usuario ceder esos permisos a otros usuarios

GRANT SELECT ON *.* TO Paco WHITH GRANT OPTION;

5.

Otorgar permisos de SELECT, INSERT, UPDATE , DELETE con un

límite de 10 consultas a la hora en la tabla jugadores de la NBA

GRANT SELECT, INSERT, PUDATE, DELETE ON nba.jugadores

TO Paco

WITH

MAX_QUERIES_PER_HOUR

10

MAX_UPDATES_PER_HOUR

10;

DENEGAR PERMISOS A USUARIOS

REVOKE tipo_privilegio *(columnas)+ *, tipo_privilegio*(columnas)++ …

ON

{nombre_tabla |*|*.*|base_datos.* |base_datos.nombre_tabla}

FROM usuario [, usuario1] …

Ejemplos:

1.

Quitar el permiso de select a la tabla jardinería.Cliente al usuario

Paco.

REVOKE SELECT ON jardinería.Clientes FROM Paco;

2.

Elimina el permiso ALL PRIVILEGES de todas las tablas al usuario

Paco.

REVOKE ALL PRIVILEGES ON *.* FROM Paco;

3.

Quitar

los

permisos

de

select

e

insert

de

todas

las

tablas

de

jardinería al usuario Paco.

REVOKE SELECT, INSERT ON jardinería.* FROM Paco;



