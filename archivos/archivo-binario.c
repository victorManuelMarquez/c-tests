#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Estudiante {
    char dni[8];
    char nombre[30];
    char apellido[30];
    int nota;
} Alumno;

Alumno * nuevo_alumno() {
    Alumno *alumno;
    alumno = (Alumno *) malloc(sizeof(Alumno));
    printf("Ingrese el dni: ");
    scanf("%s", &alumno->dni);
    printf("Ingrese el nombre: ");
    scanf("%s", &alumno->nombre);
    printf("Ingrese el apellido: ");
    scanf("%s", &alumno->apellido);
    printf("Ingrese la nota: ");
    scanf("%d", &alumno->nota);
    return alumno;
}

char * calcular_estado(int nota) {
    char *estado = malloc(strlen("REGULAR") * sizeof(char));
    if (nota >= 60)
        estado = "REGULAR";
    else
        estado = "LIBRE";
    return estado;
}

void mostrar(int pos, Alumno a) {
    printf("\n\tALUMNO %d:\n\n", pos);
    printf("DNI:%s\nNOMBRE: %s\nAPELLIDO: %s\nNOTA: %d\n", a.dni, a.nombre, a.apellido, a.nota);
    printf("ESTADO: %s", calcular_estado(a.nota));
    printf("\n****************************\n");
}

void escribir_archivo(char nombre[]) {
    FILE *bin;
    bin = fopen(nombre, "ab");
    if (bin != NULL) {
        char seguir[2] = "no";
        do {
            Alumno *alumno = nuevo_alumno();
            fwrite(alumno, sizeof(Alumno), 1, bin);
            printf("Desea continuar? si | no: ");
            fflush(stdin); fflush(stdin);
            scanf("%s", &seguir);
        } while (strcmp(seguir, "si") == 0);
        fclose(bin);
    } else 
        printf("No EXISTE el archivo %s", nombre);
}

void leer_archivo(char nombre[]) {
    FILE *bin;
    bin = fopen(nombre, "rb");
    if (bin != NULL) {
        Alumno alumno;
        int reg = 0;
        while (fread(&alumno, sizeof(Alumno), 1, bin)) {
            reg++;
            mostrar(reg, alumno);
        }
        fclose(bin);
    } else
        printf("NO EXISTE el archivo %s", nombre);
}

void buscar_alumno(char nombre[]) {
    FILE *bin;
    bin = fopen(nombre, "rb");
    if (bin != NULL) {
        Alumno alumno;
        char valor[30];
        int reg = 0;
        printf("Ingrese el valor a buscar: ");
        fflush(stdin); fflush(stdin);
        scanf("%s", &valor);
        printf("Resultados:");
        while (fread(&alumno, sizeof(Alumno), 1, bin)) {
            reg++;
            if (strcmp(alumno.dni, valor) == 0) {
                mostrar(reg, alumno);
            } else if (strcmp(alumno.nombre, valor) == 0) {
                mostrar(reg, alumno);
            } else if (strcmp(alumno.apellido, valor) == 0) {
                mostrar(reg, alumno);
            } else {
                printf("%s no encontrado!\n", valor);
            }
        }
        fclose(bin);
    } else
        printf("No EXISTE el archivo %s", nombre);
}

int main() {
    char archivo[50] = "alumnos.bin";
    escribir_archivo(archivo);
    leer_archivo(archivo);
    buscar_alumno(archivo);
    return 0;
}
