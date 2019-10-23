#ifndef ASC_H
#define ASC_H

#include "virtIO_t.h"

class asciiIO_t : public virtIO_t
{
    public:
        virtual ~asciiIO_t  ()  {}
        asciiIO_t           ()  {}
        
        asciiIO_t(const string& filePath,const string& fileMode):virtIO_t(filePath, fileMode){}
        

        virtual asciiIO_t& operator << (char val)           {return writeFile   (val,"%c");}           
        virtual asciiIO_t& operator >> (char& val)          {return readFile    (val,"%c");}        

        virtual asciiIO_t& operator << (unsigned char val)  {return writeFile   (val,"%d");} 
        virtual asciiIO_t& operator >> (unsigned char& val) {return readFile    (val,"%d");}  

        virtual asciiIO_t& operator << (short val)          {return writeFile   (val,"%h");} 
        virtual asciiIO_t& operator >> (short& val)         {return readFile    (val,"%h");} 

        virtual asciiIO_t& operator << (unsigned short val) {return writeFile   (val,"%hu");} 
        virtual asciiIO_t& operator >> (unsigned short& val){return readFile    (val,"%hu");} 

        virtual asciiIO_t& operator << (int val)            {return writeFile   (val,"%d");} 
        virtual asciiIO_t& operator >> (int& val)           {return readFile    (val,"%d");} 

        virtual asciiIO_t& operator << (unsigned int val)   {return writeFile   (val,"%u");} 
        virtual asciiIO_t& operator >> (unsigned int& val)  {return readFile    (val,"%u");} 

        virtual asciiIO_t& operator << (long val)           {return writeFile   (val,"%l");} 
        virtual asciiIO_t& operator >> (long& val)          {return readFile    (val,"%l");} 

        virtual asciiIO_t& operator << (unsigned long val)  {return writeFile   (val,"%lu");} 
        virtual asciiIO_t& operator >> (unsigned long& val) {return readFile    (val,"%lu");} 

        virtual asciiIO_t& operator << (float val)          {return writeFile   (val,"%f");} 
        virtual asciiIO_t& operator >> (float& val)         {return readFile    (val,"%f");} 

        virtual asciiIO_t& operator << (double val)         {return writeFile   (val,"%lf");} 
        virtual asciiIO_t& operator >> (double& val)        {return readFile    (val,"%lf");} 

        template<typename T>
        asciiIO_t& writeFile(T& val, const string& printFormat)
        {
            int i = 1;
            if (getStatus() == cant_open_file_e)
            {
                if (getMode() == "r")
                {
                    setStatus(writeErr_e);
                }
                throw i;
            }
            fprintf(m_fp,printFormat.c_str(),val); 
            return *this;
        }
        
        template<typename T>
        asciiIO_t& readFile(T& val, const string& printFormat)
        {
            int i = 1;
            if (getStatus() == cant_open_file_e)
            {
                if (getMode() == "w")
                {
                    setStatus(readErr_e);
                }
                throw i;
            }
            fscanf(m_fp,printFormat.c_str(),&val);
            return *this;
        }

    private:

    
};

#endif