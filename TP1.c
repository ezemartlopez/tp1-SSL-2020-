#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define a 10
#define b 11
#define c 12
#define d 13
#define e 14
#define f 15
#define x 16
#define X 16

void abrirArchivo(FILE**, FILE**);

int main() {
    FILE* lectura;
    FILE* escritura;

    abrirArchivo(&lectura, &escritura);

    fclose(lectura);
    fclose(escritura);

    return 0;
}

void abrirArchivo(FILE** lectura, FILE** escritura) {
    char archivo[50];
    char archivoEscritura[62];

    printf("Ingrese el nombre del archivo a analizar\n>");

    scanf("%s", archivo);

    strcpy(archivoEscritura, archivo);
    strcat(archivo, ".txt");

    *lectura = fopen(archivo, "r");

    while(*lectura == NULL) {
        printf("\n\nSe produjo un error. Vuelva a introducir el nombre. Recuerde que no debe incluir el formato.\n>");

        scanf("%s", archivo);

        strcpy(archivoEscritura, archivo);
        strcat(archivo, ".txt");

        *lectura = fopen(archivo, "r");
    }

    strcat(archivoEscritura, "_resultado.txt");
    *escritura = fopen(archivoEscritura, "w");
}

//char automata (int palabra[], int tamanio) {
//    int estado;
//    bool reconocido = false ;
//    char octa[] = "octal";
//    char deci[] = "decimal";
//    char hexa[] = "hexadecimal";
//    char error[] = "no reconocido";
//    
//    if(palabra[0] == 0 && palabra[1] != 16)  {
//        for(int i=1;i<tamanio;i++){
//            if(palabra[i] <= 7 && palabra[i] >= 0) {
//                reconocido = true 
//            }
//            else {
//                return error;
//            }
//        }
//        if (reconocido){
//            return octa;
//        }
//    }
//    else if(palabra[0] == 0 && palabra[1] == 16) {
//        for(int j=2;j<tamanio;j++){
//            if(palabra[i] <= 9 && palabra[i] >= 0) {
//                palabra = true 
//            }
//            else {
//                return error;
//            }
//        }
//        if(reconocido){
//            return deci;
//        }
//    }
//    else if(palabra[0] <= 9 && palabra[0] != 0) {
//        for(int k=1;k<tamanio;k++){
//            if(palabra[i] <= 15 && palabra[i] >= 0) {
//                reconocido = true 
//            }
//            else {
//                return error;
//            }
//        }
//        if(reconocido){
//            return hexa;
//        }
//    }
//    else {
//        return error;
//    }
//
//}
