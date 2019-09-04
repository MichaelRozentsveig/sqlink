#include <stdio.h>
#include "malloc.h"

char myBuff[10000000]; /* 10,000,000 */

int main()
{
    char* newBuff;
    char* pToM;
    char* pToM2;
    char* pToM3;
    int i;
    int BSIZE = 100;
    int num = 10;
    
    newBuff = (char*)memInit(myBuff,&BSIZE);

    pToM = (char*)memAlloc(newBuff,BSIZE,10);
    for (i=0;i<BSIZE; i++)
    {
        printf("%d, ", newBuff[i]);
    }
    return 0;


}