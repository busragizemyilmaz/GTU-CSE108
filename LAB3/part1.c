#include <stdio.h>

int isPrime(int num)
{  
  int i;
  int flag = 0;

  if(num % 2 == 0 && num != 2)
  {
    return 0;
  }
  
  else
  {
    if (num == 2)
    {
      return 1;
    }
      
    else if (num == 1)
    {
      return 0;
    }
      
    else
    {
      for (i = 2; i < num; i++)
      {
        if (num % i == 0)
        {
          flag = 1;

          return 0;
        }
      } 

      if (!flag)
      {
        return 1;
      }
    }  
  }
}

void printPrimes(int lowerLimit, int upperLimit)
{
  int i;

  for (i = lowerLimit + 1; i < upperLimit; i++)
  {
    if (isPrime(i) == 1)
    {
      printf("%d ", i);    
    }
  }
  
  printf("\n");
}

int main()
{
  int lower_number;
  int upper_number;
  
  printf("Enter lower number: ");
  scanf("%d", &lower_number);
  
  printf("Enter upper number: ");
  scanf("%d", &upper_number);
  
  printPrimes(lower_number, upper_number);
  
  return 0;
}
