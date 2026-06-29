#include <stdio.h>
#include "dynamic_array.h"
#include "lista_simple.h"

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

int main(void) {
    printf("Laboratorio 5 - Estructuras de datos\n");

    probar_arreglo();
    probar_lista_simple();

    return 0;
}
