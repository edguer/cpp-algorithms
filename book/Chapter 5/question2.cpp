#include <bits/stdc++.h>
#include "utils.h"

using namespace std;

int main()
{
    float a = 5.2;
    // 1 00111111100000000000000000000000
    // 2 01000000000000000000000000000000
    // 3 01000000010000000000000000000000
    // 4 01000000100000000000000000000000
    // 5  01000000101000000000000000000000
    //5.1 01000000101000110011001100110011
    //5.2 01000000101001100110011001100110
    // print_bit<float>(1.12);
    std::bitset<sizeof(float)*CHAR_BIT> bs(*reinterpret_cast<unsigned long*>(&a));
    cout << bs; 
    cout << endl;
}