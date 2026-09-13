#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "task_11.h"
#define STR_MAX 256
#define REPL_MAX 256

int main(void) 
{
    char str[STR_MAX];
    char repl[REPL_MAX];
    const char *prompt = "Enter a string you want to replace characters from\nOr 'stop' to quit\n";
    const char *prompt2 = "Enter two characters 'e3' first is replaced char, second is the replacing char\n";
    char *end_str = "stop";
    bool rolling = true;
    while (rolling) 
    {
        read_string(prompt, str, STR_MAX);
        printf("Here's the str you entered: '%s'\n", str);
        if (check_str(str, end_str) == true) 
        {
            printf("Bye bye\n", str);
            rolling = false;
            return 0;
        } 
        else 
        {
            read_string(prompt2, repl, REPL_MAX);
        }
        if (check_str(repl, end_str) == true) 
        {
            printf("Bye bye\n", repl);
            rolling = false;
            return 0;
        }
        int replaced = replace_char(str, repl);
        if (replaced == 0) 
        {
            printf("String was not modified\n");
        }
        else 
        {
            printf("Here str after modification: '%s'\n", str);
            printf("How many characters were replaced: %d\n", replaced);
        }
    }
    return 0;

}

// Function replaces character in a string from 
// First *repl char, the second char is the one its being replaced with
// The function returns number of characters replaced
// Returns 0 if no characters were replaced, or *repl doesn't have 2 characters
// Also if pointers were NULL
int replace_char(char *str, const char *repl) 
{
    if (str != NULL && repl != NULL) 
    {
        int repl_len = strlen(repl);
        int switched = 0; // Variable to track switches
        if (repl_len < 2) 
        {
            return 0;
        } 
        else if (repl_len > 2) 
        {
            return 0;
        }
        else 
        {
            char *start = str;
            const char find_char = *repl;
            repl++;
            const char replace_char = *repl;
            do 
            {
                if (*start == find_char) 
                {
                    switch_char(start, replace_char);
                    switched +=1; 
                }
                start++;

            } while (*start != '\0');
        return switched;
        }   
    }
    else 
    {
        return 0;
    }

}

// Switches char a to char b
void switch_char(char *a, char b) 
{
    *a = b;
}

// Reads a string with fgets to *str variable
void read_string(const char *prompt, char *str, int str_len) 
{
    printf("%s", prompt);
    fgets(str, str_len, stdin);
    // Removing linefeed from string
    bool removed = remove_lf(str);
    if (removed == false) 
    {
        clear(); // clearing input buffer if user enters a string thats too long
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