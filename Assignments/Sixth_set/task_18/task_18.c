#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#include "useful_func\useful_funcs.h"
#include "useful_func\read_num.c"
#include "useful_func\read_string.c"

#define UPPER_LIM 15
#define LOW_LIM 0
#define BITMASK 0x3F // 0011 1111
#define RNDM_RANGE 128

int main(void) 
{
    //srand(time(NULL)); // Seeding the randomness
    srand(2);
    int number = 0;
    int *pnum = &number;
    bool in_range = true;
    while (!(number < 0)) 
    {
        printf("Enter a negative number to quit or\n");
        in_range = read_range(LOW_LIM, UPPER_LIM, pnum); // true if number in range, else false
        if (!in_range) 
        {
            printf("Number not in range\n");
            printf("Parsing failed means that you tried entering characters\n");
            if(number < 0) 
            {
                printf("You entered a negative number, Bye Bye\n");
            }
        }
        else if (in_range)
        {
            printf("%d\n", number);
            int rndm_num = generate_num(RNDM_RANGE);
            printf("random num in hex: %03X\n", rndm_num);
            int shifted_num = (rndm_num >> number);
            int masked_num = (BITMASK & shifted_num); // 0001 1111 & whatever shifted num is
            printf("number after masking in hex: %03X\n", masked_num);
        }
        else  
        {
            fprintf(stderr, "Parsing failed");
        }
    }
    return 0;
}

