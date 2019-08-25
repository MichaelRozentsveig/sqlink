#ifndef HEADER_H
#define HEADER_H

typedef enum {OK, AllocationError, NotFound} AdtStatus;

typedef enum  {InOrder, PreOrder, PostOrder} OrderType; 

typedef struct Tree Tree;

typedef void (*walkFunc)(int order);

void walkBST(Tree* tree, walkFunc func, int order);

Tree* createBST();

AdtStatus insertValToBST(Tree* bst,int value);

AdtStatus searchValInBST(Tree* bst, int value);

AdtStatus deleteValFromBST(Tree* bst, int value);

AdtStatus destroyBST(Tree* tree);

#endif