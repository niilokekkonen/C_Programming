#include <stdio.h>
#include <string.h>

// Counts the UPPER CASE letters in the string *str
// Returns false if *str is NULL
// Returns true if succesfully counted the letters;

void replace(char *str) 
{
    char replaced = 't';
    char asterisk = '*';
    // Checking for NULL pointers
    if (str != NULL) 
    {    
        char *start = str;
        // Initializing the end of the string
        while (*start != '\0') 
        {
            if (*start == replaced)
            {
                *start = asterisk;
            }
        start++;
        }
    }
}