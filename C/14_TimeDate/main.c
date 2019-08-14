#include <stdio.h>
#include <stdlib.h>

#include "Header.h"

int main(){
	
	cTime_t* Time = (cTime_t*)malloc (sizeof(cTime_t));
	cTime_t* TimeAdder = (cTime_t*)malloc (sizeof(cTime_t));
	cDate_t* Date = (cDate_t*)malloc (sizeof(cDate_t));
	cDate_t* DateAdder = (cDate_t*)malloc (sizeof(cDate_t));
	
	int format=0;
	int cont=1;
	unsigned int option=0;
	unsigned int hour=0,min=0,sec=0;
	unsigned int day=0, month=0, year=0;

	if (!Time || !TimeAdder || !Date || !DateAdder){
		printf("Malloc Failed!\n");
		return 0;
	}

	while (cont) 

	{
		printf("Choose option: \n");
		printf("1: Set Time  \n"); 
		printf("2: Print Time  \n");
		printf("3: Add Time  \n");
		printf("4: Set Date \n");
		printf("5: Print Date \n");
		printf("6: add Date \n");

		printf("Any another number - stop \n");

		scanf("%u", &option);
		switch (option) 
		{
			case 1: 
				printf("Please insert hour:\n");
				scanf("%u", &hour);
				printf("Please insert minutes:\n");
				scanf("%u", &min);		
				printf("Please insert seconds:\n");
				scanf("%u", &sec);		
				setTime(hour,min,sec,Time);
 				break;

			case 2: 
				printf("Select printing format:\n");
				printf("1:  12H\n");
				printf("2:  24H\n");
				scanf("%d",&format);
				printTime(Time,format);
				break;

			case 3: 
				printf("Insert hour of adder time:\n");
				scanf("%u", &hour);
				printf("Insert minutes of adder time:\n");
				scanf("%u", &min);		
				printf("Insert seconds of adder time:\n");
				scanf("%u", &sec);		
				setTime(hour,min,sec,TimeAdder);
				addTime(Time,TimeAdder);
				break;

			case 4: 
				printf("Please insert day:\n");
				scanf("%u", &day);
				printf("Please insert month:\n");
				scanf("%u", &month);		
				printf("Please insert year:\n");
				scanf("%u", &year);
				setDate(day,month,year,Date);
				break;

			case 5: 
				printf("Select printing format:\n");
				printf("1:  Day / Month(string) / Year\n");
				printf("2:  Day / Month / Year\n");
				printf("3:  Month / Day / Year\n");
				scanf("%d",&format);
				printDate(Date,format);
				break;

			case 6: 
				printf("Insert days of adder time:\n");
				scanf("%u", &day);
				printf("Insert month of adder time:\n");
				scanf("%u", &month);		
				printf("Insert year of adder time:\n");
				scanf("%u", &year);		
				setDate(day,month,year,DateAdder);
				addDate(Date,DateAdder);
				break;

			default: cont=0; break;
		}
	}
	free(Time);
	free(TimeAdder);
	free(Date);
	free(DateAdder);
	
	return 0;


}

