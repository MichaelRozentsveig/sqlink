#include "Analizer.h"
# include <iostream>
# include <string>
# include <set>
# include <iterator>
# include <algorithm>
# include <vector>

using namespace std;

const string Analyzer_t::m_preDefTypes[] =
	{"char", "short", "int", "long", "float", "double", "void"};

const string Analyzer_t::m_keyWords[] =
	{"if", "else", "for" , "while", "class", 
		"private", "public", "protected", "main","virtual", "const" };

const string Analyzer_t::m_operators[] =
	{"++", "--", "==", "->" , "=", "+", "-", "*", "&", "<<", ">>"};

const string Analyzer_t::m_predefTokens[] =
	{"(", ")", "[", "]" , "{" , "}", ";", "<", ">" , "=", "+", "-", "*", "&"};


set<string> Analyzer_t::s_predefinedTypes
	(m_preDefTypes, m_preDefTypes + (sizeof(m_preDefTypes))/ sizeof(m_preDefTypes[0]));

set<string> Analyzer_t::s_keyWords
	(m_keyWords, m_keyWords + (sizeof(m_keyWords)) / sizeof(m_keyWords[0]));

set<string> Analyzer_t::s_operators
	(m_operators, m_operators + (sizeof(m_operators))/sizeof(m_operators[0]));

set<string> Analyzer_t::s_predefTokens
	(m_predefTokens, m_predefTokens + (sizeof(m_predefTokens)) / sizeof(m_predefTokens[0]));

void Analyzer_t::Finish()
{   
    m_isIf=false;
	printClosureError('(', this->m_roundBracCounter);
	printClosureError('{', this->m_curlyBracCounter);
	printClosureError('[', this->m_squareBracCounter);
	
}
bool Analyzer_t::checkOperators(const string& token, size_t line)
{
    if (m_predefTypeFlag && (token == "+" || token == "-") )
        {
            cout << "Line " << line << "error, illegal variable name" << endl;
            m_predefTypeFlag = false;
        }
        
    if (token == "+")
    {
        if (m_plusCounter < 2)
        {
            m_plusCounter++;
            m_minusCounter =0;
        }
        else
        {
            m_plusCounter   = 0;
            cout << "Line "<< line << "- error, illegal operator '+++'" << endl;
        }
        return true;
    }
    if (token == "-")
    {
        if (m_minusCounter < 2)
        {
            m_minusCounter++;
            m_plusCounter = 0;
        }
        else
        {
            m_minusCounter  = 0;
            cout << "Line "<< line << "- error, illegal operator '---'" << endl;
        }
        return true;
    }
    m_minusCounter  = 0;
    m_plusCounter   = 0;
    return false ;
}

void Analyzer_t::init()
{
    m_roundBracCounter      = 0;     // ()
    m_curlyBracCounter      = 0;     // {}
    m_squareBracCounter     = 0;     // []

    m_plusCounter           = 0;     // +
    m_minusCounter          = 0;     // -

    m_isIf                  = false; // If
    m_isMain                = false; // Main
}

void Analyzer_t::printClosureError(const char& closureSign,const int& countNotClosed ) const
{
    if (countNotClosed > 0)
    {
        cout    << "Error - "       << countNotClosed 
                << "'"              << closureSign 
                << "' not closed."  << endl;
    }
}

void Analyzer_t::printMissingClosures() const
{
    printClosureError('(', m_roundBracCounter);
    printClosureError('{', m_curlyBracCounter);
    printClosureError('[', m_squareBracCounter);  
}

bool Analyzer_t::isClosure(const string& ch) const
{
    return (ch == "(" || ch == ")" || 
            ch == "[" || ch == "]" || 
            ch == "{" || ch == "}"      );
}

bool Analyzer_t::checkEnclosure(const string& token, size_t line)
{
    if (token == "if" || token == "else")
    {
        if (m_predefTypeFlag)
        {
            cout << "Line " << line << "error, illegal variable name" << endl;
            m_predefTypeFlag = false;
        }
        if (token == "if")
        {
            m_isIf = true;
        }
        else
        {
            if (m_isIf == false)
            {
                cout << "Line "<< line <<": error, else without if" << endl;
            }
        }
        
    }
    if (isClosure(token))
    {
        if (m_predefTypeFlag)
        {
            cout << "Line " << line << "error, illegal variable name" << endl;
            m_predefTypeFlag = false;
        }
        
        switch(token[0])
        {
            case '(' :  m_roundBracCounter++; return true; 
            case ')' :  m_roundBracCounter--;
                        if (m_roundBracCounter<0)
                        {
                            m_roundBracCounter = 0;
                            cout << "Line "<<line<<"- Error ')' without '('" << endl;
                        } return true;

            case '{' :  m_curlyBracCounter++; return true; 
            case '}' :  m_curlyBracCounter--;
                        if (m_curlyBracCounter<0)
                        {
                            m_curlyBracCounter = 0;
                            cout << "Line "<<line<<"- Error '}' without '{'" << endl;
                        } return true;

            case '[' :  m_squareBracCounter++; return true; 
            case ']' :  m_squareBracCounter--;
                        if (m_squareBracCounter<0)
                        {
                            m_squareBracCounter = 0;
                            cout << "Line "<<line<<"- Error ']' without '['" << endl;
                        } return true;

            default: return false;
        }
        
    }
}

bool Analyzer_t::isValidVar(const string& token) const
{
    return (isalpha(token[0]) || token[0] == '_');
}

bool Analyzer_t::nameTaken(const string& token) const
{
    return (m_takenVarNames.find(token) != m_takenVarNames.end());
}

void Analyzer_t::insertToNamesVector(const string& varName)
{
    m_takenVarNames.insert(varName);
}

void Analyzer_t::analyzeLine( Tokenizer_t& tokenizer, size_t line)
{
    vector <string>::iterator m_next ;
    m_next = tokenizer.getVector().begin();

    while (m_next != (tokenizer.getVector()).end())
    {
        analyzeToken(*m_next, line);
        m_next++;
    }
}

void Analyzer_t::analyzeToken(const string& token, size_t line)
{
    if (!m_isMain)
    {
        if (token != "main")
        {
            cout << "Line " << line <<"- no 'main' before" << endl;
        }
        m_isMain = true;
    }
    
    if (checkOperators(token,line))
    {
        return;
    }

    if (checkEnclosure(token,line))
    {
        return;
    }
    if (s_predefinedTypes.find(token) != s_predefinedTypes.end())
    {
        if (m_predefTypeFlag)
        {
            cout << "Line " << line << "- error, multiple type" << endl;
            m_predefTypeFlag = false;
        }
        else
        {
            m_predefTypeFlag = true;
        }
        return;
    }

    if (m_predefTypeFlag)
    {
        if (s_keyWords.find(token)          != s_keyWords.end() ||
            s_operators.find(token)         != s_operators.end() ||
            s_predefinedTypes.find(token)   != s_predefinedTypes.end())
        {
            cout << "Line " << line << "- error, illegal variable name" << endl;
        }
        else
        {
            if (nameTaken(token))
            {
                cout << "Line " << line << "- error, variable '"<<token<<"' already declared"<< endl;
            }
            else
            {
                if(isValidVar(token))
                {
                    m_takenVarNames.insert(token);
                }
                else
                {
                    cout <<"Line "<< line << "- error, illegal variable name" << endl;
                }           
            }
        }
        m_predefTypeFlag = false;
    }
    else
    {
        if (s_predefinedTypes.find(token)   == s_predefinedTypes.end()  &&
            s_keyWords.find(token)          == s_keyWords.end()         &&
            s_predefinedTypes.find(token)   == s_predefinedTypes.end()  &&
            isValidVar(token)                                           &&
            !nameTaken(token))
        {
            cout << "Line "<< line << "- error, "<< token << " is not declared"<<endl;
        }
    }   
}



