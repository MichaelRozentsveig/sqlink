#ifndef AN_H
#define AN_H
#include "Tokenizer.h"

#include <string>
#include <vector>
#include <set>

using namespace std;

class Analyzer_t
{
    public:

        Analyzer_t          (){}
        virtual ~Analyzer_t (){}
        void init();

        void analyzeToken       (const string& token, size_t line);
        void analyzeLine        (const Tokenizer_t& tokenizer, size_t line);


    protected:

        bool checkEnclosure     (const string& token, size_t line) ;

        bool checkOperators     (const string& token, size_t line)  ;

        void printClosureError  (const char& closureSign,const int& countNotClosed ) const;

        void treatClosure       (const string& token, size_t line);

        bool isValidVar         (const string& token) const;

        bool isClosure          (const string& ch) const;

        bool nameTaken          (const string& token) const ;

        void insertToNamesVector(const string& varName);

        void printMissingClosures() const;
        

    private:
        int     m_roundBracCounter;     // ()
        int     m_curlyBracCounter;     // {}
        int     m_squareBracCounter;    // []

        int     m_plusCounter;          // +
        int     m_minusCounter;         // -

        bool    m_isIf;
        bool    m_predefTypeFlag;       
        bool    m_isMain;

        set <string> m_takenVarNames;

        const static string     m_preDefTypes   [];
        const static string     m_keyWords      [];
        const static string     m_operators     [];
        const static string     m_predefTokens  [];  

        static set<string>      s_predefinedTypes;
	    static set<string>      s_keyWords;
	    static set<string>      s_operators;
	    static set<string>      s_predefTokens;

};


#endif