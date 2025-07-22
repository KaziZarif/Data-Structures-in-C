#ifndef AVL_H
#define AVL_H

typedef struct avl_node {
    int value;
    int height;
    struct node* left;
    struct node* right;
} AvlNode;

typedef struct avl_tree {
    AvlNode* root;
} AvlTree;

AvlTree* avl_init();
void avl_insert(AvlTree* tree, int value);
int avl_exists(AvlTree* tree, int target);
void avl_destroy(AvlTree* tree);

#endif 