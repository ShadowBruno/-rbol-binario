//arbol binario in-order 
//revisa si hay izquierda si hay cambia a izquierda si no imprime valor y luego revisa si hay derecha si si va a la izquierda y se repite 
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    char data;
    struct Nodo* left;
    struct Nodo* right;
};

void inOrder(struct Nodo* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

int main() {
    
    printf("Arbol binario in-order\n");
    printf("\n");
    struct Nodo* R = malloc(sizeof(struct Nodo));
    struct Nodo* A = malloc(sizeof(struct Nodo));
    struct Nodo* B = malloc(sizeof(struct Nodo));
    struct Nodo* C = malloc(sizeof(struct Nodo));
    struct Nodo* D = malloc(sizeof(struct Nodo));
    struct Nodo* E = malloc(sizeof(struct Nodo));
    struct Nodo* F = malloc(sizeof(struct Nodo));
    struct Nodo* G = malloc(sizeof(struct Nodo));

    R->data='R'; A->data='A'; B->data='B'; C->data='C';
    D->data='D'; E->data='E'; F->data='F'; G->data='G';

    R->left=A;   R->right=B;
    A->left=C;   A->right=D;
    B->left=E;   B->right=F;
    F->left=G;   F->right=NULL;
    C->left=D->left=E->left=G->left=NULL;
    C->right=D->right=E->right=G->right=NULL;

    printf("Recorrido in-order: \n");
    inOrder(R);  
    printf("\n");
    free(G); free(F); free(E); free(D);
    free(C); free(B); free(A); free(R);

    return 0;
}