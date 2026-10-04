#include <stdio.h>
#include <string.h>

void to_lower(char *s);
void to_upper(char *s);

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("uso: %s <palabra>\n", argv[0]);
    printf("ej: %s 'Hola Mundo!'\n", argv[0]);
    return -1;
  }
  char *test = argv[1];
  to_lower(test);
  printf("to lower: %s\n", test);
  to_upper(test);
  printf("to upper: %s\n", test);
}


//Transforma el string 's' a minúsculas
void to_lower(char *s){
  //Se itera hasta que termine el string (se encuentra el '\0')
  while (*s != '\0'){  
    /*
    Sabemos que cada char en el string, C lo interpreta según ASCII y le asigna un número
    Hay que notar que las letras mayusculas están entre 65 y 90 (incluidos)
    Además, para pasar de una letra mayuscula a una minuscula, basta con sumarle 32 a la letra mayuscula
    */ 
    
    //Si la letra es mayuscula
    if (*s >= 65 && *s <= 90){ 
      //Le sumamos 32
      *s += 32; 
      //Avanzamos el puntero al siguiente char
      s++;
    }

    //Si la letra es minuscula
    else {
      //Avanzamos el puntero al siguiente char
      s++;
    }
  }
}


//Transforma el string 's' a mayusculas
void to_upper(char *s){
  //Se itera hasta que termine el string (se encuentra el '\0')
  while (*s != '\0'){  
    /*
    Sabemos que cada char en el string, C lo interpreta según ASCII y le asigna un número
    Hay que notar que las letras minusculas están entre 97 y 122 (incluidos)
    Además, para pasar de una letra minuscula a una mayuscula, basta con restarle 32 a la letra minuscula
    */ 

    //Si la letra es minuscula
    if (*s >= 97 && *s <= 122){ 
      //Le restamos 32
      *s -= 32;
      //Avanzamos el puntero al siguiente char
      s++;
    }
    //Si la letra es mayuscula
    else {
      //Avanzamos el puntero al siguiente char
      s++;
    }
  }
}
