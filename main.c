#include <stdio.h>
typedef struct node
{
    char value;
    struct node *left;
    struct node *right;
} node;


node* root;


int main(void) {
    root = new_node();
    root->value = 'R';
    root->left = new_node();
    root->left->value = 'A';
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


    return 0;
}

node* new_node(){
    node* n = (node*) malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    return n;
}

void pre_order(struct node *n) {
    
}
