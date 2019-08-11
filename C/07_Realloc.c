#include <stdio.h>
#include <stdlib.h>

int* insert(int num, int* arr, int* index, int *capacity);

int main(){
	
	int capacity = 0;
	int num = 0;
	int index = 0;
	int* arr = 0;
	int i=0;

	printf("Enter size of array: \n");
	scanf("%d", &capacity);
	arr = (int*) malloc(capacity *sizeof(int));

	while(1){
		printf("Insert number: (Negative to exit)\n");
		scanf("%d",&num);
		if (num<0) {break;}
		insert(num, arr, &index, &capacity);
	}
	for (i=0;i<index;i++){
		printf("%d", arr[i]);
	}
}

int* insert(int num, int* arr, int* index, int *capacity){
	
	int *temp=arr;
	int i=0;
	if (((*index)+1)>(*capacity)){
		temp = arr;
		temp = (int*)realloc(arr,((*index)*2)*sizeof(int));
		(*capacity)*=2;
		if (arr == NULL){
			printf("Not enough memory"); 
			arr = temp;
		}
	}
	arr[(*index)++] = num;
	return arr;
}


