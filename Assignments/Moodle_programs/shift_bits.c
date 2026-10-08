#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <math.h>

uint32_t get_bits(uint32_t value, uint32_t shift, uint32_t bits);

// Shift value by param shift, keeps amount of param bits
uint32_t get_bits(uint32_t value, uint32_t shift, uint32_t bits) 
{
    // If bits are 5
    uint32_t bitmask = (pow(2, bits) - 1); // 2^5 = 32 - 1 = 31. 
                                           // 31 in 8bit binary = 0001 1111, perfect mask
    value = (value >> shift);
    return bitmask & value;
    // Only the bits that are on in the mask, are returned
}
