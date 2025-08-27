#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef union {
    struct {
        double radius;
    } circle;

    struct {
        double edge1;
        double edge2;
    } triangle;

    struct {
        double width;
        double height;
    } rectangle;
} geometri_type;

typedef enum {circle, triangle, rectangle} shape_type;

typedef struct link_list {
    geometri_type shape;
    shape_type type;
    struct link_list *next;
} generate;

generate* add(generate *head, generate **new_node_ptr)
{
    generate *temp;
    generate *new_node = (generate *)malloc(sizeof(generate));
    new_node->next = NULL;

    if (head == NULL) 
    {
        head = new_node;
    }

    else 
    {
        temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }

        temp->next = new_node;
    }

    *new_node_ptr = new_node;

    return head;
}

char* typeToStr(shape_type t) 
{
    if (t == circle) return "circle";
    else if (t == triangle) return "triangle";
    else return "rectangle";
}

void searchAndRemove(generate **head, char *string, int *processed_nodes)
{
    generate *temp = *head;
    generate *prev = NULL;
    int found = 0;

    while (temp != NULL) 
    {
        if ((strcmp(string, "circle") == 0 && temp->type == circle) || (strcmp(string, "triangle") == 0 && temp->type == triangle) || 
            (strcmp(string, "rectangle") == 0 && temp->type == rectangle)) 
        {
            found = 1;
            (*processed_nodes)++;

            if (temp->type == circle) 
            {
                printf("%s %.1f\n", typeToStr(temp->type), temp->shape.circle.radius);
            }

            else if (temp->type == triangle)
            {
                printf("%s %.1f %.1f\n", typeToStr(temp->type), temp->shape.triangle.edge1, temp->shape.triangle.edge2);
            }

            else 
            {
                printf("%s %.1f %.1f\n", typeToStr(temp->type), temp->shape.rectangle.width, temp->shape.rectangle.height);
            }

            if (prev == NULL) 
            {
                *head = temp->next;
                free(temp);
                temp = *head;
            }

            else 
            {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            }

            break;
        }

        else 
        {
            prev = temp;
            temp = temp->next;
        }
    }

    if (!found) 
    {
        printf("No %s found!\n", string);
    }
}

int main()
{
    generate *head = NULL;
    generate *node;
    generate *temp;
    shape_type type;
    char command[100];
    int n;
    double value;
    char string[100];
    int found;
    int total_nodes = 0;
    int processed_nodes = 0;

    srand(time(NULL));

    do
    {
        fgets(command, sizeof(command), stdin);

        if (command[strlen(command) - 1] == '\n')
        {
            command[strlen(command) - 1] = '\0';
        }

        if (strncmp(command, "generate", 8) == 0)
        {
            sscanf(command, "generate %d", &n);

            if (n < 1 || n > 100)
            {
                printf("You can ask at most 100 and at least 1 items to be created.\n");

                return 1;
            }

            while (n > 0)
            {
                head = add(head, &node);
                total_nodes++;

                type = rand() % 3;
                node->type = type;

                if (type == circle) 
                {
                    node->shape.circle.radius = ((double)rand()/RAND_MAX)*(100.0-0.1)+0.1;
                }

                else if (type == triangle) 
                {
                    node->shape.triangle.edge1 = ((double)rand()/RAND_MAX)*(100.0-0.1)+0.1;
                    node->shape.triangle.edge2 = ((double)rand()/RAND_MAX)*(100.0-0.1)+0.1;
                }

                else 
                {
                    node->shape.rectangle.width  = ((double)rand()/RAND_MAX)*(100.0-0.1)+0.1;
                    node->shape.rectangle.height = ((double)rand()/RAND_MAX)*(100.0-0.1)+0.1;
                }

                n--;
            }
        }

        else if (strncmp(command, "process", 7) == 0)
        {
            sscanf(command, "process %s", string);

            searchAndRemove(&head, string, &processed_nodes);
        }

        else 
        {
            printf("Invalid command! Please enter \"generate\" or \"process\".\n");
        }

    } while (processed_nodes < total_nodes);

    printf("All the entities are processed.\n"); 

    return 0;
}
