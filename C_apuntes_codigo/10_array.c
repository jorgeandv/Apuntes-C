#include <stdio.h>
int main(){
    int array[5];   //Arreglo de 5 elementos enteros
    printf("Ingresa un elemento para poner en el arreglo (serán 5):\n");  //Al poner el printf() fuera del for pero el scanf() dentro del for, se hace una vez la pregunta pero se ingresa en cada iteración una respuesta
    for (int i=0; i<5; i++) {
        scanf("%d", &array[i]);   //El dato que ingresa el usuario es un int que se guarda en array[i], asi vamos metiendo los elementos al arreglo
    }
    printf("\nEl arreglo es:\n");
    for (int j=0; j<5; j++) {
        printf("\narray[%d] = %d", j, array[j]);
    }    
    return 0;
}