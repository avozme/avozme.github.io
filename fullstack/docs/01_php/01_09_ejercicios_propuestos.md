---
layout: page
title: 1.9 Prácticas
permalink: /php/ejercicios-propuestos.html
nav_order: 9
has_children: false
parent: 1 Programación web con PHP
grand_parent: Desarrollo web full stack
---


## 1.9. Prácticas
{: .no_toc }

- TOC
{:toc}

Los siguientes son una colección de prácticas de programación que funcionan exactamente igual que los ejercicios en el gimnasio: para fortalecer tu musculatura como programador o programadora.

E igual que los ejercicios en el gimnasio, estos requerirán de ti dedicación, esfuerzo y constancia. Pero por eso estás aquí, ¿no es cierto? Recuerda lo que hemos dicho muchas veces: ***a programar solo se aprende programando***.

#### Ejercicio 0: hola, mundo

Este ejercicio lo usaremos para probar la correcta puesta en marcha de nuestro **servidor web local**. 

Tienes dos opciones, como mínimo, para poner en marcha el servidor local:

1. **Instalar un servidor nativo**: instala un paquete como XAMPP o instala manualmente Apache y MariaDB en tu sistema operativo. Luego ve al directorio *htdocs* de tu Apache y escribe un programa "holamundo.php"
2. **Lanzar un servidor virtualizado con Docker (RECOMENDADO)**: baja y configura las imágenes para Apache, MariaDB y PHP. Lánzalas y pruébalas con un programa "holamundo.php". Tienes toda la información sobre cómo hacerlo en el [Apéndice 2](../docker/#a24-montando-con-docker-un-servidor-web-con-persistencia-de-datos).

Para hacer el resto de ejercicios y prácticas, puedes usar cualquiera de los dos servidores.

#### Ejercicio 1: comparar números

Vamos a hacer un primer ejercicio muy, muy sencillo para que te vayas soltando con la sintaxis de PHP y la forma de trabajar en el servidor.

Tienes que escribir un programa en PHP que:

1. Pida dos números al usuario a través de un formulario HTML.
2. Los compare para ver cuál es el menor de los dos.
3. Muestre todos los números que hay entre el menor y el mayor.

#### Ejercicio 2: anagramas

Una palabra es un anagrama de otra si contiene las mismas letras colocadas en orden diferente. Por ejemplo, "CAVA" es un anagrama de "VACA", y viceversa.

El ejercicio consiste en escribir un programa en PHP que pida al usuario dos palabras y compruebe si la primera es un anagrama de la segunda. Para ello necesitarás:

1. Crear un formulario HTML con un campo de texto y un botón de envío.
2. Procesar el formulario en otro archivo PHP (usa $_GET y $_POST para probar ambos métodos).
3. Añadir validaciones básicas (por ejemplo, que el campo no esté vacío).

#### Ejercicio 3: conexión básica a una base de datos

1. Crea una base de datos MySQL o MariaDB con una tabla *usuarios(id#, nombre, email, password)*.
2. Inserta algunos datos de prueba en la tabla.
3. Conéctate desde PHP a esa base de datos.
4. Inserta datos desde PHP con una consulta preparada. Necesitarás, por un lado, un formulario HTML para pedirle los datos al usuario y, por otro, un pequeño programa PHP que procese el envío del formulario y proceda a insertar los datos en la BD.
5. Haz después un SELECT * de la tabla que muestre el resultado en una tabla HTML, para asegurarte de que la inserción ha funcionado.

#### Ejercicio 4: CRUD sencillo

Utiliza la misma base de datos del ejercicio anterior para:

1. Implementar un listado de usuarios que, además, incluya las opciones de insertar, modificar y borrar usuarios (CRUD = Create, Read, Update, Delete).
2. Divide el CRUD en diferentes archivos PHP (list.php, create.php, edit.php, delete.php, etc).

#### Ejercicio 5: Autenticación con login básico

1. Añade a la tabla usuarios un campo rol (p. ej. admin, editor, user...).
2. Crea un formulario de login que valide usuario y contraseña.
3. Si es correcto, redirige la aplicación al área privada (el CRUD que hiciste en el ejercicio anterior).
4. Si no, regresa al login y muestra un mensaje de error.

#### Ejercicio 6: Sesiones y seguridad mínima

1. Amplía el código del ejercicio anterior e inicia sesión con *session_start()* tras un login correcto.
2. Guarda el id del usuario y su rol en variables de sesión.
3. Asegúrate de que las páginas del CRUD solo son accesibles si existe sesión iniciada.
4. Añade un botón de Cerrar sesión que destruya las variables de sesión y regrese al login.

#### Ejercicio 7. Listas de control de acceso

Modifica la aplicación que estamos construyendo para que:

1. Solo los usuarios de tipo administrador (rol = admin) puedan acceder a todas las funciones del CRUD.
2. Otros usuarios registrados pero no administradores podrán ver la tabla de usuarios pero no operar con ella (ni insertar, ni borrar ni modificar). Si lo intentan, debe aparecer un mensaje de tipo "Acción prohibida".
3. Centraliza la lógica de los permisos en un archivo común (security.php).

#### Ejercicio 8. Aproximación a MVC en PHP

Reestructura todo el código que has construido hasta ahora en tres carpetas:

* **models/** (consultas a la base de datos)
* **views/** (HTML/PHP para mostrar datos)
* **controllers/** (reciben la petición y deciden qué hacer).

Configura un único index.php que reciba la acción (?action=...) y redirija al controlador correspondiente.

***Puedes, y te aconsejo que así lo hagas, fijarte en el [código fuente de la Biblioteca](../php/mvc/#175-una-implementaci%C3%B3n-completa) que hemos visto en clase para hacer este último ejercicio.***
