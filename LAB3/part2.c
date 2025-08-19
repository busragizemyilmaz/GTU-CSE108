#include <stdio.h>

int isPerfect(int num)
{
  int i;
  int sum = 0;
  
  if (num != 1)
  {
    for (i = 1; i < num; i++)
    {
      if (num % i == 0)
      {
        sum += i;
      }
    }
  }
   
  if (sum == num)
  {
    return 1;
  }
  
  else
  {
    return 0;
  }  
}

void printPerfect(int start, int end)
{
  for (int i = start + 1; i < end; i++)
  {
    if (isPerfect(i) == 1)
    {
      printf("%d ", i);
    }
  }
  
  printf("\n");
}

int main()
{
  int start;
  int end;
  
  printf("Enter lower number: ");
  scanf("%d", &start);

  printf("Enter upper number: ");
  scanf("%d", &end);
  
  printPerfect(start, end);
  
  return 0;
}






