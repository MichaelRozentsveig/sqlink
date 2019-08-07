#include <stdio.h>

void sortArray(int[],int);
void swap(int*, int*);
int mostFrequent(int[],int);

int main(){
	int i=0;
	int ans=0;
	int arr[11] = {3,6,8,3,9,12,45,9,12,56,12};
	ans = mostFrequent (arr,11);
	printf("%d\n",ans);
}

int mostFrequent(int arr[],int size){
	int i=0;
	int counter=1, max=0;
	int current=0,next=1;
	int most=0;
	sortArray(arr,size);
	for (;current<size;current++){
		if (arr[current] == arr[current+1]){
			counter++;
		}else if(counter > max){
			max = counter;
			most = arr[current];
		}
		counter=1;
	}
	return most;
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
