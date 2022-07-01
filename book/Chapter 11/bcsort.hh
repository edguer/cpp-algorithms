#include <bits/stdc++.h>
#include "util.hh"

#ifndef BCSORT
#define BCSORT

using namespace std;

namespace contoso
{
    // O(n2)
    void bcsort(int *arr, unsigned int len, int min = INT_MIN, int max = INT_MAX, unsigned int num_buckets = 10)
    {
        // calculate bucket range and fill the buckets
        int range = (max - min) / num_buckets;
        vector<int> buckets[num_buckets];
        for (unsigned int i = 0; i < len; i++)
        {
            unsigned int current_bucket = abs(arr[i] - min) / range;
            buckets[current_bucket].push_back(arr[i]);
        }

        // sort each bucket
        unsigned int index = 0;
        for (auto bucket : buckets)
        {
            sort(bucket.begin(), bucket.end());
            for (auto item : bucket)
            {
                arr[index++] = item;
            }
        }
    }
}

#endif