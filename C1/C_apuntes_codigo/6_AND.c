#include <stdio.h>
int main(){
    //Saber si un número es par o impar
    int n;  
    printf("Ingresa un número: ");
    scanf("%d", &n);
    if (n & 1){
        printf("El número es impar");
    } else {
        printf("El número es par");
    }

    //Verificar permisos donde cada permiso es un numero binario
    //Supongamos los permisos de lectura 0001 (1 en entero), de escritura 0010 (2 en entero), de ejecución (4 en entero)
    //Tenemos el archivo 1100 (12 en entero) y queremos saber si tiene permisos de escritura y de ejecución
    int archivo = 12;
    int permisoLectura = 1;
    int permisoEjecucion = 4;
    if (archivo & permisoLectura){  //Se cae acá si archivo & permisoLectura != 0
        printf("\nEl archivo SÍ tiene permisos de lectura");
    } else {
        printf("\nEl archivo NO tiene permisos de lectura");
    }
    if  (archivo & permisoEjecucion){   //Se cae acá si archivo & permisoLectura != 0
        printf("\nEl archivo SÍ tiene permisos de ejecución");
    } else {
        printf("\nEl archivo NO tiene permisos de ejecución");
    }

    //Apagar bits especificos
    //Tenemos el numero binario 101101 (45 en entero) y queremos conservar solo los ultimos 4 bits
    int x = 45; 
    int y = 15; // 15 entero en binario es 001111, nos ayuda a conservar solo los ultimos 4 bits
    int seConserva = x&y;
    printf("\nEl número que queda es el %d", seConserva);   //El número que qeuda es el 13 que en binario es 001101 (solo conserve los ultimos 4 bits)
    return 0;
}