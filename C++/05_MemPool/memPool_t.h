#pragma once
#include "memManager_t.h"
#include "memPage_t.h"
#include <vector>
using namespace std;


class memPool_t : public memManager_t
{
    public:
		memPool_t() 
        {
			memPage_t* pg = new memPage_t;
			v.insert(v.end(), pg);	
		}
        virtual ~memPool_t()
        {
            int i;
            for(i=0;i<v.size();i++)
            {
                delete v[i];
            }
        }
        virtual size_t read(void* buffer, size_t nOfBytes);
        virtual size_t read(void* buffer, size_t nOfBytes, size_t pos);
        virtual size_t write(const void* buffer, size_t nOfBytes);
        virtual size_t write(const void* buffer, size_t nOfBytes, size_t pos);     
    private:
    	vector<memPage_t*> v;  
        memPool_t(const memPool_t& mp){}
        memPool_t& operator=(const memPool_t& mp){}			
};
