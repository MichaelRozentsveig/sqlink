#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class String_t
{
    public:
        //String_t(); // Default CTOR
        String_t(const char* str); //CTOR from const char*
        String_t(const String_t& str); // copy CTOR
        //~String_t(); // DTOR
        String_t& operator=(const String_t& str); // Assignment

        int getLength() const;
        char* getString() const;
        void setString(char* str);

        int compareStr(String_t& str) const;
        void printStr();
    private:

        char* name;
};