#include <stdio.h>
#include <stdbool.h>

int read_int(void);
float calc_avg(int sum, int count);

int main(void) 
{
    bool entering = true;
    int sum = 0;
    int count = 0;
    float average = 0;
    while (entering) 
    {
    printf("Enter an integer\nor\na negative number to stop\n");
    int returned = read_int();
    //printf("%d\n", returned);
    if (returned < 0) 
    {
        average = calc_avg(sum, count);
        printf("%.3f\n", average);
        entering = false;
    }
    else 
    {
        sum += returned;
        count += 1;
        /*
        LEFT FOR TESTING PURPOSES 
        => printf("SUM: %d, COUNT: %d\n", sum, count);
        */
    }   
    }
  return 0;   
}

// Returns float average if count is not 0
float calc_avg(int sum, int count) 
{
    float avg = 0.0;   
    if (count != 0) 
    {
        avg = (float) sum / count;
    } 
    return avg;
}

int read_int(void) 
{
    bool valid_int = false;
    int number = 0;
    while (!valid_int) 
    {
    if (scanf("%d", &number) != 1) 
    {
        while (getchar() != '\n');
        printf("Invalid input\nTry again\n");
        valid_int = false;
    } 
    else
    {
        valid_int = true;
    }
    }
    return number;
}