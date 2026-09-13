#include <stdio.h>

int read_number(const char *prompt)
{
    int number = 0;
    char input[32];
    printf("%s", prompt);
    fgets(input, 32, stdin);
    if (sscanf(input, "%d", &number) == 1) 
    {
        printf("%d", number);
        return number;    
    } else 
    {
        return 0;
    }
}