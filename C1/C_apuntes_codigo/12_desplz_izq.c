#include <stdio.h>
//

unsigned int empaquetar(unsigned char r, unsigned char g, unsigned char b, unsigned char a){
    /*
    unsigned int x= (r<<= 8);
    r<<=8 es lo mismo que r= r<<8 donde el r de la derecha se le hace un cast implicito a int pero al guardar todo en el r de la izquierda,
    todo se convierte a char pues el r de la izquierda es unsigned char, luego al guardar todo eso en el x, se guarda en un int, pues el x
    es unsigned int.
    
    La solución a lo anterior es no usar <<= sino usar <<  porque el << no reasigna el valro de una variable 
    */ 
    //Como r,g,b,a nunca serán signed, al hacer ejemplo r<<8 se hace un cast implicito a int pero es mas optimo hacerle un cast explicito a unsigned int
    unsigned int x = (unsigned int)r<<8;
    unsigned int y= x|g;
    unsigned int z= (unsigned int)y<<8;
    unsigned int v= z|b;
    unsigned int n= (unsigned int)v<<8;
    unsigned int m= n|a;
    return m;

}

int main() {
    unsigned char r = 255;  // rojo
    unsigned char g = 128;  // verde
    unsigned char b = 64;   // azul
    unsigned char a = 255;  // alpha (transparencia)
    printf("%08X", empaquetar(r,g,b,a));
    return 0;
}