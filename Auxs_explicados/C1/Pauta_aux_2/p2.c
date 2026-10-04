#include <stdlib.h>
#include <stdio.h>

int posicionBits(int x, int p, int n);

int main(){
    uint x = 0b0001110;
    uint p = 0b111;
    printf("El patron ocurre primero en la posicion 1 y obtenemos que ocurren en la posicion: %d\n",posicionBits(x,p,3));

    p = 0b0;
    printf("El patron ocurre primero en la posicion 0 y obtenemos que ocurren en la posicion: %d\n",posicionBits(x,p,1));

    p = 0b1111;
    printf("El patron no ocurre y obtenemos que: %d\n",posicionBits(x,p,4));

    uint a = 0b011;
    printf("El patron ocurre primero en la posicion 2 y obtenemos que ocurren en la posicion: %d\n",posicionBits(x,a,3));
}

int posicionBits(int x, int p, int n) {
	unsigned m = -1;	//Como m es unsigned, si se hace m=-1 su versión binaria tiene todos los bits en 1
	/*
	m se desplaza n veces a la izquierda dejando con 0's los últimos n bits y con 1's el resto
	luego, se niega lo anterior dejando con 1's los ultimos n bits y con 0's el resto
	*/
	int mask = ~(m << n);	
	/*
	El ciclo se hace hasta el largo del binario de x menos el tamaño de n (pues el patron p debe estar antes de los ultimos n bits)
	y se suma 1 para incluir la ultima posición
	*/
	for(unsigned long i = 0; i < sizeof(x)*8 - n + 1;i++){
		/*
		x se desplaza i veces a la derecha y se hace & mask, extrayendo los n bits de x (el resto son 0's)	 
		si lo anteriior es igual a p, entonces encontramos el patrón p en x, se retorna i
		si no, no hacemos nada y pasa a la siguiente iteración
		*/
		if (((x >> i) & mask) == p){
			return i; 
		}
	}
	//Si salimos del ciclo es porque no encontramos p, se retorna -1
	return -1;
}
