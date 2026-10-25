#include "stdio.h"
#include "string.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Recordar que es importante saber dónde está el cursor del archivo, pues sobre esa posición es donde se aplican las funciones
void modificar(char *nom_dic, char *palabra, char *def, int n_lin, int ancho) {
    //Se abre el archivo en modo lectura y escritura
    FILE *f = fopen(nom_dic, "r+");

    /*
	Se usa un arreglo auxiliar que lo llamamos buf (de buffer) en el cual guardaremos la línea que leeremos, por esto
	el tamaño es ancho+1, donde el +1 es para considerar el '\0' pues este no se guarda cuando usamos fread
	*/
    char buf[ancho+1];

    //Mientras aún hayan líneas en el archivo
    while (n_lin > 0) {
        /*
		1) Calcula cuántos bytes en total se quieren leer, 1*ancho. Recordar que cada char es 1 byte, por eso se usa tamaño=1
		2) Toma esos bytes del buffer de f (toma toda la línea, pues ancho es el ancho de la línea)
		3) Copia los bytes a buf, sin agregar '\0'
		4) Avanza el cursor del archivo en la cantidad de bytes leídos (queda al inicio de la siguiente línea)
		5) Retorna la cantidad de elementos completos que logró leer si todo salió bien o retorna menos que cantidad si es que se llegó al final del archivo o hubo un 
		error (no nos interesa)
		
		Así cada vez que se llamna fread se mete una línea entera del diccionario al arreglo buf
		*/
		fread(buf, 1, ancho, f);   
        n_lin--;	//Disminuyo en 1 el número de líneas

        char *c = buf;             //Puntero auxiliar para recorrer la línea que está en el arreglo buf
        
		//Mientras aún no encuentro el primer :
		while (*c != ':') {        
            c++;	//Avanzo en 1 el puntero c
        }

		/*Cuando salgo del while anterior es porque encontré el primer ':', y c quedó apuntando a ese ':'. Ahí escribo '\0' para que buf ahora
		sea un string que tiene la palabra de la línea que se guardó
        */
		*c = '\0';              

        /*
		Como en el buf ya tenemos la palabra de la línea que se guardó, ahora podemos comparar esa palabra con la que se pasó como argumento 
		para ver si estamos en la línea donde nos interesa cambiar la def
		*/
        if (strcmp(palabra, buf) == 0) {
			/*
			Al hacer fread, el cursor del archivo quedó al inicio de la siguiente línea, pero como queremos modificar la def debemos mover el cursor al inicio de la def,
			es decir, hay que retroceder el cursor -(ancho-strlen(palabra))+1, donde (ancho-strlen(palabra)) es el ancho de la def y +1 porque sino qeudamos parados en el primer ':'
			*/
            fseek(f, -ancho + strlen(palabra) + 1, SEEK_CUR);
			//Ponemos la nueva def en f
            fputs(def, f);       

			/*
			El problema es que ahora aun queda parter de la def antigua (lo que no se sobreescribió con la def nueva), asi que esos caracteres hay que dejarlos en blanco (con ' ') 
			¿Hasta cuando? Hasta que encontremos el segundo ':'
			Para esto usamos un while usando fgetc para identificar cuando encontremos el segundo ':'
			*/
            while (fgetc(f) != ':') {
				//El fgetc avnazó el cursor en uno, así que debo volver a retroceder el cursor para poder sobrescribir correctamente 
                fseek(f, -1, SEEK_CUR);   
				//Ponemos el ' ' en f
                fputc(' ', f);            
            }
			//Cuando salgo del while anterior es porque ya hice todo, así que corto con un break 
            break;                 
        }
    }
	//Aseguramos de terminar el programa y enviar todo al archivo en disco
    fclose(f);
}


int main() {
    // ejemplo de uso: modificar la definición de tranquilo en el archivo dict.txt
    modificar("dict.txt", "tranquilo", "contrario a inquieto", 10, 48);
    return 0;
}
