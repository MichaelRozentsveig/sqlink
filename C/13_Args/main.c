#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Header.h"

int main (int argc, char* argv[]){

	int age;
	char* name;
	if (argc==3){
		if (isNum(argv[1]) && isString(argv[2])){
			printf("%s is %d years old\n",argv[2], atoi(argv[1]));
		}else if (isNum(argv[2]) && isString(argv[1])){
			printf("%s is %d years old\n",argv[1], atoi(argv[2]));
		}else{
			printf("Bad input\n");
		}	
	}
	return 0;
}
	


