#include <bits/stdc++.h>

using namespace std;

void print(int *arr, int *sum, int index)
{
    cout << "Solution: ";
    for (int j = 0; j <= index; j++)
    {
        cout << arr[j] << "*" << sum[j] / arr[j] << " ";
    }
    cout << endl;
}
void get_combination(int *arr, int *sum, int index, int n, int possibilities, int *count)
{
    if (possibilities <= index)
        return;

    if (!sum)
        sum = new int[possibilities]{0};

    int val = arr[index];
    for (int i = 0; i <= n / val; i++)
    {
        int total = 0;
        sum[index] = i * val;
        for (int j = 0; j <= index; j++)
            total += sum[j];

        if (total == n)
        {
            // print(arr, sum, index);
            sum[index] = 0;
            (*count)++;
        }
        else if (total > n)
        {
            sum[index] = 0;
            break;
        }
        else if (index < possibilities - 1)
        {
            get_combination(arr, sum, index + 1, n, possibilities, count);
        }
    }
}

int cache[10000] = {0};
int simple_count(int n)
{
    if (n < 0) return 0;
    else if (n == 0) return 1;
    else if (n >= 0 && cache[n] != 0) return cache[n];
    else 
    {
        int sum = simple_count(n - 1) + simple_count(n - 2) + simple_count(n - 3);
        cache[n] = sum;
        return sum;
    }
}

int main()
{
    int n = 10000;
    int possibilities[] = {1, 2, 3};
    int len = sizeof(possibilities) / sizeof(int);
    int count = 0;
    // get_combination(possibilities, NULL, 0, n, len, &count);
    // cout << "Count: " << count << endl;
    cout << "Count simple: " << simple_count(n) << endl;
}