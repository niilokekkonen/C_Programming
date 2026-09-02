#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "task_9.h"

#define ARR_LEN 20
#define MAX 20
#define MIN 1

int main(void) 
   
{   
    
    unsigned int arr[ARR_LEN] = {};
    randomize_array(arr, ARR_LEN);
    srand(time(NULL));
    bool searching = true;
    while (searching) 
    {
        
    int user_target = prompt_user();
    if (user_target == 0) 
    {
        printf("See ya later alligator :D\n");
        searching = false;
    }
    else if (user_target == -2) 
    {
        printf("Target out of range\n");
    }
    else if (user_target == -3) 
    {
        printf("Target negative, Try again\n");
    }
    else 
    {
        int found = find_first(arr, user_target);
        if (found == -1) 
        {
            printf("Not found\n");
        } 
        else 
        {
            printf("TARGET FOUND\n");
            printf("Index of target = %d\n", found);
        }
    }
    }
    return 0;
}

int prompt_user(void) 
{
    printf("Enter a number to search for\nor 0 to stop\n");
    int number = read_int();
    if (number > 0) 
    {
        int in_range = read_range(number, MIN, MAX);
        if (in_range > 0) 
        {
            return number;
        }
        else 
        {
            return -2; // Out of range 
        }
    }
    else if (number == 0) 
    {
        return 0;
    }
    else 
    {
        return -3; // Negative input
    }
}

int find_first(const unsigned int *array, unsigned int target) 
{
    bool found = false;
    int index = 0;
    printf("Target = %d\n", target);
    while(!found) 
    {
        int val = *array;
        printf("Looking at -> %d\n", val);
        if (val == target) 
        {
            found = true;
            return index; // Returning the index where target was found
        } 
        else if (val == 0) 
        {
            return -1;
        }
        array++;
        index += 1;
    }
}

// Returns true when array has been filled with random numbers
// The range can be adjusted with max, min variables
// Function makes the last item 0
bool randomize_array(unsigned int *array, int length) 
{
    for (int i = 0; i < (length - 1); i++) 
    {   
        array[i] = rand() % (MAX + 1 - MIN) + MIN;              
    }
    array[ARR_LEN - 1] = 0;
    print_numbers(array, length);
    return true;   
}

// Prints the values in this array
void print_numbers(unsigned int *array, int length) 
{
    for (int i = 0; i < length; i++) 
    {
        printf("%8d\n", array[i]);
    }    
}

// Function that reads a number, and checks if its in range of int low, int high
int read_range(int number, int low, int high)
{
    if (number < low || number > high) 
    {
        return -2; // Out of range
    }
    else if (number >= low && number <= high)
    {
        //printf("Number is in range\n");
        return number;
    }
}

int read_int(void) 
{
    bool valid_int = false;
    int number = 0;
    while (!valid_int) 
    {
    if (scanf("%d", &number) != 1 || number < 0) 
    {
        while (getchar() != '\n');
        printf("Invalid input\nTry again\n");
        valid_int = false;
    } 
    else
    {
        return number;
    }
    }
}