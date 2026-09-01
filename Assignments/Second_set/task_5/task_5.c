#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "task_5.h"
// EDIT: Removed constant 'error' code variables to ensure programs general usefulness
#define ROUNDS 3 // Const round variable


int main (void) 
{
    int k = 0;
    int min = 1;
    int max = 6;
    while (k < ROUNDS) 
    {
        printf("|Round %d\n", (k + 1) );
        printf("|Let's play\n|Roll the dice\n");
        Sleep(1000);
        int entered = read_range(min, max);
        int bot_result = entered + 1; // TO keep the bot winning 
        if (entered == 6) 
        {   
            printf("I got %d It's a tie\n", max);

        }
        else if (entered == false) 
        {
            printf("Try again! Faulty input.\nYou must enter whole numbers\n");
            k--; // Not spending a round for input error
        }
        else 
        {
            printf("I got %d, I win!\n", bot_result);
        }
        k++;
    }
    return 0;
}
// Function that reads a number, and checks if its in range of int low, int high
int read_range(int low, int high)
{
    printf("Enter a number between (%d - %d)\n", low, high);
    int number = valid_int();
    if (number < low || number > high) 
    {
        //printf("Number out of range\n");
        return false;
    }
    else if (number >= low || number <= high)
    {
        //printf("Number is in range\n");
        return number;
    }
}
// Validates integer, outputs false if not valid int
int valid_int(void) 
{
    int number = 0;
    bool valid_int = false;
    if (scanf("%d", &number) != 1) 
    {
        while (getchar() != '\n');
        
        valid_int = false;
        return false; // Returns false if invalid input
    } 
    else
    {
        // the number is a valid integer i.e. valid_int = true
        return number;
    }
}