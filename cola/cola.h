#ifndef COLA_H_
#define COLA_H_

typedef struct Nodo {
    char *dato;
    struct Nodo *siguiente;
} Elemento;

typedef struct Lista {
    Elemento *inicio;
    int tamanio;
} Cola;

void inicializar(Cola *fila);

int poner(Cola *fila, char *dato);

int sacar(Cola *fila);

int vaciar(Cola *fila);

int editar(Cola *fila, char *nuevo);

#define primer_dato(fila) fila->inicio->dato

void mostrar(Cola *fila);

#endif
