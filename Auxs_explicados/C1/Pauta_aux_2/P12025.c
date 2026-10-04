typedef unsigned long long Decimal;
typedef unsigned long long int ullong;

ullong decimal2int(Decimal x) {
    //Inicia en 0
    ullong resultado = 0;
    //El ciclo es desde 60 restando 4
    for (int i = 60; i >= 0; i -= 4) {
        ullong digito = (x >> i) & 0xF;     //Se calcula cada dígito, desplanzado x según i y obtieniendo sus 4 bits menos significativos
        resultado = (resultado << 3) + (resultado << 1) + digito; // resultado*10 + digito, como al inicio resultado=0, cumple para todos los casos
    }
    return resultado;   //Se retorna el resultado
}

