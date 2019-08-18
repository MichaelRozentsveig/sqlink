#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include "Header.h"

 

int main(){
	int i=0,size;
	char num;
	int ans=0;
	char strRegular[6]="bbbbbb";
	char strUnion[4] = "bbbb";
	
	compress(strRegular);
	compressUnion(strUnion);
	
	
	for(i=0;i<4;i++){
		decimalToBinChar(strRegular[i]);
	}
	printf("\n");

	for(i=0;i<3;i++){
		decimalToBinChar(strUnion[i]);
	}
	printf("\n");


}
