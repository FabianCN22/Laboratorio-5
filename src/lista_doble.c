#include <stdio.h>
#include <stdlib.h>
#include "lista_doble.h"

NodoDoble *ld_crear_nodo(int dato) {
    NodoDoble *nuevo;

    nuevo = (NodoDoble *) malloc(sizeof(NodoDoble));

    if (nuevo == NULL) {
        return NULL;
    }

    nuevo->dato = dato;
    nuevo->ant = NULL;
    nuevo->sig = NULL;

    return nuevo;
}

int ld_insertar_inicio(NodoDoble **lista, int dato) {
    NodoDoble *nuevo;

    if (lista == NULL) {
        return 0;
    }

    nuevo = ld_crear_nodo(dato);

    if (nuevo == NULL) {
        return 0;
    }

    nuevo->sig = *lista;

    if (*lista != NULL) {
        (*lista)->ant = nuevo;
    }

    *lista = nuevo;

    return 1;
}

int ld_insertar_final(NodoDoble **lista, int dato) {
    NodoDoble *nuevo;
    NodoDoble *actual;

    if (lista == NULL) {
        return 0;
    }

    nuevo = ld_crear_nodo(dato);

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
    nuevo->ant = actual;

    return 1;
}

int ld_insertar_pos(NodoDoble **lista, int dato, int pos) {
    NodoDoble *nuevo;
    NodoDoble *actual;
    int i;

    if (lista == NULL || pos < 0) {
        return 0;
    }

    if (pos == 0) {
        return ld_insertar_inicio(lista, dato);
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

    if (actual->sig == NULL) {
        return ld_insertar_final(lista, dato);
    }

    nuevo = ld_crear_nodo(dato);

    if (nuevo == NULL) {
        return 0;
    }

    nuevo->sig = actual->sig;
    nuevo->ant = actual;
    actual->sig->ant = nuevo;
    actual->sig = nuevo;

    return 1;
}

int ld_eliminar(NodoDoble **lista, int dato) {
    NodoDoble *actual;

    if (lista == NULL || *lista == NULL) {
        return 0;
    }

    actual = *lista;

    while (actual != NULL) {
        if (actual->dato == dato) {
            if (actual->ant != NULL) {
                actual->ant->sig = actual->sig;
            } else {
                *lista = actual->sig;
            }

            if (actual->sig != NULL) {
                actual->sig->ant = actual->ant;
            }

            free(actual);
            return 1;
        }

        actual = actual->sig;
    }

    return 0;
}

NodoDoble *ld_buscar(NodoDoble *lista, int dato) {
    NodoDoble *actual;

    actual = lista;

    while (actual != NULL) {
        if (actual->dato == dato) {
            return actual;
        }

        actual = actual->sig;
    }

    return NULL;
}

void ld_imprimir_adelante(NodoDoble *lista) {
    NodoDoble *actual;

    actual = lista;

    printf("[ ");

    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->sig;
    }

    printf("]\n");
}

void ld_imprimir_atras(NodoDoble *lista) {
    NodoDoble *actual;

    actual = lista;

    if (actual == NULL) {
        printf("[ ]\n");
        return;
    }

    while (actual->sig != NULL) {
        actual = actual->sig;
    }

    printf("[ ");

    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->ant;
    }

    printf("]\n");
}

void ld_liberar(NodoDoble **lista) {
    NodoDoble *actual;
    NodoDoble *siguiente;

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
