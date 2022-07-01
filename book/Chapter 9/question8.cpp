#include <bits/stdc++.h>

using namespace std;

int sum_array(int *arr, int len)
{
    int ret = 0;
    for (int i = 0; i < len; i++)
    {
        ret += arr[i];
    }
    return ret;
}

void print(int *arr, int len)
{
    cout << "Permutation: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << "$ ";
    }
    cout << endl;
}

vector<vector<int>> *cache = new vector<vector<int>>[10];
void permutation(int *coins, int len, int n, int coin_index, int *sum = NULL, int sum_count = 0)
{
    if (coin_index < len)
    {
        if (!sum) sum = new int[n];
        sum[sum_count++] = coins[coin_index];
        int total = sum_array(sum, sum_count);
        // cout << "Coin " << coins[coin_index] << ", total " << total << endl;

        if (total == n)
        {
            print(sum, sum_count);
        }
        else
        {
            int j = coin_index;
            if (coins[coin_index] > n)
            {
                sum_count--;
                permutation(coins, len, n, coin_index + 1, sum, sum_count);
                return;
            }
            else if (n - total < coins[coin_index])
            {
                j++;
            }
            for (; j < len; j++)
            {
                // cout << "it coin " << coins[j] << endl;
                permutation(coins, len, n, j, sum, sum_count);
            }
        }
    }
}

void permutation(int *coins, int len, int n)
{
    for (int i = 0; i < len; i++)
    {
        permutation(coins, len, n, i);
    }
}



int main()
{
    int coins[] = {25, 10, 5, 1};
    int n = 3000;
    permutation(coins, sizeof(coins)/sizeof(int), n);
    /**
     * 25$ 10$ 5$ 1$
     * 
     * n = 1 -> 1$
     * n = 2 -> 1$ 1$
     * n = 5 -> $5, 1$ 1$ 1$ 1$ 1$
     * n = 6 -> $5 1$, 1$ 1$ 1$ 1$ 1$ 1$
     * n = 7 -> $5 1$ 1$, 1$ 1$ 1$ 1$ 1$ 1$ 1$
     * n = 10 -> 10$, $5 $5, $5 1$ 1$ 1$ 1$ 1$, 1$ 1$ 1$ 1$ 1$ 1$ 1$ 1$ 1$ 1$
     * */
}