#include <bits/stdc++.h>

using namespace std;

void QuickSort(int *arr, int start, int end)
{
    if (end > start)
    {
        int pivot = arr[end];
        int low = start - 1;
        for (int i = start; i < end; i++)
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

        QuickSort(arr, start, low - 1);
        QuickSort(arr, low + 1, end);
        
    }
}

int main()
{
    int arr[] = { 9, 3, 7, 1, 2, 10, 40, 0, 1, 2, 0 };
    int len = sizeof(arr) / sizeof(int);

    QuickSort(arr, 0, len - 1);

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;
}