---
layout: page
title: 3.5 La base de datos. Migraciones, seeders y modelos
permalink: /laravel/migraciones-seeders-modelos.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 5
has_children: false
---

## 3.5. Migraciones
{: .no_toc }

- TOC
{:toc}

Las **migraciones** constituyen una especie de control de versiones para la base de datos de la aplicación. Permiten crear y modificar tablas de la BD con independencia del SGBD que estemos usando.

Con las migraciones no solo podrás reconstruir la base de datos en menos de lo que tarda en decirse "Von Neumann" (algo muy práctico cuando estás en fase de desarrollo), sino que podrás parchear la base de datos de una aplicación en producción en un tiempo record y con riesgo cero. 

(Solo el que ha tenido que parchear la base de datos de una aplicación en producción antes de la existencia de las migraciones sabe la tranquilidad de espíritu que esto produce y la cantidad de problemas embarazosos que te quita de encima).

Antes de empezar, ten en cuenta que las versiones recientes de Laravel **utilizan SQLite por defecto**. Para **usar MySQL o MariaDB**, debes configurar correctamente las variables de entorno en el archivo `.env`:

```env
DB_CONNECTION=mysql
DB_HOST=127.0.0.1
DB_PORT=3306
DB_DATABASE=mi_base_de_datos
DB_USERNAME=mi_usuario_de_BD
DB_PASSWORD=mi_password_de_BD
```

### 3.5.1. Crear tablas mediante las migraciones

La primera cosa para las que sirven las migraciones es para **crear las tablas de tu aplicación**. Olvídate de exportar e importar a mano el archivo SQL de tu base de datos. Eso lo hacían los cromañones.

Vamos a trabajar con un ejemplo, como siempre. Imagina que tenemos una tabla llamada *Clients* con los campos típicos: *id*, *name*, *address*, etc.

De acuerdo. Creemos, paso a paso, las migraciones de esta tabla:

**Paso 1**: Crear la migración para la tabla Clients:

```bash
$ php artisan make:migration create_clients_table
```

Esto generará un fichero en la carpeta `database/migrations` cuyo nombre contendrá un *timestamp* o marca de tiempo. Vamos, que contendrá un numerajo con la fecha y hora actual. Algo tan bonito como `database/migrations/20241226072434_create_clients_table.php` (las versiones modernas de Laravel separan el nombre con guiones bajos).

Si editas ese fichero, verás que devuelve una clase anónima que contiene dos métodos:

* **up()** → se ejecuta cuando se lanza la migración. Se encarga de crear la tabla en la base de datos.
* **down()** → se ejecuta cuando se deshace la migración. Se encarga de eliminar la tabla de la base de datos.

**Paso 2**: Editar el fichero de la migración recién creado:

En el método *up()* tienes que indicar las columnas que tendrá la tabla. Por ejemplo:

```php
return new class extends Migration {
    public function up(): void {
        Schema::create('clients', function (Blueprint $table) {
           $table->id(); // Equivalente a bigIncrements('id')
           $table->string('name', 75)->unique(); // VARCHAR
           $table->text('address')->nullable();  // TEXT
           $table->integer('level');             // INT
           $table->date('birth_date');           // DATE
           // La siguiente línea crea campos created_at y updated_at. Si la borras
           // esos campos no existirán en tu tabla.
           $table->timestamps();
        });
    }

    public function down(): void {
        Schema::dropIfExists('clients');
    }
};
```

**Paso 3**: Lanzar las migraciones.

```bash
$ php artisan migrate
```

Esto creará las tablas que no se hayan creado aún. Es decir, si una migración ya se ha lanzado con anterioridad, no se vuelve a ejecutar para no perder los datos que pudieran existir en esas tablas.

**Paso 4**: Revertir las migraciones (si es necesario)

Si necesitas revertir la creación de todas las tablas:

```bash
$ php artisan migrate:rollback
```

Para revertir solo el último paso en la creación de tablas:

```
$ php artisan migrate:rollback --step=1
```

Para dejar la BD a su estado original (vacía):

```
$ php artisan migrate:reset
```

¡Cuidado! Estas acciones son destructivas. Pero, por supuesto, hay una forma de modificar una tabla sin borrarla y volver a crearla. Es lo que vamos a hacer a continuación.

### 3.5.2. Modificar tablas mediante migraciones

Si necesitas **modificar una tabla que ya existe** (por ejemplo, para añadir o eliminar campos), tienes dos opciones:

1. Modificar la migración original (en la que se crea la tabla) para añadir o eliminar el campo afectado. Esto te obligará a lanzar la migración de nuevo y, por lo tanto, la tabla se reconstruirá y todos los datos que pudiera contener se perderán.
2. Crear una nueva migración en la que únicamente se haga la modificación de la tabla, sin tocar el resto. Esto respetará los datos que la tabla ya pudiera contener.

Como es lógico, la opción 2 será la que preferiremos si la aplicación ya está en producción y necesitamos modificar la estructura de la base de datos. En cambio, durante el desarrollo, puede ser más simple utilizar la opción 1.

Supongamos que queremos añadir un campo *email* a la tabla *Clients* del apartado anterior. Si optas por la opción 2, es decir, por crear una nueva migración que se encargue de hacer esa modificación en la tabla sin alterar sus datos, la forma de proceder es la siguiente:

**Paso 1**. Crear la migración:

```bash
$ php artisan make:migration add_email_to_clients --table=clients
```

(Nota: puedes asignar el nombre que quieras a las migraciones, pero Laravel aconseja utilizar las convenciones que ves en estos ejemplos para simplificarnos la vida)

**Paso 2**: Editar la nueva migración en `database/migrations/` para añadir, en el método *up()*, el campo nuevo; y, en el método *down()*, especificaremos qué hay que hacer en caso de que se fuerce un rollback de esta migración:

```php
return new class extends Migration {
    public function up(): void {
        Schema::table('clients', function (Blueprint $table) {
            $table->string('email')->after('address');
        });
    }

    public function down(): void {
        Schema::table('clients', function (Blueprint $table) {
            $table->dropColumn('email');
        });
    }
};
```

### 3.5.3. Otras operaciones en las migraciones

Las migraciones pueden usarse para cualquier otra operación sobre la estructura de la base de datos, como:

* Cambiar tipos de columnas.
* Cambiar atributos de columnas (null, unique, default...)
* Cambiar o asignar claves primarias y ajenas.

Las migraciones construidas de este modo nos permitirán reproducir la base de datos en cualquier servidor o actualizarla en cualquier momento sobre una aplicación en producción sin necesidad de programar parches o exportar la BD a un archivo SQL para importarlo en otro servidor.

Como te dije al principio, solo el que ha hecho alguna vez alguna de estas cosas a mano sabe la cantidad de trabajo que las migraciones ahorran en el mantenimiento de una aplicación y la asombrosa cantidad de errores embarazosos que evita.

Más info en la documentación oficial: [https://laravel.com/docs/migrations](https://laravel.com/docs/migrations)

### 3.5.4. Seeding

El ***seeding*** es una técnica adicional a la de las migraciones que permite **cargar con datos las tablas** de la base de datos.

Es muy práctico en estos supuestos:

* Si quieres tener un conjunto de **datos de prueba** en tu base de datos de desarrollo, esa que destrozas periódicamente cuando haces pruebas. Con un solo comando, tendrás la base de datos reconstruida después de cada destrozo.
* Si necesitas cargar algunos datos mínimos en algunas tablas para que la aplicación, una vez desplegada en un servidor de producción, funcione (por ejemplo, para crear un usuario administrador en la tabla *users* o para crear algunas entradas en una tabla *options*).

Para crear un *seeder* (por ejemplo, para la tabla *users*), sigue estos pasos:

**Paso 1**. Ejecuta el comando (se aconseja la convención en singular `UserSeeder`):

```bash
$ php artisan make:seeder UserSeeder
```

**Paso 2**. Edita el archivo `database/seeders/UserSeeder.php` y añade el código de inserción al método *run()* (por supuesto, modifica el código para adaptarlo a tu tabla y a tus datos):

```php
namespace Database\Seeders;

use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;

class UserSeeder extends Seeder {
    public function run(): void {
        DB::table('users')->truncate();  // Optativo: vacía la tabla antes de rellenarla
        DB::table('users')->insert([
            'name' => 'Stephen Falken',
            'address' => 'Oregon 97, Goose Island',
            'email' => 'sfalken@norad.com',
            'birth_date' => '1932-09-03',
        ]);
        DB::table('users')->insert([
            'name' => 'Jennifer Mack',
            'address' => 'Richmond Av 3385, Seattle',
            'email' => 'jenmack876@gmail.com',
            'birth_date' => '1967-01-28',
        ]);        
    }
}
```

**Paso 3**. Ejecuta este comando para lanzar el seeder y que los datos se carguen en tu tabla:

```bash
$ php artisan db:seed --class=UserSeeder
```

Esto cargará solo dos registros en la tabla *users*. Si quieres más, solo tienes que crear nuevas líneas *insert()* en el método *up()*.

### 3.5.5. Automatizar el seeding

Lanzar los seeders de uno en uno puede ser muy tedioso. Puedes lanzar varios seeders con un solo comando si haces lo siguiente:

**Paso 1**. Edita el fichero `database/seeders/DatabaseSeeder.php`

**Paso 2**. Añade a la función *run()* una llamada usando el método *call()* por cada seeder que quieras ejecutar automáticamente:

```php
    $this->call([
        UserSeeder::class,
        // Añade otros seeders aquí separados por comas
    ]); 
```

**Paso 3**. ¡Y listo! Al ejecutar el comando `db:seed` de Artisan, sin indicar la clase, se lanzarán todos los seeders que hayas añadido a *run()*.

```
$ php artisan db:seed
```


### 3.5.6. Chuleta de comandos para manejar migraciones

Por último, te muestro un resumen con los comandos más útiles sobre migraciones y seeders para que puedas consultarlos cuando lo necesites:

* Lanzar todas las migraciones pendientes:

   ```
   $ php artisan migrate
   ```

* Crear la migración para crear una tabla:

   ```
   $ php artisan make:migration <nombre> --create=<tabla>
   ```

* Crear una migración para modificar una tabla ya existente: 

   ```
   $ php artisan make:migration <nombre> --table=<tabla>
   ```

* Retroceder un paso en todas las migraciones:

   ```
   $ php artisan migrate:rollback
   ```

* Retroceder N pasos en todas las migraciones:

   ```
   $ php artisan migrate:rollback --step=<N>
   ```

* Deshacer todas las migraciones que se hayan ejecutado hasta ahora (resetear la base de datos):

   ```
   $ php artisan migrate:reset
   ```

* Resetear la base de datos y volver a reconstruirla lanzando todas las migraciones:

   ```
   $ php artisan migrate:refresh
   ```

* Resetear la base de datos, reconstruirla y llenarla de datos con los seeders:

   ```
   $ php artisan migrate:refresh --seed
   ```

* Eliminar todas las tablas y lanzar todas las migraciones de nuevo:

   ```
   $ php artisan migrate:fresh
   ```

* Eliminar todas las tablas y lanzar todas las migraciones y todos los seeders de nuevo:

   ```
   $ php artisan migrate:fresh --seed
   ```   

### 3.5.7. Práctica con migraciones

En las prácticas anteriores dejamos preparadas las rutas, el controlador y las vistas de nuestro recurso `products`. Ahora ha llegado el momento de **crear la tabla en la base de datos** para poder guardar nuestros productos reales, sustituyendo a los productos de prueba que habíamos escrito "a mano" en el controlador.

#### Objetivos

Al terminar la práctica habrás aprendido a:

- Crear una migración desde la línea de comandos usando Sail.
- Definir la estructura de una nueva tabla con tipos de datos y restricciones comunes (`string`, `text`, `decimal`).
- Ejecutar migraciones para que los cambios se reflejen en la base de datos.
- Conectarte al servicio MySQL de Sail para comprobar que la tabla y sus columnas se han creado correctamente.

#### PASO 1. Crear el archivo de la migración

1. Ve al terminal de tu proyecto y asegúrate de que el contenedor Sail está funcionando (si no lo está, recuerda levantarlo con `sail up -d`).
2. Ejecuta el siguiente comando para generar la migración que creará la tabla `products`:

   ```bash
   $ ./vendor/bin/sail artisan make:migration create_products_table
   ```

3. Laravel habrá generado un nuevo archivo en `database/migrations/` con un nombre que empieza por la fecha y hora actuales (algo así como `YYYY_MM_DD_HHMMSS_create_products_table.php`). Ábrelo en tu editor.

#### PASO 2. Definir los campos de la tabla

El archivo generado contendrá los métodos `up()` y `down()`. Por defecto, Laravel ya ha incluido la columna `id` (clave primaria) y el método `timestamps()` (que crea los campos `created_at` y `updated_at`).

1. Modifica el interior del método `up()` para incluir las tres columnas necesarias para un producto: `name`, `description` y `price`. El código debe quedar parecido a este:

   ```php
   return new class extends Migration {
       public function up(): void {
           Schema::create('products', function (Blueprint $table) {
               $table->id();
               
               // Añadimos nuestras columnas para el producto:
               $table->string('name', 100);
               $table->text('description')->nullable();
               $table->decimal('price', 8, 2);
               
               $table->timestamps();
           });
       }

       public function down(): void {
           Schema::dropIfExists('products');
       }
   };
   ```

   Fíjate en los tipos elegidos: un `string` limitado a 100 caracteres para el nombre, un tipo `text` que permite valores nulos (`nullable()`) para la descripción y un campo `decimal` (8 dígitos en total, 2 de ellos decimales) para el precio.

<div markdown="1" style="color: red; font-style: italic">
**Asegúrate de ENTENDERLO TODO.** Repasa qué hace cada uno de los tipos de columna en la documentación oficial si tienes dudas sobre `string`, `text` o `decimal`.
</div>

#### PASO 3. Lanzar la migración

Para que estos cambios tomen efecto real, debemos enviar la migración a la base de datos.

1. En tu terminal, lanza las migraciones pendientes con:

   ```bash
   $ ./vendor/bin/sail artisan migrate
   ```

   Verás un mensaje indicando que la tabla `products` se ha migrado (creado) con éxito.

#### PASO 4. Comprobar la creación en la base de datos

Como estamos utilizando Laravel Sail, conectarnos directamente a nuestro servidor de base de datos MySQL es muy sencillo.

1. Ejecuta este comando en la terminal para abrir una sesión interactiva en MySQL:

   ```bash
   $ ./vendor/bin/sail mysql
   ```

2. Una vez dentro de MySQL (verás el prompt `mysql>`), puedes pedir que te muestre todas las tablas disponibles en tu base de datos:

   ```sql
   SHOW TABLES;
   ```

   Comprueba que aparece una tabla llamada `products` y otra llamada `migrations` (esta última es la que usa Laravel para llevar el control interno de qué migraciones se han ejecutado).

3. Para comprobar la estructura concreta de nuestra tabla de productos, escribe:

   ```sql
   DESCRIBE products;
   ```

   Ahí podrás ver el `id`, el `name`, el `description`, el `price` y los campos de timestamp, con sus respectivos tipos de dato en formato MySQL (por ejemplo, `varchar(100)` para el nombre).

4. Cuando termines de revisar la tabla, sal de la consola de MySQL tecleando `exit`.


