#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "task_12.h"

#define MAX_LEN 256
#define WORD_LEN 256


int main(void) 
{

    const char *prompt = "Enter a string\n";
    const char *wordp = "Enter a word you want to search from the string\n";
    char *stop_str = "stop";
    char string[MAX_LEN];
    char word[WORD_LEN];
    bool stop = false;
    while (!stop) 
    {
        read_string(prompt, string, MAX_LEN);
        stop = check_str(string, stop_str);
        if (stop) 
        {
            printf("Program closed. bye bye\n");
            stop = true;
            return 0; // Forcing shutdown
        }
        read_string(wordp, word, WORD_LEN);
        int res = count_words(string, word);
        printf("RESULT: %d\n", res);
    }
    printf("Bye bye!\n");
    return 0;
}

// Counts words in a word
// Example str: 'moi moi',
// find 'oi', 
// 2 pcs of 'oi' found in that string
// Returns int count or 0 if there is no matching words
int count_words(const char* str, const char *word) 
{
    if (str != NULL && word != NULL) 
    {
        char *match = strstr(str, word);
        if (match == NULL) 
        {
            return 0;
        }
        else 
        {
            int word_count = 0;
            while (match != NULL) 
            {
                word_count += 1;
                match++; 
                match = strstr(match, word); 
            }
            printf("Whole string = %s\n", str);
            return word_count;
        }

    }  
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
void clear_ib(void) 
{
    while(getchar() != '\n');
}