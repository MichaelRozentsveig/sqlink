#include "Tokenizer.h"

void Tokenizer_t::Tokenize(const string& str)
{
    size_t pos = 0, next = 0;
    size_t len = str.length();
    
    m_tokens.clear();
    
    for(pos = 0, next = 0; next <= len ; ++next)
    {
        if(isspace(str[next]))
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
    m_nextToken = m_tokens.begin();
}

