#ifndef AN_H
#define AN_H


using namespace std;

class Analyzer_t
{
    public:

        Analyzer_t():
            m_preDefTypes   ({"char","short","int","long","float","double","void"}),
            m_keyWords      ({"if","else","for","while","class","private","public","protected","main","const","virtual"}),
            m_operators     ({"++","--","==","->","=","+","-","*","&","<<",">>"})
        {

        }

        void analyze();

        void checkOperators();


    private:
        int     m_roundBracCounter;     // ()
        int     m_curlyBracCounter;     // {}
        int     m_squareBracCounter;    // []
        int     m_pointyBracCounter;    // <>
        
        const string&  m_preDefTypes   [];
        const string&  m_keyWords      [];
        const string&  m_operators     [];

}


#endif