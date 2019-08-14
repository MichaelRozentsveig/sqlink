#ifndef HEADER_H
#define HEADER_H

typedef struct {
	unsigned int hour;
	unsigned int min;
	unsigned int sec;
}cTime_t;


typedef struct {
	unsigned int day;
	unsigned int month;
	unsigned int year;
}cDate_t;

void setTime(unsigned int hour,unsigned int min,unsigned int sec,cTime_t* Time);

void printTime(cTime_t* time, int format);

unsigned int getHour(cTime_t* Time);

unsigned int getMinutes(cTime_t* Time);

unsigned int getSeconds(cTime_t* Time);

void addTime(cTime_t* timeOriginal, cTime_t* timeAdder);

void setDate(unsigned int day,unsigned int month,unsigned int year,cDate_t* Date);

void printDate(cDate_t* Date, int format);

unsigned int getDay(cDate_t* Date);

unsigned int getMonth(cDate_t* Date);

unsigned int getYear(cDate_t* Date);

void addDate(cDate_t* dateOriginal, cDate_t* dateAdder);

#endif
