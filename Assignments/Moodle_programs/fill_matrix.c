#include <stdio.h>
#include <stdlib.h>

void fill_matrix(int matrix[5][3]);


int main(void) 
{

    return 0;
}
void fill_matrix(int matrix[5][3]) 
{
    int i, j;
    for (i = 0; i < 5; i++) 
    {
     for (j = 0; j < 3; j++)
     {
        // when j=1, i = 0 matrix[0][1] = (1 * 5) + 0 + 1 = 6
        // when j=2, i = 0 matrix[0][2] = (2*5) + 0 + 1 = 11
        matrix[i][j] = (j*5) + i + 1;
        }
    }
}