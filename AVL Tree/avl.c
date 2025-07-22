#include <stdlib.h>
#include <stdio.h>
#include "avl.h"

// helper functions
static int height(AvlNode* node) {
    if (node != NULL) {
        return node->height;
    } else {
        return -1;
    }
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int get_balance(AvlNode* node) {
    if (node != NULL) {
        return height(node->left) - height(node->right);
    } else {
        return 0;
    }
}

static int search_node(AvlNode* node, int target) {
    if (node == NULL) {
        return 0;
    }
    if (node->value == target) {
        return 1;
    } 
    else if (target < node->value) {
        return search_node(node->left, target);
    } else {
        return search_node(node->right, target);
    }
}


// Tree functions 
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
    else if (value < node->value) {
        node->left = insert_node(node->left, value);
    } 
    else if (value > node->value) {
        node->right = insert_node(node->right, value);
    } else {
        fprintf(stderr, "Value already exists in tree.\n");
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = get_balance(node);

    // Balance the tree. There are 4 cases
    // Case 1: Left-Left  
    if (balance > 1 && value < node->left->value) {
        return rotate_right(node);
    }

    // Case 2: Right-Right
    if (balance < -1 && value > node->right->value) {
        return rotate_left(node);
    }

    // Case 3: Left-Right
    if (balance > 1 && value > node->left->value) {
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }

    // Case 4: Right-Left
    if (balance < -1 && value < node->right->value) {
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }

    return node;

}

static struct avl_node* rotate_left(AvlNode* node) {
    AvlNode* new_root = node->right;
    AvlNode* moved_subtree = new_root->left;

    new_root->left = node;
    node->right = moved_subtree;

    node->height = 1 + max(height(node->left), height(node->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
}

static struct avl_node* rotate_right(AvlNode* node) {
    AvlNode* new_root = node->left;
    AvlNode* moved_subtree = new_root->right;

    new_root->right = node;
    node->left = moved_subtree;

    node->height = 1 + max(height(node->left), height(node->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
}


int avl_exists(AvlTree* tree, int target) {
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }
    return search_node(tree->root, target);
}

static void destroy_node(AvlNode* node) {
    if (node == NULL) {
        return;
    }

    destroy_node(node->left);
    destroy_node(node->right);
    free(node);
}

void avl_destroy(AvlTree* tree) { 
    if (tree == NULL || tree->root == NULL) return;
    destroy_node(tree->root);
    free(tree);
}

