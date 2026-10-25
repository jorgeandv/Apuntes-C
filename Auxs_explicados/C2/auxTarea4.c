#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "pss.h"

#define TAMFIL (sizeof(Fila))


/*
El objetivo de este programa es recibir el archivo que contiene el diccionario e imprimir en pantalla 
el diccionario de la forma llave ===> valor
*/

//Se define la estrucutra de fila
typedef struct {
    unsigned char tamLlave; //Tamaño de la llave, 0 si la fila esta vacia
    char llaveYDef[99];     //Los primeros tamLLave bytes corresponden a la llave
                            //El resto corresponden al valor, relleno con espacios
                            //en blanco al final.
} Fila;

int main(int argc, char **argv) {
    //Error en caso de que no se haya pasado bien el archivo
    if (argc != 2) {
        fprintf(stderr, "Uso: ./revisar <archivo>\n");
        exit(1);
    }

    //AL ejecutar el programa, lo primero que se pasa es el archivo que contiene al diccionario
    /*
    Lo de abajo pudo ser:
    FILE *dicc = fopen(argv[1], "r");
    */
    char *nom = argv[1];
    FILE *dicc = fopen(nom, "r");

    //Error en caso de que no se pueda leer el archivo
    if (dicc == NULL) {
        perror(nom);
        exit(1);
    }

    //Definimos una variable fil de tipo Fila
    Fila fil;

    /*
    El fread copia en la memoria de la variable fil la primera fila del archivo
    
    El while se ejecuta mientras ese fread retorne 1, es decir, mientras retorne la cantidad de elementos que logró leer
    Recordar: fread retorna la cantidad de elementos completos que logró leer si todo salió bien o retorna menos que cantidad 
    si es que se llegó al final del archivo o hubo un error
    */

    /*
    ¿Dónde se avanza la iteración en el while?
    En el fread, pues el fread avanza el cursor cada vez que se ejecuta, así en la siguiente iteración el cursor está más adelante
    */
    while (fread(&fil, TAMFIL, 1, dicc) == 1) {
        
        //Define los arreglos de caracteres, llave y valor
        char llave[TAMFIL], valor[TAMFIL];
        //Como fil es una estructura, accedo a su campo de tamaño de la Llave y lo guardo en la variable tamLlave para trabajar más cómodo
        int tamLlave = fil.tamLlave;
        
        //La fila esta vacia
        if (tamLlave == 0) 
            continue;   //Se ignora esta iteración 

        /*
        strncpy es como strcpy pero ahora en el último argumento se pone la cantidad de bytes que se quieren copiar
        
        ¿Cuando copio bytes en un arreglo, como se cuantos bytes quedan por elemento?
        Depende del tipo de los elementos del arreglo, cada elemento ocupa sizeof(tipo) bytes.

        Así, en llave se copian tamLlave bytes de fil.llaveYDef, de esta manera el arreglo llave tiene la llave
        */
        strncpy(llave, fil.llaveYDef, tamLlave);

        //Al final del arreglo llave pongo el '\0' para que ahora sea un string
        llave[tamLlave] = 0;

        /*
        En valor se copian TAMFIL - tamLlave - 1 bytes (el tamaño del valor) de fil.llaveYDef + tamLlave
        ¿Por qué fil.llaveYDef + tamLlave?
        Tenemos que fil.llaveYDef es un arreglo que tiene a la llave y al valor, por aritmetica de punteros, al sumarle tamLlave, el puntero 
        del origen ahora apunta al primer byte del valor
        */
        strncpy(valor, fil.llaveYDef + tamLlave, TAMFIL - tamLlave - 1);

        //Al final del arreglo valor pongo el '\0' para que ahora sea un string
        valor[TAMFIL - tamLlave - 1] = 0; 

        /*
        El problema es que en valor copiamos todo lo que iba después de la llave, incluyendo el valor e incluyendo espacios en blanco,
        tenemos que quitar esos espacioes en blanco
        */

        /*
        El puntero fin apunta al final del valor (al final de los espacios en blanco)
        Donde
        *valor es el arreglo que inclute el valor e incluye los espacios en blanco
        *(TAMFIL - 1 - tamLlave) es la cantidad de bytes del valor
        * -1 pues el índice del último byte es la cantidad de bytes menos 1
        */
        char *fin = valor + ((TAMFIL - 1 - tamLlave) - 1);

        //Mientras fin siga dentro del arreglo (recordar que valor apunta al primer valor) y fin apunte a un espacio
        while (fin >= valor && *fin == ' ')
            fin--;      //Retrocedo fin

        //Recordar que fin[1] == *(fin + 1)
        //Cuando se sale del while anterior, fin quedó apuntando al fin del valor sin espacios , así que ponemos '\0' ahí  
        fin[1] = 0;

        //Imprimimos llave ===> valor
        printf("%s ===> %s\n", llave, valor);
    }

    //Error cuando se leyó o escribió el archivo
    if (ferror(dicc)) {
        perror(nom);
        exit(1);
    }

    //Aseguramos de terminar el programa y enviar todo al archivo en disco
    fclose(dicc);
    return 0;
}