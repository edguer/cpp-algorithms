#include <bits/stdc++.h>
#include "utils.h"

short int interpolate(short int original, char piece, unsigned short int start, unsigned short int end)
{
    // clear bits from start to end
    short int left = ~0 << start; // 111100000000
    cout << "left ";
    print_bit<short int>(left);
    cout << endl;
    short int right = ((1 << end) - 1); // 000000001111
    cout << "right ";
    print_bit<short int>(right);
    cout << endl;
    short int mask = left | right; // 111100001111
    cout << "mask ";
    print_bit<short int>(mask);
    cout << endl;
    original = original & mask; // all "middle" bits will be set to 0
    cout << "original ";
    print_bit<short int>(original);
    cout << endl;
    mask = piece; // transfer piece to a bigger variable, shifting it to match the required position
    cout << "mask2 ";
    print_bit<short int>(mask);
    cout << endl;
    return original | mask;
}


int main()
{
    short int original = 0;
    print_bit<short int>(original);
    cout << endl;
    
    char piece = ~0;
    print_bit<char>(piece);
    cout << endl;

    cout << "Result: ";
    print_bit<short int>(interpolate(original, piece, 12, 4));
    cout << endl;
}