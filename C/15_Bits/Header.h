#ifndef HEADER_H
#define HEADER_H

typedef struct {
	int m_numOfFeatures;
	unsigned char* m_arrFeatures;
}BitMap;

typedef int(*binary)(int,BitMap*);

BitMap* createBitMap(int n);

void destroyBM(BitMap* bm);

int BitOn(int n, BitMap* bmPtr);

int BitOff(int n, BitMap* bmPtr);

int BitStatus(int n, BitMap* bmPtr);

void printBitNum(BitMap* bmPtr);

static void decimalToBinChar(unsigned char);


#endif
