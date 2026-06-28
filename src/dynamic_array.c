#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"

void da_init(DynamicArray *array, int capacity) {
    if (array == NULL) {
        return;
    }

    if (capacity <= 0) {
        capacity = 1;
    }

    array->data = (int *) malloc(sizeof(int) * capacity);

    if (array->data == NULL) {
        array->size = 0;
        array->capacity = 0;
        return;
    }

    array->size = 0;
    array->capacity = capacity;
}

int da_add(DynamicArray *array, int value) {
    int new_capacity;
    int *new_data;

    if (array == NULL || array->data == NULL) {
        return 0;
    }

    if (array->size == array->capacity) {
        new_capacity = array->capacity * 2;
        new_data = (int *) realloc(array->data, sizeof(int) * new_capacity);

        if (new_data == NULL) {
            return 0;
        }

        array->data = new_data;
        array->capacity = new_capacity;
    }

    array->data[array->size] = value;
    array->size++;

    return 1;
}

int da_get(DynamicArray *array, int index, int *value) {
    if (array == NULL || value == NULL) {
        return 0;
    }

    if (index < 0 || index >= array->size) {
        return 0;
    }

    *value = array->data[index];

    return 1;
}

void da_print(DynamicArray *array) {
    int i;

    if (array == NULL || array->data == NULL) {
        printf("Arreglo no inicializado.\n");
        return;
    }

    printf("[ ");

    for (i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }

    printf("]\n");
}
