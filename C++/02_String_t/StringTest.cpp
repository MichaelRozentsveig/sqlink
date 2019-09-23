#include <iostream>
#include "String_t.h"
using namespace std;

int main()
{
    cout<<"Constructor of str1 and string2:"<< endl;

    String_t s1("str1"), s2("string2");
    s1.printStr();
    s2.printStr();

    cout<<endl<<"Compare str1 to string2:" << s1.compareStr(s2)<<endl;
    
    cout<<endl<< "Assignment of string2 to str1:" ;
    s1=s2;
    cout << "Printing both strings:" << endl;
    s1.printStr();
    s2.printStr();

    cout<<endl<< "Length of string2: "<< s2.getLength()<< endl;

    cout<<"Get string 2: " << endl << s2.getString()<< endl;

    char s3[8] = "STRING3";

    cout<< "Set STRING3 on str1"<< endl;
    s1.setString(s3);
    cout<<"Printing STRING3 instead of str1: "<< endl;
    s1.printStr();

    cout<< "To Lower from STRING3: "<< endl; 
    s1.lowCase();
    cout<< s1 << endl;

    cout<<"STRING3 < string2: "<< (s1<s2) << endl;
    cout<<"STRING3 > string2: "<< (s1>s2) << endl;
    cout<<"STRING3 <= string2: "<< (s1<=s2) << endl;
    cout<<"STRING3 >= string2: "<< (s1>=s2) << endl;
    cout<<"STRING3 == string2: "<< (s1==s2) << endl;
    cout<<"STRING3 != string2: "<< (s1!=s2) << endl;

    cout<<"STRING3 contains RING? "<< s1.contains("ring")<<endl;
    cout<<"STRING3 contains BBB? "<< s1.contains("BBB")<<endl;

    cout<<"STRING3 char at index 2: "<< s1[2]<<endl;
}