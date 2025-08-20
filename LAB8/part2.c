#include <stdio.h>
#include <string.h>

void compressString(const char *str, char *result)
{
  int i, j = 0;
  int str_length = strlen(str);
  int result_length;
  int count = 1;
 
  for (i = 0; i < str_length; i++)
  {
    if (str[i] == str[i + 1])
    {
      count++;
    }
    
    else
    {
      result[j] = str[i];
      j++;

      sprintf(&result[j], "%d", count);
      j++;

      count = 1;
    }
  }
  
  result_length = strlen(result);
  if (result_length < str_length)
  {
    printf("Compressed string: %s\n", result);  
  }
  
  else
  {
    printf("Compressed string: %s\n", str); 
  }
}

void main()
{
  char string[100];
  char result[100];
  
  printf("Enter a string: ");
  scanf("%s", string);
  
  compressString(string, result);
}
