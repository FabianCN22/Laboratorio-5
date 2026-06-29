#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

typedef struct NodoDoble {
    int dato;
    struct NodoDoble *ant;
    struct NodoDoble *sig;
} NodoDoble;

NodoDoble *ld_crear_nodo(int dato);
int ld_insertar_inicio(NodoDoble **lista, int dato);
int ld_insertar_final(NodoDoble **lista, int dato);
int ld_insertar_pos(NodoDoble **lista, int dato, int pos);
int ld_eliminar(NodoDoble **lista, int dato);
NodoDoble *ld_buscar(NodoDoble *lista, int dato);
void ld_imprimir_adelante(NodoDoble *lista);
void ld_imprimir_atras(NodoDoble *lista);
void ld_liberar(NodoDoble **lista);

#endif
