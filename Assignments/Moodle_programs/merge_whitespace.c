#include <stdio.h>

void merge_whitespace(char *str)
{
    if (str == NULL)
    {
        return;
    }

    char *read = str;
    char *write = str;
    bool prev_is_space = false;

    while (*read != '\0')
    {
        if (isspace((unsigned char)*read))
        {
            if (!prev_is_space)
            {
                *write = ' ';
                write++;
                prev_is_space = true;
            }
        }
        else
        {
            *write = *read;
            write++;
            prev_is_space = false;
        }
        read++;
    }

    *write = '\0';
}