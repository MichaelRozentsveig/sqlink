#ifndef HEADER_H
#define HEADER_H

typedef struct{
	char word [30];
	unsigned int count;

} wordStruct;

void lastNlines(int n,char*); 
void charCount(char*);
void wordCount(char*);

#endif
