#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Header.h"

int isString(char* str){
	int i=0;
	for (i=0;i<strlen(str);i++){
		if (!isalpha(str[i])){
			return 0;
		}
	}
	return 1;
}

int isNum(char* num){
	int i=0;
	for (i=0;i<strlen(num);i++){
		if (!isdigit(num[i])){
			return 0;
		}
	}
	return 1;
}
