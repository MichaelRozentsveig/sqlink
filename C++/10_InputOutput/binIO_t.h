#ifndef BIN_H
#define BIN_H

#include "binIO_t.h"
class binIO_t : public virtIO_t
{
    public:
        binIO_t& operator >>   (void* Buf);
        binIO_t& operator <<   (const void* Buf);
        void operator,          (int len);

        virtual binIO_t& operator << (char val)            
        virtual binIO_t& operator >> (char& val)           

        virtual binIO_t& operator << (unsigned char val)   
        virtual binIO_t& operator >> (unsigned char& val)  

        virtual binIO_t& operator << (short val)           
        virtual binIO_t& operator >> (short& val)          

        virtual binIO_t& operator << (unsigned short val)  
        virtual binIO_t& operator >> (unsigned short& val) 

        virtual binIO_t& operator << (int val)             
        virtual binIO_t& operator >> (int& val)            

        virtual binIO_t& operator << (unsigned int val)    
        virtual binIO_t& operator >> (unsigned int& val) 

        virtual binIO_t& operator << (long val)            
        virtual binIO_t& operator >> (long& val)          

        virtual binIO_t& operator << (unsigned long val)   
        virtual binIO_t& operator >> (unsigned long& val)  

        virtual binIO_t& operator << (float val)           
        virtual binIO_t& operator >> (float& val)          

        virtual binIO_t& operator << (double val)        
        virtual binIO_t& operator >> (double& val)         



        template <typename T> 
        binIO_t& readFile(T& val)
        {
            //fread(&val, sizeof(T),1,m_fp);
            return *this;
        }

        template <typename T>
        binIO_t& writeFile(T& val)
        {
            //fwrite(val,sizeof(T),1m_fp);
            return *this;
        }
    private:

};

#endif