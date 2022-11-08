// Funciones para la pila

#ifndef PILA_FUNCION_H_
#define PILA_FUNCION_H_

void inicializar(Pila *tas) {
    tas->inicio = NULL;
    tas->tamanio = 0;
}

int poner(Pila *tas, char *dato) {
    Elemento *nuevo;
    if ((nuevo = (Elemento *) malloc (sizeof (Elemento))) == NULL)
        return -1;
    if ((nuevo->dato = (char *) malloc (50 * sizeof (char))) == NULL)
        return -1;
    strcpy(nuevo->dato, dato);
    nuevo->siguiente = tas->inicio;
    tas->inicio = nuevo;
    tas->tamanio++;
    return 0;
}

int sacar(Pila *tas) {
    Elemento *eliminar;
    if (tas->tamanio == 0)
        return -1;
    eliminar = tas->inicio;
    tas->inicio = tas->inicio->siguiente;
    free(eliminar->dato);
    free(eliminar);
    tas->tamanio--;
    return 0;
}

int vaciar(Pila *tas) {
    while (tas->tamanio > 0) {
        printf("sacando [%s]... ", tas->inicio->dato);
        sacar(tas);
        printf("Quedan %d elementos.\n", tas->tamanio);
    }
    return 0;
}

int editar(Pila *tas, char *nuevo) {
    printf("Reemplazando [%s] por %s: ", ultimo_dato(tas), nuevo);
    Elemento *editar = tas->inicio;
    strcpy(editar->dato, nuevo);
    tas->inicio = editar;
    printf("Ok.\n");
    mostrar(tas);
    return 0;
}

void mostrar(Pila *tas) {
    Elemento *actual;
    int i;
    actual = tas->inicio;
    printf("La pila tiene %d elementos:\n\n", tas->tamanio);
    printf("*********** TOPE DE LA PILA ***********\n");
    for (i = 0; i<tas->tamanio; i++) {
        printf("\t\t%s\n", actual->dato);
        actual = actual->siguiente;
    }
    printf("___________ FONDO DE LA PILA __________\n\n");
}

#endif
