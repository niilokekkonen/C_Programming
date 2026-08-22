#include <stdio.h>
#include <windows.h>
#define MONTHS 12

int main(void) 
{
    
    float income_array[MONTHS] = {0};
    float tax_array[MONTHS] = {0};
    float tax_rate = 0;
    float higher_tax = 0;
    float income_limit = 0;
    float income_sum = 0;
    float low_part = 0;
    float high_part = 0;
    
    printf("Enter tax rate:\n");
    scanf("%f", &tax_rate);
    printf("Enter income limit:\n");
    scanf("%f", &income_limit);
    printf("Enter tax rate above limit:\n");
    scanf("%f",&higher_tax);
    // For loop to fill income array
    for (int i = 0; i < MONTHS; i++) 
    {
        printf("Enter your income for month %d\n", i + 1);
        scanf("%f", &income_array[i]);
        
    }
    // For loop to calculate taxes
    for (int i = 0; i < MONTHS; i++) 
    {
        income_sum += income_array[i];
        if (income_sum <= income_limit) 
        {
            tax_array[i] = (tax_rate/100 * income_array[i]);
        }
        else if (income_sum > income_limit) 
        {
            tax_array[i] = (higher_tax/100 * income_array[i]);
        }
        else 
        {
            low_part = tax_rate/100 * income_array[i];
            high_part = higher_tax/100 * income_array[i];
            tax_array[i] = low_part + high_part;
        }

    }
    
    printf("%5s\t%8s\t%8s","month", "income", "taxes\n");
    // For loop to display monthly income + taxes
    for (int i = 0; i < MONTHS; i++)
    {
        printf("%5d\t%8.2f\t%8.2f\n",(i+1),income_array[i],tax_array[i]);
        
    }
    Sleep(10000);
    return 0;
}