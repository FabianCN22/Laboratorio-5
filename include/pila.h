#ifndef PILA_H
#define PILA_H

typedef struct NodoPila {
    int dato;
    struct NodoPila *sig;
} NodoPila;

int pila_push(NodoPila **pila, int dato);
int pila_pop(NodoPila **pila, int *dato);
int pila_top(NodoPila *pila, int *dato);
int pila_vacia(NodoPila *pila);
void pila_imprimir(NodoPila *pila);
void pila_liberar(NodoPila **pila);

#endif
