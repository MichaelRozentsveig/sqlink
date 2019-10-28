#include "Tokenizer.h"
#include "Parser.h"
#include "Analizer.h"
#include <iostream>

Parser_t::Parser_t():m_tokenizer(new Tokenizer_t), m_analyzer(new Analyzer_t)
{}

Parser_t::~Parser_t() 
{
    delete m_tokenizer; 
    delete m_analyzer;        
}

void Parser_t::parseFile(const string& file)
{
    m_file.open(file.c_str());
    string throwStr = "Bad input";

    if (!m_file.good())
    {
        throw throwStr;
    }
    m_analyzer->init();

    string nextLine;
    size_t line = 1;

    while(1)
    {
        getline(m_file,nextLine);
        if(!m_file.good())
        {
            break;
        }
            
        m_tokenizer->Tokenize(nextLine);
            
        if( m_tokenizer->getSize() > 0)
        {
            m_analyzer->analyzeLine(*m_tokenizer,line);
        }
            
        ++line;
    }
        
    m_analyzer->init();
        
    m_file.close();
}

