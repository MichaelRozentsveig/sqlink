#include "Tokenizer.h"
#include <ctype.h>
# include <string>
# include <iterator>
# include <vector>
#include <iostream>

string m_tokenDels = "()[]{};<>=+-*&";

void Tokenizer_t::Tokenize(const string& str)
{
    size_t pos , next ;
    size_t len = str.length();
    
    m_tokens.clear();
    
    for(pos = 0, next = 0; next <= len ; ++next)
    {
        if(isspace(str[next]))
        {
            if(next > pos)
            {
				m_tokens.push_back(string(str,pos,next-pos));
            }
            pos = next+1;                   		
        }

        else if(m_tokenDels.find(str[next]) != string::npos )
        {
            if(next > pos)
            {
                m_tokens.push_back(string(str,pos,next-pos));
            }      
            m_tokens.push_back(str.substr(next,1));
            pos = next+1;
        }
       
    }  
    if(next > pos)
    {
        m_tokens.push_back(string(str,pos,next-pos));
    }        
    m_nextToken = m_tokens.begin();
}

