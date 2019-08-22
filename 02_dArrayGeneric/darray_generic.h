#ifndef H_DARRAY
#define H_DARRAY

#include <stdlib.h>

typedef enum  {OK, AllocationError} AdtStatus; 

typedef void (* elementDestroy)(void *_elem, void *context);
typedef int (* elementCompare)(void *_elemA, void *_elemB);
typedef void(* elementPrint)(void* _elem);

/* forward declaration of the darray type */

typedef struct darray darray;

/* Create a new dynamic array. Return its address in d_arr.
   The initial capacity is the number of items that can be stored
   before a new allocation is needed. */

AdtStatus darrayCreate(darray **dArr, int initial_capacity);
AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context);

/* Add number to the end. */
AdtStatus   darrayAdd(darray *dArr,  void  *_item);

/* Delete number from the end, hand-over the deleted item 
   in a variable pointed to by _item */
AdtStatus   darrayDelete(darray *dArr,  void **_item);
AdtStatus   darrayGet(darray *dArr, size_t _index, void **_item);
AdtStatus   darraySet(darray *dArr, size_t _index, void  *_item);
AdtStatus   darrayItemsNum(darray *dArr, int*  _numOfItems);

/* in place (ascending) sorting an array of size arraySize */
AdtStatus darraySort(darray *dArr,elementCompare compareFunc ); /* correct this !!! */
AdtStatus printDarray(darray* dArr, elementPrint printFunc);
#endif