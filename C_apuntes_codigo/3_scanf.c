#include <stdio.h>
int main(){
    float examen1, examen2;  //Declaramos el tipo de la variable examen1 y examen2
    printf("Dime la nota de tu primer examen: ");
    scanf("%f",&examen1);   //Lo que ingresa el usuario es un float que se guarda en la variable examen1 (la cual ya habiamos declarado su tipo)
    printf("Dime la nota de tu segundo examen: ");
    scanf("%f",&examen2);   //Lo que ingresa el usuario es un float que se guarda en la variable examen2 (la cual ya habiamos declarado su tipo)
   
    float notaFinal;
    notaFinal = (examen1 + examen2) / 2;
    printf("Tu nota final es %f", notaFinal);
    return 0;
}