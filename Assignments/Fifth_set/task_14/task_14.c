#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "task_14.h"

// Useful funcs brought from Assignments\useful_func
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\useful_funcs.h"
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\read_string.c"
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\Read_num.c"

#define LINE_LEN 80
#define LINE_CNT 100
#define FILE_LEN 20

int main(void) 
{
    const char *hello = "Enter a filename you want to open\n";
    // Initial variables
    // Line cnt = rows
    // Line Len = columns(strlen)
    char str_arr[LINE_CNT][LINE_LEN];
    char *outfile = "out.txt";
    // Line count to keep track of read lines
    int lc = 0;
    int *lp = &lc;  
    char infile_name[FILE_LEN] = {'\n'};
    // Reading string from user
    read_string(hello, infile_name, FILE_LEN);
    if (infile_name[0] == '\n') 
    {
        fprintf(stderr, "Couldn't read filename\n");
        return 1;
    } 
    else 
    {
        // Reading text from file
        bool read_file = read_text(infile_name, lp,str_arr);
        if (read_file==true) 
    {
        // Writing text
        write_text(outfile, lp, str_arr);
        return 0;
    }
    else 
    {
        return 1;
    } 
    }
}



// Reads strings from a file, into a multidimensional array
// takes filename, pointer to line count, and ptr to str_arr[line_cnt][line_len] as parameters
bool read_text(const char *filename, int *linecount,char (*str_arr)[LINE_LEN]) 
{   // Initial variables
    FILE *inf = NULL;
    int lc = 0;
    inf = fopen(filename, "r");
    if (inf == NULL) 
    {
        fprintf(stderr, "File %s couldn't be opened\n", filename);
        return false;
    }
    else 
    {
        // Checking for end of file
        while ( lc < LINE_CNT && !feof(inf)) 
        {
            if (fgets(str_arr[lc], LINE_LEN, inf) != NULL) 
            {
                lc++;
            }

        }
        printf("Read %d lines, from %s\n", lc, filename);
        *linecount = lc;
        fclose(inf);
        /* 
        for (int i = 0; i < lc; i++) 
        {
            printf("STR %d: %s", i+1, str_arr[i]);
        }
        printf("\n");    
        */
        return true;
    }
}

// Writes lines from a 2d char array to the filename specified
// Takes in the amount of lines, filename, string array and data
bool write_text(const char *filename, int *linecount, char (*str_arr)[LINE_LEN]) 
{
    FILE *outf = NULL;
    outf = fopen(filename, "a");
    if (outf == NULL) 
    {
        fprintf(stderr, "Writing to file -> %s failed\n");
        return false;
    }
    else 
    {
        for (int i = 0; i < *linecount; i++) 
        {
            fputs(str_arr[i], outf);
        }
        
    }
    printf("Wrote %d lines, to %s\n", *linecount, filename);
    fclose(outf);
    return true;  
}

// Capitalizes all letters in a string
// Takes ptr to string as arg
void str_to_upper(char *str)
{
    while (*str != '\0') 
    {
        *str = toupper((unsigned char) * str);
        str++;
    }
}