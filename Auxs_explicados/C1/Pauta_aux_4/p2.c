#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct nodo {
    char *str;
    struct nodo *sgte;
} Nodo;

typedef struct cola {
    Nodo *primero;
    Nodo *ultimo;
} Cola;



Cola *crearCola(void) {
    Cola *q = malloc(sizeof(Cola));
    q->primero = NULL;
    q->ultimo = NULL;
    return q;
}

//Tiempo de ejecucion O(1) es que no hayan ciclos

void put(Cola *q, char *str) {
    Nodo *nuevo = malloc(sizeof(Nodo)); //El puntero nuevo apunta un Nodo que esta en la memoria que reervamos con malloc()
    nuevo->str = malloc(strlen(str) + 1); //Accedo al campo str de nuevo que esta en la memoria que reservamos con malloc()
    strcpy(nuevo->str, str); //Copiamos en el campo str de nuevo el stirng str que recibe la funcion
    
    nuevo->sgte = NULL; //Como nuevo apunta al Nodo que queremos meter a la cola, este se metera como ultimo, entonces su sgte debe ser NULL
    
    //Caso base: La cola esta vacia
    if (q->primero == NULL) { //eso igual se puede hacer con q->ultimo
        q->primero = nuevo;
        q->ultimo = nuevo;
    }

    //Caso 1: La cola no esta vacia
    else {
        q->ultimo->sgte = nuevo; //El campo sgte del ultimo nodo de la cola ahora apunta a nuevo que a su vez apunta al Nodo que metimos (Esto afecta al ultimo nodo)
        q->ultimo = nuevo; //El ultimo nodo de la cola ahora es el nuevo que a su vez apunta al Nodo que metimos (Esto afecta a la estructura)
    }
}



char *get(Cola *q) {
    //Caso base: La cola esta vacia    
    if (q->primero == NULL) {
        return NULL;    //Se retorna NULL (esto igual se considera como puntero asi que no hay problema con la def de la funcion)
    }

    //Caso 1: La cola no esta vacia
    Nodo *first = q->primero; //Guardo una copia, el puntero first apunta al primer nodo de la cola
    char *str = first->str;  //Guardo una copia, el puntero str apunta al str del primer nodo de la cola
    q->primero = first->sgte; //El primer nodo de la cola ahora es el sgte nodo de lo que antes era el primer nodo original (pues quitamos el primer nodo original)

    //Caso 1.1: La cola solo tenia un nodo, al sacar el nodo quedo la cola vacia
    if (q->primero == NULL) {
        q->ultimo = NULL;  //El ultimo nodo de la cola ahora es NULL (como la cola tenia un nodo, primero y ultimo apuntaban a ese nodo, primero quedo NULL cuando saque el nodo, pero faltaba ultimo)
    }

    free(first);    //Libero la memoria donde estaba el nodo que saque
    /*
    Por que se usa free si no tenemos malloc()?
    Porque cuando agregamos un nodo usamos malloc() (en la def del put), es decir, el nodo que vamos a sacar en algun momento se agrego con malloc(), por eso
    cuando lo sacamos debemos liberar ese malloc()
    */
    return str;     //Se retorna el puntero str (que apunta al strdel primer nodo de la cola)
}



void freeCola(Cola *q) {
    Nodo *actual = q->primero;  //Guardo una copia, el puntero actual aputa al primer nodo de la cola
    while (actual != NULL) { //Se ejecuta mientras actual no sea NULL
        Nodo *sgte = actual->sgte; //Guardo una copia, el puntero sgte apunta al sgte del nodo al que apunta actual
        free(actual->str);  //Libero el str del nodo al que apunta actual
        free(actual);   //Libero el nodo al que apunta actual
        actual = sgte;  //actual ahora es el puntero sgte
    }
    free(q); //Libero la cola
}



void printCola(Cola *q) {
    Nodo *actual = q->primero;

    while (actual != NULL) {
        printf("%s ", actual->str);
        actual = actual->sgte;
    }
    printf("\n");
}



int main(){
	Cola *queue = crearCola();
    printf("Cola creada !!\n");
    put(queue, "Primero");
    printf("Hemos ingresado un valor a la cola\n");
    printCola(queue);
	printf("\n");
	put(queue, "Segundo");
    put(queue, "Tercero");
    put(queue, "Cuarto");
	printf("Ingresamos varios valores y la cola ahora es:\n");
    printCola(queue);
	printf("\n");
    printf("Comenzando extracción total !\n");
    int n = 4;
    while (n != 0){
        printf("Valor extraído: %s\n", get(queue));
        n--;
    }
    printf("La cola ahora es:\n");
    printCola(queue);
    printf("Volvemos a llenar la cola\n");
    put(queue, "Primero");
    put(queue, "Segundo");
    put(queue, "Tercero");
    put(queue, "Cuarto");
    printf("La cola ahora es:\n");
    printCola(queue);
	freeCola(queue);
    printf("Cola liberadaa\n");
    printf("La cola ahora es:\n");
    printCola(queue); // Entrega SEGFAULT
}