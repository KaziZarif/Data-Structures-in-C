#ifndef AVL_H
#define AVL_H

typedef struct node {
    int value;
    int height;
    struct node* left;
    struct node* right;
} Node;

typedef struct tree {
    Node* root;
} AvlTree;

AvlTree* avl_init();
void avl_insert(AvlTree* tree, int value);
int avl_exists(AvlTree* tree, int target);
void avl_destroy(AvlTree* tree);
