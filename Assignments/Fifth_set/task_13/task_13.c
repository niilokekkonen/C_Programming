#include <stdio.h>
#include <stdlib.h>
#include "task_13.h"
#include <string.h>

// Useful funcs brought from Assignments\useful_func
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\useful_funcs.h"
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\read_string.c"
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\Read_num.c"


#define FILE_LEN 100
#define LINESIZE 10

int main(void) 
{
    const char *hello = "Enter a filename you want to open\n";
    char file_name[FILE_LEN];
    read_string(hello, file_name, FILE_LEN);
    if (strlen(file_name) > 0) 
    {
        read_nums(file_name);
    }
    else 
    {
        printf("Enter a filename\n");
    }
    return 0;
}

// Reads integers from the file
// Filename is passed as argument 
void read_nums(const char *filename) 
{
    // Initializing pointer variables for files
    FILE *inp_f = NULL;
    // Initial values for storing number, smallest, largest, integer count
    int ic = 0;
    int number = 0; 
    int largest = -1000;
    int smallest = 1000;
    // Opening file with fopen();
    inp_f = fopen(filename, "r");
    char line[LINESIZE];
    
    if (inp_f == NULL) 
    {
        // Outputting error to STDerr
        fprintf(stderr, "File %s couldn't be opened\n", filename);
    } 
    else 
    {  printf("Opening file: %s\n", filename);
        // Searching for End Of File 
        while(!feof(inp_f)) 
        {
            // Finding when the last byte gets passed
            if (fgets(line, LINESIZE, inp_f) != NULL) 
            {
                if (sscanf(line, "%d", &number) == 1) 
                {
                    // Increasing linecount to know how many lines were read
                    ic++;
                    printf("Read %d\n", number);
                    if (number < smallest) 
                    {
                        smallest = number;
                    }
                    if (number > largest) 
                    {
                        largest = number;
                    }
                }
                else 
                {
                    printf("Int not read\n");
                }
            }
        }
        fclose(inp_f);
    printf("Largest: %d\nSmallest: %d\n", largest, smallest);
    }
}