#include <stdio.h>

// Reads a number from stdinput
// Returns the number if read else returns 
int read_number(const char *prompt)
{
    int number = 0;
    int *pnum = & number;
    char input[32];
    printf("%s", prompt);
    fgets(input, 32, stdin);
    bool parsed = parse_number(input, pnum);
    if (parsed) 
    {
      printf("Parsed(%d) input %d\n", parsed, number);
      return number;  
    }
    else 
    {
        printf("Parsed(%d) input %d\n", parsed, number);
        return 0;
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