#include <stdio.h>
#include <stdlib.h>

#include "Header.h"

typedef int l;

int main(){
	
	int capacity=0, num=0;
	struct DA_t* dynArrSt = NULL;
	
	printf("Enter Size of Array:\n");
	scanf("%d",&capacity);

	dynArrSt = createDA(capacity); /*Creates new struct with new array (size of capacity)*/

	while(1){
	
		printf("Insert number: (-1 to exit)\n");
		scanf("%d",&num);

		if (num==-1) {break;}
		insert(dynArrSt, num); /* adding num to the array*/
	}
	printf("\n");

	printDA(dynArrSt); /*Printing the array */
	
	destroy(dynArrSt); /*Free array and struct*/
}


