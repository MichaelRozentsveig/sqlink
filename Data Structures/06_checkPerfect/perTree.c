#include <stdio.h>

#include "perTree.h"


int checkPerfect(Node_t* root)
{
    if ((root->left == NULL) && (root->right == NULL))
    {
        return 1 ;
    }
    if ((checkPerfect(root->left) && checkPerfect(root->left) && (heightTree(root->left)== heightTree(root->right))) == 1)
    {
        return 1;
    }
    return 0;
}

int heightTree(Node_t* node)
{
    int height =0;
    while (node!= NULL)
    {
        if (node->right == NULL || node->left == NULL)
        {
            break;
        }
        height++;
        node = node->left;
    }
    return height;
}

Node_t* newNode(int data) 
{ 
    Node_t* node = malloc(sizeof(Node_t)); 
    node->value = data; 
    node->right = NULL ;
    node->left = NULL; 
    return node; 
} 