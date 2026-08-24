#include <stdio.h>
#include <stdbool.h>

int read_int(void);
int calc_avg(int sum, int count);

int main(void) 
{
    bool entering = true;
    int sum = 0;
    int count = 0;
    int average = 0;
    while (entering) 
    {
    printf("Enter an integer\nor\na negative number to stop\n");
    int returned = read_int();
    //printf("%d\n", returned);
    if (returned < 0) 
    {
        average = calc_avg(sum, count);
        printf("%d", average);
        entering = false;
    }
    else 
    {
        sum += returned;
        count += 1;
        printf("SUM: %d, COUNT: %d\n", sum, count);
    }
    }
  return 0;   
}

int calc_avg(int sum, int count) 
{
    int avg = sum / count;
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
        return number;
    }
    }
}