#include <stdbool.h>
#include <string.h>
#include "task_15.h"
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

// Useful funcs brought from Assignments\useful_func
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\useful_funcs.h"
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\read_string.c"
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\Read_num.c"


#define ARR_LEN 40
#define FILE_LEN 20
#define LINE_LEN 100

int main(void) 
{
    // Initial variables
    char *prompt = "Enter the filename you want to read\n";
    char infile_name[FILE_LEN] = {'\n'};
    int lc = 0; // Read lines from file
    int *lp = &lc;
    menu_item struct_arr[ARR_LEN];
    // Reading string from user
    read_string(prompt, infile_name, FILE_LEN);
    if (infile_name[0] == '\n') 
    {
        fprintf(stderr, "Couldn't read filename\n");
        return 1;
    }
    else 
    {
        bool read = read_data(infile_name, lp, struct_arr);
        if (read) 
        {
            print_struct(struct_arr, lp);
            return 0;
        }
        else 
        {
            return 1;
        }
    }
}

// Reads data from a file, into a struct defined in header file
// takes filename, pointer to line count, and ptr to str_arr[line_cnt][line_len] as parameters
bool read_data(const char *filename, int *linecount, menu_item struct_arr[ARR_LEN]) 
{   // Initial variables
    int ec = 0; // element count
    char line_buffer[LINE_LEN];
    char number[LINE_LEN];
    char mark = ';';
    FILE *inf = NULL;
    inf = fopen(filename, "r");
    if (inf == NULL) 
    {
        fprintf(stderr, "File %s couldn't be opened\n", filename);
        return false;
    }
    else 
    {
        // Checking for end of file
        while (ec < ARR_LEN && !feof(inf)) 
        {
            if (fgets(line_buffer, LINE_LEN, inf) != NULL) 
            {
                bool split = split_string(mark, line_buffer, number, LINE_LEN);
                if (split) 
                {
                    strcpy(struct_arr[ec].name,line_buffer);
                    struct_arr[ec].price = atof(number);
                    ec++;       
                }
                else 
                {
                    // Don't do anything, altering data only if the string can be split
                }
            }

        }
        printf("Read %d lines, from %s\n", ec, filename);
        *linecount = ec;
        fclose(inf);
        return true;
    }

}

bool split_string(char mark, char *str, char *number, int number_size) 
{
    // Finding the first occurence of mark
    char *ch = strchr(str, mark);
    if (ch == NULL) 
    {
        fprintf(stderr,"Failed to find %c\n", mark);
        return false;
    }
    else 
    {
        *ch = '\0';
        strcpy(number, (ch + 1));
        return true;
    }   
    
}

//Prints the struct data fetched from a file
// Takes struct_arr[40], and element_count as parameters
void print_struct(menu_item struct_arr[ARR_LEN], int *ec) 
{
    for (int i=0; i < *ec; i++) 
    {
        printf("%8.3lf\t%8s\n", struct_arr[i].price, struct_arr[i].name);
    }   
}