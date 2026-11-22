#include <stdio.h>
int main(){
    //Activar permisos donde cada permiso es un numero binario
    //Supongamos los permisos de lectura 0001 (1 en entero), de escritura 0010 (2 en entero), de ejecución (4 en entero)
    //Tenemos el archivo 1100 (12 en entero) y queremos darle permisos de lectura
    int archivo = 0b1100, permisoLectura = 0b0001, nuevoArchivo = archivo | permisoLectura; //podemos abreviar así al definir varias variables de un mismo tipo
    printf("El archivo con los permisos de lectura activos es el %d", nuevoArchivo);
    return 0; 
}