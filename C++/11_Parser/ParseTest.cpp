#include <iostream>
#include "Parser.h"

using namespace std;

int main(int argc, const char* argv[])
{
    Parser_t p;
    
    cout << endl;
    try
    {
        for (int i = 1; i < argc; ++i)
        {
            cout << endl << "RESULT : " << argv[i] << endl;
            p.parseFile(argv[i]);
            cout << endl;
        }
    }
    catch (string)
    {
        cout << "Failed"<< endl;
    }
    return 0;
}