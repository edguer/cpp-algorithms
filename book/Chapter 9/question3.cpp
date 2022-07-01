#include <bits/stdc++.h>
#include <math.h>

using namespace std;

void sort(int *arr, int start, int end)
{
    if (end > start)
    {
        int pivot = arr[end];
        int low = start - 1;
        for (int i = start; i <= end; i++)
        {
            if (arr[i] < pivot)
            {
                int temp = arr[i];
                arr[i] = arr[++low];
                arr[low] = temp;
            }
        }
        int temp = arr[end];
        arr[end] = arr[++low];
        arr[low] = temp;

        sort(arr, start, low - 1);
        sort(arr, low + 1, end);
    }
}

int magic(int *arr, int len)
{
    int i = 0;
    while (i < len)
    {
        if (arr[i] == i)
        {
            return i;
        }
        else if (arr[i] > i)
        {
            i = arr[i];
        }
        else
        {
            i++;
        }
    }
    printf("Magic index could not be found.");
    return INT_MIN;
}

int main()
{
    int arr[] = {1,1,5,5,6,6,6};
    int len = sizeof(arr) / sizeof(int);
    sort(arr, 0, len - 1);

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Magic index: " << magic(arr, len) << endl;
    cout << "Magic index: " << savvy(arr, 0, len - 1) << endl;
}