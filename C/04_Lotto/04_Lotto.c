#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void pickNums(int,int);

int main(){
	pickNums(6,11);
}

void pickNums(int rows, int cols){
	
	char arr[6][11] = {
			{' ','1','2','3','4','5','6','7','8','9','0'},
			{'0','-','-','-','-','-','-','-','-','-','-'},
			{'1','-','-','-','-','-','-','-','-','-','-'},
			{'2','-','-','-','-','-','-','-','-','-','-'},
			{'3','-','-','-','-','-','-','-','-','-','-'},
			{'4','-','-','-','-','-','-','-','-','-','-'}};
				
	int i=0;
	int conductNumbers =0;
	int randNum[6] = {0,0,0,0,0,0};
	int row=0,col=0;
	
	

	srand (time(NULL));
	for (i=0;i<6;i++){	
	  	randNum[i] = rand() % 49 + 1;
	}
	for (i=0;i<6;i++){
		arr[randNum[i]/10+1][randNum[i]%10+1] = '+';
	}
	
	for (row=0;row<rows;row++){
		printf("\n");
		for (col=0;col<11;col++){
			printf("%c",arr[row][col]);
		}
	}
	printf("\n");
}
