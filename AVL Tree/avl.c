#include <stdlib.h>

typedef struct node {
    int value;
    int height;
    struct node* left;
    struct node* right;
} Node;

typedef struct tree {
    Node* root;
} Tree;

struct tree* avl_init(int value) {
    
}