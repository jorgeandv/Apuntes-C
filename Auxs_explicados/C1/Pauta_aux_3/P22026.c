//char s3[7] = "13999" es s3 = ['1', '3', '9', '9', '9', '\0']

/*
Hay que notar que 
*'0'-48 es 0 que en int es 0
*'1'-48 es 1 que en int es 1
*..., así con todos

Además, 
*0+48 es 48 que en char es 0
*1+48 es 49 que en char es 1
*..., así con todos
*/

/*
La idea es hacer la suma a mano, considerando el carry (acarreo) que hacemops cuando sumamos 9+1 que ponemos un 1 arriba del siguiente dígito.
Recordar que esto es de derecha a izquierda
*/
void decInc(char *num) {
    //Largo del string
    int len = strlen(num);
    //Puntero que apunta inicialmente al último dígito (de derecha a izquierda)
    char *p = num + len - 1;  
    //Carry que inicialmente es 1
    int carry = 1;            

    //Recorremos de derecha a izquierda, sumando el carry mientras exista
    while (p >= num && carry != 0) {
        //Pasamos a int el dígito que leemos y le sumamos el carry para ver si ese digitoConCarry es 10 (necesitamos poner el carry en el siguiente digito) o no es 10
        int digitoConCarry = *p - 48 + carry;

        if (digitoConCarry == 10) {
            //El dígito que leemos ahora es 0
            *p = '0';
            //Carry es 1
            carry = 1;
            //Avanzamos al siguiente dígito a leer (de derecha a izquierda)
            p--;
        } 
        else {
            //Pasamos a char (pues p es puntero a char) el digito que leemos sumado al carry
            *p = digitoConCarry + 48;
            //Carry es 0
            carry = 0;
            //Avanzamos al siguiente dígito a leer (de derecha a izquierda)
            p--;
        }

    }

    // Si después de procesar todo el string sigue habiendo carry,
    //significa que el número creció un dígito, este es el caso de todo es 9 (ej: "999" -> "1000")
    if (carry != 0) {
        char *origenCopia = num + len;      // apunta al '\0' actual
        char *destinoCopia = num + len + 1;  // nueva posición del '\0'

        // Corremos todo (incluyendo el '\0') una posición a la derecha
        while (origenCopia >= num) {
            *destinoCopia = *origenCopia;
            destinoCopia--;
            origenCopia--;
        }
        //num quedó vacio pues corrimos todo uno a la derecha, y en esa posición vacía debe ir el 1
        *num = '1'; 
    }
}
