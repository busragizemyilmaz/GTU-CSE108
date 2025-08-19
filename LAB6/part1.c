#include <stdio.h>
#include <math.h>

double findRepetitions(int array[10])
{
  int i;
  int frequencyArray[10] = {0};
  int count = 0;

  for (i = 0; i < 10; i++)
  {
    frequencyArray[array[i]]++;
  }

  for (i = 0; i < 10; i++)
  {
    if (frequencyArray[i] > 1)
    {
      count++;
    }
  }

  return count;
}

double findMean(int array[10])
{
  int i;
  double sum = 0;
  int count = 0;
  
  for (i = 0; i < 10; i++)
  {
    sum += array[i];
    count++;
  }
  
  return (sum / count);
}

double countEvens(int array[10])
{
  int i;
  int count = 0;

  for (i = 0; i < 10; i++)
  {
    if (array[i] % 2 == 0)
    {
      count++;
    }
  }
  
  return count;
}

double calculateStd(int array[10])
{
  int i;
  double sum1 = 0;
  int count = 0;
  double sum2 = 0;
  double mean;
  
  for (i = 0; i < 10; i++)
  {
    sum1 += array[i];
    count++;
  }
  
  mean = sum1 / count;
  
  for (i = 0; i < 10; i++)
  {
    sum2 += (array[i] - mean) * (array[i] - mean);
  }
  
  return sqrt((1.0/10) * sum2);
}

double applyFunction(int array[10], double (*function)(int array[10]))
{
  return function(array);
}

void main()
{
  int i;
  int array[10];
  
  printf("Enter 10 number for array: ");
  for (i = 0; i < 10; i++)
  {
    scanf("%d", &array[i]);
  }
  
  printf("\nRepetition: %.2f\n", applyFunction(array, findRepetitions));
  printf("Mean: %.2f\n", applyFunction(array, findMean));
  printf("Number of count evens: %.2f\n", applyFunction(array, countEvens));
  printf("Standard Deviation: %.2f\n", applyFunction(array, calculateStd));
}













