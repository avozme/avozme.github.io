#include <stdio.h>

struct s_producto
{
   char nombre[20];
   float precio;
   int codigo;
   int proveedor;
   int stock;
};

struct s_proveedor
{
   int codigo;
   char nombre[50];
   char dir[50];
   long int telef;
};

void actualizar_stock(void);
void listar_productos(void);
void mostrar_datos_proveedor(int cod_proveedor);
void insertar_datos(void);

void insertar_datos(void);

int main(void)
{
   char c[50];
   int opc;
   
   insertar_datos();
   
   do
   {
      printf("Elija qué desea hacer:\n");
      printf("1 - Actualizar stock de un producto\n");
      printf("2 - Listar productos bajos de stock\n");   
      printf("3 - Salir\n");
      printf("Seleccione opción (1,2 ó 3): ");
      gets(c);
      opc = atoi(c);
      
      if (opc == 1) actualizar_stock();
      if (opc == 2) listar_productos();
   }
   while (opc!=3);
   
   return 0;
}



void actualizar_stock(void)
{
   FILE* f;
   int cod_prod, cant;
   struct s_producto producto;
   char c[50];
   
   printf("Introduzca código del producto: ");
   gets(c);
   cod_prod = atoi(c);
   
   printf("Introduzca la cantidad que el cliente ha comprado: ");
   gets(c);
   cant = atoi(c);
   
   f = fopen("productos.bin", "r+b");
   if (f == NULL) {
      printf("No puedo abrir el archivo de productos");
      return;
   }
   
   fseek(f, (cod_prod - 1) * sizeof(struct s_producto), SEEK_SET);
   fread(&producto, sizeof(struct s_producto), 1, f);
   
   producto.stock = producto.stock - cant;

   fseek(f, (cod_prod - 1) * sizeof(struct s_producto), SEEK_SET);
   fwrite(&producto, sizeof(struct s_producto), 1, f);
   
   fclose(f);
}


void listar_productos(void)
{
   FILE *f_prod;
   struct s_producto producto;
   char c[50];
   int n;

   printf("----------------------------------------------\n");
   printf("LISTADO DE PRODUCTOS BAJOS EN STOCK\n");

   f_prod = fopen("productos.bin", "rb");
   if (f_prod == NULL) {
      printf("No puedo abrir el archivo de productos");
      return;
   }
   
   while (!feof(f_prod))
   {
      n = fread(&producto, sizeof(struct s_producto), 1, f_prod);
      if ((n == 1) && (producto.stock <= 20))
      {
          printf("----------------------------------------------\n");
          printf("PRODUCTO: %s\n", producto.nombre);
          printf("UNIDADES QUE QUEDAN: %i\n", producto.stock);
          mostrar_datos_proveedor(producto.proveedor);
      }
   }
   
   fclose(f_prod);
}

void mostrar_datos_proveedor(int cod_proveedor)
{
   FILE* f_prooved;
   struct s_proveedor proveedor;
   
   f_prooved = fopen("proveedores.bin", "r+b");
   if (f_prooved == NULL) {
      printf("No puedo abrir el archivo de proveedores\n");
      return;
   }
   
   fseek(f_prooved, (cod_proveedor - 1) * sizeof(struct s_proveedor), SEEK_SET);
   fread(&proveedor, sizeof(struct s_proveedor), 1, f_prooved);
   
   printf("DATOS DEL PROVEEDOR:\n");
   printf("  - Nombre: %s\n", proveedor.nombre);
   printf("  - Dirección: %s\n", proveedor.dir);
   printf("  - Teléfono: %i\n", proveedor.telef);
   
   fclose(f_prooved);
}


void insertar_datos(void)
{
   struct s_producto producto;
   struct s_proveedor proveedor;
   char c[50];
   FILE* f;
   
   printf("INSERTAR DATOS DE PRODUCTOS (fin para terminar)\n");
   f = fopen("productos.bin", "ab"); 
   if (!f) { printf("Error al abrir archivo de productos"); return; }
   producto.codigo = 0;
   do
   {
      producto.codigo++;
      printf("Producto %i\n", producto.codigo); 
      printf("Nombre: "); gets(producto.nombre); 
      if (strcmp(producto.nombre, "fin") == 0) break; 
      producto.precio = rand() % 10 + ((float)(rand() %10) / (float)10);
      printf("Precio: %2.2f\n", producto.precio);
      producto.stock = rand() % 1000;
      printf("Stock: %i\n", producto.stock);
      printf("Cód. Proveedor: "); gets(c); producto.proveedor = atoi(c);
      
      fwrite(&producto, sizeof(struct s_producto), 1, f);
   }
   while (1==1);
   
   fclose(f);
   
   printf("INSERTAR DATOS DE PROVEEDORES (fin para terminar)\n");
   f = fopen("proveedores.bin", "ab"); 
   if (!f) { printf("Error al abrir archivo de productos"); return; }
   proveedor.codigo = 0;
   do
   {
      proveedor.codigo++;
      printf("Proveedor %i\n", proveedor.codigo); 
      printf("Nombre: "); gets(proveedor.nombre); 
      if (strcmp(proveedor.nombre, "fin") == 0) break; 
      printf("Dirección: "); gets(proveedor.dir);
      printf("Teléfono: "); gets(c); proveedor.telef = atoi(c);
      
      fwrite(&proveedor, sizeof(struct s_proveedor), 1, f);
   }
   while (1==1);
   
   fclose(f);
}

