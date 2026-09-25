---
layout: page
title: 3.7 Relaciones entre modelos
permalink: /laravel/relaciones.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 7
has_children: false
---


## 3.7. Relaciones entre tablas con Eloquent

Las **relaciones entre tablas** también se pueden manejar con Eloquent sin necesidad de andar escribiendo larguísimos `INNER JOIN` y otros miembros de su nutrida familia, con todos los errores de escritura que suelen hacernos perder el tiempo depurando SQL.

Aunque al principio te parezca que definir las relaciones entre tablas con Eloquent necesita mucho trabajo previo, te garantizo que después te alegrarás de haberlo hecho. Porque las relaciones, una vez definidas, se comportan como consultas y se puede operar con ellas como si lo fueran.

Lo comprenderemos mejor, como siempre, con ejemplos. **En los ejemplos de los siguientes apartados vamos a suponer que tenemos estas tablas ya creadas y con datos**:

* `usuarios(id#, nombre, passwd)`
* `emails(id#, email, usuario_id)` → Esta tabla tiene una relación 1:1 con usuarios
* `articulos(id#, titulo, texto, idUsuario)` → Esta tabla tiene una relación 1:N con usuarios
* `roles(id#, nombre)` → Esta tabla tiene una relación N:N con usuarios

ATENCIÓN: en la tabla *`artículos`* hemos usado a propósito un nombre no estándar para la clave foránea. Para respetar la convención de Laravel, debería llamarse *`usuario_id`* en lugar de *`idUsuario`*, como en la tabla *`emails`*.

### 3.7.1. Migraciones con claves foráneas

Antes de definir las relaciones en los modelos, debemos asegurarnos de que la base de datos refleje estas asociaciones mediante **claves foráneas**.

A partir de las versiones recientes de Laravel, crear una clave foránea que respete las convenciones en una migración es tan sencillo como usar el método `foreignId` encadenado con `constrained`:

```php
Schema::create('articulos', function (Blueprint $table) {
    $table->id();
    $table->string('titulo');
    $table->text('texto');
    
    // Crea la columna 'usuario_id' (BIGINT UNSIGNED) y añade la restricción de clave foránea
    // referenciando al campo 'id' de la tabla 'usuarios'.
    // Además, activamos el ON DELETE CASCADE. ¡¡Ojo con eso, no usar indiscriminadamente!!
    $table->foreignId('usuario_id')->constrained('usuarios')->onDelete('cascade');
    
    $table->timestamps();
});
```

Si no respetas la convención de nombres, tendrás que indicarlo manualmente:
```php
$table->unsignedBigInteger('idUsuario');
$table->foreign('idUsuario')->references('id')->on('usuarios');
```

### 3.7.2. Relaciones 1:1 (usuarios <-> emails)

Para definir un **relación 1:1** con Eloquent debes hacer lo siguiente:

**Paso 1**. En el modelo de la tabla maestra (clase `Usuario`, en nuestro ejemplo) añadimos este método:

```php
use App\Models\Email;

public function email() {
    return $this->hasOne(Email::class); 
}
```

**Paso 2**. En el modelo de la tabla relacionada (clase `Email`) añadimos este método:

```php
use App\Models\Usuario;

public function usuario() {
    return $this->belongsTo(Usuario::class); 
}
```

A partir de ahora, se puede recuperar el email de un usuario como si fuera un miembro de la clase *Usuario*, tan sencilla como esto:

```php
    $email = Usuario::find(1)->email;
    $user = Email::all()->first()->user;
```

Y también funciona al revés. Es decir, a partir de un objeto de tipo *Email*, podemos acceder a su usuario como si fuera un atributo de la clase *Email*.

### 3.7.3. Relaciones 1:N (usuarios <-> artículos)

Si tienes una **relación 1:N** (como la que hay entre las tablas de *usuarios* y *artículos* de nuestro ejemplo), para definirla en Eloquent tienes que hacer esto:

**Paso 1**. En el modelo de la tabla maestra (clase `Usuario`), añade este método:

```php
use App\Models\Articulo;

public function articulos() {
    // ATENCIÓN: indicamos el nombre de la clave foránea (idUsuario)
    // porque no hemos respetado la convención (usuario_id).
    // Si lo hubiéramos respetado, no haría falta.
    return $this->hasMany(Articulo::class, 'idUsuario'); 
}
```

**Paso 2**. En el modelo de la tabla relacionada (clase `Articulo`), añade este otro método:

```php
use App\Models\Usuario;

public function usuario() {
    return $this->belongsTo(Usuario::class, 'idUsuario'); 
}
```

¡Y listo! Ya puedes recuperar los artículos a partir del usuario, como si fueran atributos de esa clase. Y a la inversa también funciona.

Por ejemplo:

```php
    $articulos = Usuario::find(1)->articulos;
    foreach ($articulos as $articulo) {
       // Procesar cada artículo
    }
```

### 3.7.4. Relaciones N:N (usuarios <-> roles)

Si lo que tienes es una **relación N:N** (como la que hay entre *usuarios* y *roles* en nuestro ejemplo), los pasos a seguir para construirla con Eloquent son estos:

**Paso 1**. En el modelo de una de las tablas (clase `Usuario`) añadimos este método:

```php
use App\Models\Rol;

public function roles() {
    return $this->belongsToMany(Rol::class); 
}
```

**Paso 2**. En el modelo de la otra tabla (clase `Rol`) añadimos este método:


```php
use App\Models\Usuario;

public function usuarios() {
    return $this->belongsToMany(Usuario::class); 
}
```

Ahora, ya se pueden recuperar los roles a partir del usuario o a la inversa. Por ejemplo:

```php
    $roles = Usuario::find(1)->roles;
    foreach ($roles as $rol) {
       // Procesar cada rol
    }
```
### 3.7.5. La tabla pivote: insertar, modificar y borrar en relaciones N:N

Insertar, modificar y borrar en relaciones N:N implica escribir datos (normalmente, ids) en la **tabla intermedia** o **tabla pivote**, lo cual suele suponer un engorro cuando se hace *a mano* con SQL.

Ese tedioso proceso también se puede automatizar con Eloquent. Lo vemos con un ejemplo entre nuestras tablas *usuarios* y *roles*.

**Para insertar** un usuario y sus roles se usa el método *attach()*:

```php
public function store(Request $r) {
    $user = new User($r->all());
    $user->roles()->attach($r->roles);
    $user->save();
}
```

**Para actualizar** un usuario y sus roles se usa el método *sync()*:

```php
    public function update(Request $r, $id) {
        $user = User::find($id);
        $user->fill($r->all()); 
        $user->roles()->sync($r->roles); 
        $user->save();  
    }
```

**Para eliminar** un usuario y sus roles se usa el método *detach()*:

```php
    public function destroy($id) {
        $user = User::find($id);
        $user->roles()->detach(); 
        $user->delete(); 
    }
```

### 3.7.6. Problemas frecuentes en relaciones N:N

Eloquent supondrá que **el nombre de la tabla intermedia (pivote)** se ha formado con los nombres de los dos modelos en singular, en snake case y ordenados alfabéticamente.

Por ejemplo, en la relación N:N entre los modelos `Usuario` y `Rol`, Eloquent supondrá que existe una tabla llamada `rol_usuario`. Si no se llama así, la relación fallará.

Se puede indicar otro nombre de tabla al definir la relación. Por ejemplo, en el modelo de usuarios (clase `Usuario`):

```php
public function roles() {
    return $this->belongsToMany(Rol::class, 'usuarios_roles'); 
}
```

También se pueden indicar los nombres de las claves foráneas si no siguen las convenciones:

```php
    public function roles() {
        return $this->belongsToMany(Rol::class, 'usuarios_roles',
                                    'id_usuario', 'id_rol'); 
    }
```

¿Te has fijado en que hemos creado un método para acceder a la tabla relacionada, pero estamos usando un atributo en su lugar?

```php
public function articulos() {
    return $this->hasMany(Articulo::class); 
}
public function loQueSea() {
    $arts = Usuario::find(1)->articulos;  // articulos, no articulos()
}
```

Pues bien, el atributo *articulo* es un **atributo virtual** creado por Eloquent. Pero el método *articulos()* también existe, y puede usarse como una consulta, extendiéndola como necesitemos. Por ejemplo:

```php
$arts = Usuario::find(1)->articulos()->where('titulo','foo')->first(); 
```

### 3.7.7. Práctica de relaciones con Eloquent

Vamos a añadir, a nuestra aplicación `hola-laravel` donde tenemos ya un CRUD de productos funcionando, la capacidad de **asignar nuestros productos a categorías**. 

Un producto pertenecerá a una única categoría (por ejemplo: Electrónica, Hogar, Ropa), pero una categoría podrá tener muchos productos. Es decir, tendremos es una **relación 1:N**.

#### Objetivos
- Crear un nuevo modelo `Category` con su migración.
- Añadir la clave foránea a la tabla de productos creando una nueva migración.
- Establecer las relaciones Eloquent `hasMany` y `belongsTo`.
- Guardar y mostrar los productos con su respectiva categoría.

#### PASO 1. Crear el modelo Category y su tabla

1. En tu terminal (recuerda tener Sail levantado), ejecuta:
   ```bash
   ./vendor/bin/sail artisan make:model Category -m
   ```

2. Abre la migración creada en `database/migrations/` (la de `create_categories_table`) y añade un campo `name`:
   ```php
   public function up(): void {
       Schema::create('categories', function (Blueprint $table) {
           $table->id();
           $table->string('name', 50);
           $table->timestamps();
       });
   }
   ```

3. Modifica el modelo `app/Models/Category.php` para permitir asignación masiva y definir que una categoría tiene muchos productos:
   ```php
   namespace App\Models;

   use Illuminate\Database\Eloquent\Model;

   class Category extends Model
   {
       protected $fillable = ['name'];

       public function products()
       {
           return $this->hasMany(Product::class);
       }
   }
   ```

#### PASO 2. Añadir la relación al modelo Product

1. Abre `app/Models/Product.php` y añade la relación inversa y el campo a `$fillable`:
   ```php
   // Asegúrate de importar el modelo si no están en el mismo namespace
   // use App\Models\Category;

   // Añade 'category_id' al fillable existente:
   protected $fillable = ['name', 'description', 'price', 'category_id'];

   // Añade la relación:
   public function category()
   {
       return $this->belongsTo(Category::class);
   }
   ```

#### PASO 3. Actualizar la base de datos de productos

Nuestra tabla `products` actual no tiene la columna `category_id`. Vamos a crear una migración que solo modifique esa tabla para añadirle el campo.

1. Ejecuta:
   ```bash
   ./vendor/bin/sail artisan make:migration add_category_id_to_products_table --table=products
   ```

2. En la nueva migración generada, añade el campo como clave foránea:
   ```php
   public function up(): void {
       Schema::table('products', function (Blueprint $table) {
           // nullable() porque los productos que ya tenemos no tienen categoría asignada
           $table->foreignId('category_id')->nullable()->constrained()->onDelete('set null');
       });
   }

   public function down(): void {
       Schema::table('products', function (Blueprint $table) {
           $table->dropForeign(['category_id']);
           $table->dropColumn('category_id');
       });
   }
   ```

3. Lanza las migraciones:
   ```bash
   ./vendor/bin/sail artisan migrate
   ```

#### PASO 4. Llenar categorías de prueba y verlas en la web

1. Utiliza Tinker (la consola interactiva de Laravel) para crear algunas categorías de prueba rápidamente:
   ```bash
   ./vendor/bin/sail artisan tinker
   ```
   Dentro de la consola (shell interactiva), escribe y pulsa Enter tras cada línea:
   ```php
   App\Models\Category::create(['name' => 'Electrónica']);
   App\Models\Category::create(['name' => 'Hogar']);
   App\Models\Category::create(['name' => 'Oficina']);
   exit
   ```

2. Modifica el formulario de creación en `resources/views/productos/create.blade.php` para añadir un `<select>` que permita elegir la categoría. Para ello, primero debes enviar las categorías desde el controlador:
   En `ProductController@create`:
   ```php
   use App\Models\Category;
   
   public function create() {
       $categories = Category::all();
       return view('productos.create', compact('categories'));
   }
   ```
   En tu vista, añade este campo dentro del formulario:
   ```html
   <p>
       <label for="category_id">Categoría:</label>
       <select name="category_id" id="category_id">
           <option value="">-- Ninguna --</option>
           @foreach($categories as $category)
               <option value="{% raw %}{{ $category->id }}{% endraw %}">{% raw %}{{ $category->name }}{% endraw %}</option>
           @endforeach
       </select>
   </p>
   ```

3. Modifica la vista de visualización individual (`resources/views/productos/show.blade.php`) para mostrar el nombre de la categoría a través de la relación de Eloquent:
   ```html
   <p>
       <strong>Categoría:</strong>
       {% raw %}{{ $producto->category ? $producto->category->name : 'Sin categoría' }}{% endraw %}
   </p>
   ```
   *(Nota: comprobamos primero si tiene categoría porque puede ser nula)*.

¡Prueba la app! Si todo funciona, has entrelazado tus dos primeras tablas de base de datos utilizando el poder y simplicidad del ORM Eloquent.

<div markdown="1" style="color: red; font-style: italic">
**Siempre lo decimos y en esta práctica no será una excepción: ASEGÚRATE DE ENTENDERLO, NO SOLO DE QUE FUNCIONE.** 

Recuerda que cuando hagas prácticas de entrega obligatoria y exámenes, te podremos preguntar, por escrito u oralmente, qué hace tu código para comprobar que realmente lo entiendes, independientemente de si el código lo has escrito todo tú o lo has generado con ayuda de una IA.
</div>