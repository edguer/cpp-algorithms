#include <bits/stdc++.h>
#include <math.h>

using namespace std;
void subsets(int *arr, int start, int end, int depth, int *ancestors, int height)
{
    for (int i = start; i <= end; i++)
    {
        if (depth == 1)
        {
            cout << "Subset: ";
            for (int i = height - 1; i > depth - 1; i--)
            {
                cout << ancestors[i] << " ";
            }
            
            cout << arr[i] << endl;
        }
        else
        {
            ancestors[depth - 1] = arr[i];
            subsets(arr, i + 1, end, depth - 1, ancestors, height);
        }
    }
}
void subsets(int *arr, int len)
{
    for (int i = 1; i <= len; i++)
    {
        subsets(arr, 0, len - 1, i, new int[i], i);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    subsets(arr, sizeof(arr)/sizeof(int));
    //1: {1}, {3}, {4}, {7}, {10}, {45}
    //2: 
    //   1: {1, 3}, {1, 4}, {1, 7}, {1, 10}, {1, 45}
    //   2: {3, 4}, {3, 7}, {3, 10}, {3, 45}
    //   3: {4, 7}, {4, 10}, {4, 45}
    //   4: {7, 10}, {7, 45}
    //   5: {10, 45}
    //3:
    //  1:
    //    2: {1, 3, 4}, {1, 3, 7}, {1, 3, 10}, {1, 3, 45}
    //    3: {1, 3, 4}, {1, 3, 7}, {1, 3, 10}, {1, 3, 45}
    //     .
    //     .
    //     .
    //  2:
    //    3: {1, 4, 7}, {1, 4, 10}, {1, 4, 10}, {1, 3, 45}
    //    3: {1, 3, 4}, {1, 3, 7}, {1, 3, 10}, {1, 3, 45}

}