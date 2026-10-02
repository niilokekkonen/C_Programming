#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "task_21.h"


// Useful funcs brought from Assignments\useful_func
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\useful_funcs.h"
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\read_string.c"
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\read_num.c"

#define LINE_LEN 100
#define LINE_CNT 100
#define FILE_LEN 20

int main(void) 
{
    const char *hello = "Enter a filename you want to open\n";
    char *outfile = "out.txt";
    char infile_name[FILE_LEN] = {'\n'};
    char line_arr[LINE_CNT][LINE_LEN];
    // Line count to keep track of read lines
    int lc = 0;
    int *lp = &lc;  
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
        bool read_file = read_text(infile_name, lp, line_arr);
        if (read_file==true) 
        {
        // If the file was succesfully read, then check checksums
        nmea_checksum(line_arr, lc);
        return 0;
        }
        else 
        {
        // Return false
        printf("Can't read file");
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
        while (lc < LINE_CNT && !feof(inf)) 
        {
            if (fgets(str_arr[lc], LINE_LEN, inf) != NULL) 
            {
                if (str_arr[lc][0] != '\n') 
                {
                    lc++;    
                }
                else 
                {
                    // don't do nothing, so fgets overwrites the \n char
                }
            }
            
        }
        printf("Read %d lines, from %s\n", lc, filename);
        *linecount = lc;
        fclose(inf);
        return true;
    }
}
// Finds correct lines in NMEA(gps) data
// returns true after successfully finding data
// returns false if str_arr == NULL
bool nmea_checksum(char(*str_arr)[LINE_LEN], int linecount) 
{
    if (str_arr == NULL) 
    {
        return false;
    }
    else 
    {
        char start_mark = '$';
        char end_mark = '*';
        int fc = 0;
        for (int i = 0; i < linecount; i++) 
        {
            char *start = strchr(str_arr[i], start_mark);
            char *end = strchr(str_arr[i], end_mark);
            int calc_checksum = 0; // calculated checksum
            if (start != NULL && end != NULL && start < end) 
            {
               char checksum[3] = {*(end + 1),*(end + 2), '\0'}; // Checksum in data
               int hexsum = 0;
               if (sscanf(checksum, "%x", &hexsum) == 1) 
                {
                    start++;  
                    // Going through characters until char == '*'
                    while (start < end) 
                    {
                        calc_checksum ^= *start;
                        start++;
                    }
                   // printf("calc: %02X\ncheck: %02X\n", calc_checksum, hexsum);
                    if (hexsum == calc_checksum) 
                    { 
                        // Checksum was correct
                        printf("[OK] %s", str_arr[i]);

                    }
                    else 
                    {
                        fc++; // Fail count + 1 
                        // Checksum was incorrect
                        printf("[FAIL] %s", str_arr[i]);
                    }
                }
                else 
                {
                fprintf(stderr, "failed to parse checksum to hex\n");
                }

            }
            else 
            {
                printf("No $ or * on line %d\n", i + 1);
                fc++;
            }
        }
        printf("\n%d lines failed\n", fc);
    }

}