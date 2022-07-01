#include <bits/stdc++.h>

#ifndef BITOPERATIONS
#define BITOPERATIONS

using namespace std;

// shifting bits to the left multiplies them
int ShiftLeft(int value, int factor)
{
    return value << factor;
}

// shifting bits to the right divides them
int ShiftRight(int value, int factor)
{
    return value >> factor;
}

struct BitFields
{
    unsigned int one_bit_int:1; // accepts 0 and 1, trying 2 will make it go back to 0
    unsigned int two_bits_int:2; // accepts 0, 1, 2 and 3, trying 4 will make it go back to 0
    unsigned int four_bits_int:4; // accepts 0 to 7, trying 8 will make it go back to 0
};

#endif