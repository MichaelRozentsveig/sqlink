#ifndef P_H
#define P_H

#include <fstream>
#include <string>
#include "Analizer.h"
#include "Tokenizer.h"

using namespace std;

class Parser_t
{
    public:
	
        Parser_t          (): m_tokenizer(new Tokenizer_t), m_analyzer(new Analizer_t){}

        virtual ~Parser_t ()   
        {
            delete m_tokenizer; 
            delete m_analyzer;
        }
        
	    void parseFile(const string& file)
        {
            m_file.open(file.cstr());
            string throwStr = "Bad input";

            if (!m_file.good())
            {
                throw throwStr;
            }
        }
	
	private:
        Parser_t(const Parser_t& _p);
        const Parser_t& operator=(const Parser_t& _p);
        
        ifstream m_file;
        Tokenizer_t* m_tokenizer;
        Analyzer_t* m_analyzer;:

}