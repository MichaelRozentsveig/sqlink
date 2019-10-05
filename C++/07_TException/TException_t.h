#pragma once
#include <string>

using namespace std;

template <class T>
class TException_t
{
    public:
        TException_t(string srcName, T thrownObj, string txtDescription, size_t line)
        {
            m_srcName       = srcName;
            m_thrownObj     = thrownObj;
            m_txtDescription= txtDescription;
            m_line          = line;
        }

        string getSrcName()         const { return m_srcName;}
        const T& getThrownObj()     const {return m_thrownObj;}
        string getTxtDescription()  const { return m_txtDescription;}
        size_t getLine()            const { return m_line;}
        

    private:
        string  m_srcName;
        T       m_thrownObj;
        string  m_txtDescription;
        size_t  m_line;
};