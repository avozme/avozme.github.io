---
layout: page
title: X. Entornos integrados de desarrollo
permalink: /entornos-integrados-de-desarrollo/
nav_order: X
has_children: true
parent: none
---

# 7. Entornos integrados de desarrollo
{: .no_toc }

- TOC
{:toc}

**Entornos integrados de desarrollo. Depuración. Ciclo de vida del software. Trabajo en equipo y mejora continua. Control de versiones. Metodologías ágiles: Scrum.**
XXX

## 7.1. Editores de texto

XXX

## 7.2. Editores de código

Estrictamente hablando, Visual Studio Code es un **editor de código**, no un IDE.

Los editores de código son soluciones intermedias entre los editores de texto (más sencillos) y los IDEs (más sofisticados).

Los editores de código no solo permiten editar el texto, sino que proporcionan herramientas adicionales para el programador: atajos de teclado, resalto de la sintaxis del lenguaje, autocompleción del texto, etc.

XXX

 la hora de codear que le facilita a la vida a los devs. ¿Por ejemplo? syntax highlighting (coloreado de sintaxis) o code completion (que ayuda a completar los nombres de clases, métodos, campos y palabras clave).

¿Cuál es la particularidad de los IDE? Son entornos de desarrollo mucho más complejos que integran varias herramientas para el desarrollo de software en una sola aplicación. Y tan solo uno de sus componentes es editor de código.
¿Qué es Visual Studio Code?

Como dijimos, para cada editor de código existe una subcultura asociada. Los programadores se encargan de mantener vivos estos editores, ofrecen mejoras y actualizaciones y promueven su uso entre aquellas personas que recién se inician en el mundo del desarrollo.

Lo que es seguro, es que, para quienes recién comienzan, Visual Studio Code es la puerta de entrada. Este editor de código fue desarrollado por Windows -aunque también funciona muy bien en Mac-. ¿Qué ofrece? Una consola integrada, atajos y comandos que te ayudan a codear más rápido y extensiones muy útiles.

Este editor es gratuito, open-source, muy estable y rápido, y proporciona acciones y recursos muy interesantes que lo convierten en uno de los preferidos por los desarrolladores.
¿Qué podemos hacer con VS Code?

    Autocompletar con IntelliSense
    Descripción automática en tiempo real de la API
    Abrir y ordenar múltiples carpetas
    Realizar una comparación de versión lado a lado
    Editar de manera colaborativa y en vivo
    Es compatible con más de 30 lenguajes.

Visual Studio Code es muy amigable para quienes recién comienzan a aprender a programar, así que si recién estás dando tus primeros pasos en programación y quieres una herramienta que te potencie, ya sabes.

Introducción

Como desarrollador, es importante disponer de las mejores herramientas para realizar el trabajo. En el pasado, Salesforce ofreció muchas herramientas y cada una de ellas proporcionaba algo que faltaba en otras del mercado. Esta guía de inicio rápido le ayudará a familiarizarse en el próximo paso hacia nuestras increíbles herramientas para desarrolladores: Salesforce Extensions con Visual Studio Code.
Pero primero, ¿qué es un IDE?

Un IDE, o entorno de desarrollo integrado, se compone de un editor de código, herramientas de automatización de creación, un depurador y una finalización de código inteligente. Visual Studio Code ofrece todos estos componentes.
Seguir la ruta juntos

¿Desea seguir con un instructor a medida que trabaja en este paso? Eche un vistazo a este video, que forma parte de la serie Trail Together en Trailhead Live. Encontrará un vínculo a la sesión completa en la sección Recursos. 

Instalación de Visual Studio Code

Puede instalar Visual Studio Code en cualquier computadora que utilice macOS, Windows o Linux. Los requisitos del sistema son relativamente asequibles, por lo que puede ejecutarse en cualquier computadora.

    Descargue e instale la versión más reciente de Visual Studio Code para su sistema operativo. Si ya instaló Visual Studio Code, no es necesario volver a instalarlo.
    Inicie Visual Studio Code.

Familiarizarse con la interfaz

Página de bienvenida de Visual Studio Code.

La página de bienvenida de Visual Studio Code se abrirá automáticamente la primera vez que ejecute la aplicación. Esta página ofrece numerosos vínculos de acceso directo que permiten comenzar a trabajar con nuevos archivos, aprender acerca de Visual Studio Code o incluso personalizar la interfaz en función de sus preferencias. 

    En Learn (Aprender), haga clic en Interface Overview (Descripción general de la interfaz) para abrir una descripción visual de las distintas características de Visual Studio Code. La superposición Interface Overview (Descripción general) de la interfaz destaca elementos clave de navegación en el IDE de VS.Esta superposición le permite visualizar todo lo que es capaz de hacer Visual Studio Code. La barra inferior muestra las notificaciones, las advertencias y los errores actuales. También permite cambiar al terminal integrado.

    En la parte izquierda del editor podrá utilizar el explorador de archivos, buscar archivos, gestionar su código fuente, iniciar o depurar su código y gestionar extensiones. (En un futuro, también se instalarán varias extensiones para ayudar con el desarrollo.) Por último, también hay un menú que permite ejecutar comandos en el editor. Esta es otra sección que exploraremos muy pronto.
    Haga clic en cualquier punto de la pantalla para descartar la superposición visual.
    En Iniciar, haga clic en New file (Nuevo archivo).
    Haga clic en Text Editor (Editor de texto).
    En este espacio podemos comenzar a escribir. Agregue el texto Hello World en la línea 1. Documento sin título con Hello World en la primera línea de código.
    Cierre el archivo sin guardar.

Nota

Puesto que aún no guardó el código, Visual Studio Code no destaca nada.


## 7.3. Entornos integrados de desarrollo

Un **IDE** o **Entorno intrado de desarrollo** es un programa informático que proporciona, dentro del mismo programa, acceso a todas las funciones fundamentales para el desarrollo de software: edicion del código fuente, compilación, depuración, ejecución..

Con estas herramientas resulta mucho más cómodo y rápido programar que utilizando cada una de esas herramientas por separado.

Algunos IDEs son monstruos devorarrecursos que disponen de herramientas adicionales potentísimas, como autocompleción de sentencias, generador automático de código, analizador del rendimiento, refactorizador, soporte multilenguaje... Otros son más simples y ligeros, y disponen de un editor sencillo y unos pocos menús para guardar, editar y ejecutar los programas.

La elección del IDE es algo muy personal. Llegarás a una conclusión después de tener alguna experiencia con varios de ellos.

En este capítulo vamos a introducir el uso de un IDE con una enorme aceptación en los últimos años: **Visual Studio Code**.

Hay muchísimos IDEs en el mercado, algunos muy complejos como Netbeans o Eclipse, otros muy livianos como Geany, Vim o Atom. ¿En qué se diferencian unos de otros?

Hay varios factores cruciales: velocidad, versatilidad, rendimiento, complementos, funcionalidad, compatibilidad con determinados lenguajes, apariencia, etc. Cada desarrollador ha tenido siempre sus preferencias, pero en los últimos tiempos parece haber un consenso imposible entre los programadores de todo el mundo: Visual Studio Code es el IDE número uno del mundo.

