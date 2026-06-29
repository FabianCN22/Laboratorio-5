#include <stdio.h>
#include "dynamic_array.h"
#include "lista_simple.h"
#include "lista_doble.h"

void probar_arreglo(void) {
    DynamicArray arreglo;
    int valor;

    printf("\n=== ARREGLO DINAMICO ===\n");

    da_init(&arreglo, 2);

    da_add(&arreglo, 10);
    da_add(&arreglo, 20);
    da_add(&arreglo, 30);

    printf("Despues de agregar 10, 20 y 30:\n");
    da_print(&arreglo);

    if (da_get(&arreglo, 1, &valor)) {
        printf("Elemento en indice 1: %d\n", valor);
    }

    da_remove_at(&arreglo, 0);

    printf("Despues de eliminar el indice 0:\n");
    da_print(&arreglo);

    da_free(&arreglo);
}

void probar_lista_simple(void) {
    NodoSimple *lista;
    NodoSimple *encontrado;

    printf("\n=== LISTA SIMPLE ===\n");

    lista = NULL;

    ls_insertar_inicio(&lista, 20);
    ls_insertar_inicio(&lista, 10);
    ls_insertar_final(&lista, 40);
    ls_insertar_pos(&lista, 30, 2);

    printf("Despues de insertar 10, 20, 30 y 40:\n");
    ls_imprimir(lista);

    encontrado = ls_buscar(lista, 30);

    if (encontrado != NULL) {
        printf("Elemento encontrado: %d\n", encontrado->dato);
    }

    ls_eliminar(&lista, 20);

    printf("Despues de eliminar 20:\n");
    ls_imprimir(lista);

    ls_liberar(&lista);
}

void probar_lista_doble(void) {
    NodoDoble *lista;
    NodoDoble *encontrado;

    printf("\n=== LISTA DOBLE ===\n");

    lista = NULL;

    ld_insertar_inicio(&lista, 20);
    ld_insertar_inicio(&lista, 10);
    ld_insertar_final(&lista, 40);
    ld_insertar_pos(&lista, 30, 2);

    printf("Lista hacia adelante:\n");
    ld_imprimir_adelante(lista);

    printf("Lista hacia atras:\n");
    ld_imprimir_atras(lista);

    encontrado = ld_buscar(lista, 30);

    if (encontrado != NULL) {
        printf("Elemento encontrado: %d\n", encontrado->dato);
    }

    ld_eliminar(&lista, 20);

    printf("Despues de eliminar 20:\n");
    ld_imprimir_adelante(lista);

    ld_liberar(&lista);
}

int main(void) {
    printf("Laboratorio 5 - Estructuras de datos\n");

    probar_arreglo();
    probar_lista_simple();
    probar_lista_doble();

    return 0;
}
