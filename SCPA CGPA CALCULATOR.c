#include <stdio.h>   // For input/output
#include <stdlib.h>  // For exit() and general utilities
#include <math.h>    // For future expansion (optional)
#include <string.h>  // For string handling if needed

/* Function to calculate SGPA for one semester */
float calculateSGPA(int subjects)
{
    int credit, gradePoint;
    int totalCredits = 0;
    int weightedSum = 0;

    for (int i = 1; i <= subjects; i++)
    {
        printf("\nSubject %d\n", i);

        printf("Enter credits: ");
        scanf("%d", &credit);

        printf("Enter grade point (0 - 10): ");
        scanf("%d", &gradePoint);

        /* Input validation */
        if (credit <= 0 || gradePoint < 0 || gradePoint > 10)
        {
            printf("Invalid input! Re-enter values.\n");
            i--;
            continue;
        }

        weightedSum += credit * gradePoint;
        totalCredits += credit;
    }

    return (float)weightedSum / totalCredits;
}

int main()
{
    int semesters, subjects;
    float sgpa, cgpa = 0.0;

    printf("====================================\n");
    printf("        SGPA & CGPA CALCULATOR\n");
    printf("====================================\n");

    printf("Enter number of semesters: ");
    scanf("%d", &semesters);

    if (semesters <= 0)
    {
        printf("Invalid semester count!\n");
        exit(0);
    }

    for (int i = 1; i <= semesters; i++)
    {
        printf("\n--- Semester %d ---\n", i);

        printf("Enter number of subjects: ");
        scanf("%d", &subjects);

        if (subjects <= 0)
        {
            printf("Invalid subject count! Try again.\n");
            i--;
            continue;
        }

        sgpa = calculateSGPA(subjects);
        printf("SGPA of Semester %d = %.2f\n", i, sgpa);

        cgpa += sgpa;
    }

    cgpa = cgpa / semesters;

    printf("\n====================================\n");
    printf("Final CGPA = %.2f\n", cgpa);
    printf("====================================\n");

    return 0;
}
