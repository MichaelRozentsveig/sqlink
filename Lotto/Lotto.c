#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pickNums(char[][11],int );

int main(){
	int row =0,col=0;
	char arr[6][11] = {
			   {' ','1','2','3','4','5','6','7','8','9','A'},
			   {'0','-','-','-','-','-','-','-','-','-','-'},
			   {'1','-','-','-','-','-','-','-','-','-','-'},
			   {'2','-','-','-','-','-','-','-','-','-','-'},
			   {'3','-','-','-','-','-','-','-','-','-','-'},
			   {'4','-','-','-','-','-','-','-','-','-','-'}};
	
	pickNums(arr,11);
	for (row=0;row<6;row++){
		printf("\n");
		for (col=0;col<11;col++){
			printf("%c",arr[row][col]);
		}
	}
	printf("\n");
}

void pickNums(char arr[][11],int size){
	int i=0;
	int randNum[6] = {0,0,0,0,0,0};
	srand (time(NULL));
	for (;i<6;i++){	
	  	randNum[i] = rand() % 49 + 1;
	}
	for (i=0;i<6;i++){
		arr[randNum[i]/10+1][randNum[i]%10+1] = '+';
	}
}
