#include <stdio.h>

bool remove_lf(char *str) 
{
    if (str != NULL && strlen(str) != 0) 
    {   // Replacing newline with linefeed
        if (str[strlen(str) - 1] == '\n') 
        {
            str[strlen(str) - 1 ] = '\0';
            return true;
        }
        else 
        {
            return false;
        }
    }
    else 
    {
        return false;
    }
}