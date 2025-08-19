#include <stdio.h>

void main()
{
  int n;
  int reversed = 0;
  int isNegative = 0;
  
  printf("Enter a number: ");
  scanf("%d", &n);
  
  if (n < 0)
  {
    isNegative = 1;
    n = -n;   
  }
  
  while (n > 0)
  {
    reversed = (reversed * 10) + (n % 10);
    n /= 10;
  }
  
  if (isNegative == 1)
  {
    reversed = -reversed;
  }
  
  printf("Reversed number: %d\n", reversed); 
}
