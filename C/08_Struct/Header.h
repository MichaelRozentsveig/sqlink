#ifndef HEADER_h
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

struct DA_t {
	int capacity;
	int* arr;
	int index;
};

struct DA_t* createDA(int capacity);

int insert(struct DA_t* dptr, int num);

void printDA(struct DA_t*);

void destroy(struct DA_t*);

#endif
