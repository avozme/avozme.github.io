---
layout: page
title: 7. Bases de datos
permalink: /bases-de-datos/
nav_order: 7
has_children: true
parent: Introd. a la prog. y al diseño 3D
---

# 7. Bases de datos
{: .no_toc }

- TOC
{:toc}

## 7.1. Almacenamiento de la información

### 7.1.1. Sistemas lógicos de almacenamiento

Desde los primeros tiempos de la informática ha sido necesario **almacenar grandes cantidades de información** en soportes fisicos utilizando mecanismos que fueran independientes del propio soporte. 

Esos métodos de almacenamiento se denominan **sistemas de almacenamiento lógico**. 

![Sistema de almacenamiento físico del IBM 360](/docs/prog-y-3d/_site/assets/images/07-01-dispositivo-almacenamiento-fisico.jpg)
<span style='font-size: 70%; font-color: grey'><i>Sistema de almacenamiento físico del IBM 360, un ordenador de la década de 1960. Este ordenador utilizaba principalmente cintas magnéticas en lugar de discos duros para almacenar la información. En teoría, los usuarios no deberían ser conscientes de ello. Los sistemas de almacenamiento lógico nos permiten olvidarnos de cuál es el dispositivo físico donde se almacena realmente la información.</i></span>

El sistema lógico de almacenamiento más habitual es el **sistema de ficheros**. En él, la información se organiza en **directorios** (o carpetas) y **ficheros**, y luego un componente software del sistema operativo se encarga de traducir las operaciones lógicas sobre la información (por ejemplo, añadir un dato al final de un fichero) en operaciones físicas (por ejemplo, escribir un byte en determinado sector del disco duro).

Las bases de datos que estudiaremos en este capítulo también son sistemas lógicos de almacenamiento, solo que más complejos que los sistemas de ficheros. El componente software encargado de traducir operaciones lógicas en físicas se denomia **sistema gestor de bases de datos**, y en este capítulo y el siguiente vamos a aprender a familiarizarnos con él.

### 7.1.2. Sistemas de ficheros

Antes de comenzar a pelearnos con las bases de datos, conviene conocer por encima a su hermano pobre: el sistema de ficheros.

Los **archivos o ficheros** son almacenes de información con una estructura determinada que se organizan en directorios (o carpetas) con organización jerárquica.

Existen muchos sistemas de ficheros, dependiendo del sistema operativo: 

* **FAT16**: del antiguo MS-DOS y Windows 95. 
* **FAT32**: se introdujo en Windows 95 OSR2 y aún se usa masivamente a pesar de sus limitaciones. 
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

### 7.1.3. Bases de datos

Una **base de datos** es una colección de ficheros relacionados entre sí que almacenan tanto la representación abstracta de un fragmento de información del mundo real como los datos correspondientes a ese fragmento del mundo. 

Las bases de datos, por lo tanto, son sistemas de almacenamiento de información más complejos y elaborados que los ficheros, puesto que no solo guardan la información en sí, sino también la forma en la que unos datos se relacionan con otros, y además proporcionan mecanismos para manipular esos datos.

No se debe confundir la *base de datos* (los ficheros que guardan la información) con el *sistema gestor de base de datos* (el software que manipula esos ficheros). 

Existen varios tipos de bases de datos, pero las más extendidas desde hace décadas son las **bases de datos relacionales**. Durante este capítulo y el siguiente, nos referiremos exclusivamente a este tipo de bases de datos.

#### Hitos históricos de las bases de datos

* **Años 50**: solo existían los sistemas de ficheros secuenciales basados en cintas magnéticas. Tenían problemas de rendimiento, redundancia y mantenimiento. 

* **Años 60**: aparecen los primeros sistemas de ficheros aleatorios basados en discos magnéticos (discos duros). Surgen las primeras bases de datos, aunque todavía no eran relacionales y resultaban muy difíciles de manejar. 

* **1970**: Frank Codd, de IBM, publica un artículo crucial en la historia de la informática: *“A Relational Model of Data for Large Shared Data Banks”*. En él, sienta las bases del modelo relacional que todavía usamos en la actualidad. 

* **Años 80**: IBM crea DB2, un mítico gestor de bases de datos relacionales y, con él, el lenguaje SQL. 

* **Años 90**: IBM lanza DB2 Parallel Edition, que evolucionaría a DB2 Data Partition Feature, la primera base de datos distribuida. 

* **Finales de los 90**: BD2 y Oracle incorporan el paradigma de orientación a objetos. 

* **Año 2000 - actualidad**: la eclosión de Internet hace crecer el tamaño de las bases de datos de manera desconocida hasta ahora. Se generalizan bases de datos distribuidas y no relaciones (Google, Amazon, Facebook...), los sistemas de ayuda a la toma de decisiones, el *big data* y las bases de datos multidimensionales.

   Sin embargo, para aplicaciones convencionales, las bases de datos relacionales de Codd aún siguen utilizándose en la inmensa mayoría de los casos.

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

SQL, así como otros lenguajes de la base de datos, puede usarse de tres formas distintas:

* **A través de un programa cliente**: un programa cliente es aquel que nos permite conectarnos con el gestor de bases de datos y enviarle órdenes. Las respuestas también se reciben a través del programa cliente. Por ejemplo, para **MySQL** existen dos clientes muy populares, que son **PHPMyAdmin** y **MySQL Workbench**.
* **De forma programada**: se compone un archivo con varias sentencias SQL que realizan una tarea más o menos compleja. Ese archivo se envía a la base de datos para que lo ejecute y la base de datos nos responde con el resultado. 
* **De forma embebida o empotrada**: se insertan las instrucciones SQL dentro de otro lenguaje *host* o huésped (por ejemplo, PHP, aunque puede ser casi cualquier otro). El programa se ejecuta y, durante la ejecución, se lanzan las sentencias SQL contra la base de datos. Los resultados serán devueltos en esta ocasión al programa huésped, que se encargará de procesarlos. 

Empezaremos usando SQL en las dos primeras formas, pero en aplicaciones web se usa continuamente de la tercera forma. La veremos cuando hablemos de desarrollo de aplicaciones con PHP.

## 7.2. El modelo de datos

Antes de aprender el lenguaje SQL, tenemos que hacer otra cosa que muchos programadores detestan: **diseñar la base de datos** con la que vamos a trabajar.

O, al menos, conocer un par de reglas básicas de diseño de bases de datos para poder afrontar con éxito la creación de bases de datos sencillas y para poder interpretar los diseños de otros programadores.

Un **modelo de datos** es una simplificación (o *modelización*) de la parte del mundo que queremos convertir en una base de datos.

El modelo de datos, por lo tanto, busca una representación de forma abstracta y no ambigua de los datos de la aplicación y las relaciones entre ellos. Para una aplicación dada, suelen existir varios modelos de datos válidos (e infinitos modelos incorrectos). En esta sección vamos a aprender a construir modelos de datos razonablemente correctos para sistemas sencillos.


### 7.2.1. Diagramas E-R

Los **diagramas E-R** o **diagramas entidad-relación** son una representación gráfica de los datos del mundo real que pretendemos modelar.

¿Has visto alguna vez los planos de un arquitecto para una casa? El arquitecto no se limita a dibujar la planta de la casa, sino que elabora multitud de planos diferentes de la misma casa: instalaciones, cimentación, evacuación de agua, etc.

Pues bien, para crear una aplicación informática, los "arquitectos" (que, en informática, se denominan **ingenieros**) también elaboran multitud de "planos" diferentes de la misma aplicación. **El diagrama E-R es uno de esos "planos"**.

No es labor del programador elaborar esos planos. Siguiendo con la analogía anterior, si el ingeniero informático es como el arquitecto, en programador es como el albañil. Es decir, el programador se limita a seguir los planos que le facilita el arquitecto y, en todo caso, a realizar alguna pequeña corrección o sugerencia sobre el terreno.

Entonces, si el diagrama E-R pertenece al dominio de la ingeniería informática, ¿por qué tenemos que aprender a hacerlos?

Por una razón muy sencilla: si la aplicación es pequeña, no suele existir un proceso de ingeniería previa (igual que no contratamos a un arquitecto para construir la caseta del perro). Y es el programador/a quien debe hacer todo el trabajo.

De entre todos los "planos" de la aplicación, el diagrama E-R es uno de los más importantes, sobre todo si hablamos de aplicaciones web. Así que es muy conveniente que aprendas a elaborarlos y a interpretarlos. Además, son muy sencillos de hacer.


### 7.2.2. Elementos de los diagramas E-R

Los símbolos concretos de los diagramas E-R puede diferir ligeramente entre metodologías, pero en realidad significan lo mismo.

Aquí veremos los llamados **diagramas de Chen**, por el taiwanés Peter P. Chen, que fue quién los creó en 1976 cuando trabajaba en la Universidad de Harvard (EEUU) y que son de los más extendidos en la industria.

Son diagramas tan, tan sencillos, que se elaboran con solo tres elementos:

Elemento|Significado|Símbolo
-|-|-
Entidades|Son los datos de interés para el sistema: categorías de objetos reales o abstractos de los que se necesita mantener información|![Diagramas ER - Entidades](/docs/prog-y-3d/_site/assets/images/07-02-diagramas-er-entidades.png)
Atributos|Son las características propias de las entidades. Cada entidad puede tener varios atributos asociados|![Diagramas ER - Atributos](/docs/prog-y-3d/_site/assets/images/07-02-diagramas-er-atributos.png)
Relaciones|Son las conexiones lógicas entre las entidades. Representan relaciones que existen en el mundo real y que son relevantes para nuestra aplicación|![Diagramas ER - Relaciones](/docs/prog-y-3d/_site/assets/images/07-02-diagramas-er-relaciones.png)

Aquí te dejo un ejemplo de diagrama E-R. ¡No te asustes todavía! Solo es para que veas qué aspecto tiene uno de estos diagramas, no para que lo comprendas todo de golpe. En las siguientes secciones aprenderemos a hacer todo esto.

![Ejemplo de diagrama ER](/docs/prog-y-3d/_site/assets/images/07-02-diagramas-er-ejemplo.png)


### 7.2.3. Entidades

En un diagrama E-R, las **entidades** representan las categorías de datos que son importantes para el sistema, es decir, datos que nuestra base de datos debe almacenar.
* Pueden corresponderse con **objetos tangibles** (personas, artículos, libros, billetes de avión, etc) o con **objetos intangibles** (organizaciones, profesiones, sucesos, etc.)
* Se refieren a categorías de objetos. Es decir, cada objeto individual del sistema será sólo una ocurrencia de la entidad. En ese sentido, se parecen a las clases de la programación orientada a objetos.
* Se les asigna un nombre que debe ser un **sustativo**. Por ejemplo: CLIENTE, HOTEL, FACTURA, etc. Si no puedes asignarles un sustantivo con facilidad, probablemente no estás ante una entidad.
* En particular, *nunca* deberías asignar un **verbo** a una entidad. Los verbos implican acciones, y las acciones son parte del código de tu programa, no de la base de datos. Es decir, una acción probablemente se referirá a algo que tu programa hace con los datos, no a los datos mismos, que es lo que estamos tratando de modelar ahora. 

### 7.2.4. Atributos 

Los **atributos** son características que definen a cada entidad, como los atributos de las clases en programación orientada a objetos.
* Los atributos pueden ser:
   * **Atributos clave**: diferencian a cada ocurrencia de todas las demás
   * **Atributos descriptores** (o "normales"): designan otras características propias de la entidad
* Los atributos clave suelen distinguirse del resto anteponiendo el símbolo "#" al identificador del atributo.
* Por ejemplo, la entidad CLIENTE puede tener como atributos: #dni, nombre, apellido1, apellido2, teléfono y email. Los atributos concretos dependerán de lo que necesite nuestra aplicación.
* Cada atributo pertenece a un **dominio**, es decir, tiene un tipo de datos, y solo puede tomar valores dentro de ese dominio: número entero, número real, cadena de caracteres, fecha, hora, booleano, etc.

Hay dos formas de representar los atributos de una entidad en un diagrama E-R. Puedes usar la que más te guste. Por ejemplo, para la entidad CLIENTE:

![Ejemplo de atributos en un diagrama ER](/docs/prog-y-3d/_site/assets/images/07-03-diagramas-er-ejemplo-de-atributos.png)|![Ejemplo de atributos en un diagrama ER](/docs/prog-y-3d/_site/assets/images/07-03-diagramas-er-ejemplo-de-atributos-2.png)

### 7.2.5. Relaciones

Las **relaciones** representan las conexiones que existen entre las entidades en el mundo real. 

Se les asigna un nombre compuesto generalmente por **un verbo o sintagma verbal**. Por ejemplo:

![Ejemplo de relación en un diagrama ER](/docs/prog-y-3d/_site/assets/images/07-04-diagramas-er-ejemplo-de-relacion.png)

Una relación **debería poder leerse** perfectamente en ambos sentidos y formar frases con significado. En el ejemplo anterior:

* Los CLIENTES *reservan* HOTELES.
* Los HOTELES *son reservados* por CLIENTES.

Las dos frases tienen sentido, aunque lo habitual es que tengamos que cambiar el verbo a su forma pasiva en una de ellas.

Es importante que tengas en cuenta que no hay por qué representar en la base de datos *todas* las relaciones que existen en el mundo real (que suelen ser numerosísimas), sino solo las que resultan relevantes para la aplicación. Si alguna vez tienes dudas sobre si debes incluir o no una relación en tu diagrama E-R, hazte esta pregunta. ¿Realmente necesito guardar *eso* en mi base de datos?

### 7.2.6. Grado de las relaciones

Casi todas las relaciones son **binarias**, es decir, relacionan a dos entidades entre sí. Se dice que esas relaciones tienen **grado 2**.

Pero también puede haber relaciones **ternarias** (grado 3), **cuaternarias** (grado 4) y, en general, **n-arias** (grado n), aunque son menos habituales cuanto mayor es el grado. 

Por ejemplo, esta es una relación ternaria:

![Ejemplo de relación ternaria en un diagrama ER](/docs/prog-y-3d/_site/assets/images/07-04-diagramas-er-ejemplo-de-relacion-ternaria.png)

La recomendación general es que cualquier relación de grado mayor que 2 debe tratar de reducirse (sin perder información) a varias relaciones de grado 2, porque las relaciones no binarias son más difíciles de manejar. Sin embargo, esto no siempre es posible y tenemos que apañarnos con relaciones de grado 3 o 4.

### 7.2.7. Cardinalidad de las relaciones

La **cardinalidad** de una relación es el número de ocurrencias de una entidad asociado a cada ocurrencia de la otra entidad.

Sí, lo sé: esa frase no se entiende. Enseguida te lo explico mejor con un ejemplo.

Antes, déjame decirte otra cosa incomprensible. Las cardinalidades pueden ser de tres tipos:

* **De uno a uno**. Se simboliza como **1:1**
* **De uno a muchos**, simbolizado **1:N**
* **De muchos a muchos**, simbolizado **N:N** o también **N:M**

Es muy importante identificar bien la cardinalidad de cada relación porque luego influirá a la hora de construir la base de datos.

Ahora sí, vamos a comprender todo este galimatías mediante un ejemplo.

Supón que tenemos una entidad llamada CLIENTE y otra entidad llamada HOTEL. Sabemos que ambas están conectadas mediante la relación RESERVA, porque, en el mundo real, los *clientes reservan hoteles* y los *hoteles son reservados por clientes*.

![Ejemplo de cardinalidad en un diagrama ER](/docs/prog-y-3d/_site/assets/images/07-05-diagramas-er-cardinalidad-1.png)

Ahora bien, **¿cuál es la cardinalidad de esa relación?** ¿1:1, 1:N o N:N?

Para responder a eso, siempre debes plantearte estas situaciones:

1. **Tomamos un CLIENTE cualquiera. ¿En cuántos hoteles puede hacer una reserva?**
   * Respuesta: en 0, 1 o MUCHOS.
   * Por lo tanto, en el lado del HOTEL de la relación, la *participación* es 0 como mínimo y N como máximo. Esto se simboliza con (0,N)

   ![Ejemplo de cardinalidad en un diagrama ER](/docs/prog-y-3d/_site/assets/images/07-05-diagramas-er-cardinalidad-2.png)

2. **Tomamos un HOTEL cualquiera . ¿Cuántos clientes pueden hacer la reserva en él?**
   * Respuesta: 0, 1 o MUCHOS clientes.
   * Por lo tanto, en el lado del CLIENTE la *participación* también es 0 como mínimo y N como máximo. Es decir, otra vez (0,N)

   ![Ejemplo de cardinalidad en un diagrama ER](/docs/prog-y-3d/_site/assets/images/07-05-diagramas-er-cardinalidad-3.png)

3. **Ahora tomamos el valor MÁXIMO de participación en cada extremo.**
   * En el extremo del CLIENTE, la participación era (0,N). Nos quedamos con el máximo: N
   * En el extemo del HOTEL, la participación también era (0,N). Nos quedamos con el maximo: N

   ![Ejemplo de cardinalidad en un diagrama ER](/docs/prog-y-3d/_site/assets/images/07-05-diagramas-er-cardinalidad-4.png)

**Por lo tanto, *la cardinalidad de la relación RESERVA* es de N:N**, lo que se simboliza así en el diagrama E-R:

![Ejemplo de cardinalidad en un diagrama ER](/docs/prog-y-3d/_site/assets/images/07-05-diagramas-er-cardinalidad-5.png)


#### Cardinalidad de relaciones N-arias

Recuerda que las relaciones N-arias son aquellas en las que intervienen más de dos entidades.

Es más complicado calcular la cardinalidad o establecer los atributos de la relación, pero por lo demás son iguales que las binarias.

Por ejemplo:

![Ejemplo de cardinalidad en relación ternaria en un diagrama ER](/docs/prog-y-3d/_site/assets/images/07-05-diagramas-er-cardinalidad-relaciones-n-arias.png)

#### Una grafía alternativa

Existe otra forma de dibujar las entidades y las relaciones, prescindiendo del rombo. Y las cardinalidades de cada extremo también se indican gráficamente y no con números:

![Ejemplo de grafía alternativa para los diagramas ER](/docs/prog-y-3d/_site/assets/images/07-06-diagramas-er-grafia-alternativa.png)

### 7.2.8. Atributos propios de las relaciones

No solo las entidades tienen atributos: **algunas relaciones complejas tienen sus propios atributos**.

Suelen ser aquellos atributos que no encajan bien en ninguna de las entidades relacionadas. Por ejemplo:

![Ejemplo de relación con atributos](/docs/prog-y-3d/_site/assets/images/07-07-diagramas-er-atributos-de-relaciones.png)

Intenta encajar el atributo *fecha de entrada* en cualquiera de las dos entidades y verás que no hay manera:
* No encaja bien en CLIENTE, porque un cliente puede tener muchas fechas de entrada diferentes (una por cada reserva), no solo una.
* No encaja bien en HOTEL, porque en cada hotel habrá un montón de fechas de entrada (una por cada cliente que haya reservado).
* Por lo tanto, la fecha de entrada solo encaja en la relación. Si lo piensas, tiene sentido: la fecha de entrada es un atributo de la RESERVA, no del cliente ni del hotel.

### 7.2.9. Relaciones reflexivas

En ocasiones, una entidad puede relacionarse consigo misma.

¿Que te parece raro? No lo es tanto. Mira esto:

![Ejemplo de relación reflexiva en diagrama ER](/docs/prog-y-3d/_site/assets/images/07-08-diagramas-er-relacion-reflexiva.png)

Como los jefes también son, a su vez, empleados, ¿cómo podríamos modelar esta relación entre jefes y empleados sin una relación reflexiva?

La respuesta es simple: no podríamos. O, al menos, no podríamos hacerlo *bien*. 

Las relaciones reflexivas existen por la sencilla razón de que también existen en el mundo real.

### 7.2.10. Entidades fuertes y débiles

A veces, se distingue entre **entidades fuertes** y **entidades débiles**.

* Las **entidades fuertes** no dependen de ninguna otra y tienen existencia por sí mismas.
* Las **entidades débiles** sí dependen de otras, y pueden hacerlo de dos modos:
   * *Dependencia en existencia*: Las ocurrencias de la entidad débil necesitan que haya alguna ocurrencia de la fuerte para existir. Si no, no tienen sentido.
   * *Dependencia en identificación*: Cada ocurrencia de la entidad débil necesita de alguna ocurrencia de la fuerte para poder identificarse. Es decir, la entidad débil sólo puede formar su clave usando la clave de la entidad fuerte.

Las entidades débiles suelen representarse así para distinguirlas de las fuertes:

![Ejemplo de entidades débiles](/docs/prog-y-3d/_site/assets/images/07-09-diagramas-er-entidades-debiles.png)

He aquí un ejemplo de **dependencia en existencia**: imagina una base de datos de los empleados de una empresa en la que, además de la información de los propios empleados, guardamos la información de los hijos e hijas de estos empleados. Una ocurrencia de la entidad *Hijo* no tiene sentido si no tiene asociada al menos una ocurrencia de la entidad *Empleado*, no solo porque no podemos tener hijos sin empleados, sino porque, en el mundo real (que, no lo olvides, es lo que estamos tratando de modelar) es exactamente eso lo que ocurre: que no existen los hijos de empleados sin empleados.

![Ejemplo de dependencia en existencia](/docs/prog-y-3d/_site/assets/images/07-09-diagramas-er-entidades-debiles-dependencia-en-existencia.png)

Y este es un ejemplo de **dependencia en identificación**. En este caso, no solo no tiene sentido que exista un *Municipio* que no esté asociado a ninguna *Provincia*, sino que incluso para identificar al municipio necesitamos saber a qué provincia pertenece (por ejemplo, porque puede haber municipios con el mismo nombre en provincias diferentes).

![Ejemplo de dependencia en identificación](/docs/prog-y-3d/_site/assets/images/07-09-diagramas-er-entidades-debiles-dependencia-en-identificacion.png)

### 7.2.11. Control de la redundancia

Un diagrama ER es **redundante** si, al eliminar una relación, no se pierde información importante para el sistema.

Las redundancias deben evitarse: son síntoma de un mal análisis y causarán problemas durante el diseño y la implementación, porque provocarán duplicidades en la información.

Las redundancias pueden detectarse porque:

* Hay ciclos en el diagrama E-R (¡pero, ojo, que no todos los ciclos son redundantes! Hay que pensarlo detenidamente antes de romper un ciclo)
* Hay dos o más relaciones en el ciclo con el mismo significado
* Las cardinalidades permiten eliminar una relación sin perder información (generalmente ocurre con cardinaridades 1:1 o, como mucho, 1:N)

### 7.2.12. Diagramas extendidos: relaciones jerárquicas

Los **diagramas EE-R** (**diagramas entidad-relación extendidos**) permiten representar de forma especial una relación muy habitual en el mundo real cuyo significado, sin embargo, no puede atraparse completamente en un diagrama E-R convencional. Se trata de la **relación jerárquica**.

En las relaciones jerárquicas, existe una entidad "madre" (o "superentidad") y una o varias entidades "hijas" (o "subentidades"), y se introduce el concepto de **herencia**, ya que las entidades hijas heredan todos los atributos de la entidad padre. Como en las clases de la programación orientada a objetos, vamos.

Debes sospechar que estás ante una relación jerárquica si el nombre de la relación encaja bien con las palabras ***ES UN*** o ***PUEDE SER UN***.

Por ejemplo, en una empresa dedicada al desarrollo de software:

* Un EMPLEADO ***PUEDE SER UN*** PROGRAMADOR
* Un EMPLEADO ***PUEDE SER UN*** COMERCIAL
* Un EMPLEADO ***PUEDE SER UN*** DIRECTIVO

Ahí tienes un ejemplo claro de relación jerárquica, que gráficamente se representa así:

![Ejemplo de relación jerárquica](/docs/prog-y-3d/_site/assets/images/07-10-diagramas-er-relacion-jerarquica.png)

Observa que la relación no se dibuja con un rombo sino con un **triángulo invertido** y se prescinde de la etiqueta, que siempre sería *ES UN* o *PUEDE SER UN*. Por lo demás, estas relaciones puede tener atributos, como cualquier otra relación, y suelen ser N-arias.

Las subentidades pueden añadir nuevos atributos propios o incluso redefinir algunos de los atributos de la superentidad si es necesario.

#### Tipos de relaciones jerárquicas

Hay varios **tipos de relaciones jerárquicas**, y es importante distinguirlas cuando modelamos nuestra base de datos porque afectará a la forma en la que implementemos la base de datos.

**Según el solapamiento:**

   * **Relaciones exclusivas**: una ocurrencia de la entidad padre debe ser una ocurrencia de una y sólo una entidad hija
   * **Relaciones inclusivas**: una ocurrencia de la entidad padre puede ser una ocurrencia de varias entidades hijas

**Según la extensión:**

   * **Relaciones totales**: una ocurrencia de la entidad padre debe ser, al menos, una ocurrencia de alguna entidad hija
   * **Relaciones parciales**: una ocurrencia de la entidad padre puede no ser ninguna ocurrencia de ninguna de sus entidades hijas

Se puede dar cualquier combinación de ellas, pero no te preocupes: es fácil entender las diferencias entre unos y otros tipos de relación jerárquica con unos pocos ejemplos, como siempre:

**RELACIÓN JERÁRQUICA EXCLUSIVA TOTAL**

En este ejemplo, un EMPLEADO:

* Puede pertenecer a una y solo una subentidad, es decir, no puede ser al mismo tiempo TÉCNICO y COMERCIAL o COMERCIAL y DIRECTIVO (**exclusiva**).
* Tiene que pertenecer necesariamente a alguna de las subentidades, es decir, tiene que ser TÉCNICO, COMERCIAL o DIRECTIVO a la fuerza (**total**)

![Ejemplo de relación jerárquica exclusiva total](/docs/prog-y-3d/_site/assets/images/07-10-diagramas-er-relacion-jerarquica-exclusiva-total.png)

**RELACIÓN JERÁRQUICA EXCLUSIVA PARCIAL**

En el siguiente ejemplo, un LIBRO:
* Puede pertenecer a una y solo una subentidad, es decir, no puede ser al mismo tiempo NOVELA y ENSAYO, por ejemplo (**exclusiva**).
* Podría pertenecer a alguna subentidad no contemplada en la jerarquía, es decir, podría no ser ni NOVELA, ni ENSAYO ni POESÍA (**parcial**)

![Ejemplo de relación jerárquica exclusiva parcial](/docs/prog-y-3d/_site/assets/images/07-10-diagramas-er-relacion-jerarquica-exclusiva-parcial.png)

**RELACIÓN JERÁRQUICA INCLUSIVA TOTAL**

En este ejemplo, un UNIVERSITARIO:
* Podría pertenecer simultáneamente a más de una subentidad, es decir, podría ser al mismo tiempo ESTUDIANTE y PROFESOR (por ejemplo, un profesor que se matricula como estudiante en algún curso de postgrado) (**inclusiva**).
* Tiene que pertenecer a la fuerza a alguna de las subentidades, es decir, tiene que ser ESTUDIANTE, PROFESOR y OTROS (**total**).

![Ejemplo de relación jerárquica inclusiva total](/docs/prog-y-3d/_site/assets/images/07-10-diagramas-er-relacion-jerarquica-inclusiva-total.png)

**RELACIÓN JERÁRQUICA INCLUSIVA PARCIAL**

Y, en este último ejemplo, tenemos que un VEHÍCULO:
* Podría pertenecer simultáneamente a más de una subentidad, es decir, podría considerarse al mismo tiempo TURISMO u FURGONETA (por ejemplo, un monovolumen) (**inclusiva**).
* Podría pertenecer a alguna subentidad no contemplada en la jerarquía, es decir, podría no ser ni TURISMO, ni FURGONETA ni CAMIÓN (por ejemplo, una BICICLETA) (**parcial**).

![Ejemplo de relación jerárquica inclusiva parcial](/docs/prog-y-3d/_site/assets/images/07-10-diagramas-er-relacion-jerarquica-inclusiva-parcial.png)

## 7.3. Paso del diagrama E-R al modelo relacional

Los diagramas E-R son una herramienta para representar gráficamente el **modelo conceptual** de una base de datos. Es decir, para crear un modelo abstracto y no ambiguo de la realidad.

Pero un diagrama E-R no se puede implementar directamente en un ordenador. Antes hay que convertirlo a un **modelo lógico**, es decir, a un modelo implementable en un ordenador.

El modelo lógico más popular desde hace décadas es el **modelo relacional**. En esta sección vamos a ver en qué consiste y cómo convertir nuestros diagramas E-R en tablas relacionales que podamos transformar en bases de datos reales.

### 7.3.1. Qué es el modelo relacional

El modelo relacional se basa en el **álgebra relacional**, una rama de las matemáticas muy bien desarrollada. Por ese motivo, las tablas también se llaman **relaciones**, lo cual puede inducir a errores, porque en los diagramas E-R llamábamos relaciones a la conexiones entre entidades.

Para evitar confusiones, nosotros llamaremos **tablas** a las relaciones del modelo relacional.

Por lo tanto, **en el modelo relacional *toda la información se almacena en tablas***:

* Cada tabla está compuesta por **filas**, que se llaman **registros** o **tuplas**.
* Cada tabla tiene **columnas**, denominadas **campos**.
* Cada **campo** tiene asignado un **dominio** o tipo de datos (número entero, número real, cadena de caracteres, etc).
* Cada registro contiene la información correspondiente a una ocurrencia de una entidad o de una relación del diagrama E-R. Por ejemplo, la entidad CLIENTES puede convertirse en una tabla como esta:

![Ejemplo de relación jerárquica inclusiva parcial](/docs/prog-y-3d/_site/assets/images/07-11-ejemplo-de-tabla-relacional.png)

Aunque los diagramas E-R y el modelo relacional se inventaron separadamente, ambos tienen una conexión muy estrecha que hace que los diagramas E-R puedan **convertirse en bases de datos relacionales con facilidad**.

El paso de un modelo al otro se hace mediante unas reglas, aunque en determinados casos hay que saber saltárselas si existe una buena razón para ello.

### 7.3.2. Pasos para convertir un diagrama E-R en un modelo relacional

La **conversión de un diagrama E-R a un modelo relacional**, es decir, a un **conjunto de tablas**, debe ser un proceso en el que *no se pierda información* y en el que obtengamos como resultado *una base de datos lo más optimizada posible*.

Para lograr esos dos objetivos, **seguiremos siempre estos dos pasos**:

1. **Convertir el diagrama E-R (modelo conceptual) en un conjunto de tablas (modelo lógico) con las *reglas de paso a tablas*.**

   En esta transformación no se debe perder ninguna información, es decir, el modelo resultante debe ser semánticamente equivalente al modelo original.
   
   Este proceso se suele denominar **paso a tablas** y existen unas reglas muy sencillas para hacerlo bien. Las veremos enseguida. Solo tienes que seguirlas y obtendrás una base de datos relacional bien diseñada (siempre que tu diagrama E-R también estuviera bien diseñado, claro).

2. **Normalizar la base de datos.**
   
   Este proceso sirve para asegurar que la redundancia se mantiene a un nivel mínimo y que no se van a producir problemas durante la utilización de la base de datos.
   
A continuación, vamos a ver cómo dar estos dos pasos. Pero antes necesitamos familiarizarnos con la terminología del modelo relacional.

### 7.3.3. Conceptos clave del modelo relacional

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

### 7.3.4. Reglas de paso a tablas

Lo hemos dicho varias veces, pero lo repetimos: **en las bases de datos relacionales *sólo existen tablas***.

La distinción entre "entidad" y "relación" desaparece. Tanto las entidades como las relaciones del modelo E-R deben convertirse en tablas. ¡Y no podemos perder información por el camino!

A partir de ahora, representaremos de forma resumida las tablas del modelo relacional con el siguiente formato:

```
NOMBRE-DE-TABLA(campo-clave#, campo1, campo2, ..., campoN)
```

Por ejemplo:

```
ALUMNOS (id#, dni, nombre, apellido1, apellido2, domicilio, teléfono, fecha_nac, id_grupo)
GRUPOS (id#, denominación, aula)
```

En esta representación resumida no se indican los dominios (es decir, los tipos de datos).

Teniendo esto en cuenta, vamos a ver, uno a uno, cómo convertir en tablas del modelo relacional todos los elementos de los diagramas E-R:

* Entidades y sus atributos
* Relaciones 1:1
* Relaciones 1:N
* Relaciones N:N
* Relaciones de dependencia (entidades fuertes y débiles)
* Relaciones reflexivas
* Relaciones N-arias
* Relaciones de jerarquía (superentidades y subentidades)

#### Entidades y sus atributos

Las **entidades** del diagrama E-R **se convierten en tablas** del modelo relacional. Siempre.

Los **atributos** de la entidad pasan a ser **campos** de la tabla.

Si algún atributo no es atómico (es decir, si se puede descomponer en atributos más pequeños) tendremos que arreglarlo durante la **normalización**, un proceso de revisión de las tablas que veremos más adelante.

Por ejemplo, aquí puedes ver una entidad ALUMNOS convertida en una tabla del mismo nombre:

![Paso a tablas - Entidades y atributos](/docs/prog-y-3d/_site/assets/images/07-12-paso-a-tablas-entidades-y-atributos.png)

#### Relaciones 1:1

Las **relaciones 1:1** del modelo E-R se convierten en **claves ajenas** del modelo relacional, aunque a veces hay que crear una **tabla nueva** para la relación.

Para decidir qué hacer, necesitamos fijarnos muy bien en la **cardinalidad** de la relación:

* **Si las dos entidades tienen participación (1,1)**, nos llevamos la clave primaria de una entidad como clave ajena a la otra (en principio, da igual cuál elijamos) (*ver ejemplo 1*).
* **Si una de las entidades tiene participación (0,1) y la otra (1,1)**, nos llevamos la clave de la parte (1,1) a la parte (0,1) para evitar valores nulos (*ver ejemplo 2*).
* **Si las dos entidades tienen participación (0,1)**, crearemos una tabla nueva para la relación, que contendrá las claves de las dos entidades más los atributos propios de la relación, si los hay. La clave de la nueva tabla será una cualquiera de las claves ajenas (*ver ejemplo 3*).
* En los dos primeros casos, si la relación tiene **atributos**, nos los llevamos a la entidad donde hayamos migrado la clave. En el último caso, los posibles atributos se quedan en la tabla nueva.

**Ejemplo 1**: aquí tenemos dos entidades con una relación 1:1. Las participaciones son (1,1) en ambos extremos. Por lo tanto, podemos mover la clave primaria como clave ajena a cualquiera de los dos extremos (el que nos parezca más lógico). Hemos decidido mover la clave de MATRICULA a la tabla de ALUMNOS.

![Paso a tablas - Relaciones 1:1 - Caso 1](/docs/prog-y-3d/_site/assets/images/07-12-paso-a-tablas-relaciones-1-1-A.png)

Por lo tanto, el campo *num_matr* es una **clave ajena** en la tabla ALUMNOS. Lo hemos marcado con una línea punteada para indicar que es un *"campo intruso"* en esa tabla.

Observa que el atributo de la relación viaja hasta ALUMNOS junto con la clave ajena.

**Ejemplo 2**: en este caso, una de las participaciones es (0,1), así que movemos la clave primaria de VEHICULOS (el lado con participación mínima 0) a EMPLEADOS (el lado con participación mínima 1):

![Paso a tablas - Relaciones 1:1 - Caso 2](/docs/prog-y-3d/_site/assets/images/07-12-paso-a-tablas-relaciones-1-1-B.png)

**Ejemplo 3**: aquí tenemos un caso en el que las dos participaciones son (0,1), así que se genera una tabla adicional para la relación.

El atributo de la relación se queda en la tabla que acabamos de crear. Y la clave primaria de esa nueva tabla puede ser cualquiera de las claves primarias de las entidades relacionadas (hemos elegido *cod_catastro*).

![Paso a tablas - Relaciones 1:1 - Caso 3](/docs/prog-y-3d/_site/assets/images/07-12-paso-a-tablas-relaciones-1-1-C.png)

#### Relaciones 1:N

Las **relaciones 1:N** del modelo E-R se convierten en **claves ajenas** del modelo relacional.

* La clave de la entidad que participa con cardinalidad 1 pasa como clave ajena a la entidad que participa con cardinalidad N.
* Si la relación tiene atributos, nos los llevamos a la entidad donde hayamos migrado la clave.
* ¡Cuidado! Hay una excepción a esta última regla: si la entidad que participa con cardinalidad 1 lo hace con (0,1) en lugar de (1,1), debe crearse una tabla para la relación si queremos suprimir los valores nulos. Esta nueva tabla tendrá como campos las claves de las otras dos tablas y, como clave, la de la entidad con cardinalidad N.

**Ejemplo 1**: en este ejemplo aparece el caso más frecuente: una cardinalidad 1:N con una participación de (1,1) en uno de los lados y (0,N) o (1,N) en el otro lado. Simplemente, se lleva la clave del lado (1,1) a la tabla del otro lado como clave ajena:

![Paso a tablas - Relaciones 1:N - Caso 1](/docs/prog-y-3d/_site/assets/images/07-12-paso-a-tablas-relaciones-1-N-A.png)

**Ejemplo 2**: aquí tenemos una participación (0,1) en el lado de cardinalidad 1. Es necesario crear una tabla para la relación y evitar así los valores nulos:

![Paso a tablas - Relaciones 1:N - Caso 2](/docs/prog-y-3d/_site/assets/images/07-12-paso-a-tablas-relaciones-1-N-B.png)

#### Relaciones N:N

Las **relaciones N:N** del modelo E-R son las más sencillas de pasar al modelo relacional: se convierten en **tablas** *siempre*.

* Los campos de la nueva tabla serán las claves primarias de las dos entidades.
* La clave primaria de la nueva tabla será el conjunto de claves ajenas.
* Si hay atributos, se añaden a la nueva tabla como campos no clave.
* Si alguna cardinalidad mínima es 0, la relación se resuelve exactamente igual.

**Ejemplo**:

![Paso a tablas - Relaciones N:N](/docs/prog-y-3d/_site/assets/images/07-12-paso-a-tablas-relaciones-N-N.png)

#### Relaciones de dependencia (entidades débiles)

La **relaciones de dependencia** se resuelven según su cardinalidad, siguiendo las mismas reglas que el resto de relaciones.

* Las dependencias en identificación suelen tener cardinalidad 1:1 o 1:N, por lo que no suelen generar tabla.
* Excepción: si la dependencia es en identificación, la clave de la entidad fuerte debe expandirse a la entidad débil y formar parte de su clave primaria.
* Además, es aconsejable que dicha clave se coloque en primer lugar en la lista de campos de la entidad débil.

#### Relaciones N-arias

Si se trata de una **relación N-aria** (ternaria, cuaternaria, etc), se pasa a tablas según las cardinalidades de las entidades participantes, siguiendo las reglas vistas anteriormente.

* Normalmente generan una nueva tabla. Ante la duda y si no lo vemos claro, lo mejor es crear una tabla para la relación. Así nos aseguramos de no perder información.
* Los campos de la nueva tabla serán las claves de las entidades que participan con cardinalidad N en la relación, más los atributos propios de la relación.
* La clave de la nueva tabla será el conjunto de claves ajenas.
* La clave de las entidades que participen con cardinalidad 1 no tienen por qué formar parte de la clave de la nueva tabla. Nuevamente, ante la duda y si no lo vemos claro, podemos incluirlas en la clave. La tabla será algo más ineficiente, pero nos aseguramos así de no tener problemas con la clave.

**Ejemplo**:

![Paso a tablas - Relaciones n-arias](/docs/prog-y-3d/_site/assets/images/07-12-paso-a-tablas-relaciones-N-arias.png)

#### Relaciones reflexivas

La **relaciones reflexivas** se resuelven según su cardinalidad, siguiendo las mismas reglas que el resto de relaciones. Lo único que ocurre es que pueden ser más difíciles de comprender para nosotros, puesto que en los dos extremos de la relación encontramos la misma entidad.

El truco está en asignar un papel diferente a la entidad en cada extremo de la relación, como si realmente fueran entidades distintas. 

**Por ejemplo**: cuando leamos la siguiente relación reflexiva, debemos pensar que el empleado de un extremo es el *jefe* y el del otro extremo es el *subordinado*.

* Así, leyéndola en el sentido subordinado -> jefe, obtendremos algo como: "un empleado (subordinado) *está a las órdendes de* uno o ningún empleado (jefe)".
* Y leyéndola en el otro sentido será algo como: "un empleado (jefe) *tiene a sus órdenes* cero, uno o varios empleados (subordinados)".

Si tenemos esto claro, las tablas resultantes son fáciles de comprender. 

En este caso, vamos a tener que generar una tabla para la relación porque la cardinalidad es 1:N y la participación mínima en el lado 1 es (0,1). Por lo tanto, estamos aplicando a la relación reflexiva las mismas reglas de paso a tablas que a cualquier otra relación binaria.

![Paso a tablas - Relaciones reflexivas](/docs/prog-y-3d/_site/assets/images/07-12-paso-a-tablas-relaciones-reflexivas.png)

#### Relaciones jerárquicas

Las **relaciones jerárquicas** tienen sus propias reglas, aunque en ciertos casos peculiares podrían no ser adecuadas.

Como normas aproximadas podemos dar estas reglas:

* **Para cada superentidad**: Crear una tabla (a no ser que tenga pocos -o ningún- atributos).
* **Para cada subentidad**: Crear una tabla para cada subentidad *que tenga atributos*. Si no tiene clave propia, la hereda de la superentidad. Si la subentidad no tiene atributos, no se crea tabla.
* **Para la relación**: Depende de si es exclusiva o inclusiva:
   * Si la relación es **exclusiva**, el atributo "tipo" de la relación se añade a la tabla de la superentidad, excepto si todas las subentidades han generado tabla.
   * Si la relación es **inclusiva**, se pueden tomar dos caminos:
      * Opción 1: Crear una tabla para la superentidad y otra para cada subentidad, tengan o no atributos. No añadir el atributo "tipo" a la superentidad.
      * Opción 2: Crear una tabla para la relación que contenga como clave la clave de la superentidad y su propio atributo "tipo". Crear tablas sólo para las subentidades que tengan atributos.

**Ejemplo de relación exclusiva**:

![Paso a tablas - Relaciones jerárquicas exclusivas](/docs/prog-y-3d/_site/assets/images/07-12-paso-a-tablas-relaciones-jerarquicas-exclusivas.png)

**Ejemplo de relación inclusiva**:

![Paso a tablas - Relaciones jerárquicas inclusivas](/docs/prog-y-3d/_site/assets/images/07-12-paso-a-tablas-relaciones-jerarquicas-inclusivas.png)
   
### 7.3.5. Y después del paso a tablas, ¿qué?

Una vez creada la lista de tablas, es necesario **revisarlas y detallarlas** antes de continuar.

Para cada campo, especificaremos su **dominio genérico**. Es decir, su tipo de datos (entero, real, cadena, lógico, fecha, etc).

En una pasada posterior, podemos detallar aún más el dominio (por ejemplo, para los enteros indicaremos el número de bits, para las cadenas, el número máximo de caracteres, etc)

Después, para cada campo, se pueden añadir las restricciones semánticas, como:
* NULL o NOT NULL, según admita o no valores nulos.
* NOT UNIQUE o UNIQUE, según pueda repetirse o no su valor en diferentes registros de la tabla.
* Generalmente, se considera que NULL y NOT UNIQUE son los valores por defecto, de manera que sólo hay que expresar las restricciones semánticas en caso de que sean NOT NULL y/o UNIQUE (por ejemplo, este es el caso de todas las claves primarias)

Como resultado final de todo este proceso, debemos obtener una lista de tablas con todos sus campos detallados: claves primarias, claves ajenas, dominios y restricciones semánticas.

Por ejemplo, este podría ser el aspecto de una tabla de facturas:

```
FACTURAS(numFactura#, fechaFactura, importe, observaciones, idCliente)
   - numFactura: entero(32 bits) UNIQUE NOT NULL
   - fechaFactura: fecha NOT NULL
   - importe: real NOT NULL
   - Observaciones: cadena(200)
   - idCliente: entero(16 bits) NOT NULL
```

### 7.3.6. Normalización

La **normalización** es un proceso de revisión de las tablas relacionales que sirve para **prevenir ciertos problemas habituales** en las bases de datos mal diseñadas.

Esos problemas suelen tener que ver con la **redundancia en los datos** y las anomalías en modificaciones, inserciones y borrados.

Ten en cuenta que la redundancia es la mayor enemiga de las bases de datos: puede producir incoherencias, y las incoherencias hacen que la base de datos deje de ser útil.

***La normalización consiste en un conjunto de técnicas que transforman un conjunto de tablas en otro equivalente donde las redundancias de información están minimizadas.***

Para lograrlo, el nuevo conjunto de tablas debe cumplir determinadas restricciones conocidas como **formas normales**. En las siguientes líneas, vamos a conocer las principales formas normales y cómo lograr que nuestra base de datos las cumpla. Pero antes tengo que presentarte a unas amigas muy importantes en esta historia: las *dependencias*.

#### Dependencias

Los datos de la base de datos tienen, por su propia naturaleza, una serie de **dependencias entre sí**.

**Por ejemplo**: en una tabla CLIENTES, el campo *nombre_cliente* depende del campo *dni_cliente*, porque cada DNI tiene asociado un (y sólo un) nombre. Esto no ocurre al revés, puesto que puede haber varias personas con el mismo nombre.

Es decir: si conocemos el DNI de un cliente, podemos averiguar su nombre sin ninguna duda. Pero si conocemos su nombre, no podemos saber con certeza cuál es su DNI.

Se dice entonces que *el campo "nombre_cliente" depende funcionalmente del campo "dni_cliente"*, y se simboliza así:

<div align='center'><strong><pre>dni_cliente -> nombre_cliente</pre></strong></div>

Si, en lugar de esos campos en concreto, hablamos de dos campos cualesquiera, llamados X e Y, se dice que ***Y depende funcionalmente de X si y sólo si cada valor de X tiene asociado en todo momento un único valor de Y***. Y se simboliza así:

<div align='center'><strong><pre>X -> Y</pre></strong></div>

**Otro ejemplo** de dependencia funcional: una tabla FALTAS_ASISTENCIA de la base de datos de un instituto tiene esta dependencia funcional:

<div align='center'><pre>(id_alumno, fecha, hora) -> tipo_falta</pre></div>

Esto significa que cada valor del trío *(id_alumno, fecha, hora)* tiene asociado un único valor de *tipo_falta*.

En cambio, NO existe esta otra dependencia: 

<div align='center'><strike><pre>id_alumno -> tipo_falta</pre></strike></div>

Es decir, cada valor de *id_alumno* no tiene asociado un único valor de *tipo_falta*, sino varios, porque un alumno puede tener muchas faltas de diverso tipo a lo largo de su vida académica.

#### Las formas normales

Una **forma normal** es un conjunto de restricciones que deben cumplir los campos de una tabla respecto de las dependencias funcionales que tienen entre ellos.

Si todos los campos cumplen las restricciones de una forma normal determinada, se dice que la tabla está en esa forma normal. Y existen varias formas normales, cada vez más restrictivas:

* **1FN**: primera forma normal.
* **2FN**: segunda forma normal.
* **3FN**: tercera forma normal.
* **FNBC**: forma normal de Boyce-Codd.
* **4FN**: cuarta forma normal.
* **5FN**: quinta forma normal.

El objetivo de cualquier base de datos bien diseñada es **alcanzar al menos la FNBC**, es decir, transformar nuestras tablas hasta que estén en FNBC.

#### Concepto intuitivo de forma normal (mediante un ejemplo)

Antes de enfangarnos en la normalización de tablas a un nivel más formal, vamos a entender lo que significan las formas normales (y la normalización) de manera intuitiva mediante un ejemplo

La 1FN, por ejemplo, establece (como vamos a ver enseguida) la siguiente restricción: "no puede haber grupos de datos compuestos en un campo".

He aquí un ejemplo de una tabla de ALUMNOS que **no está en 1FN**:

id_alumno|nombre|asignaturas
-|-|-
1028|Susana Martínez López|Matemáticas, Lengua
1029|Raquel Molinero Sánchez|Matemáticas, Física, Química
1030|Antonio Suárez Bermúdez|Latín, Griego
1031|Juan Miguel Rubio Castro|Economía, Latín, Matemáticas
etc|etc|etc

Esta tabla **no está en 1FN porque el campo *asignaturas* contiene valores múltiples**: no es atómico.

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

Afortunadamente, esa pregunta siempre tiene una respuesta clara:
* Será preferible la solución que esté en FNBC (forma normal de Boyce-Codd, que enseguida veremos).
* Si no hay ninguna en FNBC, elegiremos, por orden de preferencia, la que esté en 3FN, 2FN o 1FN y que reduzca al máximo la redundancia de información.

Por lo tanto, tenemos que conocer en qué consiste cada una de las formas normales para poder transformar nuestras tablas y dejarlas en un estado óptimo.

¡Vamos a ello!

#### Primera forma normal (1NF)

**Una tabla está en 1NF si y sólo si todos sus campos son atómicos**. Es decir, si no se pueden descomponer en datos (que tengan sentido) más pequeños.

El primer paso en la normalización de una tabla debe ser, por tanto, eliminar los campos que contengan grupos de datos.

Por ejemplo, observa esta tabla:

```
EMPLEADOS (id_empleado#, nombre, apellido1, apellido2, idioma)
```

Si un empleado habla varios idiomas, en el campo *idioma* habrá que guardar múltiples valores.

En consecuenca, **esta tabla no está en 1NF.**

La mejor solución es dividir la tabla en dos:

```
EMPLEADOS (id_empleado#, nombre, apellido1, apellido2)
IDIOMAS (idioma#, id_empleado#)
```

#### Segunda forma normal (2NF)

Para esta forma normal, debemos comprender el concepto de **dependencia funcional completa** (o plena), que se define así:

> *Dado un grupo de campos (X1, X2), se dice que otro campo Y tiene dependencia funcional completa respecto de (X1, X2) si depende funcionalmente de (X1, X2) y no lo hace de ningún subconjunto de (X1, X2). Es decir, Y no debe depender funcionalmente ni de X1 ni de X2*

Pues bien, una tabla está en 2NF si y sólo si:

* Está en 1NF
* **Todos los campos no clave tienen una dependencia funcional completa respecto de las claves candidatas.**

Las dependencias no completas con la clave son una enorme fuente de errores en la implementación.

Que no cunda el pánico. Lo entenderemos mejor con los ejemplos.

**Ejemplo 1**: Consideremos esta tabla en la que se almacenan las ventas de piezas junto con los almacenes donde esas piezas se guardan. Una misma pieza puede existir en varios almacenes, por lo que el *id_almacén* debe formar parte de la clave primaria:

```
VENTAS (id_pieza#, id_almacén#, nombre_pieza, cantidad, dirección_almacén)
```

Esta tabla no está en 2NF porque *dirección_almacén* no tiene una dependencia funcional completa con la clave primaria, ya que también depende funcionalmente de *una parte* de la clave primaria:

* (id_pieza, id_almacén) -> dirección_almacén
* id_almacén -> dirección_almacén

La mejor solución vuelve a ser dividir la tabla en dos:

```
VENTAS (id_pieza#, id_almacén#, nombre_pieza, cantidad)
ALMACENES (id_almacén#, dirección_almacén)
```

**Ejemplo 2**: Observa a hora esta tabla y trata de decidir si está o no en 2NF antes de leer la solución (supongamos que un empleado pueda trabajar a la vez en varios proyectos, desempeñando una función diferente en cada uno):

```
PROYECTOS (id_proyecto#, id_empleado#, función_empleado)
```

¿Lo tienes? Resulta que esta tabla SÍ está en 2NF porque:

* (id_empleado, id_proyecto) -> función_empleado

Si lo piensas un poco, NO EXISTE la dependencia id_empleado -> función_empleado, ni tampoco id_proyecto -> función_empleado, puesto que un empleado puede trabajar en varios proyectos y en cada proyecto puede haber muchos empleados.

#### Tercera forma normal (3NF)

Para la tercera forma normal, hay que comprender el concepto de **dependencia funcional transitiva**:

> *Supongamos una tabla con tres campos, X, Y y Z, que tienen las siguientes dependencias funcionales:*
>
> *X -> Y*
>
> *Y -> Z*
>
> *Y -> X*
>
> *En tal caso, se dice que Z tiene una **dependencia funcional transitiva con X a través de Y**, y se representa así: X - - -> Z*

Pues bien: **una tabla está en 3NF si y sólo si**:

* Está en 2NF.
* **Los campos no clave dependen de la clave *de forma no transitiva*.**

Las dependencias transitivas con la clave pueden provocar muchos errores en la implementación.

De nuevo, se entiende mejor con un ejemplo, pero tienes que pensar en ello detenidamente.

**Ejemplo**:

Supongamos esta tabla de vuelos de una compañía aérea:

```
VUELOS (num_vuelo#, fecha, origen, destino, id_compañía, nombre_compañía)
```

Esta tabla no está en 3NF porque nos encontramos estas dependencias:

* num_vuelo -> id_compañía
* id_compañía -> nombre_compañía
* id_compañía -> num_vuelo
* id_vuelo - - -> nombre_compañía (esta es la dependencia transitiva)

La solución vuelve a ser dividir la tabla en dos:

```
VUELOS (num_vuelo#, fecha, origen, destino, id_compañía)
COMPAÑÍAS (cód_compañía#, nombre_compañía)
```

Cada una de estas tablas ya no contiene dependencias transitivas y están en 3NF.

#### Forma normal de Boyce-Codd (FNBC o BCNF)

Para nuestra última forma normal, necesitamos introducir el concepto de **determinante**:

> *Se llama determinante a cualquier conjunto de campos del cual otro campo depende funcionalmente de forma completa.*

Pues bien: una tabla está en BCNF si y sólo si **todo determinante es una clave candidata**.

**Ejemplo**: volvamos sobre nuestra tabla VENTAS, donde se almacenan las ventas de productos junto con el almacén donde esos productos se encuentran.

```
VENTAS (id_producto#, id_almacén#, nombre_producto, nombre_almacén, cantidad)
```

Supondremos, en este ejemplo, que los almacenes se pueden identificar unívocamente tanto por el id como por el nombre. En ese caso, en esta tabla hay una clave primaria *(id_producto, id_almacén)* y una clave candidata (id_producto, nombre_almacén).

Pues bien, la tabla no está en BCFN porque existen cuatro determinantes:

* (id_producto, id_almacén) -> cantidad
* (id_producto, nombre_almacén) -> cantidad
* id_almacén -> nombre_almacén
* nombre_almacén -> id_almacén

La solución es, como siempre, dividir la tabla en dos:

```
VENTAS (id_venta#, id_almacén#, cantidad)
ALMACENES (id_almacén#, nombre_almacén#)
```

#### Diagramas de dependencias

Los **diagramas de dependencias** son una herramienta útil para determinar las dependencias funcionales dentro de una tabla, que es el paso previo a cualquier intento de normalización.

Consisten en una **representación gráfica de las dependencias** dentro de la tabla. Las dependencias se indican con flechas que salen de unos campos y apuntan a otros.

Por ejemplo, vamos a hacer el diagrama de dependencias de la tabla de VENTAS que ya hemos usado varias veces con ligeras variaciones:

```
VENTAS (id_pieza#, id_almacén#, nombre_almacén, cantidad)
```

Supongamos que en esa tabla existen estas dependencias:

* (id_pieza, id_almacén) -> cantidad
* id_almacén -> nombre_almacén

El diagrama de dependencias permite observar las dependencias con más facilidad (sobre todo si son muchas y complejas) y tiene un aspecto como este:

![Ejemplo de diagrama de dependencias](/docs/prog-y-3d/_site/assets/images/07-13-diagrama-de-dependencias.png)

## 7.4. Ejercicios propuestos

En esta sección vamos a proponer varios casos prácticos sencillos pero, al mismo tiempo, realistas, ordenados por dificultad creciente.

Primero encontrarás varios ejercicios en los que tendrás que diseñar un diagrama E-R y pasarlo a tablas. Más adelante hay otros ejercicios diseñados exclusivamente para practicar la normalización, ya que en esos diagramas E-R he introducido algunos errores con el fin de que te encuentres ciertos problemas habituales a la hora de normalizar bases de datos.

*Es muy importante, como siempre, que intentes hacerlos antes de mirar las soluciones*, aunque no te salgan. El tiempo que hayas empleado en darle vueltas no es tiempo perdido, sino al contrario.

Además, ten en cuenta que mi solución y la tuya no tienen por qué coincidir (siempre hay varias soluciones viables), aunque sí deberían asemejarse un poco.

#### Ejercicio 1: Librería

En este ejercicio, como en los cuatro siguientes, tienes que:

1. **Leer bien el enunciado** con los requisitos. Si necesitas hacer alguna suposición adicional, eres libre de hacerlo, siempre que sea razonable.
2. **Crear el diagrama E-R**. Para identificar las entidades, fíjate bien en los *sustantivos* que más se repitan en el enunciado. Probablemente serán entidades o atributos de entidades. Y olvídate de los verbos: probablemente serán procesos, es decir, funciones del programa que afectan poco o nada a la base de datos.
3. **Hacer el paso a tablas**.

Se pretende desarrollar una aplicación informática para la gestión de una **librería** dedicada tan sólo a la venta de libros (no vende material de papelería)

El programa debe permitir al dependiente de la librería **mantener los fondos bibliográficos** disponibles en el local, es decir: dar de alta nuevos libros, dar de baja libros y modificar libros existentes.

La librería pertenece a un club de lectores, es decir, no todo el mundo puede comprar en la misma. Para comprar, es necesario ser un socio del club. Todos los socios tienen una cuenta de cliente creada en la librería.

**Dibuja el diagrama E-R de este sistema y conviértelo en una lista de tablas relacionales.**

#### Ejercicio 2: Cajero automático

Se quiere construir el sistema informático que controle los **cajeros automáticos** de una entidad bancaria. En principio, trabajaremos sobre una versión simplificada de los cajeros automáticos reales, ya que sólo se podrán realizar dos operaciones: **sacar dinero y consultar el saldo**.

Para operar en el cajero, el usuario ha de introducir su tarjeta, en la que están grabados magnéticamente sus datos: nombre, apellidos, número de tarjeta, contraseña y número de cuenta. El cliente puede ser propio, si tiene una cuenta en la entidad bancaria, o ajeno, si su cuenta pertenece a otra entidad.

Después de introducir la tarjeta, el cliente teclea su contraseña. Si ésta es incorrecta, el cajero da otra oportunidad para teclearla. Si el cliente vuelve a fallar, la tarjeta se retiene y se anotan los datos de la operación fallida: identificador del cajero, número de operación, tipo de operación (R = retirar dinero, S = pedir saldo y O = otros), fecha, hora, número de tarjeta y mensaje emitido al cliente. Además, se genera un resguardo impreso con todos estos datos.

Si el cliente teclea correctamente su contraseña, tiene acceso al menú de operaciones, que por ahora sólo tendrá dos opciones: sacar dinero y consultar saldo.

**Dibuja el diagrama E-R de este sistema y conviértelo en una lista de tablas relacionales.**


#### Ejercicio 3: Piscina

Se quiere desarrollar un programa para informatizar la gestión de una **piscina y sus instalaciones deportivas**.

Los servicios que hay que gestionar son: instalaciones deportivas (piscina, pistas de tenis, de baloncesto, etc.), vestuarios y duchas, servicio de comedor y el baño en la piscina propiamente dicho. Para cada servicio es necesario comprar la **entrada** correspondiente. Cada entrada indica a qué servicio da derecho, la fecha (y, en su caso, el horario) de disfrute y el precio de la misma.

Cada servicio tiene un **aforo máximo** que no puede superarse. No se venderán entradas para un servicio cuando eso suponga superar el aforo.

Existen diferentes tipos de usuarios:

1. **Estudiantes** (deben presentar el carnet de estudiante), que pueden usar gratuitamente las piscinas, los vestuarios, las duchas y las pistas deportivas. Tienen un 50% de descuento en el comedor. El carnet de estudiante recoge los siguientes datos: nombre, apellidos, dni, domicilio, teléfonos, nº de matrícula, titulación y curso, junto con una foto reciente.
2. **Empleados** (deben presentar su tarjeta identificativa), que pueden usar gratuitamente todos los servicios. La tarjeta contiene estos datos: nombre, apellidos, dni, domicilio, teléfono, nº de la seguridad social, categoría y antigüedad en la empresa (fecha de ingreso)
3. **Los familiares de los empleados**, que podrán beneficiarse de un 40% de descuento en el comedor y un 60% en las instalaciones deportivas, los vestuarios y las duchas. Deben presentar una tarjeta familiar, donde figuran sus datos personales y los del empleado con el que tienen parentesco, así como el grado de ese parentesco.

**Dibuja el diagrama E-R de este sistema y conviértelo en una lista de tablas relacionales.**


#### Ejercicio 4: Agencia de viajes

Una **agencia de viajes** de la ciudad desea renovar su sistema informático. El programa de gestión debe encargarse, básicamente, de recibir las peticiones de los clientes y **buscar plazas hoteleras y pasajes de avión** que satisfagan esas peticiones.

Cuando un cliente llega a la agencia, realiza una petición de viaje. Esa petición puede consistir en un **billete de avión**, en una **reserva de hotel** o en **ambas cosas**. La petición de viaje incluye la fecha de comienzo del mismo, la fecha de fin, el número de personas que van a realizar el viaje y la ciudad de destino. Además, si se trata de una reserva de hotel, en la petición se ha de indicar la categoría (nº de estrellas) que se desea contratar, el número de habitaciones y su tipo (individual, doble, matrimonio, etc). Y si se trata de un billete de avión, hay que indicar la hora deseada de salida y regreso y el tipo de pasaje que se desea (turista, primera clase, VIP, etc)

Con la petición del cliente, la agencia de viajes realiza una primera selección: para el caso de los billetes de avión, busca en su propia base de datos de compañías aéreas los vuelos que mejor se adaptan a las peticiones del cliente. Para las reservas hoteleras, hace lo mismo con su base de datos de hoteles.

De todas las opciones posibles, el programa debe escoger la que mejor relación calidad-precio presente. Esta elección se ofrecerá al cliente en forma de **presupuesto**. El presupuesto contiene estos datos: número de presupuesto, nombre del agente que atiende al cliente, fecha, hora, importes parciales desglosados e importe total, además de todos los datos concretos de viaje (hoteles, vuelos, etc.)

**Dibuja el diagrama E-R de este sistema y conviértelo en una lista de tablas relacionales.**


#### Ejercicio 5: Fuga del castillo

*Atención: este ejercicio es de dificultad elevada*.

Se pretende desarrollar un **videojuego** de tipo **aventura gráfica**. El jugador manejará a un personaje atrapado en un castillo medieval del que tiene que encontrar la salida.

El castillo está compuesto por muchas **estancias** comunicadas entre sí mediante **puertas**. El jugador puede moverse libremente a través de esas puertas para pasar de una estancia a otra, excepto cuando una puerta está cerrada. En ese caso, tiene que encontrar antes la **llave** que abre esa puerta, que estará escondida en alguna otra habitación del castillo.

La distribución de habitaciones, puertas y llaves ocultas es fija, es decir, es la misma en todas las partidas. Cada habitación, además, tiene unas dimesiones, aspecto y decoración propias que tampoco cambian de una partida a otra.

En una de las habitaciones se esconde la llave que abre la puerta principal del castillo. El jugador debe encontrarla para poder escapar.

Además de todo esto, el castillo está poblado por **fantasmas, muertos vivientes y cucarachas gigantes**. Todos se mueven libremente por las habitaciones del castillo siempre que las puertas estén abiertas, excepto los fantasmas, que por su naturaleza incorpórea pueden atravesar las puertas, aunque estén cerradas.

Si el protagonista tropieza con uno de los monstruos, tiene que pelear con él para vencerle, o bien huir en otra dirección. Para pelear con los monstruos dispone de tres **armas** diferentes: un lanzallamas con el que pegar fuego a los fantasmas, un hacha con la que corta la cabeza de los muertos vivientes, y un insecticida especial que acaba con las cucarachas.

Sin embargo, al comenzar la partida, el jugador no dispone de ninguna de las tres armas, sino que las irá encontrando por el camino. Además, el lanzallamas y el insecticida se van agotando conforme son usados, por lo que el jugador debe rellenarlos con recargas que irá encontrando también por las habitaciones. 

El protagonista tiene tres **vidas**. Cuando muere en el encuentro con uno de los monstruos, pierde una vida. Si gasta las tres, se termina la partida y el jugador pierde.

En cualquier momento del juego, el jugador puede decidir grabar el estado actual de la partida para seguir jugando más tarde. También puede decidir cargar una partida antigua para seguir jugándola, o terminar el juego en ese momento. 

El juego termina con éxito si el jugador consigue salir del castillo. Existirá un registro con los diez mejores jugadores, donde aparecerán sus nombres junto con el tiempo que han tardado en escapar. Al terminar la partida con éxito, hay que decidir si el jugador debe figurar entre los diez mejores o no (dependiendo del tiempo que haya empleado).

**Dibuja el diagrama E-R de este sistema y conviértelo en una lista de tablas relacionales.**


#### Ejercicio 6: Carreras de caballos

Dada la siguiente tabla:

```
CARRERAS(id_jinete#, id_caballo#, nombre_jinete, nombre_caballo, fecha_carrera, id_hipódromo, nombre_hipódromo, posición_final)
```

... donde se supone que un jinete puede montar a varios caballos, pero cada caballo es montado siempre por el mismo jinete, se pide:

1. Explicar por qué la tabla NO está en BCNF y pasarla a BCNF.
2. Tomando de nuevo la tabla CARRERAS original, explicar por qué NO está en 2NF y pasarla a 2NF.
3. Con las tablas resultantes del apartado b), comprobar si están en 3NF y, en caso de no estarlo, pasarlas a 3NF.

*(Nota: para hacer este ejercicio es conveniente que antes dibujes el **diagrama de dependencias**)*.

#### Ejercicio 7: Autobuses urbanos

Dado el siguiente modelo de datos de un sistema para la gestión de los autobuses urbanos de una ciudad, se pide **hacer el paso a tablas** relacionales y **normalizar las tablas hasta BCNF**.

![Diagrama ER del ejercicio 7](/docs/prog-y-3d/_site/assets/images/07-14-ejercicio-7-diagrama-er.png)

#### Ejercicio 8: Red de bibliotecas públicas

Supón que la red de bibliotecas públicas de tu localidad tuviera una base de datos cuyo análisis correspondiera al diagrama E-R que hay más abajo.

**Pásalo a tablas y normalízalo hasta BCNF**.

![Diagrama ER del ejercicio 8](/docs/prog-y-3d/_site/assets/images/07-14-ejercicio-8-diagrama-er.png)

## 7.5. Ejercicios resueltos

Aquí iremos poniendo la solución a los ejercicios conforme los vayamos viendo en clase.