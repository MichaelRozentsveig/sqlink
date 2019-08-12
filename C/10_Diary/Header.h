#ifndef HEADER_h
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

struct Meeting_t{
	float beginH;
	float endH;
	int room;	
};

struct Calendar_t{
	struct Meeting_t** mt;
	int capacity;
	int count;
};

struct Calendar_t* createAD(int numOfMettings);

struct Meeting_t* createMeeting(); 

int insertAppo(struct Calendar_t* cal, struct Meeting_t* me); 

int removeAppo(struct Calendar_t* me, float beginH); 

struct Meeting_t* findAppo(struct Calendar_t* me, float beginH); 

void PrintAD(struct Calendar_t* cal ); 

void DestroyAD(struct Calendar_t* cal);
	

#endif
