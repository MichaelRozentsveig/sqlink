#include <stdio.h>
#include <stdlib.h>
#include "darray_generic.h"

/* forward declaration of the darray type */

struct darray
{
	size_t m_initial_capacity;
	size_t m_current_capacity;
	void** m_arr_of_elements;
	size_t m_last_index;
};

/* Create a new dynamic array. Return its address in d_arr.
The initial capacity is the number of items that can be stored
before a new allocation is needed. */

AdtStatus darrayCreate(darray **dArr, int initial_capacity)
{
	*dArr = malloc(sizeof(darray));
	if (!(*dArr))
	{
		return AllocationError;
	}
	(*dArr)->m_arr_of_elements = malloc(sizeof(void*)*initial_capacity);
	if (!((*dArr)->m_arr_of_elements))
	{
		free(*dArr);
		return AllocationError;
	}
	(*dArr)->m_last_index =  0;
    	(*dArr)->m_current_capacity  =  initial_capacity;
    	(*dArr)->m_initial_capacity = initial_capacity;
    	return OK;
}

AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context)
{
	int i=0;

	if (!dArr)
	{
		return AllocationError;
	}
	for (i=0;i<dArr->m_last_index;i++)
	{	
		destroyFunc(dArr->m_arr_of_elements[i], context);
	}
	return OK;
}

/* Add number to the end. */
AdtStatus   darrayAdd(darray *dArr,  void  *_item)
{
	void **tempArr;
	if (!dArr)
	{
		return AllocationError;
	}
	if (dArr->m_last_index == dArr->m_current_capacity)
	{
		tempArr = realloc((dArr->m_arr_of_elements),sizeof(void*)*(dArr->m_current_capacity)*2);
		if (!tempArr)
		{
	    		return AllocationError;
		}
		dArr->m_arr_of_elements = tempArr;
		dArr->m_current_capacity*=2 ;
	}
	
	dArr->m_arr_of_elements[dArr->m_last_index] = _item; 
	dArr->m_last_index++ ;
	return OK;
}

/* Delete number from the end, hand-over the deleted item 
in a variable pointed to by _item */

AdtStatus   darrayDelete(darray *dArr,  void **_item)
{
	if (!dArr)
	{
		return AllocationError;
	}

	*_item = dArr->m_arr_of_elements[dArr->m_last_index];
	dArr->m_last_index--;

	if (dArr->m_last_index == 0)
	{
		return AllocationError;
	}
	if ((dArr->m_last_index         <=   dArr->m_current_capacity/3)   && 
	    (dArr->m_initial_capacity  <    dArr->m_current_capacity/2))
	{
		dArr->m_arr_of_elements = realloc(dArr->m_arr_of_elements, sizeof(int)*(dArr->m_current_capacity/2));
		dArr->m_current_capacity /=2;
	}
	return OK;
}

AdtStatus   darrayGet(darray *dArr, size_t _index, void **_item)
{
	if (!dArr || _index > dArr->m_last_index)
	{
		return AllocationError;
	}
	*_item = dArr->m_arr_of_elements[_index];
	return OK;
}

AdtStatus   darraySet(darray *dArr, size_t _index, void  *_item)
{
	if (!dArr || _index > dArr->m_last_index)
	{
		return AllocationError;
	}
	dArr->m_arr_of_elements[_index] = _item;
	return OK;
}

AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems)
{
	if (!dArr)
	{
		return AllocationError;
	}
	*_numOfItems = dArr->m_last_index;
	return OK;
}

/* in place (ascending) sorting an array of size arraySize */
/*AdtStatus darraySort(darray *dArr); correct this !!! */

int partition(darray* dArr, int low, int high, elementCompare compareFunc)
{
	void* pivot = dArr->m_arr_of_elements[high];
	int i = (low-1);
	int j = 0 ;
	
	void* temp ;

	for (j=low; j<=high-1; j++)
	{
		if (compareFunc(dArr->m_arr_of_elements[j],pivot))
		{
			i++;
			temp = dArr->m_arr_of_elements[i];
			dArr->m_arr_of_elements[i] = dArr->m_arr_of_elements[j];
			dArr->m_arr_of_elements[j] = temp;
		}
	}
	temp = dArr->m_arr_of_elements[i+1];
	dArr->m_arr_of_elements[i+1] = dArr->m_arr_of_elements[high];
	dArr->m_arr_of_elements[high]= temp;

	return (i+1);
}

void quickSort(darray* dArr, int low, int high, elementCompare compareFunc)
{
	int part_index = 0;
	if (low<high)
	{
		part_index = partition(dArr,low,high, compareFunc);
		quickSort(dArr,low,part_index-1, compareFunc);
		quickSort(dArr,part_index+1,high, compareFunc);
	}
}
AdtStatus darraySort(darray *dArr,elementCompare compareFunc )
{
	if(!dArr)
	{
		return AllocationError;
	}
	quickSort(dArr,0,dArr->m_last_index,compareFunc);
	return OK;
}

AdtStatus printDarray(darray* dArr, elementPrint printFunc)
{
	int i = 0;
	if (!dArr)
	{
		return AllocationError;
	}
	for(i=0;i<dArr->m_last_index;i++)
	{
		printFunc(dArr->m_arr_of_elements[i]);
	}
	return OK;
}










