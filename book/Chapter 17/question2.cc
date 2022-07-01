#include <bits/stdc++.h>

using namespace std;

static const short int size = 3;

bool won(char board[][size])
{
    unsigned short int same_count_column[size] = {0};
    unsigned short int same_count_cross[2] = {0}; // 0 is from left to right
    for (unsigned short int i = 0; i < size; i++)
    {
        unsigned short int same_count_line = 0;
        for (unsigned short int j = 0; j < size; j++)
        {
            if (j > 0 && ((board[i][j - 1] == board[i][j] && ++same_count_line == 2) |
                          (i > 0 && board[i - 1][j] == board[i][j] && ++same_count_column[j] == 2)))
                return true;

            if (i > 0 && ((j > 0 && i == j && board[i - 1][j - 1] == board[i][j] && ++same_count_cross[0] == 2) |
                          (i + j == size - 1 && board[i - 1][j + 1] == board[i][j] && ++same_count_cross[1] == 2)))
                return true;
        }
    }

    return false;
}

int main()
{
    char board[size][size] =
        {
            {'O', 'X', 'O'},
            {'O', 'X', 'X'},
            {'X', 'O', 'O'}};

    cout << "Won? " << won(board) << endl;
}