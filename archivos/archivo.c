#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void leerArchivo(char nombre[]) {
    FILE *archivo;
    char * linea = NULL;
    size_t largo = 0;
    ssize_t leido;
    archivo = fopen(nombre, "r"); // solo lectura (debe existir)
    if (archivo == NULL) {
        printf("El archivo %s no existe!!!", nombre);
    } else {
        while ((leido = getline(&linea, &largo, archivo)) != EOF) {
            printf("[%zu] -> %s\n", leido, linea);
        }
        fclose(archivo); // cierro el archivo
        if (linea)
            free(linea); // libero de la memoria el puntero de la ultima línea
    }
}

void escribirArchivo(char nombre[]) {
    FILE *archivo;
    archivo = fopen(nombre, "r");
    if (archivo == NULL) {
        printf("El fichero %s no existe!!!\nSe creara uno a continuacion...\n", nombre);
    } else {
        printf("%s encontrado, abriendo...\n", nombre);
        fclose(archivo);
    }
    archivo = fopen(nombre, "a"); // crea el archivo si no existe, si existe agrega lo nuevo al final
    printf("Fichero %s abierto para su escritura.\n", nombre);
    printf("Ingrese algun dato para guardar: ");
    char datos[1000];
    fflush(stdin);
    fgets(datos, 1000, stdin);
    fputs(datos, archivo);
    fclose(archivo);
}

void buscar(char nombre[], char palabra[]) {
    FILE *archivo;
    char * linea = NULL;
    size_t largo = 0;
    ssize_t leido;
    int cont = 0;
    archivo = fopen(nombre, "r");
    if (archivo == NULL) {
        printf("El archivo %s no existe!!!", nombre);
    } else {
        while ((leido = getline(&linea, &largo, archivo)) != EOF) {
            if (strcmp(linea, palabra) == 0) {
                cont ++;
            }
        }
        fclose(archivo); // cierro el archivo
        if (linea)
            free(linea); // libero de la memoria el puntero de la ultima línea
    }
    if (cont > 0) {
        printf("se encontro %d veces.", cont);
    } else {
        printf("%s no está en el archivo.", palabra);
    }
}

void borrarArchivo(char nombre[]) {
    if (remove(nombre) == 0)
        printf("Archivo %s borrado correctamente!!!", nombre);
    else
        printf("No se pudo borrar el archivo %s", nombre);
}

int main() {
    FILE *archivo;
    char nombre[] = "mi_archivo.txt";
    printf("Se abrira el siguiente archivo: %s", nombre);
    leerArchivo(nombre);
    escribirArchivo(nombre);
    leerArchivo(nombre);
    buscar(nombre, "hola\n");
    //borrarArchivo(nombre);
    return 0;
}
