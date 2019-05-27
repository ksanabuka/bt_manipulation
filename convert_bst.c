#include <stdio.h>
#include <stdlib.h>

struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
};

void dojob_node_relink(struct s_node *head, void * ctx)
{
    struct s_node ** prev = (struct s_node **)ctx;

    if (*prev)
        (*prev)->right = head;
    
    head->left = *prev;
    *prev = head;
}

struct s_node *minv(struct s_node *head)
{
    struct s_node * tmp = head;
    while (tmp->left)
        tmp = tmp->left;
    return tmp;
}

struct s_node *maxv(struct s_node *head)
{
    struct s_node * tmp = head;
    while (tmp->right)
        tmp = tmp->right;
    return tmp;
}

void inOrderTraverse(struct s_node *head, void * ctx, void(*fn)(struct s_node *, void *))
{
    if (!head)
        return;
    inOrderTraverse(head->left, ctx, fn);
    fn(head, ctx);
    inOrderTraverse(head->right, ctx, fn);
}

struct s_node *convert_bst(struct s_node *root)
{
    struct s_node * min = minv(root);
    struct s_node * max = maxv(root);
    
    if (min && max)
    {
        struct s_node * prev = 0;
        inOrderTraverse(root, &prev, &dojob_node_relink);
        min->left = max;
        max->right = min;
    }
    
    return min;
}

struct s_node * addNode(int value)
{
    struct s_node * node = (struct s_node*)malloc(sizeof(struct s_node));
    node->value = value;
    node->left = 0;
    node->right = 0;
    return node;
}

int main(void)
{
    struct s_node * root = addNode(38);
    
    root->left = addNode(13);
    root->right = addNode(51);
    
    root->left->left = addNode(10);
    root->left->right = addNode(25);
    
    root->left->left->right = addNode(12);
    root->left->right->right = addNode(37);
    
    root->right->left = addNode(40);
    root->right->right = addNode(84);
    root->right->right->left = addNode(66);
    root->right->right->right = addNode(89);
    root->right->right->right->right = addNode(95);
    
    struct s_node * min = convert_bst(root);

    int i = 0;
    while (i++ < 12)
    {
        printf("%d\n", min->value);
        min = min->right;
    }

    return 0;
}








