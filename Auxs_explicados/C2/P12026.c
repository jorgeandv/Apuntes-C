#include <stdio.h>
#include <stdlib.h>
//Ya no tenemos la restricción de tener que usar arreglos con punteros de forma obligada, asi que podemos acceder a un elemento del arreglo de forma fácil

//Recordar que es importante saber dónde está el cursor del archivo, pues sobre esa posición es donde se aplican las funciones

//Los casos donde se corta el programa SIEMPRE deben ir antes que el caso donde se ejecuta el programa

/*
¿Cómo es la estructura del archivo?
Como el archivo sólo almacena enteros (int) de 4 bytes, cada vez que leo 4 bytes estoy leyendo un entero (como el archivo es en formato
binario little-endian que es el mismo de la arquitectura de trabajo, no hay que hacer conversiones).

Así, los primeros 4 bytes son P (Ej: 2), los siguintes 4 bytes son C (Ej: 5), los siguientes 4 bytes son 0 (Ej: 0), ... .

La idea es:
1) Abrir el archivo

2) Si la cola no está vacía, debemos mostrar el elemento desencolado en la salida estándar (usar printf) y el código de retorno 0 (usar return 0)

La condición de que la cola no esté vacía es que P!=C, pero ¿Cómo obtenemos P y C?
Debemos usar fseek para poner el cursor al inicio de la cola
Luego con fread copiar en un arreglo auxiliar que guarde elementos de 4 bytes, así el primer elemento es P y el segundo elemento esC
Luego el arreglo auxiliar quedó con dos elementos, el primero es P y el segundo es C.

Así, podemos comparar para ver el caso de P != C
El cursor quedó en el byte siguiente a C.

Una vez tenemos el P, usando fseek debemos avanzar el cursor 4*P bytes para dejar el cursor en el primer byte del elemento que necesitamos desencolar

Para desencolar ese elemento debemos usar fread con una variable auxiliar para copiar en la memoria de la variable los 4 bytes

Luego, hago printf de esa variable y return 0
*/
int main(int argc, char *argv[]) {
    //Recibe el nombre del archivo que almacena la cola
    FILE *in = fopen(argv[1], "r+");
    
    //No se puede acceder al archivo
    //Esta verificación SIEMPRE se debe hacer después del fopen
    if (in == NULL) {
        perror(argv[1]);
        return 1;
    }

    //Tamaño del archivo
    fseek(in, 0, SEEK_END);   //Mueve el cursor al final del archivo
    int tamArchivo = ftell(in);  //Devuelve el tamaño del archivo (en bytes)

    /*
    Tamaño de la cola
    Recordar que N es el tamaño de la cola, es decir, la cantidad de elementos de la cola, y la cola no considera ni a P ni a C

    Así, al tamaño del archivo hay que restarle 8 bytes (4 bytes de P y 4 bytes de C)
    Luego debemos dividir entre 4 pues cada elemento de la cola ocupa 4 bytes, y así obtenemos el tamaño de la cola
    */
    int N = (tamArchivo - 8)/4;

    //Arreglo auxiliar donde vamos a guardar P y C
    int arreglo[2];
    //El cursor quedó al inicio del archivo
    fseek(in, 0, SEEK_SET);

    //Copio en arreglo P y C (primer y segundo elemento, respectivamente)
    //El cursor quedó en el siguiente byte de C
    fread(arreglo, 4, 2, in);

    int P = arreglo[0];
    int C = arreglo[1];

    //Cola vacía
    if (P == C) {
        //Como usamos fprintf necesitamos modo escritura
        fprintf(stderr, "cola vacía\n");
        fclose(in);
        return 1;
    }

    //Cola no vacía
    //El cursor queda al inicio del elemento que voy a desencolar
    fseek(in, 4*P, SEEK_CUR);
    int desencolar;
    //Copio en la memoria de desencolar los 4 bytes del elemento que voy a desencolar
    fread(&desencolar, 4, 1, in);
    
    //Avanzo el P en uno 
    P++;
    //Al avanzar el P, podemos caer en el caso de "P excede el tamaño del arreglo", así que P no puede ser igual a N (recordar que las posiciones van desde el 0)
    if (P == N) {
        P = 0;
    }

    //El P nuevo debe quedar en el archivo
    //El cursor quedó al inicio del archivo
    fseek(in, 0, SEEK_SET);
    //Escribo el nuevo P
    fwrite(&P, 4, 1, in);

    //Aseguramos de terminar el programa y enviar todo al archivo en disco
    fclose(in); 
    printf("%d\n", desencolar);
    return 0;
}


