#include <stdio.h>
#include <string.h>

void reverse(char *s);

int main(int argc, char **argv) {
  // ejemplos
  // reverse("anitalavalatina") = "anitalavalatina"
  // reverse("abcba") = "abcba"
  // reverse("Hola mundo!") = "!odnum aloH"
  // reverse("a") = "a"
  if (argc != 2) {
    printf("uso: %s <palabra>\n", argv[0]);
    printf("ej: %s abcba\n", argv[0]);
    return -1;
  }
  char *pal = argv[1];
  printf("%s al reves es ", pal);
  reverse(pal);
  printf("%s\n", pal);
}

void reverse(char *s) {
  /*
  La idea es usar un puntero inicial, un puntero final, y una variable temporal.
  Donde en la variable temporal guardamos el valro del puntero inicial, luego sobreescribimos el valor del puntero inicial por el valor del puntero final,
  y luego sobreeescribimos el valor del puntero final por el valor de la variable temporal+

  Todo lo anterior en un ciclo hasta que los punteros inicial y final se crucen

  El por qué de la variable temporal está explicado en el bloc.
  */

  //No es necesario crear el puntero inicial, pues podemos usar s como nuestro puntero inicial

  //Creamos el puntero final como el puntero inicial avanzado en el largo del string menos 1 (recordar que strlen() no considera el último char /0)
  char *final = s + strlen(s) - 1; 

  while (s < final) { 
    char temp = *s; // guardamos el caracter del principio
    *s = *final;    // ponemos el caracter del final en el principio
    *final = temp;  // ponemos el caracter del principio en el final
    //Avanzamos el puntero inicial
    s++;
    //Retrocedemos el puntero final
    final--;
  }
}