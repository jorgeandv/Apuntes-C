#include <stdio.h>
int main(){
    int edad;
    printf("Ingresa tu edad: ");
    scanf("%d", &edad);
    if (edad >= 18){
        printf("Eres mayor de edad!");
    } else {
        printf("No eres mayor de edad!");
    }

    return 0;
}