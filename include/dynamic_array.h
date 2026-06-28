#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void da_init(DynamicArray *array, int capacity);
int da_add(DynamicArray *array, int value);
int da_remove_at(DynamicArray *array, int index);
int da_get(DynamicArray *array, int index, int *value);
void da_print(DynamicArray *array);
void da_free(DynamicArray *array);

#endif
