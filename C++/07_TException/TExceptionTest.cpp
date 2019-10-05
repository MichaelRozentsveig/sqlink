#include "TException_t.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
    try
    {
        throw TException_t<string>(__FILE__,"ABCDE","Failed string",__LINE__);
    }
    catch(const TException_t<string>& e)
    {
        cerr    << endl
                << "String Exception Caught!"<< endl
                << "File name: "        << e.getSrcName() << endl 
                << "Object thrown: "    << e.getThrownObj() << endl 
                << "What happend: "     << e.getTxtDescription() << endl
                << "Line: "             << e.getLine() << endl << endl;
    }

    try
    {
        throw TException_t<int>(__FILE__,111, "Failed int",__LINE__);
    }
    catch(const TException_t<int>& e)
    {
        cerr    << "Int Exception Caught!"<< endl
                << "File name: "        << e.getSrcName() << endl 
                << "Object thrown: "    << e.getThrownObj() << endl 
                << "What happend: "     << e.getTxtDescription() << endl
                << "Line: "             << e.getLine() << endl << endl;
    }
    
    return 0;
}
