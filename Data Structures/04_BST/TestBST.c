#include <stdio.h>
#include <stdlib.h>

#include "BST.h"

void printTree(int);

int main()
{
	Tree* tree;
	walkFunc func = printTree;
	
	int input = 0;
	int cont = 1;
	unsigned int option = 0;
	int order = 0;

	tree = createBST();
	
	while(cont)
	{
		printf("Choose option:       	\n");
		printf("1: Insert item       	\n");
		printf("2: Delete item       	\n");
		printf("3: Sum Tree          	\n");
		printf("4: Check if item exists \n");

		scanf("%u",&option);
		switch (option)
		{
			case 1: 
				printf("Insert item: \n");
				scanf("%d",&input);
				insertValToBST(tree,input);        
		    		break;

			case 2: 
				printf("Insert item to delete: \n");
				scanf("%d",&input);
				deleteValFromBST(tree, input);		        
			    	break;

			case 3: 
				printf("Insert walking order: \n");
				printf("0: InOrder \n1: PreOrder \n2: PostOrder\n" );	
				scanf("%d",&order);							
				walkBST(tree, func, order);	    
			    	break;

			case 4: 
				printf("Insert item to search: \n");
				scanf("%d",&input);
				if (!searchValInBST(tree,input))	
				{
					printf("Found ! \n");
				}else{
					printf("Not Found!\n");
				}
				break;
			default: 
				cont = 0;		    
			    	break;
			}
	}
	destroyBST(tree);
}

void printTree( int value)
{
	printf("%d", value);
}