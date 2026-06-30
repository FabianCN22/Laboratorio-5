#include <stdio.h>
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

int pila_vacia(NodoPila *pila) {
    if (pila == NULL) {
        return 1;
    }

    return 0;
}

void pila_imprimir(NodoPila *pila) {
    NodoPila *actual;

    actual = pila;

    printf("[ ");

    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->sig;
    }

    printf("]\n");
}

void pila_liberar(NodoPila **pila) {
    int dato;

    if (pila == NULL) {
        return;
    }

    while (!pila_vacia(*pila)) {
        pila_pop(pila, &dato);
    }

    *pila = NULL;
}
