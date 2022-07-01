#include <bits/stdc++.h>

using namespace std;

const int SIZE = 8;
int *copy(int *source, int len)
{
    int *ret = new int[len];
    for (int i = 0; i < len; i++)
    {
        ret[i] = source[i];
    }
    
    return ret;
}
bool check(int *columns, int row, int col)
{
    for (int row2 = 0; row2 < row; row2++)
    {
        // cout << "column 2 " << columns[row2] << " - column 1 " << col << endl;
        if (columns[row2] == col)
            return false;

        if (abs(row2 - row) == abs(col - columns[row2]))
            return false;
    }

    return true;
}
void queen(int *columns, int row = 0)
{
    if (row == SIZE)
    {
        cout << "Solution: " << endl;
        for (int i = 0; i < SIZE; i++)
        {
            if (columns[i] != INT_MIN)
            {
                cout << "Row: " << i << " Column: " << columns[i] << endl;
            }
        }
        return;
    }

    for (int col = 0; col < SIZE; col++)
    {
        if (check(columns, row, col))
        {
            columns[row] = col;
            queen(copy(columns, SIZE), row + 1);
        }
    }
}

int main()
{
    int columns[SIZE] = {INT_MIN};
    queen(columns);
}