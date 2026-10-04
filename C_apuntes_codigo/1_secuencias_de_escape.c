#include <stdio.h>  //Le dice al compilador que incluya el contendio de stdio.h
int main() {
    // \n (salto de línea) 
    printf("Probando el salto de línea");
    printf("\nHola mundo");
    
    // \t (hace el efecto de haber apretado el tab)
    printf("\n Esto es como si hi\tciera un tab");
    
    // \r (devuelve el cursor al inicio de la línea en la que se está escribiendo)
    printf("\nHola cómo\resta"); //Deberia retornar "esta cómo" porque se escribe Hola cómo, se vuelve al inciio de linea y se escribe esta (sobreescribiendo el Hola)
    
    // \b (devuelve el cursor a la posición anterior a donde está el cursor)
    printf("\nChao no quiero i\br"); //Deberia retornar "Chao no quiero r" porque se escribe Chao no quiero i, se vuelve a la posición del i y se escribe r (sobreescribiendo el i)
    
    // \", \',\\ (imprime ", ' y \)  
    printf("\nEsto permite poner las comillas dobles \" tambien las comillas simples \' tambien la barra invertida \\"); 

    return 0; 
}