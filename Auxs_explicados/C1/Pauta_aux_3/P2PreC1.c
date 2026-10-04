void elim_str(char *str, char *pat) {
    //Punteros escritores
    char *escritorSTR=str;
    //Podriamos usar directamente str pero es buena práctica definir un puntero lector
    char *lectorSTR = str;

    while (*lectorSTR != '\0') {
        char *lectorPAT = pat;
        char  *exploradorSTR  = lectorSTR; 

        while (*lectorPAT != '\0' && *exploradorSTR == *lectorPAT) {
            exploradorSTR++;
            lectorPAT++;
            }
        //Si en algún momento los caracteres no coinciden, el lectorPAT queda apuntando en el caracter donde el patrón falló

        //Si donde el patrón falló es el final del patrón, es decir, coincidió todo el patrón
        if (*lectorPAT=='\0') {
            //El puntero lectorSTR ahora está donde el puntero exploradorSTR el cual ya pasó el patrón, así en un futuro cuando se sobreescriba usando lectorSTR se sobreescribirá el patrón
            lectorSTR = exploradorSTR;

        }
        //Si donde el patrón falló no es el final del patrón, es decir, no coincidió todo el patrón
        else {
            //Con el puntero escritorSTR se sobreescribe usando los caracteres del puntero lectorSTR
            *escritorSTR = *lectorSTR;
            escritorSTR++;
            lectorSTR++;
        }
    }
    *escritorSTR= '\0';
}