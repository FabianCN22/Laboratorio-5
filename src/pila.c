#include <stdlib.h>
#include "pila.h"

int pila_push(NodoPila **pila, int dato) {
    NodoPila *nuevo;

    if (pila == NULL) {
        return 0;
    }

    nuevo = (NodoPila *) malloc(sizeof(NodoPila));

    if (nuevo == NULL) {
        return 0;
    }

    nuevo->dato = dato;
    nuevo->sig = *pila;
    *pila = nuevo;

    return 1;
}

int pila_pop(NodoPila **pila, int *dato) {
    NodoPila *temp;

    if (pila == NULL || *pila == NULL || dato == NULL) {
        return 0;
    }

    temp = *pila;
    *dato = temp->dato;
    *pila = temp->sig;

    free(temp);

    return 1;
}

int pila_top(NodoPila *pila, int *dato) {
    if (pila == NULL || dato == NULL) {
        return 0;
    }

    *dato = pila->dato;

    return 1;
}
