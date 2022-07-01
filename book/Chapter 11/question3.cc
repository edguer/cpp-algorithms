#include <bits/stdc++.h>
#include "util.hh"

using namespace std;

// O(log(n))
unsigned int get_start(int *arr, unsigned int start, unsigned int end)
{
    int tip = arr[0];
    unsigned int mid_index = (start + end) / 2;
    int mid = arr[mid_index];

    if (mid < tip && mid < arr[mid_index - 1])
    {
        return mid_index;
    }
    else if (mid < tip)
    {
        return get_start(arr, start, mid_index);
    }
    else
    {
        return get_start(arr, mid_index, end);
    }
}
unsigned int search(int *arr, int term, unsigned int start, unsigned int end)
{
    int mid_index = (end + start) / 2;

    if (arr[mid_index] == term)
        return mid_index;
    else if (end == start)
        return -1;
    else if (term < arr[mid_index])
        return search(arr, term, start, mid_index - 1);
    else
        return search(arr, term, mid_index + 1, end);
}

// first we find the starting index, which takes O(log(n)), and then we use a regular binary search 
// on the appropriate slice (before or after the starting index), which will take O(log(n)) on the worst case
// Overall, it will be O(2log(n))
unsigned int search(int *arr, int term, unsigned int len)
{
    unsigned int tip = get_start(arr, 0, len - 1);

    if (term < arr[tip])
        return -1;
    else if (term < arr[len - 1])
        return search(arr, term, tip, len - 1);
    else
        return search(arr, term, 0, tip);
}

int main()
{
    int arr[] = { 15, 16, 17, 18, 19, 20, 21, 22, 23, 1, 4, 7, 10, 12, 13, 14 };
    unsigned int len = sizeof(arr) / sizeof(int);
    cout << "Search: " << search(arr, 13, len) << endl;
}