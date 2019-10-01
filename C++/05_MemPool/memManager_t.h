#pragma once
#include <iostream>
#include <string.h>

using namespace std;

class memManager_t
{
    enum retStatus{Failed, Succeed};

    public:
        memManager_t():m_currentPos(0),m_acSize(0){};
        bool isEmpty() const {return (m_acSize==0) ;}
        size_t getCurPos()const {return m_currentPos;}
        bool setCurPos(size_t currentPos) 
        { 
            if (currentPos<=m_acSize) 
            {
                m_currentPos = currentPos;
                return Succeed;
            }
            return Failed;
        }
        
        size_t getAcSize () const  {return m_acSize;}

        virtual size_t read(void* buffer, size_t nOfBytes){}
        virtual size_t read(void* buffer, size_t nOfBytes, size_t pos){}
        virtual size_t write(const void* buffer, size_t nOfBytes){}
        virtual size_t write(const void* buffer, size_t nOfBytes, size_t pos){}

    protected:
        virtual ~memManager_t(){}
        void setAcSize(size_t acSize){m_acSize = acSize;}

    private:
        memManager_t(const memManager_t& mem){}
        memManager_t& operator=(const memManager_t& mem){}
        size_t m_currentPos;
        size_t m_acSize;
};