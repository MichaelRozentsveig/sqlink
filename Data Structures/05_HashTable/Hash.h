#ifndef HEADER_H
#define HEADER_H

typedef struct Node Node_t;
typedef struct hashtable Hashtable_t;

typedef enum {OK, AllocationError, NotFound, Found, NullPtr} AdtStatus;
typedef enum {Failed, Succeed} TestStatus;

typedef unsigned long(*hashFunction)(void* key);
typedef int(*elemCompare)           (void* elemA, void* elemB);
typedef void(*elemDestroy)          (void* elem, void* context);
typedef void(*elemPrint)            (void* value);

Hashtable_t* createHash             (int capacity, hashFunction, elemCompare);
void destroyHash                    (Hashtable_t* hash, elemDestroy,elemDestroy, void* context);
AdtStatus insertHash                (Hashtable_t* hash, void* key, void* value);
AdtStatus findHash                  (Hashtable_t* hash, void* key);
AdtStatus hashForEach               (Hashtable_t* hash, elemPrint);
AdtStatus deleteElem                (Hashtable_t* hash, void* key, elemDestroy destroyFunc,elemDestroy destroyValue, void* context);

/*AdtStatus hashDelete    (Hashtable_t* hash, )*/

#endif