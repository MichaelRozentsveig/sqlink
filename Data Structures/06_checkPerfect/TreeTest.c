#include <stdio.h>
#include <stdlib.h>

#include "perTree.h"

int main()
{
    Node_t*  root;
    root = newNode(4);

    root->left = newNode(2); 
    root->right = newNode(6); 
  
    root->left->left  = newNode(1); 
    root->left->right = newNode(3); 
    root->right->left  = newNode(5); 
    root->right->right = newNode(7); 
  
    if (checkPerfect(root) == 1)
    {
        printf("Tree is perfect\n");
    }
    else
    {
        printf("The tree is not perfect\n");
    }
}