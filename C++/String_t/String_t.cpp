#include <stdio.h>
#include <string.h>
#include "String_t.h"

String_t::String_t(const char* str)
{
    this->name = new char[strlen(str)+1];
    strcpy(this->name, str);
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
void String_t::setString(char* str)
{
    this->name = str;
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
    printf("%s\n",this->name ) ;
}