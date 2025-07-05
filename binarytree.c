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