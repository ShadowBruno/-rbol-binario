#include <stdio.h>
#include <stdlib.h>
typedef struct nodo {
    char dato;
    struct nodo* izquierda;
    struct nodo* derecha;
} nodo;
nodo* crearnodo(char letra) {
    nodo* nuevo = malloc(sizeof(nodo));
    nuevo->dato = letra;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;
    return nuevo;
}
void preOrder(nodo* nodo) {
    if (nodo == NULL) return;
    printf("%c ", nodo->dato);
    preOrder(nodo->izquierda);
    preOrder(nodo->derecha);
}
int main () {
    nodo* R = crearnodo('R');
    nodo* A = crearnodo('A');
    nodo* B = crearnodo('B');
    nodo* C = crearnodo('C');
    nodo* D = crearnodo('D');
    nodo* E = crearnodo('E');
    nodo* F = crearnodo('F');
    nodo* G = crearnodo('G');
    R->izquierda = A;
    R->derecha = B;
    A->izquierda = C;
    A->derecha = D;
    B->izquierda = E;
    B->derecha = F;
    F->derecha = G;
    preOrder(R);
    return 0;
}