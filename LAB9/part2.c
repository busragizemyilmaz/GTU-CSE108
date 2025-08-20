#include <stdio.h>

int powerOfTwo(int power)
{
  int i;
  int result = 1;
  
  for (i = 0; i < power; i++)
  {
    result *= 2;
  }
  
  return result;
}

int binaryToDecimal(int n, int power)
{
  int result = (n % 10) * powerOfTwo(power);

  if (n > 0)
  {
    result += binaryToDecimal(n / 10, power + 1);
  }
  
  return result;
}

void main()
{
  int number;
  int number2;
  int power = 0;
  int result;
  int flag;
  
  do {
    flag = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    number2 = number;

    while (number2 > 0)
    {
      if ((number2 % 10 != 0) && (number2 % 10 != 1))
      {
        flag = 1;

        printf("You must enter binary number. The number should contain only 0s and 1s.\n");

        break;
      }

      number2 /= 10;
    }
  } while (flag);
  
  result = binaryToDecimal(number, power);
  printf("Output: %d\n", result);
}
