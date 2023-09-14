
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
