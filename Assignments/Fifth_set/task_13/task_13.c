#include <stdio.h>
#include <stdlib.h>
#include "task_13.h"
// Useful funcs brought from Assignments\useful_func
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\useful_funcs.h"
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\read_string.c"

#define OUT_FILE "output.txt"
#define FILE_LEN 100
#define MODE "r"

#define LINESIZE 10

int main(void) 
{
    const char *hello = "Enter a filename you want to open\n";
    char file_name[FILE_LEN];
    read_string(hello, file_name, FILE_LEN);
    read_file(file_name);
    return 0;
}

// Reads the file passed as a variable
void read_file(const char *filename) 
{
    // Initializing pointer variables for files
    FILE *out_f = NULL;
    FILE *inp_f = NULL; 
    
    // Opening file with fopen();
    inp_f = fopen(filename, MODE);
    char line[LINESIZE];
    int lc = 0;
    
    if (inp_f == NULL) 
    {
        // Outputting error to STDerr
        fprintf(stderr,"Mode %s failed\n", MODE);
    } 
    else 
    {  
        // Searching for End Of File 
        while(!feof(inp_f)) 
        {
            // Finding when the last byte gets passed
            if (fgets(line, LINESIZE, inp_f) != NULL) 
            {
                // Increasing linecount to know how many lines were read
                lc++;
                printf("%d: %s", lc, line);
            }
        }
        printf("It worked!\n");
        fclose(inp_f);
    }
}