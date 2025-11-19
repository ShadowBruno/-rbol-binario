#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char value;
    struct node *left;
    struct node *right;
} node;


node* root;

node* new_node(){
    node* n = (node*) malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    return n;
}

int main(void) {
    root = new_node();
    root->value = 'R';
    root->left = new_node();
    //root->left->value = 'A';
    printf("%c", root->left->value);
    root->right = new_node();
    root->right->value = 'B';
    root->left->left = new_node();
    root->left->left->value = 'C';
    root->left->right = new_node();
    root->left->right->value = 'D';
    root->right->left = new_node();
    root->right->left->value = 'E';
    root->right->right = new_node();
    root->right->right->value = 'F';
    root->right->right->left = new_node();
    root->right->right->left->value = 'G';


    printf("\nPre-order traversal: \n");
    preOrder(root);
    printf("\nIn-order traversal: \n");
    inOrder(root);
    printf("\nPost-order traversal: \n");
    Postorder(root);
    return 0;
}


void preOrder(node* nodo) {
    if (nodo == NULL) return;
    printf("%c ", nodo->value);
    preOrder(nodo->left);
    preOrder(nodo->right);
}
void inOrder(node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%c ", root->value);
    inOrder(root->right);
}
void Postorder(node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    inOrder(root->right);
    printf("%c ", root->value);
}