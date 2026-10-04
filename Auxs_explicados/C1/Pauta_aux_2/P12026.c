typedef unsigned int uint32_t;
uint32_t mix(uint32_t a, uint32_t b, int k) {
    int pos = 0;
    uint32_t resultado = 0;

    //Mascara con 1's en los ultimos k bits y 0´s en el resto
    uint32_t m = -1U;
    uint32_t mask = ~(m<<k);  

    //El ciclo se ejecuta mientras pos + k no pase 32, es decir, aun queden elementos por analizar 
    while (pos + k <= 32) {
        uint32_t cifraA = (a >> pos) & mask;
        uint32_t cifraB = (b >> pos) & mask;

        //Promedio con división entera, sin usar '/'
        //(cifraA+cifraB)/2 == (cifraA>>1) + (cifraB>>1) + (1 si ambos son impares)
        uint32_t cifraResultado = (cifraA >> 1) + (cifraB >> 1) + (cifraA & cifraB & 1);

        //Guardar el promedio en su posición
        resultado = resultado | (cifraResultado << pos);

        pos = pos + k;           //pasar al siguiente elemento
    }

    return resultado;
}



//El promediar cada cifra puede ser de derecha a izquierda o de izquierda derecha y da el mismo resultado


