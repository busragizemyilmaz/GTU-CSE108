#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, j;
  int length;
  int *array;
  int money;
  int total;
  int leftover;
  int temp;
  
  printf("Enter length: ");
  scanf("%d", &length);
  
  array = (int *)malloc(length * sizeof(int));
  
  printf("Prices: ");
  for (i = 0; i < length; i++)
  {
    scanf("%d", &array[i]);
  }
  
  printf("Money: ");
  scanf("%d", &money);
  
  for (i = 0; i < length; i++)
  {
    for (j = 0; j < i; j++)
    {
      if (array[j] > array[j + 1])
      {
        temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
  
  for (i = length - 1; i >= 1; i--)
  {
    total = array[i] + array[i - 1];
    
    if (total <= money)
    {
      leftover = money - total;

      printf("\nLeftover: %d\n", leftover);

      return 1;
    }
  } 
  
  printf("\nYou have not money for to buy two chocolate. Leftover: %d\n", money);
  
  free(array);
  
  return 0;
}
