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
