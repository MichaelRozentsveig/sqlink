#ifndef MALLOC_H
#define MALLOC_H

void* memInit(int* buffer, int* size);

void* memAlloc(char* buffer, int bufferSize, int blockSize);

void memFree(char* blockPtr,int* buffer, int bufferSize);

void setMsbOff(int *num);

#endif