---
layout: page
title: 3.6 Eloquent ORM
permalink: /laravel/eloquent.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 6
has_children: false
---

## 3.6. Usando la BD con Eloquent
{: .no_toc }

- TOC
{:toc}

Eloquent uno de los componentes de Laravel que permiten al desarrollador manipular los datos de la BD sin rebajarse a escribir sucio SQL. Y lo consigue mediante un mecanismo simple y elegante: el mapeo objeto-relacional.

En esta sección vamos a ver qué es eso del mapeo y cómo sacarle a Eloquent el máximo partido para que nuestros modelos se programen prácticamente solos.

### 3.6.1. ¿Qué es el mapeo objeto-relacional?

Eloquent no es más que una librería incluida con Laravel que utiliza un patrón de software llamado **ORM (Object-Relational Mapping)** para abstraer aún más el acceso a la base de datos, de manera que no tengamos que escribir y depurar SQL.

*Mapear* los objetos de nuestra aplicación con una BD relacional significa que Eloquent convierte los registros de tus tablas en objetos de tu aplicación para que los manipules con mayor facilidad.

Sí, lo has entendido bien: podrás manejar los datos de tu base de datos como si fueran objetos de tu aplicación. Y, cuando los modifiques, borras o crees, se ejecutará el código SQL necesario (sin que tú te enteres) para traducir esas operaciones en sentencias para la base de datos.

Te lo muestro con un ejemplo.

Imagina que tenemos una tabla de artículos de un blog. La llamaremos *Articles*, y tendrá 3 campos: el *id* (entero), el *title* (cadena de caracteres) y el *body* (cadena de caracteres). Con Eloquent, usar esa tabla es tan fácil como hacer algo así:

```php
$art = Article::find('7');        // Buscamos un artículo por su id
echo $art->title;                 // Ahora podemos acceder a los campos de ese artículo
$art->body = "Texto del cuerpo";  // O también podemos modificar los campos del artículo
$art->save();                     // Si hacemos save(), los cambios se guardan en la BD
```

### 3.6.2. ¿Cómo puedo usar Eloquent en mi aplicación?

Tienes que **crear un modelo**. ¿Qué te creías? Pero con Artisan es así de fácil:

```
$ php artisan make:model <Mi-modelo>
```

Por ejemplo:

```
$ php artisan make:model Article
```

El modelo se creará en */app/models/Article.php* (¡cuidado! En versiones más antiguas de Laravel, el modelo se creará en */app/Article.php*)

Truco: si creas el modelo con la **opción -m**, se creará atomáticamente su migración, lo cual resulta tremendamente práctico:

```
$ php artisan make:model Article -m
```

Ya tienes tu modelo. Si no puedes contener tu curiosidad insaciable y lo abres, verás un archivo bastante decepcionante con este aspecto:

```php
<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Article extends Model
{
    use HasFactory;
}
```

¿Y eso es todo?

Pues sí, eso es todo. La gracia está en ese *"extends Model"* de la definición de la clase: aunque tu modelo Article parezca vacío, en realidad acaba de heredar un mogollón de características útiles de la clase *Model*. Entre otras, todos los métodos de Eloquent.

### 3.6.3. Pero ¿cómo sabe Laravel qué tabla está asociada a ese modelo?

Buena pregunta.

Laravel supondrá que **la tabla se llama igual que el modelo**, solo que en **minúscula y plural**. Es decir, la tabla de la base de datos asociada al modelo *Article* se debería llamar *articles*. 

Recuerda que en Laravel existen un montón de convenciones sobre los nombres de las cosas que conviene respetar, más que nada porque te facilitan mucho la vida y hacen que te centres en lo verdaderamente importante (crear el código de tu aplicación) en lugar de en lo accesorio (pelearte con los nombres).

No obstante, si quieres ponerle otro nombre a la tabla, puedes hacerlo. También puedes cambiar otras muchas cosas, como el nombre del campo clave (Laravel supondrá que se llama id) o los campos sobre los que se puede hacer una asignación masiva, algo muy útil que veremos un poco más adelante.

Por ejemplo, podemos editar el modelo */app/Articles.php* y añadir estas líneas dentro de nuestra clase:

```php
protected $table = 'articulos';   // El nombre de la tabla no será "articles" sino "articulos"
protected $primaryKey = 'id_art'; // La clave primaria no será "id" sino "id_art"
protected $fillable = array('id','titulo','cuerpo'); // Campos de la tabla en los que se permite la ASIGNACIÓN MASIVA (más adelante veremos qué es esto) 
```

### 3.6.4. Consultas con Eloquent

Solo con construir el modelo (y asignarlo a la tabla adecuada) ya tenemos detrás a Eloquent haciendo el mapeo objeto-relacional.

Ahora podemos ir a nuestro controlador (que, por respetar las convenciones de Laravel, debería llamarse *ArticlesController*) y **lanzar consultas** con expresiones como estas:

```php
$articlesList = Article::all();        // Devuelve todos los artículos
$myArticle = Article::find($id);       // Devuelve el artículo con ese $id
$myArticle = Article::findOrFail($id); // Error 404 si el artículo no existe
$articlesList = Article::where('id', '>', 100)->get();  // Select con where
$articlesList = Article::where('id', '>', 100)->take(10)->get();  // Select con where y take
$maxId = Article::max('id');           // Devuelve el último id asignado
```

A lo mejor hay algo que te está chirriando. Si escribimos cosas como estas en el controlador, ¿no significa eso que estamos lanzando consultas desde el controlador? Y eso está prohibidísimo en la arquitectura MVC. ¿Es que Laravel no respeta la arquitectura MVC?

Hay quien dice que sí, hay quien dice que no y hay quien dice que psé, psé.

En realidad, no estamos escribiendo SQL en el controlador, ni estamos accediendo a la base de datos de ninguna manera explícita. Cuando lanzamos un ```Article::find($id)``` desde el controlador, por ejemplo, no sabemos qué ocurre por debajo ni de dónde se extrae la información: nos limitamos a acceder a una de nuestras clases y obtener de ella un objeto de tipo *Article*.

### 3.6.5. Inserciones y borrados con Eloquent

También podemos usar Eloquent para **insertar** un nuevo artículo desde nuestro controlador:

```php
   $art = new Article;
   $art->title = 'Los Chitauri invaden Nueva York';
   $art->body = 'Bla, bla, bla';
   $art->save();
```

Si los datos del artículo vienen de un formulario, fíjate en lo alucinantemente fácil que es recoger todos esos datos, crear un objeto Article con ellos y guardar el artículo en la BD:

```php
   public function store(Request $request) {
      Article::create($request->all());  // Esto es una ASIGNACIÓN MASIVA de las que hablábamos más arriba!!
      return view('la-vista-que-sea');
   }
```

Ojo: solo los campos que hayas indicado como *fillables* en el modelo se podrán asignar al artículo de este modo. Eso es lo que significa **asignación masiva**.

Y, por supuesto, también podemos **modificar y borrar** artículos de la base de datos:

```php
   $art = Article::find(18);     // MODIFICAR
   $art->body = 'Nuevo cuerpo';
   $art->save();
   $art = Article::find(13);     // BORRAR
   $art->delete();
```

### 3.6.6. Lista de los métodos más útiles de Eloquent

Hemos visto en los últimos ejemplos **algunos métodos de Eloquent** por separado. Te los reúno en esta sección para que los puedas consultar cuando lo necesites.

Aviso: no están todos, solo los de uso más habitual. Si quieres una lista completa, ya sabes: acude a la [documentación oficial](https://laravel.com/docs/8.x/eloquent). 

* **all()** → Recupera todos los registros de una tabla.
* **where("campo", valor)** → Aplica claúsula *where*.
* **orderBy("campo", "asc\|desc")** → Aplica claúsula *order by*.
* **get()** → Recupera registros seleccionados. Se suele usar con *where* y/o *order by*:
  ```
  Ciudades::where("ciudad", "Madrid")->orderBy("id", "asc")->get();
  ```
* **first()** → Recupera el primer registro.
* **latest()** → Recupera el último registro.
* **find(valor)** → Busca registros con ese valor en el campo *id*.
* **findOrFail(valor)** → Lanza un error 404 si no encuentra el registro.
* **count(), max(), min()...** → Utiliza funciones de agregado de SQL.
* **save()** →  Inserta o actualiza registros.
* **update()** → Actualiza registros.
* **delete()** → Elimina registros.

### 3.6.7 QueryBuilder
{: .no_toc }

- TOC
{:toc}

En esta sección te voy a presentar a **QueryBuilder**, otra forma de acceder a la base de datos desde Laravel que te resultará muy útil en aquellos casos en los que, por la razón que sea, los métodos de Eloquent no sean suficientes.

#### ¿Qué es y cómo se utiliza QueryBuilder?

Eloquent permite usar la BD de forma simple y elegante en la mayor parte de las circunstancias.

Aún así, puede haber situaciones en las que queramos un acceso de más bajo nivel a la BD. Para eso existe **QueryBuilder**.

El grado de abstracción de QueryBuilder es mucho menor que el de Eloquent. Es decir, estaremos *CASI escribiendo SQL*, sin llegar a hacerlo.

Algunos ejemplos de uso te darán una pista de qué tipo cosas se pueden hacer con QueryBuilder:

```php
$users = DB::table("users")->get();	
$users = DB::table("users")->where("name", "=", "Ana")->first();
$users = DB::table("users")->where("edad", ">=", 18)->orderBy("apellidos");
$maxId = DB::table("users")->max("id");
$existe = DB::table("users")->where("id", "=", $id)->exists();
$users = DB::table("users")->select("nombre, apellidos as apell")->get(); 
```

Ahora ves a qué me refiero cuando digo que QueryBuilder es *casi* SQL, sin llegar a serlo. No tendrás que depurar el SQL, ni pelearte con comillas que se abren y cierran, ni nada de eso. QueryBuilder generará el SQL por ti a partir de expresiones como las que acabas de ver.

En la [documentación oficial](https://laravel.com/docs/8.x/queries) encontrarás una referencia completa de todas las funciones de QueryBuilder, pero con estas que ves en el ejemplo puedes construir prácticamente cualquier consulta sencilla.

#### Colecciones

El **resultado** de consultas como las que veíamos de ejemplo en el apartado anterior es bastante intuitivo: 

* O bien un **dato simple** (como el *$maxId* de la cuarta consulta, que es un entero).
* O bien un **objeto de tipo Collection**. 

Las **colecciones de Laravel** tienen un montón de métodos útiles para procesarlas y puedes echarle un vistazo a la [documentación oficial](https://laravel.com/docs/8.x/collections) para ello, pero la mayor parte de las veces basta con hacer un *foreach* sobre la variable para ir accediendo a cada uno de los elementos, que se comportarán como objetos del tipo adecuado.

Por ejemplo, para acceder a todos los registros de la tabla de usuarios:

   ```php
   $users = DB::table("users")->get();
   foreach ($users as $user) {
      echo $user->name;
      echo $user->email;
      ...etc...
   }
   ```

#### Ventajas de QueryBuilder sobre SQL

Como ves, QueryBuilder te permite construir sentencias SQL sin necesidad de escribir SQL. 

La **ventaja** de esto es triple:

1. No tendremos que depurar nuestros errores sintácticos en SQL, con el ahorro de tiempo que eso conlleva.
2. El SQL generado será 100% compatible con el gestor de base de datos que estemos utilizando. Si escribimos SQL en crudo, tendremos que adaptarlo al dialecto de nuestro gestor de base de datos. Y, si cambiamos de gestor, habrá que revisar todas las sentencias SQL para adaptarlas de nuevo. Todo esto lo evita QueryBuilder, puesto que hace esa adaptación por nosotros.
3. Es imposible que suframos un ataque por inyección de código, puesto que QueryBuilder no lo permitirá.

#### Relaciones entre tablas con QueryBuilder

Las relaciones entre tablas se manejan con **joins**, como en SQL, solo que escritos al estilo QueryBuilder.

Para hacer un **INNER JOIN**, puedes usar como referencia este ejemplo:

```php
$users = DB::table('users')
            ->join('contacts', 'users.id', '=', 'contacts.user_id')
            ->join('orders', 'users.id', '=', 'orders.user_id')
            ->select('users.*', 'contacts.phone', 'orders.price')
            ->get(); 
```

Por supuesto, también puedes hacer **LEFT JOIN** y **RIGHT JOIN**:

```php
$resultado = DB::table('A')->leftJoin('B'...); 
$resultado = DB::table('A')->rightJoin('B'...); 
```

#### SQL crudo

Por último, QueryBuilder también te permite **escribir SQL crudo**, es decir, SQL tal cual, si es que alguna vez lo necesitas.

Eso sí, deberías valorar muy bien para qué narices quieres escribir SQL crudo. ¿Estás seguro/a de que eso que intentas hacer no se puede lograr más fácilmente con Eloquent o con QueryBuilder?

Además, tendrás que extremar las precauciones ante un posible ataque por inyección de código.

Si aún así no te he convencido, puedes ejecutar tu SQL crudo así:

```php
$resultado = DB::raw('escribe-aquí-tu-sentencia-SQL');
```
