#include <iostream>
#include "tContainer_t.h"

using namespace std;

void intVector();
void charList();

int main()
{
    intVector();
    charList();         
}

void intVector()
{
    tContainer_t <int,vector<int*> > iArr;

    int* a = new int;
    int* b = new int;
    *a = 1;
    *b = 2;

    iArr.insertElement(a);
    iArr.insertElement(b);
    
    int* ip     = iArr.findElem(2) ;
    int* ip5    = iArr.findElem(10);

    cout    << "arr[0]= "   << *iArr[0] << endl;
    cout    << "arr[1]= "   << *iArr[1] << endl;

    cout    <<"First: "     << *(iArr.firstElem())  << endl  
            <<"Last: "      << *(iArr.lastElem())   << endl  
            <<"Find 2: "    << *ip                  << endl 
            <<"Find 10: "   << (iArr.findElem(10))  << endl;
    
    cout    << "Array Size Before removing 2= " << iArr.numOfElements() << endl;
    iArr.deleteElem(2);
    cout    << "Array Size after removing 2= " << iArr.numOfElements() << endl;

    cout    << "Array Size Before removing all= " << iArr.numOfElements() << endl;
    iArr.removeAllElems();
    cout    << "Array Size after removing all= " << iArr.numOfElements() << endl;  

    iArr.deleteAllElems();
    cout    << "Delete Array: "     << endl
            << "Find 6 in Array: "  << (iArr.findElem(6)) << endl << endl;
}

void charList()
{
    tContainer_t <char,list<char*> > cList;

    char* a = new char;
    char* k = new char;

    *a = 'a';
    *k = 'k';

    cList.insertElement(a);
    cList.insertElement(k);

    char* cp    = cList.findElem('k');
    char* cp1   = cList.findElem('t');

    //cout << typeid(tContainer_t <char,list<char*> >).name() << endl << typeid(cList).name() << endl ;
    cout    << "List[0]= "   << *cList[0] << endl;
    cout    << "List[1]= "   << *cList[1] << endl;

    cout    <<"First: "     << *(cList.firstElem()) << endl  
            <<"Last: "      << *(cList.lastElem())  << endl  
            <<"Find k: "    << *cp                  << endl ;
    
    cout    << "Size before deleting k: "   << cList.numOfElements() << endl;
    cList.removeElem('k');
    cout    << "Size after deleting k: "    << cList.numOfElements() << endl;

    cList.removeAllElems();
    cout    << "Size after deleting all: "  << cList.numOfElements() << endl;

}
