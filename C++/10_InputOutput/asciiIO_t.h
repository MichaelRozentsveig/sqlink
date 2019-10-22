#ifndef ASC_H
#define ASC_H

#include "asciiIO_t.h"

class asciiIO_t : public virtIO_t
{
    public:

        virtual asciiIO_t& operator << (char val) {return writeFile(val,"%c");}           
        virtual asciiIO_t& operator >> (char& val){return readFile(val,"%c");}        

        virtual asciiIO_t& operator << (unsigned char val)   
        virtual asciiIO_t& operator >> (unsigned char& val)  

        virtual asciiIO_t& operator << (short val)           
        virtual asciiIO_t& operator >> (short& val)          

        virtual asciiIO_t& operator << (unsigned short val)  
        virtual asciiIO_t& operator >> (unsigned short& val) 

        virtual asciiIO_t& operator << (int val)             
        virtual asciiIO_t& operator >> (int& val)            

        virtual asciiIO_t& operator << (unsigned int val)    
        virtual asciiIO_t& operator >> (unsigned int& val) 

        virtual asciiIO_t& operator << (long val)            
        virtual asciiIO_t& operator >> (long& val)          

        virtual asciiIO_t& operator << (unsigned long val)   
        virtual asciiIO_t& operator >> (unsigned long& val)  

        virtual asciiIO_t& operator << (float val)           
        virtual asciiIO_t& operator >> (float& val)          

        virtual asciiIO_t& operator << (double val)        
        virtual asciiIO_t& operator >> (double& val) 

        template<typename T>
        asciiIO_t& writeFile(T& val, const string& printFormat)
        {
            if (m_fp)
            {
                fprintf(m_fp,printFormat,val);
                return *this;
            }
            else
            {
                //throw
            }
        }
        
        template<typename T>
        asciiIO_t& readFile(T& val, const string& printFormat)
        {
            if (m_fp)
            {
                fscanf(m_fp,printFormat,&val);
                return *this;
            }
            else
            {
                
            }
        }
{

}

    private:

    
};

template<typename T>
asciiIO_t& asciiIO_t::writeFile(T& val, const string& printFormat)
{

}

#endif