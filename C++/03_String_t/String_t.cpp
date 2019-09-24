#include <iostream>
#include <string.h>
#include <ctype.h>
#include "String_t.h"
using namespace std;

int String_t::countStrings = 0;
int String_t::defaultCapacity = 16;
bool String_t::caseSens = true;

static char* concat(const char* firstStr,const char* secondStr);
unsigned int String_t::nextPowerOf2(unsigned int n)  
{  
    unsigned count = 0;     
    if (n && !(n & (n - 1))) 
    { 
        return n;  
    }
    while( n != 0)  
    {  
        n >>= 1;  
        count += 1;  
    }      
    return 1 << count;  
} 
unsigned int nextPowerTo2(unsigned int n)  
{  
    unsigned count = 0;     
    if (n && !(n & (n - 1))) 
    { 
        return n;  
    }
    while( n != 0)  
    {  
        n >>= 1;  
        count += 1;  
    }      
    return 1 << count;  
} 

char* String_t::createFrom(const char *str)
{
    char *tmp = new char[nextPowerOf2(strlen(str) + 1)];
    strcpy(tmp, str);
    return tmp;
}

String_t::String_t(const char* str)
{
    if(str==NULL)
    {
       this->name=new char [defaultCapacity];
       name[0]='\0';  
       this->capacity=defaultCapacity;
    }
    else
    {
    this->name = createFrom(str);
    this->capacity = nextPowerOf2(strlen(str)+1);
    } 
    countStrings++;  
}
String_t::String_t()
{
    this->name = createFrom("");
    this->capacity = defaultCapacity;
    countStrings++;
}

String_t::~String_t()
{
    delete[](this->name);
    countStrings--;
}

String_t& String_t::operator=(const String_t& str)
{
    if (this != &str)
    {
        delete[] name;
        name = (char*)str.getString();
    }
    return *this;
}

int String_t::getLength() const
{
    return strlen(this->name);
}

const char* String_t::getString() const
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

String_t& String_t::prepend(const char* str) // FIX THIS
{

    char* ans = concat(str,this->name);
    this->name = new char[nextPowerOf2(strlen(str)+strlen(this->name)+1)];
    this->name = ans;

    return *this;
}

String_t& String_t::prepend(const String_t& str)
{
    char* ans = concat(str.name,this->name);
    this->name = new char[nextPowerOf2(strlen(str.name)+strlen(this->name)+1)];
    this->name = ans;
    return *this;        
}

String_t& String_t::operator+=(const String_t& str )
{
    char* ans = concat(this->name,str.name);
    this->name = new char[nextPowerOf2(strlen(str.name)+strlen(this->name)+1)];
    this->name = ans;
    return *this;
}

String_t& String_t::operator+=(const char* str )
{
    char* ans = concat(this->name,str);
    this->name = new char[nextPowerOf2(strlen(str)+strlen(this->name)+1)];
    this->name = ans;
    return *this;
}

static char* concat(const char* firstStr,const char* secondStr)
{
    char* temp = new char[nextPowerTo2(strlen(firstStr)+strlen(secondStr)+1)];
    strcpy(temp,firstStr);
    strcat(temp,secondStr); 
    return temp;
    
}
int String_t::operator< (const  String_t& st) const
{
    int res=strcmp(this->name,st.name);
    return(res<0);
}

int String_t::operator> (const  String_t& st) const
{
    int res=strcmp(this->name,st.name);
    return(res>0);
}
int String_t::operator>=(const  String_t& st) const
{
    int res=strcmp(this->name,st.name);
    return(res>=0);
}

int String_t::operator<= (const  String_t& st) const
{
    int res=strcmp(this->name,st.name);
    return(res<=0);
}

int String_t::operator== (const  String_t& st) const
{
    int res=strcmp(this->name,st.name);
    return(res==0);
}
int String_t::operator!= (const  String_t& st) const
{
    int res=strcmp(this->name,st.name);
    return(res!=0);
}
int String_t::contains (const char* str) const 
{
    if (caseSens==true)
    {
    return (strstr(this->name, str) != NULL) ;  
    }
    else
    {
        char* temp1 = new char[strlen(name)+1];
        char* temp2 = new char[strlen(str)+1];
        strcpy(temp1,name);
        strcpy(temp2,str);
        int i=0,j=0;
        for (i=0;i<strlen(temp1);i++)
        {
            temp1[i] = tolower(temp1[i]);
        }
        for (j=0; j<strlen(temp2);j++)
        {
            temp2[j] = tolower(temp2[j]);
        }
        return (strstr(this->name, str) != NULL) ;  
    }    
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

int String_t::firstOccOfChar(char c) const
{
    int i=0;
    int length= strlen(this->name);
    if (caseSens==true)
    {
        for (i=0;i<length;i++)
        {
            if (name[i]==c)
            {
                return i;
            }
        }
    }
    else
    {
        for(i=0;i<strlen(this->name);i++)
        {
            if((this->name[i]==toupper(c))||(this->name[i]==tolower(c)))
            {
            return i;
            }
        }
    }
    return -1;
}

int String_t::lastOccOfChar(char c) const
{
    int i=strlen(this->name);
    if (caseSens==true)
    {
        for (;i>=0;i--)
        {
            if (name[i]==c)
            {
                return i;
            }
        }
    }
    else
    {
        for (;i>=0;i--)
        {
            if ((name[i]==tolower(c))|| name[i] == toupper(c))
            {
                return i;
            }
        }
    }
    return -1;
}

char* String_t::operator()(int start, int len) const
{
    char* temp = new char[len+1];
    strncpy(temp,name+start,len);
    return temp;
}
