#include <stdio.h>

typedef unsigned int uint;

uint max01(uint n){
    //Como necesitamos el valor original de n para los dos ciclos, copiamos este en una variable auxiliar
    uint aux = n;
    //Inicialmente hay 0 1's
    int ones = 0;

    /*
    Cuando aux llega a 0 (todos sus bits son 0), entonces ahí obtengo el número máximo de 1's que tiene el n original
    */
    while(aux != 0){
        //Desplazo aux en 1 bit a la izquierda
        uint saux = aux << 1;
        //Calculo el "y bit a bit"
        aux = aux & saux; 
        //Aumento en 1 la cantidad de 1's  
        ones++;
    }

    //Como necesitamos el valor original de n para los dos ciclos, copiamos este en una variable auxiliar
    aux = n;
    //Inicialmente hay 0 0's
    int zeros = 0;

    /*
    Cuando aux llega a -1, entonces ahí obtengo el número máximo de 0's que tiene el n original
    */    
    while(aux != -1U){
        //Desplazo aux en 1 bit a la izquierda y relleno a la derecha con 1
        uint saux = (aux << 1) | 1;
        //Calculo el "o bit a bit"
        aux = aux | saux;
        //Aumento en 1 la cantida dde 0's
        zeros++;
    }

    //En los primeros 6 bits (de derecha a izquierda) quedan la cantidad máxima de 0's y en el resto de bits la cantidad máxima de 1's
    return (ones<<6) | zeros;
}

 
 int main(int argc, char* argv[]){
    if (argc > 1){
	fprintf(stderr, "Usage: %s <void>\n", argv[0]);
	return 1;
    }
    
    uint x = 0b00001111111001100000000011100011;
    uint res = max01(x);
    uint ceros = res&(~(-1U<<6));
    uint unos = res>>6;
    printf("el numero: 0001111111001100000000011100011111, tiene una maximo de %d unos y %d ceros seguidos\n", unos, ceros);
    return 1;
}
