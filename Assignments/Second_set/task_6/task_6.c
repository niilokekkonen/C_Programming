#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "task_6.h"

int main(void) 
{
    int validated = 0;
    bool playing = true;
    while (playing) 
    {
        print_menu();
        validated = valid_int();
        if (validated == 777)
        {
        printf("You must enter numbers\n");
        } // Roll d6
        else if (validated == 1) 
        {
            roll_dice(1, 6);
            playing = true; // Until user quits
        }// Roll d10
        else if (validated == 2) 
        {
            roll_dice(1, 10);
            playing = true; // STILL!

        }
        else if (validated == 3) 
        {
            printf("You chose to quit, WHAT A LOSER!");
            playing = false; // User quits

        }
        else 
        {
            printf("Try to enter a number between 1-3\nas shown\n");
        }
        
    }
    return 0;
}

void roll_dice(int min, int max) 
{
    int random_var = rand() % (max + 1 - min) + min;
    printf("You rolled a %d\n", random_var);
}

// Function that prints dice game menu
void print_menu(void) 
{
    printf("Enter number before the choice.\n(1. For 6 sided dice)\n");
    printf("|1. Roll D6\n|2. Roll D10\n|3. Quit\n");
}