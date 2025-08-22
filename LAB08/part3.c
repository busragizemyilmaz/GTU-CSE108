#include <stdio.h>
#include <string.h>

void removeDuplicates(char *str)
{
    int i, j, k = 0;
    int length = strlen(str);
    char result[100];
    int flag = 0;

    if (str[length - 1] == '\n')
    {
      str[length - 1] = '\0';
    }
    
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (str[i] == str[j])
            {
                flag = 1;
            }
        }

        if (flag)
        {
            flag = 0;
            
            continue;
        }

        else
        {
            result[k] = str[i];
            k++;
        }
    }

    result[k] == '\0';

    printf("String after removing duplicates: %s\n", result);
}

void main()
{
    char string[100];

    printf("Enter a string: ");
    fgets(string, 100, stdin);

    removeDuplicates(string);
}

