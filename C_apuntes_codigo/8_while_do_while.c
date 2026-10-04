#include <stdio.h>
int main(){
    //Cuenta atrás desde 3 hasta 0
    int contador = 3;
    while (contador >=0 ){
        printf("\n%d", contador);
        contador--;
    }

    //Pide un número positivo al usuario y se corta cuando se ingresa un numero negativo
    int n;  //Como la condición se evalua despues de que le usaurio le da un valor al n, no voy a tener problemas con que el n no tiene valor
    do {
        printf("Ingresa un número entero positivo: ");
        scanf("%d", &n);
    } while (n>0);
    printf("TE DIJE QUE INGRESARAS UN NÚMERO POSITIVO!, PORFIADO");
    return 0;
}





//Simulando un do While en Python
/*
while True:
    numero = int(input("Ingresa un número positivo: "))
    if numero > 0:
        break

print(f"Ingresaste: {numero}")
*/

//Haciendo el ejercici odel do while con while
/*
#include <stdio.h>
int main(){
    int x = 1; //La condición se evalua antes de que el usuario le de un valor al x, asi que para asegurarme de que entre al ciclo tengo que darle un valor al x>0
    while (x>0){
        printf("Ingresa un número entero positivo: ");
        scanf("%d", &x);
    }
    printf("TE DIJE QUE INGRESARAS UN NÚMERO POSITIVO!, PORFIADO");
    return 0;
}
*/