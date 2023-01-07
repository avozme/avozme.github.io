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
  
  textbackground(BLUE); clrscr();
  textbackground(GREEN); textcolor(WHITE);
  gotoxy(13,3); cprintf("                                                        ");
  gotoxy(13,4); cprintf("               FUNDAMENTOS DE PROGRAMACION              ");
  gotoxy(13,5); cprintf("  Ejercicio obligatorio del tema 2 - Versión coloreada  ");
  gotoxy(13,6); cprintf("                                                        ");
  textcolor(YELLOW);
  gotoxy(13,7); cprintf("      Conduce el coche sin salirte de la carretera.     ");
  gotoxy(13,8); cprintf(" Controles: 'Z' = izquierda, 'X' = derecha, 'Q' = salir ");
  gotoxy(13,9); cprintf("                                                        ");
  
  textbackground(BLUE); textcolor(LIGHTGRAY);
  gotoxy(20,12); system("pause");
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
    textbackground(GREEN);
    escribir_espacios(cx-1);     
    textcolor(YELLOW);
    textbackground(BLACK);
    if (cx < x) printf("|");
    escribir_espacios(x-cx-1);
    textcolor(LIGHTBLUE);
    printf("H");
    escribir_espacios((cx+10)-x-1);
    textcolor(YELLOW);
    if ((cx+10) > x) printf("|");
    textbackground(GREEN);
    escribir_espacios(70-cx);
    //printf("\n");
    
    // Comprobar posiciones
    if ((x <= cx) || (x >= (cx+10)))
    {
        textbackground(GREEN);
        escribir_espacios(cx);
        textbackground(BLACK); textcolor(LIGHTRED);
        printf("CRASHHH !!!");
        textbackground(GREEN);
        escribir_espacios(70-cx);
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
  
  textbackground(BLUE);
  clrscr();
  textbackground(GREEN);
  textcolor(YELLOW);
  t1 = t2-t1;
  gotoxy(20,12); cprintf("                                       ");
  gotoxy(20,13); cprintf("  Has durado %2li minutos y %2li segundos  ", t1/60, t1%60);
  gotoxy(20,14); cprintf("                                       ");
  
  textcolor(LIGHTGRAY); textbackground(BLUE);
  gotoxy(20,16);
  system("PAUSE");	
  textbackground(BLACK);
  textcolor(LIGHTGRAY);
  clrscr();
  return 0;
}


void escribir_espacios(int n)
{
    int i;
    for (i=1; i<=n; i++) printf(" ");
}


void mostrar_vidas(int v)
{
    textbackground(BLUE);
    clrscr();
    textbackground(GREEN); textcolor(YELLOW);
    gotoxy(32, 11); cprintf("                ");
    gotoxy(32, 12); cprintf("    Vidas: %i    ", v);
    gotoxy(32, 13); cprintf("                ");
    retardo(200);
    textbackground(GREEN);
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
