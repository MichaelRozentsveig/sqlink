#include <stdio.h>

int B()
{
    printf("I'm B MUAHAHA\n");
    return 1;
}

void A(int a)
{
    
    printf("Im A\n");

    *(&a-1)= (int)B;    
}

int main()
{
    A(0);

    return 0;
} 