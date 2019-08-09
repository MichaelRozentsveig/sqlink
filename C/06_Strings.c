#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void decToBin();
int binToDec();
void squeeze();

int main(){

	int cont = 1;			/* trigger to stop loop	*/
	unsigned int option;

	while (cont) {
		printf("Choose option: \n");
		printf("1: Decimal to Binary  \n"); 
		printf("2: Binary to Decimal   \n");
		printf("3: Squeezer  \n");
		printf("4: Location  \n");
		printf("Any another number - stop \n");

		scanf("%u", &option);

		switch (option) {

			case 1:	decToBin();	break;
			case 2: binToDec();	break; 
			case 3: squeeze(); 	break;
			case 4: location();	break;
			default: cont = 0;	break;
		}
	}
}


void decToBin() { 
	char* strNum;
	int i=0, j=0;
	int binArr[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int num=0;
	int flag = 1, k=0;
	int checkNum=0, counter=1;

	while(flag){ /* To cause the program to work as infinitive loop until negative value is scanned */  

		printf("Please insert a decimal number up to 2^32-1: (Negative number to exit) \n");	
		scanf("%s",strNum);

		for(i=0; i<strlen(strNum);i++){ /* Checking for non-decimal characters*/
			if (isalpha(strNum[i])){
				printf("You entered an illegal value\n");
				flag=0;break;
			}
		}
		if (flag==0) {break;}

	    	num = atoi (strNum); /* String to Integer */
		
		if (num<0){flag=0; break; } /* Exits for negative number*/
		i=0;
	    	while (num > 0){ 
	   		binArr[i] = num % 2; 
			num= num / 2;  
			i++;
		} 

	    	for (j = i - 1; j >=0; j--){ 
			printf("%d", binArr[j]);
		}
		for (i=0 ; i<32; i++){ /*Initializing the number for the next Run*/
			binArr[i] =0;
		}
		i=0;
		counter=0;
		printf("\n");
	}	 
} 		



int binToDec(){
	char num[32] ;
	char num1[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int result = 0, i = 0;
	int rightBit = 0, rightBit1 = 0;
	int base = 1;
	int flag = 1;
	int numSize= 0;
	
	while(flag){/* To cause the program to work as infinitive loop until negative value is scanned */

		printf("Please insert a binary number: (Negative number to exit) \n");	
		scanf("%s",num);
		if (num[0] == '-'){flag=0; break; } /* Exits for negative number*/
		
		for (i=0; num[i]!= '\0';i++){
			num1[i] = num[i];  /* num is used to check for the correctness of the value */
		}	  		   /* num1 is used to create the decimal number*/
		 		
		for (i=0;num[i]!= '\0';i++){
			if (num[i] != '0' && num[i] != '1'){
				printf("You entered an illegal value\n");
				flag=0;break;
			}
		}
		if (flag==0) {break;}
		i=0;
		numSize = strlen(num1);
		for(i=numSize-1;i>=0;i--){
			if (num[i] =='1'){
				result += base;
			}
			base*=2;
		}
		printf("%d\n", result);

		result=0; /*Initializing the number for the next Run*/
		base=1;
	}	
}



void squeeze(){
	int i=0, j=0;
	char  mainStr[100], squeezer[100];
	int remove[256]; /* Number of all possible characters*/
	
	for (i=0;i<256; i++){
		remove[i]=0;
	}
	
	printf("Please insert the string you would like to squeeze:  \n");	
		scanf("%s",mainStr);

	printf("Please insert the characters you would like to remove:  \n");	
		scanf("%s",squeezer);

	if (mainStr == NULL || squeezer == NULL){ /* Empty strings*/
		printf("%s", mainStr);
		return;
	}
	
	for (i=0 ; i<strlen(squeezer); i++){ /* Turns on the ascii number of the char */
		remove[squeezer[i]] = 1;
	}
	i=0;
	while( i<strlen(mainStr)){
		if (remove[mainStr[i]] == 1){ /* Checks if the current char should be removed */
			for (j=i;j<strlen(mainStr);j++){ /* Shift right*/
				mainStr[j] = mainStr[j+1];
			}
		} else {i++;}
	}
	mainStr[i] = 0 ; /* End of string */
	printf("Your output is: %s\n", mainStr);
}



int location(){

	char mainStr[100], subStr[100];
	int i=0,j=0;
	int ans = -1 ; /* Initialized as "Not Found" */

	printf("Please insert your whole string:  \n");	
		scanf("%s",mainStr);

	printf("Please insert substring to find his location in the whole string:  \n");	
		scanf("%s",subStr);

	if (strlen(subStr) > strlen(mainStr)){ 
		printf("-1\n");
		return;
	}

	while (i< strlen(mainStr)-strlen(subStr)+1){
		while (j<strlen(subStr)+1){
			if (mainStr[i] == subStr[j]){
				i++;
				j++;
				if (subStr[j] == '\0'){ /* Means the string contains the substring */
					ans = i-strlen(subStr); /* going back to the beginning of the substring*/
				}
			} else {
 				j=0; i++;  break;
			}
		}
	}
	if (ans!=-1){
		printf("Your substring starts at index number: ");
	}
	printf("%d\n", ans);
	ans= -1; /*Initializing the number for the next Run*/
}	

			
		
		
	

