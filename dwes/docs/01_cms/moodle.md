---
layout: page
title: 1.3 Moodle
permalink: /cms/moodle
nav_order: 3
has_children: false
parent: 1 Sistemas gestores de contenido (CMS)
grand_parent: Desarrollo Web en Entorno Servidor
---

## 1.3. Moodle
{: .no_toc }

- TOC
{:toc}

(La información de esta sección está adaptada de [docs.moodle.org](https://docs.moodle.org), donde toda la documentación se encuentra publicada bajo una licencia [GNU General Public License](https://docs.moodle.org/dev/License))

### 1.3.1. Características de Moodle

Moodle es un sistema de gestión de contenidos orientado a **crear comunidades de aprendizaje** en línea. Este tipo de plataformas tecnológicas también se conoce como **LMS (Learning Management System)**. Su licencia es GPL (es decir: es software libre).

Moodle es un auténtico monstruo en cuanto a tamaño, funciones y posibilidades. Eso, por supuesto, tiene un coste: Moodle también es un devorador de recursos y resulta relativamente complejo de usar, tanto para el usuario final como para el administrador. Algunas soluciones propietarias, como *Google Suite for Education*, son más intuitivas y atractivas visualmente, pero están a años luz de Moodle en cuanto a funcionalidad.

Moodle está programado en lenguaje PHP y puede usar diferentes gestores de bases de datos para almacenar el contenido. MySQL o PostgreSQL son los más habituales, pero también es posible utilizar Oracle o SQL Server.

Las características más destacables de Moodle son:

* Su arquitectura y herramientas son apropiadas para la educación a distancia, y también para complementar el aprendizaje presencial. 
* Tiene una interfaz de usuario sencilla y compatible con todos los navegadores y las recomendaciones W3C. Eso sí, es más complejo que otras soluciones como Google Suite for Education, aunque Moodle también es muchísimo más potente.
* La instalación es sencilla (¡casi siempre!), requiriendo tan solo un servidor que soporte bases de datos y PHP con algunas extensiones bastante comunes. 
* Da mucha importancia a la seguridad: todos los formularios son revisados, las cookies cifradas, el alta de usuarios revisada, etc. 
* Es fuertemente configurable, permitiendo la instalación de módulos adicionales (plugins) para incrementar sus posibilidades.
* También pueden instalarse plantillas para cambiar su apariencia.
* Es un sistema enorme que consume *muchos* recursos en el servidor.

### 1.3.2. Algunos módulos de Moodle

Los recursos en Moodle se organizan mediante **cursos**. Un curso es gestionado por uno o varios profesores/as, que puede editar el contenido, y contiene un puñado de alumnos/as (organizados en grupos o no) que pueden acceder a los recursos pero no editarlos.

![Moodle - Lista de cursos disponibles](/assets/images/01-moodle-lista-de-cursos.png)
###### Ejemplo de lista de cursos disponibles en una instalación de Moodle (extraido de docs.moodle.org)

En Moodle, esos recursos se clasifican en categorías llamadas **módulos**. Cada módulo tiene sus propias características y está orientado a un tipo de actividad distinta: cuestionarios en línea, lecciones, tareas para que los alumnos suban, encuestas y otro montón más.

Un usuario administrador puede instalar o desinstalar módulos para ajustar su versión de Moodle a las necesidades de su organización. Por eso, aunque todos los Moodle se parecen, cada uno tiene sus propias características.

Los profesores/as pueden, dentro de sus cursos, utilizar todos los módulos que estén disponibles en el sistema para crear los recursos que su alumnado verá al acceder al curso en cuestión.

![Moodle - Lista de módulos](/assets/images/01-moodle-lista-de-modulos.png)
###### Lista de recursos disponibles en Moodle (puede variar dependiendo de los plugins instalados)

A la hora de crear un recurso, Moodle proporciona al profesor/a una enorme (y cuando digo enorme quiero decir *enooorme*) cantidad de posibilidades de configuración. Cada tipo de recurso tiene diferentes configuraciones, claro, pero algunas de las más típicas son:

* Descripción detallada del recurso.
* Fechas en las cuales ese recurso va a estar disponible para el alumnado.
* Restricciones de acceso.
* Calificación (numérica, cualitativa, por rúbrica, sin calificación...)
* Retroalimentación al finalizar la actividad.

![Moodle - Ejemplo de configuración de un recurso](/assets/images/01-moodle-configuracion-recurso.png)
###### Ejemplo de configuración de un recurso (una tarea, en este caso)

A continuación vamos a describir los módulos más populares.

#### Módulo de archivos

Los archivos son uno de los recursos más simples de los que dispone Moodle.

Se trata, simplemente, de documentos que sube el profesor/a y que estarán accesibles al alumnado. Los documentos pueden ser de cualquier tipo.

#### Módulo de Tareas

Este módulo sirve para que el alumnado envíe tareas al profesor/a. Estas tareas pueden constar de un texto en línea o uno o varios archivos subidos a la plataforma.

* Puede especificarse la fecha final de entrega de una tarea y la calificación máxima que se le podrá asignar. 
* Los estudiantes pueden subir sus tareas (en cualquier formato de archivo) al servidor. Se registra la fecha en que se han subido. 
* Se permite enviar tareas fuera de tiempo, pero el profesor puede ver claramente el tiempo de retraso. 
* Para cada tarea en particular, puede evaluarse a cada estudiante (calificaciones y comentarios) en una única página con un único formulario. Incluso se puede corregir el documento escribiendo encima, como haríamos con una tarea hecha en papel.
* Las observaciones del profesor se adjuntan a la página de la tarea de cada estudiante y se le envía un mensaje de notificación. 
* El profesor/a tiene la posibilidad de permitir el reenvío de una tarea tras su calificación (para volver a calificarla). 

![Moodle - Ejemplo de tarea](/assets/images/01-moodle-tarea.png)
###### Ejemplo de tarea de subida de texto en línea. Así es como la ve un estudiante una vez creada.

#### Módulo de consultas

Las consultas son votaciones. Pueden usarse para votar sobre algo o para recibir una respuesta de cada estudiante (por ejemplo, para pedir su consentimiento para algo).

* El profesor/a puede ver una tabla que presenta de forma intuitiva la información sobre quién ha elegido qué. 
* Se puede permitir que los estudiantes vean un gráfico actualizado de los resultados.

#### Módulo de foro

Hay diferentes tipos de foros disponibles: exclusivos para los profesores, de noticias del curso y abiertos a todos.

* Las discusiones pueden verse anidadas u ordenadas cronológicamente. 
* El profesor/a puede obligar a la suscripción del alumnado a un foro o permitir que cada persona elija a qué foros suscribirse. 
* Se pueden habilitar o inahibilitar las respuestas en un foro o en un determinado tema.
* El profesor/a puede mover los temas de discusión entre distintos foros.
* La participación en el foro del alumnado se puede calificar.

#### Módulo de Cuestionarios

Los cuestionarios son los típicos exámenes tipo test. Pueden utilizarse como exámenes, como ejercicios de autoevaluación, como pruebas de evaluación inicial, etc.

* Los profesores/as pueden definir una base de datos de preguntas que podrán ser usadas en diferentes cuestionarios. Esto requiere una gran inversión de tiempo al principio, pero luego pueden reutilizarse las preguntas toda la vida. Y existen bancos de preguntas disponibles en internet.
* Las preguntas pueden ser almacenadas en categorías de fácil acceso, y estas categorías pueden hacerse accesibles desde cualquier curso de Moodle.
* Los cuestionarios se califican automáticamente. Pueden ser recalificados si se modifican las preguntas. 
* Los cuestionarios pueden tener un límite de tiempo a partir del cual no estarán disponibles. 
* El profesor/a puede determinar si los cuestionarios pueden ser resueltos varias veces y si se mostrarán o no las respuestas correctas y los comentarios 
* Las preguntas y las respuestas de los cuestionarios pueden ser mezcladas (aleatoriamente) para impedir que el alumnado recurra al viejo truco de copiarse unos a otros. 
* Las preguntas pueden incorporar imágenes y otros recursos multimedia. 
* Hay preguntas de muchísimos tipos: verdadero/falso, respuesta múltiple, texto abierto, emparejamiento, etc. Incluso hay respuestas calculadas, perfectas para plantear un problema matemático o científico cuyos datos de entrada sean variables.

#### Módulo de encuestas

Las encuestas permiten al profesor/a conocer más datos sobre el progreso del alumnado o sobre la efectividad de un curso o un conjunto de recursos.

Es importante aclarar que el **módulo de cuestionarios** y el **módulo de encuestas** se parecen pero no son iguales. El primero es un módulo adicional opcional de Moodle (si bien es muy popular). El segundo es un módulo estándar predefinido bastante menos potente.

* Existen encuestas ya preparadas que sirven como instrumentos para el análisis de proceso de enseñanza en línea. 
* Se pueden generar informes de las encuestas, descargables como texto (CSV) o como hoja de cálculo para su posterior análisis. 
* A cada estudiante se le informa sobre sus resultados comparados con la media de la clase. 

#### Módulo de Wikis

Un wiki es un espacio colaborativo de construcción de contenido. En los wikis (como en *Wikipedia*) es la comunidad la que redacta y revisa el contenido. Las diferentes entradas del wiki pueden enlazarse entre sí (enlaces internos) o con otras páginas (enlaces externos). También se puede insertar contenido multimedia.

* Cualquier usuario puede editar cualquier artículo (bueno, en Wikipedia hay ciertos artículos protegidos, pero en los wikis de Moodle, no).
* El wiki permite que el alumnado trabaje sobre los mismos documentos de forma grupal. 
* Se guarda un historia completo de todas las modificaciones de cada entrada del wiki, de modo que pueda revertirse un cambio si se ha producido un error o una *vandalización*.
* Se guarda un registro de qué usuarios han hecho cada cambio.
* El profesor/a puede calificar la participación de cada alumno/a en el wiki. 

#### Módulo de lección

Las lecciones de Moodle son colecciones de páginas web enlazadas entre sí, de modo que *cuentan una historia*.

Al final de cada página, el profesor/a puede introducir una pregunta para comprobar en qué grado el alumno/a ha asimilado el contenido. En función de la respuesta, la lección puede dirigir al alumno/a a una página o a otra diferente, de modo que cada persona puede seguir su propio camino a lo largo de la lección.

Es como uno de esos libros de "Elige tu propia aventura", pero con un solo final (la asimilación de la lección) al que cada persona puede llegar por un camino diferente, a veces corto y directo, a veces largo y tortuoso.

#### Otros módulos

Moodle tiene muchos (pero muchos) otros módulos, algunos predefinidos y otros instalables mediante plugins. También se pueden desarrollar plugins nuevos para Moodle, desde luego, aunque en este curso no entraremos en ello.

Mencionamos a continuación muy brevemente algunos otros módulos que es habitual encontrar:

* **Enlace externo**: para crear links a recursos fuera de Moodle.
* **Página**: para crear páginas web dentro de Moodle con un sencillo editor WYSIWYG.
* **Chat**: para programar sesiones de chat de texto entre los miembros de un curso.
* **Glosario**: para crear listas de definiciones, de forma similar a un diccionario, o, en general, para organizar información.
* **Base de datos**: para crear de forma colaborativa un repositorio de información sobre cualquier temática. La estructura de cada registro de información la define el profesor/a.
* **Taller**: para crear tareas con revisión entre pares. Los criterios de revisión los establece el profesor/a.
* **Libro**: para crear material de estudio o de consulta en formato libro, con capítulos y subcapítulos.

### 1.3.3. Los roles de usuario en Moodle

Como en todo sistema complejo, en Moodle existen varios roles de usuario predefinidos, cuyo papel dentro del sistema es ligeramente distinto. Estos roles son:

* **Invitado**. No necesitan autenticarse. Solo pueden acceder a la página principal y a algunos cursos marcados como "con acceso a invitados". No pueden subir tareas, ni participar en los foros, ni contribuir al contenido de ninguna otra manera.
* **Estudiante**. Son usuarios registrados que necesitan autenticarse. Tienen acceso a determinados cursos. Para acceder a ellos tienen que estar matriculados en los mismos, algo que puede hacer el profesor/a o pueden hacer por su cuenta conociendo una clave de matriculación. Una vez que acceden a un curso, tienen acceso a todos los recursos que el profesor/a haya hecho visibles y pueden subir tareas y participar en foros, chats, wikis, etc. El profesor/a puede calificar todas sus contribuciones.
* **Profesor/a sin permisos de edición**. Puede acceder a sus cursos, evaluar las tareas del alumnado y interactuar con ellos en chats, foros y demás, pero no puede añadir, borrar ni modificar los recursos del curso.
* **Profesor/a con permisos de edición**. Puede hacer todo lo del anterior y, además, añadir, borrar y modificar recursos en un curso. Un mismo usuario puede ser profesor/a en un curso (y, por tanto, administrarlo) y estudiante en otro, o no tener ni siquiera privilegios de acceso a los otros cursos. El profesor/a tiene acceso a un completísimo sistema de cálculo de calificaciones de sus estudiantes.
* **Administrador/a**. Este usuario puede acceder con privilegios plenos a todos los cursos y también a la administración de Moodle, lo que incluye un montón de cosas: administración de usuarios, de cursos, de categorías, de plugins, de plantillas, de las copias de seguridad, de la configuración del servidor y un largo etcétera.

Además, el administrador cuenta, entre sus privilegios, con la posibilidad de renombrar estos roles y también de definir roles nuevos, asignando los permisos que considere conveniente a cada rol.

### 1.3.4. Instalación y explotación de Moodle

Moodle es un CMS mucho más complejo que Wordpress. Por eso, su instalación y explotación, aunque no difieren mucho en esencia de la de Wordpress, puede plantearte más problemas.

En esta sección vamos a ver a grandes rasgos en qué consisten las dos cosas.

#### Instalación de Moodle

La instalación de Moodle es, como decimos, parecida a la de Wordpress:

1. En primer lugar, debemos **descargar el código fuente** de Moodle del sitio oficial (moodle.org) y **subirlo a nuestro servidor** mediante FTP, SSH o el sistema de administración de archivos que nos facilite nuestro proveedor de hosting. El código fuente debe subirse a una carpeta accesible vía web (es decir, debe estar dentro de *htdocs*, *httpdocs* o *public_html*).
2. Creamos un directorio llamado ***moodledata*** vacío. Este directorio contendrá todos los recursos de los cursos. Lo ideal es que, por seguridad, el directorio *moodledata* ***NO*** sea accesible vía web (es decir, ***NO*** debe estar dentro de *htdocs*, *httpdocs* o *public_html*), pero, a veces, dependiendo de la configuración del servidor, esto no será posible.
3. Creamos una **base de datos** vacía.
4. **Lanzamos la instalación**. Para ello, solo tenemos que escribir la URI de la carpeta donde hemos copiado el código fuente. Algo como: https://mi-servidor/mi-carpeta-moodle
5. El programa de instalación se empezará a ejecutar y nos **preguntará los datos típicos**: nombre del sitio, nombre del host de bases de datos, usuario y contraseña para la base de datos, usuario y contraseña para el administrador de Moodle... Ah, y también te preguntará por la ubicación de la carpeta *moodledata*.
6. En cierto momento de la instalación, Moodle hará una **comprobación de las extensiones de PHP** instaladas en el servidor. Nos mostrará en color verde las extensiones detectadas, en amarillo o naranja las que no están instaladas pero no son imprescindibles, y en color rojo las que no están instaladas y que sí son imprescindibles. *Es necesario instalar esas extensiones para poder usar Moodle*.

   En ese caso, deberás contactar con tu proveedor de *hosting* para solicitarle la instalación de esas extensiones (o, en general, para solicitarle un entorno apto para la ejecución de Moodle).

7. Si todo va bien, Moodle comenzará a crear la estructura de la base de datos (lo cual puede demorarse unos minutos, porque la base de datos tiene más de doscientas tablas) y, al terminar, tendrás funcionando una instalación de Moodle limpia y lista para usar.

![Moodle - Comprobación de extensiones durante la instalación](/assets/images/01-moodle-chequeo-instalacion.png)
###### Listado de comprobación de extensiones durante la instalación de Moodle

#### Labores de administración

Ya hemos dicho varias veces que Moodle es un sistema realmente grande y complejo, ¿verdad?

Así que seguro que no te sorprenderá oír que la administración de Moodle también es compleja.

El mejor consejo que te puedo dar en este punto es: olvídate de tutoriales y manuales y, en su lugar, instálate un Moodle de prueba en tu servidor local y dedícate a trastear con él como si fuera un Moodle real. Crea usuarios y cursos, cambia la plantilla, juguetea con los enrolamientos, curiosea el administrador de archivos y las opciones de configuración del servidor...

Esta es la mejor manera de familiarizarse con la administración de Moodle. Luego, en el mundo real, cuando surja un problema real, sabrás (más o menos) a dónde dirigirte, o al menos no estarás por completo perdido/a.

Y, por supuesto, cuando necesites consultar algo, acude siempre en primer lugar a la documentación oficial: https://docs.moodle.org

En esta sección solo vamos a referirnos a las labores críticas de administración, esas que hay que hacer sí o sí para poner en marcha en Moodle recién instalado.

1. **Configurar el *homepage***. Una vez autenticado con un usuario administrador de Moodle, busca siempre el menú "Site administration" para acceder a las opciones de administración. Esas opciones están agrupadas por categorías: Usuarios, Cursos, Servidor, etc.

   Una de las primeras cosas que tendrás que hacer allí es buscar la sección "Front page" y, una vez allí, la opción "Front page settings". Al acceder a esta opción, podrás establecer el nombre de tu sitio y las cosas que quieres que aparezcan en el home.

   Al terminar, no olvides pulsar el botón para guardar los cambios que estará al final de la página.

2. **Cambiar la plantilla o *theme***. Las últimas versiones de Moodle vienen con dos plantillas preinstaladas, llamadas *"Boost"* y *"Classic"*. Cualquiera de las dos son totalmente funcionales, pero también un poco aburridas.

   Si quieres que tu Moodle luzca de un modo distinto, necesitarás buscar otra plantilla en internet (las hay gratuitas y de pago) y luego acceder a "Site administration" -> "Site appearance" para instalarla y activarla.

   Por supuesto, existe toda una rama de negocio centrada en la creación de *themes* para Moodle (muchos basados en las plantillas "Boost" y "Classic"), así como en el desarrollo de *plugins*. Sin embargo, entrar en detalles sobre cómo se hace eso excede a los propósitos de este curso.

3. **Crear categorías y cursos**. Si tu Moodle va a contener muchos cursos (más de seis o siete), lo más apropiado es que los organices en categorías para no volver locos a los estudiantes. Sea como sea, los cursos y las categorías pueden crearse, modificarse y eliminarse en "Site administration" -> "Courses".

   Es buena idea que eches un vistazo a la opción "Course default settings" en primer lugar, porque todos los cursos que crees van a heredar esos *settings* por defecto.

4. **Administrar usuarios**. Por último, en la sección "Site administration" -> "Users" puedes admnistrar todo lo relativo a la creación de usuarios registrados:

   * Formas de autenticación de usuarios: podrás elegir entre permitir que los usuarios se auto-registren en tu plataforma usando su email, o bien impedir esta posibilidad y registrar manualmente a los usuarios (lo cual es más seguro pero también más trabajoso).
   * Formas de enrolamiento (matriculación) en los cursos: también tendrás que elegir si vas a permitir que los estudiantes se enrolen (o matriculen) en los cursos por sí mismos (en cuyo caso, los profesores/as tienen que establecer una clave de matriculación y comunicársela a sus estudiantes para evitar accesos no deseados) o si la matriculación de hará manualmente.

5. **Configurar el sitio**. Las opciones de configuración están repartidas por todo el menú de administración y puedes pasarte semanas curioseando por ellas sin acabar de recorrerlas todas. Pero hay unas cuantas a las que debes prestar atención en el momento de poner en marcha tu Moodle:
   * Idioma: lo puedes configurar en "Site administration" -> "Language" -> "Language settings". Puedes agregar paquetes de idiomas que no estén instalados en "Site administration" -> "Language" -> "Language pack".
   * País y huso horario: muy importante para que las fechas de las entregas funcionen correctamente. Se ajusta en "Site administration" -> "Location" -> "Location settings".
   * Seguridad de las contraseñas: puedes ajustarla en "Site administration" -> "Security" -> "Site security settings" -> "Password policy".
   * Plugins: en concreto, deberías revisar los módulos que quieres que estén disponibles para tus profesores/as, lo cual se hace en "Site administration" -> "Plugins" -> "Activity modules".

Ahora ya tienes un Moodle más o menos preparado para dejarlo en manos de tus profesores/as, de modo que empiecen a cargar contenido en sus cursos y a trabajar con el alumnado.

Si nunca has ejercicio como profesor/a en Moodle, te aconsejo que tú mismo/a te des de alta en un curso como profesor/a y trastees un buen rato creando y modificando contenido. Es la mejor forma de aprender a hacerlo.

Y, siempre, recuerda que Moodle es un CMS tan enorme que nunca se terminan de conocer todos sus recovecos.

#### Migración

Lo que sigue es aplicable a la gran mayoría de los CMS, no solo a Moodle. Si lo incluimos aquí es porque, con Moodle, el proceso de migración resulta particularmente complicado.

**Migrar** una aplicación web significa *moverla de un servidor a otro* sin que se pierda ni el contenido, ni la funcionalidad ni la apariencia. Es decir, la experiencia del usuario no debe verse afectada. No visitante no deberían ni enterarse de que ahora la web está corriendo en otro servidor (salvo que hayamos cambiado el nombre de dominio, claro).

Para muchos CMS, existen plugins que automatizan o semiautomatizan el proceso de migración. Sin embargo, y según mi experiencia personal, aunque esos plugins pueden resultar útiles en Wordpress, con Moodle dejan mucho que desear y el proceso debe hacerse manualmente.

La migración manual de una aplicación web consiste en:

1. Descargar una copia completa de todos los archivos de tu Moodle en su estado actual. Eso incluye también el directorio *moodledata* completo.
2. Descargar un volcado SQL de la base de datos.
3. Poner la aplicación en "modo mantenimiento", para que nadie la use mientras dure la migración.
4. Subir el código fuente al nuevo servidor.
5. Crear una base de datos vacía en el nuevo servidor. A ser posible, con el mismo nombre que tenía en el viejo servidor.
6. Ejecutar el volcado SQL en la base de datos vacía para reproducir el contenido de la base de datos del servidor antiguo en el nuevo.
7. Revisar el archivo de configuración del CMS por si hay que cambiar alguna variable. En el caso de Wordpress, recuerda que ese archivo es *wp-settings.php*. En el caso de Moodle, el archivo se llama ***config.php*** y está ubicado en la raíz de la instalación.
8. Si has cambiado de dominio, te queda un paso adicional (si el dominio es el mismo, no tienes que hacer nada en este punto). Se trata de acceder a la base de datos de Moodle y buscar manualmente en *todas* las tablas cualquier referencia al viejo servidor para cambiarlas.

   Vamos a explicar esto último mejor.
   
   Supón que estás moviendo tu Moodle de una URI como esta: https://servidor-antiguo/moodle a una URI como esta: https://servidor-nuevo/moodle. Además de todo lo que hemos explicado en los pasos del 1 al 7, vas a tener que bucear en las tablas de la base de datos para buscar el texto "https://servidor-antiguo/moodle" y sustituirlo por "https://servidor-nuevo/moodle". Dependiendo de los plugins que tengas instalados, puedes encontrar esa cadena unas pocas veces o cientos de veces.

   Si tienes experiencia con bases de datos, puedes programar un pequeño programa que se encargue de hacer la búsqueda y la sustitución de forma automática. También puedes recurrir a clientes como PHPMyAdmin y MySQL Workbench, que te permiten hacer búsquedas y sustituciones de forma masiva en las tablas. Si no tienes experiencia con bases de datos... Bueno, en ese caso tendrás que armarte de paciencia o hacer un cursillo acelerado.

Una vez hecho todo esto, Moodle (o Wordpress, o el CMS que sea) debería estar funcionando en el nuevo servidor con normalidad.

Otro consejo importante: recuerda que Moodle es más exigente que Wordpress en cuanto a la configuración del servidor. Para evitar problemas con la migración, lo más conveniente es que el nuevo servidor tenga una configuración lo más parecida posible al antiguo. Esto incluye la versión de PHP y de MySQL (o la base de datos que uses), así como las extensiones de PHP instaladas.

Y un último consejo: cuando vayas a empezar la migración, consigue un buen cargamento de café y no te olvides de cruzar los dedos.

#### Actualización

Otro quebradero de cabeza con Moodle son las actualizaciones.

Los CMS, como cualquier otro programa, conviene tenerlos siempre actualizados para evitar problemas de seguridad y de rendimiento.

Wordpress es fácil de actualizar: el propio panel de administración te avisará cuando haya una nueva versión, y actualizarás el sistema con un par de clics. Aunque a veces pueden surgir contratiempos y es buena idea disponer de una copia de seguridad de la web antes de hacerlo, es una operación que no suele plantear problemas.

Con Moodle, la situación es en teoría igual de fácil, pero en la práctica no. Recuerda que es un sistema muuucho más grande y complejo de Wordpress, así que las actualizaciones son proporcionalmente más grandes y complejas también.

La actualización de Moodle, por lo tanto, es un proceso largo, complejo y delicado. Asegúrate de seguir a rajatabla y muy despacito estos pasos:

1. Haz una copia de seguridad de todos los archivos de tu Moodle (incluyendo *moodledata*) y de la base de datos. Descarga esa copia en un lugar seguro (no la dejes en tu servidor). Si algo sale mal, siempre puedes tratar de restaurar el Moodle que tenías.
2. Averigua qué versión de Moodle tienes. Esto lo puedes ver en "Site administration" -> "Notifications"
3. Averigua a qué versión de Moodle tienes que migrar. Si estás, digamos, en la versión 2.4, no puedes saltar a la 3.11 así, alegremente. Tienes que ir saltito a saltito, actualizando a las versiones críticas intermedias. Estas versiones críticas, en el momento de escribir esto (septiembre de 2021) son:

   1.3 > 1.6 > 1.8 > 1.9 > 2.2 > 2.7 > 3.1 > 3.6 > 3.11

   Es decir, si tu versión actual es la 2.4 y quieres llegar a la 3.11, primero tienes que actualizar a la versión crítica más cercana (la 2.7), y luego saltar a la siguiente (3.1), a la siguiente (3.6) y por fin llegar a tu versión de destino (3.11).

4. Descarga todas las versiones de Moodle por las que vas a tener que pasar hasta llegar a tu versión destino. Asegúrate de que tu servidor cumple los requisitos mínimos para poder instalarlas.
5. Pon tu Moodle en "modo mantenimiento". Esto se hace en "Site administration" -> "Server" > "Maintenance mode".
6. Si tu versión de Moodle actual es 3.0 o posterior, necesitarás establecer una "password de actualización" en tu archivo config.php. Simplemente, abre el archivo config.php y agrega esta línea:

   $CFG->upgradekey = 'tu-password';

   La password debe tener al menos 8 caracteres y mezclar números, letras y caracteres especiales.

7. Entra en los archivos de tu servidor y renombra la carpeta donde tengas instalado el Moodle actual. Vamos a suponer, por ejemplo, que lo tienes instalado en una carpeta llamada "aulavirtual". Pues bien, renómbrala a algo como "aulavirtual-antigua".
8. Sube la versión a la que vas a actualizar al servidor a la carpeta donde tenías el viejo Moodle (en nuestro ejemplo, "aulavirtual"). Recuerda que debes actualizar de manera incremental. Es decir, si tu viejo Moodle estaba en la versión 2.4, el Moodle que debes subir en este paso es la versión 2.7. 
9. Copia el config.php de la instalación antigua en la nueva.
10. Abre un navegador web y escribe la URI del nuevo Moodle seguida de "/admin". En nuestro ejemplo, esa URI sería: https://tu-servidor/aulavirtual/admin. Se iniciará la actualización de Moodle. Si incluiste una clave de actualización en config.php, en este punto de la pedirá.
11. La actualización hará algunas comprobaciones. Es posible que te salte algún error y no puedas continuar. Los errores más frecuentes se deben a extensiones de PHP que la nueva versión necesita y la vieja no, o bien a plugins o plantillas que no son compatibles con la nueva versión. Debes resolver estos problemas antes de continuar. Para las extensiones de PHP, configura bien tu servidor. Para los plugins y plantillas, vuelve a renombrar las carpetas de Moodle ("aulavirtual" pasará a "aulavirtual-nueva" y "aulavirtual-antigua" pasará a "aulavirtual") y accede a tu viejo Moodle. Desinstala los plugins o plantillas que te causan problemas y vuelve a dejar los nombres de las carpetas como estaban para poder lanzar de nuevo la actualización.
12. Cuando hayas superado todas las comprobaciones, simplemente pulsa el botón de "Continuar con la actualización" y cruza los dedos.
13. Sigue las indicaciones del actualizador. Con un poco de suerte, al terminar tendrás tu Moodle actualizado.
14. Repite los pasos del 7 al 13 hasta llegar a la versión de Moodle que te interesa alcanzar.

Como ves, es un proceso largo y tedioso, donde pueden surgir mil complicaciones. 

No es raro encontrarse con que una actualización de Moodle resulta inviable. Por ejemplo, porque tu Moodle dependa fuertemente de un plugin incompatible con las nuevas versiones. O por cualquier otra razón.

En esos casos, una alternativa es hacer una instalación limpia con la versión más actual y luego exportar e importar los cursos uno a uno. Por supuesto, esto solo es viable si tu organización tiene un número reducido de cursos.

En situaciones extremas, la actualización de Moodle se vuelve imposible. Qué le vamos a hacer.

Una última advertencia: si dispones de tiempo suficiente para ello, te sugiero hagas una copia local de tu Moodle actual y pruebes la actualización en primer lugar sobre esa copia. Si te vas a encontrar con alguna sorpresa desagradable al actualizar, mejor que te la encuentres en una copia local que en el servidor real.

Y que la fuerza te acompañe porque la vas a necesitar.