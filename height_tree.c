struct s_node {
    int value;
    struct s_node **nodes;
};


int height_tree(struct s_node *root)
{
    int i = 0;
    int rescur;
    
    if (!root)
        return -1;
    else
    {
        int hmax = 0;
        if (root->nodes)
        {
            while (root->nodes[i])
            {
                rescur = 1 + height_tree(root->nodes[i]);
                if (rescur > hmax)
                    hmax = rescur;
                i++;
            }
            return hmax;
        }
    }
    return 0;
}


#include <stdio.h>
#include <stdlib.h>


struct s_node * newnode(int item, int num_children)
{
    struct s_node * newnode = (malloc(sizeof(struct s_node)));
    newnode->value = item;
    newnode->nodes = malloc((num_children + 1) * sizeof(struct s_node));
    newnode->nodes[num_children] = NULL;
    return newnode;
}

void freeNodeRec(struct s_node *root)
{
    int i = 0;
    
    if (root)
    {
        while (root->nodes[i])
        {
            freeNodeRec(root->nodes[i]);
            i++;
        }
    }
    free(root->nodes);
    free(root);
}
//
//void freeNode(struct s_node *root)
//{
//    struct s_node *tmp = root;
//   while (1)
//   {
//       if (!root)
//           break;
//
//        while (root->children)
//        {
//            root=root->children;
//        }
//        free(root);
//        free(children);
//   }
//    root = tmp;
//
//}

int main(void)
{
    struct s_node *root = newnode(94, 2);
    
    root->nodes[0] = newnode(34, 3);
    root->nodes[1] = newnode(52, 0);
    
    root->nodes[0]->nodes[0] = newnode(1, 0);
    root->nodes[0]->nodes[1] = newnode(99, 1);
    root->nodes[0]->nodes[2] = newnode(11, 0);
    
    root->nodes[0]->nodes[1]->nodes[0] = newnode(13, 0);
    
    
    
    int res = height_tree(root);
    printf("%d\n", res);
    freeNodeRec(root);
    return 0;
  
}
