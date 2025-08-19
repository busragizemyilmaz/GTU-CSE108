#include <stdio.h>

int main()
{
   int a;
   int b;
   int c;
    
   printf("Enter length 1 for triangle: ");
   scanf("%d", &a);
   printf("Enter length 2 for triangle: ");
   scanf("%d", &b);
   printf("Enter length 3 for triangle: ");
   scanf("%d", &c);
    
   if ((a + b > c) && (a + c > b) && (b + c > a))
   {
      printf("\nValid Triangle\n");
   }
    
   else
   {
      printf("\nInvalid Triangle\n");
   }
    
   return 0;
}
