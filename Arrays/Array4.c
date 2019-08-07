#include <stdio.h>

void swap(int*, int*);
void ascendOddAndEven(int[],int);

int main(){

	int i=0;
	int arr[8]= {1,2,3,4,5,6,7,8};
	
	ascendOddAndEven(arr,8);

	for (;i<8;i++){
		printf("%d",arr[i]);	
	}

}

void ascendOddAndEven(int arr[], int size){
	int current = 0;
	int next = 1;
	for (;current<size;current++){
		for(next=current+1;next<size;next++){
			if (arr[current]%2==1 && arr[next]%2==0){
				swap(&arr[current],&arr[next]);
			}		
		}	
	}
}
	
void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}
