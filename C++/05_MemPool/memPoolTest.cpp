#include <iostream>
#include <string.h>
#include "memManager_t.h"
#include "memPage_t.h"

using namespace std;

int main()
{
    memPage_t p;
    int k=4, z=4, w=8;

    cout << "Actual size: " << p.getAcSize()<<endl;
    cout << "Capacity: "<< p.getCapacity()<<endl;

    p.write(&k,sizeof(int));
    p.read(&k,sizeof(int),0);
    cout<<"the number"<<k<<endl;
    cout<<"the index:"<<p.getCurPos()<<endl;

    p.write(&z,sizeof(int));
    p.read(&z,sizeof(int),4);
    cout<<"the number"<<z<<endl;
    cout<<"the index:"<<p.getCurPos()<<endl;

    p.write(&w,sizeof(int),2);
    p.read(&w,sizeof(int),2);
    cout<<"the number"<<w<<endl;
    cout<<"the index:"<<p.getCurPos()<<endl;
    cout << "Actual size: " << p.getAcSize()<<endl;

}   