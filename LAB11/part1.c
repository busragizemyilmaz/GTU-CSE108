#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char surname[50];
    char department[100];
    char class1[50];
    char class2[50];
    double salary;
} type_I;

typedef struct {
    char name[50];
    char surname[50];
    double salary;
    char degree;
} type_E;
  
typedef struct {
    char type;
    union {
        type_I I;
        type_E E;
    } person;
} combine_type;

combine_type salary_rise(combine_type person_info)
{
    if (person_info.type == 'I')
    {
        person_info.person.I.salary *= 105.3;
        person_info.person.I.salary /= 100;
    }

    else
    {
        if (person_info.person.E.degree == 'a')
        {
            person_info.person.E.salary *= 117.5;
            person_info.person.E.salary /= 100;
        }

        else if (person_info.person.E.degree == 'b')
        {
            person_info.person.E.salary *= 112;
            person_info.person.E.salary /= 100;
        }

        else
        {
            person_info.person.E.salary *= 109;
            person_info.person.E.salary /= 100;
        }
    }

    return person_info;
}

int readAndWriteData(char *textName, char *binaryName)
{
    combine_type c;
    char line[256];
    char *token;
    FILE *ifile = fopen(textName, "r");
    FILE *ofile = fopen(binaryName, "w");

    if (ifile == NULL)
    {
        printf("The file can not open.\n");

        return 1;
    }

    while (fgets(line, sizeof(line), ifile)) 
    {
        token = strtok(line, ",");

        if (strncmp(token, "I", 1) == 0)
        {
            c.type = 'I';

            token = strtok(NULL, " ");
            strcpy(c.person.I.name, token);

            token = strtok(NULL, ",");
            strcpy(c.person.I.surname, token);

            token = strtok(NULL, ",");
            strcpy(c.person.I.department, token);

            token = strtok(NULL, ",");
            strcpy(c.person.I.class1, token);

            token = strtok(NULL, ",");
            strcpy(c.person.I.class2, token);

            token = strtok(NULL, ",");
            sscanf(token, "%lf", &c.person.I.salary);

            c = salary_rise(c);
            fprintf(ofile, "Instructor,%s %s,%s,%s,%s,%.0f\n", c.person.I.name, c.person.I.surname, 
                    c.person.I.department, c.person.I.class1, c.person.I.class2, c.person.I.salary); 
        }

        else
        {
            c.type = 'E';

            token = strtok(NULL, " ");
            strcpy(c.person.E.name, token);

            token = strtok(NULL, ",");
            strcpy(c.person.E.surname, token);

            token = strtok(NULL, ",");
            sscanf(token, "%lf", &c.person.E.salary);

            token = strtok(NULL, ",");
            sscanf(token, " %c", &c.person.E.degree);

            c = salary_rise(c);
            fprintf(ofile, "Employee,%s %s,%.0f,%c\n", c.person.E.name, c.person.E.surname, c.person.E.salary, c.person.E.degree);
        }
    }

    fclose(ifile);
    fclose(ofile);

    return 0;
}

void main()
{
    readAndWriteData("text.txt", "binary.txt");
}