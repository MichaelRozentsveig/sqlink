#include <iostream>
#include <string.h>
#include <ctype.h>
#include "String_t.h"
using namespace std;

String_t::String_t(const char* str)
{
    if (str == NULL)
    {
        this->name = new char[32];
        name[0] = '\0';
    }
    else
    {
        this->name = new char[strlen(str)+1];
        strcpy(this->name, str);    
    }   
}

String_t::~String_t()
{
    delete[](this->name);
}

String_t& String_t::operator=(const String_t& str)
{
    if (this != &str)
    {
        delete[] name;
        name = str.getString();
    }
    return *this;
}

int String_t::getLength() const
{
    return strlen(this->name);
}

char* String_t::getString() const
{
    return this->name;
}

void String_t::setString(const char* str)
{
    delete[](this->name);
    this->name = new char[strlen(str)+1];
    strcpy(this->name,str);
}

int String_t::compareStr(String_t& str) const
{
    if (strcmp(this->name, str.name)==0)
    {
        return 0;
    }
    else if(strcmp(this->name,str.name)>0)
    {
        return 1;
    }
    return 2;
}
void String_t::printStr()
{
    cout << this->name << endl ;
}

void String_t::lowCase()
{
    int i=0;
    while ((this->name[i])!= '\0')
    {
        this->name[i] = tolower(this->name[i]);
        i++;
    }
}

void String_t::upperCase()
{
    int i=0;
    while ((this->name[i])!= '\0')
    {
        this->name[i] = toupper(this->name[i]);
        i++;
    }
}

void String_t::prepend(const char* str)
{
    char temp[32];
    strcpy(temp,this->name);
    this->setString(str);
    strcat(this->name,temp);
}

void String_t::prepend(const String_t& str)
{
    char temp[32];
    strcpy(temp,this->name);
    this->setString(str.name);
    strcat(this->name,temp);
}

String_t& String_t::operator+=(const String_t& str )
{
    char temp[64];
    strcpy(temp, this->name);
    strcat(temp,str.name);
    delete[] this->name;
    this->name = new char[strlen(temp)+1];
    strcpy(this->name,temp);

    return *this;
}

String_t& String_t::operator+=(const char* str )
{
    char temp[64];
    strcpy(temp, this->name);
    strcat(temp,str);
    delete[] this->name;
    this->name = new char[strlen(temp)+1];
    strcpy(this->name,temp);

    return *this;
}

int String_t::operator< (const  String_t& st)
{
    int res=strcmp(this->name,st.name);
    return(res<0? 1: 0);
}

int String_t::operator> (const  String_t& st)
{
    int res=strcmp(this->name,st.name);
    return(res>0);
}
int String_t::operator>=(const  String_t& st)
{
    int res=strcmp(this->name,st.name);
    return(res>=0? 1: 0);
}

int String_t::operator<= (const  String_t& st)
{
    int res=strcmp(this->name,st.name);
    return(res<=0? 1: 0);
}

int String_t::operator== (const  String_t& st)
{
    int res=strcmp(this->name,st.name);
    return(res==0? 1: 0);
}
int String_t::operator!= (const  String_t& st)
{
    int res=strcmp(this->name,st.name);
    return(res!=0? 1: 0);
}
int String_t::contains (const char* str) const 
{
    return (strstr(this->name, str) == NULL ? 0 : 1) ;    
}

ostream& operator<<( ostream& os ,const String_t& st)
{
    os <<st.getString()<<endl;
    return os;
}

istream& operator>>( istream& is , String_t& st)
{   
    char str1[128];
    is >>str1;
    st.setString(str1);
    return is;
}
 
char String_t::operator[] (unsigned int i) const 
{
    if (i>strlen(this->name))
    {
        return 0;
    } 
    return this->name[i]; 
}