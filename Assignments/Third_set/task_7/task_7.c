#include <stdio.h>
#include <stdbool.h>
#include "task_7.h"


// # INCLUDE PATH TO valid_int.c
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\Second_set\task_6\valid_int.c"

int main(void) 
{
    money_guess();
    return 0;
}


/*
Function plays a guessing game with the user
*/
void money_guess(void) 
{
    int back_up = 0;
    int user_guess = 0;
    int *pguess = &user_guess; 
    int failed_attempts = 0;
    int bot_money = 0;

    while(failed_attempts < 3) 
    {
        printf("Guess how much money I have?\n");
        bool flag = read_pos(pguess);
        bot_money = (user_guess * 2) + 20;
        if (flag == true) 
        {
            printf("You didn't get it right. I have %d euros\n", bot_money);
        }
        else if (flag == false) 
        {
            printf("Invalid input\n");
            failed_attempts += 1;
        }
    }
}

/*
Function reads a positive number, and saves it to a variable
by taking a pointer as a parameter
if x > 0 returns true, if x < 0 returns false
*/ 
bool read_pos(int *val) 
{
    printf("Enter a positive number:\n");
    int number = valid_int();
    if (number == false) 
    {
        return false;
    }
    else if (number < 0) 
    {
        return false;
    }
    else 
    {
        *val = number;
        return true;
    }
    
}

