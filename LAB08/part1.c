#include <stdio.h>
#include <string.h>

void reverseString(char str[])
{
  int i;
  int length = strlen(str);
  int first = 0;
  int last = length - 1;
  char ch;
  
  if (str[last] == '\n')
  {
    str[last] = '\0';
    last--;
  }
  
  while (first < last)
  {
    ch = str[first];
    str[first] = str[last];
    str[last] = ch;
    
    first++;
    last--;
  }
  
  printf("Reversed string: %s\n", str);
}

void main()
{
  char string[100];
  
  printf("Enter a string: ");
  fgets(string, 100, stdin);
  
  reverseString(string);
}
