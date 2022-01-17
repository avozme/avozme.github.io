
#### Ejercicio 1: compañía de seguros

**a) Crear las tablas con las restricciones detalladas en el enunciado del ejercicio:**

```sql
CREATE TABLE Personas (
	dni		VARCHAR(12)	UNIQUE NOT NULL,
	nombre	VARCHAR(50)	NOT NULL,
	apellidos	VARCHAR(50)	NOT NULL,
	ciudad	VARCHAR(50)	DEFAULT "Almería",
	país		VARCHAR(50)	DEFAULT "España",
	CONSTRAINT pk_personas
		PRIMARY KEY (dni)
);

CREATE TABLE Seguros (
	num_póliza	BIGINT	UNIQUE NOT NULL,
	compañía	VARCHAR(50)	NOT NULL,
	tipo		VARCHAR(20),
	franquicia	DECIMAL(8,2)	DEFAULT 0,
	dni_tomador	VARCHAR(12)	NOT NULL,
	fecha		DATE,
	CONSTRAINT pk_seguros
		PRIMARY KEY (num_póliza),
	CONSTRAINT fk_seguros_personas
		FOREIGN KEY (dni_tomador) REFERENCES Personas(dni)
		ON DELETE CASCADE
		ON UPDATE CASCADE
);

CREATE TABLE Coches (
	matrícula	VARCHAR(7)	UNIQUE NOT NULL,
	marca	VARCHAR(30)	NOT NULL,
	modelo	VARCHAR(30),
	potencia	DECIMAL(5,2),
	conductor	VARCHAR(12)	NOT NULL,
	seguro	BIGINT	NOT NULL,
	CONSTRAINT pk_coches
		PRIMARY KEY (matricula),
	CONSTRAINT fk_coches_personas
		FOREIGN KEY (conductor) REFERENCES Personas(dni)
		ON DELETE CASCADE
		ON UPDATE CASCADE,
	CONSTRAINT fk_coches_seguros
		FOREIGN KEY (seguro) REFERENCES Seguros(num_póliza)
		ON DELETE CASCADE
		ON UPDATE CASCADE
);
```

**b) Realizar los siguientes cambios en las tablas**

**Agregar a la tabla Personas el campo sexo, con un sólo carácter y obligatorio.**

```sql
ALTER TABLE Personas
	ADD Sexo VARCHAR(1) NOT NULL;
```

**Desactivar el borrado en cascada (no la actualización) de la clave ajena en la tabla Seguros.**

(No puede eliminarse solamente el borrado en cascada, así que hay que quitar por completo la restricción "fk_seguros_personas", y luego volver a crearla sin borrado en cascada. Observa que esto no afectará a los datos de la tabla.)

```sql
ALTER TABLE Seguros
	DROP CONSTRAINT fk_seguros_personas;

ALTER TABLE Seguros
	ADD CONSTRAINT fk_seguros_personas
		FOREIGN KEY (dni_tomador) REFERENCES Personas(dni)
		ON UPDATE CASCADE;
```

**Insertar estos registros:**
   * En Personas, DNI = 1111A, Juan Martín, C/ Barco, Roquetas de Mar, España
   * En Seguros, Nº Póliza = 1, Compañía = Mapfre, Franquicia = 299,95 €, Tomador = Juan Martín

```sql
INSERT INTO Personas VALUES ('1111A', 'Juan', 'Martín', 'C/ Barco', 'Roquetas de Mar', 'España');

INSERT INTO Seguros (num_póliza, compañía, franquicia, dni_tomador)
	VALUES (1, 'Mapfre', 299.95, '1111A');
```

**Modificar todos los seguros de tipo "Todo riesgo" para que la franquicia sea de 120 €**

```sql
UPDATE Pacientes
	SET pais = 'Desconocido'
	WHERE tipo = 'Todo riesgo';
```

**Borrar todas las personas que no vivan ni en España ni en Portugal.**

```sql
DELETE FROM Personas
	WHERE país <> 'España' AND país <> 'Portugal';
```

**c) Realizar las siguientes consultas** (SELECT):

**Nombre y apellidos, ordenados alfabéticamente, de todas las personas que viven en ciudades que empiezan por "A" (consideraremos también la "A" con tilde):**

```sql
SELECT nombre, apellidos
	FROM Personas
	WHERE ciudad LIKE 'A*'  OR  ciudad LIKE 'Á*'
	ORDER BY apellidos, nombre;
```

**Compañías de seguros que aseguran coches de la marca Seat y cuyas pólizas fueron contratadas después del año 2005.**

```sql
SELECT DISTINCT compañía
	FROM Seguros, Coches
	WHERE Seguros.num_póliza = Coches.seguro
	    AND marca = 'Seat'
	    AND fecha > '31/12/2005';
```

**Precio medio de las franquicias de los coches asegurados por la compañía Mapfre y cuya potencia es mayor de 100 caballos.**

```sql
SELECT AVG(franquicia)
	FROM Seguros, Coches
	WHERE Seguros.num_póliza = Coches.seguro
	    AND compañía = 'Mapfre'
	    AND potencia > 100;
```

**Nombre, apellidos, marca, modelo y compañía aseguradora de los vehículos cuyos dueños tienen varios coches y están asegurados en compañías diferentes.**

Esta consulta no puede resolverse tal y como está, porque no conocemos a los dueños de los vehículos. Esa información, simplemente, no está en la base de datos. Así que supondremos que los dueños y los conductores son los mismos, porque los conductores sí están en la base de datos.

```sql
SELECT nombre, apellidos, marca, modelo, compañía
	FROM Personas AS P1, Coches AS C1, Seguros
	WHERE P1.dni = Seguros.dni_tomador
	     AND Seguros.num_póliza = C1.seguro
	     AND compañía NOT IN (SELECT compañía 
 				FROM Personas AS P2, Coches AS C2, Seguros
				WHERE P2.dni = Seguros.dni_tomador
				     AND Seguros.num_póliza = C2.seguro
				     AND P2.dni = P1.dni
				     AND C2.matrícula <> C1.matrícula);
```

Otra solución posible pasa por conectar la consulta y la subconsulta a través del dni del conductor:

```sql
SELECT nombre, apellidos, marca, modelo, compañía
	FROM Personas AS P1, Coches, Seguros AS S1
	WHERE P1.dni = S1.dni_tomador
	     AND S1.num_póliza = Coches.seguro
	     AND dni IN (SELECT dni 
 			FROM Personas AS P2, Coches, Seguros AS S2
			WHERE P2.dni = S2.dni_tomador
			     AND S2.num_póliza = Coches.seguro
			     AND S1.compañía <> S2.compañía
			     AND P1.dni = P2.dni);
```

#### Ejercicio 2: Biblioteca

**¿A qué puede deberse que la base de datos esté dándonos ese error?**

En la tabla de Libros debe existir al menos un código de autor que no se corresponde con ningún autor de la tabla de Autores. Probablemente se deba a un error en la introducción de los datos. Al convertir a Libros.cód_autor en clave ajena que hace referencia a Autor.cód_autor, la integridad referencial quedaría rota, y por eso el gestor de base de datos nos impide crear esa clave ajena.

**¿Cómo puede solucionarse? Escribe el código SQL que estimes necesario para intentar arreglar el problema.**

Habría que localizar los registros de Libros que tienen asociados autores que no existen en la tabla de Autores. Una vez localizados, tenemos varias opciones: 
a) Borrarlos (una solución un poco bestia)
b) Moverlos a una nueva tabla temporal, para que el administrador de la base de datos haga lo que estime conveniente con esos registros (solución válida porque no destruye datos, pero muy trabajosa)
c) Asignarles un autor "ficticio". Por ejemplo, podemos crear un autor llamado "Desconocido" en la tabla de autores con un código especial (p.ej: el 0), y asignar esos libros al nuevo autor. Esta será la solución que adoptaremos.

```sql
INSERT INTO Autores (cód_autor, nombre) VALUES (0, 'Desconocido');

UPDATE Libros SET cód_autor = 0
	WHERE cód_autor NOT IN (SELECT cód_autor FROM Autores);
```

Ahora sí podemos crear la clave ajena de Autores sin provocar una violación de la integridad referencial. Además, deberíamos repasar los datos de la tabla de Autores para asignar autores válidos a los libros marcados con el código de autor 0 (esto hay que hacerlo manualmente: la base de datos no puede saber qué códigos son los correctos)

#### Ejercicio 3: academia de idiomas

**Crear la tabla HORARIOS. Las claves y las horas son campos obligatorios. El aula es un número entero, y, aunque no es obligatorio, tomará por defecto el valor 1.**

Como la clave primaria es triple (cod_grupo, dia_semana, dni_prof), no tiene sentido declarar esos atributos como UNIQUE de forma individual: lo que no puede repetirse es el conjunto de los tres, de modo que hay que crear una restricción de tabla que denominaremos pk_horarios_unique:

```sql
CREATE TABLE Horarios (
	cod_grupo	VARCHAR(5)	NOT NULL,
	dia_semana	CHAR(1)	NOT NULL,
	dni_prof	VARCHAR(12)	NOT NULL,
	hora_inicio	TIME	NOT NULL,
	hora_fin	TIME	NOT NULL,
	aula		SMALLINT	DEFAULT 1,
	CONSTRAINT pk_horarios
		PRIMARY KEY (cod_grupo, dia_semana, dni_prof),
	CONSTRAINT pk_horarios_unique
		UNIQUE (cod_grupo, dia_semana, dni_prof),
	CONSTRAINT fk_horarios_1
		FOREIGN KEY (cod_grupo) REFERENCES Grupos(cod_grupo),
	CONSTRAINT fk_horarios_2
		FOREIGN KEY (dni_prof) REFERENCES Profesores(dni_prof)
);
```

**Modificar la tabla ALUMNOS para agregar el campo "cod-grupo", que es una clave ajena.**

```sql
ALTER TABLE Alumnos
	ADD cod_grupo VARCHAR(5) NOT NULL;

ALTER TABLE Alumnos
	ADD CONSTRAINT fk_alumnos
		FOREIGN KEY (cod_grupo) REFERENCES Grupos(cod_grupo);
```

**Insertar el registro ["12345678-Z", "Juan", "López López", "Italiano"] en la tabla PROFESORES.**

```sql
INSERT INTO Profesores VALUES ('12345678-Z', 'Juan', 'López', 'Italiano');
```

**Consultar los nombres y apellidos de los profesores que dan clase de francés de lunes a jueves a partir de las 16:00 horas, junto con la denominación de los grupos a los que dan clase y el horario de cada día.**

```sql
SELECT nombre, apellidos, denominación, día_semana, hora_inicio, hora_fin 
	FROM Profesores, Horarios, Grupos
	WHERE Profesores.dni_prof = Horarios.dni_prof
	    AND Horarios.cod_grupo = Grupos.cod_grupo
	    AND (día_semana = 'L' OR día_semana = 'M' OR día_semana = 'X' OR día_semana = 'J')
	    AND hora_inicio >= '16:00'
	    AND idioma = 'Francés';
```

**Consultar los nombres y apellidos de los alumnos que reciben clases de al menos dos idiomas diferentes.**

```sql
SELECT DISTINCT Alumnos.nombre, Alumnos.apellidos
	FROM Alumnos, Horarios, Profesores AS Profes1
	WHERE Alumnos.cod_grupo = Horarios.cod_grupo
	    AND Horarios.dni_prof = Profes1.dni_prof
	    AND Alumnos.dni IN (SELECT Alumnos.dni 
				FROM Alumnos, Horarios, Profesores AS Profes2
				WHERE Alumnos.cod_grupo = Horarios.cod_grupo
			 	    AND Horarios.dni_prof = Profes2.dni_prof
				    AND Profes1.idioma <> Profes2.idioma);
```

**Consultar los nombres y apellidos de los alumnos que reciben clases de INGLÉS y de FRANCÉS.**

```sql
SELECT Alumnos.nombre, Alumnos.apellidos
	FROM Alumnos, Horarios, Profesores
	WHERE Alumnos.cod_grupo = Horarios.cod_grupo
	    AND Horarios.dni_prof = Profesores.dni_prof
	    AND Profesores.idioma = "Inglés"
INTERSECT
SELECT Alumnos.nombre, Alumnos.apellidos
	FROM Alumnos, Horarios, Profesores
	WHERE Alumnos.cod_grupo = Horarios.cod_grupo
	    AND Horarios.dni_prof = Profesores.dni_prof
	    AND Profesores.idioma = "Francés"
```

**Consultar los nombres y apellidos de los alumnos que reciben clases de INGLÉS o de FRANCÉS.**

```sql
SELECT Alumnos.nombre, Alumnos.apellidos
	FROM Alumnos, Horarios, Profesores
	WHERE Alumnos.cod_grupo = Horarios.cod_grupo
	    AND Horarios.dni_prof = Profesores.dni_prof
	    AND (Profesores.idioma = "Inglés" OR Profesores.idioma = "Francés");
```

**Consultar los nombres y apellidos de los alumnos que reciben clases de INGLÉS pero no reciben clases de ALEMÁN.**

```sql
SELECT Alumnos.nombre, Alumnos.apellidos
	FROM Alumnos, Horarios, Profesores
	WHERE Alumnos.cod_grupo = Horarios.cod_grupo
	    AND Horarios.dni_prof = Profesores.dni_prof
	    AND Profesores.idioma = "Inglés"
EXCEPT
SELECT Alumnos.nombre, Alumnos.apellidos
	FROM Alumnos, Horarios, Profesores
	WHERE Alumnos.cod_grupo = Horarios.cod_grupo
	    AND Horarios.dni_prof = Profesores.dni_prof
	    AND Profesores.idioma = "Alemán";
```

#### Ejercicio 4: concesionario de automóviles

**Crear la tabla COCHES, de forma coherente a cómo la hayas diseñado en el primer apartado. Utiliza tipos de datos SQL adecuados a la información que se guardará en cada campo. El campo cod_coche es obligatorio, y el campo precio tiene 10000,00 como valor por defecto.**

```sql
CREATE TABLE Coches (
	cod_coche 	INTEGER	NOT NULL UNIQUE,
	marca	VARCHAR(50)	NOT NULL,
	modelo	VARCHAR(50)	NOT NULL,
	color		VARCHAR(20),
	precio	DECIMAL(8,2)	DEFAULT 10000.00,
	tipo		VARCHAR(5),	
	CONSTRAINT pk_coches
		PRIMARY KEY (cod_coche),
	CONSTRAINT valores_tipo
		CHECK (tipo = "NUEVO" OR tipo = "KM.0" OR tipo = "USADO")
);
```

**Se ha detectado que algunos clientes tienen una "provincia" con valor nulo, pero, en cambio, sí que tienen un valor asignado al campo "ciudad". Escribe la(s) intrucción(es) SQL necesarias para arreglar este problema de la mejor manera que se te ocurra.**

Eso no habría ocurrido si la base de datos hubiera estado bien diseñada, con las provincias y las ciudades en sus respectivas tablas independientes de los Clientes.

Ahora habremos perdido datos irremediablemente. Lo único que podemos hacer es insertar una provincia genérica (por ejemplo, "Desconocida") en los registros que hayan perdido su provincia, para evitar tener valores nulos en la tabla de Clientes.

```sql
UPDATE Clientes
	SET Provincia = "Desconocida"
	WHERE Provincia IS NULL;
```

**Obtener el NIF de los clientes y los códigos de tienda que no sean de la misma ciudad.**

```sql
SELECT Clientes.cod_cliente, Tiendas.cod_tienda
	FROM Clientes, Ventas, Tiendas
	WHERE Clientes.cod_cliente = Ventas.cod_cliente
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Clientes.ciudad <> Tiendas.ciudad;
```

**Obtener la matrícula, la marca y el modelo de los coches vendidos en tiendas de la provincia de Madrid que no hayan sido vendidos en ninguna otra provincia.**

```sql
(SELECT Coches.cod_coche, marca, modelo
	FROM Coches, Ventas, Tiendas
	WHERE Coches.cod_coche = Ventas.cod_coche
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Tiendas.provincia = "Madrid")
EXCEPT
(SELECT Coches.cod_coche, marca, modelo
	FROM Coches, Ventas, Tiendas
	WHERE Coches.cod_coche = Ventas.cod_coche
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Tiendas.provincia <> "Madrid");
```

Existe una solución alternativa basada en subconsultas, pero el resultado debe ser el mismo:

```sql
SELECT Coches.cod_coche, marca, modelo
	FROM Coches, Ventas, Tiendas
	WHERE Coches.cod_coche = Ventas.cod_coche
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Tiendas.provincia = "Madrid"
	    AND Coches.cod_coche NOT IN (SELECT cod_coche
	FROM Coches, Ventas, Tiendas
	WHERE Coches.cod_coche = Ventas.cod_coche
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Tiendas.provicia <> "Madrid")
```

**Obtener el código, ciudad y dirección de las tiendas que tengan entre 5 y 10 vehículos usados que sean de marca "Renault" y modelo "Megane".**

```sql
SELECT Tiendas.cod_tienda, Tiendas.ciudad, Tiendas.dirección
	FROM Tiendas, Coches-están-en-tiendas, Coches
	WHERE Tiendas.cod_tienda = Coches-están-en-tiendas.cod_tienda
	    AND Coches-están-en-tiendas.cod_coche = Coches.cod_coche
	    AND Coches-están-en-tiendas.cantidad BETWEEN 5 AND 10
	    AND Coches.marca = "Renault" AND Coches.modelo = "Megane"
	    AND Coches.tipo = "U";
```

**Obtener el código, marca y modelo del coche, así como el nombre y apellidos del cliente, de todos los vehículos vendidos a un cliente de Almería por un concesionario de Almería.**

```sql
SELECT Coches.cod_coche, marca, modelo, nombre, apellidos
	FROM Coches, Ventas, Clientes, Tiendas
	WHERE Coches.cod_coche = Ventas.cod_coche
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Ventas.cod_cliente = Clientes.cod_cliente
	    AND Tiendas.ciudad = "Almería"
	    AND Clientes.ciudad = "Almería";
```

**Obtener el nombre y apellidos de clientes que hayan adquirido un coche en algún concesionario que posea actualmente en stock el vehículo marca "Seat", modelo "León".**

```sql
SELECT DISTINCT nombre, apellidos
	FROM Coches, Ventas, Clientes, Coches-están-en-tiendas
	WHERE Clientes.cod_cliente = Ventas.cod_cliente 
	    AND Ventas.cod_coches = Coches.cod_coche
	    AND Coches.cod_coches = Coches-están-en-venta.cod_coche
	    AND Coches.marca = "Seat" AND Coches.modelo = "León"
	    AND Coches-están-en-tienda.cantidad > 0;
```

**Obtener los nombres y apellidos de clientes que no han comprado ningún coche de color rojo a ningún concesionario de Andalucía.**

```sql
SELECT nombre, apellidos
	FROM Clientes, Ventas, Tiendas
	WHERE Clientes.cod_cliente = Ventas.cod_cliente
	    AND Ventas.cod_tienda = Tiendas.cod_tienda
	    AND Cliende.cod_cliente NOT IN (SELECT cod_cliente 
					FROM Clientes, Ventas, Tiendas
					WHERE Clientes.cod_cliente = Ventas.cod_cliente
					    AND Ventas.cod_tienda = Tiendas.cod_tienda
					    AND Coches.color = "Rojo"
					    AND Tiendas.provincia IN ("Almería", "Granada", "Jaén",
						"Málaga", "Córdoba", "Sevilla", "Cádiz", "Huelva") );
```

#### Ejercicio 5

**El número de goles marcados por el jugador Pantuflo Zapatilla en los partidos del mes de febrero de 2007.**

```sql
SELECT ADD(goles)
	FROM Futbolistas, Participan, Partidos
	WHERE Futbolistas.cod_futbolista = Participan.cod_futbolista
	    AND Participan.cod_partido = Partidos.cod_partido
	    AND nombre = "Pantuflo" AND apellidos = "Zapatilla"
	    AND fecha BETWEEN "1/2/07" AND "28/2/2007";
```

**El nombre de los equipos contra los que ha jugado el Almería en partidos arbitrados por Esquinas Torres, así como el resultado y la jornada de esos partidos.**

```sql
(SELECT nombre-eq-visitante, resultado, jornada
	FROM Juegan, Partidos, Arbitran, Arbitros
	WHERE Juegan.cod_partido = Partidos.cod_partido
	     AND Partidos.cod_partido = Arbitran.cod_partido
	     AND Arbitran.num_colegiado = Arbitros.num_colegiado
	     AND Arbitros.nombre = "Esquinas" AND Arbitros.apellidos = "Torres"
	     AND Juegan.nombre-eq-casa = "Almería")
UNION
(SELECT nombre-eq-casa, resultado, jornada
	FROM Juegan, Partidos, Arbitran, Arbitros
	WHERE Juegan.cod_partido = Partidos.cod_partido
	     AND Partidos.cod_partido = Arbitran.cod_partido
	     AND Arbitran.num_colegiado = Arbitros.num_colegiado
	     AND Arbitros.nombre = "Esquinas" AND Arbitros.apellidos = "Torres"
	     AND Juegan.nombre-eq-visitante = "Almería")
```

Una solución alternativa es la siguiente, que muestra en todos los registros el nombre de equipo "Almería" junto con su contrincante, ya sea local o visitante:

```sql
SELECT nombre-eq-casa, nombre-eq-visitante, resultado, jornada
	FROM Juegan, Partidos, Arbitran, Arbitros
	WHERE Juegan.cod_partido = Partidos.cod_partido
	     AND Partidos.cod_partido = Arbitran.cod_partido
	     AND Arbitran.num_colegiado = Arbitros.num_colegiado
	     AND Arbitros.nombre = "Esquinas" AND Arbitros.apellidos = "Torres"
	     AND (Juegan.nombre-eq-visitante = "Almería" OR Juegan.nombre-eq-casa = "Almeria")
```

**Todos los datos de la plantilla de futbolistas del Real Madrid.**

```sql
SELECT Futbolistas.*
	FROM Futbolistas, Contratos
	WHERE Futbolistas.cod-futbolista = Contratos.cod-futbolista
	    AND Contratos.nombre_eq = "Real Madrid";
```

**Buscar el nombre y la estatura del futbolista más alto del FC Barcelona.**

```sql
SELECT nombre, estatura
	FROM Futbolistas, Contratos
	WHERE Futbolistas.cod-futbolista = Contratos.cod-futbolista
	    AND Contratos.nombre_eq = "FC Barcelona"
	    AND estatura IN (SELECT MAX(estatura)
				FROM Futbolistas, Contratos
				WHERE Futbolistas.cod-futbolista = Contratos.cod-futbolista
				    AND Contratos.nombre_eq = "FC Barcelona");
```
