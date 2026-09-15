#include <stdio.h>
#include <stdlib.h>


void sort3(int *pa[3]);
void swap_pointers(int **y, int **x);

int main(void) 
{
    	
int a = 64;
int b = 64;
int c = 34;
    // a needs to be smallest, b the mid, and c the highest
    int *pa[3] = {&a, &b, &c};

    sort3(pa);

    printf("Sorted: %d, %d, %d\n", *pa[0], *pa[1], *pa[2]);
    printf("Original values: %d, %d, %d\n", a, b, c);
    

    return 0;
}
// Sorts the left most pointer to be the smallest value pa[0]
// Middle pointer is mid value pa[1]
// Right pointer is Highest value pa[2]
void sort3(int *pa[3]) 
{
    if (*pa[0] > *pa[1])
    {
        swap_pointers(&pa[0], &pa[1]);
    }
    if (*pa[2] < *pa[1]) 
    {
        swap_pointers(&pa[2], &pa[1]);
    }
    if (*pa[0] > *pa[1]) 
    {
        swap_pointers(&pa[0], &pa[1]);
    }
}

// Swaps the pointers, y and x 
// Uses double pointers(array names, that store the pointer to the original variable)
// &pa[0] = **pointer_to_a = &a 
void swap_pointers(int **y, int **x)
{
    int *temp = 0;
    if (y != NULL && x != NULL) 
    {
        temp = *y;    
        *y = *x;
        *x = temp;
    }
}