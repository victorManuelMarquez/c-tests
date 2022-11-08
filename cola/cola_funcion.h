#ifndef COLA_FUNCION_H_
#define COLA_FUNCION_H_

void inicializar(Cola *fila) {
    fila->inicio = NULL;
    fila->tamanio = 0;
}

int poner(Cola *fila, char *dato) {
    Elemento *nuevo;
    if ((nuevo = (Elemento *) malloc (sizeof (Elemento))) == NULL)
        return -1;
    if ((nuevo->dato = (char *) malloc (50 * sizeof (char))) == NULL)
        return -1;
    strcpy(nuevo->dato, dato);
    if (fila->inicio == NULL) {
        nuevo->siguiente = NULL;
        fila->inicio = nuevo;
    } else {
        Elemento *actual = fila->inicio->siguiente;
        if (actual == NULL) {
            fila->inicio->siguiente = nuevo;
        } else {
            actual->siguiente = nuevo;
        }
    }
    fila->tamanio++;
    return 0;
}

int sacar(Cola *fila) {
    Elemento *quitar;
    if (fila->tamanio == 0)
        return -1;
    quitar = fila->inicio;
    fila->inicio = quitar->siguiente;
    printf("Eliminando a [%s] de la fila... ", quitar->dato);
    free(quitar->dato);
    free(quitar);
    fila->tamanio--;
    printf("Ok.\n");
    return 0;
}

int vaciar(Cola *fila) {
    while (fila->tamanio != 0) {
        sacar(fila);
    }
    printf("Fila con %d elementos.\n", fila->tamanio);
    return 0;
}

int editar(Cola *fila, char *nuevo) {
    printf("Reemplazando [%s] por [%s]... ", primer_dato(fila), nuevo);
    Elemento *editar = fila->inicio;
    strcpy(editar->dato, nuevo);
    fila->inicio = editar;
    printf("Ok.\n");
    mostrar(fila);
    return 0;
}

void mostrar(Cola *fila) {
    Elemento *nodo = fila->inicio;
    while (nodo != NULL) {
        printf("%s | ", nodo->dato);
        nodo = nodo->siguiente;
    }
    printf("\n");
}

#endif
