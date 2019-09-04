#include <stdio.h>
#include "malloc.h"

typedef enum{FREE, TAKEN} statusBit;


static void setMsbOn(int *num);

static statusBit msbStatus(int num);

static int* split(int* blockPtr, int blockSize );

void* memInit(int* buffer, int* size)
{
    int* ptr ;

    *buffer  = (((int)buffer)%4 != 0) ? buffer + (4 - ((int)buffer)%4) : buffer ;
    (*size) = ((*size)%4 != 0)          ? (*size)- ((*size)%4)              : (*size);

    ptr = (int*)&buffer[0];
    *ptr=*size;
    setMsbOff(ptr);
    return buffer;
}

void* memAlloc(char* buffer, int bufferSize, int blockSize)
{
    char i = 0;
    int* bufferPtr;
    while (i < bufferSize)
    {
        bufferPtr=(int*)(&buffer[i]);

        if (msbStatus(buffer[i]) == FREE) 
        {
            if (blockSize+4 < buffer[i])
            {
                return split(bufferPtr,blockSize);
            }
            else if (blockSize+4 == bufferPtr[i])
            {
                setMsbOn((int*)bufferPtr);
                return bufferPtr;
            }        
            i += (*bufferPtr/4);
        }   
    }
    return NULL;
}

void memFree(char* blockPtr,int* buffer, int bufferSize)
{
    char i=0;
    int* tmpPtr = (int*)blockPtr;
    while (buffer[i++] != blockPtr);
    
    setMsbOff((int*)blockPtr); /* Set to free */
    
    while(i<bufferSize && msbStatus(tmpPtr+*tmpPtr) == FREE) /* While all the next blocks are free we combine them */
    {
        *blockPtr += (int) tmpPtr[i]+tmpPtr;
        i++;
    }
}

void setMsbOff(int *num)
{
    *num &=  0x7fffffff ;
}

void setMsbOn(int *num)
{
    *num |= 0x80000000 ;
}

static statusBit msbStatus(int num)
{
    if ((num & (0x80000000)) == 0x80000000) 
    {
        return FREE;
    }
    return TAKEN;   
}

static int* split(int* blockPtr, int blockSize )
{
    *blockPtr = blockSize+4;
    *(blockPtr+blockSize/4+1) = *blockPtr-blockSize+4;
    setMsbOn(blockPtr);
    setMsbOff(blockPtr+blockSize/4+1);
    return (blockPtr);
}