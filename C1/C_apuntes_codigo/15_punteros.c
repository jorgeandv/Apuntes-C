#include <stdio.h>


int funcion1(int n) {
    n = 20;
    return n;
}

int funcion2(int m) {
    int suma1 = m+1;
    return suma1;
}

char changeValue1(char *letter) {
    *letter = 'b';
    return *letter;
}

void changeValue2(char *letter) {
    *letter = 'c';
}

int main() {
    int x= 10;
    int *p= &x;   //El puntero p guarda la dirección de memoria de x
    printf("El valor de la variables es: %d", x);
    printf("\nEl valor de la variable obtenido desde el puntero es: %d", *p);
    printf("\nLa dirección de la memoria que guarda el valor de x es: %p", p); 
    
    //Cambiando el valor de x a travez del puntero
    *p=20;   //Ahora x vale 20
    printf("\n\nV2. El valor de la variables es: %d", x);
    printf("\nV2. El valor de la variable obtenido desde el puntero es: %d", *p);
    printf("\nV2. La dirección de la memoria que guarda el valor de x es: %p", p); 

    //Ejemplo de que al hacer función(variable) se copia el valor de variable en parámetro
    //Pasar una variable a una función por valor
    int y = 10;
    funcion1(y); //Ahora n=10 y se entra a la función donde se hace que ahora n=20 pero en todo el camino y=10
    printf("\n\n%d", funcion1(y)); 
    printf("\n%d", y);
    funcion2(y); //Ahora m=10 y se entra a la función donde se hace suma1=10+1=11 pero en todo el camino y=10
    printf("\n\n%d", funcion2(y)); 
    printf("\n%d", y);

    //Pasar una variable a una función por referencia
    char l= 'a';
    changeValue1(&l);    //Le damos a la función la dirección de memoria del valor de l, no le damos l. Así modificamos l, ahora l='b'
    printf("\n%c", changeValue1(&l)); //changeValue1 retorna 'b' asi que se imprime 'b'
    printf("\n%c", l);  //Imprime 'b'
    char h = 'z';
    changeValue2(&h); //Le damos a la función la dirección de memoria del valor de h, no le damos h. Así modificamos h, ahora h='d'
    printf("\n%c", h);  //Imprime 'd', no hicimos printf() con changeValue2 porque esta devuelve un void



    return 0;
}