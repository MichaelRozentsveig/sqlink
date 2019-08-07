#include <stdio.h>

void sort(int[],int);

int main(){

	int i =0 ;

	int arr[8] = {0,1,0,1,1,1,0,0};

	sort(arr,8);
	
	for (;i<8;i++){
		printf("%d",arr[i]);
	}
}


void sort(int arr[], int n) 
{ 
    int count = 0;
    int i =0;

    for (i = 0; i < n; i++) { 
        if (arr[i] == 0) 
            count++; 
    } 
    for (i = 0; i < count; i++) 
        arr[i] = 0; 
  
    for (i = count; i < n; i++) 
        arr[i] = 1; 
} 
