#include <bits/stdc++.h>
#include "utils.h"

using namespace std;

class bit_array
{
public:
    bit_array()
    {
        arrays = new long[size];
        for (unsigned short int i = 0; i < size; i++)
        {
            arrays[i] = 0;
        }
    }
    void set(unsigned long index)
    {
        if (array(index) > size - 1)
        {
            increase_size(array(index) + 1);
        }

        arrays[array(index)] |= ((long)1) << (index - (array(index) * default_size()));
    }
    bool is_set(unsigned long index)
    {
        if (array(index) > size - 1)
            return false;
        else
            return (arrays[array(index)] & (((long)1) << (index - (array(index) * default_size())))) != 0;
    }
    void unset(unsigned long index)
    {
        if (array(index) > size - 1)
        {
            return;
        }

        arrays[array(index)] = arrays[array(index)] ^ (((long)1) << (index - (array(index) * default_size())));
    }

private:
    long *arrays = NULL;
    unsigned long size = 1;
    unsigned long index = 0;

    unsigned short int default_size()
    {
        return sizeof(long) * CHAR_BIT;
    }

    unsigned long array(unsigned long index)
    {
        return (index + 1) / default_size();
    }

    void increase_size(unsigned long new_size)
    {
        long *new_array = new long[new_size];
        for (unsigned long i = 0; i < new_size; i++)
        {
            if (i <= size - 1)
                new_array[i] = arrays[i];
            else
                new_array[i] = 0;
        }

        size = new_size;
        arrays = new_array;
    }
};

int main()
{
    bit_array arr;
    arr.set(0);
    arr.set(1);
    arr.set(10);
    arr.set(20);
    arr.set(30);
    arr.set(50);
    arr.set(250);
    cout << "set? " << arr.is_set(250) << endl;
    arr.unset(250);
    cout << "set? " << arr.is_set(250) << endl;
}