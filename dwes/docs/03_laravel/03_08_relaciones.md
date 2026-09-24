---
layout: page
title: 3.8 Relaciones entre modelos
permalink: /laravel/relaciones.html
parent: 3 Aplicaciones SSR con Laravel
grand_parent: Desarrollo Web en Entorno Servidor
nav_order: 8
has_children: false
---

Contenidos
Relaciones Eloquent.
belongsTo.
hasMany.
belongsToMany.
Migraciones con claves foráneas.
Tabla intermedia.
Consultar relaciones.

Práctica

Ampliar nuestro CRUD.




### 3.6.7. Relaciones entre tablas con Eloquent

Las **relaciones entre tablas** también se pueden manejar con Eloquent sin necesidad de andar escribiendo larguísimos INNER JOIN y otros miembros de su nutrida familia, con todos los errores de escritura que suelen hacernos perder el tiempo depurando SQL.

Aunque al principio te parezca que definir las relaciones entre tablas con Eloquent necesita mucho trabajo previo, te garantizo que después te alegrarás de haberlo hecho. Porque las relaciones, una vez definidas, se comportan como consultas y se puede operar con ellas como si lo fueran.

Lo comprenderemos mejor, como siempre, con ejemplos. En los siguientes apartados, vamos a suponer que tenemos estas tablas:

* usuarios(id#, nombre, passwd)
* emails(id#, email, usuario_id) → Esta tabla tiene una relación 1:1 con usuarios
* articulos(id#, titulo, texto, idUsuario) → Esta tabla tiene una relación 1:N con usuarios
* roles(id#, nombre) → Esta tabla tiene una relación N:N con usuarios

ATENCIÓN: en la tabla *artículos* hemos usado a propósito un nombre no estándar para la clave foránea. Para respetar la convención de Laravel, debería llamarse *usuario_id* en lugar de *idUsuario*, como en la tabla *emails*.

#### 3.6.7.1. Relaciones 1:1 (usuarios <-> emails)

Para definir un **relación 1:1** con Eloquent debes hacer lo siguiente:

**Paso 1**. En el modelo de la tabla maestra (clase *Usuario*, en nuestro ejemplo) añadimos este método:

```php
public function email() {
    return $this->hasOne('App\Email'); 
}
```

**Paso 2**. En el modelo de la tabla relacionada (clase *Email*) añadimos este método:

```php
    public function usuario() {
        return $this->belongsTo('App\Usuario'); 
    }
```

A partir de ahora, se puede recuperar el email de un usuario como si fuera un miembro de la clase *Usuario*, tan sencilla como esto:

```php
    $email = Usuario::find(1)->email;
    $user = Email::all()->first()->user;
```

Y también funciona al revés. Es decir, a partir de un objeto de tipo *Email*, podemos acceder a su usuario como si fuera un atributo de la clase *Email*.

#### 3.6.7.2. Relaciones 1:N (usuarios <-> artículos)

Si tienes una **relación 1:N** (como la que hay entre las tablas de *usuarios* y *artículos* de nuestro ejemplo), para definirla en Eloquent tienes que hacer esto:

**Paso 1**. En el modelo de la tabla maestra (clase *Usuario*), añade este método:

```php
public function articulos() {
    return $this->hasMany('App\Articulo', 'idUsuario'); 
}
// ATENCIÓN: hemos tenido que indicar el nombre de la clave foránea
// (idUsuario) porque no habíamos respetado la convención de Laravel
// (usuario_id) al crear la tabla de artículos
```

**Paso 2**. En el modelo de la tabla relacionada (class Articulo), añade este otro método:

```php
    public function usuario() {
        return $this->belongsTo('App\Usuario'); 
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

#### 3.7.11.3. Relaciones N:N (usuarios <-> roles)

Si lo que tienes es una **relación N:N** (como la que hay entre *usuarios* y *roles* en nuestro ejemplo), los pasos a seguir para construirla con Eloquent son estos:

**Paso 1**. En el modelo de una de las tablas (clase *Usuario*) añadimos este método:

```php
public function roles() {
    return $this->belongsToMany('App\Rol'); 
}
```

**Paso 2**. En el modelo de la otra tabla (clase *Rol*) añadimos este método:


```php
    public function usuarios() {
        return $this->belongsToMany('App\Usuario'); 
    }
```

Ahora, ya se pueden recuperar los roles a partir del usuario o a la inversa. Por ejemplo:

```php
    $roles = Usuario::find(1)->roles;
    foreach ($roles as $rol) {
       // Procesar cada rol
    }
```
#### 3.7.11.4. La tabla pivote: insertar, modificar y borrar en relaciones N:N

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

#### 3.7.11.5. Problemas frecuentes en relaciones N:N

Eloquent supondrá que **el nombre de la tabla de la relación** se ha formado con los nombres de las dos tablas maestras en snake case y ordenadas alfabéticamente.

Por ejemplo, en la relación N:N entre *usuarios* y *roles*, Eloquent supondrá que existe una tabla llamada *roles_usuarios*. Si no se llama así, la relación fallará.

Se puede indicar otro nombre de tabla al definir la relación. Por ejemplo, en el modelo de usuarios (clase *Usuario*):

```php
public function roles() {
    return $this->belongsToMany('App\Rol', 'usuarios_roles'); 
}
```

También se pueden indicar los nombres de las claves foráneas si no siguen las convenciones (que, según Laravel, son *usuario_id*, *rol_id*, etc)

```php
    public function roles() {
        return $this->belongsToMany('App\Rol', 'usuarios_roles',
                                    'id_usuario', 'id_rol'); 
    }
```

¿Te has fijado en que hemos creado un método para acceder a la tabla relacionada, pero estamos usando un atributo en su lugar?

```php
public function articulos() {
    return $this->hasMany('App\Articulo'); 
}
public function loQueSea() {
    $arts = Usuario::find(1)->articulos;  // articulos, no articulos()
}
```

Pues bien, el atributo *articulo* es un **atributo virtual** creado por Eloquent. Pero el método *articulos()* también existe, y puede usarse como una consulta, extendiéndola como necesitemos. Por ejemplo:

```php
$arts = Usuario::find(1)->articulos()->where('titulo','foo')->first(); 
```
