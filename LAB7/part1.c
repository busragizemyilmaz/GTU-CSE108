#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isPass(float final_grade)
{
    if (final_grade >= 50)
    {
        return 1;
    }
    
    else
    {
        return 0;
    }
}

float calculateWeightedAverage(int midterm, int final, int hw1, int hw2, int hw3)
{
    float hw_average = (hw1 + hw2 + hw3) / 3.0;

    return (midterm * 0.3) + (final * 0.4) + (hw_average * 0.3);
}

int main()
{
    int i;
    int grades[10][5];
    float analysis[10][3];
    float final_grade = 0;
    float sum = 0;
    int pass;
    int pass_count = 0;
    int a_count = 0, b_count = 0, c_count = 0, d_count = 0, f_count = 0;
    float class_average;

    FILE *file = fopen("class_report.txt", "w");

    srand(time(NULL));

    if (file == NULL)
    {
        printf("File couldn't be opened.\n");

        return 1;
    }

    printf("Student | Midterm Final HW1  HW2  HW3\n");
    for (i = 0; i < 10; i++)
    {
        grades[i][0] = rand() % 100; 
        grades[i][1] = rand() % 100;
        grades[i][2] = rand() % 100;
        grades[i][3] = rand() % 100;
        grades[i][4] = rand() % 100;

        printf("%4d    | %6d %5d %4d %4d %3d \n", i + 1, grades[i][0], grades[i][1], grades[i][2], grades[i][3], grades[i][4]);
    }

    printf("\nStudent | Final Grade | Pass | Letter Code\n");
    for (i = 0; i < 10; i++)
    {
        final_grade = calculateWeightedAverage(grades[i][0], grades[i][1], grades[i][2], grades[i][3], grades[i][4]);
        analysis[i][0] = final_grade;
        
        sum += final_grade;

        pass = isPass(final_grade);
        analysis[i][1] = pass;
        
        if (pass)
        {
          pass_count++;
        }

        if (final_grade >= 90)
        {
            analysis[i][2] = 5;
            a_count++;
        }
        
        else if (final_grade >= 75)
        {
            analysis[i][2] = 4;
            b_count++;
        }
        
        else if (final_grade >= 65)
        {
            analysis[i][2] = 3;
            c_count++;
        }
        
        else if (final_grade >= 50)
        {
            analysis[i][2] = 2;
            d_count++;
        }
        
        else
        {
            analysis[i][2] = 1;
            f_count++;
        }

        printf("%4d    | %9.2f   | %3.0f  | %6.0f \n", i + 1, analysis[i][0], analysis[i][1], analysis[i][2]);
    }
    
    printf("\nLegend: 5 = A, 4 = B, 3 = C, 2 = D, 1 = F\n");

    class_average = sum / 10.0;

    fprintf(file, "=== Class Report ===\n");
    fprintf(file, "- Average Final Grade: %.2f\n", class_average);
    fprintf(file, "- Passing Students   : %d / 10\n", pass_count);
    fprintf(file, "- Letter Grade Distribution:\n  A(5): %d\n  B(4): %d\n  C(3): %d\n  D(2): %d\n  F(1): %d\n", 
            a_count, b_count, c_count, d_count, f_count);

    printf("\n=== Class Report ===\n");
    printf("- Average Final Grade: %.2f\n", class_average);
    printf("- Passing Students   : %d / 10\n", pass_count);
    printf("- Letter Grade Distribution:\n  A(5): %d\n  B(4): %d\n  C(3): %d\n  D(2): %d\n  F(1): %d\n", 
            a_count, b_count, c_count, d_count, f_count);

    if (class_average >= 85)
    {
        fprintf(file, "- Class Performance: Excellent\n");
        printf("- Class Performance: Excellent\n");
    }
    
    else if (class_average >= 70)
    {
        fprintf(file, "- Class Performance: Satisfactory\n");
        printf("- Class Performance: Satisfactory\n");
    }
    
    else
    {
        fprintf(file, "- Class Performance: Needs Improvement\n");
        printf("- Class Performance: Needs Improvement\n");
    }

    fclose(file);

    return 0;
}

