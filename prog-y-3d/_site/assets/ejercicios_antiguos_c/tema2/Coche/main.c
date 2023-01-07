#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>


#define X_INI 35    // Posición inicial de la carretera

void escribir_espacios(int n);
void mostrar_vidas(int v);
void retardo(int centesimas);




int main()
{
  int cx;   // Posición carretera
  int x;    // Posición coche
  int r, salir, vidas = 3;
  long t1, t2;
  char c;
  
  printf("FUNDAMENTOS DE PROGRAMACION\nEjercicio obligatorio del tema 2 - Versión básica\n\n\n");
  printf("Conduce el coche sin salirte de la carretera.\n");
  printf("Controles: 'Z' = izquierda, 'X' = derecha, 'Q' = salir\n\n\n");
  system("pause");
  clrscr();

  t1 = time(NULL);
  srand(t1);

  cx = X_INI;
  x = cx + 5;
  
  salir = 0;
 
  mostrar_vidas(vidas); 
  
  while (salir == 0)
  {
    // Mover la carretera
    r = rand() % 3;
    if (r == 0) { cx++; if (cx == 80) cx = 79; }
    if (r == 1) { cx--; if (cx == 0) cx = 1; }

    // Mover el coche
    if (kbhit() != 0)
    {
      c = getch();
      if (c == 'x') { x++; if (x == 80) x = 79; }
      if (c == 'z') { x--; if (x == 0) x = 1; }
      if (c == 'q') salir = 1;
    }

    // Mostrar carretera y coche
    escribir_espacios(cx-1);     
    if (cx < x) printf("|");
    escribir_espacios(x-cx-1);
    printf("H");
    escribir_espacios((cx+10)-x-1);
    if ((cx+10) > x) printf("|");
    printf("\n");
    
    // Comprobar posiciones
    if ((x <= cx) || (x >= (cx+10)))
    {
        escribir_espacios(cx);
        printf("CRASHHH !!!");
        retardo(100);
        vidas--;
        mostrar_vidas(vidas);
        cx = X_INI;
        x = cx+5;
        if (vidas == 0) salir = 1;
    }
    
    retardo(10);
  }

  t2 = time(NULL);
  
  clrscr();
  t1 = t2-t1;
  printf("Has durado %li minutos y %li segundos\n\n", t1/60, t1%60);

  system("PAUSE");	
  return 0;
}


void escribir_espacios(int n)
{
    int i;
    for (i=1; i<=n; i++) printf(" ");
}


void mostrar_vidas(int v)
{
    clrscr();
    gotoxy(34, 12);
    cprintf("Vidas: %i", v);
    retardo(200);
    clrscr();
    gotoxy(1,1);
}

// Detiene la ejecución del programa las centésimas de segundo indicadas
void retardo(int centesimas)
{
    clock_t t_ini, t_fin;
    
    t_ini = clock() / (CLOCKS_PER_SEC / 100);
    t_fin = t_ini + centesimas;
    
    while (t_ini < t_fin)
        t_ini = clock() / (CLOCKS_PER_SEC / 100);
}
