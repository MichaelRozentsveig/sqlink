#ifndef TK_H
#define TK_H

#include <string>
#include <vector>

using namespace std;

class Tokenizer_t
{
    public:

        Tokenizer_t():m_tokenDels("()[]{};<>=+-*&"){}
        virtual ~Tokenizer_t(){}

        void Tokenize(const string& str)
        {
            size_t pos = 0, next = 0;
            size_t len = str.length();
            
            m_tokens.clear();
            
            for(pos = 0, next = 0; next <= len ; ++next)
            {
                if(! (isspace(str[next])))
                {
                    if(next > pos)
                    {
                        m_tokens.push_back(str.substr(pos,next-pos));
                    }
                    pos = next+1;                   		
                }

                else if(m_tokenDels.find(str[next]) != string::npos)
                {
                    if(next > pos)
                    {
                        m_tokens.push_back(str.substr(pos,next-pos));
                    }
                    
                    m_tokens.push_back(str.substr(str[next],1));
                    pos = next+1;
                }
            }          
            m_iter = m_tokens.begin();
        }

    private:
        const string& m_tokenDels ;
        
        Tokenizer_t                  (const Tokenizer_t& tokenizer);
	    const Tokenizer_t& operator= (const Tokenizer_t& tokenizer);
        
        vector<string> m_tokens;
        vector<string>::iterator m_iter;

}

#endif