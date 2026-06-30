#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

typedef struct NodoSimple {
    int dato;
    struct NodoSimple *sig;
} NodoSimple;

NodoSimple *ls_crear_nodo(int dato);
int ls_insertar_inicio(NodoSimple **lista, int dato);
int ls_insertar_final(NodoSimple **lista, int dato);
int ls_insertar_pos(NodoSimple **lista, int dato, int pos);
int ls_eliminar(NodoSimple **lista, int dato);
NodoSimple *ls_buscar(NodoSimple *lista, int dato);
void ls_imprimir(NodoSimple *lista);
void ls_liberar(NodoSimple **lista);

#endif
