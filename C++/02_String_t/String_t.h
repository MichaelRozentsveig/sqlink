#ifndef STR_H
#define STR_H

#include <iostream>
using namespace std;

class String_t
{
    public:
        //String_t(); // Default CTOR
        String_t(const char* str); //CTOR from const char*
        String_t(const String_t& str); // copy CTOR
        ~String_t(); // DTOR
        String_t& operator=(const String_t& str); // Assignment

        int getLength() const;
        char* getString() const;
        void setString(const char* str);

        int compareStr(String_t& str) const;
        void printStr();

        void lowCase();
        void upperCase();
        void prepend(const char* str);
        void prepend(const String_t& str);
        String_t& operator+=(const char* str);
        String_t& operator+=(const String_t& str);
        int operator< (const  String_t& st);
        int operator> (const  String_t& st);
        int operator>=(const  String_t& st);
        int operator<= (const  String_t& st);
        int operator== (const  String_t& st);
        int operator!= (const  String_t& st);
        int contains (const char* nm) const ;
        char operator[] (unsigned int i) const ;

    private:

        char* name;
};

ostream& operator<<( ostream& os ,const String_t& st);
istream& operator>>( istream& is , String_t& st);

#endif