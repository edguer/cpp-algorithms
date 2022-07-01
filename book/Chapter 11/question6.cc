#include <bits/stdc++.h>

using namespace std;

static const int SIZE = 5;
int matrix[SIZE][SIZE] = {
    {0, 2, 4, 6, 8},
    {1, 10, 11, 12, 13},
    {3, 14, 15, 16, 17},
    {5, 18, 19, 20, 21},
    {7, 22, 23, 24, 25}};

int search(int value, int y, int start, int end)
{
    if (end >= start)
    {
        int mid = (start + end) / 2;
        cout << "Searching y:" << y << " start:" << start << " end:" << end << " mid:" << matrix[y][mid] << " value:" << value << endl;
        if (matrix[y][mid] == value)
            return mid;
        else if (value > matrix[y][mid])
            return search(value, y, mid + 1, end);
        else
            return search(value, y, start, mid - 1);
    }
    else
    {
        return -1;
    }
}

void search(int value, int &x, int &y, int start, int end)
{
    if (end >= start)
    {
        int mid = (start + end) / 2;
        if (matrix[mid][0] <= value && matrix[mid][SIZE - 1] >= value)
        {
            int res = search(value, mid, 0, SIZE - 1);
            if (res > -1)
            {
                y = mid;
                x = res;
            }
        }
        else if (value < matrix[mid][0] && value < matrix[mid][SIZE - 1])
        {
            search(value, x, y, start, mid - 1);
        }
        else
        {
            search(value, x, y, mid + 1, end);
        }
    }
}

int main()
{
    int x = -1, y = -1;
    search(24, x, y, 0, SIZE - 1);
    cout << "Result: (" << y << ", " << x << ")" << endl;
}