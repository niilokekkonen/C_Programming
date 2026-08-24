#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) 
{
    int class_size = 0;
    int grade = 0;
    int student_nmbr;
    // Booleans for while loops
    bool saving = false;
    bool grading = false;
    bool running = true;    
    
    while (running) 
    {
    printf("Enter the amount of students:\n");
    if (scanf("%d", &class_size) != 1) 
    {
        while (getchar() != '\n');
        printf("Invalid input\n");
        running = true;
    }
    else 
    {
        int grades[class_size];
        for (int i=0; i < class_size; i++)
        {
            grades[i] = -1;
        }
        saving = true;
        
        while (saving) 
        {
            printf("Enter student number (1 - %d) or 0 to stop:\n", class_size);
            if (scanf("%d", &student_nmbr) != 1) 
            {
                while (getchar() != '\n'); 
                printf("Invalid input\n");
            }
            else 
            {
                if (student_nmbr == 0) 
                {
                    saving = false;
                    running = false; // Turning off the program
                } 
                else if (student_nmbr > class_size || student_nmbr < 1) 
                {
                printf("Invalid student number\n");
                }
                else
                {
                    grading = true;
                }
            // Conditional loop to continue asking for the grade if the value was out of bounds.
            }
            while (grading) 
            {
                printf("Enter grade (0 - 5) for student %d or -1 to cancel:\n", student_nmbr);
                if (scanf("%d", &grade) != 1) 
                {   // Emptying the character buffer until \n character is found
                    while (getchar() != '\n'); 
                    printf("Invalid input\n");
                }
                else 
                {
                        if (grade == -1) 
                    {
                        grades[student_nmbr - 1] = -1;
                        grading = false;
                    } 
                        else if (grade < -1 || grade > 5) 
                    {
                        printf("Invalid grade\n");
                        grading = true;
                    }
                        else 
                    {
                        grades[student_nmbr - 1] = grade;
                        grading = false;
                    }
                }   
            }
        }
        printf("%8s%8s\n", "student","grade");
        for (int i = 0; i < class_size; i++) 
        {
            if (grades[i] == -1)
            {
                printf("%8d%8s\n", i+1, "N/A");
            }
            else
            {
                printf("%8d%8d\n", i+1, grades[i]);   
            }
        }
        }
    }
       
}