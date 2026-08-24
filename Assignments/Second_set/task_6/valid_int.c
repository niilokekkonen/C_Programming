#include <stdio.h>
#include <stdbool.h>
#define CHAR_CODE 777 // Character error code

int valid_int(void);

// Validating user input for being a integer
int valid_int(void) 
{
    int number = 0;
    bool valid_int = false;
    if (scanf("%d", &number) != 1) 
    {
        while (getchar() != '\n');
        
        valid_int = false;
        return CHAR_CODE; // Returns CHAR_CODE if encounters characters
    } 
    else
    {
        // the number is a valid integer i.e. valid_int = true
        return number;
    }
}