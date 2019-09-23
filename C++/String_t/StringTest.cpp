#include <stdio.h>
#include "String_t.h"

int main()
{
    printf("Constructor of str1 and string2: \n");

    String_t s1("str1"), s2("string2");
    s1.printStr();
    printf("\n");
    s2.printStr();

    printf("\nCompare str1 to string2 : %d", s1.compareStr(s2));
    
    printf("\n Assignment of string2 to str1: ");
    s1=s2;
    printf("Printing both strings: \n");
    s1.printStr();
    printf("\n");
    s2.printStr();

    printf("\nLength of string2: %d\n", s2.getLength());

    printf("Get string 2: %s\n", s2.getString());

    char s3[8] = "STRING3";

    printf("Set STRING3 on str1\n");
    s1.setString(s3);
    printf("Printing STRING3 instead of str1:\n");
    s1.printStr();

}