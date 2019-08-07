#include <stdio.h>

void sortArray(int[],int);
void swap(int*, int*);

int main(){
	int i=0;
	int arr[8] = {0,4,5,1,5,2,3,-1};
	sortArray(arr,8);
	for (;i<8;i++){
		printf("%d",arr[i]);
	}

}

void sortArray(int arr[], int size){
	int current =0, next=1;
	int i=0;
	
	for (;current<size;current++){
		for(next=current+1;next<size;next++){
			if (arr[current] > arr[next]){
				swap(&arr[current],&arr[next]);
			}
		}
	}
}

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y =temp;
}
