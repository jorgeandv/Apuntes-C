#include <stdio.h>
#include <stdlib.h>

int bits1(unsigned int n){
    int counter = 0;    //Contador parte en 0
    while(n){   //Mientras n sea distinto de 0
        /*
        El n&0b1 hace que se va analizando el último bit de la versión binaria de n:
        *Si este último bit es 1, el resultado n&0b1 es 1 en entero
        *Si este último bit es 0, el resultado n&0b1 es 0 en entero
        
        Luego, desplazo 1 a la derecha el n para que en la siguiente iteración leer 
        el "nuevo" último bit de la versión binaria de n
        */
        counter+=(n&0b1);   
        n>>=1;
    }
    return counter;
}

int main(int argc, char* argv[]){
    if (argc < 2){
	fprintf(stderr, "Usage: %s <int>\n", argv[0]);
	return 1;
    }
    
    int n = atoi(argv[1]);
    // int n = strtol(argv[1], NULL, 2); Con este pueden hacer que la terminal reciba el numero en binario
    printf("el numero %d, en binario tiene %d 1's\n", n, bits1(n));
}
