#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

void print_binaryw(uint32_t value, uint32_t width);
uint32_t bit_counter(unsigned int nr);


void print_binaryw(uint32_t value, uint32_t width) 
{
    uint32_t needed_bits = bit_counter(value); // Calculating needed bits for printing
    uint32_t total = 0; // Total of all bits

    if(width > needed_bits) 
    {
        total = width;
    }
    else 
    {
        total = needed_bits;
    }
    for(int i = (total - 1); i >= 0; i--) 
    {

        uint32_t bit = ((value >> i) & 1);
        printf("%u", bit);
    }
}

// Counts the minimal binary digits needed to print nr
// returns amount of digits read 
uint32_t bit_counter(unsigned int nr)
{
    int bits = 1;
    //While nr > 1, it needs more bits than one
    while (nr > 1) {
        nr >>= 1;
        bits++;
    }

    return bits;
}