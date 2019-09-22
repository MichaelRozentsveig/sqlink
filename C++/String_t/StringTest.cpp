#include <iostream>
using namespace std;
#include "String_t.h"

int main()
{
    String_t s1("Mike"), s2("Stas");

    s1.printStr();
    cout << endl;
    cout << s1.compareStr(s2) << endl;
    s1.printStr();
    cout << endl;

    char s3[7] = "Shpike";
    s1.setString(s3);
    cout << endl;
    s1.printStr();
    cout << endl;
    cout << s2.getLength() << endl << s2.getString() << endl;


}