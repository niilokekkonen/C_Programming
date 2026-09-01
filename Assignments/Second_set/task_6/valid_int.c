#include <stdio.h>
#include <stdbool.h>

#include "task_6.h"


// Validating user input for being a integer
int valid_int(void) 
{
    int number = 0;
    bool valid_int = false;
    if (scanf("%d", &number) != 1) 
    {
        while (getchar() != '\n');
        
        valid_int = false;
        return false; // Returns false (0) if invalid input
    } 
    else
    {
        // the number is a valid integer i.e. valid_int = true
        return number;
    }
}
