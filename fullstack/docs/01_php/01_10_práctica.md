---
layout: page
title: 1.10 Práctica final
permalink: /php/practica.html
nav_order: 10
has_children: false
parent: 1 Programación web con PHP
grand_parent: Desarrollo web full stack
---


## 1.10. Práctica final del tema 1
{: .no_toc }

- TOC
{:toc}

Para terminar la unidad didáctica de PHP vamos a proponer un caso prácticos más completo para que pongas manos a la obra.

Se trata de crear, paso a paso, una aplicación web de corte realista que puede ser muy útil en un lugar como un instituto, una empresa, una oficina o cualquier otra organización medianamente compleja. **Puedes utilizar el siguiente esqueleto de aplicación** basado en la Biblioteca v3 para no empezar de cero:

* [Descargar el esqueleto de la aplicación](../assets/code/mvc_app_scaffolding.zip)

### 1.10.1. Especificación de requisitos

Un problema que se presenta a menudo en estas organizaciones es la necesidad de compartir ciertos recursos, como proyectores, ordenadores portátiles, salas de conferencias o de exposiciones, etc.

En nuestro instituto, por ejemplo, tenemos unas hojas impresas colgadas con una chincheta en un tablón de anuncios para que el profesorado reserve los carritos con portátiles o las aulas de informática, de modo que dos personas no traten de usar a la vez el mismo recurso.

Es un método un poco primitivo (aunque eficaz, todo hay que decirlo) que se puede informatizar fácilmente mediante una aplicación web. Y eso es lo que proponemos aquí.

Se trata de **escribir una aplicación para reservar recursos** de una organización. Los recursos pueden ser de cualquier tipo (ordenadores, proyectores, espacios físicos, etc.). Los usuarios, que tendrán que estar registrados, podrán reservar cada recurso durante tramos horarios predefinidos.

Las tablas de la aplicación, por lo tanto, serán estas:

* Resources(id#, name, description, location, image) -> Los recursos que se pueden reservar
* Users(id#, username, password, realname, type) -> Los usuarios registrados
* TimeSlots(id#, dayOfWeek, startTime, endTime) -> Los tramos temporales en lo que se pueden hacer reservas
* Reservations(idResource#, idUser#, idTimeSlot#, date, remarks) -> Las reservas (remarks = comentarios)

La aplicación, una vez rellenadas con datos las tablas maestras *Resources*, *Users* y *TimeSlots*, permitirá a los usuarios registrados **reservar recursos**. Antes tendrán que autenticarse (es decir, pasar por un login). 

Para hacer una reserva, un usuario tiene que seleccionar un recurso, una fecha y un tramo horario. Si el recurso ya está reservado, no se podrá reservar por segunda vez, obviamente.

Además, habrá **usuarios de dos tipos**: 

* *Type user*: es un usuario registrado cualquiera y puede hacer reservas y ver las reservas de otras personas, pero solo puede modificar y borrar sus propias reservas.

* *Type admin*: es un usuario administrador. Puede hacer reservas y puede ver, modificar o borrar cualquier reserva de cualquier otro usuario. Además, puede hacer reservas "en bloque", es decir, puede reservar un recurso en un tramo horario durante un periodo de tiempo. Por ejemplo, puede reservar el recurso "Aula de informática" de 8:05 a 9:05 todos los lunes del primer trimestre sin necesidad de ir reservándolo día por día.

### 1.10.2. Pasos para conseguir una implementación funcional

Para conseguir implementar la aplicación completa, vamos a hacerlo por pasos, de modo incremental. ¡Que cada persona llegue hasta donde buenamente pueda!

Recuerda que puedes empezar usando [el esqueleto de la aplicación](/docs/dwes/_site/assets/code/mvc_app_scaffolding.zip) basado en la Biblioteca v4 para no programar desde cero.

#### Paso 1. Mantenimiento de la tabla Resources

En este paso, debes crear todos los elementos necesarios para hacer el manenimiento completo de la tabla de recursos. Es decir: listado, inserción, borrado y modificación de recursos.

Hazlo exactamente en ese orden, porque he escrito las operaciones en orden de dificultad en su implementación.

Para hacerlo, necesitarás:

* El punto de entrada a la aplicación (index.php)
* El controlador de recursos (clase ResourcesController)
* El modelo de recursos (clase Resources)
* La capa de abstracción (clase Db)
* La clase vista (View)
* Una colección de vistas sencillas. Al menos dos: una para mostrar el listado de recursos y otra para el formulario de inserción y modificación (se puede reutilizar el mismo formulario para las dos cosas).

Fíjate en que puedes reutilizar gran parte del [código fuente de la Biblioteca](../php/mvc/#1753-biblioteca-v3), con unas pocas adaptaciones.

Lo ideal es hacer que, desde la vista *showAllResources*, se pueda acceder al resto de funcionalidades relacionadas con los recursos. Es decir, esa vista quedaría algo así:

```
MANTENIMIENTO DE RECURSOS

Recurso                     Ubicación         Acciones

Impresora Láser Brother     Aula 8            Modificar | Eliminar
Carrito de portátiles A     Lab. Biología     Modificar | Eliminar
Proyector portátil          Dirección         Modificar | Eliminar
etc.

                                              Añadir nuevo
```
 
Los textos "Modificar", "Eliminar" y "Añadir nuevo" deben ser *links* que nos conduzcan de regreso a la aplicación para realizar esas acciones con los recursos.

#### Paso 2. Mantenimiento de la tabla TimeSlots

El mantenimiento de esta tabla es muy similar al de la anterior. Necesitarás un controlador nuevo y un modelo nuevo, con métodos muy parecidos a los que ya has implementado para *Resources*.

#### Paso 3. Mantenimiento de la tabla Users

Más de lo mismo. Reutiliza y adapta todo lo que puedas. Este tercer mantenimiento de tabla te debería salir con mucha más facilidad y rapidez que los dos anteriores.

#### Paso 4. Menú principal

Hasta ahora, tenemos un puñado de métodos en uno o varios controladores que se invocan pasando variables de control por la URL (algo como <code>http://mi-servidor/index.php?controller=resources&action=showAll</code>). 

En este punto, vamos a juntarlos todos en un menú principal que contendrá enlaces a todas esas URLs. Cuando añadamos más funcionalidades al programa, solo tendremos que agregarlas al menú principal.

Es decir, se trata de construir una vista *"mainMenu"* (o con el nombre que más te guste) a la que se acceda después de superar el login y que muestre algo como esto:

```
Bienvenid@, nombre-de-usuario

MENÚ DE OPCIONES

Mantenimiento de recursos
Mantenimiento de tramos horarios
Mantenimiento de usuarios
Cerrar sesión
```

Los textos "Mantenimiento de recursos", "Mantenimiento de tramos horarios", etc, deben ser *links* que nos conduzcan de regreso a la aplicación para acceder a las vistas de mantenimiento de esos elementos.

#### Paso 5. Autenticación

De momento, cualquiera puede entrar a la aplicación y añadir, modificar o eliminar registros de las tablas maestras.

Vamos a proteger el acceso al menú principal con un sistema de autenticación (login). Puedes, de nuevo, [reutilizar el código del ejercicio resuelto de la Biblioteca](../php/mvc/#1753-biblioteca-v3), pues allí ya existe un sistema de autenticación parecido.

No te olvides de controlar el acceso a los métodos de los controladores para que solo los usuarios debidamente autenticados puedan ejecutarlos.

#### Paso 6. Reservas

Hacer o eliminar reservas consiste, básicamente, en insertar y eliminar registros de la tabla *TimeSlots*.

Sin embargo, no es un mantenimiento como el de las otras tablas, puesto que esta tabla proviene de una relación ternaria entre tres entidades (reservas, slots y usuarios), y no es una tabla maestra como tal.

Por eso dejamos este mantenimiento de tabla para el final: porque es el más *raro* y, además, constituye la pieza principal de la aplicación: si esto no está hecho, la aplicación, simplemente, carece de su funcionalidad principal.

#### Paso 7. Roles de usuario

(Este paso es optativo)

Vamos a añadir un campo nuevo a la tabla de usuarios. Lo llamaremos *"type"*, y solo podrá contener dos valores: 0 (admin) o 1 (user). Puedes usar un VARCHAR si te sientes más cómodo/a que con códigos numéricos.

Si el usuario que entra en la aplicación es de tipo 0 (admin), tendrá acceso al menú principal y a todos los métodos de todos los controlares. Como hasta ahora, vamos.

Pero si el usuario que entra en la aplicación es de tipo 1 (user), en el menú principal solo le aparecerán las opciones de acceso a las reservas. Es decir, no podrá añadir, modificar ni eliminar usuarios, slots o recursos. Cosa que es bastante lógica, ¿no te parece?

Recuerda revisar el acceso a todos los métodos de todos los controladores para asegurarte de que un usuario de tipo 1 no entre, por ejemplo, al método para borrar recursos, ni siquiera escribiendo manualmente la URL.

#### Paso 8. Otras mejoras

(Este paso es optativo)

A la aplicación se le pueden hacer infinitas mejoras. Aquí te sugiero algunas, pero estaría bien que te sacaras otras de tu propia chistera:

* Hacer que las vistas sean visualmente atractivas con CSS y/o Javascript.
* Mostrar un calendario en el que se aprecien visualmente las reservas de una semana o de un mes. O, mejor aún, incorporar un selector para poder ver el día actual, la semana actual o el mes actual (ojo, que esto último es bastante complicadillo).
* Añadir la posibilidad de crear y anular reservas directamente desde el calendario. Observa que, así, la vista principal del usuario de tipo 1 sería el calendario, mientras que el usuario de tipo 0 seguiría accediendo al viejo menú de principal para hacer el mantenimiento completo de tablas.
* Controlar que los usuarios de tipo 1 solo puedan eliminar sus propias reservas, no las de otros usuarios. En cambio, los usuarios de tipo 0 podrán eliminar cualquier reserva.
* Eliminar automáticamente las reservas cuya fecha ya haya pasado.

#### Paso 9. Enrutador

(Este paso es optativo)

*Advertencia: ¡este paso puede resultar complicadillo!*

¿Te atreves a crear un enrutador como el de los frameworks avanzados? No es un elemento fundamental para que la aplicación web funcione, sino que tan solo sirve para construir rutas limpias.

Recuerda que el enrutador tiene que ser capaz de coger una URL limpia, como esta:

<code>
https://mi-servidor/user/show/37
</code>

...y deducir de ahí que hay que invocar el método *show(37)* del controlador de usuarios. O bien el método *showUser(37)* si tu aplicación es tan simple que solo tiene un controlador.

Debería funcionar con cualquier ruta construida de ese modo y cualquier cantidad de controladores.

A ver si se te ocurre algo para incorporar un enrutador como este a la aplicación.

(No sé si te has dado cuenta, pero, poco a poco, estamos construyendo nuestro porpio *framework* casero para programar aplicaciones MVC)