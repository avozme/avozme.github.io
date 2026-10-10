---
layout: page
title: 5.3 Persistencia de datos
permalink: /springboot/persistencia/
nav_order: 3
has_children: true
parent: 5 SSR y API REST con Spring Boot
grand_parent: Desarrollo Web en Entorno Servidor
---

## 5.3. Persistencia de datos
{: .no_toc }

- TOC
{:toc}

[Descargar presentación](https://www.dropbox.com/scl/fi/ll8ef65zeuod621l3y1dk/05_03_persistencia.pdf?rlkey=5gazknujh7k07mtf59sxb0f1g&st=xecomrge&dl=0){: .btn .btn-primary }



**Spring Data JPA** es el ORM Spring Boot (como Eloquent lo es de Laravel). Es un derivado de **Hibernate/JPA**, que debiste ver, aunque fuera por encima, en primer curso (si no es así, no te apures: se parece mucho a Eloquent).

Por tanto, Spring Data JPA se encarga de gestionar las relaciones entre tablas y mover los datos entre la base de datos real y los objetos (entities) de nuestra aplicación.

En esta sección vamos a resumir muy deprisa, sin entrar en detalles farragosos, cómo lo hace Spring Boot para **especificar las relaciones entre entidades**. Como todo en Spring Boot, se basa en el uso de las **anotaciones**.

### 5.3.1. Relaciones 1:1

En **relaciones 1:1**, las dos entidades relacionadas tienen en teoría el mismo “peso” en la relación (no hay una entidad dominante). Nosotros, como programadores y según la semántica de la relación, decidiremos **qué entidad es la dominante**.

Por ejemplo, si tenemos una entidad `Alumno` y otra entidad `Email` con una relación 1:1 entre ellas, parece claro que *la entidad `Alumno` es propietaria de esa relación y `Email` es la parte inversa*, puesto que un email no tiene sentido si no pertenece a un alumno pero un alumno sí puede existir sin email.

En tal caso, expandiríamos la clave ajena `email_id` a la tabla `alumnos` como clave ajena y lo implementaríamos así con Spring Boot:

```java
// ******** ENTIDAD ALUMNO ********
@Entity
public class Alumno {
   @OneToOne
   @JoinColumn(name = "email_id")   //  <-- Esta es la clave ajena
   private Email email;
   // Aquí iría el resto de la entidad Alumno
}

// ******** ENTIDAD EMAIL ********
@Entity
public class Email {
   @OneToOne(mappedBy = "email") //  <-- mapped indica que la otra entidad “manda”
   private Alumno alumno;
   // Aquí iría el resto de la entidad Email
}
```

### 5.3.2. Relaciones 1:N

En las **relaciones 1:N** siempre **"manda" la entidad del lado 1** (la que tiene la clave ajena en la base de datos).

Por ejemplo, si tenemos una entidad `Alumno` y otra entidad `Curso` con una relación 1:N entre ellas, siempre es la entidad `Alumno` la propietaria de la relación (su table contendrá un `curso_id` como clave ajena). `Curso` es la parte inversa.

La implementación con Spring Boot de las dos entidades sería así:

```java
// ******** ENTIDAD ALUMNO ********
@Entity
public class Alumno {
    @ManyToOne
    @JoinColumn(name="curso_id")  // <-- Clave ajena
    private Curso curso; 
   // Aquí iría el resto de la entidad Alumno
}

// ******** ENTIDAD CURSO ********
@Entity
public class Curso {
   @OneToMany(mappedBy = "curso")//  <-- mapped indica que la otra entidad “manda”
   private List<Alumno> listaAlum;
   // Aquí iría el resto de la entidad Curso
}
```

### 5.3.3. Relaciones N:N

Las **relaciones N:N**, como ya sabrás, generan una **tabla intermedia** llamada tabla **pivote**. 

A veces, se crea una entidad para esa tabla pivote (sobre todo cuando tiene mucha importancia en la aplicación o tiene muchos atributos adicionales) y sus conexiones con las tablas maestras se manejan como dos relaciones 1:N diferentes, pero lo habitual es que la tabla pivote no genere una entidad, sino que se indique en las entidades maestras.

En este caso, de nuevo, tenemos una **relación “igual por los dos lados”**, es decir, donde no hay de entrada una entidad propietaria y otra inversa. Es la semántica del problema la que nos dirá **qué entidad es dominante** en la relación, y así se lo indicaremos a Spring Boot.

Por ejemplo, si tenemos una entidad `Alumno` con una relación N:N con otra entidad `Asignatura`, parece razonable que sea el `Alumno` la entidad dominante. En tal caso, describiríamos así las entidades:

```java
// ******** ENTIDAD ALUMNO ********
@Entity
public class Alumno {  
    @ManyToMany
    @JoinTable(               
        name = "alumno_asignatura", // <-- Nombre de la tabla pivote
        joinColumns = @JoinColumn(name = "alumno_id"),
        inverseJoinColumns = @JoinColumn(name = "asignatura_id")
    )
    private List<Asignatura> asignaturas;
   // Aquí iría el resto de la entidad Alumno
}

// ******** ENTIDAD ASIGNATURA ********
@Entity
public class Asignatura {  
    @ManyToMany(mappedBy = "asignaturas")
    private List<Alumno> alumnos;
   // Aquí iría el resto de la entidad Asignatura
}
```

Una vez declaradas las entidades, puedes **olvidarte de la tabla pivote**, porque Spring Data JPA se encargará de gestionarla automáticamente.
