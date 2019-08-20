#include <stdio.h>
#include <stdlib.h>
#include "darray_int.h"

struct darray
{
    size_t m_capacity;
    size_t m_lastIndex;
    int* m_arr;
    size_t m_initial_capacity;
};

/* Create a new dynamic array. Return its address in d_arr.
   The initial capacity is the number of items that can be stored
   before a new allocation is needed. */

AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{
    *dArr = malloc(sizeof(darray));
    if (!(*dArr))
    {
        return AllocationError;
    }
    (*dArr)->m_arr = malloc(sizeof(int)*initial_capacity);
    if (!((*dArr)->m_arr))
    {
        free(*dArr);
        return AllocationError;
    }
     (*dArr)->m_lastIndex =  0;
     (*dArr)->m_capacity  =  initial_capacity;
     (*dArr)->m_initial_capacity = initial_capacity;
     return OK;
}

AdtStatus darrayDestroy(darray *dArr)
{
    if (!dArr)
    {
            return AllocationError;
    }
    free(dArr->m_arr);
    free(dArr);
    return OK;
}

/* Add number to the end. */

AdtStatus  darrayAdd(darray *dArr,  int  _item)
{
    int* tempArr;

    if (!dArr)
    {
            return AllocationError;
    }
    if (dArr->m_lastIndex == dArr->m_capacity)
    {
        tempArr = realloc((dArr->m_arr),sizeof(int)*(dArr->m_capacity)*2);
        if (!tempArr)
        {
            return AllocationError;
        }
    }
    *dArr->m_arr = *tempArr;
    dArr->m_capacity*=2 ;
    dArr->m_arr[dArr->m_lastIndex] = _item; /*Segmentation fault !! */
    dArr->m_lastIndex++ ;
    return OK;
}

/* Delete number from the end, hand-over the deleted item 
   in a variable pointed to by _item */

AdtStatus   darrayDelete(darray *dArr,  int* _item)
{
    if (!dArr)
    {
        return AllocationError;
    }
    *_item = dArr->m_arr[dArr->m_lastIndex];
    dArr->m_lastIndex--;
    if (dArr->m_lastIndex == 0)
    {
        return AllocationError;
    }
    if ((dArr->m_lastIndex         <=   dArr->m_capacity/3)   && 
        (dArr->m_initial_capacity  <    dArr->m_capacity/2))
    {
        dArr->m_arr = realloc(dArr->m_arr, sizeof(int)*(dArr->m_capacity/2));
        dArr->m_capacity /=2;
    }
    return OK;
}

AdtStatus   darrayGet(darray *dArr, size_t _index, int *_item)
{
    if (!dArr || _index > dArr->m_lastIndex)
    {
        return AllocationError;
    }
    *_item = dArr->m_arr[_index];
    return OK;
}

AdtStatus   darraySet(darray *dArr, size_t _index, int  _item)
{
     if (!dArr || _index > dArr->m_lastIndex)
    {
        return AllocationError;
    }
    dArr->m_arr[_index] = _item;
    return OK;
}

AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems)
{
    if (!dArr)
    {
        return AllocationError;
    }
    *_numOfItems = dArr->m_lastIndex;
    return OK;
}

/* in place (ascending) sorting an array of size arraySize */

AdtStatus darraySort(darray *dArr)
{
    int temp = 0 ;
    int i = 0 , j = 0 ;
    int sorted_check=0;

    if (!dArr)
    {
        return AllocationError;
    }

    for (i=0; i <dArr->m_lastIndex-1; i++)
    {
        for (j=0;j<dArr->m_lastIndex-i-1; j++)
        {
            if (dArr->m_arr[j] > dArr->m_arr[j+1])
            {
                temp = dArr->m_arr[j];
                dArr->m_arr[j] = dArr->m_arr[j+1];
                dArr->m_arr[j+1] = temp;
                sorted_check == 1;
            }
        }

        if (sorted_check ==0)
        {
            break;
        }
    }
    return OK;
}
