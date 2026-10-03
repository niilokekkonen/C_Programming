#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "task_17.h"

#define MAX_ARR_LEN 32
#define PW_LEN 64

#include "useful_func\useful_funcs.h"
#include "useful_func\read_string.c"

int main(void) 
{
    const char *hello = "Enter a password\nor\nstop to quit\n";
    char *end_str = "stop";
    char input[MAX_ARR_LEN] = {'\0'}; // Input from user
    char password[PW_LEN]; // Whole password combined
    bool generating = true;
    while (generating) 
    {
        read_string(hello, input, MAX_ARR_LEN);
        bool stop = check_str(input, end_str);
        if (stop) 
        {
            generating = false;
            printf("Entered stop, bye bye!\n");
            return 0;
        }
        if (input[0] != '\0') 
        {
            generate_pw(password, PW_LEN, input);
            printf("Password: %s\n", password);   
        }
        else 
        {
            fprintf(stderr, "Failed to read input\n");
        return 1; // Failed to read input
        }
    }
}

// Randomizes characters on the range of (upper_lim - lower_lim) + 1
// Returns true if succeeds
// Returns false if gibberish = false, gibberish is char arr buffer. 
bool random_chars(char *gibberish, int arr_len) 
{
    if (gibberish == NULL) 
    {
        return false;
    }
    else 
    {
        int low_lim = 33;
        int high_lim = 126;
        int range = (high_lim - low_lim) + 1; // ASCII table range 33 <-> 126
        int i = 0;
        srand(time(NULL));
        for(i = 0; i < arr_len; i++) 
        {
            gibberish[i] = rand() % range + '!';
        }
        gibberish[i] = '\0';
    return true;
    }
}


// Generates a password, from user input
// Returns true if successfully generated a password, else false
// Parameters = *ptr to password string, pw len, individidual array length, also the word to be converted
bool generate_pw(char *pw_str, int max_arr_size, const char *word) 
{
    int word_len = strlen(word);
    char gibberish[MAX_ARR_LEN]; // 'salt' for encryption
    bool randomized = random_chars(gibberish, word_len); // Filling gibberish str with random stuff
    if (!randomized) 
    {
        return false; // Failed to generate gibberish
    }
    else 
    {
        for (int i=0; i < word_len; i++) 
        {
            // Shifting i << 0000 0001 to the left
            // i * 2
            pw_str[(i << 1)] = word[i];
            // Writing to pw string 
            // (i * 2) + 1
            pw_str[(i<<1) + 1] = gibberish[i];
        }
        // Placing null terminator at (word_len * 2) + 1
        pw_str[(word_len << 1)] = '\0';
    return true;
    }
}