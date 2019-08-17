#include <stdio.h>
#include <stdlib.h>
#include "Header.h"


int main(){
	binary binFunc[3]={BitOn,BitOff,BitStatus};
	BitMap* bmPtr = NULL;

	int cont = 1;		/* trigger to stop loop	*/
	unsigned int option=0;
	int numOfFeatures=0;
	int ans = 0;
	int bitIndex=0;

	printf("Enter number of Features:\n");
	scanf("%d",&numOfFeatures);
	bmPtr= createBitMap(numOfFeatures);

	while (cont) {

		printf("Enter bit index:\n");
		scanf("%d", &bitIndex);

		printf("Choose option: \n");
		printf("0: Turn on Bit  \n"); 
		printf("1: Turn Off bit   \n");
		printf("2: Check Bit Status  \n");
		printf("Any another number - stop \n");
		
		scanf("%u", &option);
		
		if (option>2 || option<0){
			break;
		}
		ans =binFunc[option](bitIndex,bmPtr);
		
		if (ans == -1){
			printf("Failed \n");
		}else if (ans==1&&option==2){
			printf("%d bit is ON \n", bitIndex);
		}else if (ans==0){
			printf("%d bit is Off \n", bitIndex);
		}
	
		printBitNum(bmPtr);
		printf("\n");
	}
	destroyBM(bmPtr);
}
