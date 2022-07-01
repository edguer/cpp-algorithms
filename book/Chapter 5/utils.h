#include <bits/stdc++.h>
#include <bitset>

using namespace std;

template <class T> void print_bit(T value)
{
    bitset<sizeof(T) * 8> bs(value);
    cout << bs; 
}

template <class T> void print_bit_float(T value)
{
    std::bitset<sizeof(T)*CHAR_BIT> bs(*reinterpret_cast<unsigned long*>(&value));
    cout << bs; 
}