#include <stdlib.h>
#include <stdio.h>

//Estructura de nodo para la P2
typedef struct nodo{
	int x;
	struct nodo *izq;
  struct nodo *der;
} nodo;



//Función podar que elimina los nodos con un valor mayor a y del árbol (no libera memoria de los nodos eliminados)
void podar(nodo **pa, int y){
	nodo *a = *pa;

	//Caso base: nos encontramos con una hoja del árbol
	if(a == NULL)
		return; //No hacemos nada

	//Caso 1: Si el valor del nodo actual es mayor a 'y', tenemos que podar el nodo actual y su subarbol derecho (pues todos esos nodos son mayores al nodo actual y por ende mayores a 'y')
  //El problema es que en el subarbol izquierdo estan los nodos menores o iguales al nodo actual, pero aun así pueden haber nodos que sean mayores o menores a 'y', por lo cual hay que podar ese subarbol
	if(a->x > y){
		podar(&(a->izq), y);  //Podamos el subarbol izquierdo
		*pa = a->izq; //Ese 'a' es de la llamada donde se detecto a->x > y, despues de podar todo el subarbol izquierdo, ahora el pa debe apuntar a ese subarbol izquierdo podado (antes pa apuntaba al nodo raiz). Así se elimina el nodo actual y el subarbol derecho
	}

  //Caso 2: Si el valor del nodo actual es menor o igual a 'y', tenemos que ocnservar el nodo actual y su subarbol izquierdo (pues todos esos nodos son menores o iguales al nodo actual y por ende menores o iguales a 'y')
  //El problema es que en el subarbol derecho estan los nodos mayores al nodo actual, pero aun así pueden haber nodos que sean mayores o menores a 'y', por lo cual hay que podar ese subarbol 
	else {
    podar(&(a->der), y);
  }
}


//Utilidades para el test con los ejemplos del enunciado
nodo *createnodoT(int x, nodo *left, nodo *right){
  nodo *p = (nodo *) malloc(sizeof(nodo));
  p->x = x;
  p->izq = left;
  p->der = right;
  return p;
}

void printiArbol(nodo *a) {
  if(a == NULL) return;
  printiArbol(a->izq);
  printf("%i ", a->x);
  printiArbol(a->der);
}

void printTree(nodo* root, int space) {
  if (root == NULL) {
    return;
  }

  int count = 5;
  space += count;

  printTree(root->der, space);

  printf("\n");
  for (int i = count; i < space; i++) {
    printf(" ");
  }
  printf("%d\n", root->x);

  printTree(root->izq, space);
}


// main que prueba la función podar con los dos ejemplos
// del enunciado
int main(){
  printf("===============================================\n\n");

  nodo *t = createnodoT(4,
                createnodoT(2,
                    createnodoT(1, NULL, NULL),
                    createnodoT(3, NULL, NULL)),
                createnodoT(6,
                    createnodoT(5, NULL, NULL),
                    NULL));

  printf("Árbol del enunciado \n");
  printTree(t, 0);
  printf("\n\ninorder: ");
  printiArbol(t);

  printf("\n\n");
  printf("podar(&t, 5)\n");
  printf("Árbol depués de podar con y=5\n");
  podar(&t, 5);
  printTree(t, 0);
  printf("\n\ninorder: ");
  printiArbol(t);

  printf("\n\n");
  printf("podar(&t, 2)\n");
  printf("Árbol depués de podar con y=2\n");
  podar(&t, 2);
  printTree(t, 0);
  printf("\n\ninorder: ");
  printiArbol(t);

  printf("\n\n===============================================\n");
  return 0;
}
