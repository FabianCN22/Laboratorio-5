#include <stdio.h>
#include "dynamic_array.h"

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

int main(void) {
    printf("Laboratorio 5 - Estructuras de datos\n");

    probar_arreglo();

    return 0;
}
