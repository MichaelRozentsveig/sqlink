#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* strCombine(char*, char*);
char* strCopy(char*, char*);
int strCompare(char*, char*);

int main(){
	
	char s1[32] = "mike ";
	char s2[32] = "roz";
	
	char* combined = NULL;
	int compare = 0;
	char* copy = NULL;

	combined = strCombine(s1,s2);
	printf( " %s \n", combined);
	
	compare = strCompare(s1,s2);
	printf( " %d \n", compare);

	copy = strCopy(s1,s2);
	printf( " %s \n", copy);
	
	
	return 0;
}



char* strCombine(char* s1, char* s2){
	
	int i=0;
	int j = strlen(s1);
	char* dest = s1+j;

	while( s2[i] != '\0'){
		dest[i] = s2[i];
		i++;
	}
	dest[j] = '\0';
	
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
