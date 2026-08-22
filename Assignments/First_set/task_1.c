#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

int main(void) 
{   
    float bus_price = 0;
    float taxi_price = 0;
    float user_balance = 0;
    int user_choice = 0;
    bool broke = false;

    printf("Enter the price of a bus ticket:\n");
    scanf("%f", &bus_price);
    printf("Enter the price of a taxi trip:\n");
    scanf("%f", &taxi_price);
    printf("How much cash you got:\n");
    scanf("%f", &user_balance);
    while(!broke) 
    {
        printf("Do you want to ride with\n");
        printf("1. Bus\n2. Taxi\nEnter your choice:\n");
        scanf("%d", &user_choice);
        if (user_balance < bus_price && user_balance < taxi_price)
        {   
            broke = true;
            printf("You must walk now ;D\n");
        }
        else 
        {
            broke = false;
        }
        /* 
        First two choices for the user having enough cash
        Second Two for the user not having enough cash 
        */
        if (user_choice == 1 && user_balance >= bus_price) 
        {
            user_balance = user_balance - bus_price;
            printf("Bus ticket bought\nYour balance: %.4f\n", user_balance);
        }
        else if (user_choice == 2 && user_balance >= taxi_price) 
        {
            user_balance = user_balance - taxi_price;
            printf("Taxi trip reserved\nYour balance: %.4f\n", user_balance);
        }
        else if (user_choice == 1 && user_balance < bus_price) 
        {
            printf("Not enough money for Bus\nYour balance: %.4f\n", user_balance);
        }
        else if (user_choice == 2 && user_balance < taxi_price) 
        {
            printf("Not enough money for taxi :D\nYou Thought You Was Rich, Huh?\nYour balance: %.4f\n", user_balance);
        }  
        else 
        {
            printf("Something odd");
        }
        
    }
    return 0;
}