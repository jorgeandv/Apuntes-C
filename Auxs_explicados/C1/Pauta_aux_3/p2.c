#include <stdio.h>
#include <string.h> // en este header estan las principales funciones para trabajar con strings

int palindromo(char *s);

int main(int argc, char **argv) {
  // ejemplos
  // palindromo("anitalavalatina") = 1
  // palindromo("abcba") = 1
  // palindromo("abc") = 0
  if (argc != 2) {
    printf("uso: %s <palabra>\n", argv[0]);
    printf("ej: %s anitalavalatina\n", argv[0]);
    return -1;
  }

  char *pal = argv[1];
  int ans = palindromo(pal);
  if (ans)
    printf("%s es palindromo\n", pal);
  else
    printf("%s no es palindromo\n", pal);
}

int palindromo(char *s){
  /*
  La idea es usar un puntero inicial y otro final, donde comparemos el valor de ambos punteros con un ciclo hasta que estos se crucen (inicial<final)
  donde 
  *Si en la comparación vemos que sus valores son distintos, entonces el string no es un palindromo, se corta el ciclo y se retorna un 0
  *Si se salió del ciclo es porque no pasó el caso anterior, entonces el string es un palindromo, y se retorna un 1
  */

  //No es necesario crear el puntero inicial, pues podemos usar s como nuestro puntero inicial

  //Creamos el puntero final como el puntero inicial avanzado en el largo del string menos 1 (recordar que strlen() no considera el último char /0)
  char *final = s + strlen(s) - 1; 
  
  while (s < final){ 

    // Si son distintos, no es palíndromo
    if (*s != *final){ 
      return 0;
    }
    else {
      s++; // Avanzamos puntero del inicio
      final--; // Retrocedemos puntero del final
    }
  }
  //Si llegamos hasta acá, es palíndromo
  return 1;
}