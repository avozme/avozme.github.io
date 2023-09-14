#include <stdio.h>
#include <conio.h>

#define OPC_SALIR -1
#define NUM_OPCIONES 5
#define OPCIONES { "1. Insertar", "2. 

int main(void)
{
    int opc;
    
    do
    {
       opc = menu();
    }
    while (opc != OPC_SALIR);
    
    return 0;
}


int menu(void)
{
    int opc_actual = 1, opc_anterior = 1;
    
    clrscr();
    gotoxy(5,5); printf("Menú de opciones\n");
    gotoxy(5,7); printf("1. Insertar");
