#include <stdio.h>
#include <string.h>

void main()
{
    int i;
    char text[100];
    char pattern[99];
    int text_length;
    int pattern_length;
    int found = 0;
    int count = 0;
    int index;

    printf("text = ");
    fgets(text, 100, stdin);
    printf("pattern = ");
    fgets(pattern, 99, stdin);

    text_length = strlen(text);
    pattern_length = strlen(pattern);

    if (text[text_length - 1] == '\n')
    {
        text[text_length - 1] = '\0';

        text_length--;
    }

    if (pattern[pattern_length - 1] == '\n')
    {
        pattern[pattern_length - 1] = '\0';

        pattern_length--;
    }

    if (text[text_length - 1] == '"')
    {
        text[text_length - 1] = '\0';
        
        text_length--;
    }

    if (pattern[pattern_length - 1] == '"')
    {
        pattern[pattern_length - 1] = '\0';
        
        pattern_length--;
    }

    if (text[0] == '"')
    {
        for (i = 0; i < text_length; i++)
        {
            text[i] = text[i + 1];
        }

        text_length--;
    }

    if (pattern[0] == '"')
    {
        for (i = 0; i < pattern_length; i++)
        {
            pattern[i] = pattern[i + 1];
        }

        pattern_length--;
    }

    printf("\n");
    for (i = 0; i < text_length; i++)
    {
        if (strncmp(&text[i], pattern, strlen(pattern)) == 0)
        {
            found = 1;
            count++;
            
            if (count > 1)
            {
                printf(", ");
            }
            
            printf("Pattern found at index %d", i);
        }
    }

    if (!found)
    {
        printf("Pattern is not found in a text");
    }   

    printf("\n");
}