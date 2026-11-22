#include <stdio.h>

enum dias {
    lunes, martes, miercoles, jueves, viernes, sabado, domingo
};

typedef enum {
    manzana, naranja, platano
} Fruta;

//typedef con cosas que no son el enum
typedef int Conjunto;

int main() {
    enum dias random = martes;
    printf("%d", random);   //Imprime 1 pues random = martes == 1, usamos %d porque cada elemento del cjto enum representa a un entero
    Fruta f = manzana;
    printf("\n%d", f);
    return 0;
}