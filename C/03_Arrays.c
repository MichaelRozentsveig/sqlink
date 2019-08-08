#include <stdio.h>

void sortArray(int[],int);
void swap(int*, int*);
void sort(int[],int);
void ascendOddAndEven(int[],int);
int mostFrequent(int [],int );
int main(){

	int i=0, ans=0;
	
	int arr1[8] = {0,4,5,1,5,2,3,-1}; /* Sort */
	int arr2[8] = {0,1,0,1,1,1,0,0}; /* Binary array*/
	int arr3[8]= {1,2,3,4,5,6,7,8}; /* Even and odd sort*/
	int arr4[11] = {3,6,8,3,9,12,45,9,12,56,12}; /*Most frequent value*/
	
	
	sortArray(arr1,8);
	for (i=0;i<8;i++){
		printf("%d",arr1[i]);/* Printing the first Exercise*/
	}
	printf("\n");

	sort(arr2,8);
	for (i=0;i<8;i++){
		printf("%d",arr2[i]); /*Printing Second Exercise*/
	}
	printf("\n");

	ascendOddAndEven(arr3,8);
	for (i=0;i<8;i++){
		printf("%d",arr3[i]);/*Printing Third Exercise*/	
	}
	printf("\n");
	
	ans = mostFrequent (arr4,11);
	printf("%d\n",ans); /*Printing Last Exercise*/
	
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

void sort(int arr[], int n) { 
	int count = 0;
	int i =0;

	for (i = 0; i < n; i++) { 
		if (arr[i] == 0){
			count++; 
		}
	} 
	for (i = 0; i < count; i++){
		arr[i] = 0; 
	} 
	for (i = count; i < n; i++){
		arr[i] = 1;
	} 
} 

void ascendOddAndEven(int arr[],int size){
	int i=0,j=0;
	int temp =0;
	int mover=0;
	for(i=1;i<size;i++){
		for(j=0;j<i;j++){
			if((arr[j]%2)!=0 && (arr[i]%2)==0){
				temp=arr[j];
				arr[j]=arr[i];
				for(mover =i;mover>j;mover--)
				arr[mover]=arr[mover-1];
				arr[mover+1]=temp;
           		}
         	}
	}
}

int mostFrequent(int arr[],int size){
	int max = 0, counter = 1;
	int num = 0, currentNum = 0;
	int i=0, j=0;
	for(i = 0; i < size-1; i++){
		currentNum = arr[i];
	    	for(j =i+1; j < size; j++){
			if(currentNum == arr[j] && num != currentNum){
		    		counter++;
			}
    		}
   		if(max < counter){
        		max = counter;
        		counter = 1;
        		num = currentNum;
    		}
	}
	return num;
}
