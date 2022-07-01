#include <bits/stdc++.h>
#include <bitset>

using namespace std;

bool contains(long bit_array, unsigned short int position)
{
    return (bit_array & (1 << position)) != 0;
}

void set_array(long *bit_array, unsigned short int position)
{
    (*bit_array) |= 1 << position;
    bitset<64> bs((*bit_array));
    cout << "SET " << bs << endl;
}

void unset_array(long *bit_array, unsigned short int position)
{
    (*bit_array) = (*bit_array) ^ (1 << position);
    bitset<64> bs((*bit_array));
    cout << "UNSET " << bs << endl;
}

void clear_array_all_greater_than(long *bit_array, unsigned short int position)
{
    long mask = (1 << position) - 1;
    (*bit_array) = (*bit_array) & mask;
    bitset<64> bs((*bit_array));
    cout << "CLEAR_ALL_GREATER " << bs << endl;
}

void clear_array_all_less_than(long *bit_array, unsigned short int position)
{
    long mask = (1 << (position + 1)) - 1;
    (*bit_array) = (*bit_array) & ~mask;
    bitset<64> bs((*bit_array));
    cout << "CLEAR_ALL_LESS " << bs << endl;
}

int main()
{
    long bit_array = 0;
    set_array(&bit_array, 0);
    set_array(&bit_array, 1);
    set_array(&bit_array, 3);
    set_array(&bit_array, 5);
    set_array(&bit_array, 30);
    unset_array(&bit_array, 1);
    clear_array_all_less_than(&bit_array, 5);
    cout << "Contains? " << contains(bit_array, 30) << endl;
}