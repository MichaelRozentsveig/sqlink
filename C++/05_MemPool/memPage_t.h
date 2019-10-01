#pragma once
#include "memManager_t.h"

using namespace std;

class memPage_t : public memManager_t
{
    public:
        virtual ~memPage_t(){};
        memPage_t():m_capacity(6){m_page = new char[6];}
        memPage_t(size_t capacity){m_capacity = capacity;}

        bool isFull(){return (getAcSize()==m_capacity);}

        virtual size_t read(void* buffer, size_t nOfBytes);
        virtual size_t read(void* buffer, size_t nOfBytes, size_t pos);
        virtual size_t write(const void* buffer, size_t nOfBytes);
        virtual size_t write(const void* buffer, size_t nOfBytes, size_t pos);

        size_t getCapacity() const{return m_capacity;}
    private:
        memPage_t(const memPage_t& mp){}
        memPage_t& operator=(const memPage_t& mp){}

        size_t m_capacity;
        char* m_page;
};