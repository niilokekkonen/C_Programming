#include <stdio.h>
#include <stdbool.h>
#include "task_5.h"
#include <windows.h>
// 'ERROR' code for a user entering characters
#define CHAR_CODE 777
// 'ERROR' code for user going out of range(OUR)
#define OUR_CODE 888
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
        else if (entered == CHAR_CODE) 
        {
            printf("Try again! try to enter NUMBERS\n");
            k--; // Not spending a round for input error
        }
        else if (entered == OUR_CODE) 
        {
            printf("Try again! input OUT OF RANGE\n");
            k--;
        }
        else 
        {
            printf("I got %d, I win!\n", bot_result);
        }
        k++;
    }
    return 0;
}
// Function that reads a number, and checks if its in range
int read_range(int low, int high)
{
    printf("Enter a number between (%d - %d)\n", low, high);
    int number = valid_int();
    if (number == CHAR_CODE) 
    {
        return CHAR_CODE;
    }
    else if (number < low || number > high) 
    {
        //printf("Number out of range\n");
        return OUR_CODE;
    }
    else if (number >= low || number <= high)
    {
        //printf("Number is in range\n");
        return number;
    }
}

int valid_int(void) 
{
    int number = 0;
    bool valid_int = false;
    if (scanf("%d", &number) != 1) 
    {
        while (getchar() != '\n');
        
        valid_int = false;
        return CHAR_CODE; // Returns CHAR_CODE if encounters characters
    } 
    else
    {
        // the number is a valid integer i.e. valid_int = true
        return number;
    }
}