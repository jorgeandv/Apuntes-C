#include <stdlib.h>
#include <stdio.h> 


//Estructura de nodo para la P3
typedef struct nodo{
	char x; 
	struct nodo *izq;
  struct nodo *der;
} nodo;


//Función reemplazarNodoK que reemplaza el k-ésimo nodo en un recorrido
//inorden y retorna k si se hizo el reemplazo o la cantidad de nodos
//encontrados en caso contrario
int reemplazarNodoK(nodo **pa, int k, nodo *b){
	nodo *a = *pa;
	
	//Caso base: El arbol es vacío
	if(a == NULL)
		return 0;

  //Como se recorre en inorden, hay que usar reemplazarNodoK en izq, nodo, der

	//Guaradamos en la variable izq, la llamada reemplazarNodoK en el subarbol izquierdo
	int izq	= reemplazarNodoK(&(a->izq), k, b);
  /*
  Acá tenemos 3 casos
  * El reemplazo se hizo en el subarbol izquierdo
  * No se hizo el reemplazo en el subarbol izquierdo y el nodo actual es el nodo k
  * No se hizo el reemplazo en el subarbol izquierdo
  */

    //Caso 1: El reemplazo se hizo en el subarbol izquierdo
  //Como se hizo el reemplazo, izq es k
	if(izq == k){
		return k;   //Retornamos k, pues ya se hizo el reemplazo
	}

  //Caso 2: No se hizo el reemplazo en el subarbol izquierdo y el nodo actual es el nodo k
  //Como no se hizo el reemplazo, izq es la cantidad de nodos del subarbol izquierdo
  //Si esa cantidad+1 es k, signfica que el nodo actual es el nodo k
	else if(izq + 1 == k){
		*pa = b; // reemplazamos el k-ésimo nodo por b
		return k; // retornamos k, pues hicimos el reemplazo
	}
	
  //Caso 3: No se hizo el reemplazo en el subarbol izquierdo
  else {
    //Seguimos con el inorden, usamos reemplazarNodoK() en el subarbol derecho
    //Tenemos que usar un k' pues como ya analizamos el subarbol izquierdo y el nodo actual, en la llamada del subarbol derecho 
    //no debemos considerar el k completo, le debemos quitar los nodos que ya analizamos (izq+1) donde como no se reemplazo en el subarbol izquierdo,
    //izq es la cantidad de nodos del subarbol izquierdo.
    int der = reemplazarNodoK(&a->der, k - (izq + 1), b);

    /*
    Acá tenemos 2 casos
    * El reemplazo se hizo en el subarbol derecho
    * No se hizo el reemplazo en el subarbol derecho
    
    En ambos casos se retorna izq + der + 1 pues
   * Si caemos en el Caso 1, der es la cantidad de nodos del subarbol derecho, así izq+der+1 es la cantidad de nodos del arbol
   * Si caemos en el Caso 1, der es el nodo k´ donde reemplazamos, así izq+der+1 es el nodo k
	 */ 
    return izq + der + 1;    
  }
}



// utilidades para el test con el ejemplo del enunciado
nodo *createnodoT(char x, nodo *left, nodo *right){
  nodo *p = (nodo*) malloc(sizeof(nodo));
  p->x = (char) x;
  p->izq = left;
  p->der = right;
  return p;
}

void printcArbol(nodo *a) {
  if(a == NULL) return;
  printcArbol(a->izq);
  printf("%c ", (char) a->x);
  printcArbol(a->der);
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
  printf("%c\n", root->x);

  printTree(root->izq, space);
}

int main(){

  printf("===============================================\n\n");

  nodo *t1 = createnodoT('s',
      createnodoT('r', NULL, NULL),
      createnodoT('u',
        createnodoT('t', NULL, NULL),
        NULL));

  nodo *t2 = createnodoT('s',
      createnodoT('r', NULL, NULL),
      createnodoT('u',
        createnodoT('t', NULL, NULL),
        NULL));

  nodo *b = createnodoT('v', NULL, createnodoT('w', NULL, NULL));

  printf("Árbol a del enunciado \n");
  printTree(t1, 0);
  printf("\n\ninorder: ");
  printcArbol(t1);
  printf("\n\n");

  printf("Árbol b del enunciado \n");
  printTree(b, 0);
  printf("\n\ninorder: ");
  printcArbol(b);

  printf("\n\nreemplazarNodoK(&t, 4, b) = %d\n", reemplazarNodoK(&t1, 4, b));
  printTree(t1, 0);
  printf("\n\ninorder: ");
  printcArbol(t1);

  printf("\n\nreemplazarNodoK(&t, 2, b) = %d\n", reemplazarNodoK(&t2, 2, b));
  printTree(t2, 0);
  printf("\n\ninorder: ");
  printcArbol(t2);

  printf("\n\n===============================================\n");

  return 0;
}
