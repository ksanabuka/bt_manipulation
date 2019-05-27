#include <stdlib.h>
#include <stdio.h>

struct s_node
{
    int value;
    struct s_node *left;
    struct s_node *right;
};


int checksequence(int d1, int d2)
{
    return (d1 ==  d2 - 1) ? 1 : 0;
}

int longest_sequesnce_from_node(struct s_node *node)
{
    int left_len = 1;
    int right_len = 1;
    if (node)
    {
        if (node->left)
        {
            if (checksequence(node->value, node->left->value))
            {
                left_len = 1 + longest_sequesnce_from_node(node->left);
            }
        }
        
        if (node->right)
        {
            if (checksequence(node->value, node->right->value))
            {
                right_len = 1 + longest_sequesnce_from_node(node->right);
            }
        }
        
        return (left_len > right_len ? left_len : right_len);
    }
    else
        return 0;
    
}

void traverse(struct s_node * root, void *info, void (*fn)(struct s_node *, void *))
{
    if (root)
    {
        fn(root, info);
        traverse(root->left, info, fn);
        //fn(root, info);
        traverse(root->right, info, fn);
        //fn(root, info);
    }
}

void print_node_visitor(struct s_node *node, void *info)
{
    info = 0;
    printf("%d\n", node->value);
}


void print_all_nodes(struct s_node *node)
{
    void * info = 0;
    traverse(node, &info, &print_node_visitor);
    
}


void count_nodes_visitor(struct s_node * node, void *info)
{
    int * pNum = (int*) info;
    *pNum += 1;
}

int count_nodes(struct s_node * node)
{
    int count = 0;
    traverse(node, &count, count_nodes_visitor);
    return count;
}



void find_min_visitor(struct s_node * node, void *info)
{
    struct s_node ** pNodeMin = (struct s_node **)info;
    
    if (*pNodeMin == 0 || node->value < (*pNodeMin)->value)
        *pNodeMin = node;
}

struct s_node * findMinValueNode(struct s_node * node)
{
    struct s_node * res = 0;
    traverse(node, &res, &find_min_visitor);
    return res;
    
}


void longest_sequence_visitor(struct s_node * node, void *info)
{
    int * pMax = (int*) info;
    int l = longest_sequesnce_from_node(node);
    if (l > *pMax)
        *pMax = l;
    
}

void addition_visitor(struct s_node * node, void * info)
{
    int * pSum = (int *)info;
    
    *pSum+= node->value;
}

int sumNodeValues(struct s_node * node)
{
    int sum = 0;
    traverse(node, &sum, &addition_visitor);
    return sum;
}

int    longest_sequence(struct s_node *node)
{
    int lmax = 0;
    traverse(node, &lmax, &longest_sequence_visitor);
    return lmax;
    
    
    
    
    
    
    
    int max = 1;
    int cur;
    
    
    //traverse tree and for each node count longest sequence
    
    //if max < cur.longest_sequence -> max = cur ;
    //return max
    
    if (node)
    {
        
        if (node->left)
        {
            cur = checksequence(node->value, node->left->value) + longest_sequesnce_from_node(node->left);
            if (cur > max)
                max = cur;
            longest_sequence(node->left);
        }
        if (node->right)
        {
            cur = checksequence(node->value, node->right->value) + longest_sequesnce_from_node(node->right);
            if (cur > max)
                max = cur;
            longest_sequence(node->right);
            
        }
        return max;
    }
    else
        return 0;
}

struct s_node *  addNode(int value)
{
    struct s_node * node = (struct s_node *)malloc(sizeof(struct s_node));
    node->value = value;
    node->left = 0;
    node->right = 0;
    return node;
}


#include <stdlib.h>

int main(void)
{
    struct s_node *root_root = addNode(100);
    struct s_node * root = addNode(10);
    root_root->left = root;
    root->left = addNode(5);
    root->left->left = addNode(6);
    root->left->right = addNode(9);
    
    root->left->left->right = addNode(13);
    root->left->left->left = addNode(7);

//    int a = longest_sequence(root_root);
//    printf("%d\n", a);
//    int sum = sumNodeValues(root_root);
//    printf("%d\n", sum);
//    struct s_node * nodeMin = findMinValueNode(root_root);
//    if (nodeMin)
//        printf("%d\n", nodeMin->value);
//    int count = count_nodes(root_root);
//    printf("%d\n", count);

    print_all_nodes(root_root);
    return 0;
}




