#include <stdlib.h>
#include <stdio.h>
#include "avl.h"


struct avl_tree* avl_init() {
    AvlTree* tree = malloc(sizeof(AvlTree));
    if (tree == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    tree->root = NULL;
    return tree;
}

void avl_insert(AvlTree* tree, int value) {
    if (tree == NULL) {
        fprintf(stderr, "Tree is null\n");
        return;
    }
    tree->root = insert_node(tree->root, value);
}

struct avl_node* insert_node(AvlNode* node, int value) {
    if (node == NULL) { 
        AvlNode* new_node = malloc(sizeof(AvlNode));
        if (new_node == NULL) {
            printf("Memory allocation failed.\n");
            return NULL;
        }
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->height = 0;
        return new_node;
    }
    else if (node->value == value) {
        fprintf(stderr, "Value already exists in tree.\n");
        return node;
    }
    else if (value < node->value) {
        node->left = insert_node(node->left, value);
    } 
    else if (value > node->value) {
        node->right = insert_node(node->right, value);
    }
}