#include <iostream>
#include <string.h>
#include "memPage_t.h"

size_t memPage_t::read(void* buffer, size_t nOfBytes)
{
    if(getCurPos() + nOfBytes > getAcSize())
    {
        nOfBytes=getAcSize()-getCurPos();
    }
    memcpy(buffer,m_page+getCurPos(),nOfBytes);
    return nOfBytes;
}

size_t memPage_t::read(void* buffer, size_t nOfBytes, size_t pos)
{
    if(pos + nOfBytes > getAcSize())
    {
        nOfBytes=getAcSize()-pos;
    }
    memcpy(buffer,m_page+pos,nOfBytes);
    return nOfBytes;
}

size_t memPage_t::write(const void* buffer, size_t nOfBytes)
{
    if(getCurPos() + nOfBytes > m_capacity)
    {
        nOfBytes=m_capacity-getCurPos();
        setAcSize(m_capacity);
    }
    else if(getCurPos()+nOfBytes>getAcSize())
    {
        setAcSize(getCurPos()+nOfBytes);
    }
    if(getCurPos()!=0)
    {
        memcpy(m_page+getCurPos()+1,buffer,nOfBytes);  
    }
    memcpy(m_page+getCurPos(),buffer,nOfBytes);
    setCurPos(getCurPos()+nOfBytes-1);
    return nOfBytes;
}

size_t memPage_t::write(const void* buffer, size_t nOfBytes, size_t pos)
{
    if(pos-1>getAcSize())
    {
        return 0;
    } 
    if(pos + nOfBytes > m_capacity)
    {
        nOfBytes=m_capacity-pos;
        setAcSize(m_capacity);
    }
    else if(pos+nOfBytes>getAcSize())
    {
        setAcSize(pos+nOfBytes);
    }
    memcpy(m_page+pos,buffer,nOfBytes);
    setCurPos(getCurPos()+nOfBytes-1);
    return nOfBytes;
}