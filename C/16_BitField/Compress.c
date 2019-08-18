#include <stdio.h>
#include <string.h>

#include <stdlib.h>
#include "Header.h"
union un Union;
int compress( char* str){

	int i=0,mover=0, ans=0;
	if (!str){
		return 0;
	}
	ans = strlen(str);
	for (i=0;i<strlen(str);i++){
		str[i]-='a';	
	}
	str[0]<<=4;
	str[0]|=str[1];
	str[1]=0;

	for (i=2;i<=strlen(str)+1;i+=2){
		str[i]<<=4;
		str[i] |=str[i+1];
		str[i+1]=0;
		str[i-1-mover]=str[i];
		mover++;
	}
	return ans;
}

void decimalToBinChar(char decimal) { 
	
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

int compressUnion(char* str){

	int ans = strlen(str);
	int i=0,j=0;
	for (i=0;i<strlen(str)/2+1;i++){
		Union.lr.left = (str[i+j] - 'a');
		Union.lr.right = (str[i+1+j] - 'a');
		str[i] = Union.c;
		j++;
	}

	return ans;
}








