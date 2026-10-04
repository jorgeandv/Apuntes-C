#include <stdio.h>
int main() {
    //Muestra las tablas de multiplicar de un número que ingresa el usuario
    int n, x; //n:La tabla es de este número, x:Hasta ese número llega la tabla
    printf("Ingresa un número entero y te mostraré su tabla de multiplicar: ");
    scanf("%d", &n);
    printf("Ingresa hasta que número quieres ver la tabla: ");
    scanf("%d", &x);
    for (int i=1; i<=x; i++) {
        int resultado = n*i;
        printf("\n%d x %d = %d", n, i, resultado);
    }

    //Muestra las tablas de multiplicar que el usuario quiera
    int y;  //número de tablas que se verán
    printf("\nDime hasta cuantas tablas de multiplicar quieres ver (1 al 10): ");
    scanf("%d", &y);
    for (int i=1; i<=y; i++) {
        printf("\n\nTabla del %d", i);
        for (int j=1; j<=10; j++) {
            int resultado1 = i*j;
            printf("\n%d x %d = %d", i, j, resultado1);
        }
    }
    
    return 0;
}

