#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

void destroyBM(BitMap* bm){
	int i=0;
	if (bm) {
		free(bm->m_arrFeatures);
		free(bm);
	}
}

int BitOn(int n, BitMap* bmPtr){
	unsigned char turnOnBit = 1;
	char index =0, offset=0;

	if (n > (bmPtr->m_numOfFeatures)){
		return -1;
	}
	index = (n%8==0) ? (n/8 -1) : (n/8);
	offset = (n>0 && n%8==0) ? 8 : n%8 ;
	
	turnOnBit <<= (offset);
	bmPtr->m_arrFeatures[index] = (bmPtr->m_arrFeatures[index] | turnOnBit);
	return 1;	
}

int BitOff(int n, BitMap* bmPtr){
	unsigned char turnOffBit = 1;
	char index=0, offset=0;
	
	if (n > bmPtr->m_numOfFeatures){
		return -1;
	}
	index = (n%8==0) ? (n/8 -1) : (n/8);
	offset = (n>0 && n%8==0) ? 8 : n%8 ;
	
	turnOffBit <<= (offset);
	turnOffBit =~ turnOffBit;

	bmPtr->m_arrFeatures[index] = (bmPtr->m_arrFeatures[index] & turnOffBit);
	return 1;
}

int BitStatus(int n, BitMap* bmPtr){
	unsigned char checkBit = 1;
	/*unsigned char ans ;*/
	char index=0, offset=0;
	
	if (n > bmPtr->m_numOfFeatures){
		return -1;
	}

	index = (n%8==0) ? (n/8) -1 : (n/8);
	offset = (n>0 && n%8==0) ? 8 : n%8 ;
	checkBit <<= offset;
	
	if (checkBit == bmPtr->m_arrFeatures[index]){
		return 1;
	}else {
		return 0;
	}
}

void printBitNum(BitMap* bmPtr){
	int i=0,size;
	unsigned int num;
	if(bmPtr!=NULL){
		size=(bmPtr->m_numOfFeatures%8>0)?(bmPtr->m_numOfFeatures/8+1):(bmPtr->m_numOfFeatures/8);
		for(i=size-1; i>=0;i--){
			num=(bmPtr->m_arrFeatures[i]);
			decimalToBinChar(num);
		}
	}
	printf("\n");

}


static void decimalToBinChar(unsigned char decimal) { 
	
	int i=0;
	char binArr[256];
	
	while (decimal > 0){ 
	   		binArr[i] = decimal % 2 + '0'; 
			decimal= decimal / 2;  
			i++;
		}
	binArr[i]='\0';

	for (i=8;i>=0;i--){
		if (i<=strlen(binArr)){		  
			printf("%c",binArr[i]);
		}else{
			printf("%c",'0');
		
		}
	} 	 
} 

BitMap* createBitMap(int numOfFeatures){
	
	BitMap * bmPtr = malloc (sizeof(BitMap));

	if (!(bmPtr)){
		return NULL;
	}

	bmPtr->m_arrFeatures = calloc ((numOfFeatures/8)+1 , sizeof(unsigned char));
	
	if (!(bmPtr->m_arrFeatures)){
		free(bmPtr);
		return NULL;
	}
	bmPtr->m_numOfFeatures = numOfFeatures;	

	return bmPtr;
}






