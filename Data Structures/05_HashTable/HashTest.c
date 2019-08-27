#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

void destroyStr         (void* elem, void* context);
void destroyKey			(void* elem, void* context);
void printStr           (void* value);
int compareStr          (void* elemA, void* elemB);
unsigned long hashStr   (void* key);

int main()
{
	FILE* fp;
    Hashtable_t* ht;

	elemDestroy     destroy_str = destroyStr;
	elemDestroy 	destroy_key	= destroyKey;
	elemPrint       print_str   = printStr;
	elemCompare     compare_str = compareStr;
    hashFunction    hash_str    = hashStr;

	int size = 10;

	int inPtr1 = 5;
	int inPtr2 = 10;
	int inPtr3 = 11;
	int inPtr4 = 11;

	fp = fopen("File.txt","a");
	ht = createHash(size,hash_str, compare_str);
	insertHash(ht,"Mike",&inPtr1);
	insertHash(ht,"Bike",&inPtr2);
	insertHash(ht,"Shpike",&inPtr3);
	insertHash(ht,"Lala",&inPtr4);


	hashForEach(ht, print_str);
	printf("\n");

	deleteElem(ht,"Bike",destroy_key,destroy_str,fp);
	hashForEach(ht, print_str);
	printf("\n");

	printf("%d ",findHash(ht,"Bike"));
	printf("\n");

	destroyHash(ht,destroy_key, destroy_str,fp);

	fclose(fp);
	return 0;
}

void destroyStr(void* elem, void* context)
{
    FILE* fp = (FILE*) context;
	int* n = (int*) elem;
	
	fprintf(fp,"%d ", *n);
}

void printStr(void* _elem)
{
	int* n = (int*) _elem;
	printf("%d ", *n);
}

int compareStr(void *_elemA, void *_elemB)
{
	char *a =(char*) _elemA;
	char *b =(char*) _elemB;
    return (strcmp(a,b));    
}

unsigned long hashStr(void* str)
{
	unsigned char* s = (unsigned char*) str;
    unsigned long hash = 5381;
    int c;

    while (c=*s++)
    {
        hash = ((hash<<5)+hash)+c;
    }
    return hash;
}

void destroyKey(void* elem, void* context)
{
	FILE* fp = (FILE*) context;
	unsigned char* n = (unsigned char*) elem;
	
	fprintf(fp,"%s ", n);
	return;
	
}





