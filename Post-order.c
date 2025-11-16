#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char valor;
    struct node *izquierda;
    struct node *derecha;
    
}node;

node* raiz;

node* nuevo_node(char valor){
    node* nuevo = (node*) malloc(sizeof(node));
    nuevo->valor = valor;
    nuevo->izquierda = NULL;
    nuevo ->derecha = NULL;
    return nuevo;
}

int main() {

    raiz = nuevo_node('R');
    node* nodeA = nuevo_node('A');
    node* nodeB = nuevo_node('B');
    node* nodeC = nuevo_node('C');
    node* nodeD = nuevo_node('D');
    node* nodeE = nuevo_node('E');
    node* nodeF = nuevo_node('F');
    node* nodeG = nuevo_node('G');


    raiz -> izquierda = nodeA;
    raiz -> derecha = nodeB;
    nodeA -> izquierda = nodeC;
    nodeA -> derecha = nodeD;
    nodeB -> izquierda = nodeE;
    nodeB -> derecha = nodeF;
    nodeF -> izquierda = nodeG;

    printf(" %c ", nodeC->valor);
    printf(" %c ", nodeD->valor);
    printf(" %c ", nodeA->valor);
    printf(" %c ", nodeE->valor);
    printf(" %c ", nodeG->valor);
    printf(" %c ", nodeF->valor);
    printf(" %c ", nodeB->valor);
    printf(" %c ", raiz->valor);

}