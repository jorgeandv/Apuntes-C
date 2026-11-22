#include <stdio.h>  //Le dice al compilador que incluya el contendio de stdio.h
int main() {
    int edad1 = 43; //Definimos la variable edad1
    int edad2 = 40;
    #define PI 3.14 //Definimos la cte. PI
    printf("La primera edad es %d y la segunda edad es %d", edad1, edad2);
    printf("El valor de pi es %f", PI);
    return 0;   
}
