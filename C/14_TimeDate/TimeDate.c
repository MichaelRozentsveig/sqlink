#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"



void setTime(unsigned int hour,unsigned int min,unsigned int sec,cTime_t* Time){

	if (!Time){
		printf("Null pointer  !\n");
		return;
	}
	
	if (hour>24 || min>60 || sec>60){
		printf("Wrong time input\n");
		return;
	}
	Time->hour=hour;
	Time->min=min;
	Time->sec=sec;
}

void printTime(cTime_t* Time, int format){

	char amPm[]= "AM";
	unsigned int digitHour ;
	if (!Time){
		printf("Null pointer  !\n");
		return;
	}
	
	if (format == 2){
		printf("%u:%u:%u\n", Time->hour,Time->min,Time->sec);

	}else if (format==1){
		if((Time->hour)>12){
			amPm[0]='P';
		}
		digitHour = Time->hour;

		printf("%u:%u:%u %s\n", digitHour%12,Time->min,Time->sec, amPm);

	}else{
		printf("Wrong format input\n");
	}
}

unsigned int getHour(cTime_t* Time){
	if (!Time){
		printf("Null pointer  !\n");
		return;
	}
	return Time->hour;
}

unsigned int getMinutes(cTime_t* Time){
	if (!Time){
		printf("Null pointer  !\n");
		return;
	}
	return Time->min;
}

unsigned int getSeconds(cTime_t* Time){
	if (!Time){
		printf("Null pointer  !\n");
		return;
	}
	return Time->sec;
}

void addTime(cTime_t* timeOriginal, cTime_t* timeAdder){
	
	unsigned int tempHour = 0;
	unsigned int tempMinutes = 0;
	unsigned int tempSeconds = 0;

	if (!timeOriginal || !timeAdder){
		printf("Null pointer  !\n");
		return;
	}
	
	tempHour = timeOriginal->hour;
	tempMinutes = timeOriginal->min;
	tempSeconds = timeOriginal->sec;

	timeOriginal->hour = (timeOriginal->hour + timeAdder->hour)%24;
	timeOriginal->min = (timeOriginal->min + timeAdder->min)%60;
	timeOriginal->sec = (timeOriginal->sec + timeAdder->sec)%60;

	if (timeOriginal->sec < tempSeconds){
		(timeOriginal->min)++;
		timeOriginal->min%=60;
	}
	
	if (timeOriginal->min <= tempMinutes){
		(timeOriginal->hour)++;
		timeOriginal->hour%=60;
	}
}


void setDate(unsigned int day,unsigned int month,unsigned int year,cDate_t* Date){
	
	if (!Date){
		printf("Null pointer  !\n");
		return;
	}
	
	if (	(day>31) ||
		(month>12) ||
		(day>30 && month !=2 && month!=4 && month !=6 && month!=8 && month !=10 && month!=12) ||
		(day>29 && year%4 ==0 && month==2) ||
		(day>28 && year%4 !=0 && month==2)){
			printf("Wrong input\n");
			return;	
	}
	
	Date->day=day;
	Date->month=month;
	Date->year=year;
}

void printDate(cDate_t* Date, int format){
	
	char month[10];
	unsigned int monthNum= 0;
	
	if (!Date){
		printf("Null pointer  !\n");
		return;
	}
		
	monthNum= Date->month;
	switch(format){
		case 1:  	/* Day / Month (String) / Year */
			switch(monthNum){
				case 1: strcpy(month,"Jan"); break;
				case 2: strcpy(month,"Feb"); break;
				case 3: strcpy(month,"Mar"); break;
				case 4: strcpy(month,"Apr"); break;
				case 5: strcpy(month,"May"); break;
				case 6: strcpy(month,"Jun"); break;
				case 7: strcpy(month,"Jul"); break;
				case 8: strcpy(month,"Aug"); break;
				case 9: strcpy(month,"Sep"); break;
				case 10: strcpy(month,"Oct"); break;
				case 11: strcpy(month,"Nov"); break;
				case 12: strcpy(month,"Dec"); break;
			}
			printf("%u/%s/%u\n", Date->day,month,Date->year); break;		

		case 2:		/* Day / Month (Number) / Year */
			printf("%u/%u/%u\n",Date->day,Date->month,Date->year);
			break;

		case 3:		/* Month (Number) / Day / Year */
			printf("%u/%u/%u\n",Date->month,Date->day,Date->year);
			break;
		
		default: 
			printf("Wrong Format input");
			break;
	}
}


unsigned int getDay(cDate_t* Date){
	if (!Date){
		printf("Null pointer  !\n");
		return;
	}
	return Date->day;
}

unsigned int getMonth(cDate_t* Date){
	if (!Date){
		printf("Null pointer  !\n");
		return;
	}
	return Date->month;
}

unsigned int getYear(cDate_t* Date){
	if (!Date){
		printf("Null pointer  !\n");
		return;
	}
	return Date->year;
}

void addDate(cDate_t* dateOriginal, cDate_t* dateAdder){
	
	unsigned int tempDay = 0;
	unsigned int tempMonth = 0;
	unsigned int tempYear = 0;
	unsigned int currentMonthDays=0;

	unsigned int daysInMonth[12] = {31,28,31,30,31,30,31,30,31,30,31,30};

	if (!(dateOriginal) || !(dateAdder)){
		printf("Null pointer  !\n");
		return;
	}

	tempDay = dateOriginal->day;
	tempMonth = dateOriginal->month;
	tempYear = dateOriginal->year;
	currentMonthDays=0;

	if (tempYear%4==0){
		daysInMonth[1] = 29;
	}
	currentMonthDays = daysInMonth[tempMonth-1];
	
	dateOriginal->day = (dateOriginal->day + dateAdder->day)%currentMonthDays;
	if (dateOriginal->day < tempDay){
		(dateOriginal->month)++;
		if (dateOriginal->month!=12){
			(dateOriginal->month)%=12;
		}
			if (dateOriginal->month == 1){
				dateOriginal->year++;
			}
	}
}
	















































