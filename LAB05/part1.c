#include <stdio.h>

int generateCollatzSequence(int start, int length, FILE *file)
{
  int i;

  file = fopen("collatz.txt", "w");

  fprintf(file, "%d\n", start);
  printf("\nGenerated Collatz Sequence: \n");
  printf("%d\n", start);
  
  for (i = 0; i < length - 1; i++)
  {
    if (start % 2 == 0)
    {
      start /= 2;

      fprintf(file, "%d\n", start);
      printf("%d\n", start);    
    }
    
    else
    {
      start = (start * 3) + 1;

      fprintf(file, "%d\n", start);
      printf("%d\n", start); 
    }
  }
  
  fclose(file);

  return start;
}

void convertToBinary(int n, FILE *file)
{
  int i = 0, j;
  int binary[32];
  
  file = fopen("collatz.txt", "a");

  fprintf(file, "Decimal : %d\n", n);
  printf("\nDecimal : %d\n", n);
  
  while (n > 0)
  {
    binary[i] = n % 2;
    n /= 2;
    i++;
  }
  
  fprintf(file, "Decimal to Binary Conversion: ");
  printf("Decimal to Binary Conversion: ");
  
  for (j = i - 1; j >= 0; j--)
  {
    fprintf(file, "%d", binary[j]);
    printf("%d", binary[j]);
  }
  
  printf("\n");

  fclose(file);
}

void convertToHex(int n, FILE *file)
{
  int i = 0, j;
  char binary[32];
  int remainder;
  
  file = fopen("collatz.txt", "a");

  fprintf(file, "Decimal : %d\n", n);
  printf("\nDecimal : %d\n", n);
  
  while (n > 0)
  {
    remainder = n % 16;
    
    if (remainder < 10)
    {
      binary[i] = '0' + remainder;

    }
    
    else
    {
      binary[i] = 'A' + (remainder - 10);
    }
    
    n /= 16;
    i++;
  }
  
  fprintf(file, "Decimal to Hexadecimal Conversion: ");
  printf("Decimal to Hexadecimal Conversion: ");
  
  for (j = i - 1; j >= 0; j--)
  {
    fprintf(file, "%c", binary[j]);
    printf("%c", binary[j]);
  }  
  
  printf("\n");

  fclose(file);  
}

void convertToOctal(int n, FILE *file)
{
  int i = 0, j;
  int binary[32];
  
  file = fopen("collatz.txt", "a");

  fprintf(file, "Decimal : %d\n", n);
  printf("\nDecimal : %d\n", n);
  
  while (n > 0)
  {
    binary[i] = n % 8;
    n /= 8;
    i++;
  }
  
  fprintf(file, "Decimal to Octal Conversion: ");
  printf("Decimal to Octal Conversion: ");
  
  for (j = i - 1; j >= 0; j--)
  {
    fprintf(file, "%d", binary[j]);
    printf("%d", binary[j]);
  } 
  
  printf("\n");

  fclose(file);
}

void main()
{
  int number;
  int term;
  int return_value;
  int choice;
  FILE *file;
  
  do {
    printf("Enter the starting number of the Collatz Sequence: ");
    scanf("%d", &number);
    printf("Enter how many terms to generate: ");
    scanf("%d", &term);

    if (number <= 0 || term <= 0)
    {
      printf("\nYou must enter positive integers both of them.\n\n");
    }
  }
  while (number <= 0 || term <= 0);
  
  return_value = generateCollatzSequence(number, term, file);
  printf("\nLast number in sequence: %d\n", return_value);
  
  printf("\nChoose a conversion:\n");
  printf("1. Decimal to Binary\n");
  printf("2. Decimal to Hexadecimal\n");
  printf("3. Decimal to Octal\n");
  printf("Your choice: ");
  scanf("%d", &choice);
  
  switch(choice)
  {
    case 1:
      convertToBinary(return_value, file);
      break;
    
    case 2:
      convertToHex(return_value, file);
      break;
     
    case 3:
      convertToOctal(return_value, file);
      break;
      
    default:
      printf("\nInvalid option! Please enter a valid value (1, 2 or 3)\n");
      break;
  }
}






 





