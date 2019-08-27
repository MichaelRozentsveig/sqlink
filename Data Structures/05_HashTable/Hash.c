#include <stdlib.h>
#include "Hash.h"

struct Node
{
	void* m_key;
	void* m_value;
	struct Node* m_next;	
};

struct hashtable
{
	unsigned int m_hashCapacity;
	hashFunction hashFunc;
	elemCompare compFunc;
	Node_t** buckets;	

};

Hashtable_t* createHash(int capacity, hashFunction hashFunc, elemCompare compFunc)
{
	Hashtable_t* hashtable = NULL;
	int i;
	
	if (capacity<1)
	{
		return NULL;	
	}
	hashtable = malloc(sizeof(Hashtable_t));
	if (hashtable == NULL)
	{
		return NULL;
	}
	hashtable->buckets = malloc (sizeof(Node_t*)*capacity);
	if (hashtable->buckets == NULL)
	{
		free(hashtable);
		return NULL;
	}
	for (i=0; i<capacity; i++)
	{
		hashtable->buckets[i] = NULL;
	}
	hashtable->m_hashCapacity 	= capacity;
	hashtable->compFunc 		= compFunc;
	hashtable->hashFunc 		= hashFunc;
	return hashtable;
}

void destroyHash(Hashtable_t* hash, elemDestroy destroyKey,elemDestroy destroyValue, void* context)
{
	int i=0;
	Node_t* next;
	Node_t* current;
	
	if (hash==NULL)
	{
		return ;
	}
	for (i=0; i<hash->m_hashCapacity; i++)
	{
		current = hash->buckets[i];

		while (current != NULL)
		{
			next = current->m_next;
		 	deleteElem (hash,current->m_key,destroyKey,destroyValue,context);
			current = next;
		}
	}
	free(hash->buckets);
	free(hash);	
}

Node_t* ht_newpair(void *key, void *value ) 
{
	Node_t* newpair;

	newpair =malloc(sizeof(Node_t));
	if(newpair == NULL) 
	{
		return NULL;
	}
	if((newpair->m_key =key) == NULL) 
	{
		return NULL;
	}
	if((newpair->m_value = value) == NULL) 
	{
		return NULL;
	}
	newpair->m_next = NULL;

	return newpair;
}
AdtStatus insertHash(Hashtable_t* hash, void* key, void* value)
{
	unsigned long bin = 0;
	Node_t *newpair = NULL;
	Node_t *next = NULL;
	Node_t *last = NULL;
	if (hash == NULL)
	{
		return NullPtr;
	}
	bin = hash->hashFunc(key)%(hash->m_hashCapacity);
	next = hash->buckets[bin];

	while( next != NULL && next->m_key != NULL && hash->compFunc( key, next->m_key ) > 0 )
	{
		last = next;
		next = next->m_next;
	}
	if( next != NULL && next->m_key != NULL && hash->compFunc( key, next->m_key ) == 0 ) 
	{
		return Found;
	} 
	else 
	{
		newpair = ht_newpair( key, value );
		if( next == hash->buckets[ bin ] ) 
		{
			newpair->m_next = next;
			hash->buckets[ bin ] = newpair;
		} 
		else if (next == NULL) 
		{
			last->m_next = newpair;
		} 
		else  
		{
			newpair->m_next = next;
			last->m_next = newpair;
		}
	}
	return OK;
}

AdtStatus findHash(Hashtable_t* hash, void* key)	
{
	int bin = 0;
	Node_t* pair = malloc(sizeof(Node_t));

	if (hash==NULL || pair ==NULL)
	{
		return AllocationError;
	}	
	bin = hash->hashFunc(key)%(hash->m_hashCapacity);
	pair = hash->buckets[bin];
	
	while(pair != NULL && pair->m_key != NULL && hash->compFunc(key, pair->m_key) > 0) 
	{
		pair = pair->m_next;
	}
	if(pair == NULL || pair->m_key == NULL || hash->compFunc(key, pair->m_key) != 0) 
	{
		return NotFound;
	} 
	else 
	{
		return Found;
	}
}


AdtStatus hashForEach(Hashtable_t* hash, elemPrint printFunc)
{
	int i=0;
	Node_t* current;
	if (hash==NULL)
	{
		return AllocationError;
	}
	for (i=0; i<hash->m_hashCapacity; i++)
	{
		current = hash->buckets[i];

		while (current != NULL)
		{
			printFunc(current->m_value);
			current = current->m_next;
		}
	}
	return OK;
}


AdtStatus deleteElem (Hashtable_t* hash, void* key, elemDestroy destroyKey,elemDestroy destroyValue, void* context)
{
	int bin=0;
	Node_t *next;
	Node_t *last=NULL;
	if (hash==NULL)
	{
		return AllocationError;
	}
	bin = hash->hashFunc(key)%(hash->m_hashCapacity);
	next = hash->buckets[bin];
	while((next!=NULL && (next->m_key !=NULL) && (hash->compFunc(key,next->m_key))!=0))
	{
		last=next;
		next=next->m_next;
	}
	if(next!=NULL)
	{
		if(last==NULL)
		{
			if(next->m_next != NULL)
			{
				hash->buckets[bin] = next->m_next;					
			}
			else
			{
				hash->buckets[bin]=NULL;
			}	
		}
		else if (next->m_next != NULL)
		{
			last->m_next = next->m_next;
		}
		else
		{
			last->m_next = NULL;		
		}
		destroyKey(next->m_key,context);
		destroyValue(next->m_value,context);
		return OK;
	}
	else
	{
		return NotFound;
	}
}