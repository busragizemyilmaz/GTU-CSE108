#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** createStack(char **stack, int capacity)
{
    stack = (char **)malloc(capacity * sizeof(char *));

    return stack;
}

char** push(char **stack, int *count, int *capacity, int capacity_choice)
{
    char string[100];
    int index;
    int flag = 0;

    if ((*count) == (*capacity))
    {
        if (capacity_choice == 2)
        {
            flag = 1;
            
            (*capacity) *= 2;
        }

        else
        {
            (*capacity)++;
        }

        stack = (char **)realloc(stack, (*capacity) * sizeof(char *));
    }

    printf("Enter action: ");
    getchar();
    fgets(string, sizeof(string), stdin);
    if (string[strlen(string) - 1] == '\n')
    {
        string[strlen(string) - 1] = '\0';
    }

    index = *count;
    stack[index] = (char *)malloc((strlen(string) + 1 ) * sizeof(char));

    strcpy(stack[index], string);

    if (flag)
    {
        printf("Stack resized to capacity: %d\n", *capacity);
    }

    printf("Action recorded.\n");
    (*count)++;

    return stack;
}

char** undo(char **stack, int *count, int *capacity, int capacity_choice)
{
    int index;

    if ((*count) == 0)
    {
        printf("Stack is empty.\n");
    }

    else
    {
        index = (*count) - 1;

        printf("Undoing action: %s\n", stack[index]);

        free(stack[index]);
        stack[index] = NULL;

        (*count)--;

        if ((*count) < ((*capacity) / 2) && capacity_choice == 2)
        {
            (*capacity) /= 2;
            
            stack = (char **)realloc(stack, (*capacity) * sizeof(char *));

            printf("Stack shrunk to capacity %d\n", (*capacity));
        }
    }

    return stack;
}

void printStack(char **stack, int count)
{
    int i;

    printf("Action History (Top to Bottom):\n");
    for (i = count - 1; i >= 0; i--)
    {
        printf("%s\n", stack[i]);
    }
}

void freeStack(char **stack, int count)
{
    int i;

    for(i = 0; i < count; i++)
    {
        free(stack[i]);
    }
    free(stack);
}

int main()
{
    int capacity_choice;
    int capacity;
    int flag = 0;
    int choice;
    char **stack;
    int count = 0;

    printf("Which stack will you use?\n\n");
    printf("1.One-by-one growth stack\n");
    printf("2.Doubling capacity stack\n");
    printf("\nChoice: ");
    scanf("%d", &capacity_choice);

    if (capacity_choice == 1)
    {
        capacity = 1;
    }

    else if (capacity_choice == 2)
    {
        printf("Enter initial capacity stack: ");
        scanf("%d", &capacity);
    }

    else
    {
        printf("Invalid value. Please enter one of 1 or 2.\n");

        return 1;
    }

    stack = createStack(stack, capacity);

    printf("\n1. Perform Action\n");
    printf("2. Undo Last Action\n");
    printf("3. Print Action History\n");
    printf("4. Exit\n");

    while(!flag)
    {
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                stack = push(stack, &count, &capacity, capacity_choice);
                break;

            case 2:
                stack = undo(stack, &count, &capacity, capacity_choice);
                break;

            case 3:
                printStack(stack, count);
                break;

            case 4:
                flag = 1;
                printf("Cleaning up memory... Goodbye!\n");
                freeStack(stack, count);
                return 1;

            default:
                printf("Invalid value. Please enter 1, 2, 3 or 4.\n");           
        }
    }

    return 0;
}