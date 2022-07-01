#include <bits/stdc++.h>
#include "util.hh"

#ifndef QSORT
#define QSORT

using namespace std;

namespace contoso
{
    namespace
    {
        template <class T=int> void qsort(T *arr, unsigned int start, unsigned int end) 
        {
            if (end > start)
            {
                unsigned int low = start;
                for (unsigned int i = start; i <= end; i++)
                {
                    if (arr[i] < arr[end])
                        swap(&arr[i], &arr[low++]);
                }
                swap(&arr[low], &arr[end]);
                qsort(arr, start, low > 0 ? low - 1 : 0);
                qsort(arr, low + 1, end);
            }
        }
    }

    // O(Nlog(N)) avg, O(n2) worst
    template <class T=int> void qsort(T *arr, unsigned int len)
    {
        qsort(arr, 0, len - 1);
    }
}

#endif