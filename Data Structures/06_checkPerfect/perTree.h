#include <stdlib.h>

typedef struct Node Node_t;

struct Node
{
    int value;
    Node_t* left;
    Node_t* right;
};

int checkPerfect(Node_t* root);

int heightTree(Node_t* node);
 
Node_t* newNode(int data) ;