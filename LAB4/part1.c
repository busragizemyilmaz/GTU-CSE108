#include <stdio.h> 

int FileFunction(char *fname)
{
  int n;
  int sum = 0;
  int status;
  
  FILE * file = fopen(fname, "r");
  
  if (file == NULL)
  {
    printf("File can not be open!");

    return 1;
  }
  
  status = fscanf(file, "%d", &n);
  while (status == 1)
  {
    if (n % 2 == 0)
    {
      sum += n;
    }
    
    status = fscanf(file, "%d", &n);  
  }
  
  fclose(file);
  
  printf("Sum of even numbers: %d\n", sum);

  return 0;
}

void main()
{
  FileFunction("numbers.txt"); 
}
