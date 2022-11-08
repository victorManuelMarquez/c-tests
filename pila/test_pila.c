 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "pila.h"
 #include "pila_funcion.h"

int main() {
    Pila *tas;
    char *dato;
    if ((tas = (Pila *) malloc (sizeof (Pila))) == NULL)
        return -1;
    if ((dato = (char *) malloc (50 * sizeof (char))) == NULL)
        return -1;
    inicializar(tas);
    for (int i=0; i<3; i++) {
        printf("Ingrese un dato: ");
        scanf("%s", dato);
        poner(tas, dato);
        mostrar(tas);
    }
    printf("Pila completa:\n");
    mostrar(tas);

    // edito un valor
    printf("Ingrese un nuevo valor: ");
    scanf("%s", dato);
    editar(tas, dato);

    printf("La ultima entrada [%s] será eliminada.\n", ultimo_dato(tas));
    sacar(tas);
    mostrar(tas);
    printf("Listo!!!\n");

    // vacio la pila completamente
    vaciar(tas);
    
    // libero de la memoria a la pila
    free(tas);
    return 0;
}
