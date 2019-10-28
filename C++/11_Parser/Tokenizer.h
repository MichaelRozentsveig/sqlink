#ifndef TK_H
#define TK_H

#include "Parser.h"
#include <string>
#include <vector>
# include <iostream>
# include <string>
# include <iterator>

using namespace std;

class Tokenizer_t
{
    public:

        Tokenizer_t(){}

        virtual ~Tokenizer_t(){}

        size_t getSize() const {return m_tokens.size();}

        void Tokenize(const string& str);

        vector<string>& getVector()  {return m_tokens;}

    protected:
        

    private:
        //string m_tokenDels = "()[]{};<>=+-*&";
        
        Tokenizer_t                  (const Tokenizer_t& tokenizer);
	    const Tokenizer_t& operator= (const Tokenizer_t& tokenizer);
        
        vector  <string>           m_tokens;
        vector  <string>::iterator m_iter;
        vector  <string>::iterator m_nextToken;

};

#endif