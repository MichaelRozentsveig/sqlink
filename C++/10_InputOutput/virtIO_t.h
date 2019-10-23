#ifndef VIR_H
#define VIR_H

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

class virtIO_t
{

    public:
        typedef enum statusFile {ok_e, cant_open_file_e, bad_access_e, writeErr_e, readErr_e} statusFile;


        virtIO_t() // Default CTOR
        {
            m_fp        = 0;
            m_status    = ok_e ;

        }

        virtIO_t(const string& filePath,const string& fileMode) // CTOR from path & mode
        {
            m_fp = fopen(filePath.c_str(),fileMode.c_str());
            m_filePath  = filePath;
            m_fileMode  = fileMode;
            m_status    = ok_e;

        }
        virtual ~virtIO_t() // DTOR
        {
            if (m_fp)
            {
                fclose(m_fp);
            }
        }

        void openFile(const string& filePath, const string& fileMode)
        {
            if (m_fp)
            {
                m_status= cant_open_file_e;
            }
            m_fp = fopen(m_filePath.c_str(), m_fileMode.c_str());
            m_fileMode = fileMode;
            m_filePath = filePath;
            m_status = ok_e;
        }

        void closeFile()
        {
            if (!m_fp)
            {
                m_status = bad_access_e;
            }   
            fclose(m_fp);
            m_fp =0;
            m_status = bad_access_e;
        }

        const statusFile&   getStatus   () const            {return m_status;}
        void                setStatus   (statusFile status) {m_status = status;}

        string              getPath     () const            {return m_filePath;}
        string              getMode     () const            {return m_fileMode;}

        size_t  getFileLength() const
        {
            if (!m_fp)
            {
                return -1;
            }
            size_t pos = ftell(m_fp);
            fseek(m_fp,0,SEEK_END);
            size_t result = ftell(m_fp);
            fseek(m_fp, pos, SEEK_SET);
            return result;
        }

        int setPos      (size_t pos){return fseek(m_fp, pos, SEEK_SET);}

        size_t getPos   () const    {return ftell(m_fp);}

        virtual virtIO_t& operator << (char val)            = 0;
        virtual virtIO_t& operator >> (char& val)           = 0;

        virtual virtIO_t& operator << (unsigned char val)   = 0;
        virtual virtIO_t& operator >> (unsigned char& val)  = 0;

        virtual virtIO_t& operator << (short val)           = 0;
        virtual virtIO_t& operator >> (short& val)          = 0;

        virtual virtIO_t& operator << (unsigned short val)  = 0;
        virtual virtIO_t& operator >> (unsigned short& val) = 0;

        virtual virtIO_t& operator << (int val)             = 0;
        virtual virtIO_t& operator >> (int& val)            = 0;

        virtual virtIO_t& operator << (unsigned int val)    = 0;
        virtual virtIO_t& operator >> (unsigned int& val)   = 0;

        virtual virtIO_t& operator << (long val)            = 0;
        virtual virtIO_t& operator >> (long& val)           = 0;

        virtual virtIO_t& operator << (unsigned long val)   = 0;
        virtual virtIO_t& operator >> (unsigned long& val)  = 0;

        virtual virtIO_t& operator << (float val)           = 0;
        virtual virtIO_t& operator >> (float& val)          = 0;

        virtual virtIO_t& operator << (double val)          = 0;
        virtual virtIO_t& operator >> (double& val)         = 0;

    protected:
        FILE* m_fp; 

        

    private:

        string m_filePath;
        string m_fileMode;
        statusFile m_status;

        bool isOpen;

        virtIO_t& operator= (const virtIO_t& virtIO){}
        virtIO_t            (const virtIO_t& virtIO){}  


};

#endif