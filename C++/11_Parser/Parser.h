#ifndef P_H
#define P_H

#include <fstream>
#include <string>
#include <algorithm>

class Tokenizer_t;
class Analyzer_t;

class Parser_t
{
    public:
	
        Parser_t          ();

        virtual ~Parser_t ();
        
	    void parseFile(const std::string& file);
	
	private:
        Parser_t                    (const Parser_t& _p);
        const Parser_t& operator=   (const Parser_t& _p);
        
        std::ifstream   m_file;
        Tokenizer_t*    m_tokenizer;
        Analyzer_t*     m_analyzer;

};

#endif