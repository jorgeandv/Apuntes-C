void invertirVocales(char *str) {
    char *izq = str;

    // Puntero derecho: lo llevamos hasta el final del string
    char *der = str;
    while (*der != '\0') {
        der++;
    }
    der--; // retrocedemos uno, porque el while nos dejó parados en el '\0'

    while (izq < der) {
        // Avanzamos 'izq' hasta encontrar una vocal (o cruzarse con 'der')
        while (izq < der && *izq != 'a' && *izq != 'e' && *izq != 'i' && *izq != 'o' && *izq != 'u') {
            izq++;
        }

        // Retrocedemos 'der' hasta encontrar una vocal (o cruzarse con 'izq')
        while (izq < der && *der != 'a' && *der != 'e' && *der != 'i' && *der != 'o' && *der != 'u') {
            der--;
        }

        // Si ambos apuntan a vocales, las intercambiamos
        if (izq < der) {
            char temp = *izq;
            *izq = *der;
            *der = temp;
            izq++;
            der--;
        }
    }
}