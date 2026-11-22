#include <stdio.h>
int main(){
    int dia;
    printf("En qué dia de la semana estás (en numero del 1 al 7): ");
    scanf("%d", &dia);
    switch (dia)
    {
    case 1:
        printf("Hoy es Lunes");
        break;
    case 2:
        printf("Hoy es Martes");
        break;
    case 3:
        printf("Hoy es Miercoles");
        break;
    default:
        printf("Hoy es Jueves o Viernes o Sabado o Domingo");        
    }
    return 0;
}
