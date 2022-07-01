#include <bits/stdc++.h>
#include "util.hh"

#ifndef BSORT
#define BSORT

using namespace std;

namespace contoso
{
    // O(n2)
    void bsort(int *arr, unsigned int len)
    {
        for (unsigned int i = 0; i < len; i++)
        {
            for (unsigned int j = 0; j < len - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                    contoso::swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

#endif