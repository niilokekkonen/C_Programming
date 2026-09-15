#include <stdio.h>

void sort3(int *a, int *b, int *c);
void swap_val(int *y, int *x);

int main(void) 
{
    	
int a= 37;
int b = 12;
int c = 10;      

sort3(&a, &b, &c);  
printf("%d, %d, %d", a, b, c);

return 0;
}

// Swaps the three values using pointers
void sort3(int *a, int*b, int*c) 
{
      if (*a > *b)
    {
        swap_val(a, b);
    }
    if (*c < *b) 
    {
        swap_val(c, b);
    }
    if (*a > *b) 
    {
        swap_val(a, b);
    }

}

void swap_val(int *y, int *x)
{
    int temp = 0;
    if (y != NULL && x != NULL) 
    {
        temp = *y;    
        *y = *x;
        *x = temp;
    }
}