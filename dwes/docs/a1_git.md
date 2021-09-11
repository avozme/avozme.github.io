---
layout: page
title: Apéndice I. Sistemas de control de versiones. Git
permalink: /scv-git/
nav_order: 9
has_children: false
parent: Desarrollo Web en Entorno Servidor
---
# Apéndice 1. Sistemas de control de versiones. Git
{: .no_toc }

- TOC
{:toc}


# A1.1. Sistemas de control de versiones

Es inconcebible que un desarrollador trabaje en la actualidad sin un sistema de control de versiones.

Fíjate que en la frase anterior no tiene cabida tu opinión. Lo siento, pero es lo que hay. No importa si te gustan estos sistemas o no. No importa si estás los usas de forma habitual o siempre has huido de ellos como de la peste. No importa si ni siquiera sabes qué son o cómo funcionan. Si quieres dedicarte profesionalmente al desarrollo de software, tienes que conocerlos porque te los vas a encontrar vayas donde vayas.

## A1.1.1. ¿Qué es un sistema de control de versiones?

Un sistema de control de versiones es un almacén en la nube pensado para equipos de desarrollo de software.

Es decir, es como un Google Drive con esteroides.

El sistema de control de versiones no solo sirve para que un puñado de usuarios (entre uno y miles) suban su código fuente a la nube para ponerlo a salvo de posibles problemas con las máquinas locales, sino que, además, permite:

* Conservar absolutamente todo el historial de versiones previas.
* Documentar cada cambio, de manera que siempre sea posible saber quién, cómo, dónde, cuándo y por qué escribió cada línea de código.
* Revertir el estado del software a un estado anterior en cualquier momento.
* Crear ramas o "estados alternativos" del software, que luego podrán fusionarse con otras ramas o abandonarse sin llegar a nada.
* Crear "forks" o réplicas del sistema que luego podrán evolucionar de forma independiente (o volver a fusionarse con el contenido original).
* Evitar conflictos cuando el mismo código fuente ha sido editado simultánemente por dos personas. Y, en caso de que estos conflictos ocurran, ayudar a resolverlos.

Se trata de un buen puñado de funciones, ¿verdad? Ese es el motivo por el que absolutamente todas las organizaciones serias que se dedican a desarrollar software utilizan algún sistema de control de versiones.

Pero es que incluso para un programador/a solitario, que trabaja de forma autónoma, las ventajas de usar uno de estos sistemas superan de lejos a los inconvenientes, porque... espera un momento... ¡Resulta que no tienen ningún inconveniente!

Así que ya lo sabes: si aún no los usas, este es el momento de hacer un esfuerzo e incorporar un sistema de control de versiones a tu vida.

## A1.1.2. ¿Cómo funcionan los sistemas de control de versiones?

Existen muchos sistemas de control de versiones, aunque el mercado está dominado por unos pocos de ellos (CVS, Subversion, Mercurial, Bazaar y, sobre todo, Git). Cada uno tiene sus propias peculiaridades, pero suelen compartir varias características comunes:

* El código fuente del proyecto (y todas sus versiones previas) se guarda en un servidor. Esa colección de código fuente se denomina ***repositorio***. El servidor puede estar en Internet y pertenecer a una compañía externa, o puede estar en nuestra intranet, instalado en una de nuestras máquinas. 
* Los repositorios pueden ser remotos (si están en otra máquina distinta de la nuestra) o locales (si están en nuestra máquina).
* Cuando trabajamos, lo hacemos sobre nuestro repositorio local. Cuando una funcionalidad del código se termina, el código fuente modificado se sube al repositorio remoto, para que el resto de miembros del equipo puedan disponer de él.
* Si otra persona del equipo ha modificado los mismos archivos fuente que nosotros, el sistema de control de versiones no avisará durante la sincronización con el repositorio remoto y nos obligará a hacer manualmente una fusión de los archivos afectados, mostrándonos las diferentes versiones del mismo y las líneas de código que entran en conflicto, antes de completar la sincronización.

La sincronización con el repositorio remoto, por lo tanto, no puede ser automática (como en Google Drive o Dropbox), sino que hemos de hacerla explícita, momento en el cual el sistema nos avisará de posibles conflictos. Esta es la única manera de resolver adecuadamente esos conflictos en proyectos donde haya mucha gente trabajando simultáneamente.


# A1.2. Git básico

Git es, en la actualidad, el sistema de control de versiones más utilizado del mundo con diferencia. También es uno de los más completos y complejos. Así que, si aprendes a utilizar Git, podrás apañártelas con cualquier otro sistema de control de versiones.

En esta sección vamos a ver cómo se usa Git a nivel básico. El acceso a las funciones avanzadas irá viniendo solo, con el tiempo y el uso.

## A1.2.1. Poniendo en marcha Git

Git es un sistema de control de versiones de código abierto. De hecho, se creó inicialmente (y se sigue usando para ello) para desarrollar el núcleo de Linux. Eso quiere decir que cualquiera puede coger el código, modificarlos, adaptalo y distribuirlo.

Por eso encontrarás multitud de implementaciones de Git, así como muchos servidores y clientes que lo usan. Todos son compatibles entre sí.

Git crea repositorios locales y remotos que hay que mantener sincronizados manualmente. Eso quiere decir que, para usar Git, necesitas al menos:

* Instalar un cliente de Git en tu ordenador de trabajo.
* Instalar un servidor de Git en el ordenador donde vayas a alojar el repositorio remoto.

Para el servidor Git, mucha gente utiliza servidores gratuitos disponibles en Internet. Los más conocidos de ellos son GitHub y GitLab. Son sitios web donde te registras y ¡voilà!, ya tienes disponible un servidor Git en línea para que funcione de repositorio remoto. Además, estos sitios proporcionan características adicionales muy convenientes, como sistemas de gestión de *issues* o tareas pendientes, gestión de proyectos, estadísticas, evaluación de la calidad de software, etc. También funcionan como redes sociales para desarrolladores.

En fin, que, salvo que seas un paranoico de la seguridad o estés desarrollando código ultrasecreto para la NSA o el CSIF, usar GitHub o GitLab como repositorio remoto es la opción más interesante. Así que ya puedes registrarte en alguno de los dos.

Después de eso, solo te queda instalarte en tu ordenador un cliente Git. 

Clientes Git hay muchos, algunos más bonitos que otros. Yo te recomiendo el cliente básico en modo texto, con el que tendrás que salirte a la consola y teclear comandos. Teclear comandos incomprensibles de forma rápida y segura siempre mola mucho de cara a los demás. A parte de eso, aprenderse los comandos básicos de Git te salvará la vida en algún momento de tu futuro profesional con toda seguridad, te lo aseguro, así que es una buena inversión de tiempo.

Puedes encontrar los clientes oficiales de Git en la web del proyecto: https://git-scm.com/

Cuando hayas aprendido a apañarte con los comandos, es posible que no quieras recurrir a los clientes gráficos, pero, por si acaso, te comento que existen mogollón de ellos que te permitirán sincronizar tus archivos con un solo clic y resolver conflictos de forma rápida y muy visual. Algunos de ellos son: GitHub Desktop (ofrecido por GitHub), GitKraken, Git Cola o Tortoise Git.

Por último, ten en cuenta que todos los entornos de desarrollo medianamente potentes ofrecen una integración absoluta con Git. Es decir, que si usas Visual Studio Code, o Eclipse, o NetBeans, o muchos otros, no necesitarás ningún cliente git adicional, porque ya lo traen incorporado. Tan solo debes configurar la ruta el repositorio remoto y al local, y hala, a programar y a sincronizar como si no hubiera un mañana.

## A1.2.2. Creando un repositorio nuevo

Vale, ya tenemos nuestra cuenta en GitHub o GitLab y hemos instalado un cliente Git en nuestra máquina. ¿Ahora qué?

Podemos encontrarnos ante dos escenarios diferentes:

1. Voy a empezar un proyecto nuevo y quiero inicializar un repositorio en blanco.
2. Ya tengo mi código fuente (todo o una parte) escrito y quiero añadirlo a un repositorio git.

Vamos a ver cómo proceder en cada caso. Lo haremos mostrando cómo se usa el cliente git de línea de comando. Desde los clientes gráficos, el proceso será parecido, pero tendrás que trastear con el cliente en cuestión o leerte su documentación para ver los detalles.

#### Voy a empezar un proyecto nuevo y quiero inicializar un repositorio en blanco.

1. Abre un terminal de línea de comandos y muévete al directorio donde tienes pensado crear tu código fuente. Usa para ello los comandos *cd directorio* (para cambiar de directorio) o *mk directorio* (para crear un directorio nuevo).</li>
2. Para crear un repositorio git local en el directorio elegido, simplemente teclea este comando:</li>

    ```
    $ git init
    ```

3. Para conectar este repositorio local con un repositorio remoto en GitHub o GitLab, escribe a continuación este comando (sustituye URI por la dirección de tu repositorio que te habrá proporcionado GitHub o GitLab. Por ejemplo, en GitHub, una URI de repositorio tiene un aspecto como este: https://github.com/usuario/nombre-repositorio.git):

    ```
    $ git remote add origin <URI>
    ```
    Obviamente, el repositorio remoto deberías haberlo creado antes desde la web de GitHub o GitLab.

Eso es todo. A partir de ahora, podrás empezar a desarrollar tu código en local y a sincronizar tus archivos con el repositorio remoto cada vez que lo necesites. El procedimiento para hacer esto último lo describimos un poco más adelante.

#### Ya tengo mi código fuente y quiero añadirlo a un repositorio git

Este caso es un poquito más complejo, pero tampoco mucho. Asegúrate de tener ya creado un repositorio (vacío) en GitHub o GitLab antes de seguir esta guía.

1. Abre un terminal de línea de comandos y muévete al directorio donde tengas tu código fuente. Usa para ello el comando cd <directorio>.
2. Para crear un repositorio git local en ese directorio, simplemente teclea este comando:

    ```
    $ git init
    ```

3. Para conectar este repositorio local con un repositorio remoto en GitHub o GitLab, escribe a continuación este comando (sustituye <URI> por la dirección de tu repositorio que te habrá proporcionado GitHub o GitLab. Por ejemplo, en GitHub, una URI de repositorio tiene un aspecto como este: https://github.com/usuario/nombre-repositorio.git):

    ```
    $ git remote add origin <URI>
    ```

4. Edita el archivo .gitignore para incluir en él los archivos y directorios que no quieres incluir en el repositorio. Esto suele referirse a archivos de configuración, imágenes y otros recursos que no son parte intrínseca del código fuente o librerías de terceros. Más adelante hablaremos del archivo .gitignore con más detalle.

5. Haz tu primer commit para añadir todo el código fuente que ya tienes:

    ```
    $ git add *
    $ git commit -m "Primer commit con todo el código preexistente"
    ```

6. Sube el código de ese commit a tu repositorio remoto (te pedirá tu usuario y contraseña en GitHub o GitLab):

    ```
    $ git push
    ```

Si ahora entras en tu perfil de GitHub o GitLab, verás que el repositorio remoto ya contiene todos los archivos que tenías en tu proyecto (excepto los que señalaste en .gitignore). Los repositorios local y remoto ya están creados y puedes empezar a trabajar con normalidad, escribiendo código y subiéndolo al repositorio remoto cuando lo necesites. Este proceso lo describiremos en detalle enseguida.

Si no has entendido alguno de estos pasos, no te agobies. Enseguida te quedarán más claros.

#### Más cosas sobre la inicialización de un repositorio

Hay otro par de cosas que te interesa hacer al iniciarlizar un repositorio. Solo tendrás que hacerlo una vez y, después, tu repositorio lo recordará.

Después del *git init*, puedes indicarle al repositorio qué usuario de GitHub o GitLab va a realizar los commits. Esto se hace así:

```
$ git --config user.name "Mi-nombre-de-usuario"
$ git --config user.email "Mi-email"
```

Para comprobar que la información es correcta, simplemente teclea:

```
$ git --config list
```

#### ¡Antes de continuar! No te olvides de .gitignore

Una última cosita antes de describir cómo es el trabajo cotidiano con git y qué significa todo eso de los commits.

Esa cosita es sobre el archivo ***.gitignore***. Es un archivo muy importante que debería estar en el directorio raíz de tu proyecto. Si no existe, créalo. Ten en cuenta que en los sistemas GNU/Linux y Mac, los archivos cuyo nombre empiezan por un punto se consideran ocultos, por lo que es posible que el archivo esté ahí sin que lo veas.

Ese archivo es muy importante porque contiene una lista de todas las cosas que no se deben subir al repositorio remoto. Esto incluye, entre otros:

* **Los archivos de configuración**. Es habitual en una aplicación web tener un archivo de configuración (llamado config.php o algo parecido) con un puñado de variables donde se guarda el host de la base de datos, el usuario y la contraseña para ese host, el nombre de la base de datos, etc. Y, vamos a ver, ¿de verdad quieres que cualquiera que acceda a tu repositorio de GitHub o GitLab vea esa información?

    Además del problema de seguridad que puede suponerte (sobre todo si, como el 99% de los desarrolladores, usas el acceso root a tu servidor local de bases de datos mientras estás desarrollando un nuevo proyecto), es que no tiene sentido subir esa información al repositorio remoto, porque será diferente en cada servidor donde la aplicación se ponga en producción.

    Lo que sí suele hacerse es crear un archivo de configuración de ejemplo (algo como config-example.php), donde se muestre la estructur que debe tener config.php pero se dejen en blanco los valores de las variables. Ese archivo sí que puede sincronizarse con el resto del código y subirse a GitHub o GitLab.

* **Archivos de recursos que no forman parte de la aplicación**. Imagina que estás programando una aplicación web para una biblioteca. Esa aplicación usa algunas imágenes para construir sus vistas (por ejemplo, una hermosa fotografía de un libro antiguo para el encabezamiento). Esas imágenes **sí** forman parte de la aplicación y **sí** deben subirse al repositorio remoto.

    Pero imagina que, como es lógico, para probar la aplicación has creado un montón de libros falsos en tu base de datos local. Cada vez que añades un libro falso, le asignas una imagen de la portada (falsa también), que la aplicación almacenará en algún directorio del servidor local. Esas imágenes forman parte de los datos de prueba, no de la propia aplicación, y, por tanto **no** deberían subirse a GitHub ni GitLab. El directorio completo donde almacenes esas imagenes debería incluirse en .gitignore.

    Si no lo haces así, llenarás el repositorio remoto de basurilla y, además, harás que ocupe mucho más espacio del necesario, hasta el extremo que una clonación del repositorio puede tardar varias horas y ocupar muchos gigabytes. Ten en cuenta que el repositorio no solo contiene el estado actual del proyecto, sino también *todos los estados anteriores*, lo que incluye todas las imágenes de libros falsos que hayas podido añadir alguna vez durante el desarrollo.

    Esto no solo es aplicable a imágenes, sino a cualquier otro recurso que use la aplicación y que no forme parte de la propia aplicación: sonidos, fuentes tipográficas, vídeos, etc.

* **Bibliotecas de terceros**. A menudo, recurrimos a bibliotecas de terceros para usarlas en nuestra aplicación. Incluir ese código en nuestro repositorio nos puede meter en un embrollo legal (mírate bien la licencia de uso de *todas* las bibliotecas que vayas a utilizar) y, además, nos puede hacer engordar innecesariamente el repositorio. Tendrás que valorar una a una si es conveniente incluir determinada librería o no. Las librerías no incluidas deberán ser instaladas manualmente cuando la aplicación se despliegue en un servidor, lo cual deberás explicar muy bien en la documentación.

   Por ejemplo, en el caso de Laravel, se aconseja no incluir la carpeta "vendor" en el repositorio remoto. Es decir, hay que añadir la carpeta "vendor" a .gitignore antes de la primera sincronización. En "vendor" se encuentran todas las librerías de terceros que usa Laravel. Entonces, para desplegar esta aplicación en un servidor, ¿de dónde sacamos todas esas librerías? Fácil: cuando despleguemos el código en un servidor, solo tendremos que ejecutar "composer update" en el directorio raíz de la aplicacion, y el propio composer se encargará de instalar las librerías.


# A1.3. Trabajo básico con Git

Bueno, pues ya tenemos nuestros repositorios inicializados, conectados con el remoto y con el archivo .gitignore a punto. ¿Qué hacemos ahora?

Muy fácil: ponernos a trabajar como si git no existiera.

Y luego, cuando des por finalizada una parte de la aplicación (un método, una clase, una funcionalidad concreta: tú decides cada cuánto tiempo haces esto), pasarla a la ***Staging Area***.

## A1.3.1. Un momento... ¿Staging quéeee?

La ***Staging Area*** es como la pista de despegue de Git.

La idea es la siguiente: Git no quiere sincronizar tus archivos con el repositorio remoto de forma automática (como hacen las plataformas para el público general, como Google Drive o Dropbox), porque sabe que los programadores producimos mucha basura al cabo del día.

Si cada vez que escribimos una basurilla, Git la sincronizara con el remoto, el resto de personas del proyecto estarían recibiendo nuestra basura de forma permanente. Y nosotros la de esas personas.

Y esparcir basura no es una buena política.

Así que Git quiere que seas muy consciente de cuándo quieres sincronizar algo, y de qué es lo que quieres sincronizar. Quiere que te tomes el trabajo (que tampoco es para tanto, la verdad) de tomarte medio minuto de tu tiempo para decirle: "eh, Git, he estado trabajando en estos dos archivos esta mañana y creo que *ahora* ya no son una basura".

Para eso sirve la Staging Area.

Tienes que pasar los archivos que ya no son una basura a la Staging Area. Y tienes que hacerlo tú, generalmente cuando hayas terminado una funcionalidad y la hayas probado adecuadamente. Lo bastante como para que no te avergüence que otras personas del equipo reciban tu código.

Para añadir archivos a la Staging Area se usa el comando git add, así:

```
$ git add archivo1 archivo2 archivo3 ...
```

Se pueden añadir directorios completos:

```
$ git add directorio1 directorio2 ...
```

Y también se pueden usar símbolos comodín, como el asterisco. De modo que, si estás muy, pero que muy seguro/a de que todos los archivos que han andado tocando desde el último commit están en un estado aceptable, puedes hacer esto para que git se encargue de *añadir todos los archivos modificados recientemente a la Staging Area*:

```
$ git add *
```

Por fin, cuando tengas una o varias cosas preparadas en la Staging Area... Bueno, entonces llega el momento de hacer un **commit**.

## A1.3.2. Hacer commit

Un **commit** (palabra que podríamos traducir por "perpetrar") consiste en empaquetar todos los cambios de la Staging Area para enviarlos a otro repositorio, normalmente el repositorio remoto.

El decir, con el commit le decimos a Git: "quiero que prepares todo el código que te he puesto en la Staging Area a para enviarlo a GitHub" (o a dónde sea).

Se puede hacer un commit por cada pequeña modificación que introducimos en la Staging Area, o se pueden preparar muchos archivos en la Staging Area y luego empaquetarlos en un único mega-commit. Eso lo decidís tú y tu equipo de desarrollo. Pero suele ser buena idea hacer commits de funcionalidades o tareas individuales.

Es decir, si esta mañana he estado trabajando en dos funcionalidades, "Añadir usuarios nuevos" y "Modificar la vista de edición de usuarios", es mejor que haga dos commits separados para cada una de esas funcionalidades.

Esto es así porque, a cada commit, le tengo que añadir ***obligatoriamente*** un texto descriptivo donde indique qué cambios estoy subiendo con ese commit.

El comando para hacer un commit es:

```
$ git commit -m "Mensaje"
```

Ahora saco mi bola de cristal y te digo: no tardarás ni una semana en empezar a hacer commits cuyo texto descriptivo será algo como "aslkdaslkjda", "aaa", "yoquésé". Eso es una pésima idea. Antes o después, alguien del equipo meterá la pata, subirá un cambio indebido y todo el repositorio explotará. Entonces, intentaréis regresar a un estado en el que el código aún funcionaba, pero encontraréis un montón de commits con explicaciones incomprensibles como "aslkdaslkjda", "aaa" y "yoquésé". Y sudaréis tinta para descubrir cuál fue el commit explosivo.

Los commits deben llevar textos descriptivos breves pero informativos. Por ejemplo: "Arreglo el fallo del id de usuario inexistente al actualizar foto de perfil" o "Elimino el botón de modificar de la vista de libros".

Pero, ¡ojo!, hacer commit **no sube los archivos al repositorio remoto**. Todavía no. Recuerda que Git quiere que estés muy seguro/a de que subes lo que realmente tienes que subir, así que aún te falta un último paso: hacer ***push***.

## A1.3.3. Subir el commit: hacer push

El último paso para enviar nuestros cambios locales al repositorio remoto (típicamente, GitHub o GitLab) consiste en hacer ***push***. Es decir, literalmente, "empujar" los cambios al repositorio remoto.

La operación *push* enviará todos los commits que aún no se hayan enviado al repositorio remoto. A partir de ese momento, estarán disponibles para el resto de miembros del equipo. Pero solo a partir de ese momento.

Para hacer push, basta con escribir:

```
$ git push
```

Lo normal es que el repositorio remoto te pida tu nombre de usuario y contraseña, pero eso dependerá de si el acceso a ese repositorio está autenticado o no. Por supuesto, tanto GitHub como GitLab te solicitarán que te identifiques.

## A1.3.4. Bajar la última versión del código

Si podemos subir nuestros cambios al repositorio remoto, tendremos que tener una forma de bajar los cambios del resto de miembros del equipo, ¿verdad?

Por supuesto, existe un comando para ello. Es este:

```
$ git pull
```

Es recomendable hacer pull antes de hacer push, por si alguien a tocado alguno de los archivos que nosotros pretendemos subir. En ese caso, Git nos avisará del conflicto y nos ayudará a resolverlo (más adelante veremos cómo). No podremos hacer push hasta resolver ese conflicto, para evitar pérdidas de código.

## A1.3.5. Resumiéndolo todo: flujo de trabajo habitual con git

Si resumimos lo dicho hasta ahora, tenemos que, después de inicializar el repositorio (cosa que hay que hacer solo una vez), el trabajo cotidiano con Git consiste en:

1. Desarrollar nuestra aplicación con normalidad.
2. Cuando terminamos de hacer algo, añadirlo a la Staging Area (git add).
3. Cada cierto tiempo, o cuando acabamos una funcionalidad, empaquetar todos los cambios que esperan en la Staging Area en un commit (git commit).
4. Bajarnos los commits del resto de miembros del equipo (git pull)
5. Subir nuestros commits al repositorio remoto (git push)

Podemos verlo gráficamente en el siguiente esquema. Las tres primeras columnas (workspace, Staging Area y Local Repo) están en nuestro ordenador de trabajo. El repositorio remoto (Remote Repo) está en un servidor.

```
Workspace   Staging area (INDEX)  Local repo (HEAD)   Remote repo
    |             |                     |                  |
    | git add →   |                     |                  |
    |             |    git commit →     |                  |
    |             |                     |                  |
    | ← ← ← ← ←   |     ← ← ← ← ←       |   ← git pull     |
    |             |                     |                  |
    |             |                     |    git push →    |
    |             |                     |                  |
    |             |                     |                  |
```

Un último apunte: te voy a chivar un comando muy útil de git cuando no estás muy seguro de qué archivos has estado tocando últimamente (¿a quién no le ha pasado eso? ¿Eh?). Este comando te resumirá el estado de tu repositorio local, indicándote qué archivos han sido modificados (pero no están en la Staging Area), qué archivos están preparados en la Staging Area (pero no en un commit) y, por supuesto, qué commits están hechos pero aún sin subir.

Todo eso, gratis y tecleando este humilde comando:

```
$ git status
```

¿Es potente o no es potente este Git? Pues aún no has visto nada.

# A1.4. Algunas cosillas avanzadas sobre git

Solo con lo que hemos visto hasta ahora (add, commit, push y pull) ya tienes suficiente para empezar a funcionar con git. Luego, conforme te surjan otras necesidades, puedes ir curioseando por internet para profundizar en ciertos aspectos.

Una de esas "necesidades" que te surgirán antes o después consiste en lo siguiente:

Imagínate la escena: un día llegas a clase después de haberte acosatado a las tantas trabajando en tu proyecto. Antes de acostarte hiciste un push para subir todos tus cambios y puedes jurar que todo funcionaba perfectamente. Pero ahora, tú y el resto de miembros de tu equipo acabáis de hacer pull y... ¡BUM! El proyecto entero salta por los aires. El homepage no carga. Otras rutas que *estás seguro* de que funcionaban hace unas horas ahora no responden.

¿Qué narices ha pasado?

Tranquilidad: ahí está Git para sacarte del embrollo.

## A1.4.1. Regreso al pasado: cómo revertir los cambios

Las causas de un desastre como ese pueden ser tantas que, en la práctica, es como si fueran infinitas. Un problema con el proxy, un merge mal hecho, una desconfiguración de uno de los servidores locales que ha afectado a algún archivo clave, un error de algún miembro del equipo que ha sobreescrito cientos de archivos con versiones incorrectas... Causas infinitas, como te digo.

No suele compensar el esfuerzo de buscar la razón última de lo que ha ocurrido, salvo que os pase esto con cierta regularidad: entonces sí que es cuestión de preocuparse.

La mayoría de las veces es un problema puntual que puede resolverse de un modo muy simple: volviendo a la última versión estable.

En primer lugar, si lo que quieres es revertir cambios de los que **aún no has hecho commit**, es tan fácil como:

```
$ git reset --hard
```

Pero, la mayor parte de las veces, el problema viene de cambios de los que no solo ya se ha hecho commit, sino que incluso se han subido al repositorio remoto. ¿Cómo descartamos esos cambios para volver a un estado anterior?

En primer lugar, si aún no lo has hecho, ejecuta un **git pull** para traerte la última versión del código a tu repositorio local.

Luego, utiliza el comando **git log**:

```
$ git log (muestra historial de cambios)
$ git log --oneline (muestra historial de cambios simplificado)
```

Con esto obtendrás una lista, ordenada por cronología inversa (de más reciente a más antiguo), de todos los commits que has hecho en el repositorio. Observa que cada commit está identificado con un id único en hexadecimal. Cada id de commit está acompañado de su descripción.

Si habéis sido cuidadosos con los commits y les habéis puesto descripciones representativas (y no "asdfasdf" o "aaa"), resutará fácil localizar en esa lista el commit causante del destrozo.

A continuación, usa el comando **git revert** para regresar al commit *inmediatamente anterior* a aquel en el que se produjo el caos:

```
$ git revert HEAD [main id-de-commit] revert "Mensaje del revert"
```

Lo que hace este comando es devolver tu repositorio local (HEAD) al commit "id-del-commit". Pero, ojo, que no elimina todos los commits posteriores, sino que crea un nuevo commit (main) con el "Mensaje del revert" que le hayas indicado. En este nuevo commit habrá desaparecido todo el código conflictivo. El proyecto volverá a estar en un estado estable.

Ahora bastará con hacer **git push** para subir el nuevo commit al repositorio remoto y que todos los miembros del equipo puedan replicarlo en sus máquinas.

Es posible que, en el proceso, hayáis perdido algo de código valioso: todo depende de cuánto hayáis tenido que retroceder en el historial de commits hasta alcanzar un estado válido. Pero ese código en realidad no se ha perdido, porque los commits siguen ahí, en el historial de git.

Existe una forma de poner el repositorio local en un commit concreto. Si lo haces y abres cualquier archivo fuente, lo encontrarás como estaba en ese commit, no como está en el último. ¿No es maravilloso? Así, podrás recuperar manualmente el código que pudiera haberse perdido al hacer el *git revert*.

El comando que te permite saltar momentáneamente a cualquier commit es **git checkout**:

```
$ git checkout id-del-commit
```

Ahora puedes ver y rescatar el código fuente válido sin temor: nada de lo que hagas en este estado afectará al tu proyecto, porque los cambios se perderán cuando salgas de este "viaje en el tiempo" (salvo que crees una nueva rama del proyecto, pero esa es otra historia).

Y, para regresar al presente, es decir, al último commit, basta con teclear:

```
$ git checkout main
```

## A1.4.2. Cuando dos personas se encaprichan del mismo archivo

Cuando ejecutas *git pull*, traes a tu repositorio local las versiones más recientes de todos los archivos del proyecto. Esto ya lo sabíamos.

Si *git pull* se ejecuta sin contratiempos, aparecerá un mensaje informándote de ello.

Pero los contratiempos existen, qué le vamos a hacer. La vida sería muy aburrida y predecible sin ellos.

El contratiempo más habitual, con diferencia, al hacer *git pull* es el aviso de un conflicto el alguno de los archivos modificados en el repositorio remoto. Eso quiere decir que *tú* has estado tocando el código de un archivo *al mismo tiempo que otra persona de tu equipo*.

Supongamos que, en un archivo A, tú has añadido las líneas A1, A2 y A3, mientras que otra persona ha añadido las líneas A4, A5 y A6. Si la otra persona ha subido el archivo A al repositorio remoto antes que tú, git se dará cuenta cuando intentes hacer *git pull* de que tu copia local del archivo y la que hay en el repositorio remoto no coinciden: no solo porque la tuya tiene las nuevas líneas A1, A2 y A3, sino porque a la tuya *le faltan* las líneas A4, A5 y A6.

En ese caso, y para no perder ninguna de las nuevas líneas de código, git te mostrará un mensaje de advertencia y creará una versión nueva del archivo A en la que estarán **todas las líneas de código nuevas, tanto las tuyas como las de la otra persona**, rodeadas de unas marcas de texto como estas:

```
    <<<<<<< HEAD
        espacio
    ============
        Espacio
    >>>>>>> nueva-rama
```

Ahora, lo único que tienes que hacer es buscar manualmente esas líneas conflictivas y resolverlas a mano, es decir, quedarte con las líneas correctas y borrar las que no lo sean. Borra también todas las marcas que ha puesto ahi git para indicarte el conflicto.

Si usas cualquier editor de texto medianamente potente, te mostrará esas líneas resaltadas e incluso te ayudará a encontrarlas.

Una vez que hayas resuelto manualmente las líneas en conflicto, basta con guardar los cambios y hacer *git add* y *git commit -m "Resolviendo el conflicto bla,bl,bla"* para que el *git pull* y el *git push* vuelvan a funcionar a la perfección.

## A1.4.3. Proyectos que se complican: cómo crear ramas

Imagina esta situación: tienes un proyecto ya en marcha, con una versión más o menos estable funcionando, y entonces surge la necesidad de desarrollar una nueva funcionalidad.

Y esta nueva funcionalidad va a poner patas arriba una parte importante del código y va a dejar la aplicación hecha unos zorros durante un tiempo.

Si trabajas con tu repositorio como hemos hecho hasta ahora, el resultado es que, durante ese tiempo, todo tu proyecto dejará de funcionar. No podrás hacer demos a los clientes (ni a tus profesores/as), no podrás probar la aplicación, no podrás cargarla con datos reales, etc. ¡Todo quedará paralizado hasta que la nueva funcionalidad esté en marcha!

En un equipo de desarrollo grande, esta es una situación cotidiana que provocaría que gran parte de la gente se tuviera que quedar de brazos cruzados a la espera de la finalización de la nueva funcionalidad. Pero incluso en un equipo pequeño es un engorro llegar a este extremo.

Para evitarlo, existen **las ramas** (*branches*) de Git.

Una rama no es más que una copia del repositorio que puede evolucionar por su cuenta mientras la rama original permanece inalterada.

Los desarrolladores/as que trabajen en esa rama pueden así trabajar en la nueva funcionalidad sin que el resto del equipo se vea afectado. Cuando la nueva funcionalidad se termine, lo único que hay que hacer es fusionar las dos ramas. Esto puede ser un trabajo ímprobo si se han estado modificando los mismos archivos en la rama principal y en la rama nueva, pero no se trata de un fallo de Git, que quede claro, sino de un fallo de organización del equipo.

Y si la nueva funcionalidad nunca llega a terminarse (cosa que puede ocurrir por miles de razones), no pasa nada: la rama se elimina, o simplemente se abandona, y la rama principal sigue intacta.

Crear una rama nueva es tan sencillo como usar este comando:

```
$ git branch nombre-nueva-rama
```

El comando *git branch* tiene muchas otras posibilidades. Aquí te pongo unas cuantas:

```
$ git branch --list          (saca un listado de todas las ramas existentes)
$ git branch -d nombre-rama  (elimina una rama)
$ git branch -D nombre-rama  (elimina una rama a lo bestia, incluso si tiene cambios sin fusionar)
$ git branch -m nuevo-nombre (cambia en nombre de la rama actual)
```

Ten en cuenta que, cuando creas una rama, *aún no estás trabajando en ella*. Si quieres cambiar a esa rama para empezar a trastear con ella sin tocar a la principal, debes hacer un *git checkout*:

```
$ git checkout nombre-rama
```

Por último, para fusionar una rama con otra (típicamente, con la rama principal o *main*), tienes que seguir estos pasos:

1. Asegúrate de estar situado en la rama que va a recibir la fusión. Si esa rama es *main*, tienes que hacer:
    ```
    $ git checkout main
    ```
2. Haz un *git pull* para tener disponible la última versión del código.
3. Realiza la fusión de las dos ramas con *git merge*:
    ```
    $ git merge nombre-rama
    ```

En este punto, tendrás que resolver manualmente los conflictos que puedan surgir (si los hay), como hemos explicado más arriba.

## A1.4.4. ¿Aún quieres saber más?

Git es un sistema de control de versiones increíblemente completo. Sus creadores parecen haber pensado en escenarios de lo más aberrante y han tenido en cuenta casi cada cosa que puede suceder en un proyecto complejo. Si no, no se explica la enorme cantidad de comandos y posibilidades que ofrece.

Si necesitas saber más cosas sobre Git, internet está plagada de contenidos de calidad (y otros bastante penosos) sobre este sistema.

Como siempre te recomiendo, acude en primer lugar a la referencia oficial: https://git-scm.com/docs

Personalmente, a mí me gustan mucho los tutoriales de Atlassian. Aunque están orientados a BitBucket (un servicio competidor de GitHub o GitLab), casi todas sus recomendaciones son aplicables a cualquier servidor Git. Los puedes encontrar aquí: https://www.atlassian.com/es/git/tutorials
