---
layout: page
title: 1.4 Prestashop
permalink: /cms/prestashop
nav_order: 4
has_children: false
parent: 1 Sistemas gestores de contenido (CMS)
grand_parent: Desarrollo Web en Entorno Servidor
---



## 1.4. Prestashop
{: .no_toc }

- TOC
{:toc}

(La información de esta sección está adaptada de [doc.prestashop.com](https://doc.prestashop.com), donde se publicó originalmente con licencia *free Atlassian Confluence Open Source Project*. En el momento de escribir estas líneas, la documentación ya no está en línea, pero aún puede encontrarse en [The Wayback Machine](https://archive.org))

### 1.4.1. Características de Prestashop

Prestashop es un CMS de código abierto para la creación de comercios online de cualquier tipo. Actualmente es el líder indiscutible en su sector, aunque tiene algunos competidores serios como *Magento*, *VooCommerce* (un plugin para Wordpress), *VirtueMart* (un plugin para Joomla!) o *Shopify*.

Como sucede con otros CMS de código abierto, aunque el código fuente de Prestashop es libre y gratuito y dispone de muchos plugins y plantillas que también son gratuitas, hay muchas otras de pago. En el caso de Prestashop, esta vía de negocio es aún más acusada que con Wordpress o Moodle, de manera que es difícil (aunque no imposible) poner en marcha una tienda online basada en Prestashop sin recurrir a algunos complementos de pago.

En esta sección, vamos a hacer un repaso muy rápido a las características principales de Prestashop.

### 1.4.2. Instalación de Prestashop

#### Requisitos previos

Para instalar PrestaShop necesitas, como pasa con cualquier CMS escrito en PHP, un servidor web con soporte para PHP y un servidor de bases de datos (MySQL, MariaDB, PostgreSQL o similar).

La configuración del servidor es algo más exigente que con Wordpress. Como sucedía con Moodle, necesitarás que ciertas extensiones estén habilitadas en el servidor para que Prestashop funcione correctamente. Asegúrate de contratar un proveedor de hosting que sea compatible con Prestashop antes de ponerte en marcha, o contacta con tu proveedor actual para ver qué posibilidades de reconfiguración de tu servidor actual te ofrece.

Además, necesitarás un mínimo de 128 MB de RAM exclusivos para PHP. Pero eso solo es el mínimo. Prestashop consume muchos recursos. Cuanta más RAM tenga PHP a su disposición, mejor.

Prestashop recomienda encarecidamente la instalación sobre un sistema Unix o tipo Unix (es decir, Linux). Siempre funcionará mejor y de forma más segura que sobre un servidor de Microsoft.

Durante la instalación, el propio instalador hará un chequeo del servidor y te informará de cualquier problema de configuración antes de continuar. Pero, si lo prefieres, puedes consultar previamente la [página oficial de requisitos del sistema](https://www.prestashop.com/es/requisitos-de-sistema).

#### Proceso de instalación

Muchos proveedores de hosting permiten instalar Prestashop (igual que Wordpress, Moodle y muchos otros CMS) desde el panel de administración del propio hosting, con un par de clics. Si ese es tu caso, enhorabuena.

Si no, siempre puedes recurrir a una instalación manual. El proceso de instalación de Prestashop es semejante al de cualquier otro CMS. A grandes rasgos, se trata de seguir estos pasos:

1. Descarga la última versión de Prestashop del [sitio oficial](https://prestashop.com).
2. Sube el código fuente de Prestashop a tu servidor. Mejor si preparas previamente una carpeta para alojarlo. Ni que decir tiene que esa carpeta debería estar en una ubicación accesible vía web (es decir, dentro de *htdocs*, *httpdocs* o *public_html*). 
3. Crea una base de datos vacía en tu servidor.
4. Lanza la instalación. Para eso, basta con que escribas la URI donde has alojado el código fuente de Prestashop.
5. Sigue las instrucciones del instalador.
6. Cuando la instalación haya terminado, elimina la carpeta /install.

#### Algunos trucos y consejos

Utiliza siempre una versión de prueba, mejor en localhost, pero también puedes hacerlo en cualquier servidor.

Cuando la hayas dejado a tu gusto, puedes moverla a su ubicación definitiva. Mover un Prestashop de un servidor a otro es como mover cualquier otro CMS: te llevas todos los archivos, la base de datos y cambias los datos de configuración (en el archivo *app/config/parameters.php*).

No elimines tu versión de prueba de Prestashop. Más adelante, puede servirte como entorno de preproducción para probar cambios en tu tienda online sin que afecte a la versión en producción.

### 1.4.3. Y después de instalar, ¿qué? Breve guía para el administrador novato

Prestashop construye toda la infraestructura para montar una tienda online, pero no la tienda en sí. Es decir, alguien se tiene que encagar de subir los productos, las categorías, los precios, las ofertas especiales... 

Las posibilidades de Prestashop son inmensas y, al principio, los administradores pueden sentirse un poco perdidos al acceder al panel de administración. En esta sección hablaremos de las acciones más comunes en el trabajo inicial con Prestashop (cuando áun estás montando la tienda) y también en el día a día cuando la tienda ya está en uso.

En esta sección, vamos a resumir los pasos más importantes que debe dar un administrador cuando pretende poner en marcha una tienda online con un Prestashop recién instalado.

#### Acceder al panel de administración

Lo primero que tienes que saber es cómo entrar al *panel de administración* o "sala de máquinas" de tu Prestashop.

Simplemente, abre tu navegador web preferido y añade la ruta "admin" a la URI de tu Prestashop.

Es decir, si instalaste Prestashop en https://mi-servidor/mi-prestashop, encontrarás el acceso al panel de administración en https://mi-servidor/mi-prestashop/admin

#### Desactivar la tienda online: modo mantenimiento y modo catálogo

Una tarea habitual tras finalizar una instalación limpia, o cuando vas a meter mano a lo bestia en tu tienda, es poner Prestashop en *"modo mantenimiento"*, de manera que cualquier posible visitante no se encuentre una tienda a medio construir (lo cual da muy mala imagen), sino el aviso de que la tienda está, en efecto, a medio construir.

Acceder al panel de administración y ve a la sección *"Shop Parameters / General"*. Las opciones sobre el modo mantenimiento están en la segunda pestaña.

Además de activar/desactivar tu tienda, puedes indicar una dirección IP a través de la cual tú podrás seguir visitando la tienda para ver cómo quedan los cambios.

Cuando ya te hayas decidido por una plantilla y hayas subido unos cuantos productos, puedes preferir poner la tienda en *"modo catálogo"*. Esto es un punto intermedio entre el *"modo mantenimiento"* (la tienda es completamente inaccesible) y el modo de funcionamiento normal. En el *"modo catálogo"*, los visitantes podrán navegar por tu tienda y visitar los productos, pero no les aparecerán ni los precios ni los botones de compra.

Puedes activar/desactivar el *"modo catálogo"* en la sección *"Shop Parameters / Products Settings"* del panel de administración.

#### Borrar el contenido por defecto de la tienda

La instalación por defecto de Prestashop incluye un conjunto de datos de ejemplo que seguramente querrás eliminar. Los datos de prueba dependen de tu instalación concreta y de la versión de Prestashop.

Los datos de ejemplo que tendrás que eliminar incluyen productos, categorías, atributos, proveedores, imágenes, etiquetas, pedidos, clientes y páginas estáticas. Sin embargo, *tal vez te interese conservar por un tiempo estos datos de prueba para ver cómo luce la tienda cuando tiene datos cargados*, al menos hasta que acabes de echar un vistazo a todas las opciones de Prestashop.

Para eliminar todo esto, puedes bucear por el panel de administración y borrar los elementos que no te sirven de uno en uno (o, tal vez, modificar algunos en lugar de borrarlos para adaptarlos a tus necesidades). Es un trabajo largo y tedioso.

Por suerte, existe un ***plugin*** llamado *Database Cleaner* que te permitirá resetear la base de datos de forma muy rápida:

* Accede a la sección *"Modules > Modules & Services"* del panel de administración.
* Busca el módulo *"Database Cleaner"* y haz clic en el botón *"Install"*. Esto instalará el plugin.
* Haz clic en el botón *"Configure"*.
* Acepta el *warning* y haz clic en los botones *"Delete Catalog"* y *"Delete Orders & Customers"*. Esto limpiará de datos tu base de datos. ¡Cuidado! A menos que tengas copia, esos datos son irrecuperables.
* Haz clic en el botón *"Check & fix"* para revisar la integridad de tus tablas.
* Haz clic en el botón *"Clean & optimize"* para reorganizar los índices y dejar la base de datos en condiciones óptimas.

#### Configuración básica de tu tienda online

Ahora nos refererimeos a las cosas que tienes que configurar necesariamente a la hora de crear una tienda con Prestashop.

Antes de nada, es importante que entiendas que una cosa es la configuración del núcleo de Prestashop y otra la configuración de cada *plugin*, que en Prestashop se denominan *módulos*.

El núcleo de Prestashop se configura buceando en el panel de administración, en las secciones que veremos a continuación. En cambio, los *plugins* se configuran desde *"Modules" > "Installed Modules" > "Configure"*. Como es lógico, cada *plugin* tiene sus propias opciones de configuración y debes remitirte a la documentación del desarrollador para conocerlas.

Aquí nos referiremos únicamente a la configuración básica del núcleo de Prestashop y de algunos módulos especialmente útiles.

Una vez aclarado esto, entremos en faena. Cuando tengas una instalación limpia de Prestashop preparada, las cosas que debes configurar como mínimo son estas:

* **El nombre de tu negocio**. Se hace en *"Shop Parameters" > "Contact" > "Stores" > "Contact details" > "Shop name". Esto es muy importante hacerlo para que los buscadores te indexen adecuadamente.
* **El logo de la tienda**. El logo se verá en todas las página de la tienda online y en las facturas y emails que se emitan desde la tienda. Se accede a él en la ruta *"Design" > "Theme & Logo" > "Your current theme".
* **La moneda por defecto**. Es la moneda en la que se mostrarán los precios de los productos. Se configura en *"International" > "Localization" > "Configuration"*.
* **La información de contacto de la tienda**. Hay que establecer, al menos, el número de teléfono y una dirección de email. Se hace en *"Shop Parameters" > "Contact" > "Stores" > "Contact details"*.
* **Slider de imágenes**. El *slider* es una secuencia de imágenes que aparecen una tras otra, normalmente en la parte superior del *home* (aunque esto depende de la plantilla). Es *slider* es importantísimo desde el punto de vista del atractivo visual de la tienda. Puedes definirlo en la sección dedicada al módulo *"Image slider"*.
* **Páginas estáticas**. Las páginas estáticas, como en Wordpress, se usan para crear las típicas páginas de "Acerca de", "Aviso legal", "Términos y condiciones" y cosas así. Encontrarás que algunas ya existen en los datos por defecto, y puedes adaptarlas a tus necesidades. Otras tendrás que crearlas por tu cuenta. En ambos casos, puedes hacerlo desde *"Design" > "Pages"*.
* **Redes sociales**. Las principales redes sociales de la empresa pueden gestionarse desde el módulo *"Social media follow links"*.
* **Top menu**. El *top menu* es el menú principal de tu tienda. Suele mostrarse en la parte superior de todas las páginas, aunque esto, lógicamente, podría cambiar según la plantilla que uses. En el *top menu* puedes mostrar tus categorías de productos, así como links a otras páginas. Se gestiona desde el módulo *"Main menu"*.
* **Contenido de la *homepage***. La plantilla por defecto incluye contenido variado para el *home*: textos, imágenes, links, etc. Si vas a usar el tema por defecto, puedes modificar este contenido (o eliminarlo antes de crear el tuyo).

   La *homepage* se manipula a través de diferentes módulos. Estos son los principales a los que deberías echar al menos un vistazo:
   * *Banner*: Para cambiar la imagen que aparece al final de la *homepage*.
   * *Custom text blocks*: Mensajes de texto que aparecen debajo del banner.
   * *Theme modules*: Configuración de la plantilla actual.
   * *Legal compliance*: Información legal, que puede variar según el mercado al que te dirijas.

* **Idioma, métodos de pago y envíos**. Estos tres elementos son muy importantes y algo más complejos de configurar, por lo que los vamos a tratar en los siguientes apartados.
* **Instalar plugins y plantilla**. También hablaremos de ello un poco más abajo.
* **Dar de alta categorías y productos**. Cuando hayas pasado por todos los puntos anteriores, habrá llegado el momento de comenzar a dar crear categorías y productos en tu Prestashop. A partir de ahí, tu tienda online será plenamente funcional.

A continuación, discutimos con un poco más de detalle algunos de los puntos anteriores.

#### Cambiar el idioma

Prestahop se instala por defecto en inglés. Si te has bajado el paquete de instalación en otro idioma, se instalará ese otro idioma y, además, el inglés, por lo que puedes estar seguro de que, sea cual sea la instalación de Prestashop con la que trabajes, la encontrarás, al menos, en inglés.

Por eso es buena idea que te familiarices con el interfaz del panel de administración en inglés. Así, de paso, practicas el idioma.

Cuando hay varios paquetes de idioma instalados, el front-end mostrará un selector en la parte superior para que el visitante elija en qué idioma desea ver la página. El back-end también se mostrará en los diferentes idiomas, aunque, en este caso, tendremos un selector de idioma para cada campo de texto.

Si necesitas **instalar cualquier otro idioma**, puedes hacerlo desde el menú *"International" > "Localization / Languages"*.

Puedes instalar todos los paquetes de idioma que quieras, pero ten en cuenta que *las descripciones de los productos tendrás que traducirlas tú*. También los nombres de los productos, las categorías, las etiquetas, las páginas estáticas, etc. Prestashop no lo hará automáticamente por ti.

#### Métodos de pago

Otra cosa muy importante es configurar los métodos de pago. Esto se hace en *"Modules" > "Installed Modules" "Payments & Gateways". Muchos métodos de pago necesitarán que primero te registres como vendedor en el servicio correspondiente, como, por ejemplo, PayPal.

Por defecto, solo estarán activados dos métodos de pago: "Cheque" y "Transferencia bancaria". Ambos deben configurarse con tu información bancaria para poder recibir los pagos. Esto se hace en los módulos *"Payments by check"* y *"Wire payment"*.

Si activas cualquier otro método de pago, tendrás que configurarlo, como es lógico, desde su módulo. Y si no encuentras el método de pago que necesitas, puedes instalar otros desde el [*marketplace* de plugins de Prestashop](http://addons.prestashop.com/en/4-payments-gateways-prestashop-modules).

#### Configuración de los envíos

Cualquier tienda online necesita que configures también los envíos (excepto si lo que vendes son productos descargables, claro). 

Los envíos se configuran en el menú *"Shipping"*. Los envíos por correo, si los vas a llevar tú en persona a la oficina, son los más fáciles de configurar. Si contratas los envíos con cualquier empresa de transportes, necesitarás instalar el módulo para Prestashop de esa empresa para poder configurar y automatizar los envíos, de manera que los compradores puedan acceder, por ejemplo, a la información de seguimiento del mismo.

La devolución de productos está, en principio, deshabilitada. Si deseas habilitarla y configurarla, echa un vistazo a *"Customer service" > "Merchandise returns" > "Merchandise return (RMA) options".

#### Instalación de plugins (modules)

Prestashop tiene un montón de plugins (o *modules*, en jerga de Prestashop) disponibles para realizar tareas de lo más diverso: análisis de tráfico, métodos de pago y envío, diseño y navegación por la web, *marketing*, etc. Eso, solo entre los plugins "oficiales" que puedes encontrar en el *marketplace* de Prestashop. Si hablamos de plugins de terceras partes, la oferta se multiplica.

El ecosistema de plugins es tan amplio que no es posible tratarlo aquí ni en ningún otro sitio. Si alguna vez necesitas alguna funcionalidad extra de Prestashop, simplemente bucea por el *marketplace* para buscar un plugin que haga lo que necesitas. La dirección de *marketplace* oficial de Prestashop es: [http://addons.prestashop.com/en/2-modules-prestashop](http://addons.prestashop.com/en/2-modules-prestashop).

Cuando instales un plugin, tendrás que activarlo y configurarlo. Asegúrate de que funciona correctamente y que se lleva bien con tu plantilla antes de continuar. Si te causa problemas, prueba a cambiar la configuración o, en última instancia, desinstálalo e inténtalo con otro. Un plugin desmadrado puede fastidiar el funcionamiento de toda la web.

#### Elección de la plantilla (theme)

Dejamos para el final uno de los aspectos más importantes en cualquier CMS: elegir e instalar una plantilla.

La plantilla o *theme*, como en Wordpress, Moodle o cualquier otro CMS, determina la manera en la que se ve tu web. Es decir, afecta al aspecto pero no al contenido. Existen muchas plantillas para elegir en el *marketplace* de Prestashop: [http://addons.prestashop.com/en/3-templates-prestashop](http://addons.prestashop.com/en/3-templates-prestashop). Muchas son gratuitas, otras muchas de pago y, la mayoría, tienen una versión gratuita limitada y una versión de pago con más opciones.

También puedes desarrollar tu propia plantilla, por supuesto. Hay toda una rama de programadores profesionales especializados en desarrollo de plantillas y plugins para Prestashop. Sin embargo, eso excede de los propósitos de este texto.

### 1.4.4. Explotación de Prestashop

Después de instalar y configurar los aspectos más importantes de tu Prestashop, ya te habrás familiarizado bastante con el panel de administración.

En esta sección, vamos a hacer un rápido recorrido por ese panel por si se te ha escapado algo.

El diseño del panel de administración, como en cualquier CMS, puede variar un poco entre versiones. En general, es un panel intuitivo y fácil de usar, aunque al principio puede intimidar un poco por el elevado número de elementos que contiene. Vamos a tratar de poner un poco de orden en ese caos.

#### La barra superior

La barra superior del panel de administración contiene información muy útil y links importantes:

* La versión de Prestashop.
* Links de acceso rápido (se pueden configurar a tu gusto haciendo clic en *"Manage quick accesses"*).
* Barra de búsqueda.
* Modo depuración. Puede ayudarte a localiar la causa del error si estás teniendo problemas con tu Prestashop o con algún módulo.
* *View my shop*. Esto sirve para ver la tienda como la vería un visitante.
* Notificaciones pendientes (incluye los últimos pedidos sin procesar).
* Enlace directo a los últimos pedidos realizados, los últimos clientes registrados y los últimos mensajes recibidos.
* Acceso al perfil del usuario que está logueado.

#### Menús

Durante la administración de una tienda Prestashop, tendrás que navegar constantemente por un montón de páginas con opciones de configuración. El menú principal persigue facilitar esa navegación.

Desde Prestashop 1.7, el menú principal está dividido en 3 grandes secciones:
1. ***Sell***. Esta es la sección en la que más se trabaja en el día a día de la explotación de un Prestashop. Aquí encontrarás el acceso a los pedidos realizados y al catálogo de productos en venta. También puedes acceder a los clientes, a la atención al cliente (devoluciones y cosas así) y a las estadísticas de visitas y ventas.
2. ***Improve***. En esta sección, puedes modificar la configuración de tu Prestashop para adaptarlo a tus necesitades. Aquí encontrarás el acceso a los módulos (plugins) instalados, las plantillas, los métodos de pago y envío y la configuración del idioma.
3. ***Configure***. En esta sección encontrarás la configuración avanzada de Prestashop, así que, en principio, no tienes necesidad de tocar nada. Hay cosas como configuración de los backups automáticos, empleados de la empresa, configuración de algunos parámetros del núcleo de Prestashop, configuración del servidor web...

#### Los botones

Muchas página del panel de administración usan botones en la parte superior e inferior. Por ejemplo, la página para editar un producto puede mostrar hasta 8 botones al mismo tiempo.

Los botones siempre son los mismos y tienen el mismo comportamiento en todo el panel de administración. Los más habituales son los siguientes:
* ***Add new***. Abre una página de creación de un recurso, dependiendo del contexto: un nuevo producto, una nueva categoría, un nuevo pedido...
* ***Recommended Modules and Services***. Abre una ventana modal que contiene los módulos (plugins) disponibles en el contexto actual. Por ejemplo, en la página *"Shipping > Carriers"*, este botón mostrará los plugins instalados en la categoría *"Shipping & Logistics"*. Es muy útil cuando necesitas encontrar rápidamente qué módulo es adecuado instalar o configurar para obtener un resultado concreto.
* ***Save*** y ***Save and stay***. Almacena los cambios que se hayan hecho en la página actual. La única diferencia entre uno y otro es que el primero regresa a la página anterior y, el segundo, permanece en la página actual.
* ***Export*** e ***Import***. Exporta o importa los datos de la página actual en formato CSV (texto plano).
* ***Refresh***. Vuelve a cargar los datos de la página actual sin abandonarla.

#### Las tres columnas principales del panel de administración

Además de los elementos anteriores, al entrar al panel de administración de Prestashop encontrarás tres columnas que ocupan casi todo el espacio disponible. Estas tres columnas, aunque puedan parecer abarrotadas a primera vista, proporcionan un excelente resumen del estado de tu tienda online.

Encima de las tres columnas hay una barra que permite **seleccionar el periodo de tiempo** para el que se muestran los datos del resto del panl. Se pueden seleccionar valores como "día actual", "mes actual", "año actual", "mes anterior", "año anterior", etc. También se puede seleccionar un rango de fechas cualquiera.

Al cambiar el selector de fechas, los bloques de contenido del resto del panel se actualizan para mostrar los datos correspondientes a ese periodo.

* La **columna izquierda** ofrece un vistazo rápido de la actividad de tu tienda en el periodo seleccionado: visitantes, carritos activos, pedidos pendientes de servir, solicitudes de devolución pendientes, carritos abandonados, stock de productos y estadísticas diversas.
* La **columna central** muestra varios gráficos de ventas y una lista de los últimos pedidos. Se pueden seleccionar varios gráficos de gran interés para comprobar la evolución de las ventas, e incuso se pueden comparar varios gráficos entre sí para obtener más información. Haciendo clic en el botón de configuración, accedemos a otra página donde se muestran los ingresos y los gastos, así como el grado de consecución de los objetivos.
* La **columna derecha** es de tipo informativo y contiene las última noticias sobre Prestashop, así como notificaciones sobre nuevas versiones y enlaces útiles.

