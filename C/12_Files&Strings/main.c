#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "Header.h"


int main(){ 
	char filName [30];
	int N, cont=1;
	unsigned int option=0;
	while(cont){
		printf("\n");
		printf("Choose option: \n");
		printf("1: To recieve last N lines of a file \n");
		printf("2: Character counter\n");
		printf("3: Word counter \n");
		printf("Any other number - Stop \n");
		scanf("%u",&option);
		switch(option){
			case 1:
				printf("Insert your file name ");
				scanf("%s",filName);
				printf("Insert How many last lines you want to see ");
				scanf("%d",&N);
				lastNlines(N,filName);

				break;

			case 2:
				printf("Please insert file name: ");
				scanf("%s",filName);
				charCount(filName);

				break;

			case 3:	
				printf("Please insert file name: ");
				scanf("%s",filName);
				wordCount(filName);
				
				break;

			default: cont=0;
				break;
		}
	}
	return 0;
}
