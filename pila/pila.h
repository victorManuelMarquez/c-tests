// Cuerpo de la pila

#ifndef PILA_H_
#define PILA_H_

typedef struct Nodo {
    char *dato;
    struct Nodo *siguiente;
} Elemento;

typedef struct TopePila {
    Elemento *inicio;
    int tamanio;
} Pila;

void inicializar(Pila *tas);

int poner(Pila *tas, char *dato);

int sacar(Pila *tas);

int vaciar(Pila *tas);

int editar(Pila *tas, char *nuevo);

#define ultimo_dato(tas) tas->inicio->dato

void mostrar(Pila *tas);

#endif
