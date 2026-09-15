#include <stdio.h>
#include <string.h>

// Reads a string with fgets to *str variable
// Prompt is the question for user, *str is the variable where the read string is placed, max_str_len
void read_string(const char *prompt, char *str, int str_len) 
{
    printf("%s", prompt);
    fgets(str, str_len, stdin);
    // Removing linefeed from string
    bool removed = remove_lf(str);
    if (removed == false)
    {
        printf("Clearing input buffer...\nToo many characters were entered\nProgram Not Accurate\n");
        clear_ib();
    }
}

// Returns true if succesfully removes newline char
// Returns false if pointer is NULL, 
// Also returns false if fgets can't read the whole str
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


// clears the input buffer
void clear_ib(void) 
{
    while (getchar() != '\n');
}


// Compares two string str and comparison
// Returns true if strings match
// false if not matching, or either pointer is NULL
bool check_str(char *str, char *comparison) 
{
    if (str != NULL && comparison != NULL) 
    {
        if (strcmp(str, comparison) == 0) 
        {
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

