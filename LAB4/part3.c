#include <stdio.h>

int factorial(int n)
{
  int i;
  int product = 1;
  
  for (i = 1; i <= n; i++)
  {
    product *= i;
  }
  
  return product;
}

int binomialCoeff(int n, int k)
{
  int result;
  
  result = factorial(n) / (factorial(k) * factorial(n - k));
  
  return result;
}

void main()
{
  int i, space, j;
  int n;
  
  printf("Enter number of rows: ");
  scanf("%d", &n);
  
  for (i = 0; i < n; i++)
  {
    for (space = 0; space < n - i - 1; space++)
    {
      printf(" ");
    }
    
    for (j = 0; j <= i; j++)
    {
      printf("%d ", binomialCoeff(i,j));
    }
    
    printf("\n");
  }  
}
