#include <stdlib.h>

#include "BST.h"

typedef struct Node Node;

struct Node
{
	int m_value;
	Node* m_right;
	Node* m_left;
};

struct Tree
{
	Node* m_root;
};

static int destroyBSTnode(Node* root)
{
	if (root==NULL)
	{
		return OK;
	}
	if (root!=NULL)
	{
		destroyBSTnode(root->m_left);
		destroyBSTnode(root->m_right);
		free(root);
	}
	return AllocationError;
}

static int putValueInNode(Node* node, int value)
{
	node = malloc(sizeof(Node));
	if (node == NULL)
	{
		return AllocationError;
	}
	node->m_value = value;
	return OK;
}

static void inOrder(Node* root,walkFunc func)
{
	if(root!=NULL)
	{
		inOrder(root->m_left,func);
		func(root->m_value);
		inOrder(root->m_right,func);
	}
}

static void preOrder(Node* root,walkFunc func)
{
	if(root!=NULL)
	{
		func(root->m_value);
		inOrder(root->m_left,func);
		inOrder(root->m_right,func);

	}
}

static void postOrder(Node* root,walkFunc func)
{
	if(root!=NULL)
	{
		inOrder(root->m_left,func);
		inOrder(root->m_right,func);
		func(root->m_value);
	}
}
		
void walkBST(Tree* tree, walkFunc func, int order)
{
	switch(order)
	{
		case InOrder: 	inOrder(tree->m_root,func);
			      	break;
		case PreOrder: 	preOrder(tree->m_root,func);
			      	break;
		case PostOrder:	postOrder(tree->m_root,func);
			      	break;
		default: 	break;
	}
}
Tree* createBST()
{	
	Tree* tree = malloc(sizeof(Tree));
	if (tree == NULL)
	{
		return NULL;
	}
	tree->m_root = NULL;
	return tree;
	
}

AdtStatus insertValToBST(Tree* bst,int value)
{
	Node* currentNode;
	Node* parentNode = NULL;
	if (bst == NULL)
	{
		return AllocationError;
	}
	
	currentNode = bst->m_root;
	while (currentNode != NULL) 		/*Go to the Node where the value should be */
	{
		parentNode = currentNode;
		currentNode = (value < currentNode->m_value) ? currentNode->m_left :
						    	       currentNode->m_right ;
	}
	if (parentNode == NULL)
	{
		return putValueInNode( parentNode, value);

	}
	else if (value < parentNode->m_value)
	{
		return putValueInNode( parentNode->m_left, value);
	}
	else
	{
		return putValueInNode( parentNode->m_right, value);
	}
	return AllocationError;	
}		



AdtStatus searchValInBST(Tree* bst, int value)
{
	Node* currentNode;

	if (bst == NULL)
	{
		return AllocationError;
	}
	currentNode = bst->m_root;

	while (currentNode != NULL)
	{
		if (currentNode->m_value == value)
		{
			return OK;
		}
		else 
		{
			currentNode = (value < currentNode->m_value) ? currentNode->m_left :
								       currentNode->m_right  ;
		}	
	}
	return NotFound;
}

AdtStatus deleteValFromBST(Tree* bst, int value)
{
	Node* currentNode;
	Node* tempNode;
	if (bst == NULL)
	{
		return AllocationError;
	}
	if (searchValInBST(bst,value) == NotFound)
	{
		return NotFound;
	}
	while (currentNode != NULL)
	{
		if (currentNode->m_value == value)
		{
			if (currentNode->m_right == NULL)
			{
				tempNode = currentNode->m_left;
				free(currentNode);
				currentNode = tempNode;
				return OK;
			}
			else if (currentNode->m_left == NULL)
			{
				tempNode = currentNode->m_right;
				free(currentNode);
				currentNode = tempNode;
				return OK;
			}
			/*else
			{
				tempNode = currentNode->right;
				while(tempNode->left != NULL)
				{
					parentNode = tempNode;
					tempNode = tempNode->left;
				}
				currentNode->value = tempNode->value;
				if (parentNode !=NULL)
					parentNode->m_left -	*/
		}
		else 
		{
			currentNode = (value < currentNode->m_value) ? currentNode->m_left  :
								       currentNode->m_right ;
		}	
	}
	return OK;
	
}

AdtStatus destroyBST(Tree* tree)
{
	if (tree == NULL)
	{
		return AllocationError;
	}
	return destroyBSTnode(tree->m_root);
	
}



	


















