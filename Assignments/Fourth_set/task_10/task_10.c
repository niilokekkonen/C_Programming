#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "task_10.h"

#define STR_BUF 100

int main(void) 
{
    const char *prompt = "Enter a string, or 'stop' to quit";
    char *end_str = "stop";
    char str[STR_BUF];
    bool string_check = false;
    int str_len = 0;
    int *plen = &str_len;
    // String_check returns true when word stop is entered
    while (!string_check) 
    {
    read_string(prompt, str, STR_BUF);
    count_letters(str, plen);
    string_check = check_str(str, end_str);
    if (string_check) 
    {
        printf("Bye bye\n");
        return 0; // shutdown if user enters 'stop'
    }
    printf("String len: %d\n", str_len);
    printf("String = %s\n", str);
    }
}

// Reads a string with fgets to *str variable
void read_string(const char *prompt, char *str, int str_len) 
{
    printf("%s\n", prompt);
    fgets(str, str_len, stdin);
    // Removing linefeed from string
    bool removed = remove_lf(str);
    if (removed == false) 
    {
        printf("String is over the character limit (%d)\n", STR_BUF);
        clear(); // Clearing input buffer in case of str len being too much
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



// Counts the letters in the string *str
// Returns false if *str is NULL
// Returns true if succesfully counted the letters;
// Doesn't remove whitespaces...
bool count_letters(const char *str, int *ltr_cnt) 
{
    // Checking for NULL pointers
    // Undefined behaviour...
    if (str != NULL && ltr_cnt != NULL) 
    {    
    const char *start = str;
    *ltr_cnt = 0;
    // Initializing the end of the string
    while (*start != '\0') 
    {
        start++;
        *ltr_cnt += 1;    
    }
    if (*start == '\0') 
    {
        return true;
        // END OF STRING
    }
    }
    else 
    {
        return false;
    }
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

// Clears input buffer
void clear(void) 
{
    while (getchar() != '\n');
}