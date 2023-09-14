---
layout: page
title: 1. Bases de datos
permalink: /bases-de-datos/
nav_order: 1
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 1. Bases de datos
{: .no_toc }

- TOC
{:toc}

## 1.1. Almacenamiento de la información

### 1.1.1. Sistemas lógicos de almacenamiento

Desde los primeros tiempos de la informática ha sido necesario **almacenar grandes cantidades de información** en soportes fisicos utilizando mecanismos que fueran independientes del propio soporte. 

Esos métodos de almacenamiento se denominan **sistemas de almacenamiento lógico**. 

![Sistema de almacenamiento físico del IBM 360](/docs/prog-y-3d/_site/assets/images/07-01-dispositivo-almacenamiento-fisico.jpg)
<span style='font-size: 70%; font-color: grey'><i>Sistema de almacenamiento físico del IBM 360, un ordenador de la década de 1960. Este ordenador utilizaba principalmente cintas magnéticas en lugar de discos duros para almacenar la información. En teoría, los usuarios no deberían ser conscientes de ello. Los sistemas de almacenamiento lógico nos permiten olvidarnos de cuál es el dispositivo físico donde se almacena realmente la información.</i></span>

El sistema lógico de almacenamiento más habitual es el **sistema de ficheros**. En él, la información se organiza en **directorios** (o carpetas) y **ficheros**, y luego un componente software del sistema operativo se encarga de traducir las operaciones lógicas sobre la información (por ejemplo, añadir un dato al final de un fichero) en operaciones físicas (por ejemplo, escribir un byte en determinado sector del disco duro).

Las bases de datos que estudiaremos en este capítulo también son sistemas lógicos de almacenamiento, solo que más complejos que los sistemas de ficheros. El componente software encargado de traducir operaciones lógicas en físicas se denomia **sistema gestor de bases de datos**, y en este capítulo y el siguiente vamos a aprender a familiarizarnos con él.

### 1.1.2. Sistemas de ficheros

Antes de comenzar a pelearnos con las bases de datos, conviene conocer por encima a su hermano pobre: el sistema de ficheros.

Los **archivos o ficheros** son almacenes de información con una estructura determinada que se organizan en directorios (o carpetas) con organización jerárquica.

Existen muchos sistemas de ficheros, dependiendo del sistema operativo: 

* **FAT16**: del antiguo MS-DOS y Windows 95. 
* **FAT32**: se introdujo en Windows 95 OSR2 y aún se usa masivamente a pesar de sus limitaciones. ¿Qué limitaciones son esas? Por ejemplo, no puede menejar archivos de más de 4 GB.
* **exFAT**: un sistema FAT extendido, sin las limitaciones de FAT32, usado por Windows de forma nativa desde Windows 7. Generalmente se utiliza en memorias USB. 
* **NTFS**: usado por los sistemas Windows desde Windows NT. 
* **ext2**, **ext3** y **ext4**: sistemas por defecto en la mayoría de las distribuciones Linux.  
* **ReiserFS**: otro sistema de ficheros soportado por las distribuciones Linux. 
* **CDFS** o **ISO 9660**: Es el sistema de ficheros nativo de los CD-ROM. 
* **UDF** o **ISO 13346**: Es un sistema de ficheros estandarizado usado en CDs, DVDs y Blu-Rays. 
* **HFS+**: sistema de ficheros nativo de MacOS.  

Los ficheros, a su vez, pueden ser de diferente tipo, según cómo se codifique la información en su interior:

* **Ficheros de texto**: almacenan la información como texto, generalmente codificado como UTF-8. Estos ficheros pueden contener información de configuración de aplicaciones (ficheros .ini, .inf, .conf, etc), de código fuente (.html, .sql, .java, .php, etc), de texto plano o enriquecido (.txt, .rtf, .ps, etc) o información compleja codificada como XML o JSON (.xml, .json).
* **Ficheros binarios**: son colecciones de bits con un formato específico que sólo pueden ser interpretadas por el programa adecuado. Hay incontables tipos de fichero binario: de imagen (.jpg, .gif, .png, etc), de vídeo (.avi, .mpg, .mp4, etc), comprimidos o empaquetados (.zip, .rar, .tar, .gz, etc), ejecutables y compilados (.exe, .com, .o, etc) y muchísimos más.

Cada programa suele tener su propio formato de fichero nativo. Y los gestores de bases de datos no son una excepción. Por ejemplo

* Access guarda las bases de datos en un fichero con extensión .mdb o .accdb 
* MySQL guarda las bases de datos en tres ficheros de extensión .frm, .myd y .myi 

### 1.1.3. Bases de datos

Una **base de datos** es una colección de ficheros relacionados entre sí que almacenan tanto la representación abstracta de un fragmento de información del mundo real como los datos correspondientes a ese fragmento del mundo. 

Las bases de datos, por lo tanto, son sistemas de almacenamiento de información más complejos y elaborados que los ficheros, puesto que no solo guardan la información en sí, sino también la forma en la que unos datos se relacionan con otros, y además proporcionan mecanismos para manipular esos datos.

No se debe confundir la *base de datos* (los ficheros que guardan la información) con el *sistema gestor de base de datos* (el software que manipula esos ficheros). 

Existen varios tipos de bases de datos, pero las más extendidas desde hace décadas son las **bases de datos relacionales**. Durante este capítulo y el siguiente, nos referiremos exclusivamente a este tipo de bases de datos.

#### Sistemas gestores de bases de datos

Un **Sistema Gestor de Bases de Datos** (**SGBD** o **DBMS** en inglés) es el programa (o conjunto de programas) encargados de almacenar y manipular la información de una base de datos. 

Las **funciones** de un SGBD son:

* Permitir el acceso sencillo y eficiente a los datos 
* Garantizar la integridad de los datos 
* Garantizar la seguridad de los datos 
* Almacenar no solo los datos, sino la estructura de los mismos y la forma en la que se relacionan unos con otros
* Mantener estadísticas de uso 
* Permitir la concurrencia de usuarios (accesos múltiples simultáneos) 
* Independizar los datos físicos de las aplicaciones de usuario 
* Ofercer conectividad con el exterior 
* Incorporar herramientas de copia de seguridad 

Existen muchos sistemas gestores de bases de datos relacionales, algunos creados para manejar de forma sencilla bases de datos pequeñas y con pocos accesos, como **Microsoft Access** o **Libreoffice Base**, y otros pensados para soportar grandes volúmenes de información y muchos accesos simultáneos, como **MySQL**, **MariaDB**, **Oracle**, **SQL Server** o **PostgreSQL**.

#### Conceptos clave en bases de datos relacionales

Si hablamos exclusivamente de **bases de datos relacionales** (recuerda: existen otros tipos, pero las mayoritarias son las relacionales), hay ciertos conceptos que van a aparecer de forma recurrente a partir de ahora.

Vamos a definirlos, pero no trates de retenerlos todos: te familiarizarás con ellos poco a poco a lo largo del capítulo.

* **Tabla (o relación)**: la información en las bases de datos relacionales se organiza en tablas compuestas por filas y columnas.
* **Registro**: un registro es cada una de las filas de cada tabla. Por ejemplo, en la base de datos de los clientes de una empresa, la tabla de clientes contendrá un cliente en cada fila. Pues bien, cada fila es un *registro*.
* **Campo**: cada registro puede descomponerse casi siempre en fragmentos más pequeños. Por ejemplo, en la tabla de clientes, para cada cliente podemos almacenar su DNI, su nombre, sus apellidos, su domicilio, email, teléfono, etc. Cada uno de estos fragmentos de información se denomina *campo*.
* **Tipo de dato**: es el dominio al que pertenece cada dato almacenado en cada campo, es decir, el tipo de dato (número entero, número real, cadena de caracteres, fecha, hora, etc)
* **Campo clave**: es un campo que permite diferenciar unívocamente cada registro. Por ejemplo, el DNI es un posible campo clave de la tabla de clientes.
* **Consulta**: las consultas sirven para buscar y extraer información de la base de datos. Son un mecanismo muy sencillo para hacer algo muy complicado: bucear entre toneladas de información para localizar justo lo que buscamos.
* **Índice**: la base de datos construirá índices para acelerar el acceso a las tablas más voluminosas. Es un mecanismo interno de la base de datos que casi nunca necesitaremos manipular. 

#### Componentes de una base de datos relacional

Los SGBD relacionales son programas muy complejos. Tanto que, independientemente de su desarrollador, suelen tener varios componentes:

* **Lenguaje de definición de datos (DDL)**: nos permite crear la representación lógica de los datos y sus relaciones. 
* **Lenguaje de control de datos (DCL)**: sirve para gestionar los permisos de acceso. 
* **Lenguaje de control de transacciones (TCL)**: se utiliza para asegurar la integridad de los datos. 
* **Lenguaje de manipulación de datos (DML)**: nos permite insertar datos, borrarlos, modificarlos, etc. Pueden ser lenguajes procedimentales (el programador indica cómo se van a manipular los datos) o no procedimentales (el programador indica qué manipulación desea, y el SGBD se encarga de determinar los procedimientos más apropiados).
* **Diccionario de datos**: es una base de datos especial, porque contiene información sobre el resto de bases de datos existentes en el sistema. 
* **Motor o monitor de la base de datos**: es el interfaz entre los datos y los programas de usuario. Se encarga del acceso seguro, íntegro y eficiente a los datos físicos. 
* **Administrador de la base de datos (DBA)**: es la persona encargada de controlar la privacidad y seguridad de los datos y realizar el mantenimiento de la base de datos. 

En el resto del capítulo aprenderemos a usar algunos de estos componentes y, en particular, nos centraremos en el lenguaje DML (de manipulación de datos), que es el que se utiliza la gran parte del tiempo que estamos trabajando con una base de datos. La implementación más popular de DML es, sin duda, el **lenguaje SQL**, al que dedicaremos bastante tiempo.

## 1.2. El modelo de datos

Antes de aprender el lenguaje SQL, tenemos que hacer otra cosa que muchos programadores detestan: **diseñar la base de datos** con la que vamos a trabajar.

O, al menos, conocer un par de reglas básicas de diseño de bases de datos para poder afrontar con éxito la creación de bases de datos sencillas y para poder interpretar los diseños de otros programadores.

Un **modelo de datos** es una simplificación (o *modelización*) de la parte del mundo que queremos convertir en una base de datos.

Dicho de otra manera, los modelos de datos se parecen a los planos de una casa que traza un arquitecto: no son la casa en sí, sino una representación de la misma, y su objetivo es poder construir la casa conforme a unas especificaciones dadas.

### 1.2.1. Diagramas E-R

Los **diagramas E-R** o **diagramas entidad-relación** son una representación gráfica de los datos del mundo real que pretendemos modelar.

¿Has visto alguna vez los planos de un arquitecto para una casa? El arquitecto no se limita a dibujar la planta de la casa, sino que elabora multitud de planos diferentes de la misma casa: instalaciones, cimentación, evacuación de agua, etc.

Pues bien, para crear una aplicación informática, los "arquitectos" (que, en informática, se denominan **ingenieros**) también elaboran multitud de "planos" diferentes de la misma aplicación. **El diagrama E-R es uno de esos "planos"**.

No es labor del programador elaborar esos planos. Siguiendo con la analogía anterior, si el ingeniero informático es como el arquitecto, en programador es como el albañil. Es decir, el programador se limita a seguir los planos que le facilita el arquitecto y, en todo caso, a realizar alguna pequeña corrección o sugerencia sobre el terreno.

Entonces, si el diagrama E-R pertenece al dominio de la ingeniería informática, ¿por qué tenemos que aprender a hacerlos?

Por una razón muy sencilla: si la aplicación es pequeña, no suele existir un proceso de ingeniería previa (igual que no contratamos a un arquitecto para construir la caseta del perro). Y es el programador/a quien debe hacer todo el trabajo.

De entre todos los "planos" de la aplicación, el diagrama E-R es uno de los más importantes, sobre todo si hablamos de aplicaciones web. Así que es muy conveniente que aprendas a elaborarlos y a interpretarlos. Además, son muy sencillos de hacer.

### 1.2.2. Elementos de los diagramas E-R

Los símbolos concretos de los diagramas E-R puede diferir ligeramente entre metodologías, pero en realidad significan lo mismo. Aquí veremos los llamados **diagramas de Chen**, por el taiwanés Peter P. Chen, que fue quién los creó en 1976 cuando trabajaba en la Universidad de Harvard (EEUU) y que son de los más extendidos en la industria.

Son diagramas tan, tan sencillos, que se elaboran con solo tres elementos:

Elemento|Significado|Símbolo
-|-|-
Entidades|Son los datos de interés para el sistema: categorías de objetos reales o abstractos de los que se necesita mantener información|![Diagramas ER - Entidades](/docs/prog-y-3d/_site/assets/images/07-02-diagramas-er-entidades.png)
Atributos|Son las características propias de las entidades. Cada entidad puede tener varios atributos asociados|![Diagramas ER - Atributos](/docs/prog-y-3d/_site/assets/images/07-02-diagramas-er-atributos.png)
Relaciones|Son las conexiones lógicas entre las entidades. Representan relaciones que existen en el mundo real y que son relevantes para nuestra aplicación|![Diagramas ER - Relaciones](/docs/prog-y-3d/_site/assets/images/07-02-diagramas-er-relaciones.png)

Aquí te dejo un ejemplo de diagrama E-R. ¡No te asustes! No vas a tener que hacerlos, solo comprenderlos.

![Ejemplo de diagrama ER](/docs/prog-y-3d/_site/assets/images/07-02-diagramas-er-ejemplo.png)

En este diagrama:

* *LIBROS, BIBLIOTECAS* o *SOCIOS* son **entidades**. Representan los datos que queremos almacenar.
* *entán en*, *tienen* o *préstamos* son **relaciones**. Representan cómo los datos del mundo real se relacionan entre sí.
* Cada entidad (y algunas relaciones) tienen su propios **atributos**. Por ejemplo, la entidad *LIBROS* tiene como atributos *cod_libro*, *titulo* o *sinpsis*. Son fragmentos de información que pertenecen a esa entidad o relación.
* En las relaciones puedes ver unos números. Esos números se refieren a la **cardinalidad** o cantidad de elementos de cada entidad que participan en una relación. Por ejemplo, entre *LIBROS* y *BIBLIOTECAS* puedes ver la cardinalidad (1,N) en el lado *LIBROS*. Eso significa que *cada biblioteca tiene entre 1 y muchos (N) libros*. En el otro lado puedes ver (0,N), lo que significa que *cada libro puede estar en 0 o muchas (N) bibliotecas*. La cardinalidad global de esta relación se obtiene con el máximo de cada uno de los lados. Por eso se dice que la relación *está en* tiene una cardinalidad N:N o de "muchos a muchos".

## 1.3. Paso del diagrama E-R al modelo relacional

Los diagramas E-R son una herramienta para representar gráficamente el **modelo conceptual** de una base de datos. Es decir, para crear un modelo abstracto y no ambiguo de la realidad.

Pero un diagrama E-R no se puede implementar directamente en un ordenador. Antes hay que convertirlo a un **modelo lógico**, es decir, a un modelo implementable en un ordenador.

El modelo lógico más popular desde hace décadas es el **modelo relacional**. En esta sección vamos a ver en qué consiste y cómo convertir nuestros diagramas E-R en tablas relacionales que podamos transformar en bases de datos reales.

### 1.3.1. Qué es el modelo relacional

El **modelo relacional** es una de las posibles maneras de convertir un diagrama E-R en una base de datos real que pueda funcionar en un ordenador. Además, es la más extendida desde hace décadas.

Consiste en convertir las entidades y relaciones a **tablas bidimensionales**. Esas tablas también se llaman **relaciones**, lo cual puede inducir a errores, porque en los diagramas E-R llamábamos relaciones a la conexiones entre entidades.

Para evitar confusiones, nosotros llamaremos **tablas** a las relaciones del modelo relacional.

Por lo tanto, **en el modelo relacional *toda la información se almacena en tablas***:

* Cada tabla está compuesta por **filas**, que se llaman **registros** o **tuplas**.
* Cada tabla tiene **columnas**, denominadas **campos**.
* Cada **campo** tiene asignado un **dominio** o tipo de datos (número entero, número real, cadena de caracteres, etc).
* Cada registro contiene la información correspondiente a una ocurrencia de una entidad o de una relación del diagrama E-R. Por ejemplo, la entidad CLIENTES puede convertirse en una tabla como esta:

![Ejemplo de relación jerárquica inclusiva parcial](/docs/prog-y-3d/_site/assets/images/07-11-ejemplo-de-tabla-relacional.png)

El paso de los diagramas E-R a tablas se hace mediante unas **reglas** que nosotros no vamos a ver porque es una materia demasiado avanzada.

### 1.3.2. Pasos para convertir un diagrama E-R en un modelo relacional

La **conversión de un diagrama E-R a un modelo relacional**, es decir, a un **conjunto de tablas**, debe ser un proceso en el que *no se pierda información* y en el que obtengamos como resultado *una base de datos lo más optimizada posible*.

Para lograr esos dos objetivos, **seguiremos siempre estos dos pasos**:

1. **Convertir el diagrama E-R (modelo conceptual) en un conjunto de tablas (modelo lógico) con las *reglas de paso a tablas*.**

   En esta transformación no se debe perder ninguna información, es decir, el modelo resultante debe ser semánticamente equivalente al modelo original.
   
   Este proceso se suele denominar **paso a tablas** y existen unas reglas muy sencillas para hacerlo bien. Las veremos enseguida. Solo tienes que seguirlas y obtendrás una base de datos relacional bien diseñada (siempre que tu diagrama E-R también estuviera bien diseñado, claro).

2. **Normalizar la base de datos.**
   
   Este proceso sirve para asegurar que la redundancia se mantiene a un nivel mínimo y que no se van a producir problemas durante la utilización de la base de datos.
   
A continuación, vamos a ver cómo dar estos dos pasos. Pero antes necesitamos familiarizarnos con la terminología del modelo relacional.

### 1.3.3. Conceptos clave del modelo relacional

Antes de comenzar a ver las reglas de paso a tablas, tienes que tener muy clara la **terminología del modelo relacional**. Si ya conoces estos términos, puedes saltar sin ningún problema al siguiente apartado.

Muchos de estos conceptos ya han aparecido antes en diferentes momentos. Aquí vamos a organizarlos y a definirlos claramente antes de continuar.

1. **Tabla o relación**

   Es un conjunto de celdas dispuesto en *filas (registros)* y *columnas (campos)*.
   
   * Cada tabla guarda la información correspondiente a *una entidad* o *una relación* del modelo ER.
   * Cada *registro* guarda *una ocurrencia* de la entidad o relación. Por ejemplo, en una tabla de CLIENTES, cada registro guarda la información de *un cliente*.
   * Cada *campo* guarda *un atributo* de la entidad o relación. Por ejemplo, en una tabla de CLIENTES, cada campo guarda una parte de la información de los clientes. Así, existirá un campo *DNI*, un campo *nombre*, un campo *apellido1*, un campo *apellido2*, etc. 
   
   Las celdas de la tabla deben contener *valores atómicos*.

2. **Dominio**
   
   Es el conjunto de valores que puede tomar un campo. Es decir, es el *tipo de datos* al que pertenece un campo.

3. **Clave primaria**

   Es un *campo o conjunto de campos* cuyos valores determinan unívocamente el valor del resto de campos del registro.

   Dicho de otra manera: el resto de campos del registro dependen funcionalmente de la clave primaria (véase “Normalización”).

   Por ejemplo, en una tabla CLIENTES, la clave primaria puede ser el DNI de los clientes, porque cada cliente tendrá un DNI diferente y es imposible que se repita.

   Suele crearse un campo específico para la clave primaria, al que casi siempre se le llama, por convenio, **ID** (de "identificador"). A veces se le agrega el nombre de la tabla: *idCliente* o *id_cliente*.

4. **Clave candidata**

   Es un campo o conjunto de campos que *podrían ser clave primaria*, pero no lo son.

   En algunas tablas encontraremos varias claves candidatas, pero solo una puede ser elegida como clave primaria.

5. **Clave ajena, externa o foránea**
   
   Es un campo o conjunto de campos de una tabla que, sin ser clave en dicha tabla, sí que *forman la clave primaria en alguna otra tabla* de la base de datos.

En el siguiente ejemplo puedes ver todos esos elementos señalados en una tabla de ALUMNOS que puede pertenecer a la base de datos de un instituto, una universidad, una escuela de educación primaria, una academia de idiomas, etc.

![Partes de una tabla relacional](/docs/prog-y-3d/_site/assets/images/07-11-partes-de-una-tabla-relacional.png)


### 1.3.6. Paso a tablas y normalización

Cualquier diagrama E-R puede convertirse en un conjunto de tablas mediante una serie de reglas que a nosotros, de momento, no nos interesan (para verlas tendrás que estudiar un ciclo formativo de informática o un grado universitario).

Una vez obtenidas esas tablas, hay que revisarlas para evitar duplicidades y posibles errores. Una de las revisiones más importantes es la **normalización**, un proceso que **previene ciertos problemas habituales** en las bases de datos mal diseñadas.

Esos problemas suelen tener que ver con la **redundancia en los datos** y las anomalías en modificaciones, inserciones y borrados.

***La normalización consiste en un conjunto de técnicas que transforman un conjunto de tablas en otro equivalente donde las redundancias de información están minimizadas.***

Para lograrlo, el nuevo conjunto de tablas debe cumplir determinadas restricciones conocidas como **formas normales**. 

#### Concepto intuitivo de forma normal (mediante un ejemplo)

La normalización es un asunto bastante avanzado. Aquí solo vamos a entender lo que significan las formas normales (y la normalización) de manera intuitiva mediante un ejemplo

La *primera forma normal* (abreviada 1NF), por ejemplo, establece la siguiente restricción: "no puede haber grupos de datos compuestos en un campo".

He aquí un ejemplo de una tabla de ALUMNOS que **no está en 1FN**:

id_alumno|nombre|asignaturas
-|-|-
1028|Susana Martínez López|Matemáticas, Lengua
1029|Raquel Molinero Sánchez|Matemáticas, Física, Química
1030|Antonio Suárez Bermúdez|Latín, Griego
1031|Juan Miguel Rubio Castro|Economía, Latín, Matemáticas
etc|etc|etc

Esta tabla **no está en 1FN porque el campo *asignaturas* contiene valores múltiples**: no es atómico e indivisible.

¿Cómo se puede modificar para que esté en 1FN? Tenemos dos posibilidades.

**POSIBILIDAD 1**. Esta solución resuelve el problema de la 1NF, pero introduce **redundancia** en la tabla (en este caso, los nombres de los alumnos/as repetidos varias veces), que es uno de los mayores pecados que puede cometer un diseñador de bases de datos.

id_alumno|nombre|asignaturas
-|-|-
1028|Susana Martínez López|Matemáticas
1028|Susana Martínez López|Lengua
1029|Raquel Molinero Sánchez|Matemáticas
1029|Raquel Molinero Sánchez|Física
1029|Raquel Molinero Sánchez|Química
1030|Antonio Suárez Bermúdez|Latín
1030|Antonio Suárez Bermúdez|Griego
1031|Juan Miguel Rubio Castro|Economía
1031|Juan Miguel Rubio Castro|Latín
1031|Juan Miguel Rubio Castro|Matemáticas
etc|etc|etc

**POSIBILIDAD 2**: Esta solución también consigue alcanzar la 1FN sin perder información. Pero tampoco es gratis: ha aumentado el número de tablas y, por tanto, la complejidad de nuestra base de datos.

TABLA DE ALUMNOS

id_alumno|nombre
-|-
1028|Susana Martínez López
1029|Raquel Molinero Sánchez
1030|Antonio Suárez Bermúdez
1031|Juan Miguel Rubio Castro
etc|etc

TABLA DE MATRÍCULAS

id_alumno|asignatura
-|-
1028|Matemáticas
1028|Lengua
1029|Matemáticas
1029|Física
1029|Química
1030|Latín
1030|Griego
1031|Economía
1031|Latín
1031|Matemáticas
etc|etc

**CONCLUSIÓN**: ninguna solución es perfecta. Así que la pregunta que hay que hacerse siempre es: **¿Cuál de las soluciones es mejor?**

Afortunadamente, esa pregunta siempre tiene una respuesta clara: siempre será preferible la solución que esté en una forma normal superior. Y existen hasta 6 formas normales (1NF, 2NF, 3NF, 4NF y 5NF; entre la tercera y la cuarta, hay una forma intermedia llamada *forma normal de Boyce-Codd* o BCNF).

En el ejemplo anterior, la segunda solución es mejor porque está en BCNF, mientras que la primera solo está en 2NF.

¿Quieres saber más sobre todo esto? Nuevamente te animo a estudiar un ciclo formativo de informática (de grado superior) o un grado universitario, donde se profundiza en todos estos asuntos.

## 1.4. Ejercicios

#### Ejercicio 1: Biblioteca

Echa un vistazo a este diagrama E-R e intenta obtener las tablas relacionales correspondientes para crear una base de datos:

![Diagrama ER del ejercicio 1](/docs/prog-y-3d/_site/assets/images/07-01-diagrama-er.png)

**Solución:**

Las tablas que resultan de la aplicación de las reglas de paso a tablas son estas:

```
CLIENTES(nif#, nombre, apellidos, dirección, teléfono)
SOLICITAN(nif_cliente#, cod_libro#, fecha)
LIBROS(codigo#, titulo, autor, editorial, pvp, num_ejemplares)
SON_PEDIDOS(cod_libro#, cod_distribuidor)
DISTRIBUIDORES(codigo#, nombre, dirección, teléfono)
```

Observa un par de cosas:

* La tabla SOLICITAN surge de una relación N:N. Estas relaciones **siempre generan una tabla**.

* La tabla SON_PEDIDOS surge de una relación 1:N. Estas relaciones no suelen generar una tabla, pero en este caso la hemos creado para evitar posibles valores nulos en la tabla LIBROS.


#### Ejercicio 2: Cajero automático

Mira este diagrama E-R e intenta obtener las tablas que se derivan de él:

![Diagrama ER del ejercicio 2](/docs/prog-y-3d/_site/assets/images/07-02-diagrama-er.png)

**Solución:**

Las tablas que resultan de la aplicación de las reglas de paso a tablas son estas:

```
CLIENTES_PROPIOS(dni#, nombre, apellido1, apellido2, dirección, teléfono)
CUENTAS(num_cuenta#, saldo, maximo_diario, num_tarjeta, contraseña, dni_cliente)
OPERACIONES(num_operacion#, id_cajero, tipo_operación, fecha, hora, num_cuenta)
```

Observa como, en esta ocasión, las dos relaciones son de tipo 1:N. En esos casos *no se suele crear una tabla para la relación*, si no que se resuelve llevando la clave de la entidad que participa con 1 a la tabla de la entidad que participa con N.

Por ejemplo, entre CLIENTES y CUENTAS (relación "tiene") hay una relación 1:N. Eso significa que:

* Cada CLIENTE puede tener entre 1 y muchas cuentas (1:N)
* Cada CUENTA pertenece a 1 y solo 1 cliente (1:1)

En estas relaciones, la clave de la parte 1 (CLIENTE) se lleva a la tabla de la parte N (CUENTA). Por eso el dni del cliente aparece en la tabla CUENTAS.

#### Ejercicio obligatorio: Series de TV

Ahora te toca a ti. Vamos a hacer una pequeña base de datos para almacenar información sobre nuestras series de televisión preferidas.

Teniendo en cuenta lo que acabamos de ver, **intenta convertir este diagrama E-R en un conjunto de tablas relacionales**:


![Diagrama ER del ejercicio obligatorio](/docs/prog-y-3d/_site/assets/images/07-ejercicio-series-tv.png)