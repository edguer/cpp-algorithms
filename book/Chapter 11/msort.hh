#include <bits/stdc++.h>
#include "util.hh"

#ifndef MSORT
#define MSORT

using namespace std;

namespace contoso
{
    namespace
    {
        void merge(int *arr, unsigned int start, unsigned int middle, unsigned int end)
        {
            unsigned int len1 = middle - start + 1, len2 = end - middle;
            int arr1[len1], arr2[len2];
            for (unsigned int i1 = 0, i2 = 0; i1 < len1 || i2 < len2; i1++, i2++)
            {
                if (i1 < len1)
                    arr1[i1] = arr[i1 + start];
                if (i2 < len2)
                    arr2[i2] = arr[i2 + middle + 1];
            }

            unsigned int i1 = 0, i2 = 0, i = start;
            for (; i1 < len1 && i2 < len2; i++)
            {
                if (arr1[i1] <= arr2[i2])
                    arr[i] = arr1[i1++];
                else
                    arr[i] = arr2[i2++];
            }

            for (; i1 < len1; i1++, i++)
            {
                arr[i] = arr1[i1];
            }

            for (; i2 < len2; i2++, i++)
            {
                arr[i] = arr2[i2];
            }
        }
        void msort(int *arr, unsigned int start, unsigned int end)
        {
            if (end > start)
            {
                unsigned int middle = (end + start) / 2;
                msort(arr, start, middle);
                msort(arr, middle + 1, end);
                merge(arr, start, middle, end);
            }
        }
    }

    // O(Nlog(N))
    void msort(int *arr, unsigned int len)
    {
        msort(arr, 0, len - 1);
    }
}

#endif