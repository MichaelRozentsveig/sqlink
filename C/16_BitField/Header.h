#ifndef HEADER_H
#define HEADER_H


struct LRchar{
	unsigned int left : 4;
	unsigned int right: 4;

};

union un{
	struct LRchar lr;
	char 	      c;
};

int compressUnion(char* str);
int compress(char* str);
void decimalToBinChar(char decimal) ;
#endif
