#include <stdio.h>
#include <string.h>

#include "Header.h"


int main(){

	unsigned char num = 0, secNum =0 ;
	unsigned char ansStr [8];
	unsigned char ans=0;
	int rotator =0, value =0;
	int startIndex=0, endIndex=0;
	int p=0,n=0;
	int cont = 1;
	unsigned int option = 0;
	
		
	while (cont) {

		printf("Choose option: \n");
		printf("1: Invert Bits  \n"); 
		printf("2: Rotate Bits   \n");
		printf("3: Set Bits  \n");
		printf("4: Set Bits from Y \n");
		printf("Any other number - Stop \n");
		
		scanf("%u", &option);
		switch(option)
		{									                                   
			case 1: num = 170;
				if (invertBits(&num)==0){
					printf("Failed\n");
				}
				printf("\n");
				break;

			case 2: num = 170;
				printf("Insert num of bits to rotate:\n");
				scanf("%d", &rotator);
				if (!rotateBits(&num,rotator)){
					printf("Failed!\n");
				}
				printf("\n");
	 			break;

			case 3: num =170;
				printf("Insert start index, end index and value (0 or 1):\n");
				scanf("%d%d%d", &startIndex,&endIndex,&value);
				if (!setBits(&num,startIndex,endIndex,value)){
					printf("Failed!\n");
				}
				printf("\n");
				break;

			case 4: num=170,secNum=167;
				printf("Enter end index and number of values you want to change:\n");
				scanf("%d%d",&p,&n);
				if (!setBitsFromY(&num,p,n,&secNum)){
					printf("Failed!\n");
				}
				printf("\n");
				break;

			default: 
				cont =0;
				break;
			printf("\n");
		}
	}
	
}
