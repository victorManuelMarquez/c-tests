#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cola.h"
#include "cola_funcion.h"

int main() {
    Cola *fila;
    char *dato;
    if ((fila = (Cola *) malloc (sizeof (Cola))) == NULL)
        return -1;
    if ((dato = (char *) malloc (50 * sizeof (char))) == NULL)
        return -1;
    inicializar(fila);
    for (int i=0; i<3; i++) {
        printf("Ingrese un valor: ");
        scanf("%s", dato);
        poner(fila, dato);
        mostrar(fila);
    }
    printf("Nuevo valor para el primer elemento: ");
    scanf("%s",dato);
    editar(fila, dato);
    vaciar(fila);
    free(fila);
    return 0;
}
