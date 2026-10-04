#include <stdlib.h>
#include <stdio.h>

//Estrutura de Nodo para P1
typedef struct Nodo{
	int x;
	struct Nodo* sgte;
} Nodo;



/*La función append recibe un puntero a un puntero que apunta al primer nodo de la lista enlazada a 
y un puntero que apunta al primer nodo de la lista enlazada b

Por que para la lista enlazada a se recibe un puntero a puntero en vez de solo un puntero?
Porque si tenemos el caso donde la lista enlazada a es vacia, al agregarle la lista b, el puntero que apunta al primer nodo de la
lista a ahora debe apuntar al primer nodo de la lista b, es decir, debo modificar el puntero que apunta al primer nodo de la lista enlazada a

Esto no pasa si es que la lista a no es vacia, pero como debo cubrir todos los casos, usamos puntero a puntero
*/
void append(Nodo **pa, Nodo *b){
    /*
    Estoy definiendo el puntero a, al que le asigno el valor de *pa (que es el puntero que inicialmente apunta al primer
    elemento de la lista a del programa que llamó a la función, luego en cada recursión este puntero va avanzando)
    */

    /*Ej:
    int x=5;
    int *p=&x;   
    donde *p es x y p es &x

    int **pp=&p;
    donde *pp es p y pp es &p
    */

    /*
    Por que se define la variable a?
    En teoria podriamos usar directamente *pa en vez de a, pero una buena practica es definir a para 
    usarlo en las cosas donde solo necesitamos leer y no modificar, para luego usar *pa en donde si queremos modificar

    Esto pues a es solo una copia, si modificamos a no estamos afectando a la lista enlazada a, para eso hay que usar *pa
    */
    Nodo *a = *pa;

    //Casos base: la lista a está vacía (a == NULL), o llegamos al final de la lista
    //(el sgte de un nodo era NULL, y ese NULL es lo que ahora es "a" en esta llamada recursiva)
	if (a == NULL){
		*pa = b;    //El puntero que apunta al primer nodo de la lista a, ahora es b
		return; //corto la función
	}

    //Caso 1: la lista a no está vacía todavía (a apunta a un nodo real),
    //así que avanzo al siguiente nodo para seguir buscando el final de la lista
	append(&(a->sgte), b);
    //El primer parametro de append es Nodo **pa, es decir, un puntero a puntero, donde debemos usar & para obtener la direccion de memoria de (a->sgte) y asi tenemos un puntero a puntero
    //El segundo parametro de append es Nodo *b, es decir, un puntero, donde usamos directamente b pues este es un puntero
}



// utilidades para el test con el ejemplo del enunciado
Nodo *createNodoL(int x, Nodo *next){
    Nodo *a = (Nodo*) malloc(sizeof(Nodo));
    a->x = x;
    a->sgte = next;
}

Nodo *createNodoList(int *list, int size){
    Nodo *n = malloc(sizeof(Nodo));
    n->x = *list;
    if (size > 1) {
        n->sgte = createNodoList(++list, --size);
    } else {
        n->sgte = NULL;
    }
    return n;
}

void printNodoList(Nodo *nlist, int size){
    if (nlist == NULL)
        return;

    if(size > 1)
        printf("%d -> ", nlist->x);
    else
    printf("%d -> NULL\n\n", nlist->x);

    printNodoList(nlist->sgte, --size);
}



// main que prueba la función append con el ejemplo
// del enunciado
int main(int argvc, char* argv[]){

    printf("===============================================\n\n");

    printf("> a y b listas no vacias\n");
    int l1[] = {3, 1}, l2[] = {7, 8, 4};
    Nodo* a1 = createNodoList(l1, 2);
    Nodo* b1 = createNodoList(l2, 3);

    printf("lista a:\t");
    printNodoList(a1, 2);

    printf("lista b:\t");
    printNodoList(b1, 3);

    printf("append(&a, b):\t");
    append(&a1, b1);
    printNodoList(a1, 5);

    printf("> a una lista vacía y b una lista no vacía\n");
    Nodo* a2 = NULL;
    Nodo* b2 = createNodoList(l2, 3);

    printf("lista a:\t");
    printf("NULL\n\n");

    printf("lista b:\t");
    printNodoList(b2, 3);

    printf("append(&a, b):\t");
    append(&a2, b2);
    printNodoList(a2, 3);

    printf("===============================================\n");

    return 0;
}
