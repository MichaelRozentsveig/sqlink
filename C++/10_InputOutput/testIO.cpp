#include <iostream>
#include <string.h>
#include <stdio.h>
#include "virtIO_t.h"
#include "asciiIO_t.h"
#include "binIO_t.h"

using namespace std;

void testFunc(virtIO_t * vio);

int main()
{     
    int choose=0;
    string path;
    string mode;

    cout    <<  "Enter path"    << endl;
    cin     >>  path;
    cout    <<  "Enter mode"    << endl;
    cin     >>  mode;
    cout    <<  "Choose:"       << endl
            <<  "1 >>> Ascii"   << endl
            <<  "2 >>> Binary"  << endl;

    cin     >>  choose;
    virtIO_t * vio;

    switch(choose)
    {
        case 1:      
            try
            {    
                vio=new asciiIO_t(path,mode); 
                testFunc(vio); 
                delete vio;     
            }
            catch(int) 
            {
                cout<<"can't open file"<<endl;
            }
            break;
        
        case 2:
            try
            {
                vio = new binIO_t(path,mode);
                testFunc(vio);
                delete vio;
            }
            catch(int) 
            {
                cout<<"can't open file"<<endl;
            }
            
        default: 
            break;
    }   
    return 0;
}

void testFunc(virtIO_t * vio)
{
    int iVar;
    float fVar;
    int num =0;
    int choose=1;

    binIO_t* bio;

    while(choose)
    {
        cout<<" 1       >>>  Close"         <<endl
            <<" 2       >>>  Get path "     <<endl
            <<" 3       >>>  Get mode"      <<endl
            <<" 4       >>>  Get length "   <<endl
            <<" 5       >>>  Get position " <<endl
            <<" 6       >>>  Set position"  <<endl
            <<" 7       >>>  Get status "   <<endl
            <<" 8       >>>  Operator>>"    <<endl
            <<" 9       >>>  Operator<<"    <<endl
            <<"10       >>>  Void buffer <<"<<endl
            <<"11       >>>  Void buffer >>"<<endl
        
            <<" Other   >>>  Exit "         <<endl;

        cin>>choose;

        switch(choose)
        {
            case 1: 

                if (bio->getStatus() != virtIO_t::cant_open_file_e && bio->getStatus() != virtIO_t::bad_access_e )
                {
                    vio->closeFile();
                }
                else 
                {
                    cout<<"null pointer!"<<endl;
                }
                break;

            case 2: 

                if (bio->getStatus() != virtIO_t::cant_open_file_e && bio->getStatus() != virtIO_t::bad_access_e )
                {
                    string path=vio->getPath();
                    cout<<"path= "<<path<<endl;
                }
                else 
                {
                    cout<<"null pointer!"<<endl;
                }
                break;

            case 3: 

                if (bio->getStatus() != virtIO_t::cant_open_file_e && bio->getStatus() != virtIO_t::bad_access_e )
                {   
                    string mode=vio->getMode();
                    cout<<"mode= "<<mode<<endl;
                }
                else 
                {
                    cout<<"null pointer!"<<endl;
                }
                break;

            case 4: 

                if (bio->getStatus() != virtIO_t::cant_open_file_e && bio->getStatus() != virtIO_t::bad_access_e )
                {
                    long len=vio->getFileLength();
                    cout<<"length= "<<len<<endl;
                }
                else  
                {
                    cout<<"null pointer!"<<endl;
                }
                break;

            case 5: 

                if (bio->getStatus() != virtIO_t::cant_open_file_e && bio->getStatus() != virtIO_t::bad_access_e )
                {
                    long pos=vio->getPos();
                    cout<<"pos= "<<pos<<endl;
                }
                else 
                {
                    cout<<"null pointer!"<<endl;
                }
                break;

            case 6: 

                if (bio->getStatus() != virtIO_t::cant_open_file_e && bio->getStatus() != virtIO_t::bad_access_e )
                { 
                    long pos;
                    cout<<"enter position"<<endl;
                    cin>>pos;
                    vio->setPos(pos);
                }
                else 
                {
                    cout<<"null pointer!"<<endl;
                }
                break;

            case 7: 

                if (bio->getStatus() != virtIO_t::cant_open_file_e && bio->getStatus() != virtIO_t::bad_access_e )
                {
                    cout<<"status= "<<vio->getStatus()<<endl;
                }
                else 
                {
                    cout<<"null pointer!"<<endl;
                }
                break;

            case 8: 

                if (bio->getStatus() != virtIO_t::cant_open_file_e && bio->getStatus() != virtIO_t::bad_access_e )
                {              
                    *vio     >>  num;
                    cout    <<  num     << endl;
                }
                else
                {
                    cout<<"null pointer! "<<endl;
                }
                break;

            case 9: 

                if (bio->getStatus() != virtIO_t::cant_open_file_e && bio->getStatus() != virtIO_t::bad_access_e )
                {
                    cout    <<  "enter num"<<endl;
                    cin     >>  num;
                    *vio     <<  num;
                }
                else
                {
                    cout<<"null pointer! "<<endl;
                }
                break;
            
            case 10:

                bio = dynamic_cast<binIO_t*> (vio);
                if (bio->getStatus() != virtIO_t::cant_open_file_e && bio->getStatus() != virtIO_t::bad_access_e )
                {         
                    int length;   
                    char buffer[64]= {0};
                    cout << "Enter size to read:" << endl;
                    cin >> length;
                    try
                    {
                        *bio >> (void*)buffer, length;
                        cout << buffer << endl;
                    }
                    catch(virtIO_t::statusFile)
                    {
                        cout << "Failed" << endl;
                    }                   
                }
                else
                {
                    cout << "Null pointer" << endl;
                }
                
                break;
            
            case 11:

                bio = dynamic_cast<binIO_t*> (vio);
                if (bio->getStatus() != virtIO_t::cant_open_file_e && bio->getStatus() != virtIO_t::bad_access_e )                
                {                   
                    char buffer[64];
                    cout << "Enter string:" << endl;
                    cin >> buffer;

                    *bio << (void*) buffer, 3;
                }
                else
                {
                    cout << "Null pointer" << endl;
                } 
                break;

            default: break;                
        }
    }
}

    
  /*  binIO_t*  bIO = new binIO_t("check.txt","wb");
    char name[16] = "abcd";
    *bIO <<  i  << f ;
    *bIO >>  i  >> f ; 
    *bIO <<  name , 3;*/