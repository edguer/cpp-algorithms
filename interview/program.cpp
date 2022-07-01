#include <bits/stdc++.h>
using namespace std;

// O(n/2), memory n
void NaiveNoOrdering(int *source, int len)
{
    int middle = len / 2;

    for (int i = 1; i < len - 1; i += 2, middle++)
    {
        int temp = source[i];
        source[i] = source[middle];
        source[middle] = temp;
    }
}

// O(n/2), memory 2*n
/**
 * 1, 2, 3, 10, 20, 30
 * 1, 10, 3, 2, 20, 30
 * 1, 10, 3, 30, 20, 2
 * 1, 10, 3, 30, 2, 20
 * */
void NaiveNoMemoryEfficiency(int *source, int len)
{
    int middle = len / 2;

    int result[len];
    int result_count = 0;
    for (int i = 0, j = middle; i < len / 2 && j < len; i++, j++)
    {
        result[result_count++] = source[i];
        result[result_count++] = source[j];
    }

    for (int i = 0; i < len; i++)
    {
        source[i] = result[i];
    }
}

//O(N logN)
void Savvy(int *source, int len)
{
    // only look at the even index 1, 2, 4, 6...
    // find the first item starting from the middle
    /**
     * 1, 2, 3, 10, 20, 30
     * 1. 1, 10, 3, 10, 20, 30 -- temp = 2
     * 1a. 1, 10, 2, 10, 20, 30 -- temp = 3
     * 1b. 1, 10, 2, 3, 20, 30 -- temp = -
     * 3. 1, 10, 2, 20, 20, 30 -- temp =3
     * 3a. 1, 10, 2, 20, 3, 30
     * */
    for (int i = 1, j = len / 2; i < len; i += 2, j++)
    {
        int temp = source[i];
        source[i] = source[j];
        for (int k = i + 1; k < len; k++)
        {
            if (k != j)
            {
                int temp2 = source[k];
                source[k] = temp;
                temp = temp2;
            }
            else
            {
                source[k] = temp;
                break;
            }
        }
    }
}

int main()
{
    int source[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int len = sizeof(source) / sizeof(int);

    Savy(source, len);

    for (int i = 0; i < len; i++)
    {
        cout << source[i] << " ";
    }
    cout << endl;

    //      0 1 2 3 4  5  6  7  8  9
    //      1 2 3 4 5 10 20 30 40 50
    //i1 m5 1 10 3 4 5 1 20 30 40 50
    //i3 m6 1 10 3 20 5 1 4 30 40 50
    //i5 m7 1 10 3 20 5 30 4 1 40 50
    //i7 m8 1 10 3 20 5 30 4 40 1 50
    //      1 10 2 20 3 30 4 40 5 50
}