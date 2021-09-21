# IES CELIA VIÑAS DOCS - README

This repository contains this documentation about IES Celia Viñas de Almería (España):

* Manual de buenas prácticas digitales.
* DWES - Apuntes para el módulo "Desarrollo web en entorno servidor" (2º DAW)

## Manual de buenas prácticas digitales

The document is markdown formatted and is suitable to publish it by two methods:

### Method 1: Through GitHub Pages
If you want that the repository will be automatically published as GitHub page, its name must be the same that your GitHub username (or GitHub organization), plus "github.io".

For example, if your username or organization name is "myname", the repository must be named as "myname.github.io".

If you do that, the document will be automatically rendered and published when you update it, and it can be read on the URI myname.github.io

### Method 2: Through pandoc
You must clone the repository on your computer or your webserver. Then, go to the root directory of your local repo and execute this command:

```
$ pandoc index.md -t html -o index.html
```

This will convert the Markdown document into a simple HTML document that can be render through a standard web browser.

If you want to create a slightly stylish HTML document, you can use a pandoc template like ***Easy Template*** (the templates must be previsouly installed on ~/.pandoc/templates directory; each template is only an HTML file):

```
$ pandoc index.md -t html -o index.html --template=easy_template.html
```

Even you can add automatically a Table of Contents (TOC):

```
$ pandoc index.md -t html -o index.html --template=easy_template.html --toc
```

Finally, you can automate the publication process on your webserver by writing a simple script that execute ***git pull*** and then execute the pandoc conversion every time you will (for example, when a cron launch the proccess)

## DWES - Apuntes para el módulo "Desarrollo web en entorno servidor" (2º DAW)

Este repositorio contiene la documentación (apuntes) del módulo de ***Desarrollo Web en Entorno Servidor*** del Ciclo Formativo de Grado Superior de Desarrollo de Aplicaciones Web impartido en el IES Celia Viñas de Almería (España).

El contenido está escrito con Markdown y renderizado a HTML con Jekyll. Puede desplegarse directamente en cualquier servidor web con un ***git pull***. El sitio web estará accesible en el subdirectorio *sites*. 

También puede subirse solo el directorio *sites* mediante FTP u otro método similar.

Necesitará modificar el archivo *config.yaml* para indicar la *base_url* de su servidor y que todos los enlaces funcionen. Es posible que también necesite hacer un "buscar y reemplazar" en todos los archivos para cambiar las rutas base de las imágenes si estas no cargan adecuadamente. Regenere el sitio con jekyll después de hacer los cambios y vuelva a subirlo a su servidor. Todo debería funcionar después de eso.

## PROG-Y-3d - Apuntes de la asignatura "Introducción a la programación y al diseño 3D" (2º Bachillerato)

Este repositorio contiene la documentación (apuntes) de la asignatura "Introducción a la programación y al diseño 3D", optativa ofertada por el IES Celia Viñas de Almería en 2º de Bachillerato.

El contenido está escrito con Markdown y renderizado a HTML con Jekyll. Puede desplegarse directamente en cualquier servidor web con un ***git pull***. El sitio web estará accesible en el subdirectorio *sites*. 

También puede subirse solo el directorio *sites* mediante FTP u otro método similar.

Necesitará modificar el archivo *config.yaml* para indicar la *base_url* de su servidor y que todos los enlaces funcionen. Es posible que también necesite hacer un "buscar y reemplazar" en todos los archivos para cambiar las rutas base de las imágenes si estas no cargan adecuadamente. Regenere el sitio con jekyll después de hacer los cambios y vuelva a subirlo a su servidor. Todo debería funcionar después de eso.
