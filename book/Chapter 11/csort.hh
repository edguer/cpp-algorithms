#include <bits/stdc++.h>

#ifndef CSORT
#define CSORT

using namespace std;

namespace contoso
{
    void csort(int * arr, unsigned int len, int range_start, int range_end)
    {
        if (range_end < range_start)
        {
            cout << "Range end is less than range start." << endl;
            return;
        }

        int output[len];
        unsigned int count_size = range_end - range_start;
        unsigned int count[count_size];
        for (unsigned int i = 0; i < count_size; i++)
        {
            count[i] = 0;
        }

        // count all occurrences
        for (unsigned int i = 0; i < len; i++)
        {
            if (arr[i] > range_end || arr[i] < range_start)
            {
                cout << arr[i] << " out of accepted range." << endl;
                return;
            }

            count[arr[i] - range_start]++;
        }

        // each count will receive the sum of the item before it
        for (unsigned int i = 1; i < count_size; i++)
        {
            count[i] += count[i - 1];
        }

        // fill the output
        for (unsigned int i = 0; i < len; i++)
        {
            cout << arr[i] << " count is " << count[arr[i]] << endl;
            output[count[arr[i]]-- - 1] = arr[i];
        }

        // update the original array
        for (unsigned int i = 0; i < len; i++)
        {
            arr[i] = output[i];
        }
    }
}

#endif