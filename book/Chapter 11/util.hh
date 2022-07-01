#include <bits/stdc++.h>

#ifndef UTIL
#define UTIL

using namespace std;

namespace contoso
{
    template <class T=int> void swap(T *a, T *b)
    {
        T t = *a;
        *a = *b;
        *b = t;
    }
    template <class T=int> void print(T *arr, unsigned int len)
    {
        for (int i = 0; i < len; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

#endif