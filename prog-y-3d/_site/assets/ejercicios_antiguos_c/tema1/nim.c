// JUEGO DE NIM
// Actividad obligatoria del tema 3 (curso 05-06)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crear_montones(int *m1, int *m2, int *m3);
int elegir_monton(char turno, int m1, int m2, int m3);
int comprobar_monton(int m, int m1, int m2, int m3);
int elegir_palillos(char turno, int monton, int *m1, int *m2, int *m3);
int comprobar_palillos(int palillos, int monton, int m1 , int m2, int m3);
int mostrar_montones(char turno, int m1 , int m2, int m3);
char comprobar_fin_juego(char turno, int m1, int m2, int m3);

int main()
{
     int mtn1, mtn2, mtn3;          // Montones
     int monton;                    // Montón elegido en cada turno
     int palillos;                  // Nº de palillos elegido en cada turno
     char turno;                    // Turno ('H' = humano, 'M' = máquina)
     char ganador;                  // Ganador ('H' = humano, 'M' = máquina, 'N' = ninguno)
     
     crear_montones(&mtn1, &mtn2, &mtn3);
     turno = 'H';
     
     do
     {
           mostrar_montones(turno, mtn1, mtn2, mtn3);
           monton = elegir_monton(turno, mtn1, mtn2, mtn3);
           palillos = elegir_palillos(turno, monton, &mtn1, &mtn2, &mtn3);
           ganador = comprobar_fin_juego(turno, mtn1, mtn2, mtn3);
           if (turno == 'H') turno = 'M'; else turno = 'H';
     }
     while (ganador == 'N');
     
     if (ganador == 'H') printf("Me has ganado vilmente y haciendo trampas\n");
     else printf("Te he ganado, sucio humano\n");

     system("PAUSE");
     return 0;
}
                
// Crear el contenido inicial de los montones
void crear_montones(int *m1, int *m2, int *m3)
{
     time_t t;
     
     t = time(NULL);            // Inicializar generador de números aleatorios
     srand(t);
     
     *m1 = (rand() % 4) + 3;    // Crear contenido de los montones (entre 3 y 6 palillos)
     *m2 = (rand() % 4) + 3;
     *m3 = (rand() % 4) + 3;
}
     
     
// Elige un montón, comprobando que no esté vacío
int elegir_monton(char turno, int m1, int m2, int m3)
{
    char cad[50];
    int m, ok;
    
    if (turno == 'H')           // Turno del jugador HUMANO
    {
        do
        {
          do
          {
            printf("¿De qué montón quieres quitar palillos (1, 2 ó 3)?");
            gets(cad);
            m = atoi(cad);
          }
          while ((m < 1) || (m > 3));
          ok = comprobar_monton(m, m1, m2, m3);
          if (ok == 0)
             printf("Ese montón está vacío, elige otro\n");
        }
        while (ok == 0);
    }
    
    if (turno == 'M')           // Turno del ORDENADOR
    {
        do
        {
          do {
            m = rand() % 3 + 1;
          }
          while ((m < 1) || (m > 3));
          ok = comprobar_monton(m, m1, m2, m3);
        }
        while (ok == 0);
    }
        
    return m;
}    
        
        
// Devuelve 0 si el monton está vacío y 1 si no lo está
int comprobar_monton(int m, int m1, int m2, int m3)
{
    int res;
    if (m == 1) {
       if (m1 == 0) res = 0; else res = 1;
    }
    if (m == 2) {
       if (m2 == 0) res = 0; else res = 1;
    }
    if (m == 3) {
       if (m3 == 0) res = 0; else res = 1;
    }
    
    return res;
}


// Elige un número de palillos, comprobando que en el montón queden los suficientes
int elegir_palillos(char turno, int monton, int *m1, int *m2, int *m3)
{
    char cad[50];
    int p, ok;

    if (turno == 'H')
    {
        do
        {
          do
          {
            printf("¿Cuántos palillos quieres quitar (1 ó 2)?");
            gets(cad);
            p = atoi(cad);
          }
          while ((p < 1) || (p > 2));
          ok = comprobar_palillos(p, monton, *m1, *m2, *m3);
          if (ok == 0)
             printf("Ese montón no tiene tantos palillos, elige otra cantidad\n");
        }
        while (ok == 0);
    }              

    if (turno == 'M')
    {
        do
        {
          do
          {
            p = rand() % 2 + 1;
          }
          while ((p < 1) || (p > 2));
          ok = comprobar_palillos(p, monton, *m1, *m2, *m3);
        }
        while (ok == 0);
        printf("Es mi turno.\nElijo quitar %i palillos del montón %i\n", p, monton);
    }     
    
    if (monton == 1)
       *m1 = *m1 - p;         
    if (monton == 2)
       *m2 = *m2 - p;         
    if (monton == 3)
       *m3 = *m3 - p;         

}
     
     
// Devuelve 0 si el montón no tiene el suficiente número de palillos, o 1 en otro caso
int comprobar_palillos(int palillos, int monton, int m1 , int m2, int m3)
{
    int res;
    
    if (monton == 1)
    {
        if (palillos > m1) res = 0; else res = 1;     
    }
    
    if (monton == 2)
    {
        if (palillos > m2) res = 0; else res = 1;     
    }
    
    if (monton == 3)
    {
        if (palillos > m3) res = 0; else res = 1;     
    }

    return res;
}


// Muestra el contenido actual de los montones
int mostrar_montones(char turno, int m1 , int m2, int m3)
{
    printf("\n\nTURNO: %c\n\n", turno);
    printf("El contenido actual de los montones es:\n");
    printf("  Montón 1: %i palillos\n", m1);
    printf("  Montón 2: %i palillos\n", m2);
    printf("  Montón 3: %i palillos\n\n", m3);
}

// Comprueba si el juego ha terminado (sólo queda un palillo)
// En tal caso, devuelve el ganador. Si no, devuelve 'N'
char comprobar_fin_juego(char turno, int m1, int m2, int m3)
{
    int palillos;
    char res;
    
    palillos = m1 + m2 + m3;
    
    res = 'N';
    if (palillos == 1)
    {
        if (turno == 'H') res = 'M'; else res = 'H';
    }
    if (palillos == 0)
    {
        if (turno == 'H') res = 'H'; else res = 'M';
    }
    return res;
}
