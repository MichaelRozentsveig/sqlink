#include <stdio.h>
#include <stdlib.h>
#include "darray_generic.h"

void destroyInt(void* _elem, void* context);
void printInt(void* _elem);
int compareInt(void* _elemA, void* elemB);

int main()
{
	
	FILE* fp;
	void* elem;
	darray* dArr;
	elementDestroy destroy = destroyInt;
	elementPrint print = printInt;
	elementCompare compare = compareInt;
	int initial_capacity=0;
	int cont = 1;
	int* item1;
	int item = 0;
	unsigned int option = 0;
	unsigned int myIndex = 0;
	int myInt = 0;

	fp = fopen ("textFile.txt","a");
	if(!fp)
	{
		return 0;
	}
	
	printf("Insert capacity: \n");
    	scanf("%d", &initial_capacity);

    	if (darrayCreate(&dArr,initial_capacity))
    	{
		printf("Creation Failed !!! \n");
		return AllocationError;
    	}
	
	while(cont)
	{
		printf("Choose option:       \n");
		printf("1: Add item          \n");
		printf("2: Delete item       \n");
		printf("3: Get item          \n");
		printf("4: Set item          \n");
		printf("5: Number of items   \n");
		printf("6: Sort array        \n");
		printf("7: Print array       \n");

		scanf("%u",&option);
		switch (option)
		{
			case 1: 
				item1 = malloc(sizeof(int));
				printf("Insert item: \n");
				scanf("%d",&item1[0]);
				if (darrayAdd(dArr,item1))
				{
				    printf("Adding Failed !!! \n");
				}           
		    		break;

			case 2: 
				if (darrayDelete(dArr,  &elem))
				{
				    	printf("Deleting Failed !!! \n");
				}
						        
			    	break;

			case 3: 
				printf("Insert the index of the item you want to get:\n");
				scanf("%u",&myIndex);

				if (darrayGet(dArr,myIndex,(void**)&myInt))
				{
				    printf("Getting Failed !!! \n");
				}
				else
				{
				    printf("%d\n",myInt);   
				}		    
			    	break;

			case 4: 
				printf("Insert item: \n");
				scanf("%d",&item);

				printf("Insert the index of the item you want to set:\n");
				scanf("%u",&myIndex);

				if (darraySet(dArr,myIndex,(void*)&item))
				{
				    printf("Setting Failed !!! \n");
				}		        
			    	break;

			case 5: 
				if (darrayItemsNum(dArr,&myInt))
				{
				    printf("Getting num of items Failed !!! \n");
				}
				else
				{
				    printf("%d\n",myInt);   
				}
			    	break; 

			case 6: 
				if (darraySort(dArr,compare))
				{
				    printf("Sorting Failed !!! \n");
				}		    
			    	break;           
			case 7:
				printDarray(dArr, print);
				printf("\n");
				break;
			default: 
				cont = 0;		    
			    	break;
			}
	}
	darrayDestroy(dArr,destroy,fp);
}

void destroyInt(void* _elem, void* context)
{
    	FILE* fp = (FILE*) context;
	int* n = (int*) _elem;
	
	fprintf(fp,"%d ", *n);
	
}

void printInt(void* _elem)
{
	int n = *((int*) _elem);
	printf("%d ", n);
}

int compareInt(void *_elemA, void *_elemB)
{
	int *a =(int*) _elemA;
	int *b =(int*) _elemB;
	return a-b;
}








