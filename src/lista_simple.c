#include <stdio.h>
#include <stdlib.h>
#include "lista_simple.h"

NodoSimple *ls_crear_nodo(int dato) {
    NodoSimple *nuevo;

    nuevo = (NodoSimple *) malloc(sizeof(NodoSimple));

    if (nuevo == NULL) {
        return NULL;
    }

    nuevo->dato = dato;
    nuevo->sig = NULL;

    return nuevo;
}

int ls_insertar_inicio(NodoSimple **lista, int dato) {
    NodoSimple *nuevo;

    if (lista == NULL) {
        return 0;
    }

    nuevo = ls_crear_nodo(dato);

    if (nuevo == NULL) {
        return 0;
    }

    nuevo->sig = *lista;
    *lista = nuevo;

    return 1;
}

int ls_insertar_final(NodoSimple **lista, int dato) {
    NodoSimple *nuevo;
    NodoSimple *actual;

    if (lista == NULL) {
        return 0;
    }

    nuevo = ls_crear_nodo(dato);

    if (nuevo == NULL) {
        return 0;
    }

    if (*lista == NULL) {
        *lista = nuevo;
        return 1;
    }

    actual = *lista;

    while (actual->sig != NULL) {
        actual = actual->sig;
    }

    actual->sig = nuevo;

    return 1;
}

int ls_insertar_pos(NodoSimple **lista, int dato, int pos) {
    NodoSimple *nuevo;
    NodoSimple *actual;
    int i;

    if (lista == NULL || pos < 0) {
        return 0;
    }

    if (pos == 0) {
        return ls_insertar_inicio(lista, dato);
    }

    actual = *lista;
    i = 0;

    while (actual != NULL && i < pos - 1) {
        actual = actual->sig;
        i++;
    }

    if (actual == NULL) {
        return 0;
    }

    nuevo = ls_crear_nodo(dato);

    if (nuevo == NULL) {
        return 0;
    }

    nuevo->sig = actual->sig;
    actual->sig = nuevo;

    return 1;
}

int ls_eliminar(NodoSimple **lista, int dato) {
    NodoSimple *actual;
    NodoSimple *anterior;

    if (lista == NULL || *lista == NULL) {
        return 0;
    }

    actual = *lista;
    anterior = NULL;

    while (actual != NULL) {
        if (actual->dato == dato) {
            if (anterior == NULL) {
                *lista = actual->sig;
            } else {
                anterior->sig = actual->sig;
            }

            free(actual);
            return 1;
        }

        anterior = actual;
        actual = actual->sig;
    }

    return 0;
}

NodoSimple *ls_buscar(NodoSimple *lista, int dato) {
    NodoSimple *actual;

    actual = lista;

    while (actual != NULL) {
        if (actual->dato == dato) {
            return actual;
        }

        actual = actual->sig;
    }

    return NULL;
}

void ls_imprimir(NodoSimple *lista) {
    NodoSimple *actual;

    actual = lista;

    printf("[ ");

    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->sig;
    }

    printf("]\n");
}

void ls_liberar(NodoSimple **lista) {
    NodoSimple *actual;
    NodoSimple *siguiente;

    if (lista == NULL) {
        return;
    }

    actual = *lista;

    while (actual != NULL) {
        siguiente = actual->sig;
        free(actual);
        actual = siguiente;
    }

    *lista = NULL;
}
