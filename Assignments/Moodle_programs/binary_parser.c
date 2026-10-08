#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

bool binary_parser(const char *str, unsigned int *pu)
{
    unsigned int value = 0;  // unsigned binary value
    int digits = 0; // Saving the digits read

    if (str == NULL || pu == NULL) {
        return false;
    }

    while (isspace((unsigned char)*str)) {
        str++;
    }

    // Checking for '0b' prefix
    if (str[0] != '0' || str[1] != 'b') {
        return false;
    }
    str += 2;

    // Until the character is other than 1 or 0
    while (*str == '0' || *str == '1') {
        value = (value << 1) + (*str - '0');
        digits++; // counts amount of binary digits read
        str++;
    }
    if (digits == 0) {
        return false;
    }

    *pu = value;
    return true;
}

// Counts the minimal hex digits needed to print nr
// returns amount of digits read 
int digit_counter(unsigned int nr)
{
    int digits = 1;
    //While nr > 0b1111
    while (nr > 0xF) {
        nr >>= 4;
        digits++;
    }

    return digits;
}