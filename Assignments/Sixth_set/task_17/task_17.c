#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "task_17.h"

#define MAX_ARR_LEN 32
#define PW_LEN 64



int main(void) 
{
    char input[MAX_ARR_LEN]; // Input from user
    char gibberish[MAX_ARR_LEN]; // 'salt' for encryption
    char password[PW_LEN]; // Whole password combined
    bool randomized = random_chars(gibberish);
}

// Randomizes character on the range of (upper_lim - lower_lim) + 1
// Returns true if succeeds
// Returns false if gibberish = false, gibberish is char arr buffer. 
bool random_chars(char *gibberish) 
{
    if (gibberish == NULL) 
    {
        return false;
    }
    else 
    {
        int low_lim = 33;
        int high_lim = 126;
        int range = (high_lim - low_lim) + 1;
        int i = 0;
        int count = rand() % MAX_ARR_LEN;
        srand(time(NULL));
        for(i = 0; i < count; i++) 
        {
            gibberish[i] = rand() % range + '!';
        }
        gibberish[i] = '\0';
        printf("Random stuff: %s\n", gibberish);
    return true;
    }
}

bool generate_pw(char *str, int arr_size, const char *word) 
{
    
}