#include <stdlib.h>
#include <stdio.h>

typedef struct tree_node tree_node;
typedef struct bst bst;

struct tree_node
{
    int val;
    tree_node* left;
    tree_node* right;
};

struct bst
{
    tree_node* root;
};

/* Construct the binary search tree */
bst* init_bst()
{
    bst* new_tree = (bst*)malloc(sizeof(bst));
    if (new_tree == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    new_tree->root = NULL;
    return new_tree;
}

/* Insert value 'val' into the binary search tree */
void bst_insert(bst* tree, int val)
{   
    tree->root = insert_node(tree->root, val);

}

tree_node* insert_node(tree_node* node, int val) {
    if (node == NULL) {
        tree_node* new_node = malloc(sizeof(tree_node));
        if (new_node == NULL) {
            printf("Memory allocation failed.\n");
            return NULL;
        }
        new_node->val = val;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (val < node->val) {
        node->left = insert_node(node->left, val);
    } else if (val > node->val) {
        node->right = insert_node(node->right, val);
    }
    return node;
}

/* Return 1 if the target value in the binary search tree exists otherwise 0 */
int bst_exists(bst* tree, int target)
{
    if (tree == NULL || tree->root == NULL) {
        return 0;
    }
    return search_tree(tree->root, target);
}

int search_tree(tree_node* node, int target) {
    if (node == NULL) {
        return 0;
    }
    if (target == node->val) {
        return 1;
    }
    if (target < node->val) {
        return search_tree(node->left, target);
    } else if (target > node->val) {
        return search_tree(node->right, target);
    }
}

/* Destroy the binary search tree */
void destroy_bst(bst* tree)
{   
    if (tree == NULL) return;
    destroy_tree(tree->root);
    free(tree);
}

void destroy_tree(tree_node* node) {
    if (node == NULL) return;
    destroy_tree(node->left);
    destroy_tree(node->right);
    free(node);
}
