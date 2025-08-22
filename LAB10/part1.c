#include <stdio.h>
#include <string.h>

typedef struct {
  char name[100];
  char surname[100];
  int id;
  int midterm;
  int final;
  double average;
  char letter;
} student;

typedef struct {
  student array[100];
  int number;
  double threshold_average;
} class;

void calculate(student *s, double threshold_average)
{
    s -> average = (s -> midterm * 0.4) + (s -> final * 0.6);

    if (s -> average >= threshold_average)
    {
        s -> letter = 'P';
    }

    else
    {
        s -> letter = 'F';
    }
}

class fillOfStruct()
{
    class c;
    int i;
    char temp_name[100];
    char temp_surname[100];

    printf("Enter threshold average to pass: ");
    scanf("%lf", &c.threshold_average);
    printf("Enter the number of students in class: ");
    scanf("%d", &c.number);

    printf("\n");
    for (i = 0; i < c.number; i++)
    {
        printf("Student %d\n", i + 1);
        printf("Enter name: ");
        scanf("%s", temp_name);
        strcpy(c.array[i].name, temp_name);

        printf("Enter surname: ");
        scanf("%s", temp_surname);
        strcpy(c.array[i].surname, temp_surname);

        printf("Enter ID: ");
        scanf("%d", &c.array[i].id);
        printf("Enter midterm grade: ");
        scanf("%d", &c.array[i].midterm);
        printf("Enter final grade: ");
        scanf("%d", &c.array[i].final);

        calculate(&c.array[i], c.threshold_average);
    }

    return c;
}

void sort(class *c)
{
    class temp;
    int i, j;

    for (i = 0; i < c -> number; i++)
    {
        for (j = 0; j < c -> number - 1; j++)
        {
            if (c -> array[j + 1].average > c -> array[j].average)
            {
                temp.array[0] = c -> array[j + 1];
                c -> array[j + 1] = c -> array[j];
                c -> array[j] = temp.array[0];
            }
        }
    }
}

int update(int id, int new_final, class *c)
{
    int i;
    int found = 0;

    for (i = 0; i < c -> number; i++)
    {
        if (c -> array[i].id == id)
        {
            found = 1;
            
            c -> array[i].final = new_final;
            calculate(&c -> array[i], c -> threshold_average);

            break;
        }
    }

    if (!found)
    {
        printf("\nThe student is not found in class.\n");

        return 0;
    }

    return 1;
}

void printOfClass (class c)
{
    int i;
    int count = 0;
    float sum = 0;
    float class_average;

    printf("\nClass Information: \n");
    printf("-------------------------------------------------------------------------------\n");
    printf("Name     Surname        ID        Midterm     Final    Average     Grade    \n");
    printf("-------------------------------------------------------------------------------\n");
    for (i = 0; i < c.number; i++)
    {
        printf("%5s %10s %10d %10d %10d %10.2f %10c\n", c.array[i].name, c.array[i].surname, c.array[i].id, c.array[i].midterm, 
                c.array[i].final, c.array[i].average, c.array[i].letter);
                                    
        if (c.array[i].letter == 'P')
        {
            count++;
        }
        
        sum += c.array[i].average;
    }

    class_average = sum / c.number;

    printf("-------------------------------------------------------------------------------\n");
    printf("Passing students: %d\n", count);
    printf("Class average: %.2f\n", class_average);
}
   
void main()
{
    class class_information;
    int id;
    int new_final;

    class_information = fillOfStruct();
    printOfClass(class_information);

    sort (&class_information);
    printf("\n#call sorting function");
    printOfClass(class_information);

    printf("\nUpdate final grade:\n");
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter new final grade: ");
    scanf("%d", &new_final);
    if (update(id, new_final, &class_information))
    {
        printOfClass(class_information);
    }
}