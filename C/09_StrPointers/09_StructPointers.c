#include <stdio.h>
#include <stdlib.h>

#include "Header.h"

int insert(struct DA_t* dptr, int* num){


	struct DA_t* temp=dptr;
	int i=0;
	if (((dptr->index)+1)>(dptr->capacity)){ /*checks if we reached the end of the array*/
		temp->arr = dptr->arr;		 /* If yes, reallocation is needed*/
		temp->arr = (int**)realloc(dptr->arr,((dptr->index)*2)*sizeof(int*));
		
		(dptr->capacity)*=2; 

		if (temp->arr == NULL){ /* In case reallocation failed*/
			printf("Not enough memory"); 
			dptr->arr = temp->arr;
			return 0;
		}
	}
	(dptr->arr)[(dptr->index)++] = num;
	return 1;
}

struct DA_t* createDA(int capacity){

	struct DA_t* dptr= (struct DA_t*) malloc (sizeof(struct DA_t));/*Asks for location for the struct*/ 
	if (!(dptr)){
		return NULL;
	}
	
	dptr->arr = (int**) malloc (capacity* sizeof (int*));/*Asks for location for the array*/
	if (!(dptr->arr)){
		free(dptr);
		return NULL;
	}
	
	dptr->capacity = capacity;	
	dptr->index=0;
	
	return dptr;
}

void printDA(struct DA_t* dptr){ /*Prints all the values in the array*/
	
	int i=0;
	if(!(dptr)){return;}

	for (; i<(dptr->index); i++){
		printf("%d, ", *(dptr->arr[i]));
	}
	printf("\n");
}

void destroy(struct DA_t* a){ /*Frees the memory of the struct and the array*/
	
	int i=0;
	if (!(a)) {return;}

	for (;i<a->index;i++){
		free(a->arr[i]);
		free(a);
	}
}











