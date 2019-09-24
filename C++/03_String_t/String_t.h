#ifndef STR_H
#define STR_H

#include <iostream>
using namespace std;

class String_t
{
    public:
        String_t(); // CTOR
        String_t(const char* str); //CTOR from const char*
        String_t(const String_t& str); // copy CTOR
        ~String_t(); // DTOR
        String_t& operator=(const String_t& str); // Assignment

        char* createFrom(const char *str);

        int getLength() const;
        const char* getString() const;
        void setString(const char* str);

        int compareStr(String_t& str) const;
        void printStr();

        void lowCase();
        void upperCase();
        String_t& prepend(const char* str);
        String_t& prepend(const String_t& str);
        String_t& operator+=(const char* str);
        String_t& operator+=(const String_t& str);

        int operator< (const  String_t& st) const;
        int operator> (const  String_t& st) const ;
        int operator>=(const  String_t& st)const;
        int operator<= (const  String_t& st) const;
        int operator== (const  String_t& st) const;
        int operator!= (const  String_t& st) const;
        int contains (const char* nm) const ;
        char operator[] (unsigned int i) const ;

        static int nOfStrings (){return countStrings;}
        static bool getCaseSens (){return caseSens;}
        static bool setCaseSensOn(){bool prev = caseSens; caseSens = true; return prev;}
        static bool setCaseSensOff(){bool prev = caseSens; caseSens = false; return prev;}
        static int getDefCapacity (){return defaultCapacity;}
        static void setDefCapacity(int defCap) {defaultCapacity = nextPowerOf2 (defCap);}

        int firstOccOfChar(char c) const;
        int lastOccOfChar(char c) const;

        char* operator()(int start, int len) const;


    private:

        char* name;
        static int countStrings;
        static bool caseSens;
        int capacity;
        static int defaultCapacity;
        static unsigned int nextPowerOf2(unsigned int n);

};

ostream& operator<<( ostream& os ,const String_t& st);
istream& operator>>( istream& is , String_t& st);

#endif