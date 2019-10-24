#ifndef BIN_H
#define BIN_H

#include "virtIO_t.h"
class binIO_t : public virtIO_t
{
    public:
        virtual ~binIO_t  ()  {}
        binIO_t           ()  {}
        
        binIO_t(const string& filePath,const string& fileMode):virtIO_t(filePath, fileMode){}

        virtual binIO_t& operator << (char val)           {return writeFile   (val);}           
        virtual binIO_t& operator >> (char& val)          {return readFile    (val);}        

        virtual binIO_t& operator << (unsigned char val)  {return writeFile   (val);} 
        virtual binIO_t& operator >> (unsigned char& val) {return readFile    (val);}  

        virtual binIO_t& operator << (short val)          {return writeFile   (val);} 
        virtual binIO_t& operator >> (short& val)         {return readFile    (val);} 

        virtual binIO_t& operator << (unsigned short val) {return writeFile   (val);} 
        virtual binIO_t& operator >> (unsigned short& val){return readFile    (val);} 

        virtual binIO_t& operator << (int val)            {return writeFile   (val);} 
        virtual binIO_t& operator >> (int& val)           {return readFile    (val);} 

        virtual binIO_t& operator << (unsigned int val)   {return writeFile   (val);} 
        virtual binIO_t& operator >> (unsigned int& val)  {return readFile    (val);} 

        virtual binIO_t& operator << (long val)           {return writeFile   (val);} 
        virtual binIO_t& operator >> (long& val)          {return readFile    (val);} 

        virtual binIO_t& operator << (unsigned long val)  {return writeFile   (val);} 
        virtual binIO_t& operator >> (unsigned long& val) {return readFile    (val);} 

        virtual binIO_t& operator << (float val)          {return writeFile   (val);} 
        virtual binIO_t& operator >> (float& val)         {return readFile    (val);} 

        virtual binIO_t& operator << (double val)         {return writeFile   (val);} 
        virtual binIO_t& operator >> (double& val)        {return readFile    (val);}        



        template <typename T> 
        binIO_t& readFile(T& val)
        {
            fread(&val, sizeof(T),1,m_fp);
            return *this;
        }

        template <typename T>
        binIO_t& writeFile(T& val)
        {
            fwrite(&val,sizeof(T),1,m_fp);
            return *this;
        }

        binIO_t& operator>>(void* buf)
        {         
            m_writable = false;
            m_buf = buf;
            
            return *this;
        }

        binIO_t& operator<<(const void* _buf)
        {      
            m_writable = true;
            m_buf = (void*)_buf;
            
            return *this;
        }

        void operator,(int length)
        {
            if (m_writable)
            {  
                int res = fwrite(m_buf, 1, length, m_fp);

                if (length != res)
                {
                    setStatus(writeErr_e);
                    throw writeErr_e;
                }
            }
            else
            {    
                int res = fread(m_buf, 1, length, m_fp);
                if (length != res)
                {
                    setStatus(readErr_e);
                    throw readErr_e;
                }
            }	
            fseek(m_fp,0,SEEK_SET);
        }
    private:

        binIO_t             (const binIO_t& bio);
        binIO_t& operator=  (const binIO_t& bio);
        
        bool  m_writable;
	    void* m_buf;
};

#endif