#ifndef TK_H
#define TK_H

#include "Parser.h"
#include <string>
#include <vector>

using namespace std;

class Tokenizer_t
{
    public:

        Tokenizer_t():m_tokenDels("()[]{};<>=+-*&"){}
        virtual ~Tokenizer_t(){}

        size_t getSize() const {return m_tokens.size();}

        void Tokenize(const string& str);

        vector<string> getVector() const {return m_tokens;}

        static const string emptyStr;

    protected:
        vector  <string> m_tokens;

    private:
        const string& m_tokenDels;
        
        Tokenizer_t                  (const Tokenizer_t& tokenizer);
	    const Tokenizer_t& operator= (const Tokenizer_t& tokenizer);
        
        
        vector  <string>::iterator m_iter;
        vector  <string>::iterator m_nextToken;

};

#endif