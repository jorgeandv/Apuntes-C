#include <stdio.h>

//Recordar que el * que se usa al definir los punteros es solo sintaxis, lo que estamos haciendo es p=&algo
/*
Dado el siguiente código
int a[6] = {5, 10, 15, 20, 25, 30};
int *p = a;
int *q = &a[4];

¿Cuánto vale *p? tenemos que se define int *p=a que es lo mismo que int *p=&a[0]. Así *p es 5 (es el valor del puntero)
¿Cuánto vale p[2]? 15
¿Cuánto vale *(p + 3)? p avanza 3 posiciones, donde p=&a[0], asi queda p=&a[3] y luego a eso le calculo el valor (*), lo que da 20 (esto es lo mismo que p[3])
¿Cuánto vale q - p? posición a la que apunta q - posición a la que apunta p = 4-0 = 4
¿Cuánto vale *q? 25
¿Es válida la expresión q * 2? ¿Por qué? No, las operaciones aritmeticas de punteros son solo + entero o - entero. Ej: q+1 o q-2
*/

/*
int a[5] = {1, 2, 3, 4, 5};
int *p = a;     //int *p=a es lo mismo que int *p=&a[0]

int x = *p++;      // En x se guarda  el valor de *p (*p) y luego se avanza p en uno (p++), asi x=1
int y = *++p;       // Considerando lo que pasó antes, se avanza p en uno (p++) y luego en y se guarda el valor de *p (*p), así y=3
int z = *p;          // Considerando lo que pasó antes, en z se guarda *p, así z=3
*/

/* Ejemplo de arreglo con punteros.
int arreglo[3]={1,2,3};
int *puntero=&arreglo[0];   //puntero[0] es lo mismo que arreglo[0], ...
*/


//Si a la función invertir le damos el arreglo b, el parámetro puntero p queda p=&b[0] 
//la idea es usar dos punteros uno al inicio y otro al final, y una variable temporal que guarde el valor mientras se hace el intercambio de valores
void invertir(int *p, int n) {   //La función invertir recibe un arreglo de ints  y una variable n de tipo int 
    int *pi=&p[0];  //defino el puntero inicio que guarda la dirección de memoria del inicio del arreglo (recordar que p[0] es un valor y &p[0] una dirección, p es un puntero)
    int *pf=&p[n-1];    //defino el puntero fin que guarda la dirección de memoria del final del arreglo
    int temporal;
    while (pi<pf) { //Como pi y pf son direcciones de memoria, compararlas es lo mismo que comparar la posicion en el arreglo
    temporal=*pf;
    *pf=*pi;
    *pi=temporal;
    pi++;
    pf--;
    }

}

/* 
Por notación podriamos haber usado 
void invertir(int *p, int tam) {
    int *pi = p;
    int *pf = p + tam - 1;   // apunta al último elemento
Esto funciona porque:
p[i]  es equivalente a  *(p + i)
&p[i] es equivalente a  p + i
*/


/*
Habia usado
    temporal=*pf;
    *pi=temporal;
    *pf=*pi;
Pero esto no da el resutlado correcto porque cuando *pi se conveirte en el valor de temporal (*pf) y luego *pf toma el valor de *pi, este ultimo
*pi es al que ya le cambiamos el valor (*pi=temporal) asi que *pf no recibe el *pi original. El problema era el orden de las líneas de código.
*/