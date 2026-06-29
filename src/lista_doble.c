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
