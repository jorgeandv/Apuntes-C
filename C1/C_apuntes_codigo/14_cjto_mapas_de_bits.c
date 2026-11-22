#include <stdio.h>

typedef enum {
    manzana, pera, guinda, platano  //posición 0, posición 1, posición 2, posición 3
} Fruta;

typedef int Conjunto;

//Función singleton para Fruta
Conjunto singleton ( Fruta f ) {    //La función es de tipo Conjunto
    Conjunto c=0;
    c = c|(1<<f);
    return c;
}


int main() {
    Conjunto c = 0;
    c=c|1;    //Agregamos manzana al conjunto
    c= c|(1 << guinda);;   //agregamos guinda al conjunto, al int 1 lo desplazo 2 a la izquierda (obtengo 100) y ese resultado le hago un o al C
    return 0;
}