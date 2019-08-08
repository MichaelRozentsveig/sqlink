#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strCombine(char*, char*);
char* strCopy(char*, char*);
int strCompare(char*, char*);

int main(){
	
	char s1[] = "mike";
	char s2[] = "roz";
	
	char* combined = strCombine(s1,s2);
	int compare = strCompare(s1,s2);
	char* copy = strCopy(s1,s2);

	printf( " %s \n %d \n %s \n", combined, compare, copy ); 
	
	return 0;
}



char* strCombine(char* s1, char* s2){
	
	int i=0,j=strlen(s1);
	char* result = s1+j;

	
	for(; s2[i] != '\0'; i++){
		result[i+j] = s2[i];
	}
	result[j] = '\0';
	
	return s1;
}	

int strCompare(char* s1, char* s2){
	int result = 0, i =0;
	for (i=0 ; i<strlen(s1);i++){
		if (s1[i] != s2[i]){
			break;
		}
	}
	i++;
	result = s1[i] -s2[i];

	return result;
}

char* strCopy(char* dest, char* src){
	int i=0;
	char* result =dest;
	for (i=0;src[i]!='\0';i++){
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return result;
}
