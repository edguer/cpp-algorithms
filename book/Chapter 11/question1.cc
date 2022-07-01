#include <bits/stdc++.h>
#include "util.hh"

using namespace std;

/*
 * We have two options: using 2n memory and O(n) or n memory and O(n2) - worst case
 * We will adopt the second approach and take advantage of the buffer of the first array
 * */
void merge(int *arr1, int len1, int count1, int *arr2, int len2)
{
    if (count1 + len2 > len1)
    {
        cout << "arr1 does not support arr2" << endl;
        return;
    }
    int c1 = 0, c2 = 0;
    while (c1 < len1 && c2 < len2)
    {
        if (arr1[c1] <= arr2[c2])
        {
            c1++;
        }
        else if (c1 <= count1)
        {
            // shift arr1
            for (int j = len1; j >= c1; j--)
            {
                arr1[j + 1] = arr1[j];
            }
            arr1[c1++] = arr2[c2++];
        }
        else
        {
            arr1[c1++] = arr2[c2++];
        }
    }
}

/*
 * If we move from the back of arr1, then we don't need to shift, and we can make it in O(n)
 * */
void savvy(int *arr1, int len1, int count1, int *arr2, int len2)
{
    int index1 = count1 - 1;
    int index2 = len2 - 1;
    int index = len1 - 1;
    while (index1 >= 0 && index2 >= 0)
    {
        if (arr1[index1] >= arr2[index2])
        {
            arr1[index--] = arr1[index1--];
        }
        else
        {
            arr1[index--] = arr2[index2--];
        }
    }

    while (index1 >= 0)
        arr1[index--] = arr1[index1--];

    while (index2 >= 0)
        arr1[index--] = arr2[index2--];
}

int main()
{
    int arr1[10];
    int count1 = 6;
    arr1[0] = 3;
    arr1[1] = 4;
    arr1[2] = 6;
    arr1[3] = 9;
    arr1[4] = 50;
    arr1[5] = 53;

    int arr2[4];
    arr2[0] = 1;
    arr2[1] = 3;
    arr2[2] = 5;
    arr2[3] = 54;

    savvy(arr1, 10, count1, arr2, 4);
    contoso::print(arr1, 10);
}