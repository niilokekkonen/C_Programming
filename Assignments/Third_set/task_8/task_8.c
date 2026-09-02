#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "task_8.h"

#define ARR_LEN 15
#define MIN 1
#define MAX 10


int main(void) 
{
    srand(time(NULL));
    int arr[ARR_LEN] = {};
    randomize_array(arr, ARR_LEN);
    return 0;
}

// Prints the values in this array
void print_numbers(int *array, int length) 
{
    for (int i = 0; i < length; i++) 
    {
        printf("%8d\n", array[i]);
    }    
}

// Returns true when array has been filled with random numbers
// The range can be adjusted with max, min variables
bool randomize_array(int *array, int length) 
{
    for (int i = 0; i < length; i++) 
    {
        array[i] = rand() % (MAX + 1 - MIN) + MIN;              
    }
    print_numbers(array, length);
    return true;   
}

