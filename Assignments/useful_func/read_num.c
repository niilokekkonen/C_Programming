#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>

// Reads a number from stdinput
// Returns the number if read else returns 0 
int read_number(const char *prompt)
{
    int number = 0;
    int *pnum = &number;
    char input[32];
    printf("%s", prompt);
    fgets(input, 32, stdin);
    bool parsed = parse_number(input, pnum);
    if (parsed) 
    {
      //printf("Parsed(%d) input %d\n", parsed, number);
      return number;  
    }
    else 
    {
        //printf("Parsed(%d) input %d\n", parsed, number);
        return INT_MIN;
    }
}   

// parses a number from char to int
// Returns the number if parsed else returns 0
bool parse_number(char *input, int *pnum) 
{
    if (sscanf(input, "%d", pnum) == 1) 
    {
        return true;    
    } else 
    {
        printf("Parsing failed\n");
        return false;
    }
}

// Function that reads a number, and checks if its in range of int low, int high
// Returns false(0) if number out of range
// Else returns number 
bool read_range(int low, int high, int *pnum)
{
    printf("Enter a number between (%d - %d)", low, high);
    int number = read_number("\n");
    if (number == INT_MIN) 
    {
        return false; // Failed to parse number(Characters were entered)
    }
    if (number < low || number > high) 
    {
        *pnum = number; // 'returns' read value anyway
        return false;
    }
    else if (number >= low && number <= high)
    {
        //printf("Number is in range\n");
        *pnum = number;
        return true;
    }
}

// Returns a 'randomly' generated number in range
// If range is 0 or less, returns zero
int generate_num(int range) 
{
    int random_num = 0;
    if(range <= 0) 
    {
        return 0;
    }
    else 
    {
        random_num = rand() % range;
        return random_num;
    }
}