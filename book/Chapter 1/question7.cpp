#include <bits/stdc++.h>
#include "utils.hpp"

using namespace std;

const int rows = 4, columns = 3;
int matrix[rows][columns] = {
    {1, 0, 4},
    {1, 2, 4},
    {0, 0, 4},
    {1, 2, 4}};

void ZeroRow(int);
void ZeroColumn(int);
void ZeroColumnAndRow()
{
    int zeroed_rows = 0, zeroed_columns = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] == 0 && (zeroed_rows & (1 << i)) == 0 && (zeroed_columns & (1 << j)) == 0)
            {
                ZeroRow(i);
                zeroed_rows |= 1 << i;

                ZeroColumn(j);
                zeroed_columns |= 1 << j;

                break;
            }
        }
    }
END:
    return;
}

void ZeroRow(int row)
{
    for (int i = 0; i < columns; i++)
    {
        matrix[row][i] = 0;
    }
}

void ZeroColumn(int column)
{
    for (int i = 0; i < rows; i++)
    {
        matrix[i][column] = 0;
    }
}

int main()
{
    Run(ZeroColumnAndRow);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}