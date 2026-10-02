#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Counts the UPPER CASE letters in the string *str
// Returns false if *str is NULL
// Returns true if succesfully counted the letters;

int count_upper(char *str) 
{
    int upper_cnt = 0;
    // Checking for NULL pointers
    if (str != NULL) 
    {    
    char *start = str;
    // Initializing the end of the string
    while (*start != '\0') 
    {
        if (isupper(*start))
        {
            upper_cnt += 1;
        } 
        else 
        {
            // Letter is lower_case so do nothing
        }
        start++;
    }
    return upper_cnt;
    // END OF STRING
    }
    else 
    {
        return -1; // Returns -1 if ends up here
    }
}