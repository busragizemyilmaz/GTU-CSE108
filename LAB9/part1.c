#include <stdio.h>

void print_digits(int n)
{
  if (n >= 0)
  {
    if (n >= 10)
    {
      print_digits(n / 10);
    }

    printf("%d ", n % 10);
  }
  
  else
  {
    printf("You can not enter negative number.");
  }
}

void main()
{
  int number;
  
  printf("Enter a number: ");
  scanf("%d", &number);
  
  printf("Output: ");
  print_digits(number);
  printf("\n");
}
