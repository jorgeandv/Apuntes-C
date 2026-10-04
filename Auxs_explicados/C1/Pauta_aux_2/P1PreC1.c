typedef unsigned long long uint64;

uint64 suma (uint64 x) {
        
    uint64 resultado = 0;

    //L0
    uint64 L = x&0xF;

    //L van a ser los L's, cuando este sea 0 es porque ya no quedan N's
    while (L != 0) {
        /*
        La mascara tiene 1's en los ultimos L bits
        Ej:En la primer iteración, la mascara tiene 1's en los ultimos 2 bits (0010 en entero es un 2)
        */
        unsigned m=-1;
        int mask = ~(m<<L);

        /*
        Desplazo a la derecha en 4 el x para que al último queden los bits de N y no de L
        Ej:En la primer iteración, x queda = 0000 0000100110101110001101
        */
        x= x>>4;

        /*
        Aplico la mascara al x desplazado, así solo sobreviven los bits que representan al N
        Ej:En la primer iteración, N=01
        */
        uint64 N = x&mask;
    
        //Sumo el N al resultado
        resultado+=N;

        /*
        Desplazo a la derecha en L el x para que al último queden los bits de L y no de N
        Ej:En la primer iteración, x queda = 00 0000 00001001101011100011
        */        
        x = x>>L;

        /*
        Actualizo el L
        Ej:En la primer iteración, L es 0011
        */    
        L = x&0xF; 
    }
    //Retorno el resultado de la suma de los N
    return resultado;  
}


//La mascara debe tener la cantidad de 1's que me permitan leer el dígito N
//Ej: En la primera iteración, la mascara debe tener 2 1's