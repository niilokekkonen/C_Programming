#include <stdio.h>
#include <stdbool.h>
#include "debug.h"
#include <stdlib.h>
#include <time.h>
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\useful_funcs.h"
#include "C:\Users\niilo\Desktop\C-course\Programs\Assignments\useful_func\read_num.c"

#define RANGE_MAX 4
#define RANGE_MIN 0
#define MSG_CNT 5

int main(void) 
{
    int debug_lvl = 0;
    int *debug_ptr = &debug_lvl;
    bool in_range = false;
    srand(time(NULL));
    printf("Enter a debug level\n");
    in_range = read_range(RANGE_MIN, RANGE_MAX, debug_ptr);
    if (in_range) 
    {
	    set_debug_level(debug_lvl);    
   	    int rndm_num = generate_num(RANGE_MAX);
        printf("Debug_lvl %d\n", debug_lvl);
	    for (int i = 0; i<MSG_CNT; i++)
	    {
            rndm_num = generate_num(RANGE_MAX);
	        dprintf(rndm_num,"running_index:%d\n\trndm_num: %d\n", i, rndm_num);
	    }
	    return 0;
    }
    else 
    {
	    printf("Number %d not in range\n", debug_lvl);    
	    // Number not in range
	    return 1;     
    }
}
