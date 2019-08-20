#include <stdio.h>
#include <stdlib.h>
#include "darray_int.h"

int main()
{
    unsigned int option = 0;
    int cont  = 1;
    int item  = 1;
    int myInt = 0, myIndex = 0;

    int initial_capacity =0;

    darray *dArr;

    printf("Insert capacity: \n");
    scanf("%d", &initial_capacity);

    if (darrayCreate(&dArr,initial_capacity))
    {
        printf("Creation Failed !!! \n");
        return AllocationError;
    }

    while (cont)
    {
        printf("Choose option:       \n");
        printf("1: Add item          \n");
        printf("2: Delete item       \n");
        printf("3: Get item          \n");
        printf("4: Set item          \n");
        printf("5: Number of items   \n");
        printf("6: Sort array        \n");

        scanf("%u",&option);
        switch (option)
        {
        case 1: 
                printf("Insert item: \n");
                scanf("%d",&item);
                if (darrayAdd(dArr,item))
                {
                    printf("Adding Failed !!! \n");
                }
            
            break;

        case 2: 
                if (darrayDelete(dArr,  &myInt))
                {
                    printf("Deleting Failed !!! \n");
                }
                else
                {
                    printf("%d\n",myInt);   
                }
                
            break;

        case 3: 
                printf("Insert the index of the item you want to get:\n");
                scanf("%d",&myIndex);

                if (darrayGet(dArr,myIndex,&myInt))
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
                scanf("%d",&myIndex);

                if (darraySet(dArr,myIndex,myInt))
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
                if (darraySort(dArr))
                {
                    printf("Sorting Failed !!! \n");
                }
            
            break;            
        
        default: 
                cont = 0;
            
            break;
        }
    }
    return darrayDestroy(dArr); 
}