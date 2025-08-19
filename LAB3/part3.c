#include <stdio.h>

void Year_Control(int n)
{
  if (n % 4 == 0 && n % 100 != 0)
  {
    printf("%d is a leap year.", n);
  }
  
  else if (n % 400 == 0)
  {
    printf("%d is a leap year.\n", n);
  }
  
  else
  {
    printf("%d is not a leap year.\n", n);
  } 
}

int main()
{
  int year;
  
  printf("Please enter the year: ");
  scanf("%d", &year);
  
  Year_Control(year); 

  return 0;
}
