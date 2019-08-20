#include <stdio.h>


int main()
 { 
   unsigned int n;
   printf("enter the number:");
   scanf("%u",&n);

   result= factorial(n);
   printf("%d",n);
    
  }

unsigned factorial( unsigned int)
{
  if (n==0| n==1)
   {
    return 1;
   }
  else
   {
    return factorial((n-1)*n));
    }
}
 




}